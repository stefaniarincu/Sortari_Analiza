#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

ifstream teste("teste.in");

vector<long long> t;
vector<long long> y;
const long long RUN = 32;
vector<long long> vst;
vector<long long> vdr;

void generare_vect(vector<long long>& v, long long maxim, long long n){
    mt19937_64 gen(time(NULL));

    uniform_int_distribution<long long> random(0, maxim);

    for(long long i = 0; i < n; i++){
        v[i] = random(gen);
    }
}

bool test_sort(vector<long long>& v, long long n){
    for(long long i = 0; i < n-1; i++)
        if(v[i] > v[i+1])
            return false;
    return true;
}

void InterclasMerge(vector<long long>& v, long long st, long long mij, long long dr)
{
    long long i1 = st, i2 = mij+1;
    long long k = 0;

    while (i1 <= mij && i2 <= dr) {
        if (v[i1] <= v[i2]) {
			t[k] = v[i1];
			++i1;
		}
        else {
            t[k] = v[i2];
            ++i2;
        }
        ++k;
    }

    while (i1 <= mij) {
        t[k] = v[i1];
        ++i1;
        ++k;
    }

    while (i2 <= dr) {
        t[k] = v[i2];
        ++i2;
        ++k;
    }

    for (long long i = st; i <= dr; ++i)
		v[i] = t[i - st];
}


void mergeSort(vector<long long>& v, long long prim, long long ultim)
{
    if (prim < ultim){
        long long mij = prim + (ultim - prim) / 2;
        mergeSort(v, prim, mij);
        mergeSort(v, mij + 1, ultim);
        InterclasMerge(v, prim, mij, ultim);
    }
}

int shellSort(vector<long long>& v, long long n)
{
    long long distanta, i, j, temp;

    for (distanta = n/2; distanta > 0; distanta /= 2)
    {
        for (i = distanta; i < n; i += 1)
        {
            temp = v[i];

            for (j = i; j >= distanta && v[j - distanta] > temp; j -= distanta){
                v[j] = v[j - distanta];
            }
            v[j] = temp;
        }
    }
    return 0;
}

long long Maximul(vector<long long>& v, long long n) {
    long long maxim = v[0], i;
    for(i = 1; i < n; i++)
        if (v[i] > maxim)
            maxim = v[i];
    return maxim;
}

void countingSort10(vector<long long>& v, long long n, long long k) {
    long long cnt[10] = {}, i;

    for(i = 0; i < n; i++)
        cnt[(v[i] / k) % 10]++;

    for(i = 1; i < 10; i++)
        cnt[i] += cnt[i - 1];

    for(i = n - 1; i >= 0; i--) {
        y[cnt[(v[i] / k) % 10] - 1] = v[i];
        cnt[(v[i] / k) % 10]--;
    }

    for(i = 0; i < n; i++)
        v[i] = y[i];
}

void radixSort10(vector<long long>& v, long long n) {
    long long maxim = Maximul(v, n), i;

    for(i = 1; maxim / i > 0; i *= 10)
        countingSort10(v, n, i);
}

void countingSort2(vector<long long>& v, long long n, long long power, long long c) {
    long long cnt[c+1] = {}, i;

    for(i = 0; i < n; i++)
        cnt[(v[i] >> power) & c]++;

    for(i = 1; i <= c; i++)
        cnt[i] += cnt[i-1];

    for(i = n - 1; i >= 0; i--){
        y[cnt[(v[i] >> power) & c] - 1] = v[i];
        cnt[(v[i] >> power) & c]--;
    }

    for(i = 0; i < n; i++)
        v[i] = y[i];
}

void radixSort2(vector<long long>& v, long long n, long long power) {
     long long maxim = Maximul(v,n);
     long long c = pow(2, power)-1, i;
     for(i = 0; maxim >> i > 0; i += power){
        countingSort2(v, n, i, c);
    }
}

void interschimb(long long* a, long long* b)
{
    long long t = *a;
    *a = *b;
    *b = t;
}

long long partitie(vector<long long>& v, long long ist, long long idr)
{
    long long pivot = v[(ist+idr)/2];

    while(ist <= idr){
        while(v[ist] < pivot){
            ist++;
        }

        while(v[idr] > pivot){
            idr--;
        }

        if(ist <= idr) {
            interschimb(&v[ist], &v[idr]);
            ist++;
            idr--;
        }
    }
    return ist;
}

void quickSort(vector<long long>& v, long long ist, long long idr)
{
    if(ist < idr)
	{
		long long piv = partitie(v, ist, idr);

		quickSort(v, ist, piv - 1);
		quickSort(v, piv, idr);
	}
}

int partitie_random(vector<long long>& v, long long ist, long long idr)
{
    long long pivotrandom = v[ist + rand() % (idr - ist)];

    while(ist <= idr){
        while(v[ist] < pivotrandom){
            ist++;
        }

        while(v[idr] > pivotrandom){
            idr--;
        }

        if(ist <= idr) {
            interschimb(&v[ist], &v[idr]);
            ist++;
            idr--;
        }
    }
    return ist;
}

void quickSort_random(vector<long long>& v, long long ist, long long idr)
{
    if(ist < idr)
	{
		long long piv = partitie_random(v, ist, idr);

		quickSort_random(v, ist, piv - 1);
		quickSort_random(v, piv, idr);
	}
}

long long minim(long long a, long long b)
{
    if(a < b)
        return a;
    else
        return b;
}

void interclasTim(vector<long long>& v, long long st, long long dr)
{
    long long i, temp, j;

    for(i = st + 1; i <= dr; i++)
    {
        temp = v[i];
        j = i - 1;

        while(j >= st && v[j] >= temp)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = temp;
    }
}

void mergeSortTim(vector<long long>& v, long long st, long long mij, long long dr)
{
    long long lung1 = mij-st+1, lung2 = dr-mij, i, j = 0 , k = st;


    for(i = 0; i < lung1; i++)
        vst[i] = v[st + i];
    for(i = 0; i < lung2; i++)
        vdr[i] = v[mij + 1 + i];

    i = 0;
    while(i < lung1 && j < lung2)
    {
        if(vst[i] <= vdr[j])
        {
            v[k] = vst[i];
            i++;
        }
        else
        {
            v[k] = vdr[j];
            j++;
        }
        k++;
    }

    while(i < lung1)
    {
        v[k] = vst[i];
        k++;
        i++;
    }

    while (j < lung2)
    {
        v[k] = vdr[j];
        k++;
        j++;
    }
}

void timSort(vector<long long>& v, long long n)
{
    long long i, dimens, st, mij, dr;
    for(i = 0; i < n; i += RUN)
        interclasTim(v, i, minim((i+RUN-1),(n-1)));

    for(dimens = RUN; dimens < n; dimens = 2*dimens)
    {
        for(st = 0; st < n; st += 2*dimens)
        {
            mij = st + dimens - 1;
            dr = minim((st + 2*dimens - 1),(n-1));

            if(mij < dr)
                mergeSortTim(v, st, mij, dr);
        }
    }
}

double getTime(int sortType, long long n, long long maxim, vector<long long> w){
    if(sortType == 0){
            long long start = clock();
            sort(w.begin(), w.end());
            long long stop = clock();
            double duration = double(stop-start)/CLOCKS_PER_SEC;
            return duration;
    }
    else if(sortType == 1){
            long long start = clock();
            mergeSort(w, 0, n-1);
            long long stop = clock();
            double duration = double(stop-start)/CLOCKS_PER_SEC;
            return duration;
    }
    else if(sortType == 2){
            long long start = clock();
            shellSort(w, n);
            long long stop = clock();
            double duration = double(stop-start)/CLOCKS_PER_SEC;
            return duration;
    }
    else if(sortType == 3){
            long long start = clock();
            radixSort10(w, n);
            long long stop = clock();
            double duration = double(stop-start)/CLOCKS_PER_SEC;
            return duration;
    }
    else if(sortType == 4){
            long long start = clock();
            radixSort2(w, n, 16);
            long long stop = clock();
            double duration = double(stop-start)/CLOCKS_PER_SEC;
            return duration;
    }
    else if(sortType == 5){
            long long start = clock();
            quickSort(w, 0, n-1);
            long long stop = clock();
            double duration = double(stop-start)/CLOCKS_PER_SEC;
            return duration;
    }
    else if(sortType == 6){
            long long start = clock();
            quickSort_random(w, 0, n-1);
            long long stop = clock();
            double duration = double(stop-start)/CLOCKS_PER_SEC;
            return duration;
    }
    else if(sortType == 7){
            long long start = clock();
            timSort(w, n);
            long long stop = clock();
            double duration = double(stop-start)/CLOCKS_PER_SEC;
            return duration;
    }
}

void generare_csv(long long Min, long long Max, long long Pas, long long maxim){
    ofstream data("timp.csv");
    data<<",STL Sort,Merge Sort,Shell Sort,Radix Sort(Baza 10),Radix Sort(Baza 2^16),Quick Sort(Mediana din 2),Quick Sort(Pivot random),Tim Sort\n";
    for(long long n = Min; n <= Max; n += Pas){
        data<<n;
        vector<long long> w(n);
        generare_vect(w, maxim, n);

        t = vector<long long>(n);
        y = vector<long long>(n);
        vst = vector<long long> (n);
        vdr = vector<long long> (n);

        for(int i = 0; i < 8; i++){
            data<<","<<getTime(i, n, maxim, w);
        }
        data<<"\n";
    }

    data.close();
}

int main()
{
    srand(time(NULL));
    long long Min, Max, Pas, maxim;
    cin>>Min>>Max>>Pas>>maxim;
    generare_csv(Min, Max, Pas, maxim);
    return 0;
}


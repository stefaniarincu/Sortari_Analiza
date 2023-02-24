# Sortari_Analiza

   &emsp;In cadrul acestui proiect am implementat mai multe tipuri de sortari, pentru a analiza timpul de rulare si complexitatea acestora. <br />
   
  &emsp;&emsp;1.**Merge Sort** <br />
  &emsp;&emsp;2.**Shell Sort** <br />
  &emsp;&emsp;3.**Radix Sort** in baza 10 <br />
  &emsp;&emsp;4.**Radix Sort** in baza 2^16, folosind operatii pe biti <br />
  &emsp;&emsp;5.**Quick Sort** cu pivot egal cu mediana din 2 <br />
  &emsp;&emsp;6.**Quick Sort** alegand un pivot random <br />
  &emsp;&emsp;7.**Tim Sort** (algoritm hibrid) <br />

   &emsp;Am observat faptul ca Shell Sort este un algoritm foarte usor de implementat, dar ca timp de executie este cel mai lent dintre toti algoritmii implementati in acest proiect. <br />
   &emsp;De asemenea, exista o diferenta vizibila ca timp de executie intre Radix Sort in baza 10 si Radix Sort in baza 2^16 (unde se folosesc operatiile pe biti). Radix Sort in baza 2^16 ruleaza intr-un timp ce se apropie de 0, fiind cel mai rapid algoritm de sortare care se regaseste in acest proiect. Este mai rapid chiar si decat STL Sort, algoritmul de sortare implicit al vectorilor de tip STL. Pe cand Radix Sort in baza 10 este mai lent decat Radix Sort in baza 2^16, dar mai rapid decat STL Sort. <br />
   &emsp;In implementarea algoritmului de Quick Sort am ales ca in primul caz aleg pivotul ca fiind mediana din 2, deci aflandu-se mereu pe pozitia din mijloc, iar in cel de-al doilea caz am ales pivotul random. Din graficele facute am observat faptul ca timpul de executie nu difera foarte mult in cele 2 cazuri, desi atunci cand am ales pivotul mediana din 2 pare sa fi executat mai repede programul decat in cazul unui pivot ales random. <br />
   &emsp;Tim Sort, fiind algoritmul hibrid care sta la baza functiilor de sortare implicite (predefinite) atat in Python, cat si in C++ (de curand) are un timp de executie aproximativ egal cu cel al STL Sort-ului. <br />
   &emsp;Merge Sort se afla, de asemenea, ca timp de executie in zona Tim Sort-ului si a STL Sort-ului, dar este putin mai incet decat cele doua.

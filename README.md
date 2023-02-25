# Sorting Analyze

   &emsp;In this project, I have implemented several types of sorting, to analyze their running time and complexity. <br />
   
  &emsp;&emsp;1.**Merge Sort** <br />
  &emsp;&emsp;2.**Shell Sort** <br />
  &emsp;&emsp;3.**Radix Sort in base 10** <br />
  &emsp;&emsp;4.**Radix Sort in base 2^16**, using bitwise operations <br />
  &emsp;&emsp;5.**Quick Sort** with a **pivot equal to the median of 2** <br />
  &emsp;&emsp;6.**Quick Sort** choosing a **random pivot** <br />
  &emsp;&emsp;7.**Tim Sort** (hybrid algorithm) <br />

   &emsp;I have noticed that **Shell Sort** is a very easy algorithm to implement, but its execution time is the slowest of all the algorithms implemented in this project. <br /><br />
   &emsp;Also, there is a visible difference in execution time between **Radix Sort in base 10** and **Radix Sort in base 2^16** (where bitwise operations are used). Radix Sort in base 2^16 runs in a time that approaches 0, being the fastest sorting algorithm implemented in this project. It is even faster than **STL Sort**, the default sorting algorithm for STL vectors. I also noticed that Radix Sort in base 10 is slower than Radix Sort in base 2^16 but faster than STL Sort. <br /><br />
   &emsp;In the implementation of the **Quick Sort** algorithm, in the first case, I chose the **pivot** as the **median of 2**, so it is always in the middle position, and in the second case I chose the **pivot randomly**. From the graphs, I noticed that the execution time it's not very much different in those two cases, although when I chose the pivot as the median of 2, the program seems to execute faster than in the case of a randomly chosen pivot. <br /><br />
   &emsp;**Tim Sort**, is the hybrid algorithm that stays at the basis of the default (predefined) sorting functions in both Python and C++ (soon). It it's not surprising the fact that from the graphs we can easily see that it has an execution time approximately equal to the time from STL Sort. <br /><br />
   &emsp;If we compare the execution time, **Merge Sort** is also in the area of Tim Sort and STL Sort, but it is slightly slower than those two.
   



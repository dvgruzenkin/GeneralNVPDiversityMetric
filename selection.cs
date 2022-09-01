// One of 3 N-versions created for science experiment.

// This experiment describes in article "General diversity metric for N-version software".
// Experiment is carried out in Denis V. Gruzenkin PhD thesis writing.


using System;
using System.Collections.Generic;

class MySort {
    public static IList<T> Selection<T>(IList<T> list) where T : IComparable<T>
	{
	    for (int i = 0; i < list.Count - 1; ++i)
	    {
	        int min = i;
	        for (int j = i + 1; j < list.Count; ++j)
	        {
	        	if (list[j].CompareTo(list[min]) < 0)
	            {
	                min = j;
	            }
	        }
	        
	        var dummy = list[i];
	        list[i] = list[min];
	        list[min] = dummy;
	        
	        Console.WriteLine($"\niteration {i + 1}");
	        for (int k = 0; k < list.Count; ++k)
	            Console.Write($"{list[k]}\t");
	    }
	    
	    return list;
	}
    
    static void Main() 
    {
        Console.WriteLine("SELECTION SORT");
        //int[] sortedArr = {9, 0, -6, 18, 34, 3, 24};
		int[] sortedArr = {-20, 10, 8, 48, -5, 4, -25};
        Selection(sortedArr);
    }
}
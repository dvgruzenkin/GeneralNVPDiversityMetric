"""One of 3 N-versions created for science experiment.

This experiment describes in article "General diversity metric for N-version software".
Experiment is carried out in Denis V. Gruzenkin PhD thesis writing.
"""

__author__ = "Denis V. Gruzenkin"
__copyright__ = "Copyright 2022, Denis V. Gruzenkin"
__credits__ = ["Denis V. Gruzenkin"]
__license__ = "GPL"
__version__ = "1.0.0"
__maintainer__ = "Denis V. Gruzenkin"
__email__ = "gruzenkin.denis@good-look.su"
__status__ = "Development"


def partition(array, begin, end):
    pivot = begin
    for i in range(begin+1, end+1):
        if array[i] <= array[begin]:
            pivot += 1
            array[i], array[pivot] = array[pivot], array[i]
    array[pivot], array[begin] = array[begin], array[pivot]
    return pivot


def quick_sort(array, begin=0, end=None):
    if end is None:
        end = len(array) - 1
    
    def _quicksort(array, begin, end):
        if begin >= end:
            return
        print(array)
        pivot = partition(array, begin, end)
        _quicksort(array, begin, pivot-1)
        _quicksort(array, pivot+1, end)
    return _quicksort(array, begin, end)


def main():
    print ('QUICK SORT')
    # lst = [9, 0, -6, 18, 34, 3, 24]
    lst = [-20, 10, 8, 48, -5, 4, -25];
    quick_sort(lst)
    print(lst)


if __name__ == '__main__':
    main()

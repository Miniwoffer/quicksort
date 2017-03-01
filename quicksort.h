//
// Created by odin on 3/1/17.
//

#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H

template <typename T>
class quicksort {
private:
    static const int THRESHOLD = 2;
    static void swap(T *a, T *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    static void insertionSort(T *arr, int size)
    {
        T *arrend = arr+size-1;
        T *current;
        bool run = true;
        while(run)
        {
            current = arr;
            run = false;
            while(current != arrend)
            {
                if(*current > *(current+1)) {
                    swap(current, current + 1);
                    run = true;
                }
                current++;
            }


        }
    }
public:
    static void sort(T *arr, int size)
    {
        T *i = arr;
        T *j = arr+size-1;
        T pivot = *(arr+size/2);

        while(i < j)
        {
            while(*i < pivot && i < j)
                ++i;
            while(*j > pivot && i < j)
                --j;

            if(*i == *j && i != j) {
                ++i;
            }
            else if(i < j) {
                swap(i, j);
            }
        }
        int size_left = i-arr;
        int size_right = arr+size-i;
        if(size_left > THRESHOLD)
        {
            sort(arr,size_left);
        } else if(size_left > 2)
        {
            insertionSort(arr,size_left);
        }
        if(size_right > THRESHOLD)
        {
            sort(i,size_right);
        } else if(size_right > 2)
        {
            insertionSort(arr,size_left);
        }
    }
};


#endif //QUICKSORT_QUICKSORT_H

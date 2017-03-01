#include <iostream>

void quicksort(int*,int);
void swap(int*,int*);
int* findMiddle(int*,int*,int*);

int main()
{
    int myarr[] = {20, 37, 21, 67, 98, 86, 30, 83, 25, 40, 5, 10, 2, 35, 92, 90, 45, 93, 27, 78, 32, 96, 91, 26, 24, 66, 88, 79, 56, 44, 82, 95, 48, 76, 52, 59, 84, 80, 85, 16, 15, 3, 9, 29, 14, 11, 54, 18, 23, 19, 75, 17, 22, 4, 12, 38, 62, 50, 42, 39, 47, 61, 100, 74, 81, 1, 69, 49, 64, 55, 72, 34, 43, 63, 97, 94, 7, 13, 77, 8, 46, 60, 41, 73, 58, 99, 53, 65, 70, 31, 33, 71, 57, 51, 28, 68, 87, 89, 6, 36};
    int arrsize = (sizeof(myarr)/sizeof(*myarr));
    quicksort(myarr,arrsize);
    for(int i = 0; i < arrsize;++i)
    {
        std::cout << myarr[i] << ",";
    }
    std::cout << std::endl;
    return 0;
}

void quicksort(int *arr, int size)
{
    int pval;
    int *pivot;
    int *front = arr;
    int *middle = arr+size/2;
    int *end = arr+size-1;

    int *i = front;
    int *j = end;

    pivot = middle;
    pval = *pivot;

    while(i < j)
    {
        if(*i >= pval && *j <= pval)
        {
            swap(i,j);
            ++i;
        }
        else
            --j;
    }


    int sizefront = front-i;
    int sizeback = i-end;
    if(sizefront > 2)
    {
        quicksort(front,sizefront);
    }
    if(sizeback > 2)
    {
        quicksort(i,sizeback);
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* findMiddle(int* a,int* b,int* c)
{
    if(*a > *b && *a < *c || *a < *b && *a > *c)
        return a;
    if(*b > *a && *b < *c || *b < *a && *b > *c)
        return b;
    if(*c > *a && *c < *b || *c < *a && *c > *b)
        return c;

    return b;
}
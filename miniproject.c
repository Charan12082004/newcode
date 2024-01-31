#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 10
#define DELAY_MICROSECONDS 1000000 // 1 second
void bubbleSort(int arr[], int size);
void printArray(int arr[], int size,int s1,int s2);
void delay(int microseconds);
void swap(int *a,int *b);

int main()
{
    srand(time(NULL));

    int arr[ARRAY_SIZE];
    for(int i=0;i<ARRAY_SIZE;i++)
    {
        arr[i]=rand() %100; //Generate random integers for the array
    }

    printf("Original array: ");
    printArray(arr, ARRAY_SIZE,-1, -1);
    printf("\n");
    
    printf("Sorting steps: \n");
    bubbleSort(arr,ARRAY_SIZE);

    printf("\n sorted array: ");
    printArray(arr,ARRAY_SIZE, -1, -1);
    printf("\n");  
    return 0;
}
void bubbleSort(int arr[], int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j< size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap( &arr[j], &arr[j+1]);
                printArray(arr,size,j,j+1);
                delay(DELAY_MICROSECONDS);

            }
        }
    }
}

void delay(int microseconds)
{
    int nanoseconds= microseconds * 1000;
    for(int i=0;i< nanoseconds;i++);
}

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void printArray(int arr[], int size,int s1,int s2)
{
    for(int i=0;i<size; i++)
    {
        if(i== s1 || i==s2)
        {
            printf("\x1b[31m%d \x1b[0m", arr[i]);
        }
        else {
            printf("%d ",arr[i]);
        }
    }
    printf("\r"); // escape sequence --> used to take the cursor back to the statement so that we can override the statement
    fflush(stdout); // flush the output to make it visible immediately
}



#include<stdio.h>

void findMinMax(int* arr, int size){

    int min=arr[0];
    int max=arr[0];
    int i;

    for(i=0; i<size; i++){
        if(arr[i]<min){
          min = arr[i];
        }
        if(arr[i]>max){
          max = arr[i];
        }
    }
    printf("The smallest number is: %d\n", min);
    printf("The largest number is: %d\n", max);
}

int main() {

    int array1[] = {15, 32, 50, 67, 49, 6, 23, 95, 102, 193, 567, 320, 89};
    int size = sizeof(array1)/sizeof(array1[0]), i;

    findMinMax(array1, size);
    return 0;
}

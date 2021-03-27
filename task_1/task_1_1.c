#include<stdio.h>

int* removeEven(int* array, int* length){

    int size = *length;
    int i=0;

    while(i<size){
        if(array[i]%2==0){
            for(int j=i; j<size-1; j++){
                array[j] = array[j+1];
            }
            array[size-1] = NULL;
            size--;
            continue;
        }
        else{
          i++;
        }
    }
    *length = size;
    return array;
}

int main() {

    int array1[] = {15, 32, 6, 67, 49, 50, 23, 95, 102, 193, 567, 320, 89};
    int size = sizeof(array1)/sizeof(array1[0]), i;

    int* new_arr = removeEven(array1, &size);

    for(i=0; i<size; i++){
        printf("%d\n", new_arr[i]);
    }
    return 0;
}

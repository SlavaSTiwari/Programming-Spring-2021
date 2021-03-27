#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    int mid = l + (r - l) / 2;
    if (arr[mid] == x){
        return mid;
    }
    else if (arr[mid] > x && x > 0) {
        return binarySearch(arr, l, mid - 1, x);
    }
    else if(arr[mid] < x){
        return binarySearch(arr, mid + 1, r, x);
    }
    else {
        return -1;
    }
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 0, res;

    res = binarySearch(arr, 0, n - 1, x);

    if (res == -1){
        printf("Element is not present in array");
    }
    else{
        printf("Element is present at index %d", res);
    }
    return 0;
}

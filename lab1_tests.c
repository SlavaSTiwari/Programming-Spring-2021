#include<stdio.h>
#include<stdlib.h>

struct DynamicArray{
    int count; // No. of elements.
    int capacity; // The total memory capacity of the array.
    int elementSize; // memory size of 1 element. (Technically as we use a void pointer, this will be sizeof(void*) )
    void* data; // The data.
};


typedef struct{
    long long real;
    long long img;
}complex;

// Function prototypes:
void display(struct DynamicArray* arr);
struct DynamicArray* create_matrix(int type, int count);

// Main function
int main() {
    struct DynamicArray *matA, *matB, *res;
    int row, col, k=0;

    if (1) {
        typedef int sample;
        sample i = 3;
        printf("%d\n", i);
    }
    //typedef int sample;


    //printf("%d\n", i);

    matA = malloc(sizeof(struct DynamicArray));
    matA->data = malloc(4*sizeof(int));
    *((int*)matA->data) = 1;
    *((int*)matA->data+1)= 2;
    *((int*)matA->data+2) = 3;
    *((int*)matA->data+3) = 4;

    matB = malloc(sizeof(struct DynamicArray));
    matB->data = malloc(4*sizeof(int));
    *((int*)matB->data) = 5;
    *((int*)matB->data+1) = 6;
    *((int*)matB->data+2) = 7;
    *((int*)matB->data+3) = 8;

    printf("%d", *((int*)matB->data+(3*sizeof(int))));

    res = malloc(sizeof(struct DynamicArray));
    res->data = malloc(4*sizeof(int));
    for(row=0;row<2;row++) {
        for(col=0;col<2;col++) {
            *((int*)res->data+col+(row*2)) = 0;
            for(k=0;k<2;k++){
                printf("The loop is working\n");
                *((int*)res->data+col+(row*2)) += *((int*)matA->data+k+(row*2)) * *((int*)matB->data+col+(k*2));
                printf("%d = %d+%d\n", *((int*)res->data+col+(row*2)), *((int*)matA->data+col+(k*2)), *((int*)matB->data+k+(row*2)));
            }
            printf("%d\n", *((int*)res->data+col+(row*2)));
        }
    }


    return 0;
}

/*    printf("Enter the type of matrix A:\n1.Simple\n2.Complex\nYour Choice: ");
    type1 = choose(1,2);

    printf("Enter the number of rows/columns: ");
    max = choose(1,10);

    printf("Enter the first matrix:\n");
    matA = create_matrix(type1, max);
    printf("Size of element in matA: %d\n", matA->elementSize);

    printf("Enter the type of matrix B:\n1.Simple\n2.Complex\nYour Choice: ");
    type2 = choose(1,2);

    printf("Enter the second matrix:\n");
    matB = create_matrix(type2, max);

    display_matrix(matA);
    display_matrix(matB);

    printf("\nThe product is:\n");
    mul = matrix_product(matA, matB);
    display_matrix(mul);

    printf("\nThe sum is:\n");
    sum = matrix_sum(matA, matB);
    display_matrix(sum);

    printf("Choose a number for scalar multiplication: ");
    sclr = choose(-100, 100);
    smulA = scalar_product(matA, sclr);
    smulB = scalar_product(matB, sclr);

    printf("\n");
    display_matrix(smulA);
    printf("\n");
    display_matrix(smulB); */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct DynamicArray{
    int count;
    int capacity;
    int elementSize;
    void* data;
};

typedef struct{
    long long real;
    long long img;
}complex;

//Function prototypes
void init_matrix(struct DynamicArray *varr, int elem_type);
struct DynamicArray* create_matrix(int type, int max);
struct DynamicArray* create_random(int type, int max);
struct DynamicArray* matrix_sum(struct DynamicArray* matA, struct DynamicArray* matB);
struct DynamicArray* matrix_product(struct DynamicArray* matA, struct DynamicArray* matB);
struct DynamicArray* scalar_product(struct DynamicArray* matA, int sclr);
void show_test(int test_no);

void delete_matrix(struct DynamicArray *matrix);
void display_matrix(struct DynamicArray *varr);
int choose(int f,int l);
void show_tutorial();

int main() {

    struct DynamicArray *matA, *matB, *mul, *sum, *smul;
    int type1, type2, max, sclr, choice, opr, ent, type_no;

    while(1) {
        printf("     ==MAIN MENU==\n");
        printf("Please choose an option:\n1. Start\n2. Tutorial\n3. Quit\n(Please refer to TUTORIAL for correct input methods and to avoid undefined behavour)\nYour choice: ");
        choice = choose(1,3);
        switch(choice) {
        case 1:
            printf("\nChoose an option:\n1. Manual Entry\n2. Random Generation\n3. Test cases\nPlease Choose an option: ");
            ent = choose(1,3);
            switch(ent){
            case 1: // Manual Entry
                printf("\n   ==MANUAL ENTRY==\n\n");
                printf("Enter the type of matrix A:\n1.Simple\n2.Complex\nYour Choice: ");
                type1 = choose(1,2);

                printf("Enter the number of rows/columns: ");
                max = choose(1,10);

                printf("Enter the first matrix:\n");
                matA = create_matrix(type1, max);
                printf("Size of element in matA: %d\n", matA->elementSize);

                printf("Choose an operation:\n1. Matrix addition\n2. Matrix multiplication\n3. Scalar addition\nYour choice: ");
                opr = choose(1,3);
                switch(opr){
                case 1:
                    printf("\n  ==MATRIX ADDITION==\n\n");
                    printf("Enter the type of matrix B:\n1.Simple\n2.Complex\nYour Choice: ");
                    type2 = choose(1,2);

                    printf("Enter the second matrix:\n");
                    matB = create_matrix(type2, max);

                    printf("\nMatrix A:\n");
                    display_matrix(matA);
                    printf("\nMatrix B:\n");
                    display_matrix(matB);

                    printf("\nMatrix A + Matrix B:\n");
                    sum = matrix_sum(matA, matB);
                    display_matrix(sum);

                    delete_matrix(matA);
                    delete_matrix(matB);
                    delete_matrix(sum);
                    break;

                case 2:
                    printf("\n  ==MATRIX MULTIPLICATION==\n\n");
                    printf("Enter the type of matrix B:\n1.Simple\n2.Complex\nYour Choice: ");
                    type2 = choose(1,2);

                    printf("Enter the second matrix:\n");
                    matB = create_matrix(type2, max);

                    printf("\nMatrix A:\n");
                    display_matrix(matA);
                    printf("\nMatrix B:\n");
                    display_matrix(matB);

                    printf("\nMatrix A * Matrix B:\n");
                    mul = matrix_product(matA, matB);
                    display_matrix(mul);

                    delete_matrix(matA);
                    delete_matrix(matB);
                    delete_matrix(mul);
                    break;

                case 3:
                    printf("\n  ==SCALAR MULTIPLICATION==\n\n");
                    printf("Choose a number for scalar multiplication: ");
                    sclr = choose(-10000, 10000);

                    smul = scalar_product(matA, sclr);

                    printf("\nMatrix A:\n");
                    display_matrix(matA);
                    printf("\n%d * Matrix A:\n", sclr);
                    display_matrix(smul);

                    delete_matrix(matA);
                    delete_matrix(smul);
                    break;
                }
                break; // Case 1 (Manual entry) end.

            case 2: // Random generation
                printf("\n   ==RANDOM GENERATION==\n\n");
                printf("Enter the type of matrix A:\n1.Simple\n2.Complex\nYour Choice: ");
                type1 = choose(1,2);

                printf("Enter the number of rows/columns: ");
                max = choose(1,10);
                matA = create_random(type1, max);

                printf("Choose an operation:\n1. Matrix addition\n2. Matrix multiplication\n3. Scalar addition\nYour choice: ");
                opr = choose(1,3);
                switch(opr){
                case 1:
                    printf("\n  ==MATRIX ADDITION==\n\n");
                    printf("Enter the type of matrix B:\n1.Simple\n2.Complex\nYour Choice: ");
                    type2 = choose(1,2);

                    matB = create_random(type2, max);

                    printf("\nMatrix A:\n");
                    display_matrix(matA);
                    printf("\nMatrix B:\n");
                    display_matrix(matB);

                    printf("\nMatrix A + Matrix B:\n");
                    sum = matrix_sum(matA, matB);
                    display_matrix(sum);

                    delete_matrix(matA);
                    delete_matrix(matB);
                    delete_matrix(sum);
                    break;

                case 2:
                    printf("\n  ==MATRIX MULTIPLICATION==\n\n");
                    printf("Enter the type of matrix B:\n1.Simple\n2.Complex\nYour Choice: ");
                    type2 = choose(1,2);

                    matB = create_random(type2, max);

                    printf("\nMatrix A:\n");
                    display_matrix(matA);
                    printf("\nMatrix B:\n");
                    display_matrix(matB);

                    printf("\nMatrix A * Matrix B:\n");
                    mul = matrix_product(matA, matB);
                    display_matrix(mul);

                    delete_matrix(matA);
                    delete_matrix(matB);
                    delete_matrix(mul);
                    break;

                case 3:
                    printf("\n  ==SCALAR MULTIPLICATION==\n\n");
                    printf("Choose a number for scalar multiplication: ");
                    sclr = choose(-100, 100);

                    smul = scalar_product(matA, sclr);

                    printf("\nMatrix A:\n");
                    display_matrix(matA);
                    printf("\%d * Matrix A:\n", sclr);
                    display_matrix(smul);

                    delete_matrix(matA);
                    delete_matrix(smul);
                    break;
                }

                break;

            case 3:
                printf("\n   ==TEST CASES==\n\n");
                printf("Please choose a predetermined test case :\n");
                printf("1. 2x2: MatA:  simple | MatB: simple\n2. 2x2: MatA:  simple | MatB: complex\n3. 2x2: MatA: complex | MatB: complex\n");
                printf("4. 3x3: MatA:  simple | MatB: simple\n5. 3x3: MatA:  simple | MatB: complex\n6. 3x3: MatA: complex | MatB: complex\n");
                //printf("7. 5x5: MatA: simple | MatB = simple\n");

                printf("Choose a TEST: ");
                type_no = choose(1,6);
                show_test(type_no);

                break;
            }
            break;

        case 2:
            show_tutorial();
            break;
        case 3:
            printf("\n  ==QUITING==\n");
            return 0;
        }
    }

}

void init_matrix(struct DynamicArray *varr, int elem_type){
    //struct DynamicArray* varr;

    //varr = malloc(sizeof(struct DynamicArray));
    if(elem_type==1){ // int matrix
        varr->elementSize = sizeof(int);
    }
    if(elem_type==2){
        varr->elementSize = sizeof(long long);
    }
};

struct DynamicArray* create_matrix(int type, int max){
    struct DynamicArray* varr;
    int row, col, inc, x, elem_type;
    char chk;

    varr = malloc(sizeof(struct DynamicArray));
    varr->count = max;
    if(type==1) { // Simple matrix
        printf("Choose element type: ");
        elem_type = choose(1,2);
        init_matrix(varr, elem_type);
        varr->capacity = varr->count*varr->count*varr->elementSize;
        varr->data = malloc(varr->capacity);
        if(elem_type==1) {
            for(inc=0;inc<varr->count*varr->count;inc++){
                row = inc/varr->count + 1;
                col = inc%varr->count + 1;
                printf("Enter element [%d][%d]: ", row, col);
                scanf("%d", ((int*)varr->data+inc) );
            }
        }
        if(elem_type==2) {
            for(inc=0;inc<varr->count*varr->count;inc++){
                row = inc/varr->count + 1;
                col = inc%varr->count + 1;
                printf("Enter element [%d][%d]: ", row, col);
                scanf("%lld", ((long long*)varr->data+inc) );
            }
        }
    }

    else{ // Complex matrix
        varr->elementSize = sizeof(complex);
        varr->capacity = varr->count*varr->count*varr->elementSize;
        varr->data = malloc(varr->capacity);

        for(inc=0;inc<varr->count*varr->count;inc++){
            row = inc/varr->count + 1;
            col = inc%varr->count + 1;
            printf("Enter element [%d][%d]: ", row, col);
            scanf("%lld+%lldi", &((complex*)varr->data+inc)->real, &((complex*)varr->data+inc)->img );
        }
    }
    return varr;
}

struct DynamicArray* create_random(int type, int max) {

    struct DynamicArray* varr;
    int row, col, inc;

    srand(time(0));

    varr = malloc(sizeof(struct DynamicArray));
    varr->count = max;
    if(type==1) { // Simple matrix
        varr->elementSize = sizeof(long long);
        varr->capacity = varr->count*varr->count*varr->elementSize;
        varr->data = malloc(varr->capacity);

        for(inc=0;inc<varr->count*varr->count;inc++){
            *((int*)varr->data+inc) = rand();
        }
    }
    else{ // Complex matrix
        varr->elementSize = sizeof(complex);
        varr->capacity = varr->count*varr->count*varr->elementSize;
        varr->data = malloc(varr->capacity);

        for(inc=0;inc<varr->count*varr->count;inc++){
            ((complex*)varr->data+inc)->real= rand();
            ((complex*)varr->data+inc)->img = rand();
        }
    }
    return varr;
}


struct DynamicArray* matrix_sum(struct DynamicArray* matA, struct DynamicArray* matB){

    struct DynamicArray *sum;
    int row, col, inc;
    sum = malloc(sizeof(struct DynamicArray));
    sum->count = matA->count;

    // Case 1 (Both simple matrices)
    if(matA->elementSize==sizeof(long long) && matB->elementSize==sizeof(long long)) {
        sum->elementSize = sizeof(long long);
        sum->capacity = sum->count*sum->count*sum->elementSize;
        sum->data = malloc(sum->capacity);
        for(inc=0;inc<sum->count*sum->count;inc++) {
            *((long long*)sum->data+inc) = *((long long*)matA->data+inc) + *((long long*)matB->data+inc);
        }
    }
    if(matA->elementSize==sizeof(int) && matB->elementSize==sizeof(int)) {
        sum->elementSize = sizeof(int);
        sum->capacity = sum->count*sum->count*sum->elementSize;
        sum->data = malloc(sum->capacity);
        for(inc=0;inc<sum->count*sum->count;inc++) {
            *((int*)sum->data+inc) = *((int*)matA->data+inc) + *((int*)matB->data+inc);
        }
    }
    if(matA->elementSize==sizeof(long long) && matB->elementSize==sizeof(int)) {
        sum->elementSize = sizeof(long long);
        sum->capacity = sum->count*sum->count*sum->elementSize;
        sum->data = malloc(sum->capacity);
        for(inc=0;inc<sum->count*sum->count;inc++) {
            *((long long*)sum->data+inc) = *((long long*)matA->data+inc) + *((int*)matB->data+inc);
        }
    }
    if(matA->elementSize==sizeof(int) && matB->elementSize==sizeof(long long)) {
        sum->elementSize = sizeof(long long);
        sum->capacity = sum->count*sum->count*sum->elementSize;
        sum->data = malloc(sum->capacity);
        for(inc=0;inc<sum->count*sum->count;inc++) {
            *((long long*)sum->data+inc) = *((int*)matA->data+inc) + *((long long*)matB->data+inc);
        }
    }

    // Case 2 (Only first is complex)
    if(matA->elementSize==sizeof(complex) && matB->elementSize==sizeof(long long)) {
        sum->elementSize = sizeof(complex);
        sum->capacity = sum->count*sum->count*sum->elementSize;
        sum->data = malloc(sum->capacity);
        for(inc=0;inc<sum->count*sum->count;inc++) {
                    ((complex*)sum->data+inc)->real = ((complex*)matA->data+inc)->real + *((long long*)matB->data+inc);
                    ((complex*)sum->data+inc)->img = ((complex*)matA->data+inc)->img;
        }
    }
    if(matA->elementSize==sizeof(complex) && matB->elementSize==sizeof(int)) {
        sum->elementSize = sizeof(complex);
        sum->capacity = sum->count*sum->count*sum->elementSize;
        sum->data = malloc(sum->capacity);
        for(inc=0;inc<sum->count*sum->count;inc++) {
                    ((complex*)sum->data+inc)->real = ((complex*)matA->data+inc)->real + *((int*)matB->data+inc);
                    ((complex*)sum->data+inc)->img = ((complex*)matA->data+inc)->img;
        }
    }

    // Case 3 (only second one is complex)
    if(matA->elementSize==sizeof(long long) && matB->elementSize==sizeof(complex)) {
        sum->elementSize = sizeof(complex);
        sum->capacity = sum->count*sum->count*sum->elementSize;
        sum->data = malloc(sum->capacity);
        for(inc=0;inc<sum->count*sum->count;inc++) {
                    ((complex*)sum->data+inc)->real = *((long long*)matA->data+inc) + ((complex*)matB->data+inc)->real;
                    ((complex*)sum->data+inc)->img = ((complex*)matB->data+inc)->img;
        }
    }
    if(matA->elementSize==sizeof(int) && matB->elementSize==sizeof(complex)) {
        sum->elementSize = sizeof(complex);
        sum->capacity = sum->count*sum->count*sum->elementSize;
        sum->data = malloc(sum->capacity);
        for(inc=0;inc<sum->count*sum->count;inc++) {
                    ((complex*)sum->data+inc)->real = *((int*)matA->data+inc) + ((complex*)matB->data+inc)->real;
                    ((complex*)sum->data+inc)->img = ((complex*)matB->data+inc)->img;
        }
    }

    // Case 4 (both are complex)
    if(matA->elementSize==sizeof(complex) && matB->elementSize==sizeof(complex)) {
        sum->elementSize = sizeof(complex);
        sum->capacity = sum->count*sum->count*sum->elementSize;
        sum->data = malloc(sum->capacity);
        for(inc=0;inc<sum->count*sum->count;inc++) {
            ((complex*)sum->data+inc)->real = ((complex*)matA->data+inc)->real + ((complex*)matB->data+inc)->real;
            ((complex*)sum->data+inc)->img = ((complex*)matA->data+inc)->img + ((complex*)matB->data+inc)->img;
        }
    }

    return sum;
};

struct DynamicArray* matrix_product(struct DynamicArray* matA, struct DynamicArray* matB) {

    struct DynamicArray *mul;
    int row, col, k;
    mul = malloc(sizeof(struct DynamicArray));
    mul->count = matA->count;

    // Case 1 (Both simple matrices)
    if(matA->elementSize==sizeof(long long) && matB->elementSize==sizeof(long long)) {
        mul->elementSize = sizeof(long long);
        mul->capacity = mul->count*mul->count*mul->elementSize;
        mul->data = malloc(mul->capacity);

        for(row=0;row<mul->count;row++) {
            for(col=0;col<mul->count;col++) {
                *((long long*)mul->data+col+(row*mul->count)) = 0;
                for(k=0;k<mul->count;k++){
                    *((long long*)mul->data+col+(row*mul->count)) += *((long long*)matA->data+k+(row*mul->count)) * *((long long*)matB->data+col+(k*mul->count));
                }
            }
        }
    }
    if(matA->elementSize==sizeof(int) && matB->elementSize==sizeof(int)) {
        mul->elementSize = sizeof(int);
        mul->capacity = mul->count*mul->count*mul->elementSize;
        mul->data = malloc(mul->capacity);

        for(row=0;row<mul->count;row++) {
            for(col=0;col<mul->count;col++) {
                *((int*)mul->data+col+(row*mul->count)) = 0;
                for(k=0;k<mul->count;k++){
                    *((int*)mul->data+col+(row*mul->count)) += *((int*)matA->data+k+(row*mul->count)) * *((int*)matB->data+col+(k*mul->count));
                }
            }
        }
    }


    // Case 2 (Only first is complex)
    if(matA->elementSize==sizeof(complex) && matB->elementSize==sizeof(long long)) {
        mul->elementSize = sizeof(complex);
        mul->capacity = mul->count*mul->count*mul->elementSize;
        mul->data = malloc(mul->capacity);
        for(row=0;row<mul->count;row++) {
            for(col=0;col<mul->count;col++) {
                ((complex*)mul->data+col+(row*mul->count))->real = 0;
                ((complex*)mul->data+col+(row*mul->count))->img = 0;
                for(k=0;k<mul->count;k++){
                    ((complex*)mul->data+col+(row*mul->count))->real += ((complex*)matA->data+k+(row*mul->count))->real * *((long long*)matB->data+col+(k*mul->count));
                    ((complex*)mul->data+col+(row*mul->count))->img += ((complex*)matA->data+k+(row*mul->count))->img * *((long long*)matB->data+col+(k*mul->count));
                }
            }
        }
    }
    if(matA->elementSize==sizeof(complex) && matB->elementSize==sizeof(int)) {
        mul->elementSize = sizeof(complex);
        mul->capacity = mul->count*mul->count*mul->elementSize;
        mul->data = malloc(mul->capacity);
        for(row=0;row<mul->count;row++) {
            for(col=0;col<mul->count;col++) {
                ((complex*)mul->data+col+(row*mul->count))->real = 0;
                ((complex*)mul->data+col+(row*mul->count))->img = 0;
                for(k=0;k<mul->count;k++){
                    ((complex*)mul->data+col+(row*mul->count))->real += ((complex*)matA->data+k+(row*mul->count))->real * *((int*)matB->data+col+(k*mul->count));
                    ((complex*)mul->data+col+(row*mul->count))->img += ((complex*)matA->data+k+(row*mul->count))->img * *((int*)matB->data+col+(k*mul->count));
                }
            }
        }
    }

    // Case 3 (only second one is complex)
    if(matA->elementSize==sizeof(long long) && matB->elementSize==sizeof(complex)) {
        mul->elementSize = sizeof(complex);
        mul->capacity = mul->count*mul->count*mul->elementSize;
        mul->data = malloc(mul->capacity);
        for(row=0;row<mul->count;row++) {
            for(col=0;col<mul->count;col++) {
                ((complex*)mul->data+col+(row*mul->count))->real = 0;
                ((complex*)mul->data+col+(row*mul->count))->img = 0;
                for(k=0;k<mul->count;k++){
                    ((complex*)mul->data+col+(row*mul->count))->real += *((long long*)matA->data+k+(row*mul->count)) * ((complex*)matB->data+col+(k*mul->count))->real;
                    ((complex*)mul->data+col+(row*mul->count))->img += *((long long*)matA->data+k+(row*mul->count)) * ((complex*)matB->data+col+(k*mul->count))->img;
                }
            }
        }
    }
    if(matA->elementSize==sizeof(int) && matB->elementSize==sizeof(complex)) {
        mul->elementSize = sizeof(complex);
        mul->capacity = mul->count*mul->count*mul->elementSize;
        mul->data = malloc(mul->capacity);
        for(row=0;row<mul->count;row++) {
            for(col=0;col<mul->count;col++) {
                ((complex*)mul->data+col+(row*mul->count))->real = 0;
                ((complex*)mul->data+col+(row*mul->count))->img = 0;
                for(k=0;k<mul->count;k++){
                    ((complex*)mul->data+col+(row*mul->count))->real += *((int*)matA->data+k+(row*mul->count)) * ((complex*)matB->data+col+(k*mul->count))->real;
                    ((complex*)mul->data+col+(row*mul->count))->img += *((int*)matA->data+k+(row*mul->count)) * ((complex*)matB->data+col+(k*mul->count))->img;
                }
            }
        }
    }

    // Case 4 (both are complex)
    if(matA->elementSize==sizeof(complex) && matB->elementSize==sizeof(complex)) {
        mul->elementSize = sizeof(complex);
        mul->capacity = mul->count*mul->count*mul->elementSize;
        mul->data = malloc(mul->capacity);
        for(row=0;row<mul->count;row++) {
            for(col=0;col<mul->count;col++) {
                ((complex*)mul->data+col+(row*mul->count))->real = 0;
                ((complex*)mul->data+col+(row*mul->count))->img = 0;
                for(k=0;k<mul->count;k++){
                    ((complex*)mul->data+col+(row*mul->count))->real += ((complex*)matA->data+k+(row*mul->count))->real * ((complex*)matB->data+col+(k*mul->count))->real + ((complex*)matA->data+k+(row*mul->count))->img * ((complex*)matB->data+col+(k*mul->count))->img * (-1) ;
                    ((complex*)mul->data+col+(row*mul->count))->img += ((complex*)matA->data+k+(row*mul->count))->real * ((complex*)matB->data+col+(k*mul->count))->img + ((complex*)matA->data+k+(row*mul->count))->img * ((complex*)matB->data+col+(k*mul->count))->real;
                }
            }
        }
    }

    return mul;
}

struct DynamicArray* scalar_product(struct DynamicArray* matA, int sclr) {

    struct DynamicArray *smul;
    int inc;
    smul = malloc(sizeof(struct DynamicArray));
    smul->count = matA->count;

    // Case 1: (Simple matrix)
    if(matA->elementSize==sizeof(long long)){
        smul->elementSize = sizeof(long long);
        smul->capacity = smul->count*smul->count*smul->elementSize;
        smul->data = malloc(smul->capacity);
        for(inc=0;inc<smul->count*smul->count;inc++) {
            *((long long*)smul->data+inc) = *((long long*)matA->data+inc) * sclr;
        }
    }
    //Case 2: (Complex matrix)
    else{
        smul->elementSize = sizeof(complex);
        smul->capacity = smul->count*smul->count*smul->elementSize;
        smul->data = malloc(smul->capacity);
        for(inc=0;inc<smul->count*smul->count;inc++) {
            ((complex*)smul->data+inc)->real = ((complex*)matA->data+inc)->real * sclr;
            ((complex*)smul->data+inc)->img = ((complex*)matA->data+inc)->img * sclr;
        }
    }

    return smul;
}

// TEST CASES
void show_test(int test_no){
    struct DynamicArray *varrA, *varrB, *varr_sum, *varr_product;
    int row, col, inc;

    //TEST 1: 2x2: MatA & MatB: simple:
    if(test_no==1) {
        varrA = malloc(sizeof(struct DynamicArray));
        varrA->count = 2;
        varrA->elementSize = sizeof(int);
        varrA->capacity = varrA->count*varrA->count*varrA->elementSize;
        varrA->data = malloc(varrA->capacity);

        // Hard-coding the values:
        *((int*)varrA->data+0) = 241;
        *((int*)varrA->data+1) = 326;
        *((int*)varrA->data+2) = 972;
        *((int*)varrA->data+3) = 483;

        varrB = malloc(sizeof(struct DynamicArray));
        varrB->count = varrA->count;
        varrB->elementSize = sizeof(int);
        varrB->capacity = varrB->count*varrB->count*varrB->elementSize;
        varrB->data = malloc(varrB->capacity);

        *((int*)varrB->data+0) = 567;
        *((int*)varrB->data+1) = 295;
        *((int*)varrB->data+2) = 884;
        *((int*)varrB->data+3) = 980;

        printf("\nMatA:\n");
        display_matrix(varrA);

        printf("\nMatB:\n");
        display_matrix(varrB);

        printf("\nMatA + MatB:\n");
        printf("Matrix calculator output:\n");
        varr_sum = matrix_sum(varrA, varrB);
        display_matrix(varr_sum);

        printf("\nExpected output:\n");
        printf("  808    621 \n");
        printf("  1856   1463\n");


        printf("\nMatA * MatB:\n");
        printf("Matrix calculator output:\n");
        varr_product = matrix_product(varrA, varrB);
        display_matrix(varr_product);

        printf("Expected output:\n");
        printf("  424831    390575\n");
        printf("  978096    760080\n\n\n");
    } // TEST 1 end.

    //TEST 2: 2x2: MatA: simple | MatB: complex:
    if(test_no==2) {
        varrA = malloc(sizeof(struct DynamicArray));
        varrA->count = 2;
        varrA->elementSize = sizeof(int);
        varrA->capacity = varrA->count*varrA->count*varrA->elementSize;
        varrA->data = malloc(varrA->capacity);

        // Hard-coding the values:
        *((int*)varrA->data+0) = 100;
        *((int*)varrA->data+1) = 300;
        *((int*)varrA->data+2) = 900;
        *((int*)varrA->data+3) = 400;

        varrB = malloc(sizeof(struct DynamicArray));
        varrB->count = varrA->count;
        varrB->elementSize = sizeof(complex);
        varrB->capacity = varrB->count*varrB->count*varrB->elementSize;
        varrB->data = malloc(varrB->capacity);

        ((complex*)varrB->data+0)->real = 500;
        ((complex*)varrB->data+0)->img = 200;

        ((complex*)varrB->data+1)->real = 400;
        ((complex*)varrB->data+1)->img = 600;

        ((complex*)varrB->data+2)->real = 800;
        ((complex*)varrB->data+2)->img = 700;

        ((complex*)varrB->data+3)->real = 300;
        ((complex*)varrB->data+3)->img = 1000;

        printf("\nMatA:\n");
        display_matrix(varrA);

        printf("\nMatB:\n");
        display_matrix(varrB);

        printf("\nMatA + MatB:\n");
        printf("Matrix calculator output:\n");
        varr_sum = matrix_sum(varrA, varrB);
        display_matrix(varr_sum);

        printf("\nExpected output:\n");
        printf("  600+200i    700+600i\n");
        printf("  1700+700i   700+1000i\n");


        printf("\nMatA * MatB:\n");
        printf("Matrix calculator output:\n");
        varr_product = matrix_product(varrA, varrB);
        display_matrix(varr_product);

        printf("Expected output:\n");
        printf("  290000+230000i    130000+360000i\n");
        printf("  770000+460000i    480000+940000i\n\n\n");
    } // TEST 2 end.

    // TEST 3: 2x2: MatA: complex | MatB: complex:
    if(test_no==3) {
        varrA = malloc(sizeof(struct DynamicArray));
        varrA->count = 2;
        varrA->elementSize = sizeof(complex);
        varrA->capacity = varrA->count*varrA->count*varrA->elementSize;
        varrA->data = malloc(varrA->capacity);

        // Hard-coding the values:
        ((complex*)varrA->data+0)->real = 100;
        ((complex*)varrA->data+0)->img = 250;

        ((complex*)varrA->data+1)->real = 300;
        ((complex*)varrA->data+1)->img = 800;

        ((complex*)varrA->data+2)->real = 900;
        ((complex*)varrA->data+2)->img = 350;

        ((complex*)varrA->data+3)->real = 400;
        ((complex*)varrA->data+3)->img = 650;

        varrB = malloc(sizeof(struct DynamicArray));
        varrB->count = varrA->count;
        varrB->elementSize = sizeof(complex);
        varrB->capacity = varrB->count*varrB->count*varrB->elementSize;
        varrB->data = malloc(varrB->capacity);

        ((complex*)varrB->data+0)->real = 500;
        ((complex*)varrB->data+0)->img = 200;

        ((complex*)varrB->data+1)->real = 400;
        ((complex*)varrB->data+1)->img = 600;

        ((complex*)varrB->data+2)->real = 800;
        ((complex*)varrB->data+2)->img = 700;

        ((complex*)varrB->data+3)->real = 300;
        ((complex*)varrB->data+3)->img = 1000;

        printf("\nMatA:\n");
        display_matrix(varrA);

        printf("\nMatB:\n");
        display_matrix(varrB);

        printf("\nMatA + MatB:\n");
        printf("Matrix calculator output:\n");
        varr_sum = matrix_sum(varrA, varrB);
        display_matrix(varr_sum);

        printf("\nExpected output:\n");
        printf("  600+450i    700+1400i\n");
        printf("  1700+1050i   700+1650i\n");


        printf("\nMatA * MatB:\n");
        printf("Matrix calculator output:\n");
        varr_product = matrix_product(varrA, varrB);
        display_matrix(varr_product);

        printf("Expected output:\n");
        printf("  -320000+995000i    -820000+700000i\n");
        printf("  245000+1155000i    -380000+1275000i\n\n\n");
    }// TEST 3 end.

    //TEST 4: 3x3: MatA & MatB: simple
    if(test_no==4) { // Simple matrix with big numbers
        varrA = malloc(sizeof(struct DynamicArray));
        varrA->count = 3;
        varrA->elementSize = sizeof(int);
        varrA->capacity = varrA->count*varrA->count*varrA->elementSize;
        varrA->data = malloc(varrA->capacity);

        // Hard-coding the values:
        *((int*)varrA->data+0) = 241;
        *((int*)varrA->data+1) = 326;
        *((int*)varrA->data+2) = 972;
        *((int*)varrA->data+3) = 483;
        *((int*)varrA->data+4) = 561;
        *((int*)varrA->data+5) = 727;
        *((int*)varrA->data+6) = 805;
        *((int*)varrA->data+7) = 382;
        *((int*)varrA->data+8) = 199;

        varrB = malloc(sizeof(struct DynamicArray));
        varrB->count = varrA->count;
        varrB->elementSize = sizeof(int);
        varrB->capacity = varrB->count*varrB->count*varrB->elementSize;
        varrB->data = malloc(varrB->capacity);

        *((int*)varrB->data+0) = 567;
        *((int*)varrB->data+1) = 295;
        *((int*)varrB->data+2) = 884;
        *((int*)varrB->data+3) = 980;
        *((int*)varrB->data+4) = 725;
        *((int*)varrB->data+5) = 143;
        *((int*)varrB->data+6) = 526;
        *((int*)varrB->data+7) = 402;
        *((int*)varrB->data+8) = 671;

        printf("\nMatA:\n");
        display_matrix(varrA);

        printf("\nMatB:\n");
        display_matrix(varrB);

        printf("\nMatA + MatB:\n");
        printf("Matrix calculator output:\n");
        varr_sum = matrix_sum(varrA, varrB);
        display_matrix(varr_sum);

        printf("\nExpected output:\n");
        printf("  808    621    1856\n");
        printf("  1463   1286   870\n");
        printf("  1331   784    870\n");

        printf("\nMatA * MatB:\n");
        printf("Matrix calculator output:\n");
        varr_product = matrix_product(varrA, varrB);
        display_matrix(varr_product);

        printf("Expected output:\n");
        printf("  967399    698189    911874\n");
        printf("  1206043   841464    995012\n");
        printf("  935469    594423    899775\n\n\n");
        } // Test 4 end.

    //TEST 5: 3x3: MatA: simple | MatB: complex:
    if(test_no==5) {
        varrA = malloc(sizeof(struct DynamicArray));
        varrA->count = 3;
        varrA->elementSize = sizeof(int);
        varrA->capacity = varrA->count*varrA->count*varrA->elementSize;
        varrA->data = malloc(varrA->capacity);

        // Hard-coding the values:
        *((int*)varrA->data+0) = 200;
        *((int*)varrA->data+1) = 300;
        *((int*)varrA->data+2) = 900;
        *((int*)varrA->data+3) = 400;
        *((int*)varrA->data+4) = 500;
        *((int*)varrA->data+5) = 700;
        *((int*)varrA->data+6) = 800;
        *((int*)varrA->data+7) = 300;
        *((int*)varrA->data+8) = 100;

        varrB = malloc(sizeof(struct DynamicArray));
        varrB->count = varrA->count;
        varrB->elementSize = sizeof(complex);
        varrB->capacity = varrB->count*varrB->count*varrB->elementSize;
        varrB->data = malloc(varrB->capacity);

        ((complex*)varrB->data+0)->real = 500;
        ((complex*)varrB->data+0)->img = 450;

        ((complex*)varrB->data+1)->real = 300;
        ((complex*)varrB->data+1)->img = 600;

        ((complex*)varrB->data+2)->real = 850;
        ((complex*)varrB->data+2)->img = 1000;

        ((complex*)varrB->data+3)->real = 900;
        ((complex*)varrB->data+3)->img = 350;

        ((complex*)varrB->data+4)->real = 750;
        ((complex*)varrB->data+4)->img = 800;

        ((complex*)varrB->data+5)->real = 100;
        ((complex*)varrB->data+5)->img = 200;

        ((complex*)varrB->data+6)->real = 500;
        ((complex*)varrB->data+6)->img = 450;

        ((complex*)varrB->data+7)->real = 400;
        ((complex*)varrB->data+7)->img = 100;

        ((complex*)varrB->data+8)->real = 600;
        ((complex*)varrB->data+8)->img = 550;

        printf("\nMatA:\n");
        display_matrix(varrA);

        printf("\nMatB:\n");
        display_matrix(varrB);

        printf("\nMatA + MatB:\n");
        printf("Matrix calculator output:\n");
        varr_sum = matrix_sum(varrA, varrB);
        display_matrix(varr_sum);

        printf("\nExpected output:\n");
        printf("  700+450i    600+600i    1750+1000i\n");
        printf("  1300+350i   1250+800i   800+200i\n");
        printf("  1300+450i   700+100i    700+550i\n");

        printf("\nMatA * MatB:\n");
        printf("Matrix calculator output:\n");
        varr_product = matrix_product(varrA, varrB);
        display_matrix(varr_product);

        printf("Expected output:\n");
        printf("  820000+600000i    645000+450000i    740000+755000i\n");
        printf("  1000000+670000i   775000+710000i    810000+885000i\n");
        printf("  720000+510000i    505000+730000i    770000+915000i\n\n\n");
        } // Test 5 end.


    //TEST 6: 3x3: MatA: complex | MatB: complex:
    if(test_no==6) {
        varrA = malloc(sizeof(struct DynamicArray));
        varrA->count = 3;
        varrA->elementSize = sizeof(complex);
        varrA->capacity = varrA->count*varrA->count*varrA->elementSize;
        varrA->data = malloc(varrA->capacity);

        // Hard-coding the values:
        ((complex*)varrA->data+0)->real = 100;
        ((complex*)varrA->data+0)->img = 150;

        ((complex*)varrA->data+1)->real = 700;
        ((complex*)varrA->data+1)->img = 650;

        ((complex*)varrA->data+2)->real = 350;
        ((complex*)varrA->data+2)->img = 1500;

        ((complex*)varrA->data+3)->real = 500;
        ((complex*)varrA->data+3)->img = 450;

        ((complex*)varrA->data+4)->real = 50;
        ((complex*)varrA->data+4)->img = 650;

        ((complex*)varrA->data+5)->real = 600;
        ((complex*)varrA->data+5)->img = 250;

        ((complex*)varrA->data+6)->real = 200;
        ((complex*)varrA->data+6)->img = 900;

        ((complex*)varrA->data+7)->real = 750;
        ((complex*)varrA->data+7)->img = 350;

        ((complex*)varrA->data+8)->real = 400;
        ((complex*)varrA->data+8)->img = 850;

        varrB = malloc(sizeof(struct DynamicArray));
        varrB->count = varrA->count;
        varrB->elementSize = sizeof(complex);
        varrB->capacity = varrB->count*varrB->count*varrB->elementSize;
        varrB->data = malloc(varrB->capacity);

        ((complex*)varrB->data+0)->real = 500;
        ((complex*)varrB->data+0)->img = 450;

        ((complex*)varrB->data+1)->real = 300;
        ((complex*)varrB->data+1)->img = 600;

        ((complex*)varrB->data+2)->real = 850;
        ((complex*)varrB->data+2)->img = 1000;

        ((complex*)varrB->data+3)->real = 900;
        ((complex*)varrB->data+3)->img = 350;

        ((complex*)varrB->data+4)->real = 750;
        ((complex*)varrB->data+4)->img = 800;

        ((complex*)varrB->data+5)->real = 100;
        ((complex*)varrB->data+5)->img = 200;

        ((complex*)varrB->data+6)->real = 500;
        ((complex*)varrB->data+6)->img = 450;

        ((complex*)varrB->data+7)->real = 400;
        ((complex*)varrB->data+7)->img = 100;

        ((complex*)varrB->data+8)->real = 600;
        ((complex*)varrB->data+8)->img = 550;

        printf("\nMatA:\n");
        display_matrix(varrA);

        printf("\nMatB:\n");
        display_matrix(varrB);

        printf("\nMatA + MatB:\n");
        printf("Matrix calculator output:\n");
        varr_sum = matrix_sum(varrA, varrB);
        display_matrix(varr_sum);

        printf("\nExpected output:\n");
        printf("  600+600i    1000+1250i   1200+2500i\n");
        printf("  1400+800i   800+1450i    700+450i\n");
        printf("  700+1350i   1150+450i    1000+1400i\n");

        printf("\nMatA * MatB:\n");
        printf("Matrix calculator output:\n");
        varr_product = matrix_product(varrA, varrB);
        display_matrix(varr_product);

        printf("Expected output:\n");
        printf("  -115000+1857500i   -65000+1787500i    -740000+1525000i\n");
        printf("    52500+1447500i   -387500+1122500i    72500+1437500i\n");
        printf("    65000+1722500i   -122500+1632500i   -952500+1880000i\n\n\n");
        } // Test 6 end.
    }

void delete_matrix(struct DynamicArray *matrix){

    int inc = 0;
    free(matrix->data);
    free(matrix);
    //printf("Successfully freed!\n");
}

void display_matrix(struct DynamicArray *varr){

    int inc=0;
    if(varr->elementSize == sizeof(complex)){
        while(inc<varr->count*varr->count) {
            printf("  %lld+%lldi  ", ((complex*)varr->data+inc)->real, ((complex*)varr->data+inc)->img );
            inc++;
            if(inc%varr->count == 0){
                printf("\n\n");
            }
        }
    }
    if(varr->elementSize == sizeof(int)){
        while(inc<varr->count*varr->count) {
            printf("  %lld  ", *((int*)varr->data+inc) );
            inc++;
            if(inc%varr->count == 0){
                printf("\n\n");
            }
        }
    }
    if(varr->elementSize == sizeof(long long)){
        while(inc<varr->count*varr->count) {
            printf("  %lld  ", *((long long*)varr->data+inc) );
            inc++;
            if(inc%varr->count == 0){
             printf("\n\n");
            }
        }
    }
}

int choose(int f,int l) {

    char* msg = "";
    long long choice;
    do {
        printf("%s", msg);
        msg = "Please enter a valid option!: ";
        scanf("%d", &choice);
        scanf("%*[^\n]", &choice); // * is used to tell that we don't want to store the input.
    } while (choice < f || choice > l);
    fgetc(stdin); // consumes the newline.
    return choice;
}

void show_tutorial(){
    printf("\n\t\t\t ==TUTORIAL==\n\n");
    printf("To ensure the proper use of this matrix calculator please follow these steps:\n\n");
    printf("1. After choosing START from the MAIN MENU, choose the type of Matrix A.\n   Enter the number of rows inside Matrix A\n   (Since we are only working with square matrices, number of rows = number of columns.)\n\n");

    printf("2. If RANDOM GENERATION is chosen, You will be asked to enter the TYPE and number of rows for Matrix A.\n   Skip to [STEP 4] Matrices will be generated and displayed on the screen accordingly.\n   ");
    printf("If you choose MANUAL ENTRY, you will be asked to pick the TYPE and number of rows accordingly, move to [STEP 3].\n\n");

    printf("3. After choosing TYPE and number of rows, you will be requested to enter the elements of each matrix individually in the format:  Matrix[ROW][COLUMN].\n   ");
    printf("Enter the elements corresponding to the type of matrix chosen:\n   1. Simple matrix == [x] (x = integer)\n   2. Complex matrix == [a]+[b]i (a = real part, b = imaginary part)\n   ");
    printf("Note that you CANNOT enter different types of element inside a matrix of a specific choosen type!\n\n");

    printf("4. Next, choose an opperation to be performed\n   (You may be asked to enter a second matrix with the same dimensions as the first matrix. Please follow steps 1 and 2 respectively)\n   ");
    printf("List of available operations (Along with the format of execution):\n   1. Matrix addition (Matrix A + Matrix B)\n   2. Matrix multiplication (Matrix A * Matrix B)\n   3. Scalar multiplication (X * Matrix A) (where X is an integer)\n\n");

    printf("After choosing an OPERATION and entering the appropriate elements, The output will be displayed accordingly,\nAfter which all the values will be reset and you will be redirected to the main menu.\n");
    printf("\nMade by: Slava Shiv Tiwari\n\n\n");
}

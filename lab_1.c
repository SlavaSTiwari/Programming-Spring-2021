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
struct GynamicArray* init_matrix(int size);
struct DynamicArray* create_matrix(int type, int max);
struct DynamicArray* create_random(int type, int max);
struct DynamicArray* matrix_sum(struct DynamicArray* matA, struct DynamicArray* matB);
struct DynamicArray* matrix_product(struct DynamicArray* matA, struct DynamicArray* matB);
struct DynamicArray* scalar_product(struct DynamicArray* matA, int sclr);

void delete_matrix(struct DynamicArray *matrix);
void display_matrix(struct DynamicArray *varr);
long long choose(long long f, long long l);
void show_tutorial();

int main() {

    struct DynamicArray *matA, *matB, *mul, *sum, *smul;
    int type1, type2, max, sclr, choice, opr, ent;

    while(1) {
        printf("     ==MAIN MENU==\n");
        printf("Please choose an option:\n1. Start\n2. Tutorial\n3. Quit\n(Please refer to TUTORIAL for correct input methods and to avoid undefined behavour)\nYour choice: ");
        choice = choose(1,3);
        switch(choice) {
        case 1:
            printf("\nChoose an option:\n1.Manual Entry\n2.Random Generation\nPlease Choose an option: ");
            ent = choose(1,2);
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

struct DynamicArray* create_matrix(int type, int max){
    struct DynamicArray* varr;
    int row, col, inc, x;
    char chk;

    varr = malloc(sizeof(struct DynamicArray));
    varr->count = max;
    if(type==1) { // Simple matrix
        varr->elementSize = sizeof(long long);
        varr->capacity = varr->count*varr->count*varr->elementSize;
        varr->data = malloc(varr->capacity);

        for(inc=0;inc<varr->count*varr->count;inc++){
            row = inc/varr->count + 1;
            col = inc%varr->count + 1;
                printf("Enter element [%d][%d]: ", row, col);
                scanf("%lld", ((long long*)varr->data+inc) );
                //printf("%", );
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
    else{
        while(inc<varr->count*varr->count) {
            printf("  %lld  ", *((long long*)varr->data+inc) );
            inc++;
            if(inc%varr->count == 0){
                printf("\n\n");
            }
        }
    }

}

long long choose(long long f, long long l) {

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

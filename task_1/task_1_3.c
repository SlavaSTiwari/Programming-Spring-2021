#include<stdio.h>

void reverse(char* str) {
    int i, n=0;
    for(i=0; str[i]!='\0'; i++){
        n++;
    }
    char swap;
    for(i=0; i<n/2; i++){
        swap = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = swap;
    }
}

int main() {
    char str[] = "This is a dummy string!";
    printf("The original string is:\n%s\n", str);
    reverse(str);
    printf("\nThe reversed string is:\n%s\n", str);
    return 0;
}

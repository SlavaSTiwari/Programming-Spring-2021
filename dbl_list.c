#include<stdio.h>

struct List{
    struct List* prev;
    int data;
    struct List* next;
}

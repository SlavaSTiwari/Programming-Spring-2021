#include<stdio.h>
#include<stdlib.h>

struct List{
    struct List* prev;
    int data;
    struct List* next;;
};

void printList(struct List* list){

    while(list != NULL){
        printf(" %d ", list->data);
        list = list->next;
    }
}

void addFirst(struct List** org_list, int new_data){

    struct List* new_node = malloc(sizeof(struct List));

    new_node->data = new_data;
    new_node->next = (*org_list);
    new_node->prev = NULL;

    if ((*org_list) != NULL)
        (*org_list)->prev = new_node;

    (*org_list) = new_node;
}

void addLast(struct List** org_list, int new_data){

    struct List* new_node = (struct List*)malloc(sizeof(struct List));
    new_node->data = new_data;
    new_node->next = NULL;

    struct List* last = *org_list;

    if(*org_list == NULL){
        new_node->prev = NULL;
        *org_list = new_node;
    }

    else{
        while(last->next != NULL){
            last = last->next;
        }

    last->next = new_node;
    new_node->prev = last;
    }
}

void insertAt(struct List* prev_node, int item_num, int new_data){

    int i=1;

    while(i<item_num-1){
        prev_node = prev_node->next;
        i++;
    }

    if (prev_node == NULL){
        printf("The previous node does not exist.");
        return;
    }

    struct List* new_node = malloc(sizeof(struct List));
    new_node->data = new_data;
    new_node->next = prev_node->next;

    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void deleteAt(struct List* prev_node, int item_num){

    int i = 1;
    while(i<item_num-1){
        prev_node = prev_node->next;
        i++;
    }

    if (prev_node == NULL){
        printf("The previous node does not exist.");
        return;
    }

    struct List* temp = prev_node->next;
    prev_node->next = prev_node->next->next;
    prev_node->next->prev = prev_node;

    free(temp);
}

void concat(struct List* a, struct List* b){

    while(a->next != NULL){
        a = a->next;
    }
    a->next = b;
    b->prev = a;
}

// EXERCISE 6 NOT FINISHED
void sortConcat(struct List* a, atruct List* b){ // NOT FINISHED

    struct List* tempA = a->next;
    struct List* tempB = b->next;
    a->next = b;
    b->prev = a;

    b->next = tempA;  // all of this, in a loop
    tempA->prev = b;

    tempA->next = tempB;
    tempB->prev = tempA;

}

void freeList(struct List* head){

    struct List *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){

    struct List* head = NULL;
    struct List* temp = NULL;

    addLast(&head, 5);  // [5]
    addFirst(&head, 15);// [15, 5]
    addLast(&head, 23); // [15, 5, 23]
    addLast(&head, 2);  // [15, 5, 23, 2]
    addFirst(&head, 64);// [64, 15, 5, 23, 2]
    addLast(&head, 8);  // [64, 15, 5, 23, 2, 8]
    addLast(&head, 37); // [64, 15, 5, 23, 2, 8, 37]

    insertAt(head, 5, 0);// [64, 15, 5, 23, 0, 2, 8, 37]
    deleteAt(head, 7);   // [64, 15, 5, 23, 0, 2, 37]

    printf("The list is:");
    printList(head);

    addFirst(&temp, 3);// [3]
    addLast(&temp, 6); // [3, 6]
    addFirst(&temp, 1);// [1, 3, 6]
    addLast(&temp, 8); // [1, 3, 6, 8]
    insertAt(temp, 3, 12); // [1, 3, 12, 6, 8]

    concat(head, temp); // [64, 15, 5, 23, 0, 2, 37, 1, 3, 12, 6, 8]

    printf("The concatanated list is:");
    printList(head);
    printf("\n\n");

    freeList(head);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct List {
    int data;
    struct List* next;
};

void printList(struct List* lst){
    while(lst != NULL){
        printf(" %d ", lst->data);
        lst = lst->next;
    }
}

void addLast(struct List** org_list, int new_data){

    struct List* new_node = (struct List*)malloc(sizeof(struct List));
    new_node->data = new_data;
    new_node->next = NULL;

    struct List* last = *org_list;

    if(*org_list == NULL){
        *org_list = new_node;
    }

    else{
        while(last->next != NULL){
            last = last->next;
        }

    last->next = new_node;
    }
}

void printReverse(struct List* head)
{
    if (head == NULL){
        return;
    }
    printReverse(head->next);

    printf("% d ", head->data);
}

void reverseList(struct List** org_list)
{
    struct List* previous = NULL;
    struct List* current = *org_list;
    struct List* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *org_list = previous;
}

int palCheck(struct List** first, struct List* last){

    int palin;

    if(last==NULL){
        return 1;
    }
    if(!palCheck(first, last->next)){
        return 0;
    }
    if(last->data == (*first)->data){
        palin = 1;
    }
    else{
        palin = 0;
    }
    *first = (*first)->next;

    return palin;
}

void freeList(struct List* head){

    struct List *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {

    struct List* head = NULL;

    addLast(&head, 5);
    addLast(&head, 15);
    addLast(&head, 23);
    addLast(&head, 2);
    addLast(&head, 23);
    addLast(&head, 15);
    addLast(&head, 50);

    printf("The list is:");
    printList(head);
    printf("\n\n");

    printf("The reverse of list without reversing the list:");
    printReverse(head);
    printf("\n\n");

    printf("The list AFTER reversing the list:");
    reverseList(&head);
    printList(head);
    printf("\n\n");

    if(palCheck(&head, head)){
        printf("The list is a palindrome!\n");
    }
    else{
        printf("The list is NOT a palindrome!\n");
    }
    freeList(head);
    return 0;
}

#include<stdio.h>
#include "linkedlist.h"

int main(){
    struct linkedlist *ll = init();
    insertAtStart(ll, 10);
    display(ll);
    printf("\nhead: %d -- tail: %d\n",ll->head->data, ll->tail->data);
    insertAtEnd(ll, 9);
    insertAtEnd(ll, 8);
    insertAtEnd(ll, 7);
    insertAtEnd(ll, 6);
    display(ll);
    printf("\nhead: %d -- tail: %d\n",ll->head->data, ll->tail->data);
    insertAtPos(ll, 5, 1);
    display(ll);
    printf("\nhead: %d -- tail: %d\n",ll->head->data, ll->tail->data);
    // deleteAtPos(ll, 1);
    // display(ll);
    // printf("\nhead: %d -- tail: %d\n",ll->head->data, ll->tail->data);
    printf("pos: %d\n",searchOnList(ll, 8));
    return 0;
}
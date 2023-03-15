#include <stdbool.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct linkedlist
{
    struct Node *head;
    struct Node *tail;
};

struct linkedlist *init()
{
    struct linkedlist *list = malloc(sizeof(struct linkedlist));
    if (list == NULL)
    {
        printf("\nmemory Error!!\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}
struct Node *createNode(int d)
{
    struct Node *temp = malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("\nmemory Error!!\n");
        return NULL;
    }
    temp->data = d;
    temp->next = NULL;
    return temp;
}
bool isEmpty(struct linkedlist *list)
{
    return list->head == NULL;
}
void insertAtEnd(struct linkedlist *list, int d)
{
    struct Node *newNode = createNode(d);
    if (isEmpty(list))
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void insertAtStart(struct linkedlist *list, int d)
{
    struct Node *newNode = createNode(d);
    if (isEmpty(list))
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head = newNode;
    }
}

void insertAtPos(struct linkedlist *list, int pos, int d)
{
    struct Node *newNode = createNode(d);
    if (pos < 0)
    {
        printf("position is Invalid!!");
        return;
    }
    else
    {
        if (pos == 1)
        {
            insertAtStart(list, d);
            return;
        }
        else
        {
            struct Node *temp = list->head;
            int count = 1;
            while (count < pos - 1)
            {
                temp = temp->next;
                count++;
            }

            if (temp->next == list->tail)
            {
                insertAtEnd(list, d);
                return;
            }
            else
            {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
}
void deleteAtStart(struct linkedlist *list){
    if(isEmpty(list)){
        printf("\nList is Empty!!\n");
        return;
    }else{
        struct Node *temp = list->head;
        if(temp->next == NULL){
            list->head = NULL;
            list->tail = NULL;
            printf("%d deleted \n", temp->data);
            free(temp);
        }else{
            list->head = temp->next;
            temp->next = NULL;
            printf("%d deleted \n", temp->data);
            free(temp);
        }
    }
}
void deleteAtEnd(struct linkedlist *list){
    if(isEmpty(list)){
        printf("\nList is Empty!!\n");
        return;
    }else{
        struct Node *temp = list->head;
        while (temp->next != list->tail)
        {
            temp = temp->next;
        }
        list->tail = temp;
        temp->next = NULL;
        free(temp->next);
    }
}
void deleteAtPos(struct linkedlist *list, int pos)
{
    if(pos < 0){
        printf("Position is Invalid!!");
        return;
    }else{
        if(pos == 1){
            deleteAtStart(list);
            return;
        }else{
            struct Node *curr = list->head;
            struct Node *prev = NULL;
            int count = 1;
            while (count <= pos - 1)
            {
                prev = curr;
                curr = curr->next;
                count++;
            }
            if(curr == list->tail){
                deleteAtEnd(list);
            }else{
            prev->next = curr->next;
            curr->next = NULL;
            free(curr);
            }
        }
    }
}

int searchOnList(struct linkedlist *list, int key){
    struct Node *temp = list->head;
    int count = 1;
    while (temp != NULL)
    {
        if(temp->data == key){
            printf("key is found: %d \n", key);   
            return count;
        }
        temp = temp->next;
        count++;
    }
}
// void sortList(struct linkedlist *list){
//     if(isEmpty(list)){
//         printf("\nList is Empty!!\n");
//         return;
//     }else{
//         struct linkedlist *temp = list->head;
//         while(temp != NULL){
//             struct likedlist *compareNode = temp;
//         }
//     }
// }

void display(struct linkedlist *list)
{
    if (isEmpty(list))
    {
        printf("\nLinked List is Empty!!\n");
        return;
    }
    printf("\n Display List: \n");
    struct Node *res = list->head;
    while (res != NULL)
    {
        printf(" |  %d  | ", res->data);
        res = res->next;
    }
}

// #include <stdbool.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
//     struct Node *head;
//     struct Node *tail;
// };

// struct Node *init()
// {
//     struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
//     if (temp == NULL)
//     {
//         printf("\nmemory Error!!\n");
//         return;
//     }
//     temp->head = NULL;
//     temp->tail = NULL;
//     return temp;
// }
// struct Node *createNode(struct Node *temp, int d)
// {
//     temp->data = d;
//     temp->next = NULL;
//     return temp;
// }
// bool isEmpty(struct Node *temp)
// {
//     return temp->head == NULL;
// }
// void insertAtEnd(struct Node *temp, int d)
// {
//     struct Node *newNode = createNode(temp, d);
//     if (isEmpty(temp))
//     {
//         temp->head = newNode;
//         temp->tail = newNode;
//     }
//     else
//     {
//         temp->tail->next = newNode;
//         temp->tail = newNode;
//     }
// }

// void insertAtStart(struct Node *temp, int d)
// {
//     struct Node *newNode = createNode(temp, d);
//     if (isEmpty(temp))
//     {
//         temp->head = newNode;
//         temp->tail = newNode;
//     }
//     else
//     {
//         newNode->next = temp->head;
//         temp->head = newNode;
//     }
// }

// void display(struct Node *temp)
// {
//     if (isEmpty(temp))
//     {
//         printf("\nLinked List is Empty!!\n");
//         return;
//     }
//     printf("\n Display List: \n");
//     struct Node *res = temp->head;
//     while (res != NULL)
//     {
//         printf(" |  %d  | ", res->data);
//         res = res->next;
//     }
// }
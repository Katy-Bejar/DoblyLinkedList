#include<iostream>
using namespace std;

struct DLLNode {
    int data;
    struct DLLNode* next;
    struct DLLNode* prev;
};

struct DoblyLinkedList {
    struct DLLNode* head;
    struct DLLNode* tail;
};

void DLLInsert(struct DLLNode **head, int data, int position)
{
    int k=1;
    struct DLLNode *temp, *newNode;
    newNode = (struct DLLNode *) malloc(sizeof(struct DLLNode));

    if(!newNode){
        printf("Memory error");
        return;
    }

    newNode->data = data;
    if(position == 1){
        newNode->next = *head;
        newNode->prev = nullptr;

        if(*head)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    temp = *head;
    while((k < position-1) && temp->next != nullptr){
        temp = temp->next;
        k++;
    }

    if(k != position){
        printf("Desired position does not exist \n");
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next)
        temp->next->prev = newNode;
    
    temp->next = newNode;
    return;
}



void print(struct DLLNode **head)
{
    struct DLLNode *temp;
   
    temp = *head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

void DLLDelete(struct DLLNode **head, int position)
{
    struct DLLNode *temp, *temp2;
    temp = *head;
    int k=1;

    if(*head == nullptr){
        printf("List is empty");
        return;
    }

    if(position == 1){
        *head = (*head)->next;
        if(*head == nullptr)
            (*head)->prev = nullptr;
        free(temp);
        return;
        
    }

    while((k < position) && temp->next != nullptr){
        temp = temp->next;
        k++;
    }

    if(k != position-1){
        printf("Desired position does not exist \n");
    }

    temp2 = temp->prev;
    temp2->next = temp->next;

    if(temp->next)
        temp->next->prev = temp2;
    
    free(temp);
    return;
}

int main(){
    struct DLLNode *head = nullptr;
    DLLInsert(&head, 15, 1);
    DLLInsert(&head, 25, 2);
    DLLInsert(&head, 35, 3);
    DLLInsert(&head, 45, 4);
    print(&head);

    DLLDelete(&head, 1);
    print(&head);
    
    DLLDelete(&head, 2);
    print(&head);
    return 0;
}
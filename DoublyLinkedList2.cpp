#include<iostream>
using namespace std;

struct DLLNode {
    int data;
    struct DLLNode* next;
    struct DLLNode* prev;
}

struct DoblyLinkedList {
    struct DLLNode* head;
    struct DLLNode* tail;
};

void push_front(struct DLLNode * head,struct DLLNode * tail, int data){
    struct DLLNode * newNode;
    newNode = (struct DLLNode *) malloc(sizeof(struct DLLNode));
    newNode -> data = data;
    if(!newNode){
        printf("Memory error");
        return;
    } if (!head){
        *head = *tail = newNode; 
        newNode;
    }else {
        newNode->next = *head;
        if(*head)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }
}

void push_BACK(struct DLLNode * head,struct DLLNode * tail, int data){
    struct DLLNode * newNode;
    newNode = (struct DLLNode *) malloc(sizeof(struct DLLNode));
    newNode -> data = data;
    if(!newNode){
        printf("Memory error");
        return;
    } if (!head){
        *head = *tail = newNode; 
    } else {
        newNode->prev = *tail;
        if(*tail)
            (*tail)->next = newNode;
        *tail = newNode;
        return;
    }
}

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

void DLLDelete_front(struct DLLNode **head)
{
    struct DLLNode *temp, *temp2;
    temp = *head;
    int k=1;

    if(*head == nullptr){
        printf("List is empty");
        return;
    } else {
        *head = (*head)->next;
        if(*head == nullptr)
            (*head)->prev = nullptr;
        free(temp);
        return;
        
    }
}


void DLLDelete_back(struct DLLNode **tail)
{
    struct DLLNode *temp, *temp2;
    temp = *tail;

    if(*tail == nullptr){
        printf("List is empty");
        return;
    } else {
        *tail = (*tail)->prev;
        if(*tail == nullptr)
            (*tail)->next = nullptr;
        free(temp);
        return;
        
    }
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
    struct DLLNode *tail = nullptr;
    DLLInsert(&head, 15, 1);
    DLLInsert(&head, 25, 2);
    DLLInsert(&head, 35, 3);
    DLLInsert(&head, 45, 4);
    print(&head);

    DLLDelete(&head, 1);
    print(&head);
    
    DLLDelete(&head, 2);
    print(&head);
    
    cout << endl;
    cout << "Call to function push front: " << endl;
    push_front(&head,&tail, 400);
    print(&head);
    cout << endl;
    
    cout << "Call to function push back: " << endl;
    push_BACK(&head, &tail, 1000);
    print(&head);
    cout << endl;
    
    
    cout << "Call to function delete front: " << endl;
    DLLDelete_front(&head);
    print(&head);
    cout << endl;
    
    cout << "Call to function delete back: " << endl;
    DLLDelete_back(&tail);
    print(&head);
    cout << endl;
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode (int data){
    struct Node* cNode = (struct Node*) malloc(sizeof(struct Node));
    cNode->data = data;
    cNode->next = NULL;
    return cNode;
}

struct Node* insertAtBegin(struct Node* head, int data) {
    struct Node* cNode = createNode(data);
    // Checking condition if list is empty or not;
    if (head == NULL){
        head = cNode;
        head->next = head;
    }

    // If list not empty;
    struct Node* tNode = head;
    cNode->next = tNode;
    while (tNode->next != head)
        tNode = tNode->next;
    tNode->next = cNode;
    head = cNode;
    return head;
}

void insertAtEnd(struct Node* head, int data) {
    struct Node* cNode = createNode(data);
    // Checking condition if list is empty or not;
    if (head == NULL){
        head = cNode;
        head->next = head;
    }

    // If list not empty;
    struct Node* tNode = head;
    while (tNode->next != head)
        tNode = tNode->next;
    tNode->next = cNode;
    cNode->next = head;
}

void insertAfterNode (struct Node* head, int node, int data) {
    struct Node* cNode = createNode (data);
    struct Node* tNode = head;
    while (tNode->data != node && tNode->next != head)
        tNode = tNode->next;
    cNode->next = tNode->next;
    tNode->next = cNode;
}

void insertBeforeNode (struct Node* head, int node, int data) {
    struct Node* cNode = createNode (data);
    struct Node* tNode = head;
    while (tNode->next->data != node && tNode->next != head)
        tNode = tNode->next;
    cNode->next = tNode->next;
    tNode->next = cNode;
}

struct Node* deleteFirst (struct Node* head) {
    if (head == NULL){
        printf("Your list is empty...");
        return;
    }

    struct Node* cNode = head;
    printf("\n");
    while (cNode->next != head)
        cNode = cNode->next;
    
    struct Node* fNode = head;
    head = head->next;
    cNode->next = head;
    free(fNode);
    return head;
}

void deleteLast (struct Node* head) {
    struct Node* tNode = head;
    struct Node* ttNode = head;
    tNode = tNode->next;
    while (tNode->next != head){
        ttNode = ttNode->next;
        tNode = tNode->next;
    }
    ttNode->next = head;
    free(tNode);
}

void deleteAfterNode (struct Node* head, int node) {
    struct Node* tNode = head;
    struct Node* ttNode = NULL;
    while (tNode->data != node && tNode->next != head)
        tNode = tNode->next;
    ttNode = tNode->next;
    tNode->next = tNode->next->next;
    free(ttNode);
}

void deleteBeforeNode (struct Node* head, int node) {
    struct Node* tNode = head;
    struct Node* ttNode = NULL;
    while (tNode->next->next->data != node && tNode->next != head)
        tNode = tNode->next;
    ttNode = tNode->next;
    tNode->next = tNode->next->next;
    free(ttNode);
}

void traversalList(struct Node* head){
    struct Node* tNode = head;
    printf("\nYour List is ... \n");
    if (tNode == NULL){
        printf("List is Empty...\n");
        return;
    }

    while (tNode->next != head) {
        printf("%d | ", tNode->data);
        tNode = tNode->next;
    }
    printf("%d | ", tNode->data);
}

int main (){
    // struct Node* head = NULL;
    struct Node* head = createNode(5);
    struct Node* hNext = createNode(56);
    head->next = hNext;
    struct Node* hhNext = createNode(566);
    struct Node* hh1Next = createNode(506);
    hNext->next = hhNext;
    hhNext->next = hh1Next;
    hh1Next->next = head;
    // traversalList(head);
    head = insertAtBegin(head, 45);
    head = insertAtBegin(head, 40);
    head = insertAtBegin(head, 65);
    // traversalList(head);
    insertAtEnd(head, 665);
    insertAtEnd(head, 34);
    insertAtEnd(head, 24);
    // traversalList(head);
    insertAfterNode(head, 665, 12);
    insertAfterNode(head, 65, 25);
    insertBeforeNode(head, 40, 50);
    insertBeforeNode(head, 566, 0);
    traversalList(head);
    head = deleteFirst(head);
    // traversalList(head);
    deleteLast(head);
    traversalList(head);
    deleteAfterNode(head, 0);
    deleteAfterNode(head, 5);
    deleteBeforeNode(head, 45);
    deleteBeforeNode(head, 665);
    traversalList(head);
    
    return 0;
}
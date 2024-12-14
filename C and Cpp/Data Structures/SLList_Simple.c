#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode (int data) {
    struct Node* cNode = (struct Node*) malloc(sizeof(struct Node));
    cNode->data = data;
    cNode->next = NULL;
    return cNode;
}

struct Node* insertAtBegin (struct Node* head, int data) {
    struct Node* cNode = createNode(data);
    cNode->next = head;
    return cNode;
}

// struct Node*
void insertAtEnd (struct Node* head, int data) {
    struct Node* cNode = createNode(data);
    struct Node* tNode = head;
    while (tNode->next != NULL)
        tNode = tNode->next;
    
    tNode->next = cNode;
    // return head;
}

void insertAfterNode (struct Node* head, int node, int data) {
    struct Node* cNode = createNode (data);
    struct Node* tNode = head;
    while (tNode->data != node)
        tNode = tNode->next;
    cNode->next = tNode->next;
    tNode->next = cNode;
}

void insertBeforeNode (struct Node* head, int node, int data) {
    struct Node* cNode = createNode (data);
    struct Node* tNode = head;
    while (tNode->next->data != node)
        tNode = tNode->next;
    cNode->next = tNode->next;
    tNode->next = cNode;
}

struct Node* deleteFirst (struct Node* head) {
    struct Node* cNode = head;
    head = head->next;
    free(cNode);
    return head;
}

void deleteLast (struct Node* head) {
    struct Node* tNode = head;
    struct Node* ttNode = head;
    tNode = tNode->next;
    while (tNode->next != NULL){
        ttNode = ttNode->next;
        tNode = tNode->next;
    }
    ttNode->next = NULL;
    free(tNode);
}

void deleteAfterNode (struct Node* head, int node) {
    struct Node* tNode = head;
    struct Node* ttNode = NULL;
    while (tNode->data != node && tNode != NULL)
        tNode = tNode->next;
    ttNode = tNode->next;
    tNode->next = tNode->next->next;
    free(ttNode);
}

void deleteBeforeNode (struct Node* head, int node) {
    struct Node* tNode = head;
    struct Node* ttNode = NULL;
    while (tNode->next->next->data != node && tNode != NULL)
        tNode = tNode->next;
    ttNode = tNode->next;
    tNode->next = tNode->next->next;
    free(ttNode);
}

void traversalList(struct Node* head){
    printf("\nYour List is ... \n");
    while (head != NULL) {
        printf("%d --> ", head->data);
        head = head->next;
    }
    printf("NULL");

}

int main (){
    struct Node* head = createNode(5);
    struct Node* hNext = createNode(56);
    head->next = hNext;
    struct Node* hhNext = createNode(566);
    hNext->next = hhNext;
    head = insertAtBegin(head, 356);
    insertAtEnd(head, 36);
    insertBeforeNode(head, 56, 55);
    insertAfterNode(head, 566, 567);
    traversalList(head);
    head = deleteFirst(head);
    traversalList(head);
    deleteLast(head);
    traversalList(head);
    deleteBeforeNode(head, 56);
    traversalList(head);
    deleteAfterNode(head, 56);
    traversalList(head);
    
    return 0;
}
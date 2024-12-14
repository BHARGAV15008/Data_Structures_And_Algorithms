#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode (int data) {
    struct Node* cNode = (struct Node*) malloc(sizeof(struct Node));
    cNode->data = data;
    cNode->left = NULL;
    cNode->right = NULL;
}

struct Node* insertAtBegin(struct Node* head, int data) {
    struct Node* cNode = createNode(data);
    cNode->right = NULL;
    cNode->left = head;
    head->right = cNode;
    return cNode;
}

void insertAtEnd(struct Node* head, int data) {
    struct Node* cNode = createNode(data);
    struct Node* tNode = head;
    while(tNode->left != NULL)
        tNode = tNode->left;
    tNode->left = cNode;
    cNode->right = tNode;
}

void insertBeforeNode (struct Node* head, int node, int data) {
    struct Node* cNode = createNode(data);
    struct Node* tNode = head;
    while (tNode->data != node)
        tNode = tNode->left;
    cNode->right = tNode->right;
    cNode->left = tNode;
    tNode->right = cNode;
    cNode->right->left = cNode;
}

void insertAfterNode (struct Node* head, int node, int data) {
    struct Node* cNode = createNode(data);
    struct Node* tNode = head;
    while (tNode->data != node)
        tNode = tNode->left;
    cNode->left = tNode->left;
    cNode->right = tNode;
    tNode->left = cNode;
    cNode->left->right = cNode;
}

void traversalList (struct Node* head) {
    printf("\nYour List is ...\n");
    while (head != NULL){
        printf("%d | ", head->data);
        head = head->left;
    }
    printf("NULL");
}

int main (){
    // struct Node* head = NULL;
    struct Node* head = createNode(5);
    struct Node* hNext = createNode(56);
    head->left = hNext;
    head->right = NULL;
    struct Node* hhNext = createNode(566);
    struct Node* hh1Next = createNode(506);
    hNext->left = hhNext;
    hNext->right = head;
    hhNext->left = hh1Next;
    hhNext->right = hNext;
    hh1Next->left = NULL;
    hh1Next->right = hhNext;
    // traversalList(head);
    head = insertAtBegin(head, 45);
    head = insertAtBegin(head, 40);
    head = insertAtBegin(head, 65);
    // traversalList(head);
    insertAtEnd(head, 665);
    insertAtEnd(head, 34);
    insertAtEnd(head, 24);
    traversalList(head);
    insertBeforeNode(head, 40, 50);
    insertBeforeNode(head, 566, 0);
    insertAfterNode(head, 665, 12);
    insertAfterNode(head, 65, 25);
    traversalList(head);
    // head = deleteFirst(head);
    // // traversalList(head);
    // deleteLast(head);
    // traversalList(head);
    // deleteAfterNode(head, 0);
    // deleteAfterNode(head, 5);
    // deleteBeforeNode(head, 45);
    // deleteBeforeNode(head, 665);
    // traversalList(head);
 
    
    return 0;
}
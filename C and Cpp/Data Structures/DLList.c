#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtStart(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

struct Node* insertBeforeNode(struct Node* head, int data, int target) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return NULL;
    }
    struct Node* current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Target node not found.\n");
        return head;
    }
    newNode->prev = current->prev;
    newNode->next = current;
    if (current->prev != NULL) {
        current->prev->next = newNode;
    }
    current->prev = newNode;
    if (head == current) {
        return newNode;
    }
    return head;
}

struct Node* insertAfterNode(struct Node* head, int data, int target) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return NULL;
    }
    struct Node* current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Target node not found.\n");
        return head;
    }
    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    return head;
}

struct Node* deleteFirstNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* newHead = head->next;
    if (newHead != NULL) {
        newHead->prev = NULL;
    }
    free(head);
    return newHead;
}

struct Node* deleteLastNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return head;
}

struct Node* deleteBeforeNode(struct Node* head, int target) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL || head->next->data == target) {
        printf("Cannot delete before the first node.\n");
        return head;
    }
    struct Node* current = head->next;
    while (current->next != NULL && current->next->data != target) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Target node not found.\n");
        return head;
    }
    struct Node* nodeToDelete = current->prev;
    current->prev = nodeToDelete->prev;
    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = current;
    }
    free(nodeToDelete);
    return head;
}

struct Node* deleteAfterNode(struct Node* head, int target) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Target node not found or there is no node after the target.\n");
        return head;
    }
    struct Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = current;
    }
    free(nodeToDelete);
    return head;
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly linked list: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Node* head = NULL;

    int choice, data, target;

    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at the start\n");
        printf("2. Insert at the end\n");
        printf("3. Insert before a node\n");
        printf("4. Insert after a node\n");
        printf("5. Delete first node\n");
        printf("6. Delete last node\n");
        printf("7. Delete before a node\n");
        printf("8. Delete after a node\n");
        printf("9. Traverse the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("cls");

        switch (choice) {
            case 1:
                printf("Enter data to insert at the start: ");
                scanf("%d", &data);
                head = insertAtStart(head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the target node value before which to insert: ");
                scanf("%d", &target);
                head = insertBeforeNode(head, data, target);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the target node value after which to insert: ");
                scanf("%d", &target);
                head = insertAfterNode(head, data, target);
                break;
            case 5:
                head = deleteFirstNode(head);
                break;
            case 6:
                head = deleteLastNode(head);
                break;
            case 7:
                printf("Enter the target node value before which to delete: ");
                scanf("%d", &target);
                head = deleteBeforeNode(head, target);
                break;
            case 8:
                printf("Enter the target node value after which to delete: ");
                scanf("%d", &target);
                head = deleteAfterNode(head, target);
                break;
            case 9:
                traverse(head);
                break;
            case 0:
                freeList(head);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

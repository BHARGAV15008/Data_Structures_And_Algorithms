#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBegin(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertBeforeNode(struct Node** head, struct Node* nextNode, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (*head == nextNode) {
        insertAtBegin(head, data);
        return;
    }

    struct Node* current = *head;
    while (current != NULL && current->next != nextNode) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Given nextNode is not present in the list.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = current->next;
    current->next = newNode;
}

void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
}

void deleteAfterNode(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("Cannot delete, previous node is NULL or next node is NULL.\n");
        return;
    }

    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp);
}

void deleteBeforeNode(struct Node** head, struct Node* nextNode) {
    if (*head == NULL || nextNode == NULL || *head == nextNode) {
        printf("Cannot delete, list is empty or given nextNode is NULL.\n");
        return;
    }

    if ((*head)->next == nextNode) {
        deleteFirstNode(head);
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->next != nextNode) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Given nextNode is not present in the list.\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

void traverseList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    int choice, data;
    char ch;
    do {
        printf("\nOperations:\n");
        printf("1. Insert at start\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a node\n");
        printf("4. Insert before a node\n");
        printf("5. Delete first node\n");
        printf("6. Delete last node\n");
        printf("7. Delete after a node\n");
        printf("8. Delete before a node\n");
        printf("9. Display the list\n");
        printf("0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        system("cls");

        switch (choice) {
            case 1:
                printf("Enter data to insert at the start: ");
                scanf("%d", &data);
                insertAtBegin(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the node data after which to insert: ");
                int afterData;
                scanf("%d", &afterData);
                struct Node* afterNode = head;
                while (afterNode != NULL && afterNode->data != afterData) {
                    afterNode = afterNode->next;
                }
                insertAfterNode(afterNode, data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the node data before which to insert: ");
                int beforeData;
                scanf("%d", &beforeData);
                struct Node* beforeNode = head;
                while (beforeNode != NULL && beforeNode->data != beforeData) {
                    beforeNode = beforeNode->next;
                }
                insertBeforeNode(&head, beforeNode, data);
                break;
            case 5:
                deleteFirstNode(&head);
                break;
            case 6:
                deleteLastNode(&head);
                break;
            case 7:
                printf("Enter the node data after which to delete: ");
                int afterDelData;
                scanf("%d", &afterDelData);
                struct Node* afterDelNode = head;
                while (afterDelNode != NULL && afterDelNode->data != afterDelData) {
                    afterDelNode = afterDelNode->next;
                }
                deleteAfterNode(afterDelNode);
                break;
            case 8:
                printf("Enter the node data before which to delete: ");
                int beforeDelData;
                scanf("%d", &beforeDelData);
                struct Node* beforeDelNode = head;
                while (beforeDelNode != NULL && beforeDelNode->data != beforeDelData) {
                    beforeDelNode = beforeDelNode->next;
                }
                deleteBeforeNode(&head, beforeDelNode);
                break;
            case 9:
                system("cls");
                traverseList(head);
                break;
            case 0:
                printf("Exiting.\n");
                freeList(head);
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }

    
        while ((ch = getchar()) != '\n' && ch != EOF);

    } while (1);

    return 0;
}


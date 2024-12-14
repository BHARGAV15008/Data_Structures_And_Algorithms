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

void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    *head = newNode;
}

void insertAtLast(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertBeforeNode(struct Node** head, int data, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot insert before the node.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    while (temp->next != *head && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == *head && temp->next->data != key) {
        printf("Key not found in the list. Cannot insert before the node.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfterNode(struct Node** head, int data, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot insert after the node.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    while (temp->data != key && temp->next != *head) {
        temp = temp->next;
    }

    if (temp->data != key) {
        printf("Key not found in the list. Cannot insert after the node.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete first node.\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    if (temp == *head) {
        *head = NULL;
    } else {
        struct Node* firstNode = *head;
        *head = (*head)->next;
        temp->next = *head;
        free(firstNode);
    }
}

void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete last node.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = *head;
    }
    free(temp);
}

void deleteNodeAfter(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete node after the node.\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->data != key && temp->next != *head) {
        temp = temp->next;
    }

    if (temp->data != key) {
        printf("Key not found in the list. Cannot delete node after the node.\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

void deleteNodeBefore(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete node before the node.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;
    struct Node* prevPrev = NULL;
    int found = 0;

    while (temp->data != key && temp->next != *head) {
        prevPrev = prev;
        prev = temp;
        temp = temp->next;
        found = 1;
    }

    if (temp->data != key) {
        printf("Key not found in the list. Cannot delete node before the node.\n");
        return;
    }

    if (!found) {
        while (temp->next != *head) {
            temp = temp->next;
        }
    }

    if (prevPrev == NULL) {
        *head = temp;
    } else {
        prevPrev->next = temp;
    }
    free(prev);
}

void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    do {
        printf("\n===== Circular Linked List Operations =====\n");
        printf("1. Insert at the Start\n");
        printf("2. Insert at the Last\n");
        printf("3. Insert Before a Node\n");
        printf("4. Insert After a Node\n");
        printf("5. Delete First Node\n");
        printf("6. Delete Last Node\n");
        printf("7. Delete Node After a Node\n");
        printf("8. Delete Node Before a Node\n");
        printf("9. Traverse the List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("cls");

        switch (choice) {
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            insertAtStart(&head, data);
            break;
        case 2:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            insertAtLast(&head, data);
            break;
        case 3:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the key before which to insert: ");
            scanf("%d", &key);
            insertBeforeNode(&head, data, key);
            break;
        case 4:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the key after which to insert: ");
            scanf("%d", &key);
            insertAfterNode(&head, data, key);
            break;
        case 5:
            deleteFirstNode(&head);
            break;
        case 6:
            deleteLastNode(&head);
            break;
        case 7:
            printf("Enter the key after which to delete: ");
            scanf("%d", &key);
            deleteNodeAfter(&head, key);
            break;
        case 8:
            printf("Enter the key before which to delete: ");
            scanf("%d", &key);
            deleteNodeBefore(&head, key);
            break;
        case 9:
            traverseList(head);
            break;
        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);


    struct Node* temp = head;
    while (temp) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}


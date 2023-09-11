
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
//create new empty node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to append a new node to the end of the list
void append(struct Node **head, int data) {
       struct Node *new_node = malloc(sizeof(struct Node)); //create empty node
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}
// Function to display the list in forward order
void displayForward(struct Node **head) {
    struct Node* current = *head;
    while (current != NULL) {
        printf("%d  ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to display the list in backward order
void displayBackward(struct Node **head) {
     struct Node* current = *head;
    // Move to the last node
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }  
    while (current != NULL) { // Traverse backward and print the list
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
    
}
// Function to free the memory allocated for the list
void freeList(struct Node **head) {
    struct Node* current = *head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
void insertAtPosition(struct Node **head, int data, int position) {
    struct Node* new_node = createNode(data);

    if (position <= 0) {
        // Insert at the beginning of the list
        new_node->next = *head;
        if (*head != NULL) {
            *head = new_node;
        }
        *head = new_node;
    } else {
        struct Node* current = *head;
        int current_position = 0;

        while (current_position < position - 1 && current != NULL) {
            current = current->next;
            current_position++;
        }

        if (current == NULL) {
            // Insert at the end of the list
            struct Node* last_node = *head;
            while (last_node->next != NULL) {
                last_node = last_node->next;
            }
            last_node->next = new_node;
            new_node->prev = last_node;
          } 
        else {
            // Insert at the middle of the list
            new_node->prev = current;
            new_node->next = current->next; 
            if (current->next != NULL) {
                current->next->prev = new_node;
            }
            current->next = new_node;
          
        }
    }
}
void insertAtPosition2(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    struct Node* current = *head;

    // Handle the case where the new node should be the first node
    if (position == 1) {
        newNode->prev = NULL;
        newNode->next = current;
        current->prev = newNode;
        *head = newNode;
        return;
    }

    int currentPosition = 1;
    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->prev = current;
    newNode->next = current->next;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;
}

// Example usage
int main() {
    struct Node* head;
    head=NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
     printf("Doubly Linked List (Forward):\n");
      displayForward(&head);

    insertAtPosition(&head, 4, 0); // Insert 4 at position 1 (second position)
    // displayForward(&head); // only on use on forword
    printf("\nDoubly Linked List (Backward):\n");
    displayBackward(&head); 

    freeList(&head);

    return 0;
}
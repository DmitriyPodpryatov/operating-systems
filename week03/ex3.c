#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};
typedef struct Node* List;

List create_node(int);
void print_list(List*);
void insert_node(List*, List);
void delete_node(List*, List);

int main() {

    // Create list with value 0: {0}
    List head = create_node(0);
    printf("Create 0: ");
    print_list(&head);

    // Add 1 after 0: {0, 1}
    List second = create_node(1);
    insert_node(&head, second);
    printf("Add 1 after 0: ");
    print_list(&head);

    // Add 2 after 1: {0, 1, 2}
    List third = create_node(2);
    insert_node(&second, third);
    printf("Add 2 after 1: ");
    print_list(&head);

    // Add 3 after 0: {0, 3, 1, 2}
    List fourth = create_node(3);
    insert_node(&head, fourth);
    printf("Add 3 after 0: ");
    print_list(&head);

    // Delete 3: {0, 1, 2}
    delete_node(&head, fourth);
    printf("Delete 3: ");
    print_list(&head);

    return 0;

}

List create_node(int value) {
    List node = (List) malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void print_list(List* head) {
    List current = *head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    putchar('\n');
}

void insert_node(List* tail, List node) {
    // If tail doesn't exist
    if (*tail == NULL) {
        return;
    }
    // If tail is the last element in the list
    if ((*tail)->next == NULL) {
        (*tail)->next = node;
    }
    else {
        node->next = (*tail)->next;
        (*tail)->next = node;
    }
}

void delete_node(List* head, List node) {
    // Deleting the first element in the list
    if (*head == node) {
        node->next = NULL;
        return;
    }
    List current = *head;
    List previous;
    // Reach the node and "delete" it from the list
    while (current != NULL && current != node) {
        previous = current;
        current = current->next;
    }
    // If no such nodes in the list
    if (current == NULL) {
        return;
    }
    // Deleting the node
    previous->next = current->next;
    current->next = NULL;
}
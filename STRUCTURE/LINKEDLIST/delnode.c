
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
  char str[20];
  struct node *ptr;
};
void deleteFirstNode(struct node **head_ref)
{
  if (*head_ref == NULL)
  {
    printf("Linked list is empty. Nothing to delete.\n");
    return;
  }
  struct node *temp = *head_ref;
  *head_ref = (*head_ref)->ptr;

  // Free the memory allocated for the first node
  free(temp);
}

void printLinkedList(struct node *head)
{
  struct node *current_node = head;
  while (current_node != NULL)
  {
    printf("%s\n", current_node->str);
    current_node = current_node->ptr;
  }
}

int main()
{
  struct node *head = NULL;
  struct node *node1 = (struct node *)malloc(sizeof(struct node));
  struct node *node2 = (struct node *)malloc(sizeof(struct node));
  struct node *node3 = (struct node *)malloc(sizeof(struct node));
  strcpy(node1->str, "Node 1");
  strcpy(node2->str, "Node 2");
  strcpy(node3->str, "Node 3");
  node1->ptr = node2;
  node2->ptr = node3;
  node3->ptr = NULL;
  head = node1;

  printf("Linked list before deletion:\n");
  printLinkedList(head);
  deleteFirstNode(&head);

  printf("\nLinked list after deletion:\n");
  printLinkedList(head);
  struct node *current_node = head;
  while (current_node != NULL)
  {
    struct node *temp = current_node;
    current_node = current_node->ptr;
    free(temp);
  }

  return 0;
}

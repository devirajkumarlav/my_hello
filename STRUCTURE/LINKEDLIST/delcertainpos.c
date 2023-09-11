
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
  char str[20];
  struct node *ptr;
};
void deleteNodeAtPosition(struct node **head_ref, int position)
{
  if (*head_ref == NULL)
  {
    printf("Linked list is empty. Nothing to delete.\n");
    return;
  }

  
  if (position == 1)// If the position is 1 
  {
    struct node *temp = *head_ref;
    *head_ref = (*head_ref)->ptr;
    free(temp);
    return;
  }

  // Traverse the linked list
  struct node *previous_node = *head_ref;
  for (int i = 1; i < position - 1 && previous_node != NULL; i++)
  {
    previous_node = previous_node->ptr;
  }

  if (previous_node == NULL || previous_node->ptr == NULL)
  {
    printf("Position is out of range. Node not found.\n");
    return;
  }
  struct node *node_to_delete = previous_node->ptr;  // Save the node to delete in a temporary pointer
  previous_node->ptr = previous_node->ptr->ptr;
  free(node_to_delete);
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
  int position_to_delete = 2;
  deleteNodeAtPosition(&head, position_to_delete);

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

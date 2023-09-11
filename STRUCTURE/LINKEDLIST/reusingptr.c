
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
  char str[20];
  struct node *ptr;
};

int main()
{
  struct node *head = (struct node *)malloc(sizeof(struct node));
  struct node *current = (struct node *)malloc(sizeof(struct node));

  if (head == NULL || current == NULL)
  {
    printf("Memory allocation failed. Exiting...\n");
    return 1;
  }

  strcpy(head->str, "my first linked");
  head->ptr = NULL;

  strcpy(current->str, "my second linked");
  current->ptr=NULL;
  head->ptr = current; //link the node1 to node2
  
  //reusing the pointer
  current = (struct node *)malloc(sizeof(struct node));
 
  strcpy(current->str, "my third linked");
  current->ptr = NULL;
    head->ptr->ptr=current; //link the node1 to node2 to node3
  // Traverse the linked list and print the data of each node
  struct node *current_node = head; //add start address to pointer
  while (current_node != NULL)
  {
    printf("%s\n", current_node->str);
    current_node = current_node->ptr; //move to next location
  }

  free(head);
  free(current);
  return 0;
}
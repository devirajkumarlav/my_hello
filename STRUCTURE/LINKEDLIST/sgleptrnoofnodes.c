
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
  struct node *head = NULL; // Initialize the head pointer to NULL (empty list)
  head = (struct node *)malloc(sizeof(struct node));
  if (head == NULL)  // Check if memory allocation was successful
  {
    printf("failed ...\n");
    return 1;
  }
  strcpy(head->str, "Node 1");
  head->ptr = NULL;
  head->ptr = (struct node *)malloc(sizeof(struct node));  
  if (head->ptr == NULL)// Check if memory allocation was successful
  {
    printf("failed ...\n");
    free(head);
    return 1;
  }
  strcpy(head->ptr->str, "Node 2");
  head->ptr->ptr = NULL;
  head->ptr->ptr = (struct node *)malloc(sizeof(struct node));
  if (head->ptr->ptr == NULL)// Check if memory allocation was successful
  {
    printf("failed ...\n");
    free(head->ptr); // Free previously allocated memory before exiting
    free(head);
    return 1;
  }
  strcpy(head->ptr->ptr->str, "Node 3");
  head->ptr->ptr->ptr = NULL;
  
  // Traverse the linked list and print the data of each node
  struct node *current_node = head;
  int count = 1;
  while (current_node != NULL)
  {
    printf("Node %d: %s\n", node_count, current_node->str);
    current_node = current_node->ptr;
    count++;
  }
  current_node = head; //reallocate address to free memory
  while (current_node != NULL)
  {
    struct node *temp = current_node;
    current_node = current_node->ptr;
    free(temp); //free each node created
  }

  return 0;
}
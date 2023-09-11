
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
  char str[20];
  struct node *ptr;
};

struct node *searchLinkedList(struct node *head, const char *value)
{
  struct node *current_node = head;
  while (current_node != NULL)
  {
    if (strcmp(current_node->str, value) == 0)
    {
      return current_node; //return the address of the node
    }

    current_node = current_node->ptr;//move to next node traverse
  }

  return NULL;
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

  printf("Linked list:\n");
  printLinkedList(head);
  const char *value_to_search = "Node 2";
  struct node *result = searchLinkedList(head, value_to_search);

  if (result != NULL)
  {
    printf("\nValue found in the linked list.\n");
  }
  else
  {
    printf("\nValue not found in the linked list.\n");
  }
  struct node *current_node = head;
  while (current_node != NULL)
  {
    struct node *temp = current_node;
    current_node = current_node->ptr;
    free(temp);
  }

  return 0;
}

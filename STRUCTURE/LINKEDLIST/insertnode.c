
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
  char str[20];
  struct node *ptr;
};

void insertNode(struct node **head_ref,char *data)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  
  if (new_node == NULL)
  {
    printf("Memory allocation failed. Exiting...\n");
    return;
  }

  strcpy(new_node->str, data);
  new_node->ptr = NULL;

  if (*head_ref == NULL)
  {
    *head_ref = new_node;
    return;
  }

  // Traverse the linked list to find the last node
  struct node *current_node = *head_ref;
  while (current_node->ptr != NULL)
  {
    current_node = current_node->ptr;
  }

  // Update the last node
  current_node->ptr = new_node;
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
/*void node_at_cetain(struct node **head,int pos)
{
  struct Node *next1=NULL;
  struct Node *current=*head;
  struct Node *new_bourn=malloc(sizeof(struct Node));
  new_bourn->data=4;
  new_bourn->next=NULL;
  int i=1;
  while(current->next!=NULL && i!=pos)
  {
    i++;
    current=current->next;
  } 
  //next1=current->next;
  //current->next=new_bourn;
  //new_bourn->next=nex1;
  new_bourn->next=current->next;
  current->next=new_bourn;
}*/

int main()
{
  struct node *head = NULL;

  insertNode(&head, "Node 1");
  insertNode(&head, "Node 2");
  insertNode(&head, "Node 3");
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

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
  struct node *current2 = (struct node *)malloc(sizeof(struct node));

  if (head == NULL || current == NULL || current2 == NULL)
  {
    printf("Memory allocation failed. Exiting...\n");
    return 1;
  }
  strcpy(head->str, "my first linked");
  head->ptr = current;
  strcpy(current->str, "my second linked");
  current->ptr = current2;
  strcpy(current2->str, "my third linked");
  current2->ptr = NULL;
  // Traverse the linked list and print the data of each node
  struct node *current_node = head;
  while (current_node != NULL)
  {
    printf("%s\n", current_node->str);
    current_node = current_node->ptr;
  }
  free(head);
  free(current);
  free(current2);
  return 0;
}
/*#include<stdio.h>
#pragma pack(1)
struct name
{
  int n;
  char ch;
  struct name *link;
};
void insert(struct name **head);
struct name *reveselist(struct name *head);
int main() {
   struct name *head=malloc(sizeof(struct name));
   head->n=2;
   head->ch='a';
   head->link=NULL; // filling the data
  for(int i=0;i<3;i++)
  insert(&head); // funtion to add data as given
  struct name *temp=head;
  for(int i=0;i<3;i++){ struct name *del=head;
  while(del->link!=NULL)
  {
    temp=del;
    del=del->link;
  }  
  temp->link=NULL; //deleting the last node of list
  free(del);
  }
  temp=NULL;
  free(head);
  head=NULL;
  return 0;
}
struct name *reveselist(struct name *head)
{
  struct name *next=NULL;
  struct name *pre=NULL;
  struct name *current=head;
  
  while(current!=NULL)
  {
    next=current->link;
    current->link=pre;
    pre=current;
    current=next;
  }
  return pre;
}
void insert(struct name **head)
{
    struct name *current=malloc(sizeof(struct name));
    if((*head)->link==NULL){ current->n=4; current->ch='b'; current->link=NULL;
       (*head)->link=current;}
       else
       {
         struct name *trance=*head; //tranction of mine
         while(trance->link!=NULL)
         {
           trance=trance->link; //it move to nest position of list
         }
         current->n=4; current->ch='b';current->link=NULL;
         trance->link=current; // add to node last position of list
       }
}*/
/*struct name
{
  int num;
  char ch[4];
  double d;
  float fl;
  struct name *p;
  };
  struct name1
{
  int num;
  char ch[4];
  double d;
  float fl;
  struct name *p;
  };
int main() {struct name1 hy;
  struct name1 *pq=&hy;
  struct name hi;
  struct name *ptr=&hi;
  hi.num=23;
  hi.ch[4]="dev";
  hi.d=346346;hi.fl=5.65;
  pq->num=23;
  pq->ch[4]="dev";
  pq->p=&hi;
  pq->p->p=&hy;
  pq->p->num=90;
  pq->d=346346;pq->fl=5.65;
  ptr->num=3;
  ptr->ch[4]="nev";
  ptr->d=46;ptr->fl=7.65;
  return 0;
}*/
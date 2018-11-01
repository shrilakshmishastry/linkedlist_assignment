#include<stdio.h>
#include<stdlib.h>

// structure for doubly linked list
struct list{
  int data;
  struct list * next;
  struct list * pre;
};
typedef struct list * Node;
Node head = NULL;

// function to create node of null link
Node get_node(){
  Node tmp ;
  tmp = (Node)malloc(sizeof(struct list));
  printf("Enter the data for node\n" );
  scanf("%d",&tmp->data );
  tmp->next = NULL;
  tmp->pre = NULL;
  return tmp;
}
// function to insert front
void insert_front(/* arguments */) {
  /* code */
  Node tmp = get_node();
  if(head == NULL){
    head =  tmp;
  }
  else{
    tmp -> next = head;
    head -> pre = tmp;
    head = tmp;
  }

}

// function to delete_front
void delete_front(/* arguments */) {
  /* code */
  Node tmp;
  if(head == NULL){
    printf("no node to delete\n" );
  }
  else if (head->next == NULL) {
    /* code */
    printf("delete node conatins the data %d\n",head->data );
    head = NULL;

  } else   {
    /* code */
    tmp = head;
    head = head->next;
    head -> pre = NULL;
    printf("deleted node conatins the data %d\n",tmp->data );
    free(tmp);
  }

}

// function to display the nodes
void display(){
  Node tmp;
  if(head == NULL){
    printf("no node to display\n" );
  }
  else{
    printf("nodes of the list contains the following data\n" );
    for(tmp=head; tmp; tmp= tmp->next){
      printf("%d\n",tmp->data );
    }
  }
}

// function to find the length of list
void list_len()
{
  int i=0;
  Node tmp;
  for (tmp=head;tmp;tmp=tmp->next) {
    /* code */
    i++;
  }
  printf("Length of list is\n" );
  printf("%d\n",i );
}

int main() {
  /* code */
  int ch;
  printf("Enter only integer value\n");
  while (1) {
    /* code */
    printf("Enter 1:insert at the front \n 2:delete at the front\n 3:display \n any other integer to exit\n" );
    scanf("%d",&ch );
    switch (ch) {
      case /* value */1:insert_front();
                        list_len();
                        break;
      case 2:delete_front();
            list_len();
              break;
      case 3:display()        ;
              list_len();
              break;
      default : exit(0)        ;
    }
  }
  return 0;
}

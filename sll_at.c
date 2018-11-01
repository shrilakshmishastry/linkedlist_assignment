#include<stdio.h>
#include<stdlib.h>

// structure to singly linked list
struct node{
  int data;
  struct node * next;
};

typedef struct node * Node;

Node head = NULL;

Node get_node(/* arguments */) {
  /*
      Function to create node
      :param null
      :return tmp (Node)
  */
  Node tmp;
  tmp = (Node)malloc(sizeof(struct node));
  printf("Enter the data for node\n");
  scanf("%d",&tmp->data );
  tmp->next = NULL;
  return tmp;
}

void insert_beg(/* arguments */) {
  /*
      Function to insert node at the  beginning of list
      :param NULL
      :return NULL
  */
  Node tmp = get_node();
  if(head == NULL){
    head = tmp;
  }
  else{
    tmp->next = head;
    head = tmp;
  }

}

void insert(){
  /*
      Function to insert node at given positon
  :param no
  :return NULL
  */
  int pos,c=0,k=0;
  printf("Enter the position\n" );
  scanf("%d",&pos );
  Node tmp = get_node();
  Node var;

  if(pos == 1 && head == NULL){
    head = tmp;

  }
  else if(pos == 1 && head->next == NULL){
    tmp->next = head;
    head = tmp;

  }
  else if (pos == 1){
    tmp->next = head;
    head =tmp;
  }
  else{
    c=1;
    for(var = head;var;var=var->next){
      c++;
      if(c == pos){
        k++;
        break;
      }

    }
    if(k){
      tmp->next=var->next;
      var->next=tmp;
    }
    else{
      printf("invalid position\n" );
    }
  }
}

void display(/* arguments */) {
  /*
      Function to display the content of list
      :param null
      :return NULL
 */
    Node tmp;
    if(head == NULL ){
      printf("No node to display\n" );
    }
    else{
      for(tmp= head; tmp;tmp=tmp->next){
        printf("%d\n",tmp->data );
      }
    }
}

void search() {
  /*
      Function to search the given node in the list
      :param Null
      :return NULL
  */
  Node tmp;
  int c=0,f=0;
  int var;
  printf("Enter the element to find\n");
  scanf("%d",&var );
  if (head == NULL) {
    /* code */
    printf("No element found\n" );
  }
  else{
      for(tmp= head;tmp;tmp=tmp->next){
        c++;
        if(tmp->data == var){
          f++;
          printf(" the variable found at %d\n",c );
        }
      }
      if(!f){
        printf("No element found\n" );
      }
  }
}

void swap(Node ptr1,Node ptr2) {
    /*
        Function to swap two numbers
        :param ptr ,ptr (Node)
        :return NULL
    */
    int tmp =ptr2->data;
    ptr2->data = ptr1->data;
    ptr1->data = tmp;

  }

void insert_ascendingorder(/* arguments */) {
  /*
    Function to insert the node according to its value
    :param Null
    :return NULL
  */
  Node tmp = get_node();
  Node var,test;

  if(head == NULL){

    head =tmp;
  }
  else if(head->next == NULL){
    if(head->data > tmp->data){
      tmp->next = head;
      head = tmp;

    }
    else{
      head->next = tmp;
    }
  }
  else{
    tmp->next = head;
    head = tmp;
    for(var=head;var;var=var->next){
      for(test=head; test->next!=NULL;test=test->next){
        if(var->data < test->data){
          swap(var,test);
        }
      }
    }

    display();
  }
}


int main(/* arguments */) {
  /*
      Function to main
      :param NULL
      :return null
 */
  int ch;
  printf("Enter only integer value\n");
  while (1) {
    /* code */
    printf("Enter 1:insert at beginning 2:insert at given position 3:insert ascending order 4:search 5:display any other to exit\n" );
    scanf("%d",&ch );
    switch (ch) {
      case /* value */1:insert_beg();
                        break;
      case 2:insert();break;
      case 3:insert_ascendingorder();break;
      case 4:search();break;
      case 5:display();break;
      default :exit(0);

    }
  }

  return 0;
}

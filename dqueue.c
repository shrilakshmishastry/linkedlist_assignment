#include<stdio.h>
#include<stdlib.h>

struct list {
  /*
      structure for node
      :variables  data (int) - to store data of int type,
                  next (struct list) - pointer to next node
                  pre (struct list) - pointer to previous node
  */
  int data;
  struct list  * next;
  struct list * pre;

};

// User defined data type of struct list
typedef struct list * Node;

// pointers to rear and front of node type
Node rear = NULL;
Node front = NULL;

// a counter to nodes


Node get_node(/* arguments */) {
  /*
    Function to allocate memory for a node
  :return tmp (Node)
  */
  Node tmp ;
  tmp = (Node)malloc(sizeof(struct list));
  tmp->next = NULL;
  tmp->pre = NULL;
  printf("Enter the data of node\n" );
  scanf("%d",&tmp->data);

  return tmp;
}



void insert_front(/* arguments */) {
  /*
      Function to insert node at front end
  :param Null
  :return void
 */
  Node tmp = get_node();
  if(front == NULL){
    front = tmp;
    rear = tmp;

  }
  else{
    front -> pre = tmp;
    tmp -> next = front;
    front = tmp;
    printf("%d\n",front->data );

  }

}

void insert_rear(/* arguments */) {
  /*
      Function to insert node at rear end
  :param Null
  :return void
 */
  Node tmp = get_node();
  if(rear == NULL){
    rear = tmp;
    front = tmp;

  }
  else{
    rear -> next = tmp;
    tmp -> pre = rear;
    rear = tmp;

  }
}

void dele_front(/* arguments */) {
  /*
      Function to delete a node from dele_front
  :param no
  :return null
  */
  Node tmp;
  if(front == NULL){
    printf("No node to delete\n" );
  }
  else if(front == rear){
    printf("The deleted node contains the data\n" );
    printf("%d\n",front->data );
    front = NULL;
    rear = NULL;

  }
  else{
    tmp = front;
    front = front->next;
    printf("The data of the node deleted is\n" );
    printf("%d\n",tmp->data );
    free(tmp);

  }

}

void dele_rear(){
  /*
      Function to delete a node at rear side
      param: NULL
      return: NULL
  */
  Node tmp;
  if(rear == NULL){
    printf("No node to delete\n" );
  }

  else if (front == rear) {
    /* code */
    printf("The deleted node contains the data\n" );
    printf("%d\n",rear->data );
    rear = NULL;
    front = NULL;


  }
  else{
    tmp = rear;
    rear = rear->pre;
    printf("The data of the node deleted is\n" );
    printf("%d\n",tmp->data );
    free(tmp);

  }


}

void display(/* arguments */) {
  /*
      Function to display the content of queue
  :param NULL
  :return NULL
  */
  Node i;
  if(front == NULL || rear == NULL){
    printf("Queue is empty\n" );
  }
  else if(front == rear){
    printf("Data at given node is\n" );
    printf("%d\n",front->data );
  }
  else{
    printf("The following data is present in the queue\n");
    for (i = front; i  ; i =i->next) {
      /* code */
      printf("%d\n",i->data );

    }
  }

}


int main() {
  /*
    Function to main
  :param - void
  :return (void)
  */
  int ch;
  printf("Enter only integer value\n");
  while (1) {
    /* code */
    printf("Enter 1:insert at rearer end\n 2:insert at front end\n 3:delete at rear end\n 4:delete at front \n 5:display \nany other to exit\n");
    scanf("%d",&ch );
    switch (ch) {
      case /* value */1:
        insert_rear();
        display();
        break;
      case 2:
        insert_front()  ;
        display();
        break;
      case   3:
        dele_rear();

        break;
      case  4:
        dele_front();
        display();
        break;
      case 5:display() ;
            break;
      default : exit(0)      ;

    }
  }


  return 0;
}

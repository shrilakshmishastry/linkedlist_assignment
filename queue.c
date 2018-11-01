#include<stdio.h>
#include<stdlib.h>

int cq[100],max,f=-1,r=-1;

int is_full(/* arguments */) {
  /*
      Function to find whether queue is full
  :param NULL
  :return 1 :if queue is full
            :else 0
  */
  if ((f == 0 && r == (max-1))|| (r == ((f-1)%max))) {
    /* code */
    return 1;
  }
  else{
    return 0;
  }

}

int is_empty(/* arguments */) {
  /*
      Function to check whether queue is empty
  :param NULL
  :return 1:if it is zero
            : else 0
  */
  if(f == -1 ){
    return 1;
  }
  return 0;
}

void insert() {
  /*
      Function to insert the element
  :param
  :return NULL
  */
  int ele;
  if(r == -1 ){
    printf("Enter element\n" );
    scanf("%d",&ele );
    f++;
    r=(r+1)%max;
    cq[r]=ele;
  }
  else
  {
    if(is_full()){
    printf("queue full\n" );

  }
  else{
    printf("Enter element\n" );
    scanf("%d",&ele );
    r=(r+1)%max;
    cq[r]=ele;
  }
}

}

void delete(/* arguments */) {
  /*
      Function to delete an entry
  :param Null
  :return Null
  */
  int ele;
  if(is_empty()){
    printf("No element to delete\n" );

  }
else if(f == r){
  ele = cq[f];
  printf("%d\n",ele );
  r =-1;
  f= -1;
}
  else{
    ele=cq[f];
    f=(f+1)%max;
    printf("%d\n",ele );
  }



}

void display(){
  /*
      Function to display the content of Queue
  :param NULL
  :return NULL
  */
  int i;
  if(is_empty()){
    printf("No element to display\n" );
  }
  else{
    if(r >= f){

      for ( i = f; i <=r; i++) {

        printf("%d\n",cq[i] );
        /* code */
      }
    }
    else{
      for(i=f;i<max;i++){
        printf("%d\n",cq[i] );
      }
      for(i=0;i<=r;i++){
        printf("%d\n",cq[i] );
      }
    }

  }

}

int main() {
  /*
    Function to main
  :param NULL
  :return NULL
  */
  int ch;
  printf("Enter only integer value\n");
  printf("Enter the maximun size of queue\n" );
  scanf("%d",&max );
  while (1) {
    /* code */
    printf("Enter 1:insert 2:delete 3:display anyother to exit\n");
    scanf("%d",&ch );
    switch (ch) {
      case /* value */1: insert();break;
      case 2:delete();
      break;
      case 3:display();break;
      default:exit(0);
    }
  }
  return 0;
}

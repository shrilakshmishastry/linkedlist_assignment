#include<stdio.h>
#include <stdlib.h>

// structure to define node
struct list{
  // integer type variable to store list data
  int data ;
  // pointer to link next node
  struct list * next;
};
// defing struct list type pointer
typedef struct list * NODE;
NODE head1 = NULL;
NODE head2 = NULL;
// function to create NODE
NODE get_node() {
  /* code */
  NODE tmp = (NODE)malloc(sizeof(struct list));
  printf("Enter the data to store in node \n" );
  scanf("%d",&tmp->data );
  tmp->next = NULL;

  return tmp;
}
NODE insert_beg(NODE ptr) {
  /* code */
    NODE tmp = get_node();
    if(ptr == NULL){
    ptr = tmp;
  }
  else{
    tmp->next=ptr;
    ptr=tmp;
  }

}

void concate(){
  """
    Function to concat two list.
    return void
  """
  NODE tmp;

  printf("Elements after concatination of two list\n" );
  if(head1 == NULL)  {
    for(tmp = head2;tmp;tmp=tmp->next){
      printf("%d\n",tmp->data );
    }
  }
  if(head2 == NULL)
  {
    for(tmp = head1;tmp;tmp=tmp->next){
      printf("%d\n",tmp->data );
    }
  }
  else{
    for(tmp = head1;tmp->next!=NULL;tmp=tmp->next){

    }
      tmp->next=head2;
      head2 = NULL;
    for (tmp=head1;tmp;tmp=tmp->next ) {
      /* code */
      printf("%d\n",tmp->data );
    }
    }
}

void list_len(NODE ptr){
  /*
    Function to find the length of list.
  :param ptr (NODE) - pointer to node typedef
  :return (int) -
  */
  int i=0;
  NODE tmp;
  for (tmp=ptr;tmp;tmp=tmp->next) {
    /* code */
    i++;
  }
  printf("Length of list is\n" );
  printf("%d\n",i );
}
// function to find reverse the list
NODE reverse(NODE ptr){
  NODE pre,next,current,tmp;

  next = ptr;
  current = NULL;
  while (next) {
    /* code */
    pre = current;
    current = next;
    next = next->next;
    current->next=pre;
  }
  ptr=current;
  printf("List after reverse\n" );
  for (tmp = current;tmp;tmp=tmp->next) {
    /* code */
    printf("%d\n",tmp->data );
  }
return ptr;
}

// function to main
 int main() {
  /* code */
  int ch;
  int n1,n2,i;
  NODE tmp,top ;

  while (1) {
    /* code */
    printf("Enter your choice 0:create 1:length 2:concate 3:reverse any other to exit\n");
    scanf("%d",&ch );
  switch (ch) {
    case 0:
    printf("Enter the number of nodes in first list\n" );
    scanf("%d",&n1 );
    for ( i = 0; i < n1; i++) {
      /* code */
      tmp =  get_node();
      if(head1 == NULL){
        head1 =  tmp;
      }
      else{
        tmp->next=head1;
        head1= tmp;
      }
    }
    printf("Enter the number of nodes in second list\n" );
    scanf("%d",&n2);
    for ( i = 0; i < n2; i++) {
      /* code */
      top =  get_node();
      if(head2 == NULL){
        head2 =  top;
      }
      else{
        top->next=head2;
        head2= top;
      }
    }
    break;
    case 1:   list_len(head1);
              list_len(head2);
                          break;
    case 2:  concate();
            break;
    case  3: head1 = reverse(head1);
            head2 = reverse(head2)      ;
                    break;
    default : exit(0)                ;
  }
}





  return 0;
}

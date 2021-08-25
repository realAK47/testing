#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,M,O,x,y,count=0;
    struct node{
    int data;
    struct node * next;
    };
    struct node * newnode,*head,*temp,*del;
    head=0;
    char check='y';
    while(check=='y'){
        count++;
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the element:");
        scanf("%d",&newnode->data);
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
            newnode->next=0;
        }
        printf("\nDo you want to insert another data y/n?:");
        scanf(" %c",&check);
    }
    char selection='y';
    while(selection = 'y')
    {
        printf("\n1-insertion\n2-deletion\n3-Display\nenter the selection:");
    scanf("%d",&N);
    switch(N){
        case 1 :
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next=head;
        head=newnode;
        break;
        case 2 :
        head=head->next;
        break;
        case 3 :
        temp=head;
        while(temp!=0){
            printf("\n%d",temp->data);
            temp=temp->next;
        }
        break;
        
        
    }
      printf("Do yoy want to continue y/n");
      scanf(" %c",&selection);
    }
    
    
}

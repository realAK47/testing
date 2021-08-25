
#include<stdio.h>
#include<stdlib.h>
void main(){
struct node
{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp;
head=0;
int choice=1;
while(choice==1){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0)
        head=temp=newnode;
    else
    {
        temp->next=newnode;
            temp=newnode;
    }
    printf("Enter choice (0 for exit or 1 for adding element): ");
    scanf("%d",&choice);
}

temp=head;
printf("Linked list before reversing = ");
while(temp!=0)
{
    printf("%d ",temp->data);
    temp=temp->next;
}
printf("\n");
struct node *prevnode,*currentnode,*nextnode;
prevnode=0;
currentnode=nextnode=head;
while(nextnode!=0)
{
    nextnode=nextnode->next;
    currentnode->next=prevnode;
    prevnode=currentnode;
    currentnode=nextnode;
}
head=prevnode;
temp=head;
printf("Linked list after reversing = ");
while(temp!=0)
{
    printf("%d ",temp->data);
    temp=temp->next;
}
}

















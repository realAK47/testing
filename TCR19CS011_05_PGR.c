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
        printf("\nDo you want to continue y/n?:");
        scanf(" %c",&check);
    }
    
    char choice = 'y';
    while(choice=='y')
    {printf("\n1-insertion\n2-deletion\n3-transverse\nenter the selection:");
    scanf("%d",&N);
    switch(N){
        case 1 :
        printf("\n1-insertion at beginning\n2-insertion at the end\n3-insertion at other position\nEnter your selection:");
        scanf("%d",&M);
        switch(M){
            case 1:
            newnode=(struct node *)malloc(sizeof(struct node));
            printf("Enter the data: ");
            scanf("%d",&newnode->data);
            newnode->next=head;
            head=newnode;
            break;
            case 2:
            temp=newnode;
            newnode=(struct node *)malloc(sizeof(struct node));
            printf("Enter the data: ");
            scanf("%d",&newnode->data);
            temp->next=newnode;
            break;
            case 3:
            printf("Enter the required position: ");
            scanf("%d",&x);
            temp=head;
            for(int i=0;i<(x-2);i++){
                temp=temp->next;
            }
            newnode=(struct node *)malloc(sizeof(struct node));
            printf("Enter the data: ");
            scanf("%d",&newnode->data);
            newnode->next=temp->next;
            temp->next=newnode;
            break;
        }
        break;
        case 2 :
        printf("\n1-Delete from the beginning\n2-Delete from the end\n3-Delete from the other position\nEnter selection: ");
        scanf("%d",&O);
        switch(O){
            case 1:
            head=head->next;
            break;
            case 2:
            temp=head;
            for(int i=0;i<count-2;i++){
                temp=temp->next;
            }
            temp->next=0;
            break;
            case 3:
            printf("\nposition to be deleted: ");
            scanf("%d",&y);
            temp=head;
            for(int i=0;i<y-2;i++){
                temp=temp->next;
                del=temp->next;
            }
            temp->next=del->next;
            break;
        }
        break;
        case 3:
        temp=head;
        while(temp!=0){
            printf("\n%d",temp->data);
            temp=temp->next;
        }
        break;
        
        
    }
        printf("\nDo you want to continue y/n : ");
        scanf(" %c",&choice);
    }
    
    
}

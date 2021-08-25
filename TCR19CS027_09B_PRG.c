#include <stdio.h>
#include <stdlib.h>

int ins = 0;
int del = 0;

struct Node
{
    int data;
    struct Node *rlink;
    struct Node *llink;
};
struct Node *availhead=NULL, *availtemp; // FOR THE AVAIL LIST

struct Node *create()
{   ++ins;
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("  Enter the data :");
    scanf("%d", &(newNode)->data);
    newNode->rlink = NULL;
    newNode->llink = NULL;
   
    return newNode;
}

void traverse(struct Node *head)
{
    struct Node *ptr = NULL;

    ptr = head;
    int i = 1;
    printf("  Presently LIST: ");
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ++i;
        ptr = ptr->rlink;
    }
    printf("\n");
}
struct Node *detach() //To detach a free memory location
{
   
    struct Node *ptr = NULL;
    if (availhead==NULL )
    {
      printf("\n  No garbage memory blocks available....could not allocate memory\n");
    }
    else{
    ptr = availhead;
    availhead = availhead->rlink;
    ptr->rlink = NULL; 
    printf("\n  Attached "); 
    --del;
        
    return ptr;    
    }

}

struct Node *insert(struct Node *head)
{
    struct Node *ptr = NULL, *temp = NULL;
    int i = 0;
    ptr = head;


    struct Node *node, *garbage = NULL;

    //inserting at the end

    while (ptr->rlink != NULL)
    {

        ptr = ptr->rlink;
    }
    if (ins > 4)
    {
        printf("  Memory insufficient. Attaching the collected garbage memory blocks....");
        garbage = detach();
        if(garbage!=NULL)
       { printf("\n  Enter the data :");
        scanf("%d", &(garbage)->data);
        ptr->rlink = garbage;
        garbage->llink = ptr;
        ++ins;
        }
    }
    else
    {
        node = create();
        node->llink = ptr;
        ptr->rlink = node;
    }

    traverse(head);
    return head;
}

struct Node *delete (struct Node *head)
{
    ++del;
    struct Node *ptr = NULL;
    ptr = head;
    head = head->rlink;
    ptr->rlink = NULL;
    head->llink = NULL;
    printf("\n  Collecting deleted node....");
    if (del == 1)
    {
        availhead = ptr;
        availtemp = availhead;
    }
    else
    {
        availtemp->rlink = ptr;
        ptr->llink = availtemp;
        availtemp = availtemp->rlink;
    }

    printf("\n  Collected\n");
    traverse(head);
    return head;
}

int main()
{
    int choice, ch, num = 0;
    char s;
    struct Node *head, *node_temp;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->rlink = NULL;
    head->llink = NULL;
    printf("\n  Memory allocation of 5 nodes only!!!");
    printf("\n  1.Create list\n  2.Insert node\n  3.Delete node\n  4.Exit ");
    
    while (1)
    {
       printf("\n  Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            node_temp = (struct Node *)malloc(sizeof(struct Node));

            if (num == 0)
            {
                node_temp = create();
                head = node_temp;
                num++;
            }
            else
            {
                head = insert(head);
            }

            break;
        case 2:

            head = insert(head);
            break;
        case 3:

            head = delete (head);
            break;

        case 4:
            exit(0);
        default:
            printf("\n  Invalid choice\n");
            break;
        }
    }
}

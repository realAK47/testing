#include<stdio.h>
#include<stdlib.h>

void firstfit()
{
    int nb,np,i,j,k=0,flag;
    printf("Enter number of available blocks : ");
    scanf("%d",&nb);
    printf("\nEnter number of process : ");
    scanf("%d",&np);
    int Block_size[nb],Process_size[np],Allocation[np];
    printf("\nEnter block sizes : ");
    for(i=0;i<nb;i++)
    {
        scanf("%d",&Block_size[i]);
    }
    printf("\nEnter process sizes : ");
    for(i=0;i<np;i++)
    {
        scanf("%d",&Process_size[i]);
    }
    for(i=0;i<np;i++)
    {
        flag=0;
        for(j=0;j<nb;j++)
        {
            if(Process_size[i]<=Block_size[j])
            {
                Block_size[j]=Block_size[j]-Process_size[i];
                Allocation[k]=j;
                k++;
                flag=1;
                break;
            }
        }
        if(flag==0)
        if(flag==0)
        {
            Allocation[k]=-1;
            k++;
        }
    }
    printf("Process No     Process size     Block No\n");
    for(i=0;i<np;i++)
    {
        if(Allocation[i]!=-1)
        {
            printf("    %d             %d              %d\n",i+1,Process_size[i],Allocation[i]+1);
        }
        else
        {
            printf("    %d             %d              Not allocated\n",i+1,Process_size[i]);
        }
    }
}

void bestfit()
{
    int nb,np,i,j,min,x;
    printf("Enter number of available blocks : ");
    scanf("%d",&nb);
    printf("\nEnter number of process : ");
    scanf("%d",&np);
    int Block_size[nb],Process_size[np],Allocation[np],Diff[nb];
    printf("\nEnter block sizes : ");
    for(i=0;i<nb;i++)
    {
        scanf("%d",&Block_size[i]);
    }
    printf("\nEnter process sizes : ");
    for(i=0;i<np;i++)
    {
        scanf("%d",&Process_size[i]);
    }
    for(i=0;i<np;i++)
    {
        x=-1;
        min=999;
        for(j=0;j<nb;j++)
        {
            Diff[j]=Block_size[j]-Process_size[i];
            if(Diff[j]>=0&&Diff[j]<min)
            {
                min=Diff[j];
                x=j;
            }
        }
        Block_size[x]=min;
        Allocation[i]=x;
    }
    printf("Process No     Process size     Block No\n");
    for(i=0;i<np;i++)
    {
        if(Allocation[i]!=-1)
        {
            printf("    %d             %d              %d\n",i+1,Process_size[i],Allocation[i]+1);
        }
        else
        {
            printf("    %d             %d              Not allocated\n",i+1,Process_size[i]);
        }
    }
}

void worstfit()
{
    int nb,np,i,j,max,x;
    printf("Enter number of available blocks : ");
    scanf("%d",&nb);
    printf("\nEnter number of process : ");
    scanf("%d",&np);
    int Block_size[nb],Process_size[np],Allocation[np],Diff[nb];
    printf("\nEnter block sizes : ");
    for(i=0;i<nb;i++)
    {
        scanf("%d",&Block_size[i]);
    }
    printf("\nEnter process sizes : ");
    for(i=0;i<np;i++)
    {
        scanf("%d",&Process_size[i]);
    }
    for(i=0;i<np;i++)
    {
        x=-1;
        max=-1;
        for(j=0;j<nb;j++)
        {
            Diff[j]=Block_size[j]-Process_size[i];
            if(Diff[j]>=0&&Diff[j]>max)
            {
                max=Diff[j];
                x=j;
            }
        }
        Block_size[x]=max;
        Allocation[i]=x;
    }
    printf("Process No     Process size     Block No\n");
    for(i=0;i<np;i++)
    {
        if(Allocation[i]!=-1)
        {
            printf("    %d             %d              %d\n",i+1,Process_size[i],Allocation[i]+1);
        }
        else
        {
            printf("    %d             %d              Not allocated\n",i+1,Process_size[i]);
        }
    }
}

void main()
{
    int choice;
    while(1)
    {
        printf("Enter choice\n1)Firstfit\n2)Bestfit\n3)Worstfit\n4)Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            firstfit();
            break;
        case 2:
            bestfit();
            break;
        case 3:
            worstfit();
            break;
        case 4:
            exit(0);
        }
    }
}



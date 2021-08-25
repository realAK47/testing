#include <stdio.h>
#include <stdlib.h>

int n;
int temp;
void display(int a[],int n)
{
    int i;
    printf("\n");
    for(i=0;i<n;i++){
    printf("%d ",a[i]);
    }
    printf("\n");
}
int * bubbleSort(int arr[],int n){
    int temp;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
            else{
                continue;
            }
        }

    }
    return arr;
}


int * insertionSort(int arr[],int n){
    int temp;
    for(int i=1;i<n;i++){
        int k;
        temp = arr[i];
        for(int j=i-1;j>=0;j--){
            if(temp<arr[j]){
                arr[j+1]=arr[j];
                if(j==0){
                    arr[j]=temp;
                }
            }
            else if(temp>arr[j]){
                break;
            }
        }
    }
    return arr;

}


int * selectionSort(int arr[],int n){
    int temp,k;
    for(int i = 0;i<n-1;i++){
        temp = arr[i];
        for(int j=i+1;j<n;j++){
            if(temp>arr[j]){
                temp=arr[j];
                k=j;
            }
        }
        arr[k]=arr[i];
        arr[i]=temp;
    }
    return arr;
}

int partition(int arr[],int lb,int ub){
    int temp,start,end,pivot;
    start = lb ;
    end = ub ;
    pivot = arr[lb];
    while(start>end){
        while(pivot>arr[start]){
            start++;
        }
        while(pivot<arr[end]){
            end--;
        }
        if(start<end){
        temp = arr[start] ;
        arr[start] = arr[end] ;
        arr[end] = temp ;
        }
    }

    if(start>end){
        temp = arr[lb] ;
        arr[lb] = arr[end] ;
        arr[end] = temp ;
        }
    return end;
}
void quickSort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc = partition(a,lb,ub);
        quickSort(a,lb,loc-1);
        quickSort(a,loc+1,ub);
    }
}

void mergeSort(int a[],int l,int u)
{
    int mid;
    if(l<u)
    {
        mid=(l+u)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,u);
        merges(a,l,mid,u);
    }
}

void merges(int a[],int l,int mid,int u)
{
    int i=l,j=mid+1,k=l;
    int b[u+1];
    while(i<=mid&&j<=u)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=u)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(i=l;i<=u;i++)
    {
        a[i]=b[i];
    }
}




void main()
{
    int n,choice,x;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    int * array;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    while(x){
    printf("\nEnter choice\n1)Bubble Sort sort\n2)Selection sort\n3)Insertion sort\n4)Quick sort\n5)Merge sort\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        bubbleSort(arr,n);
        display(arr,n);
        break;
    case 2:
        selectionSort(arr,n);
        display(arr,n);
        break;
    case 3:
        insertionSort(arr,n);
        display(arr,n);
        break;
    case 4:
        quickSort(arr,0,n-1);
        display(arr,n);
        break;
    case 5:
        mergeSort(arr,0,n-1);
        display(arr,n);
        break;
    default:
        printf("\nInvalid choice");
        break;
    }
    printf("Enter 1 to exit 0 to continue \n");
    scanf("%d",&x);

    }
}


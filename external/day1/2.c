#include <stdio.h>
void swap(int *a,int*b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[high],&arr[i+1]);
    return i+1;
}

void QuickSort(int arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        QuickSort(arr,low,pi-1);
        QuickSort(arr,pi+1,high);
    }
}

int main(){
    int n;
    int prices[50];
    printf("Enter the number of items:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the price of item %d:",i+1);
        scanf("%d",&prices[i]);
    }

    QuickSort(prices,0,n-1);

    printf("Sorted prices\n");
    for(int i=0;i<n;i++){
        printf("%d ",prices[i]);
        
    }

}
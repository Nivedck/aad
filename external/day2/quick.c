#include <stdio.h>

void swap(int *a,int*b){
    int temp=*a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int low , int high){
    int pivot = arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void QuickSort(int arr[],int low,int high){
    if(low<high){
        int pivot = partition(arr,low,high);
        QuickSort(arr,low,pivot-1);
        QuickSort(arr,pivot+1,high);
    }
}

int main(){
    int arr[]={4,3,2,1};
    QuickSort(arr,0,3);
    for(int i=0;i<4;i++){
        printf("%d ",arr[i]);
    }
}
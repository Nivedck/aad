#include <stdio.h>

void merge(int arr[],int low,int mid,int high){
    int n1 = mid-low+1;
    int n2 = high - mid;
    int left[n1],right[n2];
    printf("merge started\n");
    for(int i=0;i<n1;i++){
        left[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=arr[mid+i+1];
    }

    int i=0,j=0,k=low;

    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            arr[k]=left[i];
            i++;
        }else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[],int low,int high){
    if(low<high){
        int mid= low + (high-low)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    int marks[50];
    int n;

    printf("Enter the number of students:");
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        printf("Enter mark of studend %d:",i+1);
        scanf("%d",&marks[i]);
    }

    MergeSort(marks,0,n-1);

    printf("Sorted Marks\n");
    for(int i=0;i<n;i++){
        printf("%d\n",marks[i]);
    }

}
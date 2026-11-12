//Exp6: MergeSort
#include <stdio.h>

void merge(int arr[],int low,int mid,int high){
    int n1 = mid-low+1; 
    int n2 = high-mid;
    int l[n1],r[n2];

    for(int i=0;i<n1;i++){
        l[i]=arr[low+i];
    }

    for(int j=0;j<n2;j++){
        r[j]=arr[mid+j+1];
    }

    int i=0 , j=0 , k=low;

    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            arr[k]=l[i];
            i++;
        }else{
            arr[k]=r[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=l[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=r[j];
        j++;
        k++;
    }

}

void MergeSort(int arr[],int low,int high){
    if(low < high){
        int mid = low + (high-low) /2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
}

int main(){
    int arr[]={5,6,3,2,1};
    MergeSort(arr,0,4);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}
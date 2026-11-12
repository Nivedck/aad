//Exp5: Find MinMAx using Divide and Conquer

#include <stdio.h>

typedef struct Pair{
    int min;
    int max;
}Pair;


Pair findMinMax(int arr[],int low,int high){

    Pair result,left,right;
    int mid;

    if(low==high){
        result.min=arr[low];
        result.max=arr[low];
        return result;
    }

    if(low==high+1){
        if(arr[low]<arr[high]){
            result.min=arr[low];
            result.max=arr[high];
        }else{
            result.min=arr[high];
            result.max=arr[low];
        }
        return result;
    }

    mid = low+ (high-low)/2;

    left = findMinMax(arr,low,mid);
    right= findMinMax(arr,mid+1,high);

    if(left.min < right.min) result.min = left.min;
    else result.min = right.min;

    if(left.max >right.max) result.max = left.max;
    else result.max = right.max;

    return result;
}

int main(){
    int n,arr[20];
    Pair min_max;
    
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);

    printf("Enter the array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    min_max=findMinMax(arr,0,n-1);

    printf("Minimum:%d\n",min_max.min);
    printf("Maxmimum:%d\n",min_max.max);

    return 0;

}
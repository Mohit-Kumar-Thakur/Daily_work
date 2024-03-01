//WAP in C to perform binary search in an array using recursion.

#include <stdio.h>
int binary_search(int arr[],int l, int r, int num){
    if(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==num)
            return mid;
        else if(arr[mid]>num)
            return binary_search(arr,l,mid-1,num);
        else
            return binary_search(arr,mid+1,r,num);        
    }return -1;
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int num;
    printf("Enter the number you want to search for:\n");
    scanf("%d",&num);
    int answer=binary_search(arr,0,n-1,num);
    answer == -1?printf("The element is not present in the array.\n"):
    printf("The element is present in the array at index: %d",answer);
    return 0;
}
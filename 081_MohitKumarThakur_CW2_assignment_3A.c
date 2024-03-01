//WAP in C to perform binary search iteratively in an array.

#include <stdio.h>
int binary_search(int arr[],int l,int r,int num){
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==num)
            return mid;
        else if(arr[mid]>num)
            r=mid-1;
        else
            l=mid+1;
    }return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int num;
    printf("enter the number you want to search for:\n");
    scanf("%d",&num);
    int answer=binary_search(arr,0,n-1,num);
    answer == -1?printf("The element is not present in the array:"):
    printf("The element you entered is present at index :%d",answer);
    return 0;
}
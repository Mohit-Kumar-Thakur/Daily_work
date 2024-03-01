//write a menu driven program to input an array and perform following operations
// 1.traversal: linear seach for an element in an array
// 2.inserting an element at a specified position
// 3.deleting an element from the specified position
// 4.array reversal
// 5.updating the elements of the array (multiply the elements at even indices by 2 and add 5 to the elements at odd indices)

#include<stdio.h>
#include<stdlib.h>
void traversal(int element,int n,int a[]){
    int flag=0;
                for (int i=0;i<n;i++){
                        if(a[i]==element){
                            printf("the element is present at index: %d\n",i);
                            flag++;
                        } 
                        
                }if(flag==0){
                            printf("The element is not present in the array.\n");
                        }
}

void insertion(int a[],int *n,int pos,int num){
    if (pos<=0||pos>*n+1){
        printf("invalid position:\n");
    }else{
        for (int i=*n-1;i>=pos-1;i--){
                    a[i+1]=a[i];
                }
                a[pos-1]=num;
                *n=*n+1;
                printf("the new array is:\n");
                for(int i=0;i<*n;i++){
                    printf("%d\n",a[i]);
                }
    }
}

void deletion(int a[],int *n,int posd){
    if (posd<=0||posd>*n){
        printf("invalid position:\n");
    }else{
        for (int i=posd-1;i<*n;i++){
                    a[i]=a[i+1];
                }
                *n=*n-1;
                printf("the updated array is:\n");
                for(int i=0;i<*n;i++){
                    printf("%d\n",a[i]);
                }
    }
}

void reversal(int a[],int n){
    for (int i=0;i<n/2;i++){
        int temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }
    printf("The reversed array is:\n");
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
}

void updation(int a[],int n){
    for(int i=0;i<n;i++){
                    if(i%2==0){
                        a[i]=a[i]*2;
                    }else{
                        a[i]=a[i]+5;
                    }
                }
                for(int i=0;i<n;i++){
                    printf("%d\n",a[i]);
                }
}

int main(){
    int n;
    printf("enter the number of elements:\n");
    scanf("%d",&n);
    int a=(int)malloc(n*sizeof(int));
    int c;
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    while(1){ 
        printf("enter the choice:\n1.Traversal: Linear Search\n2.Insertion\n3.Deletion\n4.Array Reversal\n5.Updation\n6.EXIT\n");
        scanf("%d",&c);

        switch(c){
            case 1:{
                int element;
                printf("enter the element:\n");
                scanf("%d",&element);
                traversal(element,n,a);
                
                    
            }break;
            case 2:{
                int pos,num;
                printf("enter the number you want to insert in the array:\n");
                scanf("%d",&num);
                printf("enter the position where you want to insert the element:\n");
                scanf("%d",&pos);
                insertion(a,&n,pos,num);
                
            }break;

            case 3:{
                int posd;
                printf("enter the position of the element you want to delete:\n");
                scanf("%d",&posd);
                deletion(a,&n,posd);
            }break;

            case 4:{
                reversal(a,n);  
            }break;

            case 5:{
                updation(a,n);
            }break;
            case 6:{
                printf("exiting from the code");
                free(a);
                return 0;
            }
            default:{
                printf("Invlaid choice Please enter your choice again");
            }

            }
    }       
}
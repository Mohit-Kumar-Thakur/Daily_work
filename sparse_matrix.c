#include<stdio.h>
int main(){
    int m,n;
    printf("enter the number of rows:\n");
    scanf("%d",&m);
    printf("enter the number of columns:\n");
    scanf("%d",&n);
    int arr[m][n];
    printf("enter the elements of the matrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }printf("the matrix you entered is:\n");
    int zero=0,nzero=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",arr[i][j]);
            if(arr[i][j]==0)
                zero++;
            else
                nzero++;
        }printf("\n");
    }if(zero>nzero){
        printf("the matrix is a sparse matrix:\n");
        int s[3][nzero],k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]!=0){
                    s[0][k]=i;
                    s[1][k]=j;
                    s[2][k]=arr[i][j];
                    k++;
                }
            }
        }printf("matrix containing non-zero element is:\n");
         for(int i=0;i<3;i++){
            for(int j=0;j<nzero;j++){
                printf("%d\t",s[i][j]);
            }printf("\n");
        }
        
    }
}
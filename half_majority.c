#include <stdio.h>
#include <stdlib.h>
int main(){
    int n; 
    printf("enter number of elements : ");
    scanf("%d", &n);
    int A[n];
    printf("enter %d elements : \n", n);
    for(int i = 0; i<n; i++){
        scanf("%d", &A[i]);
    }
    

}
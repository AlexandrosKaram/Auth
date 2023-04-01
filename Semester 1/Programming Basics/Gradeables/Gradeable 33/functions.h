#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(int *A,int n){
    int i;
    for (i=0;i<n;i++)
        printf("%d ",A[i]);
}

int* primes(int *A,int n,int *m){
    int i,j,*B,prime,k;

    B = (int*)malloc(n*sizeof(int));
    k = 0;
    
    for (i=0;i<n;i++){
        prime = 1;
        if (A[i]<2 || (A[i]%2==0 && A[i]!=2))
            prime = 0;
        else{
            int lim = (int)sqrt(A[i]);
            for (j=3;j<=lim && prime;j+=2){
                if (A[i]%j==0)
                    prime = 0;}}
        if (prime){
            B[k] = A[i];
            k++;}}
    *m = k;
  
    return B;
}
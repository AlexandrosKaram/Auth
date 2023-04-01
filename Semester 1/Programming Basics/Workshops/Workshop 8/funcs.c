#include <stdbool.h>

bool ArrayAvg(int *A, int n,float *avg){
    if (n<=0) return false; 
    int i;    
    *avg = 0;
    for (i=0;i<n;i++){
        *avg += A[i];    
    }
    *avg = *avg/n;
    return true;
}

float *Davg(int *A, int n){
    int i;
    float avg;
    ArrayAvg(A,n,&avg);
    float *B;

    B = malloc(sizeof(float)*n);

    for (i=0;i<n;i++)
        B[i] = A[i] - avg;

    return B;
}
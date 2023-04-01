#include <stdio.h>
#include <math.h>

struct vector {
    char description[20];
    double x;
    double y;
};

struct vector readVector(){
    struct vector my_vector;
    scanf("%s %lf %lf",my_vector.description,&my_vector.x,&my_vector.y);
    return my_vector;
}

double getLength(struct vector v){
    double x = v.x;
    double y = v.y;
    double magnitude = sqrt(pow(x,2)+pow(y,2));
    return magnitude;
}

struct vector findLongest(struct vector A[],int n){
    int i;
    int max = getLength(A[0]);
    struct vector maxV = A[0];
    double length;

    for (i=1;i<n;i++){
        length = getLength(A[i]);
        if (length>max){
            max = length;
            maxV = A[i];}}

    return maxV;
}

void printVector(struct vector v){
    printf("%s (%.2lf,%.2lf)",v.description,v.x,v.y);
}
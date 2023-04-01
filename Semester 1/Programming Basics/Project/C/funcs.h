#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct route{
    char start[50];
    int length;
    int uphill;
    int downhill;
    int max;
    int min;
    char finish[50];
};

// sorts parallel arrays based on length
void sortRoutes(struct route *A,float *T,int N){
    struct route temp;
    int i,j;
    float temp2;
    // sorting the array
    for (i=0;i<N-1;i++){
        for (j=0;j<N-i-1;j++){
            if (A[j].length<A[j+1].length){
                temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
                temp2 = T[j+1];
                T[j+1] = T[j];
                T[j] = temp2;
            }
        }
    }
}

float estimatedTime(struct route A){
    return A.length/65.0 + A.uphill/10.0;
}

void printRoute(struct route A,float T){
    printf("From %s to %s\n",A.start,A.finish);
    printf("Uphill %d, Downhill %d\n",A.uphill,A.downhill);
    printf("Max altitude %d, Min altitude %d\n",A.max,A.min);
    printf("Length %d, Estimated time %.0f min\n",A.length,round(T));
    printf("\n");
}

void readString(char *s,int n){
    scanf(" ");
    fgets(s,n,stdin);
    s[strcspn(s,"\n")] = '\0';
}

struct route *readFromInput(int *N){
    int i;
    struct route *A;

    scanf("%d",N);
    A = (struct route*)malloc(sizeof(struct route)*(*N));

    for (i=0;i<(*N);i++){
        readString(A[i].start,50);
        scanf("%d %d %d %d %d", &A[i].length, &A[i].uphill, &A[i].downhill, &A[i].max, &A[i].min);
        readString(A[i].finish,50);
    }

    return A;
}

void printData(struct route *A,int n){
    int i,N;

    N = n;
    for (i=0;i<n;i++){
        if (strcmp(A[i].start,A[i].finish)!=0) N++;
    }

    int cnt = 0;
    struct route *B;
    float *T;
    T = (float*)malloc(sizeof(float)*N); //estimated time
    B = (struct route*)malloc(sizeof(struct route)*N);
    
    // adding the reverse paths in b and calculating their estimated time
    for (i=0;i<n;i++){
        B[i] = A[i];
        T[i] = estimatedTime(A[i]);
        if (strcmp(A[i].start,A[i].finish)!=0){
            B[N-cnt-1] = A[i];
            strcpy(B[N-cnt-1].start,A[i].finish);
            strcpy(B[N-cnt-1].finish,A[i].start);
            B[N-cnt-1].downhill = A[i].uphill;
            B[N-cnt-1].uphill = A[i].downhill;

            T[N-cnt-1] = estimatedTime(B[N-cnt-1]);
            cnt++;
        }
    }     

    // sorting and printing the array 
    sortRoutes(B,T,N);
    for (i=0;i<N;i++){
        printRoute(B[i],T[i]);
    }
    
    free(B);
    free(T);
}

void findShort(struct route *A,int n){
    int i,L,cnt=0;
    float *T;
    struct route *B;
    B = (struct route*)malloc(sizeof(struct route));
    T = (float*)malloc(sizeof(float));

    scanf("%d",&L);

    for (i=0;i<n;i++){
        if (A[i].length<=L){
            B[cnt] = A[i];
            T[cnt] = estimatedTime(A[i]);
            cnt++;
            B = realloc(B,sizeof(struct route)*(cnt+1));
            T = realloc(T,sizeof(float)*(cnt+1));
        } 
    }

    sortRoutes(B,T,cnt);
    struct route tempRoute;
    for (i=0;i<cnt;i++){
        printRoute(B[i],T[i]);
        if (strcmp(B[i].start,B[i].finish)!=0){
            tempRoute = B[i];
            strcpy(tempRoute.start,B[i].finish);
            strcpy(tempRoute.finish,B[i].start);
            tempRoute.downhill = B[i].uphill;
            tempRoute.uphill = B[i].downhill;
            printRoute(tempRoute,estimatedTime(tempRoute));
        }
    }

    free(B);
    free(T);
}

void findLocation(struct route *A,int N){
    int i,cnt=0;
    float *T;
    char s[50];
    struct route *B;

    readString(s,50);

    B = (struct route*)malloc(sizeof(struct route));
    T = (float*)malloc(sizeof(float));

    for (i=0;i<N;i++){
        if (strcmp(s,A[i].start)==0){   // if string is the same as the start
            B[cnt] = A[i];
            T[cnt] = estimatedTime(B[cnt]);
            cnt++;
            B = realloc(B,sizeof(struct route)*(cnt+1));
            T = realloc(T,sizeof(float)*(cnt+1));
        }else if (strcmp(s,A[i].finish)==0){    // if string is the same as the end
            B[cnt] = A[i];
            strcpy(B[cnt].start,A[i].finish);
            strcpy(B[cnt].finish,A[i].start);
            B[cnt].uphill = A[i].downhill;
            B[cnt].downhill = A[i].uphill;
            T[cnt] = estimatedTime(B[cnt]);
            cnt++;
            B = realloc(B,sizeof(struct route)*(cnt+1));
            T = realloc(T,sizeof(float)*(cnt+1));
        }
    }    

    sortRoutes(B,T,cnt);
    
    for (i=0;i<cnt;i++) printRoute(B[i],T[i]);

    free(B);
    free(T);
}

void findUpHill(struct route *A,int N){
    int i,cnt=0;
    float *T;
    struct route *B;

    B = (struct route*)malloc(sizeof(struct route));
    T = (float*)malloc(sizeof(float));

    for (i=0;i<N;i++){
        if (A[i].uphill>A[i].downhill){
            B[cnt] = A[i];
            T[cnt] = estimatedTime(B[cnt]);
            cnt++;
            B = realloc(B,sizeof(struct route)*(cnt+1));
            T = realloc(T,sizeof(float)*(cnt+1));
        }else if (A[i].uphill<A[i].downhill){
            B[cnt] = A[i];
            strcpy(B[cnt].start,A[i].finish);
            strcpy(B[cnt].finish,A[i].start);
            B[cnt].uphill = A[i].downhill;
            B[cnt].downhill = A[i].uphill;
            T[cnt] = estimatedTime(B[cnt]);
            cnt++;
            B = realloc(B,sizeof(struct route)*(cnt+1));
            T = realloc(T,sizeof(float)*(cnt+1));
        }
    }

    sortRoutes(B,T,cnt);
    
    for (i=0;i<cnt;i++) printRoute(B[i],T[i]);

    free(B);
    free(T);
}

void findDownHill(struct route *A,int N){
    int i,cnt=0;
    float *T;
    struct route *B;

    B = (struct route*)malloc(sizeof(struct route));
    T = (float*)malloc(sizeof(float));

    for (i=0;i<N;i++){
        if (A[i].uphill<A[i].downhill){
            B[cnt] = A[i];
            T[cnt] = estimatedTime(B[cnt]);
            cnt++;
            B = realloc(B,sizeof(struct route)*(cnt+1));
            T = realloc(T,sizeof(float)*(cnt+1));
        }else if (A[i].downhill<A[i].uphill){
            B[cnt] = A[i];
            strcpy(B[cnt].start,A[i].finish);
            strcpy(B[cnt].finish,A[i].start);
            B[cnt].uphill = A[i].downhill;
            B[cnt].downhill = A[i].uphill;
            T[cnt] = estimatedTime(B[cnt]);
            cnt++;
            B = realloc(B,sizeof(struct route)*(cnt+1));
            T = realloc(T,sizeof(float)*(cnt+1));
        }
    }

    sortRoutes(B,T,cnt);
    
    for (i=0;i<cnt;i++) printRoute(B[i],T[i]);

    free(B);
    free(T);
}

void findAltitude(struct route *A,int n){
    int i,mini,maxi,cnt=0;
    float *T;
    struct route *B;

    B = (struct route*)malloc(sizeof(struct route));
    T = (float*)malloc(sizeof(float));

    scanf("%d %d",&mini,&maxi);

    for (i=0;i<n;i++){
        if (A[i].min>=mini && A[i].max<=maxi){
            B[cnt] = A[i];
            T[cnt] = estimatedTime(A[i]);
            cnt++;
            B = realloc(B,sizeof(struct route)*(cnt+1));
            T = realloc(T,sizeof(float)*(cnt+1));
        }
    }

    sortRoutes(B,T,cnt);
    struct route tempRoute;
    for (i=0;i<cnt;i++){
        printRoute(B[i],T[i]);
        if (strcmp(B[i].start,B[i].finish)!=0){
            tempRoute = B[i];
            strcpy(tempRoute.start,B[i].finish);
            strcpy(tempRoute.finish,B[i].start);
            tempRoute.downhill = B[i].uphill;
            tempRoute.uphill = B[i].downhill;
            printRoute(tempRoute,estimatedTime(tempRoute));
        }
    }

    free(B);
    free(T);
}

void findTimely(struct route *A,int n){
    int i,N;
    float time;

    scanf("%f",&time);

    N = n;
    for (i=0;i<n;i++){
        if (strcmp(A[i].start,A[i].finish)!=0) N++;
    }

    int cnt = 0;
    struct route *B;
    float *T;
    T = (float*)malloc(sizeof(float)*N); //estimated time
    B = (struct route*)malloc(sizeof(struct route)*N);
    
    // adding the reverse paths in b and calculating their estimated time
    for (i=0;i<n;i++){
        B[i] = A[i];
        T[i] = B[i].length/65.0 + B[i].uphill/10.0;
        if (strcmp(A[i].start,A[i].finish)!=0){
            B[N-cnt-1] = A[i];
            strcpy(B[N-cnt-1].start,A[i].finish);
            strcpy(B[N-cnt-1].finish,A[i].start);
            B[N-cnt-1].downhill = A[i].uphill;
            B[N-cnt-1].uphill = A[i].downhill;
            T[N-cnt-1] = B[N-cnt-1].length/65.0 + B[N-cnt-1].uphill/10.0;
            cnt++;
        }
    }     

    // sorting and printing the array 
    sortRoutes(B,T,N);
    for (i=0;i<N;i++){
        if (T[i]<=time){
            int t;
            t = T[i]+0.5;
            printRoute(B[i],t);
        } 
    }
    
    free(B);
    free(T);
}

struct route *readFromFile(int *n){
    int i;
    char s[50];
    struct route *A;
    FILE *fp;


    readString(s,50);
    fp = fopen(s,"r");
    fscanf(fp,"%d ",n);
    A = (struct route*)malloc(sizeof(struct route)*(*n));

    for (i=0;i<(*n);i++){
        fgets(A[i].start,50,fp);
        A[i].start[strcspn(A[i].start,"\n")] = '\0';
        fscanf(fp, "%d %d %d %d %d ", &A[i].length, &A[i].uphill, &A[i].downhill, &A[i].max, &A[i].min);
        fgets(A[i].finish,50,fp);       
        A[i].finish[strcspn(A[i].finish,"\n")] = '\0';
    }

    fclose(fp);
    return A;
}

void saveData(struct route *A,int n){
    int i,N,cnt;
    struct route *B;
    float *T;
    char s[50];
    FILE *fp;

    N = n;
    readString(s,50);
    fp = fopen(s,"w");

    for (i=0;i<n;i++){
        if (strcmp(A[i].start,A[i].finish)) N++;
    }

    T = (float*)malloc(sizeof(float)*N);
    B = malloc(sizeof(struct route)*N);
    cnt = 0;

    for (i=0;i<n;i++){
        B[i] = A[i];
        T[i] = estimatedTime(A[i]);
        if (strcmp(A[i].start,A[i].finish)){
            B[N-cnt-1] = A[i];
            strcpy(B[N-cnt-1].start,A[i].finish);
            strcpy(B[N-cnt-1].finish,A[i].start);
            B[N-cnt-1].downhill = A[i].uphill;
            B[N-cnt-1].uphill = A[i].downhill;
            T[N-cnt-1] = estimatedTime(B[N-cnt-1]);
            cnt++;
        }
    }

    sortRoutes(B,T,N);

    for (i=0;i<N;i++){
        fprintf(fp,"From %s to %s\n",B[i].start,B[i].finish);
        fprintf(fp,"Uphill %d, Downhill %d\n",B[i].uphill,B[i].downhill);
        fprintf(fp,"Max altitude %d, Min altitude %d\n",B[i].max,B[i].min);
        fprintf(fp,"Length %d, Estimated time %.0f min\n",B[i].length,round(T[i]));
        fprintf(fp,"\n");       
    }

    fclose(fp);
    free(B);
    free(T);
}
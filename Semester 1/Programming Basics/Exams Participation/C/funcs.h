int *dividedBy(int a,int b,int d,int *n){
    int i,*R;

    R = malloc(0);
    *n = 0;

    for (i=a;i<=b;i++){
        if (i%d==0){
            R = realloc(R,sizeof(int)*(*n+1));
            R[*n] = i;
            *n+=1;
        }
    }

    return R;
}
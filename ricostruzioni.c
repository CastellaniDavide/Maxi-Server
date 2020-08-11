#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int spiana(int N, int K, int A[]) {
    int r=1000000;
    int my_min,my_max;
    for(int i=0;i<(N-K+1);i++){
        my_min=1000000;
        my_max=0;
        for(int j=0;j<K;j++){
            if(A[j+i]<my_min)
                my_min=A[j+i];
            if(A[j+i]>my_max)
                my_max=A[j+i];
        }
        if((my_max-my_min)<r)
            r=my_max-my_min;
    }

    return r;
}


int A[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &A[i]));

    fprintf(fw, "%d\n", spiana(N, K, A));
    fclose(fr);
    fclose(fw);
    return 0;
}

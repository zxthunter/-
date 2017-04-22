//解30维异或方程组
#include <cstdio>
#include <cstring>
const int MATRIX_SIZE = 30;
int A[MATRIX_SIZE][MATRIX_SIZE];
int M[MATRIX_SIZE][MATRIX_SIZE+1];
int x[MATRIX_SIZE];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
void initial(){
    memset(A,0, sizeof(A));
    memset(x,0,sizeof(x));
    for (int i=0; i<MATRIX_SIZE; i++){
        A[i][i] = 1;
        int x = i % 6;
        int y = i / 6;
        for (int j=0; j<4; j++){
            int newx = x + dx[j] , newy = y+dy[j];
            if (newx >=0 && newx <6 && newy >=0 && newy<5){
                A[i][newy*6+newx] = 1;
            }
        }
    }
}
void read_data(){
    for (int i=0; i<MATRIX_SIZE; i++){
        memcpy(M[i],A[i],sizeof(A[i]));
        scanf("%d",&M[i][MATRIX_SIZE]);
    }
}
void print(){
    for (int i=0; i<MATRIX_SIZE; i++){
        for (int j=0; j<MATRIX_SIZE+1; j++){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
}
void exchange(int n){
    if (M[n][n] == 0){
        int ind = n;
        for (int i=n+1; i<MATRIX_SIZE; i++){
            if (M[i][n] == 1){
                ind = i;
                break;
            }
        }
        int tmp[MATRIX_SIZE+1];
        memcpy(tmp,M[n], sizeof(tmp));
        memcpy(M[n],M[ind], sizeof(tmp));
        memcpy(M[ind],tmp, sizeof(tmp));
    }
}
void elimination(int n){
    exchange(n);
    for (int i=n+1; i<MATRIX_SIZE; i++){
        if ( M[i][n] == 1){
            for (int j = n; j<MATRIX_SIZE+1; j++){
                M[i][j] = M[n][j] ^ M[i][j];
            }
        }
    }
}
void elimination(){
    for (int i=0; i<MATRIX_SIZE; i++){
        elimination(i);
    }
}
void back_substitution(){
    for (int i=MATRIX_SIZE-1; i>=0; i--){
        x[i] = M[i][MATRIX_SIZE];
        for (int j=MATRIX_SIZE-1; j >= i+1; j--){
            int tmp = x[j] * M[i][j];
            x[i] ^= tmp;
        }
    }
}
void print_result(){
    for (int i=0; i<5; i++){
        for (int j=0; j<6; j++){
            if (j!=5) {
                printf("%d ",x[i*6+j] );
            } else {
                printf("%d",x[i*6+j] );
            }
        }
        printf("\n");

    }
}
int main(){
    int n;
    initial();
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        read_data();
        elimination();
        back_substitution();
        printf("PUZZLE #%d\n",i+1);
        print_result();
    }
    return 0;
}
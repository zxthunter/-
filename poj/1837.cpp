// 巧妙构造背包问题
// dp[i][j] = Sigma(about k){dp[i-1][j]-dis[k]*w[i]}
#include <cstdio>
#include <cstring>
const int MID = 7500;
const int DP_SIZE = 2* MID +10;
int dis[20],w[20],dp[20][DP_SIZE];
int main(){
    int c,g;
    scanf("%d %d",&c,&g);
    for (int i=0; i<c; i++){
        scanf("%d",&dis[i]);
    }
    for (int i=0; i<g; i++){
        scanf("%d",&w[i]);
    }
    memset(dp[0],0, sizeof(dp[0]));
    for (int i = 0; i<c; i++){
        dp[0][MID+dis[i]*w[0]] = 1;
    }
    for (int i=1; i<g; i++){
        for (int j=0; j<DP_SIZE; j++){
            int cnt = 0;
            for (int k =0; k<c; k++){
                int tmp = j - dis[k]*w[i];
                if (tmp >=0 && tmp <DP_SIZE ){
                    cnt += dp[i-1][tmp];
                }
            }
            dp[i][j] = cnt;
        }
    }
    printf("%d\n",dp[g-1][MID]);
}
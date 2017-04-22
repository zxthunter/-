// 简单递推，非递归
#include <cstdio>
long long dp[91]; // 特别需要注意数字的范围
int main(){
    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<91; i++){
        dp[i] = dp[i-1]+ dp[i-2];
    }
    int n;
    while (scanf("%d",&n) != EOF){
        printf("%lld\n",dp[n]);
    }
}
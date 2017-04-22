// 两个序列的最长公共字串
// dp[i][j] = dp[i-1][j-1]+1 (s1[i] == s2[j])
// dp[i][j] = max(dp[i][j-1],dp[i][j-1])(s1[i] != s2[j])
#include <cstdio>
#include<cstring>
#include <algorithm>
char s1[101],s2[101];
int dp[101][101];
int main(){
    while (scanf("%s",s1)!=EOF && scanf("%s",s2)!=EOF){
        int l1,l2;
        l1 = strlen(s1);
        l2 = strlen(s2);
        memset(dp,0, sizeof(dp));
        //注意此处将界限提高一位，让dp帮助我们自动初始化。
        for (int i=1; i<=l1; i++){
            for (int j =1; j<=l2; j++ ){
                if (s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                } else{
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        printf("%d\n",dp[l1][l2]);
    }
}
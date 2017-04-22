// 动态规划，求最长递增子序列
// dp[i] = max{1,dp[j]+1(aj<ai&&j<i)}
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int a[31];
int dp[31],pre[31];
int main(){
    int k ;
    while (scanf("%d",&k) != EOF){
        for (int i=0; i<k; i++) {
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        memset(pre,-1, sizeof(pre));
        dp[0] = 1;
        for (int i=1; i<k; i++){
            int max = 0,maxid = -1;
            for (int j=0; j<i; j++){
                if (a[i]<=a[j] && dp[j]>max){
                    max = dp[j];
                    maxid = j;
                }
            }
            dp[i] = 1+max;
            pre[i] = maxid;
        }
        int tid = -1,max = 0;
        for (int i=0; i<k; i++){
            if (dp[i]>max){
                max = dp[i];
                tid = i;
            }
        }
        /****/
        //打印出这个序列
//        vector<int> pv;
//        while (tid != -1){
//            pv.push_back(a[tid]);
//            tid = pre[tid];
//        }
//        for (vector<int>::iterator it = pv.end()-1; it>= pv.begin(); --it){
//            printf("%d ",*it);
//        }
//        printf("\n");
        /*****/
        printf("%d\n",max);
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

long dp[10010];
int main() {
    int t , e ,f , n , w[510] , p[510];
    while (scanf("%d",&t) != EOF) {
        for (int i=0; i<t; i++){
            scanf("%d %d %d",&e,&f,&n);
            for (int j=0; j<n; j++){
                scanf("%d %d",&p[j],&w[j]);
            }
            memset(dp,0, sizeof(dp));
            int totalW = f-e;
            for (int j = 0; j<=totalW; j++){
                int minIndex = -1;
                long minWeight = LONG_MAX;
                for (int k=0; k<n; k++){
                    if (j - w[k] >= 0 && dp[j - w[k]] + p[k] < minWeight) {
                        if (dp[j - w[k]] != 0 || (dp[j - w[k]] == 0 && j - w[k] == 0)){
                            minIndex = j - w[k];
                            minWeight = dp[j - w[k]] + p[k];
                        }
                    }
                }
                if (minIndex != -1) {
                    dp[j] = minWeight;
                }
            }
            if (dp[totalW] > 0) {
                printf("The minimum amount of money in the piggy-bank is %d.\n",dp[totalW]);
            } else {
                printf("This is impossible.\n");
            }
        }

    }
}

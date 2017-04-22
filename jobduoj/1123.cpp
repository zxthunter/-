// 背包问题
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[100][1010],v[100],w[100];
int main() {
    int t, m;
    while (scanf("%d %d", &t, &m) != EOF){
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &w[i], &v[i]);
        }
        for (int i = 0; i <= t; i++) {
            if (i < w[0]) {
                dp[0][i] = 0;
            } else {
                dp[0][i] = v[0];
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < w[i]; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            for (int j = w[i]; j <= t; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
        printf("%d\n", dp[m - 1][t]);
    }
    return 0;
}
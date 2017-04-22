// DAG动态规划
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
int endtimes[10100];
int main (){
    memset(endtimes,-1,sizeof(endtimes));
    int n,res = 0;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        int pi,t;
        scanf("%d %d",&pi,&t);
        if (t == 0){
            endtimes[i] = pi;
            res = max(res,pi);
        } else{
            int maxnum = -1;
            for (int j = 0; j<t; j++){
                int ni;
                scanf("%d",&ni);
                ni--;
                if (endtimes[ni]>maxnum){
                    maxnum = endtimes[ni];
                }
            }
            endtimes[i] = maxnum + pi;
            res = max(res,endtimes[i]);
        }
    }
    printf("%d",res);
    return 0;
}

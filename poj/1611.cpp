//并查集
#include <cstdio>
const int MAX_N = 30010;
int pre[MAX_N];
void init(int n){
    for (int i=0; i<n; i++){
        pre[i] = i;
    }
}
// 寻找并查集的最父亲结点，并且进行状态压缩
int find(int r){
    // 寻找集合树的根
    int t = r;
    while (pre[t] != t){
        t = pre[t];
    }
    // 进行集合树状态的压缩
    while (pre[r] != r){
        int x = pre[r];
        pre[r] = t;
        r = x;
    }
    return t;
}
//合并x、y两个集合
void join(int x, int y){
    if (find(x) != find(y)){
        pre[pre[x]] = pre[y];
    }
}
int main(){
    int m,n;
    while (scanf("%d %d",&n,&m) == 2 && (n!=0 || m!=0)){
        init(n);
        for (int i=0; i<m; i++){
            int k;
            scanf("%d",&k);
            int t1,t2;
            scanf("%d",&t1);
            while (--k > 0){
                scanf("%d",&t2);
                join(t1,t2);
                t1 = t2;
            }
        }
        int srcind = find(0),cnt = 0;
        for (int i=0; i<n; i++){
            if (find(i) == srcind) {
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
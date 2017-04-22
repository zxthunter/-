//²¢²é¼¯
#include <iostream>
#include <cstring>
#include <set>
using namespace std;
int tree[1000];
set<int> s;
int findRoot(int t){
    if (tree[t] == -1) return t;
    else {
        int tmp = findRoot(tree[t]);
        tree[t] = tmp;
        return tmp;
    }
}
int main(){
    int m,n;
    while(cin>>n && n!=0 && cin>>m){
        memset(tree,-1, sizeof(tree));
        int a,b;
        for (int i=0; i<m; i++){
            cin>>a>>b;
            int rootA = findRoot(a),rootB = findRoot(b);
            if (rootA != rootB){
                tree[rootA] = rootB;
            }
        }
        s.clear();
        for (int i=1; i<=n; i++){
            s.insert(findRoot(i));
        }
        cout<<s.size()-1<<endl;
    }
}
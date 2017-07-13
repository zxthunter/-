// Dijstra算法，小技巧：一个顶点的边用一个vector<Edge>表示
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge {
    int next;
    int val;
};

int dis[110], pre[110];
bool in_set[110];

int main() {
    int n, m;
    while (cin>>n >> m && n!= 0 && m!=0){
        vector<Edge> vecs[110];
        for (int i=0; i<m; i++){
            int a, b, val;
            cin >> a >> b >> val;
            Edge edge;
            edge.next = a;
            edge.val = val;
            vecs[b].push_back(edge);
            edge.next = b;
            vecs[a].push_back(edge);
        }
        for (int i=1; i<=n; i++){
            dis[i] = 0;
            pre[i] = INT_MAX;
            in_set[i] = false;
        }
        pre[1] = 0;
        int cnt = 0;
        while (cnt < n){
            cnt ++;
            int min_e = INT_MAX;
            int ind = -1;
            for (int i=1; i<=n; i++){
                if (!in_set[i] && pre[i] < min_e ){
                    min_e = pre[i];
                    ind = i;
                }
            }
            in_set[ind] = true;
            dis[ind] = pre[ind];
            vector<Edge> vec = vecs[ind];
            for (vector<Edge>::iterator it = vec.begin(); it<vec.end(); it++){
                Edge edge = *it;
                if (!in_set[edge.next] && dis[ind] + edge.val < pre[edge.next]){
                    pre[edge.next] = dis[ind] + edge.val;
                }
            }
        }
        cout << dis[n] <<endl;
    }

}

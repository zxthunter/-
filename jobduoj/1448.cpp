#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


int main() {
    int n , m;
    while ( cin>> n >> m && n!=0){
        vector<int> vecs[101];
        int into[101];
        memset(into, 0, sizeof(into));
        queue<int> q;
        for (int i=0; i<m; i++){
            int a ,b;
            cin >> a >> b;
            vecs[a].push_back(b);
            into[b]++;
        }
        for (int i=0; i<n; i++){
            if (into[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()){
            int v = q.front();
            q.pop();
            cnt ++;
            vector<int> vec = vecs[v];
            for (vector<int>::iterator it = vec.begin(); it < vec.end(); ++it){
                if (--into[*it] == 0) {
                    q.push(*it);
                }
            }
        }
        if (cnt == n){
            cout<<"YES"<<endl;
        } else {
            cout << "NO" <<endl;
        }
    }
}

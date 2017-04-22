#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX_N = 65536;
int vis[MAX_N],row_trace[MAX_N],col_trace[MAX_N];
int arr[4][4];
int src ;
queue<int> q;

int arr2int(){
    int res = 0, t = 1;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            res += t*arr[i][j];
            t = t<<1;
        }
    }
    return res;
}
void flip(int x, int y){
    for (int i=0; i<4; i++){
        arr[x][i] = !arr[x][i];
    }
    for (int i=0; i<4; i++){
        arr[i][y] = !arr[i][y];
    }
    arr[x][y] = !arr[x][y];
}
int flip(int x,int y,int s){
    int t = 0;
    int ind = x*4+y;
    t |= 1<<ind;
    for (int i=0; i<4; i++){
        ind = i*4 +y;
        t |= 1<<ind;
    }
    for (int i=0; i<4; i++){
        ind = x*4 +i;
        t |= 1<<ind;
    }
    return (s ^ t);
}
int main(){
    memset(vis,-1,sizeof(vis));
    memset(row_trace,-1,sizeof(row_trace));
    memset(col_trace,-1,sizeof(col_trace));
  /*  for (int i=0; i<4; i++){
        string s;
        getline(cin,s);
        for (int j=0; j<4; j++){
            if (s[j] == '+'){
                arr[i][j] = 1;
            } else if(s[j] == '-') {
                arr[i][j] = 0;
            } else return 0;
        }
    }
    */

    for (int i = 0; i < 4; ++i) {
        char ch[5];
        scanf("%s", ch);
        for (int j = 0; j < 4; ++j) {
            if (ch[j] == '+') {
                arr[i][j] = 1;
            } else {
                arr[i][j] = 0;
            }
        }
    }

    src = arr2int();
    vis[src] = 0;
    q.push(src);
    bool hava_ans = false;
    while (!q.empty()){
        int s = q.front();
        q.pop();
        if (s == 0 ) {
            hava_ans = true;
            break;
        }
        int rest = vis[s];
        for (int i=0; i<4; i++){
            for (int j=0; j<4; j++){
                int t = flip(i,j,s);
                if (vis[t] == -1){
                    vis[t] = rest + 1 ;
                    row_trace[t] = i;
                    col_trace[t] = j;
                    q.push(t);
                }
            }
        }
    }
    if (hava_ans){
        cout<<vis[0]<<endl;
        int i = row_trace[0], j = col_trace[0], t = 0;
        vector<int> ti,tj;
        while (t != src){
            ti.push_back(i+1);
            tj.push_back(j+1);
            t = flip(i,j,t);
            i = row_trace[t];
            j = col_trace[t];
        }
        for (int i = ti.size()-1; i>=0; i--){
            cout<<ti[i]<<" "<<tj[i]<<endl;
        }
    }
    return 0;
}
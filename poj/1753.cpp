//广搜+状态压缩
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int MAX_N = 65536;
int vis[65536];
int arr[4][4];
int tmparr[4][4];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
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
void int2arr(int t){
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            arr[i][j] = t % 2;
            t /= 2;
        }
    }
}
void flip(int x, int y){
    arr[x][y] = !arr[x][y];
    for (int k=0; k<4; k++){
        if (x+dx[k]>=0 && x+dx[k]<4 && y+dy[k]>=0 && y+dy[k]<4){
            arr[x+dx[k]][y+dy[k]] = !arr[x+dx[k]][y+dy[k]];
        }
    }
}
int main(){
    memset(vis,-1,sizeof(vis));
    for (int i=0; i<4; i++){
        string s;
        getline(cin,s);
        for (int j=0; j<4; j++){
            if (s[j] == 'b'){
                arr[i][j] = 1;
            } else if(s[j] == 'w') {
                arr[i][j] = 0;
            } else return 0;
        }
    }
    int t = arr2int();
    vis[t] = 0;
    q.push(t);
    bool hava_ans = false;
    while (!q.empty()){
        t = q.front();
        q.pop();
        if (t == 0 or t == ((1<<16)-1)) { // 注意运算符的优先级+-是大于移位的
            hava_ans = true;
            break;
        }
        int2arr(t);
        int rest = vis[t];
        memcpy(tmparr,arr, sizeof(arr));
        for (int i=0; i<4; i++){
            for (int j=0; j<4; j++){
                flip(i,j);
                t = arr2int();
                if (vis[t] == -1){
                    vis[t] = rest + 1 ;
                    q.push(t);
                }
                memcpy(arr,tmparr, sizeof(arr));
            }
        }
    }
    if (hava_ans){
        if (vis[0]>= 0){
            cout<<vis[0];
        }else if (vis[(1<<16)-1]>= 0){
            cout<<vis[(1<<16)-1];
        }
    } else {
        cout<<"Impossible";
    }
    return 0;
}
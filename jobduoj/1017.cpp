// 最小生成树算法
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Edge{
    int a;
    int b;
    int value;
};

bool comp(Edge a, Edge b){
    return a.value < b.value;
}
int father[101];

int findRoot(int ind){
    if (father[ind] != -1){
        return findRoot(father[ind]);
    } else {
        return ind;
    }
}

bool merge(int res, int dst){
    int resRoot = findRoot(res);
    int dstRoot = findRoot(dst);
    if (resRoot == dstRoot){
        return false;
    } else {
        father[resRoot] = dstRoot;
        while (father[res] != -1){
            int tmp = father[res];
            father[res] = dstRoot;
            res = tmp;
        }
        return true;
    }
}

int main(){
    int n;
    while (cin >> n && n!=0){
        vector<Edge> vec;
        memset(father,-1, sizeof(father));
        for (int i = 0; i< (n*(n-1)/2); i++){
            Edge edge;
            cin >> edge.a >> edge.b >> edge.value;
            vec.push_back(edge);
        }
        sort(vec.begin(),vec.end(),comp);
        int sum = 0;
        for (vector<Edge>::iterator it = vec.begin(); it < vec.end(); it++){
            if (merge((*it).a,(*it).b)){
                sum += (*it).value;
            }
        }
        cout<<sum<<endl;
    }
}

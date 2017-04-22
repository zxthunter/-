// 重载比较方法
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> Pair;
string lines[110];
int cmp(const Pair &x, const Pair &y){
    if (x.second != y.second){
        return x.second<y.second;
    } else{
        return x.first<y.first;
    }
}
int main() {
    int n,l;
    string s;
    cin>>l>>n;
    getline(cin,s);
    vector<Pair> pairs;
    for (int i=0; i<n; i++){
        int sum = 0;
        getline(cin,s);
        lines[i] = s;
        for (int j=0; j<l-1; j++){
            for (int k=j+1; k<l; k++){
                if (s[j]>s[k]){
                    sum++;
                }
            }
        }
        pairs.push_back(make_pair(i,sum));
    }
    sort(pairs.begin(),pairs.end(),cmp);
    for (vector<Pair>::iterator it = pairs.begin(); it<pairs.end(); it++){
        int ind = it->first;
        cout<<lines[ind]<<endl;
    }
    return 0;
}
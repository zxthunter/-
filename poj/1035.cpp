// STL的使用
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#define DICT_NUM 10000+100
using namespace std;
static string DICT[DICT_NUM];
static map<string,int> dicts[20];
void build(vector<int> & ans,string s){
    //delete
    for (map<string,int>::iterator it = dicts[s.length()-1].begin(); it!=dicts[s.length()-1].end(); it++){
        int time = 0, i =0, j = 0;
        while (i<it->first.length() && j<s.length()){
            if (it->first[i] == s[j]){
                i++;
                j++;
            } else{
                j++;
                if (++time > 1) break;
            }
        }
        if (time<=1) ans.push_back(it->second);
    }
    //replace
    for (map<string,int>::iterator it = dicts[s.length()].begin(); it!=dicts[s.length()].end(); it++){
        int time = 0, i =0, j = 0;
        while (i<it->first.length() && j<s.length()){
            if (it->first[i] == s[j]){
                i++;
                j++;
            } else{
                i++;
                j++;
                if (++time > 1) break;
            }
        }
        if (time<=1) ans.push_back(it->second);
    }
    //insert
    for (map<string,int>::iterator it = dicts[s.length()+1].begin(); it!=dicts[s.length()+1].end(); it++){
        int time = 0, i =0, j = 0;
        while (i<it->first.length() && j<s.length()){
            if (it->first[i] == s[j]){
                i++;
                j++;
            } else{
                i++;
                if (++time > 1) break;
            }
        }
        if (time<=1) ans.push_back(it->second);
    }
}

int main(){
    string s;
    vector<int> v;
    int i = 0;
    while (getline(cin,s) && s[0]!='#'){
        dicts[s.length()].insert(pair<string,int>(s,i));
        DICT[i++] = s;
    }
    while (getline(cin,s) && s[0]!='#'){
        if (dicts[s.length()].count(s)){
            cout<<s<<" is correct"<<endl;
        } else{
            v.clear();
            build(v,s);
            if (v.empty()) {
                cout<<s<<":"<<endl;
                continue;
            }
            sort(v.begin(),v.end());
            cout<<s<<":";
            for (vector<int>::iterator it = v.begin(); it<v.end(); it++){
                cout<<" "<<DICT[*it];
            }
            cout<<endl;
        }
    }
}
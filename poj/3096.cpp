// STL的使用
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
const string ans[2] = {" "," NOT "};
int main() {
    string line;
    while (getline(cin,line) && line[0]!='*'){
        bool res = true;
        int gap = 1;
        while (line.length()>2 && gap<line.length()){
            set<string> s;
            int i=0;
            while (i+gap < line.length()){
                string tmp = line.substr(i,1)+line.substr(i+gap,1);
                if (s.count(tmp)){
                    res = false;
                    break;
                } else {
                    s.insert(tmp);
                }
                i++;
            }
            gap ++;
        }
        cout<<line<<" is"<<(res? ans[0] : ans[1])<<"surprising."<<endl;
    }
    return 0;
}
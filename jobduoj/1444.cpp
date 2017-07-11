#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX_SIZE  = 10000010;
int father[MAX_SIZE];
int num[MAX_SIZE];


int findRoot(int ind){
    if (father[ind] != -1) {
        return findRoot(father[ind]);
    } else {
        return ind;
    }
}

void merge(int src, int dst) {
    int dstRoot = findRoot(dst);
    int srcRoot = findRoot(src);
    if (dstRoot != srcRoot ) {
        father[srcRoot] = dstRoot;
        num[dstRoot] += num[srcRoot];
    }
    while ( father[src] != -1){
        int tmp = father[src];
        father[src] = dstRoot;
        src = tmp;
    }
}


int main() {
    int n;
    while (scanf("%d",&n) != EOF){
        memset(father , -1 , sizeof(father));
        for (int i=0; i<=MAX_SIZE; i++){
            num[i] = 1;
        }
        for (int i=0; i<n; i++) {
            int a,b;
            scanf("%d %d",&a,&b);
            merge(a,b);
        }
//        int max = 0;
//        for (int i=0; i<MAX_SIZE -1 ; i++){
//            if (num[i]>max){
//                max = num[i];
//            }
//        }
        printf("%d\n",*std::max_element(&num[0],&num[MAX_SIZE]));
    }
}

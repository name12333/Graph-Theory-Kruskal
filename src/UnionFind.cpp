#include "UnionFind.h"

UnionFind::UnionFind(int n):parent(n), rank(n, 0){
    for(int i =0;i<n;i++){
        parent[i] = i;
    }
}

// 使用路径压缩来优化查找
int UnionFind::find(int x){
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

bool UnionFind::isSame(int x,int y){
    x = find(x);
    y = find(y);
    return x==y;
}

// 使用按秩合并优化：将rank较小的树连接到rank较大的树上
void UnionFind::join(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    
    // 使用rank优化：将rank较小的树连接到rank较大的树上，这样可以避免树的高度过大
    if(rank[x] < rank[y]) {
        parent[x] = y;
    } else if(rank[x] > rank[y]) {
        parent[y] = x;
    } else {
        parent[y] = x;
        rank[x]++;
    }
}


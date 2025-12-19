#pragma once
#include<vector>

class UnionFind{
public:
    explicit UnionFind(int n);
    int find(int x);
    bool isSame(int x,int y);
    void join(int x,int y);
private:
    std::vector<int> parent;
    std::vector<int> rank;
};
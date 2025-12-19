#pragma once
#include<vector>
#include<string>
#include"Edge.h"

class Graph{
public:
    Graph();
    Graph(int n);
    void addEdge(int u,int v,int cost);
    bool loadFromFile(const std::string& filename);

    int n_verts;
    std::vector<Edge> edges;
};
#include "Graph.h"
#include<iostream>
#include<fstream>

Graph::Graph(){}
Graph::Graph(int v):n_verts(v){}

void Graph::addEdge(int u,int v,int cost){
    edges.push_back({u,v,cost});
}

bool Graph::loadFromFile(const std::string& filename){
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cerr<<"Error opening file: "<<filename<<std::endl;
        return false;
    }
    if(file.peek()==std::ifstream::traits_type::eof()){
        std::cerr<<"File is empty"<<std::endl;
        return false;
    }
    int edgesCount;
    // 验证是否能正确读取顶点数和边数
    if (!(file >> n_verts >> edgesCount)) {
        std::cerr << "Error: Invalid file format: " << filename << std::endl;
        file.close();
        return false;
    }
    // 验证数据有效性
    if (n_verts < 0 || edgesCount < 0) {
        std::cerr << "Error: Invalid graph parameters in file: " << filename << std::endl;
        file.close();
        return false;
    }
    edges.reserve(edgesCount);

    for (int i = 0; i < edgesCount; i++) {
        int u, v, cost;
        if (!(file >> u >> v >> cost)) {
            std::cerr << "Error: Invalid edge data at line " << i + 2 << " in file: " << filename << std::endl;
            file.close();
            return false;
        }
        addEdge(u, v, cost);
    }

    file.close();
    return true;
}
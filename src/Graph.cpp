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

    int edgesCount;
    file>>n_verts>>edgesCount;

    for(int i =0;i<edgesCount;i++){
        int u,v,cost;
        file>>u>>v>>cost;
        addEdge(u,v,cost);
    }
    file.close();
    return true;
}
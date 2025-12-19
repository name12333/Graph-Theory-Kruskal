#include <iostream>
#include "Graph.h"
#include "Kruskal.h"
#include "Exporter.h"
#include "Logger.h"

int main() {
    // 加载或创建网络图
    Graph network;
    if(!network.loadFromFile("../data/network.txt")){
        // 使用默认数据
        network = Graph(5);
        network.addEdge(0, 1, 2);
        network.addEdge(1, 2, 3);
        network.addEdge(2, 3, 1);
        network.addEdge(2, 4, 4);
        network.addEdge(1, 3, 6);
    }
    
    // 计算最小生成树
    std::vector<int> nodes;
    std::vector<ProcessStep> detailedSteps;
    int minCost = Kruskal::runWithDetailedProcess(network, nodes, detailedSteps);
    
    // 导出数据用于可视化
    Exporter::exportDetailedProcess(nodes, detailedSteps, "../web/process.json");
    Exporter::exportGraph(nodes, network.edges, "../web/graph.json");
    
    std::cout << "最小攻击总代价: " << minCost << std::endl;
    
    return 0;
}

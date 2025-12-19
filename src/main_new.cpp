#include <iostream>
#include "Graph.h"
#include "Kruskal.h"
#include "Exporter.h"
#include "Logger.h"

int main() {
    // 加载或创建网络图
    Graph network;
    if(!network.loadFromFile("data/network.txt")){
        // 使用默认数据
        network = Graph(5);
        network.addEdge(0, 1, 2);
        network.addEdge(1, 2, 3);
        network.addEdge(2, 3, 1);
        network.addEdge(2, 4, 4);
        network.addEdge(1, 3, 6);
    }

    // 计算防御前的最小生成树
    std::vector<int> nodes;
    std::vector<ProcessStep> detailedSteps;
    int minCost = Kruskal::runWithDetailedProcess(network, nodes, detailedSteps);

    // 导出防御前数据用于可视化
    Exporter::exportDetailedProcess(nodes, detailedSteps, "web/before_process.json");
    Exporter::exportGraph(nodes, network.edges, "web/before_graph.json");

    std::cout << "防御前最小攻击总代价: " << minCost << std::endl;

    // 创建防御后的网络（增加一些边的代价）
    Graph defendedNetwork = network;
    for(auto& edge : defendedNetwork.edges) {
        edge.cost *= 2; // 将每条边的代价翻倍
    }

    // 计算防御后的最小生成树
    std::vector<int> defendedNodes;
    std::vector<ProcessStep> defendedDetailedSteps;
    int defendedMinCost = Kruskal::runWithDetailedProcess(defendedNetwork, defendedNodes, defendedDetailedSteps);

    // 导出防御后数据用于可视化
    Exporter::exportDetailedProcess(defendedNodes, defendedDetailedSteps, "web/after_process.json");
    Exporter::exportGraph(defendedNodes, defendedNetwork.edges, "web/after_graph.json");

    std::cout << "防御后最小攻击总代价: " << defendedMinCost << std::endl;

    // 计算防御效果
    int increase = defendedMinCost - minCost;
    float increasePercent = (float)increase / minCost * 100;
    std::cout << "防御代价增加: " << increase << " (" << increasePercent << "%)" << std::endl;

    return 0;
}

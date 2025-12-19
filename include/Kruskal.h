#pragma once
#include "Graph.h"
#include <vector>
#include "Exporter.h"  // 引入ProcessStep结构体

class Kruskal{
public:
    // 运行Kruskal算法，记录详细过程（包括考虑但未选择的边）并返回最小生成树的总代价
    static int runWithDetailedProcess(const Graph& graph, std::vector<int>& nodes, std::vector<ProcessStep>& steps);
};
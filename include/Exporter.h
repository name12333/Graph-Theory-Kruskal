#pragma once
#include <vector>
#include <string>
#include "Edge.h"

// 表示算法过程中的一个步骤
struct ProcessStep {
    Edge edge;           // 当前考虑的边
    bool selected;       // 是否被选中加入最小生成树
    std::string reason;  // 选择或拒绝的原因
};

class Exporter {
public:
    // 导出Kruskal算法执行过程到JSON文件，用于可视化
    static void exportProcess(const std::vector<int>& nodes, std::vector<Edge>& steps, const std::string& filename);
    // 导出详细的Kruskal算法执行过程到JSON文件，包含考虑但未选择的边
    static void exportDetailedProcess(const std::vector<int>& nodes, const std::vector<ProcessStep>& steps, const std::string& filename);
    // 导出图结构到JSON文件
    static void exportGraph(const std::vector<int>& nodes, const std::vector<Edge>& edges, const std::string& filename);
};

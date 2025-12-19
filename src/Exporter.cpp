#include "Exporter.h"
#include <fstream>
#include <iostream>

/**
 * 导出Kruskal算法执行过程到JSON文件，用于可视化
 * 
 * @param nodes 图中的节点列表
 * @param steps 算法执行过程中选择的边（按顺序）
 * @param filename 输出文件名
 */
void Exporter::exportProcess(const std::vector<int>& nodes,std::vector<Edge>& steps, const std::string& filename) {
    // 打开输出文件
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // 开始写入JSON格式
    file << "{\n";

    // 写入节点列表
    file << "  \"nodes\": [";
    for (size_t i = 0; i < nodes.size(); ++i) {
        file << nodes[i];
        if (i < nodes.size() - 1) file << ", ";
    }
    file << "],\n";

    // 写入算法步骤（按顺序选择的边）
    file << "  \"steps\": [\n";
    for (size_t i = 0; i < steps.size(); ++i) {
        const Edge& e = steps[i];
        file << "    {\"from\": " << e.from << ", \"to\": " << e.to << ", \"cost\": " << e.cost << "}";
        if (i < steps.size() - 1) file << ",";
        file << "\n";
    }
    file << "  ]\n";

    // 结束JSON格式
    file << "}\n";

    // 关闭文件
    file.close();
}

/**
 * 导出详细的Kruskal算法执行过程到JSON文件，包含考虑但未选择的边
 *
 * @param nodes 图中的节点列表
 * @param steps 算法执行过程中的所有步骤（包括考虑但未选择的边）
 * @param filename 输出文件名
 */
void Exporter::exportDetailedProcess(const std::vector<int>& nodes, const std::vector<ProcessStep>& steps, const std::string& filename) {
    // 打开输出文件
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // 开始写入JSON格式
    file << "{\n";

    // 写入节点列表
    file << "  \"nodes\": [";
    for (size_t i = 0; i < nodes.size(); ++i) {
        file << nodes[i];
        if (i < nodes.size() - 1) file << ", ";
    }
    file << "],\n";

    // 写入算法步骤（所有考虑的边）
    file << "  \"steps\": [\n";
    for (size_t i = 0; i < steps.size(); ++i) {
        const ProcessStep& step = steps[i];
        file << "    {\"from\": " << step.edge.from << ", \"to\": " << step.edge.to << ", \"cost\": " << step.edge.cost;
        file << ", \"selected\": " << (step.selected ? "true" : "false");
        file << ", \"reason\": \"" << step.reason << "\"}";
        if (i < steps.size() - 1) file << ",";
        file << "\n";
    }
    file << "  ]\n";

    // 结束JSON格式
    file << "}\n";

    // 关闭文件
    file.close();
}

/**
 * 导出图结构到JSON文件
 * 
 * @param nodes 图中的节点列表
 * @param edges 图中的所有边
 * @param filename 输出文件名
 */
void Exporter::exportGraph(const std::vector<int>& nodes, const std::vector<Edge>& edges, const std::string& filename) {
    // 打开输出文件
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // 开始写入JSON格式
    file << "{\n";

    // 写入节点列表
    file << "  \"nodes\": [";
    for (size_t i = 0; i < nodes.size(); ++i) {
        file << nodes[i];
        if (i < nodes.size() - 1) file << ", ";
    }
    file << "],\n";

    // 写入所有边
    file << "  \"edges\": [\n";
    for (size_t i = 0; i < edges.size(); ++i) {
        const Edge& e = edges[i];
        file << "    {\"from\": " << e.from << ", \"to\": " << e.to << ", \"cost\": " << e.cost << "}";
        if (i < edges.size() - 1) file << ",";
        file << "\n";
    }
    file << "  ]\n";

    // 结束JSON格式
    file << "}\n";

    // 关闭文件
    file.close();

}

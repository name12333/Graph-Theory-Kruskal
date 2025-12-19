#include "Kruskal.h"
#include "UnionFind.h"
#include "Logger.h"
#include <algorithm>
#include <iostream>


int Kruskal::runWithDetailedProcess(const Graph &graph, std::vector<int>& nodes, std::vector<ProcessStep>& steps) {
    // 准备节点列表
    nodes.clear();
    for(int i = 0; i < graph.n_verts; i++) {
        nodes.push_back(i);
    }

    // 准备边列表并排序
    auto edges = graph.edges;
    std::sort(edges.begin(), edges.end(), [](const Edge& a,const Edge& b){
        return a.cost<b.cost; // 返回true表示a应该排在b前面
    });

    UnionFind uf(graph.n_verts);
    int totalCost = 0;
    int edgesAdded = 0;

    // 清空步骤记录
    steps.clear();

    Logger::log("开始最小攻击代价分析（含详细过程记录）");

    std::cout << "[+] 最小攻击代价攻击路径集合:";
    for(const auto& e:edges){
        // 检查两个顶点是否已经在同一个集合中（是否已连通）
        int rootFrom = uf.find(e.from);
        int rootTo = uf.find(e.to);
        std::cout << "    检查边 " << e.from << " -> " << e.to << ": " 
                  << e.from << "的根是" << rootFrom << ", " 
                  << e.to << "的根是" << rootTo << std::endl;

        if(!uf.isSame(e.from, e.to)){
            // 不在同一个集合中，加入这条边不会形成环
            uf.join(e.from, e.to);
            totalCost += e.cost;
            edgesAdded++;

            // 记录步骤（被选中的边）
            ProcessStep step;
            step.edge = e;
            step.selected = true;
            step.reason = "顶点不在同一集合中，不会形成环";
            steps.push_back(step);

            std::cout << "    边: " << e.from << " -> " << e.to << ", 代价: " << e.cost << std::endl;

            // 如果已经添加了足够的边（n-1条边），则提前结束
            if(edgesAdded == graph.n_verts - 1) {
                break;
            }
        } else {
            // 在同一个集合中，加入这条边会形成环，不选择
            ProcessStep step;
            step.edge = e;
            step.selected = false;
            step.reason = "顶点已在同一集合中，会形成环";
            steps.push_back(step);

            std::cout << "    跳过边: " << e.from << " -> " << e.to << ", 代价: " << e.cost << " (会形成环)" << std::endl;
        }
    }

    std::cout << "[+] 最小攻击总代价: " << totalCost << std::endl;
    Logger::result("最小攻击总代价: " + std::to_string(totalCost));
    return totalCost;
}
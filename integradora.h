
#ifndef INTEGRADORA_H
#define INTEGRADORA_H

#include <vector>
#include <utility>

struct Edge {
    int u, v, peso;
    bool operator<(const Edge &other) const {
        return peso < other.peso;
    }
};

class UnionFind {
public:
    std::vector<int> parent, rank;
    UnionFind(int N);
    int FindSet(int x);
    void UnionSet(int x, int y);
};

std::vector<Edge> get_edges(int N, const std::vector<std::vector<int>> &graph);
std::vector<Edge> kruskal_mst(int N, const std::vector<std::vector<int>> &graph);
std::pair<int, std::vector<int>> viajante(int N, const std::vector<std::vector<int>> &graph);
int bfs(int N, std::vector<std::vector<int>> &residual, std::vector<int> &parent, int source, int sink);
void update_flow(std::vector<std::vector<int>> &residual, const std::vector<int> &parent, int flow, int source, int sink);
int flujo_max(int N, const std::vector<std::vector<int>> &capacity, int source, int sink);
std::vector<std::pair<int, int>> central_cerca(const std::vector<std::pair<int, int>> &colonias);

#endif

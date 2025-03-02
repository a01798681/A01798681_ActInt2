
/*
Actividad Integradora 2
 * Programa que ayude a una empresa que quiere incursionar en los servicios de Internet.
 * Autores:
 *   - Andrés Cabrera Alvarado - A01798681
 *   - José Eduardo Rosas Poncio - A01784461
 *   - Yael Octavio Pérez Méndez - A01799842
 * Fecha de creación: 26/01/25
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <limits>
#include "integradora.h"
using namespace std;

const int INF = numeric_limits<int>::max();

UnionFind::UnionFind(int N) : parent(N), rank(N, 0) {
    for (int i = 0; i < N; ++i) parent[i] = i;
}

int UnionFind::FindSet(int x) {
    if (x != parent[x]){
        parent[x] = FindSet(parent[x]); // Path compression
    }
    return parent[x];
}

void UnionFind::UnionSet(int x, int y) {
    int rx = FindSet(x), ry = FindSet(y);
    if (rx != ry) {
        if (rank[rx] > rank[ry]){
            swap(rx, ry);
        }
        parent[rx] = ry;
        if (rank[rx] == rank[ry]){
            ++rank[ry];
        }
    }
}

vector<Edge> get_edges(int N, const vector<vector<int>> &graph) {
    vector<Edge> edges;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if (graph[i][j] > 0){
                 edges.push_back({i, j, graph[i][j]});
            }
    return edges;
}

vector<Edge> kruskal_mst(int N, const vector<vector<int>> &graph) {
    vector<Edge> edges = get_edges(N, graph);
    sort(edges.begin(), edges.end());
    
    UnionFind uf(N);
    vector<Edge> result;

    for (const auto &edge : edges) {
        if (uf.FindSet(edge.u) != uf.FindSet(edge.v)) {
            result.push_back(edge);
            uf.UnionSet(edge.u, edge.v);
        }
    }
    return result;
}

/*
 * @brief Resuelve el problema del Viajante utilizando fuerza bruta.
 * @param N Número de ciudades.
 * @param graph Matriz de adyacencia con los costos entre ciudades.
 * @return Un par con el costo mínimo y la mejor ruta encontrada.
 */
pair<int, vector<int>> viajante(int N, const vector<vector<int>> &graph){
    vector<int> cities(N), mejor_ruta;
    for (int i = 0; i < N; ++i) cities[i] = i;
    int minCost = INF;
    do{
        int cost = 0;
        for (int i = 0; i < N - 1; ++i)
            cost += graph[cities[i]][cities[i + 1]];
        cost += graph[cities[N - 1]][cities[0]];
        if (cost < minCost){
            minCost = cost;
            mejor_ruta = cities;
        }
    } while (next_permutation(cities.begin(), cities.end()));
    return {minCost, mejor_ruta};
}

int bfs(int N, vector<vector<int>> &residual, vector<int> &parent, int source, int sink) {
    fill(parent.begin(), parent.end(), -1);
    queue<pair<int, int>> q;
    q.push({source, INF});
    parent[source] = source;

    while (!q.empty()) {
        auto [node, flow] = q.front();
        q.pop();
        
        for (int next = 0; next < N; ++next) {
            if (parent[next] == -1 && residual[node][next] > 0) {
                parent[next] = node;
                int newFlow = min(flow, residual[node][next]);
                if (next == sink){
                    return newFlow;
                }
                q.push({next, newFlow});
            }
        }
    }
    return 0;
}

void update_flow(vector<vector<int>> &residual, const vector<int> &parent, int flow, int source, int sink) {
    int cur = sink;
    while (cur != source) {
        int prev = parent[cur];
        residual[prev][cur] -= flow;
        residual[cur][prev] += flow;
        cur = prev;
    }
}

int flujo_max(int N, const vector<vector<int>> &capacity, int source, int sink) {
    vector<vector<int>> residual = capacity;
    vector<int> parent(N);
    int max_flujo = 0, flow;

    while ((flow = bfs(N, residual, parent, source, sink))) {
        max_flujo += flow;
        update_flow(residual, parent, flow, source, sink);
    }

    return max_flujo;
}

/*
 * @brief Encuentra la central más cercana a cada ubicación utilizando distancias euclidianas.
 * @param N Número de ubicaciones.
 * @param ubicacion Vector de coordenadas (x, y) de las ubicaciones.
 * @param centrals Vector de coordenadas (x, y) de las centrales.
 * @return Un vector donde cada índice indica la central más cercana a la ubicación correspondiente.
 */
vector<pair<int, int>> central_cerca(const vector<pair<int, int>> &colonias) {
    vector<pair<int, int>> resultado(colonias.size());
    for (int i = 0; i < colonias.size(); ++i) {
        double min_dist = INF;
        pair<int, int> mejor_central = colonias[i];  // Si no encuentra mejor, se queda igual
        for (int j = 0; j < colonias.size(); ++j) {
            if (i == j){
                    continue;
            }
            double dist = sqrt(pow(colonias[i].first - colonias[j].first, 2) + 
                               pow(colonias[i].second - colonias[j].second, 2));
            if (dist < min_dist) {
                min_dist = dist;
                mejor_central = colonias[j];  // Se asigna la mejor central
            }
        }
        resultado[i] = mejor_central;
    }
    return resultado;
}

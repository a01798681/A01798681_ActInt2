
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
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge{
    int u, v, peso;
    bool operator<(const Edge &other) const{
        return peso < other.peso;
    }
};

/*
 * @brief Encuentra el spanning tree utilizando el algoritmo de Kruskal.
 * @param N Número de nodos en el grafo.
 * @param graph Matriz de adyacencia que representa el grafo.
 * @return Un vector de aristas que forman el árbol de expansión mínima.
 */
vector<Edge> kruskal_mst(int N, const vector<vector<int>> &graph){
    vector<Edge> edges, result;
    vector<int> parent(N), rank(N, 0);
    for (int i = 0; i < N; ++i) parent[i] = i;
    auto find = [&](int x){
        while (x != parent[x]) x = parent[x];
        return x;
    };
    auto conjunto_set = [&](int x, int y){
        int rx = find(x), ry = find(y);
        if (rx != ry){
            if (rank[rx] > rank[ry])
                parent[ry] = rx;
            else if (rank[rx] < rank[ry])
                parent[ry] = ry;
            else
                parent[ry] = rx, ++rank[rx];
        }
    };
    for (int i = 0; i < N; ++i){
        for (int j = i + 1; j < N; ++j){
            if (graph[i][j] > 0){
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }
    sort(edges.begin(), edges.end());
    for (const auto &edge : edges){
        if (find(edge.u) != find(edge.v)){
            result.push_back(edge);
            conjunto_set(edge.u, edge.v);
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

/*
 * @brief Calcula el flujo máximo en un grafo utilizando el algoritmo de Edmonds-Karp.
 * @param N Número de nodos en el grafo.
 * @param capacity Matriz de capacidades de las aristas.
 * @param source Nodo fuente.
 * @param sink Nodo sumidero.
 * @return El flujo máximo desde el nodo fuente al sumidero.
 */
int flujo_max(int N, const vector<vector<int>> &capacity, int source, int sink){
    vector<vector<int>> residual = capacity;
    vector<int> parent(N);
    auto bfs = [&](){
        fill(parent.begin(), parent.end(), -1);
        queue<pair<int, int>> q;
        q.push({source, INF});
        parent[source] = source;
        while (!q.empty()){
            int node = q.front().first;
            int flow = q.front().second;
            q.pop();
            for (int next = 0; next < N; ++next){
                if (parent[next] == -1 && residual[node][next] > 0){
                    parent[next] = node;
                    int newFlow = min(flow, residual[node][next]);
                    if (next == sink) return newFlow;
                    q.push({next, newFlow});
                }
            }
        }
        return 0;
    };
    int max_flujo = 0, flow;
    while ((flow = bfs())){
        max_flujo += flow;
        int cur = sink;
        while (cur != source){
            int prev = parent[cur];
            residual[prev][cur] -= flow;
            residual[cur][prev] += flow;
            cur = prev;
        }
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
vector<pair<int, int>> central_cerca(const vector<pair<int, int>> &colonias){
    vector<pair<int, int>> resultado(colonias.size());
    for (int i = 0; i < colonias.size(); ++i){
        double min_dist = INF;
        pair<int, int> mejor_central = colonias[i];  // Si no encuentra mejor, se queda igual
        for (int j = 0; j < colonias.size(); ++j){
            double dist = sqrt(pow(colonias[i].first - colonias[j].first, 2) + pow(colonias[i].second - colonias[j].second, 2));
            if (dist < min_dist){
                min_dist = dist;
                mejor_central = colonias[j];  // Se asigna la mejor central
            }
        }
        resultado[i] = mejor_central;
    }
    return resultado;
}


/*
 * @brief Función principal que lee los datos de entrada y llama a las funciones anteriores.
 * @return 0 si el programa se ejecuta correctamente.
*/

int main(){
    cout << "num de colonias (N): ";
    int N;
    cin >> N;

    cout << "matriz de distancias (N x N):\n";
    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> graph[i][j];

    cout << "matriz de capacidades (N x N):\n";
    vector<vector<int>> capacity(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> capacity[i][j];

    cout << "coordenadas (x,y):\n";
    vector<pair<int, int>> ubicacion(N);
    for (int i = 0; i < N; ++i){
        char temp;
        cin >> temp >> ubicacion[i].first >> temp >> ubicacion[i].second >> temp;
    }

    cout << "\nSALIDA:";
    // 1. Minimum Spanning Tree
    auto mst = kruskal_mst(N, graph);
    cout << "\nForma de cablear las colonias con fibra (A,B):\n";
    for (const auto &edge : mst){
        cout << "(" << char('A' + edge.u) << ", " << char('A' + edge.v) << ")\n";
    }

    // 2. Traveling Salesman Problem
    auto [minCost, bestRoute] = viajante(N, graph);
    cout << "ruta a seguir por el personal:\n";
    for (int city : bestRoute){
        cout << char('A' + city) << " ";
    }
    cout << char('A' + bestRoute[0]) << "\n";

    // 3. Maximum Flow
    int source = 0, sink = N - 1;
    int max_flujo = flujo_max(N, capacity, source, sink);
    cout << "flujo maximo de informacion: " << max_flujo << "\n";

    // 4. Closest Centrals
    auto nuevos_puntos = central_cerca(ubicacion); // Se asume que algunas ubicaciones son centrales
    cout << "lista de poligonos:\n";
    for (const auto &punto : nuevos_puntos){
        cout << "(" << punto.first << ", " << punto.second << ")\n";
    }

    return 0;
}

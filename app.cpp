
#include "main.cpp"

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

#include "main.cpp"
#include <gtest/gtest.h>

// Test para Kruskal
TEST(KruskalTest, BasicGraph) {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    auto mst = kruskal_mst(5, graph);
    EXPECT_EQ(mst.size(), 4);  // Un MST de 5 nodos tiene 4 aristas
}

// Test para Viajante
TEST(ViajanteTest, SimpleGraph) {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    auto [minCost, bestRoute] = viajante(4, graph);
    EXPECT_EQ(minCost, 80);  // Ruta óptima
}

// Test para Flujo Máximo (Edmonds-Karp)
TEST(MaxFlowTest, SmallNetwork) {
    vector<vector<int>> capacity = {
        {0, 10, 5, 0, 0, 0},
        {0, 0, 15, 9, 0, 0},
        {0, 4, 0, 0, 8, 0},
        {0, 0, 0, 0, 15, 10},
        {0, 0, 0, 0, 0, 10},
        {0, 0, 0, 0, 0, 0}
    };
    EXPECT_EQ(flujo_max(6, capacity, 0, 5), 14);  // Flujo máximo esperado
}

// Test para Centrales más Cercanas
TEST(CentralTest, BasicLocations) {
    vector<pair<int, int>> colonias = {{0, 0}, {5, 5}, {10, 10}};
    auto result = central_cerca(colonias);
    EXPECT_EQ(result.size(), 3);  // Debe asignar una central a cada colonia
}

// Función principal para ejecutar los tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

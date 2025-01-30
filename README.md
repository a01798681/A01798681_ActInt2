# Actividad Integradora 2

## Descripción

Este proyecto incluye dos programas que analizan archivos de texto para realizar tareas específicas como:
1. Verificar la presencia de patrones en archivos de texto.
2. Identificar el palíndromo más largo en un archivo de texto.
3. Encontrar la subcadena común más larga entre dos archivos.
4. Implementar el algoritmo de la función Z para búsqueda eficiente de patrones.

El propósito de implementar dos algoritmos diferentes en este proyecto fue evaluar cual de los dos mostraba 
una eficiencia mayor y de esta manera evaluar su complejidad espacial y computacional.

**Fecha de creación:** 21/01/2025

---

## Archivos
### 1. `main.cpp`
Este archivo resuelve cuatro problemas fundamentales para optimizar la infraestructura de servicios de Internet en una población pequeña:

- **Parte 1:** Determina la mejor forma de cablear las colonias con la menor cantidad de fibra óptica, utilizando el algoritmo de **Kruskal**.
- **Parte 2:** Encuentra la **ruta óptima** para recorrer todas las colonias exactamente una vez y regresar al punto de inicio, resolviendo el **Problema del Viajante (TSP)**.
- **Parte 3:** Calcula el **flujo máximo de información** entre dos colonias, utilizando el **algoritmo de Ford-Fulkerson**.
- **Parte 4:** Identifica la **central más cercana** a cada colonia basándose en la distancia euclidiana, facilitando la expansión de la red.

#### **Funciones principales:**
- **`get_edges`**: Extrae todas las conexiones posibles entre colonias a partir de la matriz de adyacencias.
- **`kruskal_mst`**: Aplica el algoritmo de **Kruskal** para encontrar la forma más eficiente de cablear las colonias.
- **`viajante`**: Encuentra la ruta más corta para recorrer todas las colonias mediante **fuerza bruta**.
- **`bfs`**: Implementa **BFS** para encontrar caminos aumentantes en la red de flujo.
- **`flujo_max`**: Calcula el **flujo máximo de información** en la red utilizando el algoritmo de **Ford-Fulkerson**.
- **`central_cerca`**: Determina la **central más cercana** para cada colonia usando distancia euclidiana.

#### Uso:
El programa requiere archivos de entrada (`integradora.h`) en el mismo directorio para ejecutar correctamente.

---

### 2. `app.cpp`
Este archivo ejecuta el programa principal que permite optimizar la infraestructura de una red de Internet en una población pequeña. Se encarga de leer los datos de entrada y llamar a las funciones principales para calcular la mejor forma de cableado, la ruta óptima de distribución, el flujo máximo de datos y la asignación de nuevas centrales.

#### **Procesos principales:**
- **Parte 1:** Determina la mejor manera de cablear las colonias utilizando el **algoritmo de Kruskal**, minimizando el costo total de fibra óptica.
- **Parte 2:** Encuentra la **ruta más corta** para recorrer todas las colonias exactamente una vez y regresar al punto de inicio, resolviendo el **Problema del Viajante (TSP)**.
- **Parte 3:** Calcula el **flujo máximo de información** entre dos colonias, utilizando el **algoritmo de Ford-Fulkerson**.
- **Parte 4:** Identifica la **central más cercana** a cada colonia basándose en la distancia euclidiana, facilitando la expansión de la red.

### **2. Funciones principales**
- **`kruskal_mst(N, graph)`**: Aplica el **algoritmo de Kruskal** para encontrar la forma más eficiente de cablear las colonias con fibra óptica.
- **`viajante(N, graph)`**: Encuentra la **ruta más corta** para la entrega de documentos y notificaciones mediante **fuerza bruta**.
- **`flujo_max(N, capacity, source, sink)`**: Calcula el **flujo máximo de información** en la red utilizando el **algoritmo de Ford-Fulkerson**.
- **`central_cerca(ubicacion)`**: Determina la **central más cercana** para cada colonia usando distancia euclidiana.

#### Uso:
El programa requiere archivos de entrada (`main.cpp`) en el mismo directorio para ejecutar correctamente.

---

### 3. `test.cpp`
Este archivo contiene pruebas unitarias para validar el correcto funcionamiento de las funciones principales del programa utilizando **Google Test**. Las pruebas aseguran que los algoritmos implementados para la optimización de redes de Internet produzcan los resultados esperados en diferentes escenarios.

#### **Casos de prueba incluidos:**
- **Test 1: Kruskal - Construcción del Árbol de Expansión Mínima (MST)**
  - Valida que el **algoritmo de Kruskal** genere un **árbol de expansión mínima** con el número correcto de aristas.
  - **Función probada:** `kruskal_mst(N, graph)`

- **Test 2: Viajante - Ruta Óptima del Repartidor**
  - Evalúa la solución del **Problema del Viajante (TSP)**, verificando que el costo mínimo calculado sea el esperado.
  - **Función probada:** `viajante(N, graph)`

- **Test 3: Flujo Máximo - Análisis de Capacidad de la Red**
  - Prueba el cálculo del **flujo máximo** entre dos nodos de una red, utilizando **Edmonds-Karp** (implementación de Ford-Fulkerson con BFS).
  - **Función probada:** `flujo_max(N, capacity, source, sink)`

- **Test 4: Centrales Más Cercanas**
  - Confirma que la función que encuentra la **central más cercana** para cada colonia devuelve un resultado válido.
  - **Función probada:** `central_cerca(colonias)`

#### Uso:
El programa requiere archivos de entrada (`main.cpp`) en el mismo directorio para ejecutar correctamente.

---

### 4. `integradora.h`
Este archivo define las estructuras y funciones principales del programa, asegurando modularidad y reutilización del código en la optimización de redes de Internet.

### **Estructuras**
- **`Edge`**: Representa una conexión entre colonias con su peso (distancia).
- **`UnionFind`**: Implementa conjuntos disjuntos para manejar la conectividad en el **Árbol de Expansión Mínima (MST)**.

### **Funciones Principales**
- **`kruskal_mst(N, graph)`** → Encuentra el **MST** con **Kruskal**.
- **`viajante(N, graph)`** → Calcula la **ruta óptima** para el **Problema del Viajante (TSP)**.
- **`flujo_max(N, capacity, source, sink)`** → Determina el **flujo máximo** de datos con **Ford-Fulkerson**.
- **`central_cerca(colonias)`** → Encuentra la **central más cercana** a cada colonia.


##Requerimientos
- Compilador C++ (compatible con C++11 o superior).
- Tener instalado gtest y Cmake
- Archivos de texto en el mismo directorio que los ejecutables.

##Autores
- Andrés Cabrera Alvarado A01798681
- José Eduardo Rosas Poncio A01784461
- Yael Octavio Pérez Méndez A01799842

---

## Contribuciones
- **Andrés Cabrera Alvarado (A01798681):**
  - Implementación de las estructuras `Edge` y `UnionFind` en `integradora.h`.
  - Desarrollo de la función `kruskal_mst` para encontrar el **Árbol de Expansión Mínima (MST)**.
  - Procesamiento de la **matriz de distancias (N x N)** en `main.cpp`.
  - Generación de la salida con la forma óptima de **cablear las colonias con fibra óptica**.

- **José Eduardo Rosas Poncio (A01784461):**
  - Implementación del **Problema del Viajante (TSP)** en `integradora.h` mediante fuerza bruta.
  - Desarrollo de las funciones `bfs`, `update_flow` y `flujo_max` para calcular el **flujo máximo de datos** en `integradora.h`.
  - Procesamiento de la **matriz de capacidades (N x N)** en `main.cpp`.
  - Generación de la salida con la **ruta óptima del viajante** y el **flujo máximo de información**.

- **Yael Octavio Pérez Méndez (A01799842):**
  - Implementación de la función `central_cerca` en `integradora.h` para asignar cada colonia a la **central más cercana**.
  - Procesamiento de la **lista de coordenadas de las colonias** en `main.cpp`.
  - Generación de la salida con la **asignación de colonias a centrales** en formato de polígonos.

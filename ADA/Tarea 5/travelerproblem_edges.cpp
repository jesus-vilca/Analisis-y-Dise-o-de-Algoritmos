#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct Edge {
    int src;
    int dest;
    int weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int vertex, vector<int>& parent) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent[vertex], parent);
}

void unionSets(int x, int y, vector<int>& parent) {
    int parentX = findParent(x, parent);
    int parentY = findParent(y, parent);
    parent[parentX] = parentY;
}

vector<int> getMST(const vector<Edge>& edges, int numVertices) {
    vector<int> parent(numVertices, -1);
    vector<Edge> mst;
    vector<int> mstPath;

    int numEdges = edges.size();
    int edgeCount = 0;
    int index = 0;

    while (edgeCount < numVertices - 1 && index < numEdges) {
        Edge currEdge = edges[index++];
        int srcParent = findParent(currEdge.src, parent);
        int destParent = findParent(currEdge.dest, parent);

        if (srcParent != destParent) {
            mst.push_back(currEdge);
            unionSets(srcParent, destParent, parent);
            edgeCount++;
        }
    }

    for (const Edge& edge : mst) {
        mstPath.push_back(edge.src);
        mstPath.push_back(edge.dest);
    }

    return mstPath;
}

void performDFS(const vector<vector<int>>& graph, int startVertex, vector<bool>& visited, stack<int>& dfsStack) {
    dfsStack.push(startVertex);
    visited[startVertex] = true;

    while (!dfsStack.empty()) {
        int currVertex = dfsStack.top();
        dfsStack.pop();

        for (int neighbor : graph[currVertex]) {
            if (!visited[neighbor]) {
                dfsStack.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

vector<int> greedyTSP(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<Edge> edges;

    // Construir un vector de aristas con pesos
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    // Ordenar las aristas en orden ascendente de peso
    sort(edges.begin(), edges.end(), compareEdges);

    // Obtener el árbol de expansión mínimo (MST)
    vector<int> mstPath = getMST(edges, numVertices);

    // Construir un grafo representando el MST
    vector<vector<int>> mstGraph(numVertices);
    for (int i = 0; i < mstPath.size(); i += 2) {
        int src = mstPath[i];
        int dest = mstPath[i + 1];
        mstGraph[src].push_back(dest);
        mstGraph[dest].push_back(src);
    }

    // Realizar un recorrido en profundidad (DFS) sobre el MST
    vector<bool> visited(numVertices, false);
    stack<int> dfsStack;
    vector<int> tspPath;

    performDFS(mstGraph, 0, visited, dfsStack);

    // Obtener el recorrido aproximado
    while (!dfsStack.empty()) {
        tspPath.push_back(dfsStack.top());
        dfsStack.pop();
    }

    return tspPath;
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 9, 10},
        {2, 0, 6, 4},
        {9, 6, 0, 8},
        {10, 4, 8, 0}
    };

    vector<int> tspPath = greedyTSP(graph);

    cout << "Recorrido aproximado: ";
    for (int vertex : tspPath) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}

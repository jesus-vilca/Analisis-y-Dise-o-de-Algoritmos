#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

int findNearestVertex(int currVertex, const vector<vector<int>>& graph, vector<bool>& visited) {
    int n = graph.size();
    int nearestVertex = -1;
    int minDistance = INF;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currVertex][i] < minDistance) {
            minDistance = graph[currVertex][i];
            nearestVertex = i;
        }
    }

    return nearestVertex;
}

vector<int> greedyTSP(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> tspPath;
    tspPath.push_back(0);
    visited[0] = true;

    for (int i = 0; i < n - 1; i++) {
        int lastVertex = tspPath.back();
        int nearestVertex = findNearestVertex(lastVertex, graph, visited);
        tspPath.push_back(nearestVertex);
        visited[nearestVertex] = true;
    }

    tspPath.push_back(0); // Volver al punto de partida

    return tspPath;
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 9, 10},
        {1, 0, 6, 4},
        {15, 7, 0, 8},
        {6, 3, 12, 0}
    };

    vector<int> tspPath = greedyTSP(graph);

    cout << "Recorrido aproximado: ";
    for (int vertex : tspPath) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

int tsp(int n, vector<vector<int>>& graph, int start) {
    vector<int> vertex;
    for (int i = 0; i < n; i++) {
        if (i != start) vertex.push_back(i);
    }

    int minPath = INF;
    do {
        int currentPathWeight = 0;
        int k = start;
        for (int i = 0; i < vertex.size(); i++) {
            currentPathWeight += graph[k][vertex[i]];
            k = vertex[i];
        }
        currentPathWeight += graph[k][start];
        minPath = min(minPath, currentPathWeight);
    } while (next_permutation(vertex.begin(), vertex.end()));

    return minPath;
}

int main() {
    int n = 4; // Number of cities
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int start = 0; // Start from city 0

    int minPath = tsp(n, graph, start);

    cout << "Minimum Path Length: " << minPath << endl;

    return 0;
}

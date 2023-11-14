#include <iostream>
#include <vector>
using namespace std;

// Undirected graph
class Graph {
public:
    Graph(int v) {
        this->v = v;
        adj.resize(v + 1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int start, vector<bool>& visited) {
        if (!visited[start]) {
            visited[start] = true;

            for (auto i : adj[start]) {
                dfs(i, visited);
            }
        }

        return;
    }

private:
    vector<vector<int>> adj; // adjacency list
    int v; // number of vertices
};


int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    Graph myGraph(vertices);

    while(edges--) {
        int x, y;
        cin >> x >> y;

        myGraph.addEdge(x, y);
    }

    vector<bool> visited(edges, false);
    int connectedComponents = 0;

    for (int i = 1; i <= vertices; i++) {
        if (!visited[i]) {
            myGraph.dfs(i, visited);
            connectedComponents++;
        }
    }

    cout << connectedComponents << endl;

    return 0;
}

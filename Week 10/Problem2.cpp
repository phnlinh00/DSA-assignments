#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Directed graph
class Graph {
public:
    Graph(int v) {
        this->v = v;
        adj.resize(v + 1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    int shortestPath(vector<int>& distances, int start, int end) {
        queue<int> q;
        q.push(start);
        distances[start] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == end) {
                return distances[node];
            }

            for (int neighbor : adj[node]) {
                if (distances[neighbor] == -1) {
                    distances[neighbor] = distances[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return -1; // No path found
    }

private:
    vector<vector<int>> adj; // adjacency list
    int v; // number of vertices
};


int main() {
    int vertices, edges, start, end;
    cin >> vertices >> edges >> start >> end;

    Graph myGraph(vertices);

    while(edges--) {
        int x, y;
        cin >> x >> y;

        myGraph.addEdge(x, y);
    }

    vector<int> distances(vertices + 1, -1);

    cout << myGraph.shortestPath(distances, start, end);

    return 0;
}

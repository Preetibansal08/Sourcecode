#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

typedef pair<int, int> pii;  // Pair to represent a node and its weight (weight, node)

// Function to find the shortest path from the source to all other nodes using Dijkstra's Algorithm
void dijkstra(int source, vector<vector<pii>>& graph, vector<int>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});  // Push the source node with distance 0
    dist[source] = 0;

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // If the current distance is greater than the recorded distance, skip processing
        if (currDist > dist[node]) continue;

        for (auto edge : graph[node]) {
            int nextNode = edge.first;
            int weight = edge.second;
            int newDist = currDist + weight;

            if (newDist < dist[nextNode]) {
                dist[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pii>> graph(n + 1);
    vector<int> dist(n + 1, numeric_limits<int>::max());

    cout << "Enter the edges (node1, node2, weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // If the graph is undirected
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    dijkstra(source, graph, dist);

    cout << "Shortest distances from source node " << source << ":" << endl;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == numeric_limits<int>::max()) {
            cout << "Node " << i << " is unreachable" << endl;
        } else {
            cout << "Node " << i << " : " << dist[i] << endl;
        }
    }

    return 0;
}

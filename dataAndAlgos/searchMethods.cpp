#include <vector>
#include <queue>

using namespace std;

// Graph stored as: adj[u] = list of neighbors of u
// Example: adj[0] = {1,2} means edges 0→1 and 0→2
vector<int> bfs(int start, int n, vector<vector<int>>& adj) {
    vector<int> dist(n, -1); // distance (in edges) from start
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) { // go through neighbors
            if (dist[v] == -1) { // not visited yet
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist; // dist[v] = shortest steps from start to v
}

// Graph stored as: adj[u] = list of {neighbor, weight}
// Example: adj[0] = {{1,4}, {2,7}} means edges 0→1 (weight 4), 0→2 (weight 7)
vector<int> dijkstra(int start, int n, vector<vector<pair<int,int>>>& adj) {
    vector<int> dist(n, INT_MAX); // distance from start to each node
    dist[start] = 0;

    // Min-heap ordered by (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // stale entry, skip

        for (auto [v, w] : adj[u]) { // explore neighbors
            if (dist[u] + w < dist[v]) { // found shorter path
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist; // dist[v] = shortest distance from start to v
}

// Graph stored as: adj[u] = list of {neighbor, weight}
// Heuristic: function<int(int,int)> heuristic(node, goal)
int astar(int start, int goal, int n,
          vector<vector<pair<int,int>>>& adj,
          function<int(int,int)> heuristic) {

    vector<int> g(n, INT_MAX); // cost from start to node
    g[start] = 0;

    // Min-heap ordered by f = g + h
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({heuristic(start, goal), start});

    while (!pq.empty()) {
        auto [f, u] = pq.top(); pq.pop();
        if (u == goal) return g[u]; // found shortest path

        for (auto [v, w] : adj[u]) {
            int tentative = g[u] + w;
            if (tentative < g[v]) { // found better path
                g[v] = tentative;
                int fscore = tentative + heuristic(v, goal);
                pq.push({fscore, v});
            }
        }
    }
    return -1; // goal unreachable
}

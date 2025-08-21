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

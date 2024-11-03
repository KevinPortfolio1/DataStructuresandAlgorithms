//1. 最短路徑

//最短路徑問題通常用於圖論中，最常見的算法有 Dijkstra 和 Floyd-Warshall。

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(int source, const vector<vector<pii>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source}); // {距離, 頂點}

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue; // 已經找到更短的距離

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "Distance from " << source << " to " << i << " is " << dist[i] << endl;
    }
}

int main() {
    vector<vector<pii>> graph = {
        {{1, 4}, {2, 1}},
        {{0, 4}, {3, 1}},
        {{0, 1}, {3, 5}},
        {{1, 1}, {2, 5}}
    };
    
    dijkstra(0, graph);
    return 0;
}

//2. 最佳二元搜尋樹

//最佳二元搜尋樹的目的是最小化搜尋一組給定鍵的成本。

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int optimalBST(const vector<int>& keys, const vector<int>& freq) {
    int n = keys.size();
    vector<vector<int>> cost(n, vector<int>(n, 0));

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            cost[i][j] = numeric_limits<int>::max();

            for (int r = i; r <= j; ++r) {
                int c = (r > i ? cost[i][r - 1] : 0) + 
                        (r < j ? cost[r + 1][j] : 0) + 
                        accumulate(freq.begin() + i, freq.begin() + j + 1, 0);
                cost[i][j] = min(cost[i][j], c);
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    vector<int> keys = {10, 20, 30};
    vector<int> freq = {34, 8, 50};
    
    cout << "Cost of Optimal BST is " << optimalBST(keys, freq) << endl;
    return 0;
}

//3. 推銷員旅行問題 (TSP)

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int tsp(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
    dp[1][0] = 0; // Start from the first city

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; ++v) {
                if (mask & (1 << v)) continue;
                dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + graph[u][v]);
            }
        }
    }

    int res = INT_MAX;
    for (int u = 1; u < n; ++u) {
        res = min(res, dp[(1 << n) - 1][u] + graph[u][0]);
    }

    return res;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Cost of TSP is " << tsp(graph) << endl;
    return 0;
}
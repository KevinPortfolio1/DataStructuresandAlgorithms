//貪婪法  最小成本擴張樹 單起點全終點最短路徑  c++

//最小生成樹（使用 Prim 算法）


#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void prim(int start, const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> minCost(n, INF);
    vector<bool> inMST(n, false);
    minCost[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int cost = edge.second;

            if (!inMST[v] && cost < minCost[v]) {
                minCost[v] = cost;
                pq.push({minCost[v], v});
            }
        }
    }

    cout << "最小生成樹的邊權重：\n";
    for (int i = 0; i < n; ++i) {
        if (minCost[i] != INF) {
            cout << "到節點 " << i << " 的最小成本: " << minCost[i] << "\n";
        }
    }
}

int main() {
    int n = 5; // 節點數量
    vector<vector<pair<int, int>>> graph(n);

    // 添加邊 (u, v, cost)
    graph[0].emplace_back(1, 2);
    graph[0].emplace_back(3, 6);
    graph[1].emplace_back(0, 2);
    graph[1].emplace_back(2, 3);
    graph[1].emplace_back(3, 8);
    graph[2].emplace_back(1, 3);
    graph[2].emplace_back(3, 7);
    graph[3].emplace_back(0, 6);
    graph[3].emplace_back(1, 8);
    graph[3].emplace_back(2, 7);
    
    prim(0, graph);
    return 0;
}

//單起點全終點最短路徑（使用 Dijkstra 算法）


#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int start, const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "從節點 " << start << " 到所有節點的最短距離：\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] != INF) {
            cout << "到節點 " << i << " 的最短距離: " << dist[i] << "\n";
        } else {
            cout << "到節點 " << i << " 無法到達\n";
        }
    }
}

int main() {
    int n = 5; // 節點數量
    vector<vector<pair<int, int>>> graph(n);

    // 添加邊 (u, v, cost)
    graph[0].emplace_back(1, 10);
    graph[0].emplace_back(2, 5);
    graph[1].emplace_back(2, 2);
    graph[1].emplace_back(3, 1);
    graph[2].emplace_back(1, 3);
    graph[2].emplace_back(3, 9);
    graph[3].emplace_back(4, 2);
    graph[4].emplace_back(3, 6);

    dijkstra(0, graph);
    return 0;
}
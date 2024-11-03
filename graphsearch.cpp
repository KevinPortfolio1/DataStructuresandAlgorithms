//1. BFS（廣度優先搜尋）
//BFS 是一種逐層遍歷圖形的演算法，通常使用佇列來實現。

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // 建立一個圖（用鄰接表表示）
    vector<vector<int>> graph = {
        {1, 2},    // 0
        {0, 3, 4}, // 1
        {0},       // 2
        {1},       // 3
        {1, 5},    // 4
        {4}        // 5
    };

    cout << "BFS starting from node 0: ";
    bfs(0, graph);

    return 0;
}

//2. DFS（深度優先搜尋）
//DFS 是一種深入探索圖形的演算法，通常使用遞迴或堆疊來實現。


#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
    }
}

int main() {
    // 建立一個圖（用鄰接表表示）
    vector<vector<int>> graph = {
        {1, 2},    // 0
        {0, 3, 4}, // 1
        {0},       // 2
        {1},       // 3
        {1, 5},    // 4
        {4}        // 5
    };

    vector<bool> visited(graph.size(), false);
    cout << "DFS starting from node 0: ";
    dfs(0, visited, graph);

    return 0;
}

//總結

//    BFS：使用隊列，逐層遍歷，適合找最短路徑。
//    DFS：使用遞迴或堆疊，深入探索，適合尋找所有可能路徑。
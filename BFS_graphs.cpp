#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
#include <vector>
#include <queue>
#include<stack>

using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addEgde(int u, int v, bool direction) {
        adj[u].push_back(v);

        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void printEdges(vector<pair<int, int>> edges) {
        for (auto i : edges) {
            cout << i.first << " " << i.second << endl;
        }
    }

    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << "-> ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void BFS(int startNode) {
        unordered_map<int, bool> visited;
        queue<int> q;

        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

 
};

int main() {
    vector<pair<int, int>> edges;
    int n;
    cout << "enter the no of nodes : ";
    cin >> n;

    int m;
    cout << "enter the no of edges : ";
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u, v));

        g.addEgde(u, v, 0);
    }
    // g.printEdges(edges);
    g.printAdjList();

    int startNode;
    cout << "Enter the starting node : ";
    cin >> startNode;

    cout << "BFS traversal starting from node " << startNode << ": ";
    g.BFS(startNode);
    

    return 0;
}

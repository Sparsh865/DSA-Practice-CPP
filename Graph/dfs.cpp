#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>> &adjList, int currentNode, vector<bool> &visited, vector<int> &dfsOrder)
{
    visited[currentNode] = true;
    dfsOrder.push_back(currentNode + 1); // Adjusting to 1-based index for output

    for (int neighbor : adjList[currentNode])
    {
        if (!visited[neighbor])
        {
            dfs(adjList, neighbor, visited, dfsOrder);
        }
    }
}

vector<vector<int>> createGraph(int vertices, int edges)
{
    vector<vector<int>> adjList(vertices);
    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1); // Adjusting for 0-based index
        adjList[v - 1].push_back(u - 1); // For undirected graph
    }
    return adjList;
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adjList = createGraph(vertices, edges);
    vector<bool> visited(vertices, false);
    vector<int> dfsOrder;

    // DFS traversal starting from vertex 1
    cout << "Depth First Traversal starting from vertex 1: ";
    for (int i = 0; i < vertices; ++i)
    {
        if (!visited[i])
        {
            dfs(adjList, i, visited, dfsOrder);
        }
    }

    // Print DFS order
    for (int node : dfsOrder)
    {
        cout << node << " ";
    }

    return 0;
}
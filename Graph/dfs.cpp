#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adjList, int currentNode, vector<bool> &visited, vector<int> &dfsOrder)
{
    visited[currentNode] = true;
    dfsOrder.push_back(currentNode + 1); 

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
        adjList[u - 1].push_back(v - 1); //If vertice start from 1
        // adjList[u].push_back(v); //If vertice start from 0
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

    for (int i = 0; i < vertices; ++i)
    {
        if (!visited[i])
        {
            dfs(adjList, i, visited, dfsOrder);
        }
    }

    for (int node : dfsOrder)
    {
        cout << node << " ";
    }

    return 0;
}

// 0 1
// 0 2
// 0 3
// 1 3
// 2 4
// 3 5
// 3 6
// 4 7
// 4 5
// 5 2
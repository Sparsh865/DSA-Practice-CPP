#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(const vector<vector<int>> &adjList, int startNode, vector<bool> &visited)
{
    queue<int> q;
    vector<int> bfsOrder;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        bfsOrder.push_back(currentNode + 1);

        for (int neighbor : adjList[currentNode])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return bfsOrder;
}

vector<vector<int>> createGraph(int vertices, int edges)
{
    vector<vector<int>> adjList(vertices);
    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1); 
    }
    return adjList;
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adjList = createGraph(vertices, edges);
    vector<bool> visited(vertices, false);

    vector<int> bfsOrder = bfs(adjList, 0, visited); 

    for (int node : bfsOrder)
    {
        cout << node << " ";
    }

    return 0;
}
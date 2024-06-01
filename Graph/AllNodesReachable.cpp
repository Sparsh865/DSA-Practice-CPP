#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph(int vertices, int edges){
    vector<vector<int>> adjList(vertices);
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1);
    }
    return adjList;
}

void dfs(vector<vector<int>> adjList, int startNode, vector<bool> &visited, int &count){
    visited[startNode] = true;
    count++;

    for (int neighbour : adjList[startNode])
    {
        if (!visited[neighbour])
        {
            dfs(adjList, neighbour, visited, count);
        }
    }
}

bool nodes_Are_Reachable(vector<vector<int>> adjList, int startNode, int vertices){
    vector<bool> visited(vertices, false);
    int count = 0;
    dfs(adjList, startNode, visited, count);

    if (count == vertices)
        return true;
    return false;
}

int main(){
    int vertices, edges, startNode;
    cin >> vertices >> edges;
    vector<vector<int>> adjList = createGraph(vertices, edges);
    cin >> startNode;
    startNode -= 1;

    if (nodes_Are_Reachable(adjList, startNode, vertices))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

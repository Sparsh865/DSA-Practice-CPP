#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adjList, int startNode, vector<bool> &visited,vector<int>& bfsOrder){
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()){
        int currentNode = q.front();
        q.pop();
        bfsOrder.push_back(currentNode + 1); //If vertice start from 1
        // bfsOrder.push_back(currentNode); // If vertice start from 0

        for (int neighbor : adjList[currentNode]){
            if (!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

vector<vector<int>> createGraph(int vertices, int edges){
    vector<vector<int>> adjList(vertices);
    for (int i = 0; i < edges; ++i){
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1); // If vertice start from 1
        // adjList[u].push_back(v); //If vertice start from 0    
    }
        return adjList;
    
}


int main(){
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adjList = createGraph(vertices, edges);
    vector<bool> visited(vertices, false);
    vector<int> bfsOrder;
    // int startNode;
    // cin>>startNode;
    // startNode=startNode-1;
    // bfs(adjList, startNode, visited,bfsOrder); //Instead of zero you can include any starting node
    bfs(adjList, 0, visited, bfsOrder);

    for (int node : bfsOrder){
        cout << node << " ";
    }

    return 0;
}
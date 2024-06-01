#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph(int vertices,int edges){
    vector<vector<int>> adjList(vertices);
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adjList[u-1].push_back(v-1); //If not 0 vertice
        // adjList[u].push_back(v); //If 0 vertice
    }
    return adjList;
}

void bfs(vector<vector<int>>& adjList,int startNode,vector<bool>& visited,vector<int>& bfsOrder){
    queue<int>q;

    visited[startNode]=true;
    q.push(startNode);

    while(!q.empty()){
        int currentNode = q.front();
        bfsOrder.push_back(currentNode + 1); //If vertices start from 1
        // bfsOrder.push_back(currentNode); //If vertices start from 0
        q.pop();
        for(int neighbour: adjList[currentNode]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}


void dfs(vector<vector<int>>& adjList,int startNode,vector<bool>& visited,vector<int>& dfsOrder){
    visited[startNode] = true;
    dfsOrder.push_back(startNode+1);//If vertices start from 1
    // dfsOrder.push_back(startNode);//If vertices start from 0
    for(int neighbour : adjList[startNode]){
        if(!visited[neighbour]){
            dfs(adjList,neighbour,visited,dfsOrder);
        }
    }
}
int main(){
    int vertices,edges;
    cin>>vertices>>edges;

    vector<vector<int>> adjList = createGraph(vertices,edges);
    vector<bool> visited1(vertices,false);
    vector<bool> visited2(vertices,false);
    vector<int> bfsOrder;
    vector<int> dfsOrder;
    
    //If we have diff startNode
    int startNode;
    cin>>startNode;
    startNode -= 1; // Adjust for 1-based indexing ( If 0 not there)

    // bfs(adjList,0,visited1,bfsOrder);
    bfs(adjList,startNode,visited1,bfsOrder); //if startNode is custom

    if(!visited2[startNode]){
        dfs(adjList,startNode,visited2,dfsOrder); //If customer startNode place this before the below code
    }

    for(int i=0;i<vertices;i++){
        if(!visited2[i]){
            dfs(adjList,i,visited2,dfsOrder);
        }
    }

    cout<<"BFS: ";
    for(int node: bfsOrder){
        cout<<node<<" ";
    }
    cout<<endl;

    cout<<"DFS: ";
    for(int node: dfsOrder){
        cout<<node<<" ";
    }
    cout<<endl;

    return 0;

}
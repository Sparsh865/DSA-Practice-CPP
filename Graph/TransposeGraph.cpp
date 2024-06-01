#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph(int vertices,int edges){
    vector<vector<int>> adjList(vertices);
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adjList[u-1].push_back(v-1);
    }
    return adjList;
}

vector<vector<int>> transposeGraph(vector<vector<int>> adjList){
    int V = adjList.size();
    vector<vector<int>> transpose(V);

    for(int u=0;u<V;u++){
        for(int v:adjList[u]){
            transpose[v].push_back(u);
        }
    }
    return transpose;
}
void printGraph(vector<vector<int>> &adjList){
    int V = adjList.size();
    for (int i = 0; i < V; ++i)
    {
        cout << "Vertex " << i + 1 << ": ";
        for (int j = 0; j < adjList[i].size(); ++j)
        {
            cout << adjList[i][j] + 1 << " ";
        }
        cout << endl;
    }
}
void displayGraph(vector<vector<int>>adjList){
    int v=adjList.size();
    for (int i = 0; i < v; i++)
    {
        cout << i << "--> ";
        for (int j = 0; j < adjList[i].size(); j++)
            cout << adjList[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    int vertices,edges;
    cin>>vertices>>edges;

    vector<vector<int>>adjList = createGraph(vertices,edges);
    vector<vector<int>>transpose_adjList = transposeGraph(adjList);

    displayGraph(adjList);
    cout<<endl;
    displayGraph(transpose_adjList);
    return 0;
}
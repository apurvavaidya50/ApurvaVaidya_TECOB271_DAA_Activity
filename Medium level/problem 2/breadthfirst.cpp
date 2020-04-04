#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10000]; //adj[a].push_back(b); for add an edge from a to b
int visited[10000]={0}; //O if not visited, 1 if visited
int level[10000];

void addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
 adj[w].push_back(v);
}

void bfs(int s, int n)
{
    for(int i=0; i<10000;i++){
        visited[i] = 0;
    level[i]=0;
    }
    queue<int>Q;
    Q.push(s);
    visited[s] = 1;
    level[s] = 0;

    while(!Q.empty())
    {
        int u = Q.front();

        for(int i=0; i<adj[u].size(); i++){
            if(visited[adj[u][i]]==0){
                int v = adj[u][i];
                level[v] = level[u]+6;
                visited[v] = 1;
                Q.push(v);
            }
        }
        Q.pop();
    }

  for(int i=1;i<=n;i++)
    {
        if(i!=s)
        {
            if(level[i]==0)
            cout<<"-1 ";
            else
            cout<<level[i]<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    int q;
   cin>>q;
  while(q-->0){

    int n,m;
   cin>>n>>m;
    for(int i=0;i<n+3;i++)
         adj[i].clear();
   for(int i=0;i<m;i++){
        int u,v;
   cin>>u>>v;
   addEdge(u,v);
   }
   int s;
   cin>>s;
bfs(s,n);
}
}
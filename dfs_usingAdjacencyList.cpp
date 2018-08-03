    // Adjacency list to store graph

    #include<bits/stdc++.h>
    #define MAX 10000

    using namespace std;

    vector<int> adjlist[MAX];
    int visited[MAX];

    void dfs(int u) {
        visited[u]=1;
          // Recurse over all children of u
        for(int i=0;i<adjlist[u].size();i++)
        {
        int t=adjlist[u][i];
        if(!dfs[t])
        {
            dfs(t);
        }
  }
        /*
        for(const int& v : adjlist[u]) {
            // If v has not been visited yet, recurse
            if(!visited[v]) dfs(v);
        }
        */
    }
    // Array to mark vertices visited by DFS

    int main()
    {
        memset(visited, 0, sizeof visited);

    // Read Graph
    // First read number of vertices (N) and edges (M)
    // Then read the directed edges
    // Note that vertices are zero-indexed
    int N,M;
    scanf("%d%d",&N,&M);

    for(int i=0;i<M;i++) {
      int a,b;
      scanf("%d%d",&a,&b);
      adjlist[a].push_back(b);
    }

    // DFS function
    for(int i=1;i<=N;i++)
    {
        if(dfs[i]==0){
            dfs(i);
        }
    }


    // Call dfs(0) and we will have the reachability to all other vertices


    }


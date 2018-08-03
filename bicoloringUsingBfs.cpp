#include<bits/stdc++.h>
#define MAX 1000
#define node 200
 using namespace std;

 vector <int> edges[MAX];
 int vis[node];

 bool bfs(int x)
 {
     memset(vis,0,sizeof(vis));
     queue <int> mQ;
     vis[x]=1;
     mQ.push(x);
     while(!mQ.empty())
     {
         int u=mQ.front();
         mQ.pop();
         int size=edges[u].size();
         for(int i=0; i< size; i++)
         {
             int v=edges[u][i];
             if(vis[v]==0)
             {
                 if(vis[u]==1)
                    vis[v]=2;
                 else
                    vis[v]=1;
                 mQ.push(v);
             }
             if(vis[u]==vis[v])
                return false;
         }
     }
     return true;

 }

 int main()
 {
     while(1)
     {
         int n,e;
         cin >> n;
         if(n==0) break;
         cin >> e;
         while(e--)
         {
             int x,y;
             cin >> x >> y;
             edges[x].push_back(y);
             edges[y].push_back(x);
         }
         if(bfs(0)==true)
            cout << "BICOLORABLE." << endl;
         else
            cout << "NOT BICOLORABLE." << endl;
         for(int i=0; i<n; i++)
            edges[i].clear();

     }
     return 0;
 }


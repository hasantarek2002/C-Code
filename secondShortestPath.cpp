#include<bits/stdc++.h>
#define MAX 100000
#define inf 500000000000

using namespace std;

vector < pair <int,int> > adj[MAX];
priority_queue < pair <int,int> ,vector < pair < int,int> > , greater < pair <int,int> > > Q;
stack <int> myStack;
bool vis[MAX];
int pre[MAX];
long long dis[MAX];
//int node,edge;

int main()
{
    int t;
    cin >> t;
    for(int k=0; k<t; k++)
    {
        vector<int>myVec;
        int node,edge,u,v,w,d=0;
        cin >> node >> edge;
        while(edge--)
        {
            int x,y,w;
            cin >> x >> y >> w;
            x--,y--;
            adj[x].push_back(make_pair(w,y));
            adj[y].push_back(make_pair(w,x));
        }
        for(int i=1; i< node; i++)
            dis[i]=inf;
        Q.push(make_pair(0,0));

        while(!Q.empty())
        {
            u=Q.top().second;
            Q.pop();
            int size=adj[u].size();
            for(int i=0; i<size; i++)
            {
                w=adj[u][i].first;
                v=adj[u][i].second;
                if(!vis[v] && dis[u] + w < dis[v])
                {
                    dis[v]=dis[u]+w;

                   // d=dis[u];
                    Q.push(make_pair(dis[v],v));
                    pre[v]=u;
                }
                vis[v]=true;
            }

        }
        node--;
        /*
        while(node)
        {
            myStack.push(dis[node]);
            node=pre[node];
        }
        */
        for(int i=node; i>=0;i--)
        {
            myStack.push(dis[node]);
            node=pre[node];
        }
        while(!myStack.empty())
        {
            myVec.push_back(myStack.top());
            myStack.pop();
        }
        //int l=pre[v];
        sort(myVec.begin(),myVec.end());
        cout << myVec[1] << endl;
        //for(int i=0; i<myVec.size(); i++)


       // cout << d << endl;

       // cout << "Case "<< i+1 <<": " << << endl;

        for(int i=0; i<node; i++)
            adj[i].clear();
        myVec.clear();
    }

    return 0;
}

#include<bits/stdc++.h>
#define N 1000

using namespace std;

vector<int>edges[N];
int dis[N]={0};
int vis[N]={0};
int prev[N];
void recurse(int cur, int x)
{
    if(cur==x) return;
    recurse(prev[cur],x);
    cout << prev[cur] << "  ";
}

int bfs(int start,int endd)
{
    memset(prev,-1,sizeof(prev));
    queue <int> mQ;
    bool temp=false;
    vis[start]=1;
    mQ.push(start);
    while(!mQ.empty())
    {
        int node=mQ.front();
        mQ.pop();
        int size=edges[node].size();
        for(int i=0; i< size; i++)
        {
            int cur=edges[node][i];
            if(vis[cur]==0)
            {
                vis[cur]=1;
                dis[cur] = dis[node]+1;
                prev[cur]=node;
                mQ.push(cur);
                if(cur==endd)
                {
                    temp=true;
                    recurse(cur,start);
                    cout << endd << endl;
                    return dis[cur];
                }


            }
        }
    }
    if(temp==false)
        return -1;

}

int main()
{
    int node,edge,start,endd;
    cout << " Enter node and end edge number : ";
    cin>> node >> edge;
    /*
    for(int i=0; i<node; i++)
    {
        //distance[i]=0;
        prev[i]=-1;
        //vis[i]=0;

    }
    */
    while(edge--)
    {
        int x,y;
        cin >> x >> y;
        edges[x].push_back(y);
        //edges[y].push_back(x);
    }
    cout << " Enter start and end vertex : ";
    cin >> start>>endd;
    int path= bfs(start,endd);
    if(path==-1)
        cout << " Shortest path does not exist." << endl;
    else cout << "Shortest path is : "<<path << endl;





    return 0;
}


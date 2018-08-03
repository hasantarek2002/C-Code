#include<bits/stdc++.h>
#define MAX 200005
#define inf 500000000000

using namespace std;

vector < pair <int,int> > edges[MAX];
priority_queue < pair <int,int> ,vector < pair < int,int> > , greater < pair <int,int> > > Q;
stack <int> myStack;
bool vis[MAX];
int pre[MAX];
long long dis[MAX];
int node,m,x,y,w;

int main(){
    scanf("%d%d",&node,&m);
    while(m--){
        scanf("%d%d%d",&x,&y,&w);
        x--,y--;
        edges[x].push_back(make_pair(w,y));
        edges[y].push_back(make_pair(w,x));
    }
    for(int i=1; i<node; i++)
        dis[i]=inf;
    Q.push(make_pair(0,0));
    while(!Q.empty()){
        x=Q.top().second;
        Q.pop();
        m=edges[x].size();
        for(int i=0;i<m; i++){
            w=edges[x][i].first;
            y=edges[x][i].second;
            if(vis[y]==false && dis[x] +w < dis[y]){
                dis[y]=dis[x]+w;
                Q.push(make_pair(dis[y],y));
                pre[y]=x;
            }
            vis[x]=true;
        }
    }
    node--;
    if(dis[node]==inf)
        printf("-1\n");
    else{
        while(node){
            myStack.push(node+1);
            node=pre[node];
        }
        printf("1");
        while(!myStack.empty()){
            printf(" %d",myStack.top());
            myStack.pop();
        }
        printf("\n");
    }
    return 0;
}

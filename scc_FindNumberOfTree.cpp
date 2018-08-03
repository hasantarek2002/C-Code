
#include<bits/stdc++.h>
using namespace std;
int dfs[10000];
vector<int>edge[1000];
void dfsVisit(int p){

 dfs[p]=1;
 for(int i=0;i<edge[p].size();i++)
  {
     int t=edge[p][i];
     if(!dfs[t])
     {
       dfsVisit(t);
     }
  }
}

int main(void)
{
     cout<<"enter num of node and edges"<<endl;
     int n,m;
     cin>>n>>m;
     for(int i=0;i<m;i++)
     {
       int x,y;
       cin>>x>>y;
       edge[x].push_back(y);
        edge[y].push_back(x);
     }
     int cnt=0;
     for(int i=1;i<=n;i++)
      {
        if(dfs[i]==0){
        dfsVisit(i);
        cnt++;
       }
      }
      cout<<cnt<<endl;


}

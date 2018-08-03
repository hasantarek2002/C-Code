#include<bits/stdc++.h>

using namespace std;
vector <int>edges[100000];
int color[100000];

int main()
{

    while(1)
    {
        int n,m;
        cin >> n;
        if(n==0)
            break;
        cin>>m;
        for(int i=0; i<m; i++){
            int x,y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        memset(color,0,sizeof(color));
        queue<int>mQ;
        color[0]=1;
        mQ.push(0);
        int f=0;
        while(!mQ.empty()){
            int u=mQ.front();
            mQ.pop();
            for(int i=0; i<edges[u].size();i++){
                int v=edges[u][i];
                if(color[v]==0){
                    if(color[u]==1){
                        color[v]=2;
                    }
                    else{
                        color[v]=1;
                    }
                    mQ.push(v);
                }
                if(color[u]==color[v]){
                    f=1;
                    break;
                }
            }
            if(f==1)
                break;
        }
        if(f==1){
            cout << "NOT BICOLORABLE."<<endl;
        }
        else{
            cout << "BICOLORABLE."<<endl;
        }

        for(int i=0; i<=m;i++){
            edges[i].clear();
        }
    }


    return 0;
}

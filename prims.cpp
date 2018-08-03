#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;      
typedef vector<ii> vii;      
typedef vector<int> vi;

vector < vii > adjList;
int V, E;

vi vis;
vi sorted;

void IO()
{
    freopen("in.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
}

vi taken;                                
priority_queue< ii, vector<ii>, greater<ii> > pq;           

void process(int u) {  
  
  taken[u] = 1;
  int loop = adjList[u].size();
  
  for (int j = 0; j < loop; j++) {
    //ii v = AdjList[vtx][j];
    int w = adjList[u][j].first;
    int v = adjList[u][j].second;
    
    if (!taken[v]) 
        pq.push(ii(w,v));
} }                   





int main()
{
	IO();

	int t;
	cin >> t;
	for(int k=0; k<t; k++){
		int p;
		cin >>p;
		scanf("%d%d",&V, &E);

		adjList.assign(V,vii());

		for(int i=0; i<E; i++)
		{
		    int a,b,w;
		    scanf("%d%d%d",&a,&b,&w);

		    adjList[a].push_back(ii(w,b));
		    adjList[b].push_back(ii(w,a));

		}

		int cost = 0;

		taken.assign(V, 0);
		process(0);

		while (!pq.empty()) 
		{  
		    ii front = pq.top(); 
		    pq.pop();
		    int u = front.second;
		    int w = front.first;  
		    if (!taken[u]) 
		        cost += w;
		    process(u); 
		}                          
		printf("MST cost = %d (Prim's)\n", cost);
	
	}
	

    return 0;
}

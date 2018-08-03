#include<bits/stdc++.h>

using namespace std;
void func(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}


int block;
int cnt[1000005];



struct Query
{
    int L, R,index,value;
};
bool compare(Query x, Query y)
{
    if (x.L/block != y.L/block)
        return x.L/block < y.L/block;
    return x.R < y.R;
}

int main()
{
    func();
    int n,m;

    scanf("%d%d",&n,&m);
    Query q[m];
    int res[m];
    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }


    for(int i=0; i<m; i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        q[i].index=i;
        q[i].L=l-1;
        q[i].R=r-1;
    }
    block = (int)sqrt(n);
    sort(q, q + m, compare);
    for(int i=0; i<m; i++)
        cout <<q[i].L<<"   "<<q[i].R<<endl;
    int prevL = 0, prevR = 0;
    int currSum = 0;
    memset(cnt,0,sizeof(cnt));
    for (int i=0; i<m; i++)
    {
        int distinct=0;
        int currL = q[i].L, currR = q[i].R;     //3 1 2 2 3 3 7
        while (prevL < currL)
        {
            cnt[a[prevL]]--;
            if(cnt[a[prevL]]==0)  distinct--;
            prevL++;
        }
        while (prevL > currL)
        {
            cnt[a[prevL-1]]++;
            if(cnt[a[prevL-1]]==1)  distinct++;
            prevL--;
        }
        while (prevR <= currR)
        {
            cnt[a[prevR]]++;
            if(cnt[a[prevR]]==a[prevR])  distinct++;//
            prevR++;
        }
        while (prevR > currR+1)
        {
            cnt[a[prevR-1]]--;
            if(cnt[a[prevR-1]]==0)  distinct--;
            prevR--;
        }
        q[i].value=distinct;

    }

    for(int i=0; i<m; i++)
    {
        //cout<<q[i].index<<" >> "<< q[i].value<<endl;
        res[q[i].index]=q[i].value;
    }
    for(int i=0; i<m; i++)
    {
        printf("%d\n", res[i]);

    }


    return 0;
}

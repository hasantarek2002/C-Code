#include<bits/stdc++.h>

using namespace std;

int main ()
{
    int W=5,w=0,maxprofit=0;
    pair<int,int>p[5];
    pair<int,int>p1[5];

    /*
    for(int i=0; i<5; i++){
        int x,y;
        cin >>x>>y;
        p[i]=make_pair(x,y);
    }
    */
    p[0]=make_pair(12,4);
    p[1]=make_pair(32,8);
    p[2]=make_pair(40,2);
    p[3]=make_pair(30,6);
    p[4]=make_pair(50,1);

    for(int i=0; i<5; i++){
        p[i].first=p[i].first/p[i].second;       // first=benifit   second=weight
        //cout << p[i].first << "   " << p[i].second << endl;
    }
    sort(p,p+5);

    for(int i=5-1,j=0;i>=0;i--,j++){
        p1[j]=p[i];
    }
    int i=0;
    while(w<W)
    {
        int value=p1[i].first;
        int x=min(p1[i].second,W-w);
        w=w+x;
        maxprofit=maxprofit+(value*x);
        i++;
    }
    cout << maxprofit << endl;





    return 0;
}

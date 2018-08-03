#include<bits/stdc++.h>

using namespace std;

int main ()
{
    pair<int,int>p[5];
    pair<int,int>p1[5];

    p[0]=make_pair(3,4);
    p[1]=make_pair(4,8);
    p[2]=make_pair(20,2);
    p[3]=make_pair(5,6);
    p[4]=make_pair(50,1);

  /*
    for(int i=0; i<5; i++){
        int x,y;
        cin >>x>>y;
        p[i]=make_pair(x,y);
    }
    */

     cout << "before sort" << endl;
    for(int i=0; i<5; i++){
        //p[i].first=p[i].first/p[i].second;       // first=benifit   second=weight
        cout << p[i].first << "   " << p[i].second << endl;
    }
 /*
    cout << "after sort" << endl;
    sort(p,p+5);

    for(int i=0; i<5; i++){
        cout << p[i].first << "   " << p[i].second << endl;
    }

    for(int i=5-1,j=0;i>=0;i--,j++){
        //p[j].first=p[i].first;
        //p[j].second=p[i].second;
        p1[j]=p[i];
    }

    cout << "reversing  sort 'descending' : " << endl;
    for(int i=0; i<5; i++){
        cout << p1[i].first << "   " << p1[i].second << endl;
    }
    */
    //cout << p[0].first << "   " << p[0].second << endl;


    return 0;
}

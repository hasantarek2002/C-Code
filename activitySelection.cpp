#include<bits/stdc++.h>

using namespace std;

int main ()
{
    pair<int,int>p[5];
    vector<int>myVec;

     /*
    for(int i=0; i<5; i++){
        int x,y;
        cin >>x>>y;
        p[i]=make_pair(x,y);
    }
    */

    p[0]=make_pair(4,1);    /////////first=finishing time
    p[1]=make_pair(5,3);    /////////second=starting time
    p[2]=make_pair(6,0);
    p[3]=make_pair(7,5);
    p[4]=make_pair(8,3);

    sort(p,p+5);
    myVec.push_back(p[0].first);
    int j=0;
    for(int i=1; i<5; i++)
    {
        if(p[i].second >= p[j].first)
        {
            myVec.push_back(p[i].first);
            j=i;
        }
    }
    cout << "Activity : "<< myVec.size()<< endl;
    for(int i=0; i<myVec.size(); i++)
    {
        cout << "finishing time of "<<i+1 << "  is  "<< myVec[i]<<endl;
    }


    return 0;
}

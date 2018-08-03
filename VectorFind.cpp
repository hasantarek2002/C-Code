#include<bits/stdc++.h>

using namespace std;
void func(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int main()
{
    //func();
    int n,m;
    vector<int>v;

    for(int i=0; i<5; i++)
    {
        v.push_back(i);
    }
    auto it=find(v.begin(),v.end(),4);
    if(it!=v.end()){
        cout << "found"<<endl;
        v.erase(it);
    }
    else  cout << " not found"<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i]<<endl;
    }
}


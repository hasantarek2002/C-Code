#include<bits/stdc++.h>

using namespace std;
void func(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}


int main(){
    func();
    long long a,b,x,y,z,s1,s2;
    cin>>a>>b>>x>>y>>z;
    s1=a+b;
    s2=(x+y)*2+z*3;
    if(s2-s1 <0) cout <<0<<endl;
        cout<<s2-s1<<endl;

}

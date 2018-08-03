
#include<bits/stdc++.h>

using namespace std;
void func(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
struct c{
    string s;
    int a;
     bool operator < (c k) const{
        return a< k.a;
    }
};
int main()
{
    //func();
    int n;
    string s;
    vector<string>v;
    map<c,bool>mp;
    c k;
    k.s="ds";
    k.a=0;
    mp.insert( pair<c,bool>(k,true));
    k.s="as";
    k.a=1;
    mp.insert( pair<c,bool>(k,true));
    k.s="es";
    k.a=2;
    mp.insert( pair<c,bool>(k,true));
    k.s="fs";
    k.a=3;
    mp.insert( pair<c,bool>(k,true));
    //cin >>n;

    /*
    map<string,bool,less<string>>mp;
    unordered_map<string,bool>mp;
    mp.insert( pair<string,bool>("ds",true));
    mp.insert( pair<string,bool>("as",true));
    mp.insert( pair<string,bool>("es",true));
    mp.insert( pair<string,bool>("fs",true));
    mp.insert( pair<string,bool>("zs",true));
    */
    for (auto it=mp.begin(); it!=mp.end(); ++it){
        c temp=it->first;
        cout << temp.s<<endl;
    }
    //std::cout << it->first.<< '\n';
    //mymap.insert ( std::pair<char,int>('a',100) );

}


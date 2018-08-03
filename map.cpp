
#include<bits/stdc++.h>

using namespace std;
void func(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

int main()
{
    //func();
    int n;
    string s;
    vector<string>v;
    //cin >>n;
    //map<string,bool,greater<string>>mp;
    //map<string,bool,less<string>>mp;
    map<string,bool>mp;
    mp.insert( pair<string,bool>("ds",true));
    mp.insert( pair<string,bool>("as",true));
    mp.insert( pair<string,bool>("es",true));
    for (auto it=mp.begin(); it!=mp.end(); ++it)
    std::cout << it->first<< '\n';
    //mymap.insert ( std::pair<char,int>('a',100) );

}
/*


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
    func();
    int n;
    string s;
    map<string,c>mp;
    cin >>n;
    for (int i=0; i<n;i++)
    {
        c k;
        cin >> s;
        k.s=s;
        k.a=i;
        auto it = mp.find(s);
        if (it != mp.end())
        {
            mp.erase (it);
        }
        mp.insert( pair<string,c>(s,k));
    }
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        c temp;
        temp=it->second;
        cout << temp.s<<endl;
    }


/*
    mp.insert( pair<string,bool>("ds",true));
    mp.insert( pair<string,bool>("as",true));
    mp.insert( pair<string,bool>("es",true));
    mp.insert( pair<string,bool>("fs",true));
    mp.insert( pair<string,bool>("zs",true));
    for (auto it=mp.begin(); it!=mp.end(); ++it){
        c temp=it->first;
        cout << temp.s<<endl;
    }*/

}
*/

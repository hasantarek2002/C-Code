
#include<bits/stdc++.h>

using namespace std;
void func(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}
int main()
{
    //func();
    int n;
    vector<string> v;
    set<string> ms;
    if(ms.find("s")!=ms.end()){
        //ms.insert("as");
        cout << "paisi"<<endl;
    }
    else cout << "pai nai"<<endl;
    ms.insert("ds");
    ms.insert("as");
    ms.insert("es");
    ms.insert("gs");

    for(auto it=ms.begin();it!=ms.end();it++)
    {
        cout <<*it<<endl;
    }


}


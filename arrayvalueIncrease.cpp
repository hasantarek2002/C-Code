
#include<bits/stdc++.h>

using namespace std;
void func(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}
int main()
{
    int a[]={2,1,3,1,5,5,5};
    int arr[7];
    memset(arr,0,sizeof(arr));
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {
            if(a[i]==a[j] && i!=j){
                a[arr[i]++];
                //arr[a[i]++];
            }
        }
    }
    for(int i=0; i<7; i++)
    {
        cout << arr[i]<<endl;

    }


}



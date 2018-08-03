#include <iostream>
#include <vector>

using namespace std;
int main ()
{
    int arr[5]={1,5,10,25,100};
    int s=102,count=0,c,c1=0;

    while(s>0)
    {
        c=arr[0];
        for(int i=0; i<5-1; i++){

            if(c<arr[i+1] && arr[i+1]<=s){
                c=arr[i+1];
            }
        }
        int num=s/c;
        count+=num;
        s = s-(num*c);

    }
    cout << count<<endl;



  return 0;
}

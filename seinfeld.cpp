#include<iostream>

using namespace std;

int main()
{   int k=1;
    while(k)
    {
        string s;
        cin >> s;
        if(s[0]=='-') break;
        int len=s.length();
        int right=0,left=0,count=0;
        for(int i=0; i<len; i++)
        {
            if(s[i]=='{')
                left++;
            else
            {
                if(s[i]=='}' && left==0)
                {
                    left++;
                    right++;
                }
                else
                    left--;
            }
        }
        int ans=right+left/2;

        cout << k << ". " << ans << endl;
        k++;

    }




    return 0;
}

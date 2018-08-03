#include<iostream>

using namespace std;

void failureFunctionConstruction(int *failureFunction,string pattern)
{

    failureFunction[0]=0;
    int k=0;
    for(int q=1; q<pattern.length(); q++)
    {
        while((k>0) && (pattern[k]!=pattern[q]))
            k=failureFunction[k];
        if(pattern[k]==pattern[q])
            k++;
        failureFunction[q]=k;
    }

    /*
    for(int i=0; i<pattern.length();i++)
    {
        cout << failureFunction[i] << "  " ;

    }
    cout << endl;
    */
}

    void kmpMatch(int *failureFunction,string text, string pattern)
    {
        int q=0;
        for(int i=0; i<text.length(); i++)
        {
            while((q>0) && (pattern[q]!=text[i]))
                q=failureFunction[q];
            if(pattern[q]==text[i])
                q++;
            if(q==pattern.length())
            {
                cout << "match at shift " << i-pattern.length()+1 << endl;
                q--;
                q=failureFunction[q];
            }
        }
    }

    void kmp(string text,string pattern)
    {
        int *failureFunction;
        failureFunction=new int [pattern.length()];
        failureFunctionConstruction(failureFunction,pattern);
        kmpMatch(failureFunction,text,pattern);
    }



int main()

{
    string pattern,text;
    getline(cin,text);
    getline(cin,pattern);
    kmp(text,pattern);
    //failureFunctionConstruction(pattern);

    return 0;
}

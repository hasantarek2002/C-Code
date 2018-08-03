#include<iostream>
#include<vector>

using namespace std;

int main ()
{
    vector <int> myVec;

    //pushback

    for(int i=0; i<10; i++)
    {
        myVec.push_back(i);
    }

    for(int i=0; i<5; i++)
    {
        myVec[i] = i+1;
    }


    for(int i=0; i<myVec.size(); i++)
        cout << myVec[i] << "     ";
    cout << endl;

    //myVec.clear();

    if(!myVec.empty())
        cout << "Vector size is " << myVec.size() << endl;
    else
        cout << "Vector size is " << myVec.size() << endl;

    return 0;
}

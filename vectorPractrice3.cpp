#include<iostream>
#include<vector>

using namespace std;

int main ()
{
    vector <int> myVec;
    vector <int> :: iterator it;

    //pushback

    for(int i=0; i<10; i++)
    {
        myVec.push_back(i);
    }

    //-----------
    //insertion

    //it =myVec.begin();
    //myVec.insert(it,22);
    //myVec.insert(it+1,3,222);
    //myVec.insert(it+2,222);

    //myVec.insert(myVec.end(),22);
    //myVec.insert(myVec.end()-2,22);
    //myVec.insert(myVec.end()-2,3,22);
    //---------------



    //-----------
    //delete

    //it =myVec.begin();
    //myVec.erase(it);
    //myVec.erase(it+1);
    //myVec.erase(myVec.end()-1);
    //myVec.erase(myVec.begin(),myVec.end());
    //myVec.erase(myVec.begin(),myVec.end()-1);
    //myVec.erase(myVec.begin()+1,myVec.end());
    //myVec.erase(myVec.begin()+2,myVec.end()-2);

    //--------------


    /*
    for(int i=0; i<myVec.size(); i++)
        cout << myVec[i] << "     ";

    */
    /*
    for(it=myVec.begin(); it!=myVec.end(); it++)
        cout << *it << "    ";
    cout << endl;
    */


    for(it=myVec.end()-1; it!=myVec.begin()-1; it--)
        cout << *it << "    ";
    cout << endl;

    //myVec.clear();

    if(!myVec.empty())
        cout << "Vector size is " << myVec.size() << endl;
    else
        cout << "Vector size is " << myVec.size() << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> myVec;
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int m;
        cin >> m;
        myVec.push_back(m);
    }

    for(int i=0; i<myVec.size(); i++)
        cout << myVec[i] << "     ";
    cout << endl;

    cout << "Vector size is " << myVec.size() << endl;
    int temp=myVec.size()/2;

    for(int i=0; i<temp-1; i++)
        myVec.pop_back();

    for(int i=0; i<myVec.size(); i++)
        cout << myVec[i] << "     ";


    cout << endl;
    cout << "Vector size is " << myVec.size() << endl;
	return 0;
}

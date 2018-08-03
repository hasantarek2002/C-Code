#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
vector <int> :: iterator iIt;
.begin();
.end();

.. constructor
= operator
.size();
[]
push_back();
pop_back();
.empty();
.insert()
.erase()
//
front
back
*/

int main (void)
{
	vector <int> myVec;

	/*
	while (1)
	{
		int input;
		cin >> input;
		if(input ==0) break;
		else myVec.push_back(input);
	}
	*/

	for(int i=0;i<10;i++)
		myVec.push_back(5*i);

	/*
	int temp = myVec.size()/2;

	for(int i=0; i<myVec.size()/2; i++)
		myVec.pop_back();


	for(int i=0; i<myVec.size(); i++)
		myVec[i] =1+i;
    */


	vector <int> :: iterator iIt;
	//myVec.erase(myVec.begin()+3, myVec.end()-2);
	//iIt = myVec.end();

	//myVec.erase( iIt-1);

    //iIt = myVec.begin();
	//iIt = myVec.end();//myVec.begin();
	//myVec.insert(iIt-3,3,420);
	//myVec.insert(iIt+1,420);

	/*
	*/
	iIt = find(myVec.begin(),myVec.end(),5);
	//cout << *iIt << endl;
    myVec.insert(iIt,19);

	for(int i=0; i<myVec.size(); i++)
		cout << myVec[i] << "\t";
	cout << endl;

	//myVec.clear();


	if(!myVec.empty())cout << "size is " << myVec.size() << endl;
	else cout << "size is " << myVec.size() << endl;
	return 0;
}








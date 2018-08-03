
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main (void)
{

	ifstream iFile;
	iFile.open("input.txt");
	if(iFile.is_open())
	{
		int numberOfLetter;
		iFile >> numberOfLetter;

		for(int i=0; i<numberOfLetter; i++)
		{
			string s;
			int num;
			iFile >> s;
			iFile >> num;
			cout << s << "  " << num << endl;
		}
		iFile.close();
	}
	else
	{
		cout << "Could not open file" << endl;
	}

    /*
	ofstream oFile;
	oFile.open("o11.txt", ofstream::out);
	if(oFile.is_open())
	{
		string name[3] = {"Tahlil Zibran", "Mahir Mahbub", "Shamima Akter"};
		int age[3] = {7, 154, 19};
		double salary[3] = {12.345678, 1111.445, 2.11};

		oFile << "Name" << "\t\t\t" << "Age" << "\t\t" << "Salary" << endl;

		for(int i=0; i<3; i++)
		{
			oFile 	<< name[i] << "\t\t" << setw(3) << setfill(' ') << age[i] << "\t\t"
					<< setw(9) << setfill('x') << setprecision(8) << salary[i] << endl;
		}
		oFile.close();
	}
	else
	{
		cout << "Could not open file" << endl;
	}
    */

	return 0;
}



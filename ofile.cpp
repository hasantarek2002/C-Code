#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

int main(){

    ofstream ofile;
    ofile.open("ooo.txt",ofstream::out);
    if(ofile.is_open()){
        string name[3]= {"mehedi","millad","shamim"};
        int age[3]= {23,435,33};
        double salary[3]={1234.876736,2345.6,34.45};
        ofile << "name" << "\t\t" << "age" << "\t\t" << "salary" << endl;

        for(int i=0; i<3; i++){
            ofile<< name[i] << "\t\t" << setw(3) << setfill(' ') << age[i] << "\t\t"
            << setw(8) << setfill('x') << setprecision(8) << salary[i] << endl;

        }
        ofile.close();

    }
    else
        cout << "Could not open file" << endl;

    return 0;

}


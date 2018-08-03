#include<iostream>
#include<iomanip>

using namespace std;

int main(){

    string name[3]= {"mehedi","millad","shamim"};
    int age[3]= {23,435,33};
    double salary[3]={1234.876736,2345.6,34.45};
    cout << "name" << "\t\t" << "age" << "\t\t" << "salary" << endl;

    for(int i=0; i<3; i++){
        cout<< name[i] << "\t\t" << setw(3) << setfill(' ') << age[i] << "\t\t"
        << setw(8) << setfill('x') << setprecision(8) << salary[i] << endl;

    }





    return 0;

}

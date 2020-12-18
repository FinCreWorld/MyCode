#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream infile;
    infile.open("afile.dat");
    cout<<infile.showpos<<endl;
    char data[100];
    infile>>data;
    cout<<data<<endl;
    cout<<infile.showpos<<endl;
    infile.seekg(1, ios::end);
    cout<<infile.showpos<<endl;
    infile>>data;
    cout<<data<<endl;
    system("pause");
    return 0;
}
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
int main(){
    string filename = "./test.in";
    ifstream in(filename, ios::in|ios::binary|ios::ate);
    if(!in.is_open()){
        cout<<"couldn't open the file\n";
        system("pause");
        exit(1);
    }
    long size;
    size = in.tellg();
    in.seekg(0, ios::beg);
    char * buffer;
    buffer = new char [size+1];
    in.read(buffer, size);
    buffer[size] = '\0';
    in.close();

    cout<<"Bytes:"<<size<<endl;
    cout<<string(buffer).length()<<endl;
    cout<<"Below is the content:"<<endl;
    cout<<buffer<<endl;

    delete buffer;
    system("pause");
    return 0;
}
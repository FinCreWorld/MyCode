#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char data[100];

    // 以写模式打开文件
    ofstream outfile;
    outfile.open("afile.dat");

    cout<<"Writing to the file"<<endl;
    cout<<"Enter your name:";
    cin.getline(data, 100);

    // 向文件写入输入的数据
    outfile<<data<<endl;

    cout<<"Enter your age:";
    cin>>data;
    cin.ignore();
    outfile<<data<<endl;

    // 关闭打开的文件
    outfile.close();

    memset(data, 0, sizeof(data));

    // 以写模式打开文件
    ifstream infile;
    infile.open("afile.dat");

    // 读入文件中的数据
    cout<<"Reading from the file"<<endl;
    infile>>data;

    // 输出数据
    cout<<data<<endl;

    // 再次读入数据
    infile>>data;
    cout<<data<<endl;

    infile.close();

    system("pause");
    return 0;
}
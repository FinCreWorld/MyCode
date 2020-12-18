// 修改文本文件中的某一行
#include<fstream>
#include<cstdio>
#include<iostream>
using namespace std;
 
int main()
{
	fstream fs("test.in", ios::binary | ios::out | ios::in);
    string s;
    string a = "123\n";
    int i = 0;
    while(getline(fs, s)){
        if(s[0] == 'a'){
            fs.seekp(-s.length()-1, ios::cur);
            // cout<<s.length();
            fs.write(a.c_str(), 4);
            break;
        }
        // cout<<s.length()<<" ";
        // cout<<fs.tellg()<<endl;
        // cout<<s.substr(0, s.length()-1);
    }
	fs.close();
    system("pause");
	return 0;
}
#include <iostream>
#include <direct.h>
#include <string>
using namespace std;
void deleteFile(string url){
    struct _finddata_t fb;
    string path;
    long handle;
    int resultone;
    int noFile;

    noFile = 0;
    handle = 0;

    path = url + "/*";

    handle = _findfirst(path.c_str(), &fb);

    if(handle != -1){
        while(0 == _findnext(handle, &fb)){
            noFile = strcmp(fb.name, "..");

            if(0 != noFile){
                path.clear();
                path = url + "/" + fb.name;
                if(fb.attrib == 16){
                    deleteFile(path);
                }else{
                    remove(path.c_str());
                }
            }
        }
    }
    _rmdir(url.c_str());
    _findclose(handle);
}
int main(){
    string url = "./learnCpp/test";
    deleteFile(url);
    system("pause");
    return 0;
}
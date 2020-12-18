#include<iostream>
#include<cstdlib>
using namespace std;

// base-class
class Shape{
    public:
    void setWidth(int w){
        width = w;
    }
    void setHeight(int h){
        height = h;
    }
    protected:
    int width;
    int height;
};

class PaintCost{
    public:
    int getCost(int area){
        return area*70;
    }
};

// 派生类
class Rectangle: public Shape, public PaintCost{
    public:
    int getArea(){
        return width*height;
    }
};

int main(){
    Rectangle rect;

    rect.setHeight(1);
    rect.setWidth(2);

    cout<<rect.getArea()<<endl;
    cout<<rect.getCost(rect.getArea())<<endl;

    system("pause");
    return 0;
}
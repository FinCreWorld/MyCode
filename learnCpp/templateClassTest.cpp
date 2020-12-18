#include<iostream>
#include<vector>

using namespace std;

template <class T>
class Stack {
    private:
        vector<T> elems;

    public:
        void push(T const&);
        void pop();
        T top() const;
        bool empty() const{
            return elems.empty();
        }
};

template <class T>
void Stack<T>::push (T const& elem){
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop(){
    if(elems.empty()){
        throw out_of_range("Stack<>::pop: empty stack");
    }
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const{
    if(elems.empty()){
        throw out_of_range("Stack<>::top(): empty stack");
    }
    return elems.back();
}

int main(){
    try{
        Stack<int> intStack;
        Stack<string> strStack;

        intStack.push(1);
        intStack.push(2);
        intStack.push(10);

        while(!intStack.empty()){
            cout<<intStack.top()<<endl;
            intStack.pop();
        }

        strStack.push("hello");
        strStack.push("world");

        while(!strStack.empty()){
            cout<<strStack.top()<<endl;
            strStack.pop();
        }

        // intStack.pop();

        system("pause");
        return 0;
    }catch(exception const& e){
        cerr<<"Exception: "<<e.what()<<endl;
        system("pause");
        return -1;
    }
}
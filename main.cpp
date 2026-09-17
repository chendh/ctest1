#include <iostream>
using namespace std;

int main(){
    string str="";
    while (true) {
        cout << "input a string: " ;
        cin >> str;
        if (str!="q") cout << "hello, " << str << endl;
        else {
            cout << "good bye!";
            break;
        }
    } 
}
#include <iostream>

using namespace std;

int main(){
    int n;
    string name = "";
    string id = "";
    int total = 0;

    cout << "input name: " ;
    cin >> name ;

    cout << "input id: " ;
    cin >> id;
    cout << "please input a number n: ";
    cin >> n;

    // For loop
    for (int i=1; i<=n ; i++){
        total += i;
        // total = total + i;
    }

    cout << "for loop : The sum of 1 to " << n << " is " << total << endl;

    // While loop
    int i=1;
    total = 0;
    while (i<=n){
        total += i;
        i++;
    }
    cout << "while loop : The sum of 1 to " << n << " is " << total << endl;

    // Do-while loop
    i = 1;
    total = 0;
    do{
        total += i;
        i++;
    } while (i<=n);
    cout << "do-while loop : The sum of 1 to " << n << " is " << total << endl;
    
    return 0;
}
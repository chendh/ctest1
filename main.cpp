#include <iostream>

using namespace std;

int main(){
    int n;
    string message = " is a prime";

    cin >> n;

    for (int i = 2; i<n; i++){
        if (n%i==0) message = " is not a prime";
    }
    cout << n << message << endl;
    return 0;
}
#include <iostream>
#include <string>


using namespace std;


int toDecimal(int n, int b) {
    int result = 0;
    int mult = 1;

    while (n > 0) {
        result += (n % b) * mult;
        n /= 10;     
        mult *= b;      
    }
    return result;
}

int toBase(int n, int b) {
    int result = 0;
    int mult = 1;

    while (n > 0) {
        result += (n % b) * mult;
        mult *= 10;
        n /= b;
    }

    return result;
}

string toBase2(int n, int b) {
    string chars = "0123456789ABCDEFGHIJ";
    string result = "";

    while (n > 0) {
        result = chars[n % b] + result;
        n /= b;
    }

    return result;
}


int main() {
    cout << "10 toDecimal: " << toDecimal(10, 2) << endl;
    cout << "1011 toDecimal: " << toDecimal(1011, 2) << endl;

    cout << "11 toBase: " << toBase(11, 2) << endl;
    cout << "16 toBase: " << toBase(16, 2) << endl;

    cout << "56 toBase 16: " << toBase2(56, 16) << endl;
    cout << "154 toBase 20: " << toBase2(154, 20) << endl;

    return 0;
}
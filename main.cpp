// COSCI 130
// HW 3
// Daniel Stahl

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double convert(string s);

int main() {
    convert("10001101");
}

double convert(string s) {
    bool sign = (s[0] == '1'? true : false);
    int exponent = 0;
    int significand;
    double total = 0;
    int count = 1;
    int power = 2;
    
    while (count <= 3) {
        if (s[count] == '1') {
            exponent += static_cast<int>(pow(2, power));
        }
        
        power--;
        count++;
    }
    
    for (int x = count; x < 8; x++) {
        // convert binary to dec with hidden 1
        // Check for zeros at the end i.e 1000 = . jumps 1 || 1100 = . jumps 2 || 1110 = . jumps 3
        // finds jumps and minus it agains exponent i.e -2-1 = -3
        // Find the real exponent and check against:
        /*
         2^-1    1/2
         2^-2    1/4
         2^-3    1/8
         2^-4    1/16
         2^-5    1/32
         2^-6    1/64
        */
        
    }
    
    cout << exponent - 3 << endl;
    
    return total;
}

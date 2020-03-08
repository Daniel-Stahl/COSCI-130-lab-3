// COSCI 130
// HW 3
// Daniel Stahl

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

double convert(string s);

int main() {
    cout << convert("11111111") << endl;
}

double convert(string s) {
    bool sign = (s[0] == '1'? true : false);
    bool allZero = true;
    int allOnes = 0;
    bool expZero = true;
    bool exitLoop = false;
    double exponent = 0;
    double significand = 0;
    double jump = 0;
    double total = 0.0;
    int count = 1;
    int power = 2;

    // Checking for all zeros
    for (int x = 1; x < 8 && allZero != false; x++) {
        if (s[x] == '1') {
            allZero = false;
        } else {
            allZero = true;
        }
    }
    
    // if not all zeros then perform convert
    if (allZero == false) {
        while (count <= 3) {
            if (s[count] == '1') {
                exponent += pow(2, power);
                expZero = false;
                allOnes++;
            }
            
            power--;
            count++;
        }
        
        // Significand part:
        for (int x = 7; x > 3; --x) {
            power++;
            
            if (s[x] == '1') {
                significand += pow(2, power);
                allZero = false;
            }
            
            if (!exitLoop) {
                switch (x) {
                    case 7:
                        if (s[x] == '1') {
                            jump = 4;
                            exitLoop = true;
                        }
                        break;
                    case 6:
                        if (s[x] == '1') {
                            jump = 3;
                            exitLoop = true;
                        }
                        break;
                    case 5:
                        if (s[x] == '1') {
                            jump = 2;
                            exitLoop = true;
                        }
                        break;
                    case 4:
                        if (s[x] == '1') {
                            jump = 1;
                            exitLoop = true;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    if (!allZero) { // Checks for all Zeros
        if (allOnes == 3 && significand > 0) { //Checks if NaN
            return nan(0);
        } else if (!sign && allOnes && significand == 0) { // Check for Pos INF
            return numeric_limits<double>::infinity();
        } else if(sign && allOnes && significand == 0) { // Check for Neg Inf
            return -numeric_limits<double>::infinity();
        } else { // If !NaN && !Inf then convert num
            if (!expZero) {
                exponent -= 3;
                significand += 16;
            } else {
                exponent = -2;
            }
            
            switch (static_cast<int>(exponent - jump)) {
                case -1:
                    total = 2;
                    break;
                    
                case -2:
                    total = 4;
                    break;
                    
                case -3:
                    total = 8;
                    break;
                    
                case -4:
                    total = 16;
                    break;
                    
                case -5:
                    total = 32;
                    break;
                    
                case -6:
                    total = 64;
                    break;
                default:
                    break;
            }
            
            if (sign) {
                cout << -significand << "/" << total << endl;
            } else {
                cout << significand << "/" << total << endl;
            }
            
            total = significand/total;
            
        }
    } else { // All zeros
        if (!sign) {
            total = 0;
            
        } else {
            total = -0;
        }
    }
    
    return total = (sign ? -total : total);
}

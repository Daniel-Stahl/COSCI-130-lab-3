// COSCI 130
// HW 3
// Daniel Stahl

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

double convert(string s);

int main() {
    convert("01010101");
}

double convert(string s) {
    bool sign = (s[0] == '1'? true : false);
    bool allZero = true;
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
        if (s[x] == '0') {
            allZero = true;
        } else {
            allZero = false;
            cout << "Not all zeros" << endl;
        }
    }
    
    // if not all zeros then perform convert
    if (allZero == false) {
        while (count <= 3) {
            if (s[count] == '1') {
                exponent += pow(2, power);
                expZero = false;
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
        
        cout << "Exponent: " << exponent << endl;
        cout << "Jump: " << jump << endl;
        cout << "Significand: " << significand << endl;
    }
    
    if (!expZero) {
        exponent -= 3;
        significand += 16;
        cout << "true exponent: " << exponent - jump << endl;
    } else {
        exponent = -2;
        cout << "true exponent: " << exponent - jump << endl;
    }
    
    cout << significand << endl;
    
    switch (static_cast<int>(exponent - jump)) {
        case -1:
            total = significand / 2;
            cout << "Total = " << total << endl;
            break;
            
        case -2:
            total = significand / 4;
            cout << "Total = " << total << endl;
            break;
            
        case -3:
            total = significand / 8;
            cout << "Total = " << total << endl;
            break;
            
        case -4:
            total = significand / 16;
            cout << "Total = " << total << endl;
            break;
            
        case -5:
            total = significand / 32;
            cout << "Total = " << total << endl;
            break;
            
        case -6:
            total = significand / 64;
            cout << "Total = " << total << endl;
            break;
        default:
            break;
    }
    
    if (!sign) {
        cout << -0 << endl;
    }
    
    return total;
}

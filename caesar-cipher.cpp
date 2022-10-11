#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string userString;
    std::cout << "Enter String To Be Encrypted: ";
    std::cin >> userString;

    // make sure all of the entered string is a letter
    while(!userString.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
        std::cout << "Improper Input. Please Try Again With Only Letters: ";
        std::cin >> userString;
    }

    // get from the user if we should encrypt or decrypt
    std::string process;
    std::cout << "Do You Want To Encrypt Or Decrypt A Message? (E/D): ";
    std::cin >> process;

    // make sure that the given direction is valid
    while(!process.find_first_not_of("eEdD")) {
        std::cout << "Improper Input. Please Try Again: ";
        std::cin >> process;
    }

    // get the values to shift the given string
    std::string userShift;
    std::cout << "Enter The Desired Shift Value Deliminated With Spaces. All Missing Values Default To 1: ";
    std::cin >> userShift;

    // make sure all the shift values are numbers
    while(!std::all_of(userShift.begin(), userShift.end(), ::isdigit)) {
        std::cout << "Improper Shift Value: ";
        std::cin >> userShift;
    }

    // if there is only a single value to shift then set entire vector to that value
    std::vector<std::string> userShiftVector(userString.length(), "1");
    if (userShift.size() == 1) {
        for (int i = 0; i < userShiftVector.size(); i++) {
            userShiftVector.at(i) = userShift;
        }
    }

    // take the shift list apart
    int pos, loc = 0;
    while ((pos = userShift.find(" ")) != std::string::npos) {
        userShiftVector.at(loc) = userShift.substr(0, pos);
        userShift.erase(0, pos + 1);
        loc++;
    }

    std::string newString;
    bool encryptMessage;
    std::transform(process.begin(), process.end(), process.begin(), ::toupper);
    if (process == "E") {
        encryptMessage = true;
    } else {
        encryptMessage = false;
    }

    switch (encryptMessage) {
        case 1: // encrypt message
            int newCharAscii;
            char newChar;
            
            for (int i = 0; i < userString.length(); i++) {
                newCharAscii = userString[i] + std::stoi(userShiftVector.at(i));
                newChar = char(newCharAscii);
                
                if (userString[i] >= 'a' and userString[i] <= 'z' and newChar > 'z') {
                        newCharAscii = newCharAscii - 'z' + 'a' - 1;
                        newChar = char(newCharAscii);
                } else if (userString[i] >= 'A' and userString[i] <= 'Z' and newChar > 'Z') {
                        newCharAscii = newCharAscii - 'Z' + 'A' - 1;
                        newChar = char(newCharAscii);
                }
                std::cout << userString[i] << " : " << userString[i] + 0 << " => " << newChar << " : " << newCharAscii << std::endl;
            }

            std::cout << "Original String: " << userString << std::endl 
                      << "Shift Value: " << userShift << std::endl 
                      << "Resulting String: " << newString << std::endl;
            break;
        default: // decrypt message
            std::transform(userString.begin(), userString.end(), userString.begin(), ::tolower);
            for (int i = 1; i < 26; i++) {
                for (int j = 0; j < newString.size(); j++) {
                    break;
                }
            }
            break;
    }

    // keep exe open
    char c; std::cin >> c;
    return 0;
}
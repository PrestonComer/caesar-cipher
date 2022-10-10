#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string userString, userShift, newString, token;
    int k, newStringAscii, pos, loc = 0;

    std::cout << "Enter String To Be Encrypted: ";
    std::cin >> userString;

    // make sure all of the entered string is a letter
    while(!userString.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
        std::cout << "Improper Input. Please Try Again With Only Letters: ";
        std::cin >> userString;
    }

    // get the values to shift the given string
    std::cout << "Enter The Desired Shift Value Deliminated With Spaces. All Missing Values Default To 1: ";
    std::cin >> userShift;

    // make sure all the shift values are numbers
    while(!std::all_of(userShift.begin(), userShift.end(), ::isdigit)) {
        std::cout << "Improper Shift Value: ";
        std::cin >> userShift;
    }


    std::vector<std::string> userShiftVector(userString.length(), "1");

    if (userShift.size() == 1) {
        userShiftVector.at(0) = userShift;
    }

    // take the shift list apart
    while ((pos = userShift.find(" ")) != std::string::npos) {
        userShiftVector.at(loc) = userShift.substr(0, pos);
        userShift.erase(0, pos + 1);
    }

    for (int i = 0; i < userShiftVector.size(); i++) {
        newString += userString[i] + std::stoi(userShiftVector.at(i));
    }

    std::cout << "Original String: " << userString << std::endl 
              << "Shift Value: " << userShift << std::endl 
              << "Resulting String: " << newString << std::endl;

    // keep exe open
    char c; std::cin >> c;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost>

int main() {
    std::string userString, userShift, selectedDirection;

    std::cout << "Enter String To Be Encrypted: ";
    std::cin >> userString;

    // make sure all of the entered string is a letter
    while(userString.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
        std::cout << "Improper Input. Please Try Again With Only Letters: ";
        std::cin >> userString;
    }

    // get the values to shift the given string
    std::cout << "Enter The Desired Shift Value Deliminated With Spaces. The Default Value Is 1: ";
    std::cin >> userShift;

    // make sure all the shift values are numbers
    while(!std::all_of(userShift.begin(), userShift.end(), ::isdigit)) {
        std::cout << "Improper Shift Value: ";
        std::cin >> userShift;
    }

    // do we want A to become B or Z when shift value is 1
    std::cout << "Enter The Desired Shift Direction (L/R): ";
    std::cin >> selectedDirection;

    // make sure the user picked a direction
    while(selectedDirection != "L" && selectedDirection != "R") {
        std::cout << "Improper Direction. Please Try Again: ";
        std::cin >> selectedDirection;
    }

    // take the shift list apart
    std::vector<std::string> userShiftVector(userString.length(), "1");
    std::vector<std::string> shiftedString;
    int loc = 0;
    while ((pos = userShift.find(" ")) != std::string::npos) {
        token = userShift.substr(0, pos);

        std::count << userString[loc] << " : " << userString[loc] + token << std::endl;
        // for (int i = 0; i < userString.length(); i++) {
        // std::cout << userString[i] << " : " << std::stoi(userString[i]) <<
                //   << " = " << userString[i] + userShiftVector.at(i) << std::endl;
        // }

        userInput.erase(0, pos + 1);
    }

    // do the math
    // if (selectedDirection == "L") {
        
    // } else if (selectedDirection == "R") {

    // }

    // keep exe open
    char c; std::cin >> c;
    return 0;
}
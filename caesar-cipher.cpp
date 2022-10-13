#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> getInput() {
    // userInput {
        // (0) String To Be encrypted
        // (1) Process To Be Done
        // (2) Values To Shift By
    std::vector<std::string> userInput(10, "");
    std::cout << "Enter String To Be Encrypted: ";
    std::cin >> userInput.at(0);

    // make sure all of the entered string is a letter
    while(!userInput.at(0).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
        std::cout << "Improper Input. Please Try Again With Only Letters: ";
        std::cin >> userInput.at(0);
    }

    std::cout << "Do You Want To Encrypt Or Decrypt A Message? (E/D): ";
    std::cin >> userInput.at(1);

    // make sure that the given direction is valid
    while(!userInput.at(1).find_first_not_of("eEdD")) {
        std::cout << "Improper Input. Please Try Again: ";
        std::cin >> userInput.at(1);
    }

    std::cout << "Enter The Desired Shift Value Deliminated With Spaces. All Missing Values Default To 1: ";
    std::cin >> userInput.at(2);

    // make sure all the shift values are numbers
    while(!std::all_of(userInput.at(2).begin(), userInput.at(2).end(), ::isdigit)) {
        std::cout << "Improper Shift Value: ";
        std::cin >> userInput.at(2);
    }

    return userInput;
}


std::string encryptMessage(std::vector<std::string> userShiftVector, std::string originalString) {
    int newCharAscii;
    char newChar;
    std::string newString;
    
    for (int i = 0; i < originalString.length(); i++) {
        newCharAscii = originalString[i] + std::stoi(userShiftVector.at(i));
        newChar = char(newCharAscii);
        
        if (originalString[i] >= 'a' && originalString[i] <= 'z' && newChar > 'z') {
            newCharAscii = newCharAscii - 'z' + 'a' - 1;
            newChar = char(newCharAscii);
        } else if (originalString[i] >= 'A' && originalString[i] <= 'Z' && newChar > 'Z') {
            newCharAscii = newCharAscii - 'Z' + 'A' - 1;
            newChar = char(newCharAscii);
        }
        std::cout << originalString[i] << " : " << originalString[i] << " => " << newChar << " : " << newCharAscii << std::endl;
        newString += newChar;
    }

    return newString;
}

std::vector<std::string> decryptMessage(std::string encryptedString) {
    std::vector<std::string> possibleDecryptions(26, "");
    std::string decryptedString;
    int newCharAscii;
    char newChar;

    for (int i = 1; i < 26; i++) {
        decryptedString = "";

        for (int j = 0; j < encryptedString.length(); j++) {
            // create decrypted String
            newCharAscii = encryptedString[i] - i;
            newChar = char(newCharAscii);

            if(encryptedString[j] >= 'a' && encryptedString[j] <= 'z' && newChar < 'a') {
                newCharAscii = newCharAscii + 'z' - 'a' + 1;
                newChar = char(newCharAscii);
            } else if(encryptedString[j] >= 'A' && encryptedString[j] <= 'Z' && newChar < 'A') {
                newCharAscii = newCharAscii + 'Z' - 'A' + 1;
                newChar = char(newCharAscii);
            }
            decryptedString += newChar;
        }
        possibleDecryptions.at(i) = decryptedString;
    }
    return possibleDecryptions;
}

int main() {
    std::vector vals = getInput();
    for (int i = 0; i < vals.size(); i++) {
        std::cout << i << ": " << vals.at(i) << std::endl;
    }

    std::string userString = vals.at(0);

    // get from the user if we should encrypt or decrypt
    std::string process = vals.at(1);

    // get the values to shift the given string
    std::string userShift = vals.at(2);

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

    switch (process == "e" || process == "E") {
        case 1: // encrypt message
            std::cout << "Original String: " << userString << std::endl 
                      << "Shift Value: " << userShift << std::endl 
                      << "Resulting String: " << encryptMessage(userShiftVector, userString) << std::endl;
            break;

        default: // decrypt message
            std::vector<std::string> result = decryptMessage(userString);
            for (int i = 0; i < result.size(); i++) {
                std::cout << "Shift By "<< i << ": " << result[i] << std::endl;
            }
            break;
    }

    // keep exe open
    char c; std::cin >> c;
    return 0;
}
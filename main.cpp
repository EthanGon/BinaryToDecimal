#include <iostream>
#include <cmath>
#include <string>

using namespace std;

static bool running = true;

static void DecideProgramLoopState() {
    string answer{};
    bool answered = false;

    while (!answered) {
        cout << "Continue? Enter Y/N: " << endl;
        cin >> answer;

        if ((answer != "y" || answer != "Y") || (answer != "n" || answer != "N")) {

            if ((answer == "y" || answer == "Y")) {
                answered = true;
                cout << endl;
            }

            if ((answer == "n" || answer == "N")) {
                answered = true;
                running = false;

                cout << "Ending program.. Goodbye." << endl;
            }


        }


    }
}

int main()
{
    
    while (running) {
        string userInput;
        string decimalResult;
        double result{};
        bool isBinary = true;
        bool isNeg = false;
        bool hasDecimal = false;
        size_t decimalIndex{};
        userInput = {};


        cout << "Enter binary number: ";
        cin >> userInput;


        // checks if input is neg/pos, checks where decimal is and only if 0/1s are in the input.
        for (unsigned int i = 0; i < userInput.size(); i++) {
            if (i == 0 && userInput[i] == '-') {
                isNeg = true;
                continue;
            }

            if (userInput[i] == '.') {
                hasDecimal = true;
                decimalIndex = i;
                continue;
            }

            if (userInput[i] != '0' && userInput[i] != '1') {
                cout << "Not a binary number." << endl;
                isBinary = false;
                break;
            }
        }

        if (isBinary) {

            size_t size = hasDecimal ? decimalIndex : userInput.size();

            // determines what curr/start value should be depending on signed value
            size_t currIndex = isNeg ? size - 2 : size - 1;
            size_t startIndex = isNeg ? 1 : 0;

            for (size_t i = startIndex; i < size; i++) {
                int currVal = userInput[i] - '0';

                double valToAdd = ((pow(2, currIndex))) * currVal;

                result += valToAdd;
                currIndex--;
            }

        }


        if (hasDecimal) {
            size_t size = userInput.size();

            int indexVal = 1;

            for (size_t i = decimalIndex + 1; i < size; i++) {
                int currVal = userInput[i] - '0';

                double valToAdd = (pow(2, -indexVal)) * currVal;
                indexVal++;

                result += (valToAdd);

            }


        }

        if (isNeg) { result *= -1; }

        if (isBinary) {
            cout << "Decimal result: " << to_string(result) << endl;
        }

        DecideProgramLoopState();
        
    }

    return 0;
}




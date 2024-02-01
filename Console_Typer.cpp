#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

//control the animation delay in ms and second.
int animationDelayMs = 100;
int finalSleepDurationSec = 5;

void updateCharRange(char& currentChar, char& charRangeEnd, char ch) {
    if (isupper(ch)) { currentChar = 'A'; charRangeEnd = 'Z'; }
    else if (islower(ch)) { currentChar = 'a'; charRangeEnd = 'z'; }
    else if (isdigit(ch)) { currentChar = '0'; charRangeEnd = '9'; }
    //  else if (!isalpha(ch) and !isdigit(ch)) { displayedText += ch; continue; }
    else if (!isalpha(ch) and !isdigit(ch)) { currentChar = ch - 3; charRangeEnd = ch; }
}

void promptForMessage(string& msg) {
    while (msg.empty())
    {
        cout << "Enter your text to Animate: ";
        getline(cin, msg);

        if (msg.empty()) { cout << "Error: Please enter a non-empty message." << endl; }
    }
    cout << endl;
}

int main()
{
    string msg = "", displayedText = "";
    //This function enables input based typing effect
    promptForMessage(msg);

    for (size_t i = 0; i < msg.size(); i++)
    {
        cout << "\r" << displayedText;

        char currentChar, charRangeEnd;
        updateCharRange(currentChar, charRangeEnd, msg[i]);

        for (currentChar; currentChar <= charRangeEnd; currentChar++)
        {
            cout << currentChar << flush;
            this_thread::sleep_for(chrono::milliseconds(animationDelayMs));
            //purpose of the \b character used for backspace
            cout << "\b";

            if (msg[i] == currentChar) { displayedText += currentChar; break; }
        }
    }
    // Clears the current line to display the updated text
    cout << "\r" << displayedText;
    this_thread::sleep_for(chrono::seconds(finalSleepDurationSec));
    return 0;
}
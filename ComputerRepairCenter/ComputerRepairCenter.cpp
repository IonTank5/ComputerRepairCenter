/*
Jacob Choi
Lab Assignment Computer Repair Center
10/30/2020
Removing the options after it is chosen
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
using std::cout; using std::cin; using std::endl; using std::string; //So I don't have to use std:: before these commonly used commands
int main()
{
    double overallTotal = 0;
    //While loop so they can go again
    while (true) {
        char choice;
        string choices = "aAbBcCdD";
        double prices[] = { 200, 150, 75, 12 };
        bool flag = false;
        int spot;
        double total = 0;
        bool checker[] = { false, false, false, false };
        std::vector<string> repairs = { "A.Replaced the CPU and RAM.", "B.Replaced the RAM only.", "C.Repaired the Monitor.", "D.Fixed stuck key." };
        int counter = 0, counter2 = 0;
        int howMany;
        cout << "Computer Repair Center" << endl << endl;
        while (true) {
            cout << "How many repairs were completed?" << endl;
            cin >> howMany;
            if (1 <= howMany && howMany <= 4) {
                break;
            }
            else {
                cout << "Please enter valid number" << endl;
            }
        }
        while (true) {
            counter = 0;
            //Getting the repair
            cout << "What work was performed? Here are the choices:" << endl;
            for (string j : repairs) {
                if (!checker[counter]) {
                    cout << j << endl;
                }
                ++counter;
            }
            cin >> choice;
            flag = false;
            for (int i = 0; i < choices.length(); i++) {
                if (choice == choices[i]) {
                    spot = i * 2 / 2 / 2; //Weird conversion to find which repair was chosen using the char array
                    if (!checker[spot]) {
                        checker[spot] = true;
                        flag = true;
                    }
                    else {
                        cout << "Please pick one of the valid repair options" << endl;
                        break;
                    }
                }
            }
            if (flag) {
                total += prices[spot];
                counter2++;
            }
            else {
                //Error trapping the user
                cout << "Please pick one of the valid repair options" << endl;
            }
            if (counter2 == howMany) {
                break;
            }
        }
        cin;
        string name, temp;
        bool edgar = false;
        cout << "Total: $" << std::fixed << std::showpoint << std::setprecision(2) << total << endl;
        cout << "What is the name of your technician?" << endl;
        cin >> name;
        temp = name; //temp variable to check with EDGAR
        std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (temp == "EDGAR") { //Checking if the technician is Edgar
            edgar = true;
            total = total * 0.85;
            cout << "Here is your 15% discount." << endl;
            cout << "Total: $" << std::fixed << std::showpoint << std::setprecision(2) << total << endl;
        }
        else {
            cout << "We hope " << name << " did their job to your satisfaction." << endl;
        }
        overallTotal += total;
        string answer;
        cout << "Overall Total: $" << std::fixed << std::showpoint << std::setprecision(2) << overallTotal << endl;
        cout << "Would you like to go again?" << endl;
        cin >> answer;
        std::transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
        if (answer == "YES" || answer == "Y") { //checking if they want to add another repair
            cout << endl;
            continue;
        }
        else {
            break;
        }
    }
    return 0;
}
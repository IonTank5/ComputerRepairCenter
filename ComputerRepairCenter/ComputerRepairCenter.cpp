/*
Jacob Choi
Lab Assignment Computer Repair Center
10/30/2020
Allowing the user to input the prices
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using std::cout; using std::cin; using std::endl; using std::string; //So I don't have to use std:: before these commonly used commands
int main()
{
    double overallTotal = 0;
    double prices[4];
    //Extra: Allowing the user to input custom prices for each repair
    while (true) {
        cout << "Enter price for \"Replaced the CPU and RAM.\" ";
        cin >> prices[0];
        if (prices[0]<0) {
            break;
        }
        else {
            cout << "Please enter a positive non zero number" << endl; //Error message if input is out of bounds
        }
    }
    while (true) {
        cout << "Enter price for \"Replaced the RAM only.\" ";
        cin >> prices[1];
        if (prices[1] < 0) {
            break;
        }
        else {
            cout << "Please enter a positive non zero number" << endl; //Error message if input is out of bounds
        }
    }
    while (true) {
        cout << "Enter price for \"Repaired the Monitor.\" ";
        cin >> prices[2];
        if (prices[2] < 0) {
            break;
        }
        else {
            cout << "Please enter a positive non zero number" << endl; //Error message if input is out of bounds
        }
    }
    while (true) {
        cout << "Enter price for \"Fixed stuck key.\" ";
        cin >> prices[3];
        if (prices[3] < 0) {
            break;
        }
        else {
            cout << "Please enter a positive non zero number" << endl; //Error message if input is out of bounds
        }
    }
    //Printing the options and prices to the user.
    cout << "\n$" << std::fixed << std::showpoint << std::setprecision(2) << prices[0] << " A.Replaced the CPU and RAM.  "
        << "\n$" << std::fixed << std::showpoint << std::setprecision(2) << prices[0] << " B.Replaced the RAM only.  "
        << "\n$" << std::fixed << std::showpoint << std::setprecision(2) << prices[1] << " C.Repaired the Monitor.  "
        << "\n$" << std::fixed << std::showpoint << std::setprecision(2) << prices[2] << " D.Fixed stuck key.  \n\n\n";
    //While loop so they can go again
    for (int i = 0; i < 4;i++) { //For loop to limit to 4 repairs
        char choice;
        string choices = "aAbBcCdD";
        //double prices[] = { 350, 150, 75, 12 };
        bool flag = false;
        int spot;
        cout << "Computer Repair Center" << endl << endl;
        while (true) {
            //Getting the repair
            cout << "What work was performed? Here are the choices:\nA.Replaced the CPU and RAM.\nB.Replaced the RAM only.\nC.Repaired the Monitor.\nD.Fixed stuck key." << endl;
            cin >> choice;
            for (int i = 0; i < choices.length(); i++) {
                if (choice == choices[i]) {
                    spot = i;
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
            else {
                //Error trapping the user
                cout << "Please pick one of the valid repair options" << endl;
            }
        }
        cin;
        int amount;
        while (true) {
            cout << "How many repairs were done? (Between 1 and 4)" << endl; //Asking how many of the repairs were done
            cin >> amount;
            if (1 <= amount && amount <= 4) {
                break;
            }
            else {
                cout << "Please enter a number between 1 and 4" << endl; //Error message if input is out of bounds
            }
        }
        string name, temp;
        bool edgar = false;
        spot = spot * 2 / 2 / 2; //Weird conversion to find which repair was chosen using the char array
        double total = prices[spot] * double(amount); //finding the total by multiplying the price by the amount
        cout << "Total: $" << std::fixed << std::showpoint << std::setprecision(2) << total << endl;
        cout << "What is the name of your technician?" << endl;
        cin >> name;
        temp = name; //temp variable to check with EDGAR
        std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (temp == "EDGAR") {
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
        cout << "Overall Total: " << std::fixed << std::showpoint << std::setprecision(2) << overallTotal << endl;
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
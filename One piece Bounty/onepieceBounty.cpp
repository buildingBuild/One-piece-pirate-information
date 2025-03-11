#include <iostream>
#include <string> // for the name
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

string capital(string word)
{

    for (int i = 0; i < word.size(); i++)
    {
        word[i] = toupper(word[i]);
    }

    return word;
}

struct biometrics
{

    string name;
    long long bounty;
    string bio;
    int picture;
};

struct temp
{
    string name;
};

int main()
{

    ifstream PutFs;
    ofstream BringFs;

    char userFinalChoice;
    int i = 0;
    string userSearch;
    char eraseInput;
    char editInput;
    bool found = false;
    biometrics pirate[1000];
    temp prates[1000];
    do
    {

        cout << endl;
        cout << "\nONE PIECE BOUNTY DATABASE" << endl;
        cout << "SELECT AN OPTION USING NUMBERS AS INPUT" << endl;
        cout << endl;
        cout << "1. ADD A CHARACTER TO EXISTING DATABASE" << endl;
        cout << "2. SEARCH FOR A CHARACTER IN DATABASE" << endl;
        cout << "3. UPDATE CHARACTER IN DATABASE" << endl;
        cout << "4. REMOVE A CHARACTER FROM DATABASE" << endl;
        cout << "5. STORE DATABASE IN DOCUMENT AND EXIT" << endl;

        int userInput;
        cin >> userInput;
        cin.ignore();

        switch (userInput)
        {

        case 1:

            cout << "ENTER NAME OF PIRATE: ";
            cin.ignore();
            getline(cin, pirate[i].name);
            cout << "ENTER THE PIRATES BOUNTY: (฿)";
            cin >> pirate[i].bounty;
            cin.ignore();

            cout << "RELEVANT DATA/INFORMATION ABOUT THE PIRATE: ";
            getline(cin, pirate[i].bio);
            cout << endl;
            i = i + 1;
            break;

        case 2:
            cout << "Looking for a specific pirate to see if they are stored in the database ?" << endl;

            cout << "Enter pirate full Name if available" << endl;
            getline(cin, userSearch);

            userSearch = capital(userSearch);

            for (int j = 0; j < i; ++j)
            {

                prates[j].name = capital(pirate[j].name);

                if (userSearch == prates[j].name)
                {
                    cout << endl;
                    cout << "PIRATE FOUND IN DATABASE!" << endl;
                    cout << "DISPLAYING PIRATE INFORMATION...." << endl;
                    cout << endl;
                    cout << "  Pirate Name: " << pirate[j].name;
                    cout << endl;
                    cout << "  Bounty: (฿)" << pirate[j].bounty << endl;
                    cout << "  Relevant Data: " << pirate[j].bio << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {

                cout << endl;
                cout << "PIRATE NOT FOUND IN DATABASE...." << endl;

                cout << endl;
                break;
            }
            break;

        case 3:
            cout << "DISPLAYING VARIOUS PIRATE INFORMATION" << endl;

            for (int h = 0; h < i; ++h)
            {

                cout << "  Pirate #" << h + 1;
                cout << endl;
                cout << "  Pirate Name: " << pirate[h].name;
                cout << endl;
                cout << "  Bounty: (฿)" << pirate[h].bounty << endl;
                cout << "  Relevant Data: " << pirate[h].bio << endl;
                cout << endl;

                cout << "WOULD YOU LIKE TO EDIT THIS PIRATE DATA (Y/N): ";
                cin >> editInput;
                editInput = toupper(editInput);
                cin.ignore();

                if (editInput == 'Y')
                {

                    cout << "  Pirate #" << h + 1;
                    cout << endl;
                    cout << "Pirate Name: " << pirate[h].name << endl;
                    cout << "  Pirate New Name: ";
                    getline(cin, pirate[h].name);
                    cout << endl;
                    cout << "Bounty: (฿)" << pirate[h].bounty << endl;
                    cout << "  New Bounty: (฿)";
                    cin >> pirate[h].bounty;
                    cin.ignore();
                    cout << endl;
                    cout << " Relevant Data: " << pirate[h].bio << endl;
                    cout << "  New Relevant Data: ";
                    getline(cin, pirate[h].bio);
                    cout << endl;
                    cout << "PIRATE DATA UPDATED, YOUR WELCOME" << endl;
                    break;
                }
            }
            break;

        case 4:
            cout << "ATTEMPTING TO DISPLAY VARIOUS PIRATE INFORMATION" << endl;

            for (int p = 0; p < i; ++p)
            {

                cout << "  Pirate #" << p + 1;
                cout << endl;
                cout << "  Pirate Name: " << pirate[p].name;
                cout << endl;
                cout << "  Bounty: (฿)" << pirate[p].bounty << endl;
                cout << "  Relevant Data: " << pirate[p].bio << endl;
                cout << endl;

                cout << "WOULD YOU LIKE ERASE (IMU-STYLE) THIS PIRATE FROM EXISTENCE (Y/N): ";
                cin >> eraseInput;
                eraseInput = toupper(eraseInput);

                if (eraseInput == 'Y')
                {
                    cout << endl;
                    pirate[p].name = "N/A";
                    pirate[p].bounty = 0;
                    pirate[p].bio = "N/A";

                    cout << "THIS PIRATE NEVER EXISTED, YOUR WELCOME" << endl;
                    break;
                }
            }
            break;

        case 5:
            BringFs.open("bount.txt");
            if (!BringFs.is_open())
            {
                cout << "Error opening File" << endl;
                return 1;
            }

            for (int z = 0; z < i; ++z)
            {

                BringFs << "Pirate #" << z + 1;
                BringFs << endl;
                BringFs << "  Pirate Name: " << pirate[z].name;
                BringFs << endl;
                BringFs << "  Bounty: (฿)" << pirate[z].bounty << endl;
                BringFs << "  Relevant Data: " << pirate[z].bio << endl;
                BringFs << endl;
            }
            cout << "SUCCESS.... DATABASE HAS BEEN STORED TO A DOCUMENT " << endl;
            cout << endl;
            cout << "Thanks for using our application, have a nice one" << endl;
            BringFs.close();

            break;

        default:
            cout << "ERROR" << endl;
            exit(0);
            break;
        }
        cout << "Would you like to continue the process(Y/N)" << endl;

        cin >> userFinalChoice;
        userFinalChoice = toupper(userFinalChoice);

    } while (userFinalChoice == 'Y');

    cout << "Thanks for using our application, have a nice one" << endl;

    return 0;
}
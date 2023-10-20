#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Player
{
public:
    int player_id;
    string country;
    string payer_name;
    string date_of_birth;
    int age;
    string role;
    string batting_style;
    string bowling_style;
    int matches_played;
    int runs_scored;
    int wickets_taken;
    int catches_taken;
    float batting_average;
    float bowling_average;
    int strike_rate;

    Player* next;
};

Player* head = NULL;
Player* tail = NULL;

// New player data
Player* createPlayerData();

void readPlayerDataFromFile();

//  1. Show Cricketer List
void showPlayerData(Player* head);

// 2. Search Cricketer Information
void searchPlayerDataByCountry(string targetCountry);
void searchPlayerDataByPlayerID(int targetPlayerID);
void searchPlayerDataByPlayerName(string targetPlayerName);
void searchPlayerDataByDateOfBirth(string targetDateOfBirth);
void searchPlayerDataByAge(int targetAge);
void searchPlayerDataByRole(string targetRole);
void searchPlayerDataByBattingStyle(string targetBattingStyle);
void searchPlayerDataByBowlingStyle(string targetBowlingStyle);
void searchPlayerDataByMatchesPlayed(int targetMatchesPlayed);
void searchPlayerDataByRunsScored(int targetRunsScored);
void searchPlayerDataByWicketsTaken(int targetWicketsTaken);
void searchPlayerDataByCatchesTaken(int targetCatchesTaken);
void searchPlayerDataByBattingAverage(float targetBattingAverage);
void searchPlayerDataByBowlingAverage(float targetBowlingAverage);
void searchPlayerDataByStrikeRate(int targetStrikeRate);

// 3. Add Cricketer Information
void addPlayerDataAtFront(Player* player, Player* head);
void addPlayerDataAtEnd(Player* player, Player* tail);
void addPlayerDataAtPosition(Player* player, int position);


// 4. Update Cricketer Information
void updatePlayerID(int targetPlayerID);
void updatePlayerName(string targetPlayerName);

// 5. Delete Cricketer Information
void deletePlayerData(int targetPlayerID);


int main()
{
    readPlayerDataFromFile();

    while (true)
    {
        cout << "\tPlayer Database For ICC Men's Cricket World Cup 2023" << endl << endl;

        cout << "\tMain Menu" << endl;
        cout << "\t1. Show Cricketer List" << endl;
        cout << "\t2. Search Cricketer Information" << endl;
        cout << "\t3. Add Cricketer Information" << endl;
        cout << "\t4. Update Cricketer Information" << endl;
        cout << "\t5. Delete Cricketer Information" << endl;
        cout << "\t0. Exit" << endl << endl;

        cout << "\tEnter Instruction: ";
        int input;
        cin >> input;

        switch (input)
        {
        case 1:
            showPlayerData(head);
            break;
        case 2:
        {
            while(true)
            {
                cout << "\t1. Search by Country" << endl;
                cout << "\t2. Search by Player ID" << endl;
                cout << "\t3. Search by Player Name" << endl;
                cout << "\t4. Search by Date of Birth" << endl;
                cout << "\t5. Search by Age" << endl;
                cout << "\t6. Search by Role" << endl;
                cout << "\t7. Search by Batting Style" << endl;
                cout << "\t8. Search by Bowling Style" << endl;
                cout << "\t9. Search by Matches Played" << endl;
                cout << "\t10. Search by Runs Scored" << endl;
                cout << "\t11. Search by Wickets Taken" << endl;
                cout << "\t12. Search by Catches Taken" << endl;
                cout << "\t13. Search by Batting Average" << endl;
                cout << "\t14. Search by Bowling Average" << endl;
                cout << "\t15. Search by Strike Rate" << endl << endl;

                cout << "\tEnter Instruction: ";
                int inputChoice;
                cin >> inputChoice;

                

                switch (inputChoice)
                {
                    case 1: 
                    {
                        cout << "\tEnter Country: ";
                        string country;
                        cin.ignore();
                        getline(cin, country);
                        searchPlayerDataByCountry(country);
                        break;
                    }
                    case 2:
                    {
                        // Implement searchPlayerDataByPlayerID();
                        break;
                    }
                    case 3:
                    {
                        // Implement searchPlayerDataByPlayerName();
                        break;
                    }
                    case 4:
                    {
                        // Implement searchPlayerDataByDateOfBirth();
                        break;
                    }
                    case 5:
                    {
                        // Implement searchPlayerDataByAge();
                        break;
                    }
                    case 6:
                    {
                        // Implement searchPlayerDataByRole();
                        break;
                    }
                    case 7:
                    {
                        // Implement searchPlayerDataByBattingStyle();
                        break;
                    }
                    case 8:
                    {
                        // Implement searchPlayerDataByBowlingStyle();
                        break;
                    }
                    case 9:
                    {
                        // Implement searchPlayerDataByMatchesPlayed();
                        break;
                    }
                    case 10:
                    {
                        // Implement searchPlayerDataByRunsScored();
                        break;
                    }
                    case 11:
                    {
                        // Implement searchPlayerDataByWicketsTaken();
                        break;
                    }
                    case 12:
                    {
                        // Implement searchPlayerDataByCatchesTaken();
                        break;
                    }
                    case 13:
                    {
                        // Implement searchPlayerDataByBattingAverage();
                        break;
                    }
                    case 14:
                    {
                        // Implement searchPlayerDataByBowlingAverage();
                        break;
                    }
                    case 15:
                    {
                        // Implement searchPlayerDataByStrikeRate();
                        break;
                    } 
                    default: cout << "\tExcited Search Operation Successfully" << endl;
            }
            break;
          }
        } 
        break;  
        case 3:
            // Implement updatePlayerData();
            break;
        case 4:
            // Implement deletePlayerData();
            break;
        case 5:
            // Implement searchPlayerData();
            break;
        case 0:
            cout << "\tPlayer Database System Exited Successfully";
            exit(0);
        }
    }

    return 0;
}


Player* createPlayerData()
{
    Player* newPlayer = new Player;

    cout << "Enter Player ID: ";
    cin >> newPlayer->player_id;

    // Check if a player with the same ID already exists
    Player* current = head;
    bool isDuplicate = false;
    while (current != NULL)
    {
        if (current->player_id == newPlayer->player_id && current->player_id>0)
        {
            isDuplicate = true;
            cout << "A player with the same ID already exists." << endl;
            break;
        }
        current = current->next;
    }

    if (!isDuplicate)
    {
        cout << "Enter Country: ";
        cin.ignore(); 
        getline(cin, newPlayer->country);

        cout << "Enter Player Name: ";
        getline(cin, newPlayer->payer_name);

        cout << "Enter Date of Birth: ";
        getline(cin, newPlayer->date_of_birth);

        cout << "Enter Age: ";
        cin >> newPlayer->age;

        cout << "Enter Role: ";
        cin.ignore();
        getline(cin, newPlayer->role);

        cout << "Enter Batting Style: ";
        getline(cin, newPlayer->batting_style);

        cout << "Enter Bowling Style: ";
        getline(cin, newPlayer->bowling_style);

        cout << "Enter Matches Played: ";
        cin >> newPlayer->matches_played;

        cout << "Enter Runs Scored: ";
        cin >> newPlayer->runs_scored;

        cout << "Enter Wickets Taken: ";
        cin >> newPlayer->wickets_taken;

        cout << "Enter Catches Taken: ";
        cin >> newPlayer->catches_taken;

        cout << "Enter Batting Average: ";
        cin >> newPlayer->batting_average;

        cout << "Enter Bowling Average: ";
        cin >> newPlayer->bowling_average;

        cout << "Enter Strike Rate: ";
        cin >> newPlayer->strike_rate;

        newPlayer->next = NULL;
    }
    else
    {
        // If a player with the same ID exists, don't add the new player.
        delete newPlayer;
        newPlayer = NULL;
    }

    return newPlayer;
}


void readPlayerDataFromFile()
{
    ifstream inputFile;
    inputFile.open("/Users/saifmohammed/Desktop/Player-Database/Player-Database-CWC-2023.csv");

    if (inputFile.fail())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }

    string line;
    int count = 0;

    while (getline(inputFile, line))
    {
        if (count >= 1)
        {
            Player* player = new Player;
            stringstream ss(line);

            ss >> player->player_id;
            ss.ignore(); // Ignore the comma
            getline(ss, player->country, ',');
            getline(ss, player->payer_name, ',');
            getline(ss, player->date_of_birth, ',');
            ss >> player->age;
            ss.ignore();
            getline(ss, player->role, ',');
            getline(ss, player->batting_style, ',');
            getline(ss, player->bowling_style, ',');
            ss >> player->matches_played;
            ss.ignore();
            ss >> player->runs_scored;
            ss.ignore();
            ss >> player->wickets_taken;
            ss.ignore();
            ss >> player->catches_taken;
            ss.ignore();
            ss >> player->batting_average;
            ss.ignore();
            ss >> player->bowling_average;
            ss.ignore();
            ss >> player->strike_rate;

            player->next = NULL;

            if (head == NULL)
            {
                head = player;
                tail = player;
            }
            else
            {
                tail->next = player;
                tail = player;
            }
        }
        count++;
    }
    inputFile.close();
}

void showPlayerData(Player* head)
{
    Player* current = head;

    cout << "Player Data:" << endl;

    while (current != NULL)
    {
        cout << current->player_id << "\t"
             << current->country << "\t"
             << current->payer_name << "\t"
             << current->date_of_birth << "\t"
             << current->age << "\t"
             << current->role << "\t"
             << current->batting_style << "\t"
             << current->bowling_style << "\t"
             << current->matches_played << "\t"
             << current->runs_scored << "\t"
             << current->wickets_taken << "\t"
             << current->catches_taken << "\t";

        cout << fixed << setprecision(2);
        cout << current->batting_average << "\t"
             << current->bowling_average << "\t"
             << current->strike_rate << endl;

        current = current->next;
    }
}

void searchPlayerDataByCountry(string targetCountry)
{
    Player* current = head;
    bool found = false;

    cout << "Players from " << targetCountry << ":" << endl;

    while (current != NULL)
    {
        if (current->country == targetCountry)
        {
            found = true;
            cout << current->player_id << "\t"
                 << current->country << "\t"
                 << current->payer_name << "\t"
                 << current->date_of_birth << "\t"
                 << current->age << "\t"
                 << current->role << "\t"
                 << current->batting_style << "\t"
                 << current->bowling_style << "\t"
                 << current->matches_played << "\t"
                 << current->runs_scored << "\t"
                 << current->wickets_taken << "\t"
                 << current->catches_taken << "\t";

            cout << fixed << setprecision(2);
            cout << current->batting_average << "\t"
                 << current->bowling_average << "\t"
                 << current->strike_rate << endl;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found from " << targetCountry << endl;
    }
}




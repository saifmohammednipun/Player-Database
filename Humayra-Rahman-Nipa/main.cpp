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
    string player_name;
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

// Initally read player data from file
void readPlayerDataFromFile();

// clear file before writing
void clearFileBeforWriting(string filename);

//  1. Show Cricketer List
void showAllPlayerData(Player* head);
void showIndividualPlayerData(Player* head,int playerID);

// 2. Search Cricketer Information
void searchPlayerDataByPlayerID(int targetPlayerID);
void searchPlayerDataByCountry(string targetCountry);
void searchPlayerDataByPlayerName(string targetPlayerName);
 void searchPlayerDataByDateOfBirth(string targetDateOfBirth);
 void searchPlayerDataByAge(int targetAge);
 void searchPlayerDataByRole(string targetRole);
 void searchPlayerDataByBattingStyle(string targetBattingStyle);
void searchPlayerDataByBowlingStyle(string targetBowlingStyle);
// void searchPlayerDataByMatchesPlayed(int targetMatchesPlayed);
// void searchPlayerDataByRunsScored(int targetRunsScored);
// void searchPlayerDataByWicketsTaken(int targetWicketsTaken);
// void searchPlayerDataByCatchesTaken(int targetCatchesTaken);
// void searchPlayerDataByBattingAverage(float targetBattingAverage);
// void searchPlayerDataByBowlingAverage(float targetBowlingAverage);
// void searchPlayerDataByStrikeRate(int targetStrikeRate);





// Write updated player data in to file
void writePlayerToCSV(Player* player, string filename);






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
        cout << "\t6. Sort Cricketer List"<<endl;
        cout << "\t7. Generate Report "<< endl;
        cout << "\t0. Exit" << endl << endl;

        cout << "\tEnter Instruction: ";
        int input;
        cin >> input;

        switch (input)
        {
        case 1:
        {
            while(true)
            {
                cout<<"\t\tShow Cricketer Information"<<endl<<endl;
                cout<<"\t1. Show All Cricketers List"<<endl;
                cout<<"\t2. Show Individual Information"<<endl;
                cout<<"\t0. Return Main Menu"<<endl<<endl;

                cout<<"\tEnter Instruction: ";
                cin>>input;
                switch(input)
                {
                    case 1:
                    {
                        clearFileBeforWriting("/Users/saifmohammed/Desktop/Player-Database/Modified-Player-Database-CWC-2023.csv");
                        showAllPlayerData(head);
                        break;
                    }
                    case 2:
                    {
                        int id;
                        cout<<"\tEnter Player ID: ";
                        cin>>id;
                        showIndividualPlayerData(head,id);
                        break;
                    }
                    case 0: break;
                    default: cout << "\tInvalid input. Please try again." << endl;
                }
                if(input==0)
                break;
            }
        }
        break;
        case 2:
        {
            while(true)
            {
                cout << "\t\tSearch Cricketer Information" << endl<<endl;
                cout << "\t1. Search by Player ID" << endl;
                cout << "\t2. Search by Country" << endl;
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
                cout << "\t0. Return Main Menu" << endl << endl;

                cout << "\tEnter Instruction: ";
                int input;
                cin >> input;

                switch (input)
                {
                    case 1:
                    {
                        cout << "\tEnter Player ID: ";
                        int playerID;
                        cin >> playerID;
                        searchPlayerDataByPlayerID(playerID);
                        break;
                    }

                    case 2:
                     {
                        cout << "\tEnter Country: ";
                        string country;
                        cin.ignore();
                        getline(cin, country);
                        searchPlayerDataByCountry(country);
                        break;
                    }
                    case 3:
                    {
                        cout << "\tEnter Player Name: ";
                        string playerName;
                        cin.ignore();
                        getline(cin, playerName);
                       searchPlayerDataByPlayerName(playerName);
                        break;
                    }
                    case 4:
                    {
                        cout << "\tEnter Date of Birth: ";
                        string dateOfBirth;
                        cin.ignore();
                        getline(cin, dateOfBirth);
                        //searchPlayerDataByDateOfBirth(dateOfBirth);
                        break;
                    }
                    case 5:
                    {
                        cout << "\tEnter Age: ";
                        int age;
                        cin >> age;
                       // searchPlayerDataByAge(age);
                        break;
                    }
                    case 6:
                    {
                        cout << "\tEnter Role: ";
                        string role;
                        cin.ignore();
                        getline(cin, role);
                       // searchPlayerDataByRole(role);
                        break;
                    }
                    case 7:
                    {
                        cout << "\tEnter Batting Style: ";
                        string battingStyle;
                        cin.ignore();
                        getline(cin, battingStyle);
                       // searchPlayerDataByBattingStyle(battingStyle);
                        break;
                    }
                    case 8:
                    {
                        cout << "\tEnter Bowling Style: ";
                        string bowlingStyle;
                        cin.ignore();
                        getline(cin, bowlingStyle);
                        //searchPlayerDataByBowlingStyle(bowlingStyle);
                        break;
                    }
                    case 9:
                    {
                        cout << "\tEnter Matches Played: ";
                        int matchesPlayed;
                        cin >> matchesPlayed;
                        //searchPlayerDataByMatchesPlayed(matchesPlayed);
                        break;
                    }
                    case 10:
                    {
                        cout << "\tEnter Runs Scored: ";
                        int runsScored;
                        cin >> runsScored;
                        //searchPlayerDataByRunsScored(runsScored);
                        break;
                    }
                    case 11:
                    {
                        cout << "\tEnter Wickets Taken: ";
                        int wicketsTaken;
                        cin >> wicketsTaken;
                       // searchPlayerDataByWicketsTaken(wicketsTaken);
                        break;
                    }
                    case 12:
                    {
                        cout << "\tEnter Catches Taken: ";
                        int catchesTaken;
                        cin >> catchesTaken;
                       // searchPlayerDataByCatchesTaken(catchesTaken);
                        break;
                    }
                    case 13:
                    {
                        cout << "\tEnter Batting Average: ";
                        float battingAverage;
                        cin >> battingAverage;
                        //searchPlayerDataByBattingAverage(battingAverage);
                        break;
                    }
                    case 14:
                    {
                        cout << "\tEnter Bowling Average: ";
                        float bowlingAverage;
                        cin >> bowlingAverage;
                       // searchPlayerDataByBowlingAverage(bowlingAverage);
                        break;
                    }
                    case 15:
                    {
                        cout << "\tEnter Strike Rate: ";
                        int strikeRate;
                        cin >> strikeRate;
                       // searchPlayerDataByStrikeRate(strikeRate);
                        break;
                    }
                    case 0 : break;
                    default: cout << "\tInvalid input. Please try again." << endl;
            }
            if(input==0)
            break;
          }

        }
        break;
        case 3:
        {
            while(true)
            {
                cout<<"\t\tAdd Cricketer Information"<<endl<<endl;
                cout<<"\t1. Add New Player Data at Front"<<endl;
                cout<<"\t2. Add New Player Data at End"<<endl;
                cout<<"\t3. Add New Player Data at Position"<<endl;
                cout<<"\t0. Return Main Menu"<<endl<<endl;

                cout<<"\tEnter Instruction: ";
                cin>>input;
                switch(input)
                {
                    case 1:
                    {
                        Player* newPlayer = createPlayerData();
                        if (newPlayer != NULL)
                        {
                           // addNewPlayerDataAtFront(newPlayer, head);
                            cout<<"New Player Data Added Successfully at the Front"<<endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        Player* newPlayer = createPlayerData();
                        if (newPlayer != NULL)
                        {
                           // addNewPlayerDataAtEnd(newPlayer, tail);
                            cout<<"New Player Data Added Successfully at the End"<<endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        Player* newPlayer = createPlayerData();
                        if (newPlayer != NULL)
                        {
                            cout << "Enter position: ";
                            int position;
                            cin >> position;
                           // addNewPlayerDataAtPosition(newPlayer, position);
                            cout<<"Player Data Added Successfully at "<<position<<" Position"<<endl;
                        }
                        break;
                    }
                    case 0: break;
                    default: cout << "\tInvalid input. Please try again." << endl;
                }
                if(input==0)
                break;
            }
        }
        break;
        case 4:
        {
            int targetPlayerID;
            cout << "Enter Player ID you want to update: ";
            cin >> targetPlayerID;
            //clearFileBeforWriting("/Users/saifmohammed/Desktop/Player-Database/Modified-Player-Database-CWC-2023.csv");
           // updatePlayerInformation(head,targetPlayerID);

            break;
        }
        case 5:
        {
            while(true)
            {
                cout<< "Player Data Deletion"<<endl<<endl;
                cout<<"\t1. Delete Player Data by Player ID"<<endl;
                cout<<"\t2. Delete Player Data by Player Name"<<endl;
                cout<<"\t3. Delete Player Data by Country"<<endl;

                cout<< "\t4. Delete Plater Data From Front"<<endl;
                cout<< "\t5. Delete Player Data From End"<<endl;
                cout<< "\t6. Delete Player Data From Any Position"<<endl;
                cout<< "\t7. Delete Whole Player Database"<<endl;
                cout<<"\t0. Return Main Menu"<<endl<<endl;

                cout << "\tEnter Instruction: ";
                cin>>input;
                switch(input)
                {
                    case 1:
                    {
                        cout << "Enter Player ID: ";
                        int playerID;
                        cin >> playerID;
                       // deletePlayerDataByPlayerID(playerID);
                        cout<<"Player Data Deleted Successfully By Player ID"<<endl;
                        break;
                    }
                    case 2:
                    {
                        cout << "Enter Player Name: ";
                        string playerName;
                        cin.ignore();
                        getline(cin, playerName);
                       // deletePlayerDataByPlayerName(playerName);
                        cout<<"Player Data Deleted Successfully By Player Name"<<endl;
                        break;
                    }
                    case 3:
                    {
                        cout << "Enter Country: ";
                        string country;
                        cin.ignore();
                        getline(cin, country);
                        //deletePlayerDataByCountry(country);
                        cout<<"Player Data Deleted Successfully By Country"<<endl;
                        break;
                    }
                    case 4:
                    {
                       // deletePlayerDataFromFront(head);
                        cout<<"Player Data Deleted Successfully From Front"<<endl;
                        break;
                    }
                    case 5:
                    {
                       // deletePlayerDataFromEnd(tail);
                        cout<<"Player Data Deleted Successfully From End"<<endl;
                        break;
                    }
                    case 6:
                    {
                        cout << "Enter position: ";
                        int position;
                        cin >> position;
                       // deletePlayerDataFromPosition(head, position);
                        cout<<"Player Data Deleted Successfully From "<<position<<" Position"<<endl;
                        break;
                    }
                    case 7:
                    {
                      //  deletePlayerDatabase();
                        cout<<"Player Database Deleted Successfully"<<endl;
                        break;
                    }

                    case 0: break;
                    default: cout << "\tInvalid input. Please try again." << endl;
                }

             if(input==0)
             break;
            }
        }

            break;

        case 6:
        {
            cout<< "Sort Player Information"<<endl<<endl;
            cout<<"\t1. Sort Cricketers by PlayerID" <<endl;
            cout<<"\t2. Sort Cricketers by Country" <<endl;
            cout<<"\t3. Sort Cricketer by Match Played " <<endl;
            cout<<"\t4. Sort Cricketer by Run Scored"<<endl;
            cout<<"\t5. Sort Cricketer by Wickets Taken" <<endl;
            cout<<"\t6. Sort Cricketer by Catches Taken" <<endl;
            cout<<"\t7. Sort Cricketer by Strike Rate" <<endl;

            int input;
            cout<<"Enter Instruction: ";
            cin>>input;


        break;
        }
        case 7: break;
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
        if (current->player_id == newPlayer->player_id && current->player_id<=0)
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
        getline(cin, newPlayer->player_name);

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
    inputFile.open("D:/project/Player-Database-using-LinkedList/Player-Database-CWC-2023.csv");

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
            getline(ss, player->player_name, ',');
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

void printPlayerData(Player* player)
{
    cout << player->player_id << setw(15)
            << player->country << setw(22)
            << player->player_name << setw(13)
            << player->date_of_birth << setw(8)
            << player->age << setw(23)
            << player->role << setw(20)
            << player->batting_style << setw(24)
            << player->bowling_style << setw(10)
            << player->matches_played << setw(10)
            << player->runs_scored << setw(10)
            << player->wickets_taken << setw(10)
            << player->catches_taken << setw(10);
    cout << fixed << setprecision(2);
    cout << player->batting_average << setw(10)
            << player->bowling_average << setw(10)
            << player->strike_rate << endl;
}

void clearFileBeforWriting(string filename)
{
    // Open the file with ios::trunc to clear existing content
    ofstream clearFile(filename, ios::trunc);

    if (!clearFile.is_open())
    {
        cout << "Error opening file for clearing." << endl;
        return;
    }

    clearFile.close();
}

 // Function to write a Player to a .csv file
void writePlayerToCSV(Player* player, string filename)
{

    // Open the output file in append mode
   ofstream outputFile(filename, ios::app);

    if (!outputFile.is_open()) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    // Write the Player data to the .csv file
    outputFile << player->player_id << ","
               << player->player_name << ","
               << player->country << ","
               << player->date_of_birth << ","
               << player->age << ","
               << player->role << ","
               << player->batting_style << ","
               << player->bowling_style << ","
               << player->matches_played << ","
               << player->runs_scored << ","
               << player->wickets_taken << ","
               << player->catches_taken << ","
               << player->batting_average << ","
               << player->bowling_average << ","
               << player->strike_rate << "\n";

    // Close the output file
    outputFile.close();
}

void showAllPlayerData(Player* head)
{
    Player* current = head;

    cout << "Player Data:" << endl;
    cout<<"ID"<<setw(15)<< "Country"<<setw(22)<<"Player Name"<<setw(16)<<"Date of Birth"<<setw(6)<<"Age"<<setw(22)<<"Role"<<setw(20)<<"Batting Style"<<setw(20)<<"Bowling Style"<<setw(15)<<"M.P."<<setw(9)<<"Runs"<<setw(10)<<"Wickets"<<setw(10)<<"Catches"<<setw(10)<<"Bat Avg"<<setw(10)<<"Bowl Avg"<<setw(10)<<"SR"<<endl;
    while (current != NULL)
    {
        printPlayerData(current);
        writePlayerToCSV(current, "/Users/saifmohammed/Desktop/Player-Database/Modified-Player-Database-CWC-2023.csv");
        current = current->next;
    }
}

void showIndividualPlayerData(Player* head, int targetPlayerID)
{
    Player* current = head;
    bool found = false;

    while (current != NULL)
    {
        if (current->player_id == targetPlayerID)
        {
            found = true;

            cout<<"Individual Player Data:"<<endl<<endl;
            cout<< "Player ID " << "\t\t : " << current->player_id << endl;
            cout<< "Country " << "\t\t : " << current->country << endl;
            cout<< "Player Name " << "\t : " << current->player_name << endl;
            cout<< "Date of Birth " << "\t : " << current->date_of_birth << endl;
            cout<< "Player Age " << "\t\t : " << current->age << endl;
            cout<< "Player Role " << "\t : " << current->role << endl;
            cout<< "Batting Style " << "\t : " << current->batting_style << endl;
            cout<< "Bowling Style " << "\t : " << current->bowling_style << endl;
            cout<< "Matches Played " << "\t : " << current->matches_played << endl;
            cout<< "Runs Scored " << "\t : " << current->runs_scored << endl;
            cout<< "Wickets Taken " << "\t : " << current->wickets_taken << endl;
            cout<< "Catches Taken " << "\t : " << current->catches_taken << endl;
            cout<< "Batting Average" << "\t : " << current->batting_average << endl;
            cout<< "Bowling Average" << "\t : "<< current->bowling_average << endl;
            cout<< "Strike Rate " << "\t : " << current->strike_rate << endl;

        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with ID " << targetPlayerID << endl;
    }

}


void searchPlayerDataByPlayerID(int targetPlayerID)
{
    Player* current = head;
    bool found = false;

    while (current != NULL) //to traverse the whole linked list until the last node
    {
        if (current->player_id == targetPlayerID)
        {
            found = true;
            printPlayerData(current); //printing the player data
        }
        current = current->next;  //holding the next node's address-> keep traversing until found the exact node
    }

    if (!found)
    {
        cout << "No players found with ID " << targetPlayerID << endl;
    }
}

void searchPlayerDataByCountry(string targetCountry)
{
    Player* current = head;
    bool found = false;

    while (current != NULL) //to traverse the whole linked list until the last node
    {
        if (current->country == targetCountry)
        {
            found = true;
            printPlayerData(current); //printing the player data
        }
        current = current->next;  //holding the next node's address-> keep traversing until found the exact node
    }

    if (!found)
    {
        cout << "No players found with Country " << targetCountry << endl;
    }
}
void searchPlayerDataByPlayerName(string targetPlayerName)
{
    Player* current = head;
    bool found = false;

    while (current != NULL) //to traverse the whole linked list until the last node
    {
        if (current->player_name == targetPlayerName)
        {
            found = true;
            printPlayerData(current); //printing the player data
        }
        current = current->next;  //holding the next node's address-> keep traversing until found the exact node
    }

    if (!found)
    {
        cout << "No players found with this Name " << targetPlayerName<< endl;
    }
}
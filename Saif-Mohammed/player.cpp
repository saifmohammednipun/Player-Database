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

void readPlayerDataFromFile();
void printPlayerData(Player* player);
void showAllPlayerData();
void searchPlayerData();
void updatePlayerData();
void addPlayerData();
void editPlayerData();
void deletePlayerData();

int main()
{
    readPlayerDataFromFile();
        
    while(true)
    {
       
        cout << "\tPlayer Database For ICC Men's Cricket World Cup 2023"<<endl<<endl;
        
        cout << "\tMain Menu"<<endl;
        cout << "\t1. Show Cricketer List"<<endl;
        cout << "\t2. Add Crickter Information"<<endl;
        cout << "\t3. Update Crickter Information"<<endl;
        cout << "\t4. Delete Crickter Information"<<endl;
        cout << "\t5. Search Crickter Information"<<endl;
        cout << "\t0. Exit"<<endl<<endl;

        cout << "\tEnter Instruction: ";
        int input; 
        cin >> input; 

        switch(input)
        {
            case 1: showAllPlayerData(); break;
            case 2: searchPlayerData(); break;
            case 3: updatePlayerData(); break; 
            case 4: addPlayerData(); break;
            case 5: editPlayerData(); break;
            case 6: deletePlayerData(); break;
            case 0: cout<<"\tSystem Exited Successfully"; exit(0);

        }

    }
    
    return 0;
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
    cout << player->player_id << "\t"
         << player->country << "\t"
         << player->player_name << "\t"
         << player->date_of_birth << "\t"
         << player->age << "\t"
         << player->role << "\t"
         << player->batting_style << "\t"
         << player->bowling_style << "\t"
         << player->matches_played << "\t"
         << player->runs_scored << "\t"
         << player->wickets_taken << "\t"
         << player->catches_taken << "\t";

    cout << fixed << setprecision(2);
    cout << player->batting_average << "\t"
         << player->bowling_average << "\t"
         << player->strike_rate << endl;
}

void showAllPlayerData(Player* head)
{
    Player* current = head;

    cout << "Player Data:" << endl;

    while (current != NULL)
    {
        printPlayerData(current);

        current = current->next;
    }
}

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public: 
        int key;
        Node* next;

    Node()
    {
        this->key = 0;
        this->next = NULL;
    }

    Node(int key)
    {
        this->key = key;
        this->next = NULL;
    }
    
    ~Node(){};

};

Node* head = NULL;
Node* cur = NULL;

class player
{
public:
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
    int batting_average;
    int bowling_average;
    int strike_rate;

    player( string country,
            string payer_name,
            string date_of_birth,
            int age,
            string role,
            string batting_style,
            string bowling_style,
            int matches_played,
            int runs_scored,
            int wickets_taken,
            int catches_taken,
            int batting_average,
            int bowling_average,
            int strike_rate
            )
    {
        this->country = country;
        this->payer_name = payer_name;
        this->date_of_birth = date_of_birth;
        this->age = age;
        this->role = role;
        this->batting_style = batting_style;
        this->bowling_style = bowling_style;
        this->matches_played = matches_played;
        this->runs_scored = runs_scored;
        this->wickets_taken = wickets_taken;
        this->catches_taken = catches_taken;
        this->batting_average = batting_average;
        this->bowling_average = bowling_average;
        this->strike_rate = strike_rate;
        
    }
};

void printPlayerData()
{
  
   ifstream inputFile;
   inputFile.open("/Users/saifmohammed/Desktop/Player-Database/Player-Database-CWC-2023.csv");

   if(inputFile.fail())
   {
       cout << "Error opening file" << endl;
        exit(1);
   }
    
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
    int batting_average;
    int bowling_average;
    int strike_rate;
    
    string myString;
    string line;


    while(getline(inputFile, line))
    {
        try{
        stringstream ss(line);
        getline(ss,country, ',');
        getline(ss,payer_name, ',');
        
        getline(ss,date_of_birth, ',');
        //date_of_birth = date_of_birth.substr(0,2)+date_of_birth.substr(3,4)+date_of_birth.substr(6,2);
     
        age = stoi(myString);
        getline(ss,role, ',');
        getline(ss,batting_style, ',');
        getline(ss,bowling_style, ',');
        matches_played = stoi(myString);
        runs_scored = stoi(myString);
        wickets_taken = stoi(myString);
        catches_taken = stoi(myString);
        batting_average = stoi(myString);
        bowling_average = stoi(myString);
        strike_rate = stoi(myString);
        }
        catch(exception e)
        {
        }
     

        cout <<country +"\t"+
            payer_name + "\t"+
            date_of_birth + "\t" +
            to_string(age) + "\t"+
            role + "\t"+
            batting_style + "\t"+
            bowling_style + "\t"+
            to_string(matches_played) + "\t"+
            to_string(runs_scored) + "\t"+ 
            to_string(wickets_taken) + "\t"+
            to_string(catches_taken) + "\t"+
            to_string(batting_average) + "\t"+
            to_string(bowling_average) + "\t"+
            to_string(strike_rate) << endl;
    }
}


int main()
{
    printPlayerData();

    return 0;
}
//---------------------------------------------------------------------------------------------------------------------
 
 
 //Name: Muhammad Shumas Mazhar
 //Registration: l1f23bscs1097
 //Lab 14 OOPS
 //Task 3

//---------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstring>

using namespace std;

class Player {
private:
    char* playerName;
    int expYears;

public:
    Player() {
        playerName = nullptr;
        expYears = 0;
    }

    Player(const char* name, int experience) {
        playerName = new char[strlen(name) + 1];
        strcpy(playerName, name);
        expYears = experience;
    }

    Player(const Player& other) {
        playerName = new char[strlen(other.playerName) + 1];
        strcpy(playerName, other.playerName);
        expYears = other.expYears;
    }

    Player& operator=(const Player& other) {
        if (this != &other) {
            delete[] playerName;
            playerName = new char[strlen(other.playerName) + 1];
            strcpy(playerName, other.playerName);
            expYears = other.expYears;
        }
        return *this;
    }

    ~Player() {
        delete[] playerName;
    }

    void display() const {
        cout << "Player Name: " << playerName << endl;
        cout << "Experience: " << expYears << " years" << endl;
    }
};

//---------------------------------------------------------------------------------------------------------------------

class SportsTeam {
private:
    char* teamName;
    char* sportName;
    Player* players;
    int playerCount;
    int maxPlayers;

public:
    SportsTeam() {
        teamName = nullptr;
        sportName = nullptr;
        players = nullptr;
        playerCount = 0;
        maxPlayers = 0;
    }

    SportsTeam(const char* tName, const char* sName, int max) {
        teamName = new char[strlen(tName) + 1];
        strcpy(teamName, tName);
        sportName = new char[strlen(sName) + 1];
        strcpy(sportName, sName);
        maxPlayers = max;
        players = new Player[maxPlayers];
        playerCount = 0;
    }

    ~SportsTeam() {
        delete[] teamName;
        delete[] sportName;
        delete[] players;
    }

    void addPlayer(const Player& player) {
        if (playerCount < maxPlayers) {
            players[playerCount] = player;
            playerCount++;
        } else {
            cout << "Team is full. Cannot add more players." << endl;
        }
    }

    void display() const {
        cout << "Team Name: " << teamName << endl;
        cout << "Sport Name: " << sportName << endl;
        cout << "Players in the Team:" << endl;
        for (int i = 0; i < playerCount; i++) {
            players[i].display();
            cout << endl;
        }
    }
};

//---------------------------------------------------------------------------------------------------------------------

int main() {
    SportsTeam team("Dream Team", "Football", 3);

    Player player1("John", 3);
    Player player2("Alex", 5);
    Player player3("Sarah", 2);

    team.addPlayer(player1);
    team.addPlayer(player2);
    team.addPlayer(player3);

    team.display();

    cout << endl;

    player1.display();
    player2.display();
    player3.display();

    return 0;
}
//---------------------------------------------------------------------------------------------------------------------

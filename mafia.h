/*Determines whether a player is dead or alive*/
enum Status{
  alive, 
  dead
};

/*Name bank*/
char *names[] = {"Joseph", "Joan", "John", "Patricia", "James", "Monica", "Paul", "Peter", "Simon", "Juliana"};

/*Determines the job of the individual*/
char *Job[4] = {"mafia", "policeOfficer", "doctor", "citizen"};

/*Describes a player*/
typedef struct{
  char *name;
  enum Status playerDoA;
  char *occupation;
  int vote;
}Player;

/*Function definitions*/
void AddToGame(Player * player2Add);
void RemoveFromGame();
bool noPlayer();
Player * createPlayer(char *namOfPlayer, char *work);
void ridNewline(int choice, char *stringValue);
void delay(int delTime);
void traverseList();
int userJobPosition(char *selJob);

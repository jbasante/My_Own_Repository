/*Determines whether a player is dead or alive*/
enum Status{
  alive, 
  dead
};

/*Determines the job of the individual*/
enum Job{
  mafia,
  policeOfficer,
  doctor,
  citizen
};

/*Describes a player*/
typedef struct{
  char *name;
  enum Status playerDoA;
  enum Job occupation;
  int vote;
}Player;

/*Function definitions*/
void AddToGame(Player * player2Add);
void RemoveFromGame();
bool noPlayer();
Player * createPlayer(char *namOfPlayer);
void ridNewline(int choice, char *stringValue);
void delay(int delTime);
void traverseList();

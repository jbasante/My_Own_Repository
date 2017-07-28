/*Determines whether a player is dead or alive*/
enum Status{
  alive, 
  dead
};

/*Describes a player*/
typedef struct{
  char *name;
  enum Status playerDoA;
  int vote;
}Player;

/*Function definitions*/
void AddToGame(Player * player2Add);
void RemoveFromGame();
bool noPlayer();
Player * createPlayer(char *namOfPlayer);
void ridNewline();
void delay(int delTime);

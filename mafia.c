#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

struct node{
  Player NewPlayer;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

/*Function definitions*/
void AddToGame(Player player2Add);
void RemoveFromGame();
bool noPlayer();
Player * createPlayer(char *namOfPlayer);

int main(){

  int numOfPlayers;
  char PorR;

  printf("\n*************************MAFIA*****************************\n"
	 "Mafia is a game of many players. As many players can play\n"
	 "the game as possible. At least six(6) people must play the game.\n"
	 "The game is easy to understand as the inbuilt coordinator will\n"
	 "direct you as to what to do and also give you information about\n"
	 "what is goin on in the game. The game is played until the mafia\n"
	 "is arrested or killed. Good Luck!!!\n\n");

  while(1){
    while(1){
      printf("How many players will be playing the game: ");
      if ((scanf("%d", &numOfPlayers) == 1) && (numOfPlayers > 5))
	break;
      while(getchar() != '\n');
    }
    while(1){
      printf("You entered %d.\n"
	     "Press p to continue or r to enter a different number of players: ", numOfPlayers);
      while(getchar() != '\n');
      PorR = getchar();
      
      if (PorR == 'p'){
	printf("Please enter your name as the first player of the game: ");
	break;
	/*Play game here*/
      }
      else if(PorR == 'r'){
	printf("Please wait ...\n");
	break;
      }
      else{
	perror("You pressed the wrong button!!!\n");
      }
    }
  }
  /*  
  Player * tryPlayer;
  char tryname[64] = "Joseph";
  tryPlayer = createPlayer(tryname);
  printf("The name of the player is %s. He is currenly %d. His vote number is %d\n", tryPlayer->name, tryPlayer->playerDoA, tryPlayer->vote);
  free(tryPlayer);
  */
  return 0;
}

/*
void AddToGame(struct Player player2Add){
  struct node *newPlayer = (struct node *)malloc(sizeof(struct node));
  newPLayer->NewPlayer = player2Add;
  nwPlayer->next = NULL;

  if(noPlayer()){
    head = newPlayer;
    tail = head;
  }
  else{
    tail->next = newPlayer;
    tail = tail->next;
  }
}
*/

void RemoveFromGame(){
}

bool noPlayer(){
  return ((head == NULL) && (tail == NULL));
}

/*Function: Creates a player and initializes its characterisitics*/
Player * createPlayer(char *nameOfPlayer){
  Player *newPlayer = (Player *)malloc(sizeof(Player));
  
  newPlayer->name = nameOfPlayer;
  newPlayer->playerDoA = alive;
  newPlayer->vote = 0;

  return newPlayer;
}

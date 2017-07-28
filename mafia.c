#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "mafia.h"

struct node{
  Player * NewPlayer;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

int main(){

  int numOfPlayers;
  char PorR;
  char playerFirstName[64];
  Player * tryPlayer;
  Player * tryPlayer2;
  char secondPlayer[64] = "Matthew";

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
      /*Break from loop if the entered value is a number and greater than 5. Else, ask the user to enter a new value*/
      if ((scanf("%d", &numOfPlayers) == 1) && (numOfPlayers > 5)){
	printf("You entered %d.\n",  numOfPlayers);
	break;
      }else
	printf("Incorrect input. Please try again...\n");
      ridNewline(1, NULL);
    }
    while(1){
      /*Press a button to either continue or put in a different number of players*/
      printf("Press p to continue or r to enter a different number of players: ");
      ridNewline(1, NULL);
      PorR = getchar();
      ridNewline(1, NULL);
      
      if (PorR == 'p'){
	printf("Please enter your first name as the first player of the game: ");
	fgets(playerFirstName, sizeof(playerFirstName)-1, stdin);
	ridNewline(2, playerFirstName);
	tryPlayer = createPlayer(playerFirstName);
	tryPlayer2 = createPlayer(secondPlayer);
	AddToGame(tryPlayer);
	AddToGame(tryPlayer2);
	traverseList();
	free(tryPlayer);
	/*Play game here*/
      }
      else if(PorR == 'r'){
	break;
      }
      else{
	perror("You pressed the wrong button!!!\n");
      }
    }
  }
  return 0;
}

void AddToGame(Player * player2Add){
  struct node *newPlayer = (struct node *)malloc(sizeof(struct node));
  newPlayer->NewPlayer = player2Add;
  newPlayer->next = NULL;

  if(noPlayer()){
    head = newPlayer;
    tail = head;
  }
  else{
    tail->next = newPlayer;
    tail = tail->next;
  }
}


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

void ridNewline(int choice, char *stringValue){
  if (choice == 1)
    while(getchar() != '\n');
  else if (choice == 2){
    if (stringValue[strlen(stringValue)-1] == '\n'){
      stringValue[strlen(stringValue)-1] = ' ';
    }
  }
}

void delay(int delTime){
  int x = 0;
  while(x < delTime)
    x++;
}

void traverseList(){
  struct node *ptr;
  ptr = head;
  while(ptr != NULL){
    printf("Player name: %s \n", ptr->NewPlayer->name);
    ptr = ptr->next;
  }
}

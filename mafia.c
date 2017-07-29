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

  int numOfPlayers, i;
  char PorR;
  char userName[64];
  Player * userPlayer;
  Player * otherPlayer;
  char secondPlayer[64] = "Matthew";
  char playerJob[64];
  int jobNumber[3];

  printf("\n*************************MAFIA*****************************\n"
	 "Mafia is a game of many players. As many players can play\n"
	 "the game as possible. At least six(6) and at most ten (10) people\n"
	 "must play the game. The game is easy to understand as the inbuilt\n"
	 "coordinator will direct you as to what to do and also give you \n"
	 "information about what is goin on in the game. The game is played \n"
	 "until the mafia is arrested or killed. Good Luck!!!\n\n");

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
	/*Prepare user as player and add to game*/
	printf("\nPlease enter your first name as the first player of the game: ");
	fgets(userName, sizeof(userName), stdin);
	ridNewline(2, userName);
	printf("Do you want to be a mafia, policeOfficer, doctor?\n"
	       "Please enter the occupation just as is in this question: ");
	fgets(playerJob, sizeof(playerJob), stdin);
	ridNewline(2, playerJob);
	jobNumber[0] = userJobPosition(playerJob);
	userPlayer = createPlayer(userName, Job[jobNumber[0]]);
	AddToGame(userPlayer);
	
	/*Add the rest of the players to the game*/
	for (i = 0; i < numOfPlayers-1; i++){
	  otherPlayer = createPlayer(names[i], "citizen");
	  AddToGame(otherPlayer);
	}
	traverseList();
	free(otherPlayer);
	break;
	/*Play game here*/
      }
      else if(PorR == 'r'){
	break;
      }
      else{
	perror("You pressed the wrong button!!!\n");
      }
    }
    break;
  }
  return 0;
}

/*Function: Adds players to the game*/
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
Player * createPlayer(char *nameOfPlayer, char *work){
  Player *newPlayer = (Player *)malloc(sizeof(Player));
  
  newPlayer->name = nameOfPlayer;
  newPlayer->occupation = work;
  newPlayer->playerDoA = alive;
  newPlayer->vote = 0;

  return newPlayer;
}

/*Function: Gets rid of newline character*/
void ridNewline(int choice, char *stringValue){
  if (choice == 1)
    while(getchar() != '\n');
  else if (choice == 2){
    if (stringValue[strlen(stringValue)-1] == '\n'){
      stringValue[strlen(stringValue)-1] = '\0';
    }
  }
}

void delay(int delTime){
  int x = 0;
  while(x < delTime)
    x++;
}

/*Function" Prints information about a Player*/
void traverseList(){
  struct node *ptr;
  ptr = head;
  int j = 1;
  while(ptr != NULL){
    printf("Player%d: %s \n", j, ptr->NewPlayer->name);
    printf("Player is a %s\n", ptr->NewPlayer->occupation);
    ptr = ptr->next;
    j++;
  }
}

/*Function: Returns an integer based on the job the user inputs*/
int userJobPosition(char *selJob){
  if (strcmp(selJob, "mafia") == 0)
    return 0;
  else if (strcmp(selJob, "policeOfficer") == 0)
    return 1;
  else if (strcmp(selJob, "doctor") == 0)
    return 2;
}

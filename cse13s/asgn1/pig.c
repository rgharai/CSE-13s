#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "names.h"
#include <inttypes.h>

#define NAMES_LEN 10

// THis is enumerating of positions
typedef  enum { SIDE , RAZORBACK , TROTTER , SNOUTER , JOWLER } Position;
const  Position  pig[7] = {
   SIDE ,
   SIDE ,
   RAZORBACK ,
   TROTTER ,
   SNOUTER ,
   JOWLER ,
   JOWLER
};


void  prtPts(int *points){
   for (int i = 0; i < NAMES_LEN; i++){
      printf("points for %d is: %d", i, points[i]);
   }
}
// Make the array for the players and assign variables from the name.h file
int main(){



   // Asking how many players in the game
   int numPlayers(void);
   int num_Players = 0;
   int points[NAMES_LEN];

   //num plrs input
   printf("How many players? ");
   scanf("%d", &num_Players);
   if(num_Players > NAMES_LEN){
      printf("Invalid number of players. Using 2 instead.\n");
      num_Players = 2;
   }
   
   //initializing pts
   for (int i = 0; i < NAMES_LEN; i++){
      points[i] = 0;
   }
   
   //trying to get random seed to start the game
   int64_t seed;
   printf("random seed: ");
   scanf("%"SCNd64, &seed);
   srandom(seed);
   
   bool gameover = false;
   
   
   // While loop to go throug7 each turn
   while (!gameover){
      for (int i = 0;i< num_Players;i++){

         printf("%s rolls the pig... ",names[i]);
         

         bool done = false;
         while(done == false){
            int roll = random()%7;
            //Using Switch statements, assign/add  points for the given position of the pig when the random number is outputted.
            switch(roll){
               case RAZORBACK:
                  points[i]+=10;
                  printf("pig lands on back");
                  break;
               case TROTTER:
                  points[i]+=10;
                  printf("pig lands upright");
                  break;
               case SNOUTER:
                  points[i]+=15;
                  printf("pig lands on snout");
                  break;
               case JOWLER:
                  points[i]+= 5;
                  printf("pig lands on ear");
                  break;
               case SIDE:
                  printf("pig lands on side");
                  done = true;
                  break;
            }
         }

         printf("\n");

         if(points[i]>= 100){
            printf("%s wins with %d points!\n",names[i], points[i]);
            gameover=true;
            break;
         }
      }
   }


   return 0;
}


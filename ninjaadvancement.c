/*
Yjang Wynter

COP3223C

Program 7

9/22/2018

ninjaadvancemens.c is the seventh program for my Online Class in COP3223.
This program solves the problem statement by utilizing switch statements to solve
individual tasks that are classed in the menu found within the main function.
I tried using functions, but couldn't do it and scrapped my design on the in the last 4 hour till due time
The program in concept should work, but I did not give myself enough time to hammer out errors in the code
So without further ado, this is my shoddy work I have no choice but to turn in
---------------------------------------------------------------------------
This program aims to combine that require to read a file specified by a user which
manipulates the data to compares a student's test scores to his/her peers.

*/
//pre-processor derivatives
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//prototype
void printMenu();

int main (){

int lowBound, highBound, choice, range = highBound - lowBound, i, total, students = 0;
int  header, userScore = 0, scores[header], min = INT_MAX, max = INT_MIN, higher, sameScore = 0, lowNum, theCut = 0;
double lowPerc, average;

char fileName[header];
//opens the file for reading and writing
FILE *ifp=NULL;
     while (ifp==0){
        printf("What is the name of the input file?\n");

        scanf("%s",fileName);

        ifp = fopen(fileName, "r");
         //In case the file is not found.
            if (ifp==0)

                printf("FILE NOT FOUND\n");
        }
        //This reads the first value which correspondinds to the amount of scores in the file
        fscanf(ifp, "%d", &header);

printf("What did you score on your assessment?\n");
scanf("%d", &userScore);

printf("The scores for %d students of the Ninja Academy have been read.\n", header);

for (i = 0; i < header; i++){
  fscanf(ifp, "%d", &scores[i]);
    }


    printMenu();

    scanf("%d", &choice);

while (choice !=8){

        switch(choice){

        case 1:
            printf("What is the lower bound?\n");

            scanf("%d", &lowBound);

            printf("What is the upper bound?\n");

            scanf("%d", &highBound);

            for (i = lowBound; i <= highBound; i++){

            total += scores[i];
            }

            average = total / range;

            printf("The average score from student %d to student %d is %.2f.\n", lowBound, highBound, average);

            total = 0;

            highBound = 0;

            lowBound = 0;

        break;


        case 2:


         printf("What is the lower bound?\n");

            scanf("%d", &lowBound);

            printf("What is the upper bound?\n");

            scanf("%d", &highBound);

            for (i = lowBound; i <= highBound; i++){

                if (min > scores[i]){

                min = scores[i];
                }
            }
            printf("The lowest score from student %d to student %d is %d.\n", lowBound, highBound, min);

             min = INT_MAX;

            highBound = 0;

            lowBound = 0;

        break;


        case 3:
         max = INT_MIN;
         printf("What is the lower bound?\n");

            scanf("%d", &lowBound);

            printf("What is the upper bound?\n");

            scanf("%d", &highBound);

            for (i = lowBound; i <= highBound; i++){

                if (scores[i] > max){

                max = scores[i];
                }
            }
            printf("The highest score from student %d to student %d is %d.\n", lowBound, highBound, max);

            max = INT_MIN;

            highBound = 0;

            lowBound = 0;

        break;


        case 4:
         higher = 0;

            printf("What is the lower bound?\n");

            scanf("%d", &lowBound);

            printf("What is the upper bound?\n");

            scanf("%d", &highBound);

            for (i = lowBound; i <= highBound; i++){

                if (scores[i] > userScore){

                higher += 1;
                }
            }
            printf("%d students scored higher than you.\n", higher);

            higher = 0;
        break;


//Case 5 is broken, I have no clue, comment it out to run
/*
        case 5:
            lowPerc = 0;

            lowNum = 0;

             printf("What is the lower bound?\n");

            scanf("%d", &lowBound);

            printf("What is the upper bound?\n");

            scanf("%d", &highBound);

            for (i = lowBound; i <= highBound; i++){

                if (scores[i] < userScore){

                lowNum += scores[i];
                }
            }
            lowPerc = lowNum / range;

            printf("%.2f percent of students scored lower than you.", lowPerc);

            lowPerc = 0;

            lowNum = 0;

        break;
        */



        case 6:
        sameScore = 0;
        printf("What is the lower bound?\n");

            scanf("%d", &lowBound);

            printf("What is the upper bound?\n");

            scanf("%d", &highBound);

            for (i = lowBound; i <= highBound; i++){

                if (scores[i] == userScore){

                sameScore += 1;
                }
            }
            printf("%d students scored the same as you.\n", sameScore);

            higher = 0;

        break;



        case 7:
        printf("How many students will be advancing?");

        scanf("%d", &theCut);

        for( i = 0; i < students; i++){

        if (scores[i] > userScore){

            students += 1;

            }
        }
        if (students < theCut){

            printf("You will be able to advance to the master class!");
        }
        else{

         printf("You will not be able to advance.");

        }
        break;

        default:

         printf("That input is not valid\n");

         break;


            }
    //resets choice
    choice = 0;
    //loops the print and user response
    printMenu();

    scanf("%d", &choice);

    }

fclose(ifp);
    return 0;
}




//Pre-Conditions: none
//Post-Conditions: menu is called to be printed in main()
void printMenu(){
printf("What would you like to do?\n");

    printf("\t1.Calculate the average assessment score for a subset of the donations.\n");
    printf("\t2.Calculate the minimum assessment score for a subset of the donations. \n");
    printf("\t3.Calculate the maximum assessment score for a subset of the donations. \n");
    printf("\t4.Calculate the number of assessment scores exceeding the user's score. \n");
    printf("\t5.Calculate what percentage of the assessment scores are under the user's score.\n");
    printf("\t6.Determine how many other students scored the same as the user. \n");
    printf("\t7.Determine if the user will be able to advance. \n");
    printf("\t8.Quit \n");
    }





#include <stdio.h>

typedef struct
{
    unsigned int firstVisit : 1;
    unsigned int visitAgain : 1;
    unsigned int fingersLost : 4;
    unsigned int sharkAttack : 1;
    unsigned int daysWeek : 3;
} survey;

void surveyResults(survey s){
    if(s.firstVisit) puts("First time visitor!");
    if(s.visitAgain) puts("Would visit again.");
    if(s.fingersLost > 0) printf("I lost %i finger(s)!\n", s.fingersLost);
    if(s.sharkAttack) puts("A SHARK ATTACKED ME!");
    if(s.daysWeek > 0) printf("I would spend, at most, %i days here.\n", s.daysWeek); 
}

int main()
{
    survey s = {1, 1, 2, 1, 7};
    surveyResults(s);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START.SLOTS 91   


struct Car 
{
    char number[20];
    char size[10];
    int entry0Hour;
    int exit0Hour;
};


struct Slot 
{
    int  id;
    char   size[10];
    int  filled;
    struct Car car;
};

struct Slot *slots   =    NULL;
int total0Slots   =   START_SLOTS;
float total0Money   =    0;
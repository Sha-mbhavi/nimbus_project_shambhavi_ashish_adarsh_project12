#ifndef PARKING_H
#define PARKING_H

#include "car.h"


struct Slot {
    int id;           
    char size[10];  
    int filled;        
    struct Car car;  
};


extern struct Slot *slots;
extern int totalSlots;
extern float totalMoney;


void setupSlots(void);
void expandSlot(void);
void parkCar(void);
void removeCar(void);
void searchCar(void);
void showSlots(void);
void showReport(void);

#endif

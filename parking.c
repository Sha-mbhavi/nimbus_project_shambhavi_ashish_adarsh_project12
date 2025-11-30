#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parking.h"

#define START_SLOTS 91


struct Slot *slots = NULL;
int totalSlots = START_SLOTS;
float totalMoney = 0;



void setupSlots() {
    slots = (struct Slot*) malloc(totalSlots * sizeof(struct Slot));
    if (!slots) {
        printf("Memory error.\n");
        return;
    }

    for (int i = 0; i < totalSlots; i++) {
        slots[i].id = i + 1;
        slots[i].filled = 0;

        if (i < 30)
            strcpy(slots[i].size, "small");
        else if (i < 60)
            strcpy(slots[i].size, "medium");
        else
            strcpy(slots[i].size, "large");
    }
}


void expandSlot() {
    int newCount = totalSlots + 10;
    struct Slot *t = realloc(slots, newCount * sizeof(struct Slot));

    if (!t) {
        printf("Could not expand memory.\n");
        return;
    }

    slots = t;


    for (int j = totalSlots; j < newCount; j++) {
        slots[j].id = j + 1;
        strcpy(slots[j].size, "medium");
        slots[j].filled = 0;
    }

    totalSlots = newCount;
    printf("Expanded. Total slots: %d\n", totalSlots);
}


void parkCar() {
    struct Car c;

    printf("Car number: ");
    scanf("%s", c.number);

    printf("Car size (small/medium/large): ");
    scanf("%s", c.size);

    printf("Entry hour: ");
    scanf("%d", &c.entryHour);


    for (int i = 0; i < totalSlots; i++) {
        if (slots[i].filled == 0 && strcmp(slots[i].size, c.size) == 0) {
            slots[i].car = c;
            slots[i].filled = 1;
            printf("Parked at slot %d\n", slots[i].id);
            return;
        }
    }


    printf("No free slot. Expanding...\n");
    expandSlot();
}


void removeCar() {
    int s;
    printf("Slot to free: ");
    scanf("%d", &s);

    if (s < 1 || s > totalSlots || slots[s - 1].filled == 0) {
        printf("Invalid slot.\n");
        return;
    }

    printf("Exit hour: ");
    scanf("%d", &slots[s - 1].car.exitHour);

    int hrs = slots[s - 1].car.exitHour - slots[s - 1].car.entryHour;
    if (hrs <= 0) hrs = 1;

    float base = 20, fine = 10;
    float bill = hrs * (base + fine);

    printf("Car %s removed. Hours: %d  Bill: %.2f\n",
           slots[s - 1].car.number, hrs, bill);

    totalMoney += bill;
    slots[s - 1].filled = 0;
}


void searchCar() {
    char n[20];
    printf("Car number: ");
    scanf("%s", n);

    for (int i = 0; i < totalSlots; i++) {
        if (slots[i].filled && strcmp(slots[i].car.number, n) == 0) {
            printf("Found at slot %d\n", slots[i].id);
            return;
        }
    }
    printf("Not found.\n");
}


void showSlots() {
    for (int i = 0; i < totalSlots; i++) {
        if (slots[i].filled)
            printf("Slot %d [%s] - %s\n",
                   slots[i].id, slots[i].size, slots[i].car.number);
        else
            printf("Slot %d [%s] - Empty\n",
                   slots[i].id, slots[i].size);
    }
}


void showReport() {
    int f = 0;

    for (int i = 0; i < totalSlots; i++)
        if (slots[i].filled) f++;

    printf("Slots: %d  Filled: %d  Money: %.2f\n",
           totalSlots, f, totalMoney);
}

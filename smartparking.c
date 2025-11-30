
    // no free slot found
    printf("No free slot. Expanding...\n");
    expandSlot();
}

void removeCar() {
    int s;
    printf("Slot to free: ");
    scanf("%d", &s);

    if(s < 1 || s > totalSlots || slots[s-1].filled == 0){
        printf("Invalid slot.\n");
        return;
    }

    printf("Exit hour: ");
    scanf("%d", &slots[s-1].car.exitHour);

    int hrs = slots[s-1].car.exitHour - slots[s-1].car.entryHour;
    if(hrs <= 0) hrs = 1;

    float base = 20, fine = 10;
    float bill = hrs * (base + fine);

    printf("Car %s removed. Hours: %d  Bill: %.2f\n",
           slots[s-1].car.number, hrs, bill);

    totalMoney += bill;
    slots[s-1].filled = 0;
}

void searchCar() {
    char n[20];
    printf("Car number: ");
    scanf("%s", n);

    for(int i = 0; i < totalSlots; i++){
        if(slots[i].filled && strcmp(slots[i].car.number, n) == 0){
            printf("Found at slot %d\n", slots[i].id);
            return;
        }
    }

    printf("Not found.\n");
}

void showSlots() {
    for(int i = 0; i < totalSlots; i++){
        if(slots[i].filled){
            printf("Slot %d [%s] - %s\n", slots[i].id, slots[i].size,
                   slots[i].car.number);
        } else {
            printf("Slot %d [%s] - Empty\n", slots[i].id, slots[i].size);
        }
    }
}

void showReport() {
    int f = 0;
    for(int i = 0; i < totalSlots; i++){
        if(slots[i].filled) f++;
    }

    printf("Slots: %d  Filled: %d  Money: %.2f\n",
           totalSlots, f, totalMoney);
}

int main() {
    int ch;
    setupSlots();

    while(1){
        printf("\n1.Park  2.Remove  3.Search  4.Show  5.Report  6.Exit\nChoice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: parkCar(); break;
            case 2: removeCar(); break;
            case 3: searchCar(); break;
            case 4: showSlots(); break;
            case 5: showReport(); break;
            case 6:
                free(slots);
                return 0;
            default:
                printf("Invalid.\n");
        }
    }
}



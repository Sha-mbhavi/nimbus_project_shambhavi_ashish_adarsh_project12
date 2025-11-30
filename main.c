#incclude<stdio.h>
#include<stdlib.h>
#include"parking.h"
int main(){
  int ch;
  setupslot();
  while(1){
    printf("\n1.Park 2. remove  3. search  4. show  5. report  6.exit\nchoice:");
    scanf("%d",&ch);
    switch(ch){
      case1:parkcar();
      break;
      case2:removecar();
      break;
      case3:searchcar();
      break;
      case4:showslot();
      break;
      case5:showreport();
      break;
      case6:
        free(slots);
        return 0;
      default:
        print("Invalid.\n");
    }
  }
}

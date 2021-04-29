#include <stdio.h>

void printTillMax(int min, int max) {
    for(int i = min; i <= max; i++) {
   	printf("number: %d \n", i);
   }
}

int main() {
  int max, min;

  printf("Shine on you crazy diamond\n");
  printf("Enter a min number\n");
  scanf("%d", &min);
  printf("Enter a max number\n");
  scanf("%d", &max);
  printTillMax(min, max);
  return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct {
  char name[40];
  int* bro;
} Person;

void givePercent(int n) {
   if(n == 1) printf("true");
   if(n == 0) printf("false");
}

int main() {
  int n;
  Person p;

  printf("enter number of elements");
  scanf("%d", &n);
  p.bro = (int*)calloc(n, sizeof(int));

    if (p.bro == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
  
        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");
  
        // Get the elements of the array
        for (int i = 0; i < n; ++i) {
            p.bro[i] = i + 1;
        }

	printf("sizeof arr %ld\n", sizeof(p.bro) / sizeof(p.bro[0]));
  
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (int i = 0; i < n; ++i) {
            printf("%d, ", p.bro[i]);
        }
    }
//	char result[8];
    givePercent(0);
    //printf("result: %s", result[0]);

  return 0;

}

#include<stdio.h>
#include<stdlib.h>

int main() {

  int nums[3] = {40, 21, 2};
  int i = 0, j = 0;
  float max = 0, min;
  int x;
  while(i < 3)
  {
     if(max < nums[i]) {
     	max = nums[i];
     }

     i++;
  }

  min = max;

  while(j < 3) {
    if(nums[j] < min) {
    	min = nums[j];
    }
    j++;
  }
     printf("max %f\n", max);
     printf("min %f\n", min);
     printf("press x to clear the console\n");
     scanf("%d", &x);
     if(x) {
       system("clear");

     }
     

  return 0;
}

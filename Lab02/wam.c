// Author: Megan Wong
// Date created: 21/05/2019
// Compute student WAM and grade

#include <stdio.h>
#include <math.h>

int main (void) {
  int course1 = 0;
  int course2 = 0;
  int course3 = 0;
  int course4 = 0;
  double average = 0;

  printf("Enter marks for 4 courses enrolled in past semester:\n");
  scanf("%d %d %d %d", &course1, &course2, &course3, &course4);
  
  average = (course1 + course2 + course3 + course4) / 4.0;

  // %.2f -- the .2 makes sure only two decimal points are printed
  printf("Your WAM  is: %.2f\n", average);

  if (average >= 85) {
     printf("Your grade is HD\n");
  }else if (average >= 75) {
        printf("Your grade is D\n");
        }else if (average>= 65) {
              printf("Your grade is CR\n");
              }else if (average>=50){
                    printf("Your grade is PS\n");
                    }else {
                     printf("Your grade is FL\n");
                     }
  return 0;
}

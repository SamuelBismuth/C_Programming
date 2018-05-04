#include <stdio.h>
#define PI 3.14

int circle(double radius, double *area, double *perimeter) {
   *area = PI * radius * radius;
   *perimeter = 2 * PI * radius;
   return 0;
}

int main() {
   printf("Please enter a radius please : ");
   double radius;
   double area;
   double perimeter;
   scanf("%lf", &radius);
   circle(radius, &area, &perimeter);
   printf("Area : %f\n",area);
   printf("Perimeter : %f\n", perimeter);
   return 0;
}



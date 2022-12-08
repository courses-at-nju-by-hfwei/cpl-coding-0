//
// Created by hfwei on 2022/12/8.
//

#include <stdio.h>
#include <math.h>

#define NUM_OF_PARTITIONS 10000

typedef double (*fp)(double);

double Integrate(double low, double high, double (*fp)(double));
double Square(double x);

int main() {
  double low = 0.0;
  double high = 1.0;
  double integration = 0.0;

  integration = Integrate(low, high, Square);
  printf("Integrate(%f, %f, Square) = %f\n", low, high, integration);

  integration = Integrate(low, high, sin);
  printf("Integrate(%f, %f, sin) = %f\n", low, high, integration);

  integration = Integrate(low, high, cos);
  printf("Integrate(%f, %f, cos) = %f\n", low, high, integration);

  // double (*functions[3])(double) = {Square, sin, cos};
  fp functions[3] = {Square, sin, cos};
  for (int i = 0; i < 3; i++) {
    integration = Integrate(low, high, functions[i]);
    printf("integration = %f\n", integration);
  }

  return 0;
}

double Integrate(double low, double high, double (*fp)(double)) {
  double interval = (high - low) / NUM_OF_PARTITIONS;
  double sum = 0.0;

  for (int i = 0; i < NUM_OF_PARTITIONS; i++) {
    double x = low + interval * i;
    double y = fp(x);
    sum += y * interval;
  }

  return sum;
}

double Square(double x) {
  return x * x;
}
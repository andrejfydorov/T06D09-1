#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define NMAX 10

int input(int *a, int *n, int *c);
void output(int *a, int n);
int check_array(int *a, int n);
void shift_arr(int *a, int n, int num);

int main() {
  int n = NMAX, c, data[NMAX];

  if (input(data, &n, &c) == 0 && check_array(data, n) == 0) {
    shift_arr(data, n, c);
    output(data, n);
  } else {
    printf("n/a");
  }

  return 0;
}

int input(int *a, int *n, int *c) {
  scanf("%d", n);
  if (*n > 10)
    return -1;
  for (int *p = a; p - a < *n; p++) {
    if (scanf("%d", p) != 1) {
      return -1;
    }
  }
  scanf("%d", c);
  return 0;
}

void output(int *a, int n) {
  for (int *p = a; p - a < n; p++) {
    if ((p - a) == n - 1) {
      printf("%d", *p);
    } else {
      printf("%d ", *p);
    }
  }
}

void shift_arr(int *a, int n, int num) {
  int temp_arr[NMAX];
  if (num > 0) {
    int i = 0;
    for (int *p = a + num; p - a < n; p++) {
      temp_arr[i++] = *p;
    }
    for (int *p = a; p - a < num; p++) {
      temp_arr[i++] = *p;
    }
    i = 0;
    for (int *p = a; p - a < n; p++) {
      *p = temp_arr[i++];
    }
  }
  if (num < 0) {
    int i = 0;
    for (int *p = a + n - 1; p - a >= n - abs(num); p--) {
      temp_arr[i++] = *p;
    }
    i = n - 1;
    for (int *p = a + n - abs(num) - 1; p - a >= num; p--) {
      a[i--] = *p;
    }
    i = abs(num) - 1;
    for (int *p = a; p - a < abs(num); p++) {
      a[p - a] = temp_arr[i--];
    }
  }
}

int check_array(int *a, int n) {
  int res = 0;
  for (int *p = a; p - a < n; p++) {
    if (isdigit(*p) != 0) {
      return -1;
    }
  }

  return res;
}
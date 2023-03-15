#include <ctype.h>
#include <stdio.h>

#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
void quick_sort(int *s_arr, int first, int last);
int check_array(int *a, int n);
void swap(int *a, int *b);
void siftDown(int *numbers, int root, int bottom);
void heapSort(int *numbers, int array_size);

int main() {
  int n = NMAX, data[NMAX];
  int data2[NMAX];
  for (int *p = data; p - data < n; p++) {
    data2[p - data] = *p;
  }

  if (input(data, n) == 0 && check_array(data, n) == 0) {
    quick_sort(data, 0, n - 1);
    output(data, n);
    printf("\n");
    heapSort(data2, n);
    output(data, n);
  } else {
    printf("n/a");
  }

  return 0;
}

int input(int *a, int n) {
  for (int *p = a; p - a < n; p++) {
    if (scanf("%d", p) != 1) {
      return -1;
    }
  }
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

void quick_sort(int *s_arr, int first, int last) {
  int i = first, j = last, x = s_arr[(first + last) / 2];

  do {
    while (s_arr[i] < x)
      i++;
    while (s_arr[j] > x)
      j--;

    if (i <= j) {
      if (s_arr[i] > s_arr[j])
        swap(&s_arr[i], &s_arr[j]);
      i++;
      j--;
    }
  } while (i <= j);

  if (i < last)
    quick_sort(s_arr, i, last);
  if (first < j)
    quick_sort(s_arr, first, j);
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

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
// Функция "просеивания" через кучу - формирование кучи
void siftDown(int *numbers, int root, int bottom) {
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done)) {
    if (root * 2 == bottom) // если мы в последнем ряду,
      maxChild = root * 2;  // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // если элемент вершины меньше максимального потомка
    if (numbers[root] < numbers[maxChild]) {
      int temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    } else      // иначе
      done = 1; // пирамида сформирована
  }
}
// Функция сортировки на куче
void heapSort(int *numbers, int array_size) {
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2); i >= 0; i--)
    siftDown(numbers, i, array_size - 1);
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i >= 1; i--) {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i - 1);
  }
}

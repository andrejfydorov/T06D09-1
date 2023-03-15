/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#include <ctype.h>

#define NMAX 10

int input (int *buffer, int *length);
void output (int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);
int check_array(int *a, int n);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main()
{
    int n = NMAX, data[NMAX], data_out[NMAX];
	int inp = input(data, &n);
	int sum = sum_numbers(data, n);
	int ch = check_array(data, n);

	if (inp == 0 && sum != 0 && ch == 0) {
		int finded = find_numbers(data, n, sum, data_out);		
		printf("%d\n", sum);
		output(data_out, finded);
	} else {
		printf("n/a");
	}

	return 0;
}

int input(int *buffer, int *length) {
  scanf("%d", length);
  if (*length > 10)
	return -1;
  for (int *p = buffer; p - buffer < *length; p++) {
    if (scanf("%d", p) != 1) {
      return -1;
    }
  }
  return 0;
}

void output(int *a, int n) {
  for (int *p = a; p - a < n; p++) {
    if ((p - a) == n - 1) {
      printf("%d\n", *p);
    } else {
      printf("%d ", *p);
    }
  }
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length)
{
	int sum = 0;
	
	for (int i = 0; i < length; i++)
	{
		if (buffer[i] % 2 == 0)
		{
			sum = sum + buffer[i];
		}
	}
	
	return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers)
{
	int finded = 0;
	for (int *p = buffer; p - buffer < length; p++)
	{
		if (*p == 0)
		{
			continue;
		}	
		if ((number % (*p)) == 0)
		{
			*numbers = *p;
			numbers++;
			finded++;
		}
		
	}
	
	return finded;
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
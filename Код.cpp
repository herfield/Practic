/*#include <stdio.h>
#include <iostream>
#define a 16807
#define m 2147483647
#define am (1.0/m)
#define q 12773
#define r 2836
#define n 32
#define w 8
#define d (1+(m-1)/n)
#define e 1.2e-7
#define x (1.0-e)
#define MASK 123456789

static long t;

void Seed(long t1)
{
	t = t1;
}

float unirand0(void)
{
	long k;
	float ans;

    t ^= MASK;
    k = t / q;

    if ((t = a * (t -k * q) - r * k) < 0)
    t += m;
    ans = am * t;

    t ^= MASK;

    return(ans);
}

float unirand1(void)
{
	int z;
	long k;
	static long y = 0, v[n];
	float temp;


	if (t <= 0 | | !y)
	{
	 if (t < 0)
	 t = -t;
	 else if (t == 0)
	 t = 1;
	 for (z = n + w - 1; z >= 0; z--)
	 {
	 k = t / q;

	 if ((t = a * (t - k * q) - r * k) < 0)
	 t += m;

	 if (z < n)
	 v[z] = t;
	 }


	 y = v[0];
	}

	k = t / q;
	if ((t = a *(t - k * q) - r * k) < 0)
	t += m;

	y = v[z = y /d];
	v[z] = t;
	if ((temp = am * y) > x)
	return(x);
	else
	return(temp);
}
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Генератор случайных чисел Парка-Миллера с перетасовкой" << endl;
	int i;
	Seed(6723);
	for (i = 0; i < 100; i++)
	printf("%f/n", unirand1());
}*/

//Генератор случаныйх чисел Парка-Миллера без перетасовки

#include <stdio.h>
#include <iostream>
#define a 16807
#define m 2147483647
#define am (1.0/m)
#define q 12773
#define r 2836
#define MASK 123456789

static long t;

void Seed(long t1)
{
	t =t1;
}

float unirand(void)
{
	long k;
	float ans;

	t ^= MASK;
	k = t / q;

	if ((t= a * (t - k * q) - r) <0)
	t += m;

	ans = am * t;

	t ^= MASK;

	return(ans);
}
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Генератор сллучайных числе Парка-Миллера без перетасовки" << endl;
	int i;
	Seed(6723);
	for (i = 0; i < 100; i++)
	printf(("%f\n", unirand()));
}
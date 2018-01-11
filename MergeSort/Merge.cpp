#include <stdio.h>
#include <malloc.h>
#include <random>
#include <iostream>

using namespace std;

void testF();
void testS();
void testT();
void testFo();



void merge(int *p, int left, int right); //merger 

void merge_br(int *p, int left, int right); //splitting





int main()
{
	int n = 12;					//number of elements                                     

	int *p;						//for sorting
	p = (int*)malloc(n * sizeof(int));

	int* f = (int*)malloc(n * sizeof(int)); //for test

	for (int i = 0; i < n; i++)
	{
		p[i] = rand() % 100;
	}

	for (int i = 0; i < n; i++) //for test
		f[i] = p[i];

	int left = 0, right = n;

	printf("Initial massive:\n");
	for (int i = 0; i < n; i++)
		printf(" %d", p[i]);

	printf("\n");

	merge_br(p, left, right);

	printf("Massive after sorting:\n");
	for (int i = 0; i < n; i++)
		printf(" %d", p[i]);

	// 5 элементов в обратном порядке
		cout << endl << "Test 1:" << endl;
	testF();

	//5 одинаковых элементов
	cout << endl << "Test 2:" << endl;
	testS();

	//пустой массив
	cout << endl << "Test 3:" << endl;
	testT();

	//просто массив из 5 элементов
	cout << endl << "Test 4:" << endl;
	testFo();

	free(p);
	free(f);
	return 0;
}



void merge(int *p, int left, int right)
{

	int n = (right - left);
	int half = (left + right) / 2;
	int a = 0, b = 0; //for cycles


	int *final;
	final = (int*)malloc(n * sizeof(int));

	while (((left + a) < half) && ((half + b) < right))
	{
		if (p[left + a] < p[half + b])
		{
			final[a + b] = p[left + a];
			a++;
		}
		else
		{
			final[a + b] = p[half + b];
			b++;
		}
	}

	while ((left + a) < half)
	{
		final[a + b] = p[left + a];
		a++;
	}

	while ((half + b) < right)
	{
		final[a + b] = p[half + b];
		b++;
	}

	for (int i = 0; i < (a + b); ++i)
	{
		p[left + i] = final[i];
	}

	free(final);
	return;
}


void merge_br(int *p, int left, int right)
{
	if ((left + 1) >= right)
		return;
	int h = (left + right) / 2;
	merge_br(p, left, h);
	merge_br(p, h, right);
	merge(p, left, right);
}



void testF()
{
	int n = 5, x = 3;
	int* p;
	p = new int[n];

	for (int i = 0; i < n; ++i)
	{
		p[i] = x;
		x--;
		cout << p[i] << ' ';
	}

	merge_br(p, 0,n);

	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		cout << p[i] << ' ';
	}

	delete[]p;
}

void testS()
{
	int n = 5;
	int* p;
	p = new int[n];

	for (int i = 0; i < n; ++i)
	{
		p[i] = 1;
		cout << p[i] << ' ';
	}

	merge_br(p, 0, n);

	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		cout << p[i] << ' ';
	}

	delete[]p;

}

void testT()
{
	int n = 5;
	int* p;
	p = new int[n];
	merge_br(p, 0, n);
	cout << endl;
	delete[]p;
}

void testFo()
{
	int n = 5;
	int* p;
	p = new int[n];

	for (int i = 0; i < n; ++i)
	{
		p[i] = rand() % 10;
		cout << p[i] << ' ';
	}

	merge_br(p, 0, n);

	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		cout << p[i] << ' ';
	}

	delete[]p;

}

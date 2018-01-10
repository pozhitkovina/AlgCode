#include "stdio.h"
#include "random"
#include <iostream>

using namespace std;

void testF();
void testS();
void testT();
void testFo();

int median(int first, int medium, int last)
{
	if (first >= medium)
	{
		if (first >= last)
			return 1;		//1 means p[1]
		else if (first <= last)
			if (last >= medium)
				return 3;			//3 means p[n]
	}
	if (first < medium)
		if (medium >= last)
			return 2;			//2 means p[(l+n)/2]

	return 0;
}

void qsortic(int *p, int n)
{
	int med = median(p[0], p[n / 2], p[n]);

	int o = 0;

	if (med == 1)
		 o = 0;
	if (med == 2)
		 o = (n / 2);
	if (med == 2)
		 o = n;

	int op = o;
	if (p[n / 2] != p[op])
	{
		int t = p[op];
		p[op] = p[n / 2];
		p[n / 2] = t;
	}

}

void qsort(int *p, int n)
{
	qsortic(p, n-1);

	for (;;)
	{
		if (n < 2)
			return;
		int i = 0, j = n - 1;
		int x = p[n / 2];
		while (i <= j)
		{
			while (x > p[i])
				++i;
			while (x < p[j])
				--j;
			if (i <= j)
			{
				int t = p[i];
				p[i] = p[j];
				p[j] = t;
				++i;
				--j;
			}
		}
		if ((j + 1) > (n - i)) //test on small/big part:for small-recursion, for big-changing n & p
		{
			qsort(p + i, n - i);
			n = j + 1;
		}
		else
		{
			qsort(p, j + 1);
			p = p + i;
			n = n - i;
		}
	}
}

int main()
{
	int n = 11;
	int * p;
	p = new int[n];

	cout << "Before sorting:" << endl;

	for (int i = 0; i < n; ++i)
	{
		p[i] = rand() % 1000;
		cout << p[i] << ' ';
	}

	qsort(p, n);

	cout << endl<< "After sorting:" << endl;

	for (int i = 0; i < n; ++i)
	{
		cout << p[i] << ' ';
	}

	// 5 элементов в обратном порядке
	cout << endl << "Test 1:" <<endl;
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

	delete[]p;
	return 0;
}


void testF ()
{
	int n = 5, x = 3;
	int* p;
	p = new int[n];

	for (int i = 0; i < n; ++i)
	{
		p[i] = x ;
		x--;
		cout << p[i] << ' ';
	}

	qsort(p, n);

	cout << endl ;

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

	qsort(p, n);

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
	qsort(p, n);
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

	qsort(p, n);

	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		cout << p[i] << ' ';
	}

	delete[]p;

}

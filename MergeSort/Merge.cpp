#include <stdio.h>
#include <malloc.h>
#include <random>




void merge(int *p, int left, int right); //merger 

void merge_br(int *p, int left, int right); //splitting

void test(int *arr_init, int *arr_sorted,int n);

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

	test(f, p, n);

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

void test(int *arr_init, int *arr_sorted, int n)
{
	uint32_t wrong_idx = 0;
	bool correct_result = true;
	merge_br(arr_init, 0, n);
	for (int i = 0; i < n; i++)
	{
		if (arr_init[i] != arr_sorted[i])
		{
			correct_result = false;
			wrong_idx = i;
			break;
		}
	}

	if (!correct_result)
	{
		printf("\nError at idx=%d, got %d, expected %d \n", wrong_idx, arr_init[wrong_idx], arr_sorted[wrong_idx]);
	}
	else printf("\n\nProgram is correct!\n");
}
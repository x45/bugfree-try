#include <stdio.h>
#define MAX 10
int binsearch(int x, int v[], int n);
int binsearch2(int x,int v[], int n);
int oop1 = 0;
int oop2 = 0;
int binsearch(int x, int v[], int n)
{
	extern int oop1;
	int low, high, mid;
	low = 0;
	high = n-1;
	while (low <= high){
		++oop1;
		mid = (low+high)/2;
		if (x < v[mid])
		{
			++oop1;
			high = mid+1;
		}
		else if (x > v[mid])
		{
			++oop1;
			low = mid+1;
		}
		else
			return mid;
	}
	return -1;
}


int binsearch2(int x, int v[], int n)
{
	int low, high, mid;
	extern int oop2;
	low = 0;
	high = n-1;
	while (low <= high){
		++oop2;
		mid = (low+high)/2;
		if (x < v[mid])
		{
			++oop2;
			high = mid -1;
		}
		else
		{
			++oop2;
			high = mid +1;
		}
	}
	if (x == v[mid])
		return mid;
	else
		return -1;

}

int main (int argc, char const* argv[])
{
	extern int oop1, oop2;
	int a[MAX];
	int i, j;
	int s = 1;
	
	for (i=0; i < MAX; ++i)
		a[i] = i+1;

	i = binsearch(s, a, MAX);
	j = binsearch2(s, a, MAX);
	
	printf("On bin1 : %d in %d with %d actions\n",s,i,oop1);
	printf("On bin2 : %d in %d with %d actions\n",s,j,oop2);
	return 0;
}


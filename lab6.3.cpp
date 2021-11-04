#include <iostream>
using namespace std;

void create(int* &a, int n,int i)
{
	if (i < n)
	{
		a[i] = -20 + rand() % (41);
		cout << a[i] << " ";
		create(a, n, i+1);
	}
}

template <typename T>
void create(T*& a, int n, int i)
{
	if (i < n)
	{
		a[i] = -20 + rand() % (41);
		cout << a[i] << " ";
		create(a, n, i + 1);
	}
}

template <typename T>
T find(T*& a, int n, T& b,int i)
{
	if (i<n)
	{	if ((a[i] % 2 == 1) || (-a[i] % 2 == 1))
		{
			b = a[i];
			find(a, n, b, i + 1);
		}
	}
	else
	{
		return b;
	}
}

int find(int*& a, int n, int& b, int i)
{
	if (i < n)
	{
		if ((a[i] % 2 == 1) || (-a[i] % 2 == 1))
		{
			b = a[i];
			find(a, n, b, i + 1);
		}
	}
	else
	{
		return b;
	}
}

void result(int*& a, int& b, int n, int i)
{
	if (i<n)
	{	
		if ((b > a[i]) && (a[i] % 2 == 1 || -a[i] % 2 == 1))
		{
			b = a[i];
		}
		result(a, b, n, i + 1);
	}
}
template <typename T>
void result(T*& a, T& b, int n, int i)
{
	if (i < n)
	{
		if ((b > a[i]) && (a[i] % 2 == 1 || -a[i] % 2 == 1))
		{
			b = a[i];
		}
		result(a, b, n, i + 1);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int n, b = 0,i = 0;

	cout << "n="; cin >> n;
	int* q = new int[n];

	create(q, n,i);
	find(q, n, b,i);
	result(q, b, n,i);

	cout << endl << "b=" << b;

	return 0;
}
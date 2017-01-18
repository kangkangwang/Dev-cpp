#include <iostream>
#include <cmath>

using namespace std;

bool isp(int n);
void Print_(bool* p, int m, int n, int i, int j);
int getlen(bool * p, int m, int n, int i, int j, int&);

int main()
{
	int m, n;
	cin >> m >> n;

	bool* set_p = new bool[n - m + 1];

	for (int i = m; i <= n; i++)
	{
		set_p[i - m] = false;

		if (isp(i))
		{
			set_p[i - m] = true;
		}
	}

	int s1 = -1, s2 = -1, count = 0, data, maxdata = 0;
	int k, j;
	k = m;
	while (k <= n)
	{
		if (set_p[k-m])
		{
			j = k;
			while (j <= n)
			{
				if (set_p[j-m])
				{
					int num = getlen(set_p, m, n, k, j, data);
					if (num > count)
					{
						count = num;
						maxdata = data;
						s1 = k;
						s2 = j;
					}
					if (num == count&&data>maxdata)
					{
						maxdata = data;
						s1 = k;
						s2 = j;
					}

				}
				j++;
			}

		}

		k++;
	}


	Print_(set_p, m, n, s1, s2);

	delete[] set_p;
	system("pause");
	return 0;
}

bool isp(int n)
{
	if (n == 0 || n == 1)return false;
	bool result = true;

	int s = (int)sqrt(n);

	for (int i = s; i > 1; i--)
	{
		if (n%i == 0)
		{
			result = false;
		}
	}

	return result;


}

void Print_(bool* p, int m, int n, int i, int j)
{
	if (i<0||j<0)
	{
		return;
	}
	if (i==j)
	{
		cout << i << endl;
		return;
	}
	int d = j - i;
	cout << i << endl << j << endl;
	while ((j + d) <= n&&p[j + d-m])
	{
		j += d;
		cout << j << endl;
	}
	return;
}

int getlen(bool * p, int m, int n, int i, int j,int& lastdata)
{
	if (i>=j)
	{
		lastdata = -1;
		return 1;
	}
	int d = j - i;
	int num = 2;
	lastdata = j;

	while ((j + d) <= n&&p[j + d-m])
	{
		j += d;
		lastdata = d;
		num++;
	}
	return num;
}

#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{

	int *f,*g,*w;
	int k,n;

	while(cin>>n>>k)
	{
		f=new int[n];
		g=new int[k];
		w=new int[k];
		for (int i=1; i<=k; i++)
		{
			cin>>g[i]>>w[i];
		}

		for (int i=0; i<=n; i++)
		{
			f[i]=0;
		}

		for (int i=1; i<=k; i++)
			for (int j=1; j<=n; j++)
			{
				if (g[i]<=j)
				{
					f[j]=max(f[j],f[j-g[i]]+w[i]);
				}
			}

		cout<<f[n]<<endl;

		delete[] f;
		delete[] g;
		delete[] w;
	}


	return 0;
}

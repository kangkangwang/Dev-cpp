#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	long long sum;
	while(cin>>n)
	{
		sum=(long long)n*(n+1)*(n+2)/6;
		cout<<sum<<endl;
	}
	return 0;
}

#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	float a,b;
	while(cin>>a>>b)
	{
		float k,h,j;
		k=b/a;
		int sum=0;
		for(int i=0;i<=a;i++)
		{
			j=b-k*i;
			sum+=(int)j;
			if(sum>=100)
			{
				cout<<"Yes."<<endl;
				break;
			}
		}
		if(sum<100)
			{
				cout<<"No."<<endl;
			
			}
	}
	return 0;
}

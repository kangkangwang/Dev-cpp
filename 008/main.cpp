#include <iostream>
#include <cstring>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	string str;
	while(cin>>str)
	{
		int c[9];
		int* ah[7];
		int h=0;

		int len=str.length();
		for(int i=0;i<7;i++)
		{
			ah[i]=NULL;
		}
		for(int i=0;i<len;i++)
		{
			c[i]=str[i]-48;        
			if(str[i]=='?')
			{
				ah[h]=c+i;
				h++;
			}
		}
		for(int j=0;j<pow(10,h);j++)
		{
			int cu=j;
			for(int k=0;k<h;k++)
			{
				int mod=pow(10,(h-k-1));
				int q=cu/mod;
				*(ah[k])=q;
				cu=cu-q*mod;
			}
			if(c[0]==0||c[3]==0||c[6]==0)continue;
			int sum=c[0]*10+c[1]+c[3]*10+c[4];
			int ans=0;
			if(len==8)
			{
				 ans=c[6]*10+c[7];
			}else
			{
				 ans=c[6]*100+c[7]*10+c[8];
			}
			if(ans==sum)
			{
				cout<<c[0]*10+c[1]<<'+'<<c[3]*10+c[4]<<'='<<sum<<endl;
				break;
			}
				
		}
		
	}
	return 0;
}

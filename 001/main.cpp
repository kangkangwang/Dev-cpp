#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int num,index,n;
	
	while(cin>>n)
	{
		index=1;
		num=0;
		while(1)
		{
			if(index<n+1)
			{
				index=index*2;
				num++;
			}
			else
			{
				index=(index-n)*2-1;
				num++;
			}
			
			if(index==1)break;
		}
		
		cout<<num<<endl;
	
	}
	
	return 0;
}

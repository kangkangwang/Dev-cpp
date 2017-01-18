#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int p[4]={0,1,2,3};
 
 void a(int *p,int i)
 {
 	if(i==4)
 	{
 		for(int k=0;k<4;k++)
 		{
 			cout<<p[k]<<',';
		 }
		 cout<<endl;
	 }
 	for(int j=i;j<4;j++)
 	{
 		int temp=p[i];
 		p[i]=p[j];
 		p[j]=temp;
 		a(p,i+1);
 		p[j]=p[i];
 		p[i]=temp;
	 }
 }
 
int main(int argc, char** argv) {
	a(p,0);
	return 0;
}

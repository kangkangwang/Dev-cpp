#include <iostream>
#include <string>
#include <cmath>

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int data[10], N, ans;

int  combinedata(int data[],int index,int current,int len,int sum)
{

	if(index>-1)sum+=index*pow(10,len-current);
	if(current==len)
	{
		if(sum%N==0)ans++;	
		return 0;
	}
	for(int i=0;i<10;i++)
	{
		if(data[i]>0)
		{
			data[i]--;
			combinedata(data,i,current+1,len,sum);
			data[i]++;
		}
	}
	return ans;
	 
}

int main(int argc, char** argv) {

	string str;
//	while(cin>>str>>N)
//	{
//cin>>str>>N;
N=1;
str="123456789"; 
		ans=0;
		for(int i=0;i<10;i++)data[i]=0;
		for(int i=0;i<str.length();i++)
		{
			data[str[i]-48]+=1;
		}
		cout<<combinedata(data,-1,0,str.length(),0)<<endl;
		
//	}
	return 0;
}


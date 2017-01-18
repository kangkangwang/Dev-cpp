#include<iostream>
#include<string>
using namespace std;


int ans(char* s1,char* s2)
{
	int n1=strlen(s1);
	int n2=strlen(s2);
	if(n1<1||n2<1)return -1;
	int** s;
	int res=0,i,k;
	s=new int*[n1];

	for( i=0;i<n1;i++)
	{
		if(i>1)delete[] s[i-2];
		s[i]=new int[n2];
		for( k=0; k<n2;k++)
		{
			if(k==0||i==0)
			{
				if(s1[i]==s2[k])
				{
						s[i][k]=1;
						res=res<s[i][k]?s[i][k]:res;
				}
				else s[i][k]=0;
			}
			else{
				if(s1[i]==s2[k])
				{
					s[i][k] = s[i-1][k-1] + 1;  
					res=res<s[i][k]?s[i][k]:res;
				}
				else{
					s[i][k]=0;
				}
			}
		}
	}

	delete[] s[n1-2];
	delete[] s[n1-1];
	delete[] s;

	return res;


}
int main()

{

	int T,i=0;
	cin>>T;
	//char p1[100000],p2[100000];
	char* ptr1[200],*ptr2[200];
	while(i<T){
		
		ptr1[i]=new char[100000];
		ptr2[i]=new char[100000];
		
		cin.ignore();
		cin.get(ptr1[i],100000);
		cin.ignore();
		cin.get(ptr2[i],100000);
		
		
		i++;
	}
		for(i=0;i<T;i++)	cout<<ans(ptr1[i],ptr2[i])<<endl;

	return 0;

}

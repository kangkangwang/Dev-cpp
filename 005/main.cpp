#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int ob[10][10];
	int op[10][10];
	
	int m ,n ,x, y,sum,temp;
	while(cin>>m>>n>>x>>y)
	{
		for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					cin>>ob[i][j];
					op[i][j]=-1;
				}
			}
		
		op[x][y]=ob[x][y];
		temp=op[x][y];
		sum=0;
		
		while(true)
		{
			
			sum+=temp;
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(op[i][j]>0)
					{
						op[i][j]-=temp; 
						if(op[i][j]==0) //∏Ø¿√ÕÍ±œ 
						{
							op[i][j]=-2;//±Íº« 
							
						}
					}
				}
			}
			
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(op[i][j]==-2) 
						{
							op[i][j]==0; 
							if(i>0&&i<m-1)
							{
								op[i+1][j]=op[i+1][j]==-1?ob[i+1][j]:op[i+1][j];
								op[i-1][j]=op[i-1][j]==-1?ob[i-1][j]:op[i-1][j];
							}
							else if(i==0)op[i+1][j]=op[i+1][j]==-1?ob[i+1][j]:op[i+1][j];
							else if(i==m-1)op[i-1][j]=op[i-1][j]==-1?ob[i-1][j]:op[i-1][j];
							
							if(j>0&&j<n-1)
							{
								op[i][j+1]=op[i][j+1]==-1?ob[i][j+1]:op[i][j+1];
								op[i][j-1]=op[i][j-1]==-1?ob[i][j-1]:op[i][j-1];
							}
							else if(j==0)op[i][j+1]=op[i][j+1]==-1?ob[i][j+1]:op[i][j+1];
							else if(j==n-1)op[i][j-1]=op[i][j-1]==-1?ob[i][j-1]:op[i][j-1];
						}
				}
			} 
			
			temp=0;
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(op[i][j]>0)
					{
						temp=(temp==0)?op[i][j]:(temp>op[i][j]?op[i][j]:temp);
						
					}
				}
			}
			
			if(temp==0)break;
		}
		
		cout<<sum<<endl;
	}
	
	return 0;
}

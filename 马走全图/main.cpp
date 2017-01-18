#include <iostream>
#include <vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int px[8] {2,1,-1,-2,-2,-1,1,2};
int py[8] {1,2,2,1,-1,-2,-2,-1};
int map[8][8];
int h[8][8];
void path(int x,int y,int count);
int main(int argc, char** argv)
{
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
		{
			for(int n=0; n<8; n++)
			{
				int x=i+px[n];
				int y=j+py[n];
				if(x<8&&x>-1&&y<8&&y>-1)
				{
					map[x][y]++;
				}
			}
		}
	path(0,0,0);
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			cout<<h[i][j]<<'\t';
		}
		cout<<endl;
	}
	return 0;
}

void path(int x,int y,int count)
{
	if(count==64)return;
	h[x][y]=count+1;
	int min=8,xn,yn,u,v;

	for(int i=0; i<8; i++)
	{
		xn=x+px[i];
		yn=y+py[i];

		if(xn<8&&xn>-1&&yn<8&&yn>-1&&h[xn][yn]==0)
		{
			map[xn][yn]--;
			if(map[xn][yn]<min)
			{
				min=map[xn][yn];
				u=xn;
				v=yn;
			}
		}
	}
	
	path(u,v,count+1);
}

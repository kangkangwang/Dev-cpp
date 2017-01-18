#include <iostream>

#include <iomanip>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

#define I 9999

#define N 20 /*点数*/

int  cost[N][N] = {
    {0,3,I,I,I,1,I,I,I,I,I,I,I,I,I,I,I,I,I,I},
    {3,0,5,I,I,I,6,I,I,I,I,I,I,I,I,I,I,I,I,I},
    {I,5,0,4,I,I,I,1,I,I,I,I,I,I,I,I,I,I,I,I},
    {I,I,4,0,2,I,I,I,6,I,I,I,I,I,I,I,I,I,I,I},
    {I,I,I,2,0,I,I,I,I,7,I,I,I,I,I,I,I,I,I,I},
    {1,I,I,I,I,0,1,I,I,I,2,I,I,I,I,I,I,I,I,I},
    {I,6,I,I,I,1,0,6,I,I,I,7,I,I,I,I,I,I,I,I},
    {I,I,1,I,I,I,6,0,2,I,I,I,3,I,I,I,I,I,I,I},
    {I,I,I,6,I,I,I,2,0,8,I,I,I,4,I,I,I,I,I,I},
    {I,I,I,I,7,I,I,I,8,0,I,I,I,I,5,I,I,I,I,I},
    {I,I,I,I,I,2,I,I,I,I,0,4,I,I,I,3,I,I,I,I},
    {I,I,I,I,I,I,7,I,I,I,4,0,3,I,I,I,4,I,I,I},
    {I,I,I,I,I,I,I,3,I,I,I,3,0,3,I,I,I,5,I,I},
    {I,I,I,I,I,I,I,I,4,I,I,I,3,0,7,I,I,I,2,I},
    {I,I,I,I,I,I,I,I,I,5,I,I,I,7,0,I,I,I,I,3},
    {I,I,I,I,I,I,I,I,I,I,3,I,I,I,I,0,5,I,I,I},
    {I,I,I,I,I,I,I,I,I,I,I,4,I,I,I,5,0,8,I,I},
    {I,I,I,I,I,I,I,I,I,I,I,I,5,I,I,I,8,0,6,I},
    {I,I,I,I,I,I,I,I,I,I,I,I,I,2,I,I,I,6,0,4},
    {I,I,I,I,I,I,I,I,I,I,I,I,I,I,3,I,I,I,4,0}
};

int dist[N]; 

int main(int argc, char** argv) {
	
	int v,w,min,visit[N];
	
	for(v=0;v<N;v++)/*初始化*/
	{
		visit[v]=false;
		dist[v]=cost[0][v];
	}
	
	visit[0]=true;
	
	for(int i=0;i<N-1;i++)
	{
		/*寻找没有遍历的最小边*/
	
		min=I;
		
		for(v=0;v<N;v++) 
		{
			if(visit[v]==false&&dist[v]<min)
			{
				w=v;
				min=dist[v];
				
			}
		}
		
		visit[w]=true;
		/*遍历一条边*/
		
		for(v=0;v<N;v++)
		{
			if(!visit[v]&&cost[w][v]+dist[w]<dist[v])
			{
				dist[v]=cost[w][v]+dist[w];
			}
		} 
	}
	
	for(v=0;v<N;v++)
	{
		cout<<char(0+65)<<"->"<<char(v+65)<<':'<<dist[v]<<"\t\t";
	}
	cout<<endl;
	
	 
	return 0;
}

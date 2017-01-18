#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,m;
	while(cin>>n>>m)
	{
		int dx=m-6*n;
		int dy=4*n-m;
		if(dx>0||dy>0||dx%(-2)!=0||dy%(-2)!=0)
		cout<<"Impossible.\n"<<endl;
		else
		{
			cout<<dx/(-2)<<" Ghouls"<<endl;
			cout<<dy/(-2)<<" Crypt Fiends\n"<<endl;
		}
	}
	return 0;
}

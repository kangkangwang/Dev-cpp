#include <iostream>
#include<cmath>
using namespace std;

int main(int argc, char** argv) {
	double  k,a,b,v,d,dw;
	while(cin>>k>>a>>b>>v)
	{
		d=(b-a*k>0?b-a*k:a*k-b)/sqrt(1+pow(k,2));
		dw=sqrt(pow(a,2)+pow(b,2)-pow(d,2));
		cout.precision(3);
		cout.setf(ios::fixed);
		cout<<(d*v)/dw<<endl;
	}
	return 0;
}

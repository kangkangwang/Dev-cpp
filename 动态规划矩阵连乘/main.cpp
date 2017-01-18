#include <iostream>
#include <climits>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int a[6][6],d[6][6];
void path(int i ,int j);

int main(int argc, char** argv) {

	int p[7]= {30,35,15,5,10,20,25};

	int len=sizeof(p)/sizeof(int)-1;
	for(int i=0; i<len-1; i++) {
		a[i][i]=0;
		d[i][i]=-1;
	}
	int j;
	for(int k=1; k<len; k++) {
		for(int i=0; i<len-k; i++) {
			j=k+i;
			a[i][j]=INT_MAX;
			for(int n=i; n<j; n++) {
				int temp=a[i][n]+a[n+1][j]+p[i]*p[n+1]*p[j+1];
				if(temp<a[i][j]) {
					a[i][j]=temp;
					d[i][j]=n;
				}
			}
		}
	}
	for(int i=0; i<len; i++) {
		for(int j=0; j<len; j++) {
			cout<<a[i][j]<<'\t';
		}
		cout<<endl;
	}
	cout<<"-----------------------------------------------"<<endl;
	for(int i=0; i<len; i++) {
		for(int j=0; j<len; j++) {
			cout<<d[i][j]<<'\t';
		}
		cout<<endl;
	}
	cout<<"-----------------------------------------------"<<endl;
	cout<<a[0][len-1]<<endl;
	path(0,len-1);
	return 0;
}

void path(int i ,int j) {
	if(d[i][j]==-1||i==j) {
		cout<<i;
		return;
	}
	cout<<'(';
	path(i,d[i][j]);
	cout<<"),(";
	path(d[i][j]+1,j);
	cout<<')';
	return;
}

#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv)
{
	string str="XLZR VMGKM SCWRS JU OTVF CEUGU PCCXP VPT PGSSVFWFX YH V QBUNFN SQLXSI.";
	int index=0;
	for(int i=0; i<str.length(); i++)
	{
		int d=(char)str[i];
		if(d>64&&d<91)
		{
			index++;
			d=d-64;
			cout<<(char)((d+26-((index+1)*index/2)%26)%26+64);
		}
		else
		{
			cout<<str[i];
		}
	}
	cout<<endl;

	return 0;
}

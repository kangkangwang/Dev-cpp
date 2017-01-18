/*
#include <iostream>
#include <stack>
using namespace std;
int main()
{
	char p[100];
	int index;
	cin.get(p,100);
	string ppt=p;
	stack<string> pt;
	
	while((index=ppt.find(' '))!=-1)
	{
	
	string temp=ppt.substr(0,index);
	pt.push(temp);
	ppt.erase(0,index+1);
}
string temp=ppt.substr(0,index);
	pt.push(temp);
	ppt.erase(0,index+1);
	
	while(!pt.empty())
	{
		cout<<pt.top()<<' ';
		pt.pop();
	}
    return 0;
}*/
/* Code by Slyar 八皇后问题 */ 


/*
	Name: Find left n 
	Copyright: WKK 
	Author: 王康康 
	Date: 26/03/15 20:27
	Description: 递归查找二叉树的左节点个数 
*/

//#include <iostream>
//using namespace std;
//
//void tree(int i,int j,int left,int right,int x,int y)
//{
//	if((left+right)>=max(x,y))return;
//	if(i==x&&j==y)cout<<left<<endl;
//
//	tree(i+j,j,left+1,right,x,y);
//	tree(i,i+j,left,right+1,x,y);
//	
//}
//int main()
//{
//tree(1,1,0,0,1,99);
//}




//#include <iostream>
//
//#include <string>
//
//#include <list>
//
//#include <cstdlib>
//
//
//using namespace std;
//
//struct str{
//		string word;
//		int num;
//	};
//	
//	
//int main()
//{
//	string name,temp;
//	
//	getline(cin,name);
//	str op;
//	bool flag=false;
//	list<str> ptr;
//	list<str>::iterator p;
//	
//	for(int i=0;i<name.length();i++)
//	{
//		if(name[i]!=' '){
//			temp+=name[i];
//		}else
//		{
//			op.word=temp;
//			op.num=1;
//			
//			temp.clear();
//			for(p=ptr.begin();p!=ptr.end();p++)
//			 {
//			if(	(*p).word==op.word)
//			{
//				flag=true;
//				(*p).num+=1;
//				break;
//			}
//			 }
//			
//			if(flag==false)
//			{
//				ptr.push_back(op);
//				flag=false;
//			}
//			
//			
//		}
//	}
//			op.word=temp;
//			op.num=1;
//			
//			temp.clear();
//			for(p=ptr.begin();p!=ptr.end();p++)
//			 {
//			if(	(*p).word==op.word)
//			{
//				flag=true;
//				(*p).num+=1;
//				
//			}
//			 }
//			
//			if(flag==false)
//			{
//				ptr.push_back(op);
//				flag=false;
//			}
//	
//	while(!ptr.empty())
//	{
//		op=ptr.front();
//		ptr.pop_front();
//		cout<<op.word<<','<<op.num<<endl;
//	}
//
//	system("pause");
//	
//}


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	 char *p;
	cin>>p;
	char*s,*m,*h;

	m=",";
	cout<<p;
	s=strtok(p,m);
	
	while(s)
	{
		cout<<s<<endl;
		s=strtok(NULL,m);
	}
	
	cout<<p;
}



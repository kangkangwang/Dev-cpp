/*
	Name: postorder
	Copyright: 
	Author: WKK
	Date: 27/03/15 08:46
	Description: 已知先序和后序用递归求后序 
*/

#include <iostream>
#include <string>

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node
{
	char ch;
	node *left;
	node *right;
};
void postorder(node* T)
{
	if(T->left!=NULL)postorder(T->left);
	if(T->right!=NULL)postorder(T->right);
	cout<<T->ch;
} 

int buildetree(string prestr,string instr,node* &T)
{
	if(prestr.length()>0)
	{
		T=new node();
		T->ch=prestr[0];
		int index=instr.find(prestr[0]);
		/*left*/
		buildetree(prestr.substr(1,index),instr.substr(0,index),T->left);
		/*right*/
		buildetree(prestr.substr(index+1),instr.substr(index+1),T->right);
	}
}
int main(int argc, char** argv) {
	node* T;
	string str1,str2;
	cout<<"请分别输入先序和中序：\n"; 
	cin>>str1>>str2;
	cout<<"后序：\n"; 
	buildetree(str1,str2,T);
	postorder(T);
	return 0;
}

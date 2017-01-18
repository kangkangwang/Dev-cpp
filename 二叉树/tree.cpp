
#include<iostream>
#include<cstdlib>

using namespace std;

class node//树节点定义 
{
	public:
		node* left;
		node* right;
		char data;
};

int postTravel(node* p)//后序遍历二叉树 
{
	if(p!=NULL)
	{

	if(p->left!=NULL)postTravel(p->left);
	if(p->right!=NULL)postTravel(p->right);
	cout<<p->data<<',';
	}
	return 0; 
}

int createTree(char* pre, char* mid,node* &T)
{
	int length=strlen(pre);
	if(length==0)return 0;
	T=new node();
	T->data=pre[0];
	
	char* p=strchr(mid,pre[0]);
	int pos=p-mid;
	
	if(pos!=0)//构造左子树 
	{
		char *left_pre=new char[pos+1];
		char *left_mid=new char[pos+1];
		
		strncpy(left_pre,pre+1,pos);
		left_pre[pos]=0;
		strncpy(left_mid,mid,pos);
		left_mid[pos]=0;
		
		createTree(left_pre,left_mid,T->left); 
	}
	
        	if(pos!=length-1)//构造右子树
	{
		char *right_pre=new char[length-pos];
		char *right_mid=new char[length-pos];
		
		strncpy(right_pre,pre+pos+1,length-pos-1);
		right_pre[length-pos-1]=0;
		strncpy(right_mid,mid+pos+1,length-pos-1);
		right_mid[length-pos-1]=0;
		
		createTree(right_pre,right_mid,T->right);
	} 
	return 0;
}
int main ()
{
	node* T;
	int num=0;
	char* pre,* mid;
	cout<<"Please input number of elements:\n";
	cin>>num; 
	pre=new char[num+1];
	mid=new char[num+1];
	cout<<"Please input preorder string:"<<endl;
	cin>>pre;
	cout<<"Please input midorder string:"<<endl;
	cin>>mid;
	cout<<"The postorder string is:\n";
	createTree(pre,mid,T);
	postTravel(T);
	
	system("pause");
	return 0;	
}

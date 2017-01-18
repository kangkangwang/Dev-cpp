#include <iostream>

#include <iostream>
#include <stdio.h>
//#include <ICRSINT.H>
#include <string>
using namespace std;
#import "c:\program files\common files\system\ado\msado15.dll" no_namespace rename("EOF", "adoEOF")

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	CoInitialize(NULL);//初始化Com库
_ConnectionPtr pMyConnect=NULL;//对象指针
HRESULT hr=pMyConnect.CreateInstance(__uuidof(Connection));//将对象指针实例化
if(FAILED(hr))
{
cout<<"_ConnectionPtr对象指针实例化失败！"<<endl;
return;
}
//下面是连接到SQL SERVER数据库的连接字符串，其中的参数需要根据具体情况进行修改
//_bstr_t strConnect="Driver={sql server};server=qiany;uid=;pwd=;database=pubs";
//下面是连接到Oracle数据库的连接字符串，其中的参数也要自己改
_bstr_t strConnect="Provider=OraOLEDB.Oracle;Data Source=orcl;User Id=scott;Password=m123;";
//连接到数据库，要捕捉异常
Try
{
pMyConnect->Open(strConnect,"","",NULL);
}
catch (_com_error &e){
cout<<e.ErrorMessage() <<endl;
}
//连接到数据库后，开始执行SQL语句
_RecordsetPtr m_pRecordset;//记录集对象指针，用来执行SQL语句并记录查询结果
if(FAILED(m_pRecordset.CreateInstance( __uuidof( Recordset ))))
{
cout<<"记录集对象指针实例化失败！"<<endl;
return 0;
}
char sSql[]="SELECT* FROM EMP";//这里可以用_variant_t的类型（一种COM变量类型，_bstr_t也是）
try{
m_pRecordset->Open((_variant_t)sSql,
pMyConnect.GetInterfacePtr(),
adOpenDynamic,
adLockOptimistic, adCmdText);//打开数据库，执行SQL语句
}
catch (_com_error &e)
{
cout << e.ErrorMessage()<<endl;
}
//SQL语句执行完毕，读取查询结果
try
{
m_pRecordset->MoveFirst(); //记录集指针移动到查询结果集的前面
while(m_pRecordset->adoEOF==VARIANT_FALSE)
{
//这里就读取emp表中的雇员的名字
char *sName=(char*)(_bstr_t)(m_pRecordset->Fields->GetItem(_variant_t("ename"))->Value);
cout<<(char*)(_bstr_t)(m_pRecordset->Fields->GetItem(_variant_t("ename"))->Value)<<endl;
m_pRecordset->MoveNext();
}
}
catch (_com_error &e)
{
cout<<e.ErrorMessage()<<endl;
}
//添加记录
try
{
if(!m_pRecordset->Supports(adAddNew))
{
cout<<"记录添加失败!"<<endl;
return 0;
}
m_pRecordset->AddNew();
m_pRecordset->Fields->GetItem(_variant_t("au_id"))->Value=_bstr_t("998-72-8882");
m_pRecordset->Fields->GetItem(_variant_t("au_lname"))->Value=_bstr_t("赵薇2");
m_pRecordset->Fields->GetItem(_variant_t("au_fname"))->Value=_bstr_t("赵薇2");
m_pRecordset->Fields->GetItem(_variant_t("phone"))->Value=_bstr_t("赵薇2");
m_pRecordset->Update();
}//try
catch (_com_error &e)
{
cout<<"e.ErrorMessage()!"<<endl;
}
	return 0;
}

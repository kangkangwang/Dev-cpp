#include <iostream>

#include <iostream>
#include <stdio.h>
//#include <ICRSINT.H>
#include <string>
using namespace std;
#import "c:\program files\common files\system\ado\msado15.dll" no_namespace rename("EOF", "adoEOF")

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	CoInitialize(NULL);//��ʼ��Com��
_ConnectionPtr pMyConnect=NULL;//����ָ��
HRESULT hr=pMyConnect.CreateInstance(__uuidof(Connection));//������ָ��ʵ����
if(FAILED(hr))
{
cout<<"_ConnectionPtr����ָ��ʵ����ʧ�ܣ�"<<endl;
return;
}
//���������ӵ�SQL SERVER���ݿ�������ַ��������еĲ�����Ҫ���ݾ�����������޸�
//_bstr_t strConnect="Driver={sql server};server=qiany;uid=;pwd=;database=pubs";
//���������ӵ�Oracle���ݿ�������ַ��������еĲ���ҲҪ�Լ���
_bstr_t strConnect="Provider=OraOLEDB.Oracle;Data Source=orcl;User Id=scott;Password=m123;";
//���ӵ����ݿ⣬Ҫ��׽�쳣
Try
{
pMyConnect->Open(strConnect,"","",NULL);
}
catch (_com_error &e){
cout<<e.ErrorMessage() <<endl;
}
//���ӵ����ݿ�󣬿�ʼִ��SQL���
_RecordsetPtr m_pRecordset;//��¼������ָ�룬����ִ��SQL��䲢��¼��ѯ���
if(FAILED(m_pRecordset.CreateInstance( __uuidof( Recordset ))))
{
cout<<"��¼������ָ��ʵ����ʧ�ܣ�"<<endl;
return 0;
}
char sSql[]="SELECT* FROM EMP";//���������_variant_t�����ͣ�һ��COM�������ͣ�_bstr_tҲ�ǣ�
try{
m_pRecordset->Open((_variant_t)sSql,
pMyConnect.GetInterfacePtr(),
adOpenDynamic,
adLockOptimistic, adCmdText);//�����ݿ⣬ִ��SQL���
}
catch (_com_error &e)
{
cout << e.ErrorMessage()<<endl;
}
//SQL���ִ����ϣ���ȡ��ѯ���
try
{
m_pRecordset->MoveFirst(); //��¼��ָ���ƶ�����ѯ�������ǰ��
while(m_pRecordset->adoEOF==VARIANT_FALSE)
{
//����Ͷ�ȡemp���еĹ�Ա������
char *sName=(char*)(_bstr_t)(m_pRecordset->Fields->GetItem(_variant_t("ename"))->Value);
cout<<(char*)(_bstr_t)(m_pRecordset->Fields->GetItem(_variant_t("ename"))->Value)<<endl;
m_pRecordset->MoveNext();
}
}
catch (_com_error &e)
{
cout<<e.ErrorMessage()<<endl;
}
//��Ӽ�¼
try
{
if(!m_pRecordset->Supports(adAddNew))
{
cout<<"��¼���ʧ��!"<<endl;
return 0;
}
m_pRecordset->AddNew();
m_pRecordset->Fields->GetItem(_variant_t("au_id"))->Value=_bstr_t("998-72-8882");
m_pRecordset->Fields->GetItem(_variant_t("au_lname"))->Value=_bstr_t("��ޱ2");
m_pRecordset->Fields->GetItem(_variant_t("au_fname"))->Value=_bstr_t("��ޱ2");
m_pRecordset->Fields->GetItem(_variant_t("phone"))->Value=_bstr_t("��ޱ2");
m_pRecordset->Update();
}//try
catch (_com_error &e)
{
cout<<"e.ErrorMessage()!"<<endl;
}
	return 0;
}

#include <iostream> 
#include <windows.h> 
using namespace std; 

int main() 
{ 
  STARTUPINFO si; //һЩ�ر���������
  int n=1; 
  memset(&si,0,sizeof(STARTUPINFO)); 
  si.cb=sizeof(STARTUPINFO); 
  si.dwFlags=STARTF_USESHOWWINDOW; 
  si.wShowWindow=SW_SHOW; 

  PROCESS_INFORMATION pi; //�ر��������ý���
  //����Ҫ���еĳ���//��·��
  if(!CreateProcess(NULL,"C://Program Files//Internet Explorer//iexplore.exe",NULL,NULL,false,0,NULL,NULL,&si,&pi)) 
  { 
    cout <<"Create Fail!" <<endl; 
    exit(1); 
  } 
  else 
  { 
    cout <<"Success!" <<endl; return(0); 
  }
}

#include <iostream>
#include"courlist.h"
#include"stulist.h"
#include"manager.h"
#include<fstream>
using namespace std;

int main()
{
    stulist stulist2;
    courlist courlist2;
    string id,stuname,pass;
    int ag,enro,cting;int a[50];//ѧ����
    int nmb,cur,mape;
    string couname,fa,teac,nat;
    double sco;//�γ���
    string accou,access;
    int i,i1,i2,i3,i4,fh,linshi,j;
    student *curstudent;
    course *test;
    string zaiti;
    ifstream instudent("student.txt");
    ifstream incourse("course.txt");
    ifstream inmanager("manager.txt");
    while(instudent>>id>>stuname>>ag>>enro>>pass>>cting)
    {
        for(i=0;i<cting;i++){instudent>>a[i];}
        student rea(id,stuname,ag,enro,pass,cting,a);
        stulist2.addstu(rea);
    }
    instudent.close();
    while(incourse>>nmb>>couname>>teac>>sco>>nat>>fa>>cur>>mape)
    {
        course crs(nmb,couname,teac,sco,nat,fa,cur,mape);
        courlist2.add(crs);
    }
    incourse.close();
    inmanager>>accou>>access;
    manager manager2(accou,access);
    int hope=1;//�ж��Ƿ����
    while(hope!=-1)
    {
        i1=0;i2=0;
		i=0;i4=0;
		cout<<"    ------------------------------------------------------\n";
		cout<<"    |           ��ӭ����ѧУ���β�ѯϵͳ                 |"<<endl;
	    cout<<"    |           1.��ѯ������Ϣ                           |"<<endl;
		cout<<"    |           2.���ߵ�¼                               |"<<endl;
		cout<<"    |           3.����Ա��¼               ��Ȩ������Ȩ�ؾ� |"<<endl;
		cout<<"    ------------------------------------------------------\n";
    	cout<<"               ��ѡ��1/2/3,-1Ϊ��������";
    	cin>>i1;
		system("cls");
		switch(i1)
		{
		    case 1:
			  while(i!=-1)
			  {
				  fh=0;
				  cout<<"--------------����ҽзָ���--------------------\n";
				  cout<<"1.��ʾ���пγ���Ϣ������"<<endl;
				  cout<<"2.����"<<endl;
				  cout<<"��ѡ��1/2,����-1�����ϲ�ṹ����"<<endl;
				   cin>>i;
				   system("cls");
				   switch(i){
				   case 1:{
				       courlist2.show();
                        courlist2.ultimatesort();
                        courlist2.show();
						   cout<<"�����������ַ���"<<endl;
			               cin>>fh;fh=-1;
			               system("cls");
				   }
			               break;

				   case 2:
					   courlist2.ultimatefind();system("cls");
						   break;
                   case -1:break;
				   }
			  }
			  break;
    case 2:
            curstudent=stulist2.login();
            if(curstudent==NULL){break;}
            while(i1!=-1){
            cout<<"--------------����ҽзָ���--------------------\n";
				  cout<<"1.��ʾ������Ϣ"<<endl;
				  cout<<"2.��ʾ�Ѿ�ѡ��Ŀγ�"<<endl;
				  cout<<"3.��ѯ"<<endl;
				  cout<<"4.��������ѡ�λ���ѡ"<<endl;
				  cout<<"5.�޸�����"<<endl;
				  cout<<"��ѡ��1/2/3/4/5,����-1�����ϲ�ṹ����"<<endl;
				  cin>>i1;
				  switch(i1)
				  {
				      case 1:curstudent->display();cout<<"�������������ַ���";cin>>i3;system("cls");break;
				      case 2:for(j=0;j<curstudent->getcounting();j++){
				          courlist2.findnumber(curstudent->subject[j])->display();
				      }cout<<"�������������ַ���";cin>>i3;system("cls");break;
				      case 3:courlist2.ultimatefind();cout<<"�������������ַ���";cin>>i3;system("cls");break;
				      case 4:cout<<"��������:";cin>>linshi;curstudent->choosecourse(linshi);system("cls");
				      cout<<"�������������ַ���";cin>>i3;break;
				      case 5:curstudent->changepassword();cout<<"�������������ַ���";cin>>i3;system("cls");break;
				      case -1:break;
				  }
				  system("cls");
            }
			system("cls");
		    break;
       case 3:
           if(!manager2.login()){break;}
           while(i2!=-1)
       {
           cout<<"--------------����ҽзָ���--------------------\n";
           cout<<"1.��ʾ���пγ���Ϣ"<<endl;
           cout<<"2.���ҿγ�,����֮��ɽ����޸ģ�ɾ������"<<endl;
           cout<<"3.��ӿγ�"<<endl;
           cout<<"4.�޸�����"<<endl;
           cout<<"5.�޸�ѧ��"<<endl;
           cout<<"6.ɾ��ѧ��"<<endl;
           cout<<"7.���ѧ��"<<endl;
           cout<<"��ѡ��1/2/3,����-1�����ϲ�ṹ����"<<endl;
           cin>>i2;
           system("cls");
           switch(i2){
               case 1:courlist2.show();cout<<"�������������ַ���"<<endl;
               cin>>fh;fh=-1;break;
               case 2:courlist2.ultimatefind();
               cout<<"1.�޸Ŀγ���Ϣ"<<endl;
               cout<<"2.ɾ���γ���Ϣ"<<endl;
               cout<<"��ѡ��1/2,����-1�����ϲ�ṹ����"<<endl;
               cin>>i4;
               while(i4!=-1)
               {
                   if(i4==1){
                    cout<<"������Ҫ�޸ĵĿγ̵ı��";
                    cin>>linshi;
                    test=courlist2.findnumber(linshi);
                    cout<<"׼��Ҫ�޸ĸ���";
                    test->display();
                    courlist2.change(test);
                    cout<<"�����ɹ�"<<endl;
                   }
                   else if(i4==2){
                        cout<<"������Ҫɾ���Ŀγ̵ı��";
                        cin>>linshi;
                        cout<<"׼��ɾ������";
                        courlist2.findnumber(linshi)->display();
                        stulist2.deletenumber(linshi);//ɾ������ѧ���й�������Ϣ��
                        courlist2.removecourse(linshi);
                        cout<<"�����ɹ�"<<endl;
                   }
                   else{}
               cout<<"�������������ַ���"<<endl;
               cin>>fh;system("cls");fh=-1;break;
               }
               break;
               case 3:{
                   cout<<"�������¿γ̵ı�ţ����֣��ον�ʦ��ѧ�֣��γ����ʣ�����ѧԺ";
               cin>>nmb>>couname>>teac>>sco>>nat>>fa;
               course co1(nmb,couname,teac,sco,nat,fa,0,0);
               courlist2.add(co1);
               cout<<"�����ɹ�"<<endl;
               cout<<"�������������ַ���"<<endl;
               cin>>fh;system("cls");fh=-1;
               }break;
               case 4:manager2.shiftpass();
               cout<<"�������������ַ���"<<endl;;
               cin>>fh;system("cls");fh=-1;break;
               case 5:cout<<"������Ҫ�޸ĵ�ѧ������";cin>>zaiti;
               stulist2.changedata(zaiti);
               cout<<"�������������ַ���"<<endl;
               cin>>fh;system("cls");fh=-1;break;
               case 6:cout<<"������Ҫɾ����ѧ������";cin>>zaiti;
               stulist2.deletedata(zaiti);
               cout<<"�������������ַ���"<<endl;
               cin>>fh;system("cls");fh=-1;break;
               case 7:{cout<<"��������ѧ����ѧ�ţ����������䣬��ѧʱ�䣬����"<<endl;
               cin>>id>>stuname>>ag>>enro>>pass;
               student rea2(id,stuname,ag,enro,pass);
               stulist2.addstu(rea2);
               cout<<"�������������ַ���"<<endl;
               cin>>fh;system("cls");fh=-1;break;
               }

               case -1:break;
           }
           break;


       }

	  case -1:
		hope=-1;break;

	default:

		cout<<"�������"<<endl;
		break;

		}
	}
	courlist2.write();
	stulist2.write();
	cout<<"ллʹ��";
	return 0;

}

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
    int ag,enro,cting;int a[50];//学生用
    int nmb,cur,mape;
    string couname,fa,teac,nat;
    double sco;//课程用
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
    int hope=1;//判定是否结束
    while(hope!=-1)
    {
        i1=0;i2=0;
		i=0;i4=0;
		cout<<"    ------------------------------------------------------\n";
		cout<<"    |           欢迎进入学校开课查询系统                 |"<<endl;
	    cout<<"    |           1.查询开课信息                           |"<<endl;
		cout<<"    |           2.读者登录                               |"<<endl;
		cout<<"    |           3.管理员登录               版权所有侵权必究 |"<<endl;
		cout<<"    ------------------------------------------------------\n";
    	cout<<"               请选择（1/2/3,-1为结束）：";
    	cin>>i1;
		system("cls");
		switch(i1)
		{
		    case 1:
			  while(i!=-1)
			  {
				  fh=0;
				  cout<<"--------------你好我叫分割线--------------------\n";
				  cout<<"1.显示所有课程信息与排序"<<endl;
				  cout<<"2.查找"<<endl;
				  cout<<"请选择（1/2,输入-1返回上层结构）："<<endl;
				   cin>>i;
				   system("cls");
				   switch(i){
				   case 1:{
				       courlist2.show();
                        courlist2.ultimatesort();
                        courlist2.show();
						   cout<<"输入任意数字返回"<<endl;
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
            cout<<"--------------你好我叫分割线--------------------\n";
				  cout<<"1.显示个人信息"<<endl;
				  cout<<"2.显示已经选择的课程"<<endl;
				  cout<<"3.查询"<<endl;
				  cout<<"4.按输入编号选课或退选"<<endl;
				  cout<<"5.修改密码"<<endl;
				  cout<<"请选择（1/2/3/4/5,输入-1返回上层结构）："<<endl;
				  cin>>i1;
				  switch(i1)
				  {
				      case 1:curstudent->display();cout<<"请输入任意数字返回";cin>>i3;system("cls");break;
				      case 2:for(j=0;j<curstudent->getcounting();j++){
				          courlist2.findnumber(curstudent->subject[j])->display();
				      }cout<<"请输入任意数字返回";cin>>i3;system("cls");break;
				      case 3:courlist2.ultimatefind();cout<<"请输入任意数字返回";cin>>i3;system("cls");break;
				      case 4:cout<<"请输入编号:";cin>>linshi;curstudent->choosecourse(linshi);system("cls");
				      cout<<"请输入任意数字返回";cin>>i3;break;
				      case 5:curstudent->changepassword();cout<<"请输入任意数字返回";cin>>i3;system("cls");break;
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
           cout<<"--------------你好我叫分割线--------------------\n";
           cout<<"1.显示所有课程信息"<<endl;
           cout<<"2.查找课程,查找之后可进行修改，删除操作"<<endl;
           cout<<"3.添加课程"<<endl;
           cout<<"4.修改密码"<<endl;
           cout<<"5.修改学生"<<endl;
           cout<<"6.删除学生"<<endl;
           cout<<"7.添加学生"<<endl;
           cout<<"请选择（1/2/3,输入-1返回上层结构）："<<endl;
           cin>>i2;
           system("cls");
           switch(i2){
               case 1:courlist2.show();cout<<"请输入任意数字返回"<<endl;
               cin>>fh;fh=-1;break;
               case 2:courlist2.ultimatefind();
               cout<<"1.修改课程信息"<<endl;
               cout<<"2.删除课程信息"<<endl;
               cout<<"请选择（1/2,输入-1返回上层结构）："<<endl;
               cin>>i4;
               while(i4!=-1)
               {
                   if(i4==1){
                    cout<<"请输入要修改的课程的编号";
                    cin>>linshi;
                    test=courlist2.findnumber(linshi);
                    cout<<"准备要修改该项";
                    test->display();
                    courlist2.change(test);
                    cout<<"操作成功"<<endl;
                   }
                   else if(i4==2){
                        cout<<"请输入要删除的课程的编号";
                        cin>>linshi;
                        cout<<"准备删除该项";
                        courlist2.findnumber(linshi)->display();
                        stulist2.deletenumber(linshi);//删除所有学生中关联的信息；
                        courlist2.removecourse(linshi);
                        cout<<"操作成功"<<endl;
                   }
                   else{}
               cout<<"请输入任意数字返回"<<endl;
               cin>>fh;system("cls");fh=-1;break;
               }
               break;
               case 3:{
                   cout<<"请输入新课程的编号，名字，任课教师，学分，课程性质，开课学院";
               cin>>nmb>>couname>>teac>>sco>>nat>>fa;
               course co1(nmb,couname,teac,sco,nat,fa,0,0);
               courlist2.add(co1);
               cout<<"操作成功"<<endl;
               cout<<"请输入任意数字返回"<<endl;
               cin>>fh;system("cls");fh=-1;
               }break;
               case 4:manager2.shiftpass();
               cout<<"请输入任意数字返回"<<endl;;
               cin>>fh;system("cls");fh=-1;break;
               case 5:cout<<"请输入要修改的学生号码";cin>>zaiti;
               stulist2.changedata(zaiti);
               cout<<"请输入任意数字返回"<<endl;
               cin>>fh;system("cls");fh=-1;break;
               case 6:cout<<"请输入要删除的学生号码";cin>>zaiti;
               stulist2.deletedata(zaiti);
               cout<<"请输入任意数字返回"<<endl;
               cin>>fh;system("cls");fh=-1;break;
               case 7:{cout<<"请输入新学生的学号，姓名，年龄，入学时间，密码"<<endl;
               cin>>id>>stuname>>ag>>enro>>pass;
               student rea2(id,stuname,ag,enro,pass);
               stulist2.addstu(rea2);
               cout<<"请输入任意数字返回"<<endl;
               cin>>fh;system("cls");fh=-1;break;
               }

               case -1:break;
           }
           break;


       }

	  case -1:
		hope=-1;break;

	default:

		cout<<"输入错误"<<endl;
		break;

		}
	}
	courlist2.write();
	stulist2.write();
	cout<<"谢谢使用";
	return 0;

}

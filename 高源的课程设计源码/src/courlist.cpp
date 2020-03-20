#include "courlist.h"
#include<iostream>
#include<fstream>
courlist::courlist()
{
    head=NULL;
    size=0;
}

courlist::~courlist()
{
    //dtor
}

void courlist::add(course &cou)
{
    course *cou1=new course(cou);
    if(head==NULL){head=cou1;size++;return;}
    course *p=head;
    while(p->next!=NULL){p=p->next;}
    p->next=cou1;size++;return;
}
//-------------以下为查找函数-------------------
course *courlist::findnumber(int no)
{
    course *p=head;
    while(p->getnumber()!=no&&p->next!=NULL){p=p->next;}
    if(p->getnumber()==no){return p;}
    else{cout<<"无此课"<<endl;}
    return NULL;
}
void courlist::findname(string n)
{
    course *p=head;
    while(p!=NULL)
    {
        if(p->getname()==n){p->display();}
        p=p->next;
    }
}
void courlist::findfaculty(string f)
{
    course *p=head;
    while(p!=NULL)
    {
        if(p->getfaculty()==f){p->display();}
        p=p->next;
    }
}
void courlist::findteacher(string t)
{
    course *p=head;
    while(p!=NULL)
    {
        if(p->getteacher()==t){p->display();}
        p=p->next;
    }
}

void courlist::show()
{
    course *p=head;
    while(p!=NULL){p->display();p=p->next;}
}
void courlist::ultimatefind()
{
    int order;int linshi;string zaiti;
    cout<<"--------------你好我叫分割线--------------------\n";
    cout<<"1.按编号查找"<<endl;
    cout<<"2.按课程名称查找"<<endl;
    cout<<"3.按教师名称查找"<<endl;
    cout<<"4.按院系名称查找"<<endl;
    cout<<"请选择（1/2/3/4,输入-1返回上层结构）："<<endl;
    cin>>order;
    switch(order)
    {
    case 1:cout<<"请输入编号:";cin>>linshi;findnumber(linshi)->display();break;
    case 2:cout<<"请输入课程名:";cin>>zaiti;findname(zaiti);break;
    case 3:cout<<"请输入教师名:";cin>>zaiti;findteacher(zaiti);break;
    case 4:cout<<"请输入院系:";cin>>zaiti;findfaculty(zaiti);break;
    }
    cout<<"请输入任意数字返回";
    cin>>order;return;
}

void courlist::write()
{
    ofstream outcourse("course.txt");
    course *p=head;
    while(p!=NULL)
    {
        outcourse<<p->getnumber()<<" "<<p->getname()<<" "<<p->getteacher()
        <<" "<<p->getscore()<<" "<<p->getnature()<<" "<<p->getfaculty()
        <<" "<<p->getcur()<<" "<<p->getmaxp()<<endl;
        p=p->next;
    }
    outcourse.close();
}

void courlist::sortscore()
{
  course temp(80,"test","aliean",7,"选修","虚空",9,10);
  course *p1,*p2;
  for(p1=head;p1->next!=NULL;p1=p1->next)
  {
      for(p2=p1->next;p2!=NULL;p2=p2->next)
      {
          if(p1->getscore()>p2->getscore())
          {
              temp=(*p1);
              (*p1)=(*p2);
              (*p2)=temp;
          }
      }
  }
}

void courlist::sortfaculty()
{

  course temp(-1,"test","aliean",0,"选修","虚空",0,0);
  course *p1,*p2;
  for(p1=head;p1->next!=NULL;p1=p1->next)
  {
      for(p2=p1->next;p2!=NULL;p2=p2->next)
      {
          if(p1->getfaculty()>p2->getfaculty())
          {
              temp=(*p1);
              (*p1)=(*p2);
              (*p2)=temp;
          }
      }
  }
}
void courlist::ultimatesort()
{
    int m;
    cout<<"--------------你好我叫分割线--------------------\n";
    cout<<"1.按学分进行排序"<<endl;
    cout<<"2.按开课院系进行排序"<<endl;
    cout<<"请选择（1/2,输入-1返回上层结构）："<<endl;
    cin>>m;
    system("cls");
    switch(m)
    {
        case 1:sortscore();break;
        case 2:sortfaculty();break;
        case -1:break;
    }
}


void courlist::change(course *target)
{
    cout<<"请输入新的名字，教师名字，学分，课程性质，开课学院，"<<endl;
    string nm,tnm,natu,fa;
    double s;
    cin>>nm>>tnm>>s>>natu>>fa;
    target->shift(nm,tnm,s,natu,fa);
    cout<<"修改成功"<<endl;
}
void courlist::removecourse(int no)
{
    course *pre=head;
    course *p=head;
    if(p->getnumber()==no)
    {
        head=p->next;
        pre->~course();
        return;
    }
    p=p->next;
    while(p!=NULL)
    {
        if(p->getnumber()==no){pre->next=p->next;p->~course();return;}
        p=p->next;
        pre=p->next;
    }
    cout<<"无此课"<<endl;

}


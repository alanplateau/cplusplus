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
//-------------����Ϊ���Һ���-------------------
course *courlist::findnumber(int no)
{
    course *p=head;
    while(p->getnumber()!=no&&p->next!=NULL){p=p->next;}
    if(p->getnumber()==no){return p;}
    else{cout<<"�޴˿�"<<endl;}
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
    cout<<"--------------����ҽзָ���--------------------\n";
    cout<<"1.����Ų���"<<endl;
    cout<<"2.���γ����Ʋ���"<<endl;
    cout<<"3.����ʦ���Ʋ���"<<endl;
    cout<<"4.��Ժϵ���Ʋ���"<<endl;
    cout<<"��ѡ��1/2/3/4,����-1�����ϲ�ṹ����"<<endl;
    cin>>order;
    switch(order)
    {
    case 1:cout<<"��������:";cin>>linshi;findnumber(linshi)->display();break;
    case 2:cout<<"������γ���:";cin>>zaiti;findname(zaiti);break;
    case 3:cout<<"�������ʦ��:";cin>>zaiti;findteacher(zaiti);break;
    case 4:cout<<"������Ժϵ:";cin>>zaiti;findfaculty(zaiti);break;
    }
    cout<<"�������������ַ���";
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
  course temp(80,"test","aliean",7,"ѡ��","���",9,10);
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

  course temp(-1,"test","aliean",0,"ѡ��","���",0,0);
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
    cout<<"--------------����ҽзָ���--------------------\n";
    cout<<"1.��ѧ�ֽ�������"<<endl;
    cout<<"2.������Ժϵ��������"<<endl;
    cout<<"��ѡ��1/2,����-1�����ϲ�ṹ����"<<endl;
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
    cout<<"�������µ����֣���ʦ���֣�ѧ�֣��γ����ʣ�����ѧԺ��"<<endl;
    string nm,tnm,natu,fa;
    double s;
    cin>>nm>>tnm>>s>>natu>>fa;
    target->shift(nm,tnm,s,natu,fa);
    cout<<"�޸ĳɹ�"<<endl;
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
    cout<<"�޴˿�"<<endl;

}


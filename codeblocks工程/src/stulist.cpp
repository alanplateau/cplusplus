#include "stulist.h"
#include"student.h"
#include<iostream>
#include<fstream>
stulist::stulist()
{
    size=0;
    head=NULL;
}

stulist::~stulist()
{
    //dtor
}
void stulist::addstu(student &stu2)//������ĩβ����
{
    student *stu3=new student(stu2);
    if(head==NULL){head=stu3;size++;return;}
    student *p=head;
    while(p->next!=NULL){p=p->next;}
    p->next=stu3;size++;return;

}
student *stulist::search(string no)//����Ų���
{
    student *p=head;
    while(p->getid()!=no&&p->next!=NULL){p=p->next;}
    if(p->getid()==no){return p;}
    else{cout<<"�޴���"<<endl;}
    return NULL;

}
student * stulist::login()
{
    string xuehao,mima;
    cout<<"������ѧ��:";
    cin>>xuehao;
    cout<<"����������:";
    cin>>mima;
    student *p=head;
    while(p!=NULL)
    {
        if(p->getid()==xuehao&&p->getpassword()==mima){cout<<"��½�ɹ�"<<endl;return p;}
        p=p->next;
    }
    cout<<"��½ʧ��"<<endl;
    return NULL;
}
void stulist::write()
{
    int m;
    ofstream outstu("student.txt");
    student *p=head;
    while(p!=NULL)
    {
        outstu<<p->getid()<<" "<<p->getname()<<" "<<p->getage()
        <<" "<<p->getey()<<" "<<p->getpassword()<<" "<<p->getcounting()<<" ";
        for(m=0;m<p->getcounting();m++){outstu<<p->subject[m]<<" ";}
        outstu<<endl;
        p=p->next;
    }
    outstu.close();
}
void stulist::deletenumber(int no)
{
    int m;
    student *p=head;
    while(p!=NULL)
    {
        if(p->existcourse(no)!=-1)
        {
            m=p->existcourse(no);
            p->cover(m);
        }
        p=p->next;
    }
}
student *stulist::findstu(string no)
{
    student *p=head;
    while(p->getid()!=no&&p->next!=NULL){p=p->next;}
    if(p->getid()==no){return p;}
    else{cout<<"�޴˿�"<<endl;}
    return NULL;
}
void stulist::changedata(string no)
{
    string id,nm,pa;
    int a,ey;
    student *p2=findstu(no);
    cout<<"׼��Ҫ�޸ĸ���";
    p2->display();
    cout<<"������ѧ�ţ����������䣬��ѧʱ�䣬����"<<endl;
    cin>>id>>nm>>a>>ey>>pa;
    p2->setdata(id,nm,a,ey,pa);
    cout<<"�����ɹ�"<<endl;
    return ;

}
void stulist::deletedata(string no)
{
    student *p2=findstu(no);
    cout<<"׼��Ҫɾ������";
    p2->display();
   student *pre=head;
    student *p=head;
    if(p->getid()==no)
    {
        head=p->next;
        pre->~student();
        return;
    }
    p=p->next;
    while(p!=NULL)
    {
        if(p->getid()==no){pre->next=p->next;p->~student();return;}
        p=p->next;
        pre=p->next;
    }
    cout<<"�޴���"<<endl;

}

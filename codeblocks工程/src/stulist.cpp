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
void stulist::addstu(student &stu2)//向链表末尾插入
{
    student *stu3=new student(stu2);
    if(head==NULL){head=stu3;size++;return;}
    student *p=head;
    while(p->next!=NULL){p=p->next;}
    p->next=stu3;size++;return;

}
student *stulist::search(string no)//按编号查找
{
    student *p=head;
    while(p->getid()!=no&&p->next!=NULL){p=p->next;}
    if(p->getid()==no){return p;}
    else{cout<<"无此人"<<endl;}
    return NULL;

}
student * stulist::login()
{
    string xuehao,mima;
    cout<<"请输入学号:";
    cin>>xuehao;
    cout<<"请输入密码:";
    cin>>mima;
    student *p=head;
    while(p!=NULL)
    {
        if(p->getid()==xuehao&&p->getpassword()==mima){cout<<"登陆成功"<<endl;return p;}
        p=p->next;
    }
    cout<<"登陆失败"<<endl;
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
    else{cout<<"无此课"<<endl;}
    return NULL;
}
void stulist::changedata(string no)
{
    string id,nm,pa;
    int a,ey;
    student *p2=findstu(no);
    cout<<"准备要修改该项";
    p2->display();
    cout<<"请输入学号，姓名，年龄，入学时间，密码"<<endl;
    cin>>id>>nm>>a>>ey>>pa;
    p2->setdata(id,nm,a,ey,pa);
    cout<<"操作成功"<<endl;
    return ;

}
void stulist::deletedata(string no)
{
    student *p2=findstu(no);
    cout<<"准备要删除该项";
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
    cout<<"无此人"<<endl;

}

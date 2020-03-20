#include "student.h"
#include"courlist.h"
#include<iostream>
using namespace std;
student::student(string id,string nm,int a,int ey,string pa,int c,int *data)
{
    studentid=id;
    name=nm;
    age=a;
    enrollyear=ey;
    password=pa;
    next=NULL;
    counting=c;
    subject=new int[50];//��ѡ50��
    int i;
    for(i=0;i<c;i++){subject[i]=data[i];}
}
student::student(const student &stu1)
{
    studentid=stu1.studentid;
    name=stu1.name;
    age=stu1.age;
    enrollyear=stu1.enrollyear;
    password=stu1.password;
    next=NULL;
    counting=stu1.counting;
    subject=new int[50];
    int i;
    for(i=0;i<counting;i++)
    {
        subject[i]=stu1.subject[i];
    }
}

student::~student()
{
    delete []subject;
}
void student::display()
{
    cout<<"ѧ��"<<studentid<<endl;
    cout<<"����"<<name<<endl;
    cout<<"����"<<age<<endl;
    cout<<"��ѧ���"<<enrollyear<<endl;
}
void student::add(int temp)
{
    subject[counting]=temp;
    counting++;
}
string student::getid(){return studentid;}

string student::getname(){return name;}

int student::getage(){return age;}

int student::getey(){return enrollyear;}

string student::getpassword()
{
    return password;
}

int student::getcounting()
{
    return counting;
}
void student::changepassword()
{

    cout<<"�������µ�����:";
    cin>>password;
    cout<<"�ɹ�"<<endl;
}

int student::existcourse(int no)
{
    int i;
    for(i=0;i<counting;i++)
    {
        if(subject[i]==no)
        return i;
    }
    return -1;
}
void student::cover(int no)
{
    int i;
    for(i=no;i<counting-1;i++){subject[i]=subject[i+1];}
    counting--;
}

void student::choosecourse(int no)
{
    int j;
    if(existcourse(no)==-1)
    {
        cout<<"�Ƿ�Ҫ������ſ�,��������1����������-1"<<endl;
        cin>>j;
        if(j==-1){cout<<"�����ɹ�"<<endl;return;}
        else{add(no);return;}
    }
    else
    {
        cout<<"����ѡ�����ſΣ��Ƿ�Ҫȡ������������1����������-1"<<endl;
        cin>>j;
        if(j==-1){return;}
        else{cover(existcourse(no));cout<<"�����ɹ�"<<endl;}

    }

}
void student::setdata(string id,string na,int a,int ey,string pa)
{
    studentid=id;
    name=na;
    age=a;
    enrollyear=ey;
    password=pa;
}
student::student(string id,string nm,int a,int ey,string pa)
{
    studentid=id;
    name=nm;
    age=a;
    enrollyear=ey;
    password=pa;
    next=NULL;
    counting=0;
    subject=new int[50];//��ѡ50��
}


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
    subject=new int[50];//限选50门
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
    cout<<"学号"<<studentid<<endl;
    cout<<"名字"<<name<<endl;
    cout<<"年龄"<<age<<endl;
    cout<<"入学年份"<<enrollyear<<endl;
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

    cout<<"请输入新的密码:";
    cin>>password;
    cout<<"成功"<<endl;
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
        cout<<"是否要添加这门课,是请输入1，否请输入-1"<<endl;
        cin>>j;
        if(j==-1){cout<<"操作成功"<<endl;return;}
        else{add(no);return;}
    }
    else
    {
        cout<<"您已选了这门课，是否要取消，是请输入1，否请输入-1"<<endl;
        cin>>j;
        if(j==-1){return;}
        else{cover(existcourse(no));cout<<"操作成功"<<endl;}

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
    subject=new int[50];//限选50门
}


#include "course.h"
#include<iostream>
using namespace std;
course::course(int n,string na,string tenm,double s,string nt,string f,int cu,int ma)
{
    number=n;
    name=na;
    teachername=tenm;
    score=s;
    nature=nt;
    faculty=f;
    next=NULL;
    currentperson=cu;
    maxperson=ma;
}

course::~course()
{

}
void course::display()
{
    cout<<number<<' '<<name<<' '<<teachername<<' '<<score<<' '
    <<nature<<' '<<faculty<<' '<<"已选"<<currentperson<<"人"<<' '
    <<"最多可选"<<maxperson<<"人"<<endl;
}
void course::shift(string nm,string tnm,double s,string na,string fa)
{
    name=nm;teachername=tnm;score=s;
    nature=na;faculty=fa;
}
 course & course::operator=(course &c)
 {
     number=c.number;
     name=c.name;
     teachername=c.teachername;
     score=c.score;
     nature=c.nature;
     faculty=c.faculty;
     currentperson=c.currentperson;
     maxperson=c.maxperson;
     return *this;
 }

int course::getnumber(){return number;}

string course::getname(){return name;}

string course::getteacher(){return teachername;}

double course::getscore(){return score;}

string course::getfaculty(){return faculty;}

string course::getnature(){return nature;}

int course::getcur(){return currentperson;}

int course::getmaxp(){return maxperson;}




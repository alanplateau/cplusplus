#ifndef COURSE_H
#define COURSE_H
#include<string>
using namespace std;

class course
{
    public:
        course *next;//
        course(int,string,string,double,string,string,int ,int  );
        virtual ~course();
        void display();
        void shift(string nm,string tnm,double s,string na,string fa);
        course & operator =(course &c);
        int getnumber();
        string getname();
        string getteacher();
        double getscore();
        string getnature();
        string getfaculty();
        int getcur();
        int getmaxp();

    protected:
        int number;//课程编号
        string name;
        string teachername;//任课教师
        double score;//学分
        string nature;//课程性质
        string faculty;//开课院系
        int currentperson;//已选该课的人数
        int maxperson;//该科可选的最大人数
};

#endif // COURSE_H

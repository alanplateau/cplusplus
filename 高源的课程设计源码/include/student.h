#ifndef STUDENT_H
#define STUDENT_H
#include<string>
using namespace std;

class student
{
    public:
        student(string,string,int,int,string,int,int * );
        student(string,string,int,int,string);
        virtual ~student();
        void display();//展示个人信息
        void add(int temp);//将课程编号编入subject末尾
        student(const student &stu1);
        student *next;
        string getid();//得到学号
        string getname();
        int getage();
        int getey();
        string getpassword();
        int getcounting();
        void changepassword();//修改密码
        void choosecourse(int no);//选课或取消已选的课
        int existcourse(int no);
        void cover(int no);//从no后开始一个一个往前移
        int *subject;//存放学生所选课程的学生编号
        void setdata(string id,string na,int a,int ey,string pa);
    protected:
        string studentid;//学号
        string name;
        int age;
        int enrollyear;//入学年份
        string password;//密码
        int counting;//已选课科目数量
};

#endif // STUDENT_H

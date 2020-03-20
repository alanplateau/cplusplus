#ifndef COURLIST_H
#define COURLIST_H
#include"course.h"

class courlist
{
    public:
        courlist();
        virtual ~courlist();
        void add(course &cou);//向末尾插入
        course *findnumber(int no);//按编号查找
        void findname(string n);//按名字查找
        void findfaculty(string f);//按院系查找
        void findteacher(string t);//按教师名字查找
        void ultimatefind();//集合所有查找
        void show();//展示所有课程信息
        void write();//写入文件
        void sortscore();//按学分排序
        void sortfaculty();//按开课学院排序
        void ultimatesort();//排序
        void change(course *target);
        void removecourse(int no);
    protected:
        course *head;
        int size;

};

#endif // COURLIST_H

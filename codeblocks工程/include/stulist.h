#ifndef STULIST_H
#define STULIST_H
#include"student.h"

class stulist
{
    public:
        stulist();
        virtual ~stulist();
        void addstu(student & stu2);
        student *search(string no);//°´±àºÅ²éÕÒ
        student * login();
        void write();
        student * findstu(string no);
        void deletenumber(int no);//删除所有选了no课的号码
        void changedata(string no);//修改特定学生数据
        void deletedata(string no);//删除特定学生

    protected:
        student *head;
        int size;

};

#endif // STULIST_H

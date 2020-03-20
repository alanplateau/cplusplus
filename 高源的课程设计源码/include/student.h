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
        void display();//չʾ������Ϣ
        void add(int temp);//���γ̱�ű���subjectĩβ
        student(const student &stu1);
        student *next;
        string getid();//�õ�ѧ��
        string getname();
        int getage();
        int getey();
        string getpassword();
        int getcounting();
        void changepassword();//�޸�����
        void choosecourse(int no);//ѡ�λ�ȡ����ѡ�Ŀ�
        int existcourse(int no);
        void cover(int no);//��no��ʼһ��һ����ǰ��
        int *subject;//���ѧ����ѡ�γ̵�ѧ�����
        void setdata(string id,string na,int a,int ey,string pa);
    protected:
        string studentid;//ѧ��
        string name;
        int age;
        int enrollyear;//��ѧ���
        string password;//����
        int counting;//��ѡ�ο�Ŀ����
};

#endif // STUDENT_H

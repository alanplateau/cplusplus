#ifndef COURLIST_H
#define COURLIST_H
#include"course.h"

class courlist
{
    public:
        courlist();
        virtual ~courlist();
        void add(course &cou);//��ĩβ����
        course *findnumber(int no);//����Ų���
        void findname(string n);//�����ֲ���
        void findfaculty(string f);//��Ժϵ����
        void findteacher(string t);//����ʦ���ֲ���
        void ultimatefind();//�������в���
        void show();//չʾ���пγ���Ϣ
        void write();//д���ļ�
        void sortscore();//��ѧ������
        void sortfaculty();//������ѧԺ����
        void ultimatesort();//����
        void change(course *target);
        void removecourse(int no);
    protected:
        course *head;
        int size;

};

#endif // COURLIST_H

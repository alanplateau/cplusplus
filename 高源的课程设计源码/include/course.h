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
        int number;//�γ̱��
        string name;
        string teachername;//�ον�ʦ
        double score;//ѧ��
        string nature;//�γ�����
        string faculty;//����Ժϵ
        int currentperson;//��ѡ�ÿε�����
        int maxperson;//�ÿƿ�ѡ���������
};

#endif // COURSE_H

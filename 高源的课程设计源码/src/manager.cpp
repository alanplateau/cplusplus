#include "manager.h"
#include"string"
#include<iostream>
manager::manager(string ac,string pass )
{
    account=ac;
    password=pass;
}

manager::~manager()
{
    //dtor
}
bool manager::login()
{
    string accou,pa;
    cout<<"�������˺�";cin>>accou;
    cout<<"����������";cin>>pa;
    if(accou==account&&password==pa)
    {
        cout<<"��½�ɹ�"<<endl;
        return true;
    }
    cout<<"��½ʧ��"<<endl;
    return false;
}
void manager::shiftpass()
{
    cout<<"�������µ�����";
    cin>>password;
    cout<<"�޸ĳɹ�"<<endl;
}

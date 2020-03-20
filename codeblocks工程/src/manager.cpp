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
    cout<<"ÇëÊäÈëÕËºÅ";cin>>accou;
    cout<<"ÇëÊäÈëÃÜÂë";cin>>pa;
    if(accou==account&&password==pa)
    {
        cout<<"µÇÂ½³É¹¦"<<endl;
        return true;
    }
    cout<<"µÇÂ½Ê§°Ü"<<endl;
    return false;
}
void manager::shiftpass()
{
    cout<<"ÇëÊäÈëÐÂµÄÃÜÂë";
    cin>>password;
    cout<<"ÐÞ¸Ä³É¹¦"<<endl;
}

#ifndef MANAGER_H
#define MANAGER_H
#include<string>
using namespace std;
class manager
{
    public:
        manager(string ,string);
        virtual ~manager();
        bool login();
        void shiftpass();

    protected:
        string account;
        string password;
};

#endif // MANAGER_H

#if !defined(BACKLOG_H)
#define BACKLOG_H

#include <string>
#include <fstream>
#include <iostream>
//#include <windows.h>
#include <unistd.h>


using namespace std;
class Backlog
{
private:
    int num_entries;
    string * entries;
public:
    Backlog(/* args */);
    ~Backlog();


    void add_entry();
    void await_entry();
    void write_entry(string entry);

};

char request();






#endif // BACKLOG_H

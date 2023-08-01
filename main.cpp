#include <string>
#include <fstream>
#include <iostream>
//#include <windows.h>
#include <unistd.h>
#include "backlog.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Backlog log = Backlog();

    ifstream fin;
    
    string pipeline_file = "storage_pipeline.txt";

    string check;
    while (true)
    {
        fin.open(pipeline_file.c_str());

        fin >> check;
        if (check == "add_entry")
        {
            log.add_entry();
            break;
        }
        else if (check == "view_backlog")
        {
            //
        }
        else if (check == "close_program")
        {
            break;
        }
        
        
        
    }
    
    return 0;
}

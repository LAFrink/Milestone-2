/******************************************************
** Program:
** Author: Lucas Frink
** Date: 
** Description: 
** Input: 
** Output: 
******************************************************/

// MAKE ADD TO BACKLOG

#include <string>
#include <fstream>
#include <iostream>
//#include <windows.h>
#include <unistd.h>
#include "backlog.h"



using namespace std;


Backlog::Backlog()
{
    
    ifstream fin;
    string backlog_file = "storage.txt";
    fin.open(backlog_file.c_str());
    fin >> this->num_entries;
    string temp_text;
    string * temp_arr = new string [this->num_entries];
    fin >> temp_text; // skip past first "*****"
    for (int i = 0; i < this->num_entries; i++)
    {
        fin >> temp_text;
        while (temp_text != "*****")
        {

            temp_arr[i] += temp_text + "\n";
            fin >> temp_text;
        }
    }
    this->entries = temp_arr;
    fin.close();
}


Backlog::~Backlog()
{
    if (this->entries != NULL){
		delete [] this->entries;
		this->entries = NULL;
	}
}
void Backlog::add_entry()
{
    string check;
    // ofstream fout;
    ifstream fin;
    string pipeline_file = "storage_pipeline.txt";


    await_entry();
    string new_entry;
    fin.open(pipeline_file.c_str());

    while (true)
    {
        fin >> check;
        if (check == "end_file")
        {
            break;
        }
        new_entry += check + "\n";
    }
    
    write_entry(new_entry);
}


void Backlog::await_entry()
{
    string check;
    ofstream fout;
    ifstream fin;
    string pipeline_file = "storage_pipeline.txt";

    fout.open(pipeline_file.c_str());

    fout << "send_entry";

    fout.close();

    while (true)
    {
        cout << endl << "go";
        sleep(10);
        fin.open(pipeline_file.c_str());
        fin >> check;
        fin.close();
        if (check != "send_entry")
        {
            break;
        }
    }
}

void Backlog::write_entry(string new_entry)
{
    ofstream fout;
    string backlog_file = "storage.txt";

    this->num_entries++;
    fout << this->num_entries;

    string temp_text;


    string * temp_arr = new string [this->num_entries];


    temp_arr[0] = new_entry;

    for (int i = 1; i < this->num_entries; i++)
    {
        temp_arr[i] = this->entries[i-1];
    }
    delete [] this->entries;
    this->entries = temp_arr;



    fout.open(backlog_file.c_str());
    fout << "\n*****\n";
    fout << new_entry;
    for (int i = 1; i < this->num_entries; i++)
    {
        fout << "*****\n";
        fout << this->entries[i-1];
    }
    fout << "*****\n";
    fout.close();

}

// This function is not part of the class
char request()
{
    char answer;
    cout << "Would you like to receive previous entries? (Y - yes | N - no)";

    cout << endl << "Your Choice: ";
    cin >> answer;
    answer = toupper(answer);
    while (answer != 'Y' && answer != 'N')
    {
        cout << endl << "Error: Enter Y or N." << endl;
        answer = request();
        cin.clear();
    }
    return answer;
}
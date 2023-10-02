#include<bits/stdc++.h>
#include<fstream>
#include "dostrap.hpp"

using namespace std;

void render(vector<string> &tasks)
{
    tasks.clear();

    ifstream readFile("database.txt");

    string line;

    readFile.seekg(0);

    while(getline(readFile,line))
    {
        tasks.push_back(line);
    }

    readFile.close();
}

void addTask(vector<string> &tasks)
{
    dostrap d;

    system("cls");

    fstream writeFile("database.txt", ios::in | ios::out | ios::app);

    d.heading("  Add New Task Here :",50,6,8);

    string line;

    cout<<">> ";
    getline(cin,line);

    cin.ignore();

    writeFile<<line<<endl;
    writeFile.close();

    d.prompt("Task added successfully",50);
    return;
}

void removeTask(vector<string> &tasks, int index)
{
    dostrap d;

    system("cls");

    d.heading("This Task :",50,6,8);
    cout<<"  "<<tasks[index]<<endl;
    d.warning("Has been removed!",50);

    ofstream writeFile("database.txt");

    for(int i=0;i<tasks.size();i++)
    {
        if(i!=index)
        {
            writeFile<<tasks[i]<<endl;
        }
    }

    writeFile.close();
    system("pause");
}

int main()
{
    dostrap d;

    SetConsoleTitleA("To-Do App - by Rohan Sapkal");

    int index=-1;
    char key;
    string action;
    vector<string> tasks;

    while(1)
    {
        render(tasks);

        d.title("To Do App",30,30,'=',6);
        if(index==-1)
        {
            d.cooltext("  Add new task    ",224);
            action = "Add Task";
        }else
        {
            d.cooltext("  Add new task    ",15);
            action = "Remove Task";
        }
        d.br(70,'-',15);

        for(int i=0;i<tasks.size();i++)
        {
            if(index!=i)
            {
                d.cooltext("  "+tasks[i]+"  ",15);
                cout<<endl;
            }else
            {
                d.cooltext("  "+tasks[i]+"  ",224);
                cout<<endl;
            }
        }

        d.br(70,'-',6);

        d.cooltext("  use <SPACE> to "+action,8);

        key = getch();

        if(key==72)
        {
            index--;
            if(index<-1){index = tasks.size()-1;}
        }

        if(key==80)
        {
            index++;
            if(index==tasks.size()){index = -1;}
        }

        if(key==32)
        {
            if(index==-1)
            {
                addTask(tasks);
            }else
            {
                removeTask(tasks,index);
                index = -1;
            }
        }
        system("cls");
    }

    return 0;
}

#ifndef DOSTRAP_HPP
#define DOSTRAP_HPP

#include<iostream>
#include<string.h>
#include<windows.h>
#include<conio.h>

using namespace std;

class globalVar
{
    protected:
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        int defCol = 15; // to set default colour
};

//============================================================================================================

class menubars : protected globalVar
{

    public:

        int menubar1(string title, vector<string> options);
};

int menubars::menubar1(string title, vector<string> options) // menubar 1
{
    int len=60;
    int index=0;
    char key;

    options.push_back("Exit"); // compulsary exit option for ux

    title.size()>=len ? len+=4 : len+=0;

    string line(len,'='); // line style

    while(1)
    {
        string spaces(len-title.size()-3,' '); // title spaces

        SetConsoleTextAttribute(h,11);
        cout<<line<<endl;

        SetConsoleTextAttribute(h,defCol);
        cout<<"  "<<title;// show title

        SetConsoleTextAttribute(h,11);
        cout<<spaces<<'|'<<endl;

        SetConsoleTextAttribute(h,11);
        cout<<line<<endl;

        string emptyline(len-1,' ');// make gaps for options i.e(line height).


        for(int i=0;i<options.size();i++)
        {
            SetConsoleTextAttribute(h,11);
            cout<<emptyline<<'|'<<endl;

            if(index!=i)
            {
                SetConsoleTextAttribute(h,defCol);
                cout<<"  "<<options[i]<<"  ";

                SetConsoleTextAttribute(h,11);
                string spaces2(len-(options[i].size()+5),' ');// non hovered option spaces
                cout<<spaces2<<'|'<<endl;

                SetConsoleTextAttribute(h,defCol);
            }
            else
            {
                SetConsoleTextAttribute(h,31);
                cout<<"    "<<options[i]<<"    ";

                SetConsoleTextAttribute(h,11);
                string spaces2(len-(options[i].size()+9),' '); // hovered option spaces
                cout<<spaces2<<'|'<<endl;

                SetConsoleTextAttribute(h,defCol);
            }
        }

        SetConsoleTextAttribute(h,11);
        cout<<emptyline<<'|'<<endl;
        cout<<line<<endl;

        SetConsoleTextAttribute(h,8);
        cout<<"  use <SPACE> to select option";

        string spaces3(len-31,' '); // spaces for msg -> use <SPACE> ...

        SetConsoleTextAttribute(h,11);

        cout<<spaces3<<'|'<<endl;
        cout<<line<<endl;

        key = getch();

        if(key==72) // ASCII value for UP key
        {
            index--;
            if(index<0){index = options.size()-1;}
        }

        if(key==80) // same for DOWN key
        {
            index++;
            if(index>= options.size()){index=0;}
        }

        if(key==32){ // also for <SPACE>

            SetConsoleTextAttribute(h,defCol); // reset to default (user's) selected colour

            if(index == options.size()-1)
            {
                return -1; // for exit;
            }
            else
            {
                return index;
            }
        }
        system("cls");
    }
}

//==================================================================================================================
class dostrap : protected globalVar
{

    public :
        void br(int len, char sy, int col);

        void cooltext(string text, int col);

        void heading(string label, int len, int text_col, int line_col);

        void label(string text, int col);
        void loading(int len, int speed);

        void notify(string msg, int len);

        void processing(int len, int speed);
        void prompt(string msg, int len);

        void set_def_col(int col);

        void title(string label, int lp, int rp, char sy, int col);
        void title2(string label, int lp, int rp, char sy, int line_col, int text_col);

        void warning(string msg, int len);
};

void dostrap::br(int len, char sy, int col)
{
    string breakline(len,sy);

    SetConsoleTextAttribute(h,col);
    cout<<breakline<<endl;
    SetConsoleTextAttribute(h,defCol);
}

void dostrap::cooltext(string text, int col)
{
    SetConsoleTextAttribute(h,col);
    cout<<text<<endl;
    SetConsoleTextAttribute(h,defCol);
}

void dostrap::heading(string label, int len, int text_col, int line_col)
{
    string line(len,'-');
    SetConsoleTextAttribute(h,text_col);
    cout<<"  "<<label<<endl;
    SetConsoleTextAttribute(h,line_col);
    cout<<line<<endl;
    SetConsoleTextAttribute(h,defCol);
}

void dostrap::label(string text, int col)
{
    SetConsoleTextAttribute(h,col);
    cout<<"  "<<text<<"      "<<endl;
    SetConsoleTextAttribute(h,defCol);
}

void dostrap::loading(int len, int speed)
{
    string line(len,'-');
    SetConsoleTextAttribute(h,8);
    cout<<line<<endl;
    string spaces(len-12,' ');
    line.clear();
    line = "  Loading..."+spaces;

    SetConsoleTextAttribute(h,160);
    for(int i=0;i<len;i++){
        cout<<line[i];
        Sleep(speed);
    }
    cout<<endl;
    SetConsoleTextAttribute(h,defCol);
}

void dostrap::processing(int len, int speed)
{
    string line(len,'-');
    SetConsoleTextAttribute(h,8);
    cout<<line<<endl;
    string spaces(len-13,' ');
    line.clear();
    line = "  Processing..."+spaces;

    SetConsoleTextAttribute(h,48);
    for(int i=0;i<len;i++){
        cout<<line[i];
        Sleep(speed);
    }
    cout<<endl;
    SetConsoleTextAttribute(h,defCol);
}

void dostrap::prompt(string msg, int len)
{
    string line(len,'-');

    SetConsoleTextAttribute(h,10);
    cout<<line<<"\n\t"<<msg<<endl;
    SetConsoleTextAttribute(h,defCol);
    Sleep(2500);
}

void dostrap::set_def_col(int col)
{
    defCol = col;
    SetConsoleTextAttribute(h,defCol);
}

void dostrap::title(string label, int lp, int rp, char sy, int col)
{
    string lpad(lp,' ');
    string rpad(rp,' ');

    string text = lpad+label+rpad+'|';
    string line(text.size(),sy);

    SetConsoleTextAttribute(h,col);
    cout<<line<<"\n"<<text<<"\n"<<line<<endl;
    SetConsoleTextAttribute(h,defCol);
}

void dostrap::title2(string label, int lp, int rp, char sy, int line_col, int text_col)
{
    string lpad(lp,' ');
    string rpad(rp,' ');

    string text = lpad+label+rpad+' ';
    string line(text.size(),sy);

    SetConsoleTextAttribute(h,line_col);
    cout<<line<<endl;

    SetConsoleTextAttribute(h,text_col);
    cout<<text<<endl;

    SetConsoleTextAttribute(h,line_col);
    cout<<line<<endl;
    SetConsoleTextAttribute(h,defCol);
}

void dostrap::notify(string msg, int len)
{
    string line(len,'-');

    SetConsoleTextAttribute(h,6);
    cout<<line<<"\n\t"<<msg<<endl;
    SetConsoleTextAttribute(h,defCol);
    Sleep(2500);
}

void dostrap::warning(string msg, int len)
{
    string line(len,'-');

    SetConsoleTextAttribute(h,12);
    cout<<line<<"\n\t"<<msg<<endl;
    SetConsoleTextAttribute(h,defCol);
    Sleep(2500);
}
#endif // DOSTRAP_HPP

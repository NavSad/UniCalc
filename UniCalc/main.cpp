//
//  main.cpp
//  UniCalc
//
//  Created by NavSad on 12/31/20.
//

#include <iostream>
#include <curses.h>
#include <locale>
#include <unistd.h>
#include <time.h>
#include <form.h>
#include "calc.hpp"
#include "ui.hpp"

#define BACKSPACE 127
#define ENTER 10

using namespace std;

int main()
{
    //string buffer;
    vector<int> buffer;
    string input;
    //char buf[200];
    string con_buffer;
    double result;
    int ch;
    int row,col;
    int cur_row=0;
    int cur_col=0;
    initscr();
    cbreak();
    noecho();
    //curs_set(0);
    keypad(stdscr,TRUE);
    nodelay(stdscr, TRUE);
    getmaxyx(stdscr,row,col);
    setlocale(LC_ALL, "");
    WINDOW *pad=new_pad(row*10, col);
    WINDOW *sub=subpad(pad, row,col, 0, 0);
    wmove(sub,0,0);
    wclear(sub);
    wrefresh(sub);
    while(true)
    {
       /* //mvaddch(0,0, ACS_BLOCK|A_BLINK);
        refresh();
        if(getch()==ERR)
        {
            //mvaddch(0,0,ACS_BLOCK|A_BLINK);
            refresh();
            continue;
        }*/
        while(true)
        {
            ch=getch();
            switch(ch)
            {
                case ERR:
                    wrefresh(sub);
                    break;
                case BACKSPACE:
                    getyx(stdscr,cur_row,cur_col);
                    if(buffer.size()>0)
                    {
                        mvdelch(cur_row, cur_col-1);
                        buffer.pop_back();
                    }
                    break;
                case ENTER:
                    getyx(stdscr,cur_row,cur_col);
                    con_buffer=condense(buffer);
                    mvprintw(cur_row+1, 0, con_buffer.c_str());
                    result=calculate(con_buffer);
                    mvprintw(cur_row+2,0,"%d",result);
                    move(cur_row+3,0);
                    //Add more features
                    break;
                
                case KEY_LEFT:
                    getyx(stdscr,cur_row,cur_col);
                    if(cur_col==0)
                    {
                        cur_col=col;
                        move(cur_row,cur_col);
                        refresh();
                        break;
                    }
                    move(cur_row,cur_col-1);
                    refresh();
                    break;
                case KEY_RIGHT:
                    getyx(stdscr,cur_row,cur_col);
                    if(cur_col==col)
                    {
                        cur_col=0;
                        move(cur_row,cur_col);
                        refresh();
                        break;
                    }
                    move(cur_row,cur_col+1);
                    refresh();
                    break;
                case KEY_UP:
                    getyx(stdscr,cur_row,cur_col);
                    if(cur_row==0)
                    {
                        break;
                    }
                    move(cur_row-1,cur_col);
                    refresh();
                    break;
                case KEY_DOWN:
                    getyx(stdscr,cur_row,cur_col);
                    if(cur_row==row)
                    {
                        break;
                    }
                    move(cur_row+1,cur_col);
                    refresh();
                    break;
                default:
                    waddch(sub, ch);
                    buffer.push_back(ch);
                    break;
            }
        }
    }
    endwin();
    return 0;
}

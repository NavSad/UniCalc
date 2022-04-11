//
//  ui.cpp
//  UniCalc
//
//  Created by NavSad on 2/2/21.
//

#include "ui.hpp"
#include "calc.hpp"

WINDOW* new_window(int height,int width, int starty,int startx)
{
    WINDOW* win=newwin(height,width, starty, startx);
    return win;
}

WINDOW* new_pad(int nrows,int ncols)
{
    WINDOW* pad=newpad(nrows, ncols);
    return pad;
}

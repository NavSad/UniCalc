//
//  ui.hpp
//  UniCalc
//
//  Created by NavSad on 2/2/21.
//

#ifndef ui_hpp
#define ui_hpp

#include <stdio.h>
#include <ncurses.h>

WINDOW* new_window(int height,int width,int starty,int startx);

WINDOW* new_pad(int nrows, int ncols);

#endif /* ui_hpp */

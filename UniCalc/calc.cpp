//
//  calc.cpp
//  UniCalc
//
//  Created by NavSad on 1/23/21.
//

#include "calc.hpp"

std::string condense(std::vector<int>& buffer)
{
    std::string con_buffer;
    char ch;
    for(int i=0;i<buffer.size();i++)
    {
        ch=lookup_char(buffer.at(i));
        con_buffer+=ch;
    }
    buffer.clear();
    for(int i=0;i<con_buffer.size();i++)
    {
        
    }
    return con_buffer;
}

double calculate(std::string con_buffer)
{
    double result;
    return result;
}

char lookup_char(int con_ch)
{
    char ch;
    ch=char(con_ch);
    return ch;
}

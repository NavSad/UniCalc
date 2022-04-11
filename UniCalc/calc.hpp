//
//  calc.hpp
//  UniCalc
//
//  Created by NavSad on 1/23/21.
//

#ifndef calc_hpp
#define calc_hpp

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

std::string condense(std::vector<int>& buffer);

double calculate(std::string con_buffer);

char lookup_char(int con_ch);

#endif /* calc_hpp */

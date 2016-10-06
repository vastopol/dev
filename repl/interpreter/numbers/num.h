#ifndef __NUM_H__
#define __NUM_H__ 

#include <iostream>
#include <string>
#include <cmath>

class Num
{
    private:
        int val;        // value 
        std::string tag;// id associated with value
    
    public:
        Num();
        Num(int, std::string);
        ~Num();
        int getVal();
        std::string getTag();
};



#endif // __NUM_H__
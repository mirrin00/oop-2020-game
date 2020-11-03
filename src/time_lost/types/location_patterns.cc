#include "time_lost/types/location_patterns.h"

namespace time_lost{

namespace types{

const std::string LocationPatterns::patterns[LocationPatterns::count] = {
        //0
        "#####\
         0#0#0\
         00000\
         0#0#0\
         #####",
        //1
        "##0##\
         #000#\
         00#00\
         #000#\
         ##0##",
        //2
        "#####\
         00000\
         #####\
         00000\
         #####",
        //3
        "#0#0#\
         #0#0#\
         #0#0#\
         #0#0#\
         #0#0#",
        //4
        "00000\
         #00#0\
         00#00\
         0#00#\
         ###00",
        //5
        "##0##\
         0#00#\
         0#00#\
         00000\
         00000",
        //6
        "##000\
         ##000\
         00#00\
         000##\
         000##",
        //7
        "00#00\
         0#0#0\
         #000#\
         00000\
         #####"
    };

} // objects
} // time_lost
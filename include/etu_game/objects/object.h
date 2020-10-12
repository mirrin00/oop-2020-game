#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

#include "../logic/publisher.h"

namespace etu_game{

namespace objects{

class Object{
protected:
    int h_pos, w_pos;

    logic::Publisher pub;

    virtual void Notify();
public:
    Object(int start_h_pos = 0, int start_w_pos = 0);

    ~Object();

    Object(const Object& obj);

    Object& operator=(const Object& obj);

    int GetHeightPosition();

    int GetWidthPosition();

    void SetHeightPosition(int new_h_pos);

    void SetWidthPosition(int new_w_pos);

    friend std::ostream& operator<<(std::ostream& os, const Object& obj);
};

    std::ostream& operator<<(std::ostream& os, const Object& obj);

}
}

#endif // OBJECT_H
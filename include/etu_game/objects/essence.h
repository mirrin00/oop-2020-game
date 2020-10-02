#ifndef ESSENCE_H
#define ESSENCE_H

namespace etu_game {

namespace objects {

class Essence{
private:
    int h_pos, w_pos;

protected:
    int health;
    
public:
    Essence(int start_health, int start_h_pos = 0, int start_w_pos = 0);

    ~Essence();

    void Move(int on_height, int on_width);

    int GetHeightPosition();

    int GetWidthPosition();

    void SetHeightPosition(int new_h_pos);

    void SetWidhtPosition(int new_w_pos);
};

} // objects
} // etu_game

#endif // ESSENCE_INTERFACE_H
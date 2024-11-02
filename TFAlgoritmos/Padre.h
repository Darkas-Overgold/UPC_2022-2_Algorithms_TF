#pragma once
#include "time.h"
#include <iostream>
#include <vector>
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace std;
class Padre {
public:
    Padre(int w, int h); // nuestra principal clase es pare, luego?
    ~Padre();
    Rectangle Get_Rectangle();
    bool get_Visible();
    void set_Visible(bool v);
    int getX();
    int getY();
    int getwidth();
    int getheight();
protected: // aquí se da el polimorfismo 
    int x, y;
    int dx, dy;
    int height, width;
    int idX, idY;
    bool visible;
};
Padre::Padre(int w, int h)
{
    height = h; width = w;
    idX = 0; idY = 0;
    visible = true;
}
Padre::~Padre() {}
Rectangle Padre::Get_Rectangle() { return Rectangle(x, y, width, height); }
bool Padre::get_Visible() { return visible; }
void Padre::set_Visible(bool v) { visible = v; }
int Padre::getX() { return x; }
int Padre::getY() { return y; }
int Padre::getwidth() { return width; }
int Padre::getheight() { return height; }
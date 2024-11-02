#pragma once
#include "Padre.h"
class Enfermera :public Padre
{
public:
    Enfermera(int w, int h);
    ~Enfermera();
    void Mover(Graphics^ g);
    void Dibujar(Graphics^ g, Bitmap^ bmp);
};

Enfermera::Enfermera(int w, int h) :Padre(w, h)
{
    width = w;
    height = h;
    x = rand() % 400;
    y = rand() % 400;
    do
    {
        dx = dy = 5 - rand() % 7;
    } while (dx == 0 || dy == 0);
}
Enfermera::~Enfermera() {}
void Enfermera::Mover(Graphics^ g)
{

    if (dy < 0)
        idY = 2;
    if (dy > 0)
        idY = 1;
    if (dx > 0)
        idY = 0;
    if (dx < 0)
        idY = 3;
    if (x + dx<0 || x + dx + width>g->VisibleClipBounds.Width)
        dx *= -1;
    if (y + dy<0 || y + dy + height>g->VisibleClipBounds.Height)
        dy *= -1;
    x += dx;
    y += dy;

    idX++;
    if (idX == 3)idX = 0;
}

void Enfermera::Dibujar(Graphics^ g, Bitmap^ bmp)
{
    Rectangle sectionShow = Rectangle(idX * width, idY * height, width, height);
    Rectangle zoom = Rectangle(x, y, width, height);
    g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
    g->DrawRectangle(Pens::Transparent, Get_Rectangle());
}

#pragma once
#include "Padre.h"
class Tuberculosis :public Padre {
public:
    Tuberculosis(int w, int h);
    ~Tuberculosis();
    void Mover(Graphics^ g);
    void Dibujar(Graphics^ g, Bitmap^ bmp);
};
Tuberculosis::Tuberculosis(int w, int h) :Padre(w, h) {
    width = w;
    height = h;
    x = rand() % 400;
    y = rand() % 400;
    do {
        dx = dy = rand() % 10;
    } while (dx == 0 || dy == 0);
}
Tuberculosis::~Tuberculosis() {}
void Tuberculosis::Mover(Graphics^ g) {
    if (x + dx<0 || x + dx + width>g->VisibleClipBounds.Width)
        dx *= -1;
    if (y + dy<0 || y + dy + height>g->VisibleClipBounds.Height)
        dy *= -1;
    x += dx;
    y += dy;

    idX++;
    if (idX == 3)idX = 0;
}
void Tuberculosis::Dibujar(Graphics^ g, Bitmap^ bmp) {
    Rectangle sectionShow = Rectangle(idX * width, idY * height, width, height);
    Rectangle zoom = Rectangle(x, y, width, height);
    g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
    g->DrawRectangle(Pens::Transparent, Get_Rectangle());
}
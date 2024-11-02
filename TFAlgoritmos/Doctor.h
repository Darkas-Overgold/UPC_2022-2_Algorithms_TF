#pragma once
#include "Padre.h"
#include"Jeringa.h"
class Doctor :public Padre
{
public:
    Doctor(int w, int h);
    ~Doctor();
    void Mover(Graphics^ g, Keys tecla);
    void Dibujar(Graphics^ g, Bitmap^ bmp);
    void Restar_Vida();
    int Cant_vida();
    char getDirection();
    void jeringa(Graphics^ g, Bitmap^ bmp);
    void generar_jeringa(int w, int h, int x, int y, char d);
    Jeringa* getJeringa(int i);
    int getcant_jeringa();
private:
    int vida;
    char direction;
    vector<Jeringa*>vecJ;
};
Doctor::Doctor(int w, int h) :Padre(w, h)
{
    vecJ = vector<Jeringa*>();
    width = w;
    height = h;
    vida = 3;
    x = y = 300;
    dx = dy = 5;
    direction = 'S';
}
Doctor::~Doctor() {}
void Doctor::Mover(Graphics^ g, Keys tecla)
{
    switch (tecla)
    {
    case Keys::Right:
        idY = 2;
        if (x + width < g->VisibleClipBounds.Width)
            x += dx;
        direction = 'D';
        break;
    case Keys::Left:
        idY = 1;
        if (x > 0)
            x -= dx;
        direction = 'A';
        break;
    case Keys::Down:
        idY = 0;
        if (y + dy + height < g->VisibleClipBounds.Height)
            y += dy;
        direction = 'S';
        break;
    case Keys::Up:
        idY = 3;
        if (y > 0)
            y -= dy;
        direction = 'W';
    }
    idX++;
    if (idX == 3)idX = 0;
}
void Doctor::Dibujar(Graphics^ g, Bitmap^ bmp)
{
    Rectangle sectionShow = Rectangle(idX * width, idY * height, width, height);
    Rectangle zoom = Rectangle(x, y, width, height);
    g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
    g->DrawRectangle(Pens::Transparent, Get_Rectangle());
}

void Doctor::Restar_Vida() { vida--; }
int Doctor::Cant_vida() { return vida; }
char Doctor::getDirection() { return direction; }

void Doctor::jeringa(Graphics^ g, Bitmap^ bmp)
{
    for (int i = 0; i < vecJ.size(); i++)
    {
        vecJ.at(i)->Mover(g);
        vecJ.at(i)->Dibujar(g, bmp);
    }
    //eliminar balas cuando llegan a un extremo
    for (int i = 0; i < vecJ.size(); i++)
        if (vecJ.at(i)->getX() < 50 || vecJ.at(i)->getX() + vecJ.at(i)->getwidth() > g->VisibleClipBounds.Width
            || vecJ.at(i)->getY() < 0 || vecJ.at(i)->getY() + vecJ.at(i)->getheight() + 20 > g->VisibleClipBounds.Height)
            vecJ.erase(vecJ.begin() + i);
}
void Doctor::generar_jeringa(int w, int h, int x, int y, char d)
{
    vecJ.push_back(new Jeringa(w, h, x, y, d));
}

Jeringa* Doctor::getJeringa(int i)
{
    return  vecJ[i];
}

int Doctor::getcant_jeringa() { return vecJ.size(); }
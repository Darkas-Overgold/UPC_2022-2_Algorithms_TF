#include"Padre.h"
class Jeringa :public Padre
{
public:
	Jeringa(int w, int h, int _x, int _y, char d);
	~Jeringa();
	void Dibujar(Graphics^ g, Bitmap^ bmp);
	void Mover(Graphics^ g);
private:
	char direction;
};

Jeringa::Jeringa(int w, int h, int _x, int _y, char d) :Padre(w, h)
{
	width = w;
	height = h;
	x = _x;
	y = _y;
	direction = d;
	dx = dy = 10;
}
Jeringa::~Jeringa() {}
void Jeringa::Dibujar(Graphics^ g, Bitmap^ bmp)
{
	g->DrawImage(bmp, x, y, width, height);
	g->DrawRectangle(Pens::Transparent, Get_Rectangle());
}
void Jeringa::Mover(Graphics^ g)
{
	switch (direction)
	{
	case 'W':
		if (y >= 0)y -= dy;
		break;
	case 'S':
		if (y + height < g->VisibleClipBounds.Height)
			y += dy;
		break;
	case 'A':
		if (x > 0)x -= dx;
		break;
	case 'D':
		if (x + width < g->VisibleClipBounds.Width)
			x += dx;
	}
}

#pragma once
#include "Doctor.h"
#include "Tuberculosis.h"
#include "Enfermera.h"
class Juego
{
public:
    Juego(int bmpDoctor_ancho, int bmpDoctor_alto, int bmpEnemigo_ancho, int bmpEnemigo_alto, int bmpEnfermera_ancho, int bmpEnfermera_alto,
        int cantEnemigos, int niv);
    ~Juego();
    void Mover_Personaje(Graphics^ g, Keys tecla);
    void Dibujar_Todo(Graphics^ g, Bitmap^ bmpDoctor, Bitmap^ bmpEnemigo, Bitmap^ bmpEnfermera);
    void mover_todo(Graphics^ g, Bitmap^ bmpJeringa);
    void generar_enemigos(int bmpEnemigo_ancho, int bmpEnemigo_alto);
    void generar_enfermera(int bmpEnfermera_ancho, int bmpEnfermera_alto);
    void colision();
    void generar_jeringa(int w, int h);
    int devolver_cant_enemigo();
    void Muestra_Contadores(Graphics^ g);
    bool ganar_perder();
private:
    Doctor* objD;
    vector<Tuberculosis*>vecT;
    vector<Enfermera*>vecE;

    clock_t tiempo_eliminar;
    clock_t tiempo_juego;

    int cant_enemy;
    int nivel;
};

Juego::Juego(int bmpDoctor_ancho, int bmpDoctor_alto, int bmpEnemigo_ancho, int bmpEnemigo_alto, int bmpEnfermera_ancho, int bmpEnfermera_alto,
    int cantEnemigos, int niv)
{
    cant_enemy = cantEnemigos;
    nivel = niv;

    objD = new Doctor(bmpDoctor_ancho, bmpDoctor_alto);
    vecT = vector<Tuberculosis*>();
    vecE = vector<Enfermera*>();

    tiempo_eliminar = clock();
    tiempo_juego = clock();
    for (int i = 0; i < cant_enemy; i++)
        generar_enemigos(bmpEnemigo_ancho, bmpEnemigo_alto);

    for (int i = 0; i < 2; i++)
        generar_enfermera(bmpEnfermera_ancho, bmpEnfermera_alto);

}

Juego::~Juego() {}
void Juego::Mover_Personaje(Graphics^ g, Keys tecla)
{
    objD->Mover(g, tecla);
}
void Juego::mover_todo(Graphics^ g, Bitmap^ bmpJeringa)
{
    for (int i = 0; i < vecT.size(); i++)
        vecT.at(i)->Mover(g);

    for (int i = 0; i < vecE.size(); i++)
        vecE.at(i)->Mover(g);

    objD->jeringa(g, bmpJeringa);
}

void Juego::Dibujar_Todo(Graphics^ g, Bitmap^ bmpDoctor, Bitmap^ bmpEnemigo, Bitmap^ bmpEnfermera)
{
    objD->Dibujar(g, bmpDoctor);

    for (int i = 0; i < vecT.size(); i++)
        vecT.at(i)->Dibujar(g, bmpEnemigo);

    for (int i = 0; i < vecE.size(); i++)
        vecE.at(i)->Dibujar(g, bmpEnfermera);

}
void Juego::colision()
{
    //Verificar colision enfermera-enemigo
    for (int i = 0; i < vecE.size(); i++)
        for (int j = 0; j < vecT.size(); j++)
            if (vecE.at(i)->Get_Rectangle().IntersectsWith(vecT.at(j)->Get_Rectangle()))
                vecT.at(j)->set_Visible(false);

    //Verificar colision jeringa-enemigo
    for (int i = 0; i < vecT.size(); i++)
        for (int j = 0; j < objD->getcant_jeringa(); j++)
            if (vecT.at(i)->Get_Rectangle().IntersectsWith(objD->getJeringa(j)->Get_Rectangle()))
                vecT.at(i)->set_Visible(false);

    for (int i = 0; i < vecT.size(); i++)
        if (vecT.at(i)->Get_Rectangle().IntersectsWith(objD->Get_Rectangle()))
            if ((clock() - tiempo_eliminar) / CLOCKS_PER_SEC >= 3)
            {
                objD->Restar_Vida();
                tiempo_eliminar = clock();
            }
    //Eliminar jeringas
    for (int j = 0; j < vecT.size(); j++)
        if (!vecT.at(j)->get_Visible())
            vecT.erase(vecT.begin() + j);
}
void Juego::generar_enemigos(int bmpEnemigo_ancho, int bmpEnemigo_alto)
{
    vecT.push_back(new Tuberculosis(bmpEnemigo_ancho, bmpEnemigo_alto));
}
void Juego::generar_enfermera(int bmpEnfermera_ancho, int bmpEnfermera_alto)
{
    vecE.push_back(new Enfermera(bmpEnfermera_ancho, bmpEnfermera_alto));
}

void Juego::generar_jeringa(int w, int h)
{
    if (objD->getcant_jeringa() == 0 && nivel == 2)
        objD->generar_jeringa(w, h, objD->getX(), objD->getY(), objD->getDirection());

    if (nivel == 1)
        objD->generar_jeringa(w, h, objD->getX(), objD->getY(), objD->getDirection());
}

int Juego::devolver_cant_enemigo() { return vecT.size(); }

void Juego::Muestra_Contadores(Graphics^ g)
{
    g->DrawString("Enemigos: " + vecT.size(), gcnew Font("Arial", 12), Brushes::Red, 0, 60);
    g->DrawString("vida: " + objD->Cant_vida(), gcnew Font("Arial", 12), Brushes::Red, 0, 100);

    if (nivel == 2)
        g->DrawString("Tiempo: " + ((clock() - tiempo_juego) / CLOCKS_PER_SEC), gcnew Font("Arial", 12), Brushes::Red, 0, 20);
}

bool Juego::ganar_perder()
{
    if (nivel == 2 && (clock() - tiempo_juego) / CLOCKS_PER_SEC >= 30)return false;

    if (vecT.size() < 1)return false;
    return objD->Cant_vida() > 0;
}
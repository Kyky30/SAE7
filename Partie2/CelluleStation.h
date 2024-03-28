#pragma once
#include "Arbre.h"

#include <array>

struct CelluleStation
{
    int _ID; // numero identification station
    std::array<Arbre, 12> tab_arbres; // 1 arbre par mois
    CelluleStation* _pSuiv;
    CelluleStation* _pPred;



    CelluleStation(int ID = -1) : _ID{ ID }, _pSuiv{ nullptr }, _pPred{ nullptr } {}
};


#pragma once

#include <iostream>

#include "CelluleStation.h"
#include "ListeStation.h"
#include "CelluleArbre.h"
#include "Arbre.h"
#include <vector>

float somme_deltaT(Arbre ab);
float temperatureMoyenneMois(ListeStation lB, int mois);
float temperatureMoyenneAnnee(ListeStation lB);
float temperatureMaxMois(ListeStation lB, int month);
float temperatureMinMois(ListeStation lB, int month);
float temperatureMaxAnnee(ListeStation lB);
float temperatureMinAnnee(ListeStation lB);
float temperatureMoyenneSaison(ListeStation lB, int saison);
float parcoursAnnees(Arbre ab, int& nbStat);
float temperatureMoyenneToutesAnnees(ListeStation lB);

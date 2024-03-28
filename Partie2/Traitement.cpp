#include "Traitement.h"

//exemple de fonction pour l exploitation de la structure arborescente
float somme_deltaT(Arbre ab) {

	if (ab.get_rac() == nullptr) return 0;
	else {
		Arbre arbregauche(ab.get_rac()->_pFilsG);
		Arbre arbredroit(ab.get_rac()->_pFilsD);

		return ab.get_rac()->_deltaT + somme_deltaT(arbregauche) + somme_deltaT(arbredroit); // parcours prefixe
	}
}

float temperatureMoyenneMois(ListeStation lB, int month) {
    int nbStat = 0; // Compteur de station
    float sumT = 0; // Somme des temperatures
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        // Permet de vérifier si la station a des données pour le mois
        if (pCell->tab_arbres[month].get_rac() != nullptr) {
            // Ajout de la temérature de la station a sumT
            sumT += pCell->tab_arbres[month].get_rac()->_tempMois;
            nbStat++;
        }
    }
    // Renvoie la moyenne des températures
    return sumT / nbStat;
}

float temperatureMoyenneAnnee(ListeStation lB) {
    int nbStat = 0; // Compteur de station
    float sumT = 0; // Somme des temperatures
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        for (int i = 0; i < 12; i++) {
            // Permet de vérifier si la station a des données pour le mois
            if (pCell->tab_arbres[i].get_rac() != nullptr) { 
                // Ajout de la temérature de la station a sumT
                sumT += pCell->tab_arbres[i].get_rac()->_tempMois;
                nbStat++;
            }
        }
    }
    // Renvoie la moyenne des températures
    return sumT / nbStat;
}

float temperatureMaxMois(ListeStation lB, int month) {
    float maxTemp = -INFINITY; // Vatiable qui stock la temperature maximale
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        // Permet de vérifier si la station a des données pour le mois
        if (pCell->tab_arbres[month].get_rac() != nullptr) 
        { 
            // Compare les temperatures et change maxTemp si une température est supérieur
            if (maxTemp < pCell->tab_arbres[month].get_rac()->_tempMois) {
                maxTemp = pCell->tab_arbres[month].get_rac()->_tempMois;
            }
        }
    }
    // Renvoie la température maximale du mois
    return maxTemp;
}

float temperatureMinMois(ListeStation lB, int month) {
    float minTemp = +INFINITY; // Vatiable qui stock la temperature minimale
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        // Permet de vérifier si la station a des données pour le mois
        if (pCell->tab_arbres[month].get_rac() != nullptr) 
        {
            // Compare les temperatures et change maxTemp si une température est inferieur
            if (minTemp > pCell->tab_arbres[month].get_rac()->_tempMois) {
                minTemp = pCell->tab_arbres[month].get_rac()->_tempMois;
            }
        }
    }
    // Renvoie la température minimale du mois
    return minTemp;
}

float temperatureMaxAnnee(ListeStation lB) {
    float maxTemp = -INFINITY; // Vatiable qui stock la temperature maximale
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        for (int i = 0; i < 12; i++) {
            // Permet de vérifier si la station a des données pour le mois
            if (pCell->tab_arbres[i].get_rac() != nullptr)
            {
                // Compare les temperatures et change maxTemp si une température est supérieur
                if (maxTemp < pCell->tab_arbres[i].get_rac()->_tempMois) {
                    maxTemp = pCell->tab_arbres[i].get_rac()->_tempMois;
                }
            }
        }
    }
    // Renvoie la température maximale de l'annee
    return maxTemp;
}

float temperatureMinAnnee(ListeStation lB) {
    float minTemp = INFINITY; // Vatiable qui stock la temperature minimale
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        for (int i = 0; i < 12; i++) {
            // Permet de vérifier si la station a des données pour le mois
            if (pCell->tab_arbres[i].get_rac() != nullptr) 
            { 
                // Compare les temperatures et change maxTemp si une température est inferieur
                if (pCell->tab_arbres[i].get_rac()->_tempMois < minTemp) {
                    minTemp = pCell->tab_arbres[i].get_rac()->_tempMois;
                }
            }
        }
    }
    // Renvoie la température minimale de l'annee
    return minTemp;
}

float temperatureMoyenneSaison(ListeStation lB, int saison) {
    int nbStat = 0; // Compteur de station
    float sumT = 0; // Somme des temperatures
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        // Parcours 3 mois pour la saison / trimestre
        for (int i = (saison - 1) * 3; i < saison * 3; i++) {
            // Permet de vérifier si la station a des données pour le mois du trimestre
            if (pCell->tab_arbres[i].get_rac() != nullptr) 
            {
                // Ajout de la temérature de la station a sumT
                sumT += pCell->tab_arbres[i].get_rac()->_tempMois;
                nbStat++;
            }
        }
    }
    // Renvoie la moyenne des températures
    return sumT / nbStat;
}

float parcoursAnnees(Arbre ab, int& nbStat) {
    float sumT = 0; // Somme des temperatures pour le mois
    // Permet de verifier si la racine de l'arbre est nul
    if (ab.get_rac() == nullptr) return 0;
    else {
        // Crée deux objets arbre pour les sous-arbres gauche et droit de la racine
        Arbre arbregauche(ab.get_rac()->_pFilsG);
        Arbre arbredroit(ab.get_rac()->_pFilsD);
        // Ajout de la temerature de la station a sumT
        sumT += ab.get_rac()->_tempMois;
        nbStat++;

        // Permet de vérifie si le sous-arbre gauche n'est pas nul
        if (arbregauche.get_rac() != nullptr)
        {
            // Appel recursif de parcoursAnnees sur le sous-arbre gauche et ajoute la valeur renvoyee a sumT
            sumT += parcoursAnnees(arbregauche, nbStat);
        }
        // Permet de vérifie si le sous-arbre droit n'est pas nul
        if (arbredroit.get_rac() != nullptr)
        {
            // Appel recursif de parcoursAnnees sur le sous-arbre droit et ajoute la valeur renvoyee a sumT
            sumT += parcoursAnnees(arbredroit, nbStat);
        }
    }
    // Renvoie la somme des températures
    return sumT;
}

float temperatureMoyenneToutesAnnees(ListeStation lB) {
    int nbStat = 0; // Compteur du nombre de stations parcouru (noeud)
    float sumT = 0; // Somme des temperatures
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        for (int i = 0; i < 12; i++) {
            // Permet de vérifier si la station a des données pour le mois
            if (pCell->tab_arbres[i].get_rac() != nullptr) 
            {
                // Appelle recursif de parcoursAnnees sur cet arbre et ajoute la valeur renvoyée a sumT
                sumT += parcoursAnnees(pCell->tab_arbres[i], nbStat);
            }
        }
    }
    // Renvoie la moyenne des températures
    return sumT / nbStat;
}

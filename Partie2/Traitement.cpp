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
        // Permet de v�rifier si la station a des donn�es pour le mois
        if (pCell->tab_arbres[month].get_rac() != nullptr) {
            // Ajout de la tem�rature de la station a sumT
            sumT += pCell->tab_arbres[month].get_rac()->_tempMois;
            nbStat++;
        }
    }
    // Renvoie la moyenne des temp�ratures
    return sumT / nbStat;
}

float temperatureMoyenneAnnee(ListeStation lB) {
    int nbStat = 0; // Compteur de station
    float sumT = 0; // Somme des temperatures
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        for (int i = 0; i < 12; i++) {
            // Permet de v�rifier si la station a des donn�es pour le mois
            if (pCell->tab_arbres[i].get_rac() != nullptr) { 
                // Ajout de la tem�rature de la station a sumT
                sumT += pCell->tab_arbres[i].get_rac()->_tempMois;
                nbStat++;
            }
        }
    }
    // Renvoie la moyenne des temp�ratures
    return sumT / nbStat;
}

float temperatureMaxMois(ListeStation lB, int month) {
    float maxTemp = -INFINITY; // Vatiable qui stock la temperature maximale
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        // Permet de v�rifier si la station a des donn�es pour le mois
        if (pCell->tab_arbres[month].get_rac() != nullptr) 
        { 
            // Compare les temperatures et change maxTemp si une temp�rature est sup�rieur
            if (maxTemp < pCell->tab_arbres[month].get_rac()->_tempMois) {
                maxTemp = pCell->tab_arbres[month].get_rac()->_tempMois;
            }
        }
    }
    // Renvoie la temp�rature maximale du mois
    return maxTemp;
}

float temperatureMinMois(ListeStation lB, int month) {
    float minTemp = +INFINITY; // Vatiable qui stock la temperature minimale
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        // Permet de v�rifier si la station a des donn�es pour le mois
        if (pCell->tab_arbres[month].get_rac() != nullptr) 
        {
            // Compare les temperatures et change maxTemp si une temp�rature est inferieur
            if (minTemp > pCell->tab_arbres[month].get_rac()->_tempMois) {
                minTemp = pCell->tab_arbres[month].get_rac()->_tempMois;
            }
        }
    }
    // Renvoie la temp�rature minimale du mois
    return minTemp;
}

float temperatureMaxAnnee(ListeStation lB) {
    float maxTemp = -INFINITY; // Vatiable qui stock la temperature maximale
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        for (int i = 0; i < 12; i++) {
            // Permet de v�rifier si la station a des donn�es pour le mois
            if (pCell->tab_arbres[i].get_rac() != nullptr)
            {
                // Compare les temperatures et change maxTemp si une temp�rature est sup�rieur
                if (maxTemp < pCell->tab_arbres[i].get_rac()->_tempMois) {
                    maxTemp = pCell->tab_arbres[i].get_rac()->_tempMois;
                }
            }
        }
    }
    // Renvoie la temp�rature maximale de l'annee
    return maxTemp;
}

float temperatureMinAnnee(ListeStation lB) {
    float minTemp = INFINITY; // Vatiable qui stock la temperature minimale
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        for (int i = 0; i < 12; i++) {
            // Permet de v�rifier si la station a des donn�es pour le mois
            if (pCell->tab_arbres[i].get_rac() != nullptr) 
            { 
                // Compare les temperatures et change maxTemp si une temp�rature est inferieur
                if (pCell->tab_arbres[i].get_rac()->_tempMois < minTemp) {
                    minTemp = pCell->tab_arbres[i].get_rac()->_tempMois;
                }
            }
        }
    }
    // Renvoie la temp�rature minimale de l'annee
    return minTemp;
}

float temperatureMoyenneSaison(ListeStation lB, int saison) {
    int nbStat = 0; // Compteur de station
    float sumT = 0; // Somme des temperatures
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        // Parcours 3 mois pour la saison / trimestre
        for (int i = (saison - 1) * 3; i < saison * 3; i++) {
            // Permet de v�rifier si la station a des donn�es pour le mois du trimestre
            if (pCell->tab_arbres[i].get_rac() != nullptr) 
            {
                // Ajout de la tem�rature de la station a sumT
                sumT += pCell->tab_arbres[i].get_rac()->_tempMois;
                nbStat++;
            }
        }
    }
    // Renvoie la moyenne des temp�ratures
    return sumT / nbStat;
}

float parcoursAnnees(Arbre ab, int& nbStat) {
    float sumT = 0; // Somme des temperatures pour le mois
    // Permet de verifier si la racine de l'arbre est nul
    if (ab.get_rac() == nullptr) return 0;
    else {
        // Cr�e deux objets arbre pour les sous-arbres gauche et droit de la racine
        Arbre arbregauche(ab.get_rac()->_pFilsG);
        Arbre arbredroit(ab.get_rac()->_pFilsD);
        // Ajout de la temerature de la station a sumT
        sumT += ab.get_rac()->_tempMois;
        nbStat++;

        // Permet de v�rifie si le sous-arbre gauche n'est pas nul
        if (arbregauche.get_rac() != nullptr)
        {
            // Appel recursif de parcoursAnnees sur le sous-arbre gauche et ajoute la valeur renvoyee a sumT
            sumT += parcoursAnnees(arbregauche, nbStat);
        }
        // Permet de v�rifie si le sous-arbre droit n'est pas nul
        if (arbredroit.get_rac() != nullptr)
        {
            // Appel recursif de parcoursAnnees sur le sous-arbre droit et ajoute la valeur renvoyee a sumT
            sumT += parcoursAnnees(arbredroit, nbStat);
        }
    }
    // Renvoie la somme des temp�ratures
    return sumT;
}

float temperatureMoyenneToutesAnnees(ListeStation lB) {
    int nbStat = 0; // Compteur du nombre de stations parcouru (noeud)
    float sumT = 0; // Somme des temperatures
    // Parcours de la liste de stations
    for (CelluleStation* pCell = lB.get_tete(); pCell != nullptr; pCell = pCell->_pSuiv) {
        for (int i = 0; i < 12; i++) {
            // Permet de v�rifier si la station a des donn�es pour le mois
            if (pCell->tab_arbres[i].get_rac() != nullptr) 
            {
                // Appelle recursif de parcoursAnnees sur cet arbre et ajoute la valeur renvoy�e a sumT
                sumT += parcoursAnnees(pCell->tab_arbres[i], nbStat);
            }
        }
    }
    // Renvoie la moyenne des temp�ratures
    return sumT / nbStat;
}

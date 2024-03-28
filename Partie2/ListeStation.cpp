#include "ListeStation.h"

#include <iostream>



// Cette fonction est un peu a modifier par rapport a la partie 1 car il y a un tableau maintenant en plus
void ListeStation::ajoute_cellule_en_tete(const CelluleStation& cel) {
    CelluleStation* nouvelleCellule = new CelluleStation(cel);
    nouvelleCellule->_pSuiv = _pListDeb;
    nouvelleCellule->tab_arbres = cel.tab_arbres;
    if (_pListDeb != nullptr) {
        _pListDeb->_pPred = nouvelleCellule;
    }
    _pListDeb = nouvelleCellule;
    if (_pListFin == nullptr) {
        _pListFin = nouvelleCellule;
    }
}

void ListeStation::affiche_liste() const {
    CelluleStation* pTemp = _pListDeb;
    while (pTemp != nullptr) {
        std::cout << pTemp->_ID << " ";
        pTemp = pTemp->_pSuiv;
    }
}

void ListeStation::affiche_liste_endroit() const {
    CelluleStation* pTemp = _pListFin;
    while (pTemp != nullptr) {
        std::cout << pTemp->_ID << " ";
        pTemp = pTemp->_pPred;
    }
}

size_t ListeStation::nbelem() const {
    size_t compteur = 0;
    CelluleStation* pTemp = _pListDeb;
    while (pTemp != nullptr) {
        compteur++;
        pTemp = pTemp->_pSuiv;
    }
    return compteur;
}


// renvoie le ptr vers cellule avec cle. Si cle absente renvoie null
CelluleStation* ListeStation::recherche_ptr(int cle) const {
    CelluleStation* pTemp = _pListDeb;
    while (pTemp != nullptr) {
        if (pTemp->_ID == cle) {
            return pTemp;
        }
        pTemp = pTemp->_pSuiv;
    }
    return nullptr; // pas trouvé
}


void ListeStation::supprime_cellule(int cle) {
    CelluleStation* pTemp = recherche_ptr(cle);
    if (pTemp == nullptr) {
        return; // pas trouvé
    }
    if (pTemp->_pPred != nullptr) {
        pTemp->_pPred->_pSuiv = pTemp->_pSuiv;
    }
    else {
        _pListDeb = pTemp->_pSuiv;
    }
    if (pTemp->_pSuiv != nullptr) {
        pTemp->_pSuiv->_pPred = pTemp->_pPred;
    }
    else {
        _pListFin = pTemp->_pPred;
    }
    delete pTemp;
}


void ListeStation::liberer_liste() {
    CelluleStation* pTemp = _pListDeb;
    while (pTemp != nullptr) {
        CelluleStation* pSuiv = pTemp->_pSuiv;
        delete pTemp;
        pTemp = pSuiv;
    }
    _pListDeb = nullptr;
    _pListFin = nullptr;
}

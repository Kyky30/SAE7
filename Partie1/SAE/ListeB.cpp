#include "ListeB.h"
#include <iostream>


void ListeB::ajoute_cellule_en_tete(const CelluleB& cel) {
    CelluleB* newCell = new CelluleB(cel._info);
    // Si la liste est vide, la nouvelle cellule est la premi�re et la derni�re de la liste
    if (_pListDeb == nullptr) {
        _pListDeb = newCell;
        _pListFin = newCell;
    }
    // Sinon on ajoute la nouvelle cellule en t�te de la liste
    else {
        newCell->_pSuiv = _pListDeb;
        _pListDeb->_pPred = newCell;
        _pListDeb = newCell;
    }
}

void ListeB::ajoute_cellule_en_queue(const CelluleB& cel) {
    CelluleB* newCell = new CelluleB(cel._info);
    // Si la liste est vide, la nouvelle cellule est la premi�re et la derni�re de la liste
    if (_pListFin == nullptr) {
        _pListDeb = newCell;
        _pListFin = newCell;
    }
    // Sinon on ajoute la nouvelle cellule en queue de la liste
    else {
        _pListFin->_pSuiv = newCell;
        newCell->_pPred = _pListFin;
        _pListFin = newCell;
    }
}


void ListeB::affiche_liste() const {
    CelluleB* current = _pListDeb;
    while (current != nullptr) {
        std::cout << current->_info << " ";
        current = current->_pSuiv;
    }
}


void ListeB::affiche_liste_endroit() const {
    CelluleB* current = _pListFin;
    while (current != nullptr) {
        std::cout << current->_info << " ";
        current = current->_pPred;
    }
}

// Renvoie le nombre de cellules dans la liste
int ListeB::nbelem() const {
    int count = 0;
    CelluleB* current = _pListDeb;
    while (current != nullptr) {
        count++;
        current = current->_pSuiv;
    }
    return count;
}

// renvoie le ptr vers cellule avec cle. Si cle absente renvoie null
CelluleB* ListeB::recherche_ptr(int cle) const {
    CelluleB* current = _pListDeb;
    while (current != nullptr && current->_info != cle) {
        current = current->_pSuiv;
    }
    return current;
}

void ListeB::supprime_cellule(int cle) {
    CelluleB* current = recherche_ptr(cle);
    // Si la cellule existe, on la supprime de la liste
    if (current != nullptr) {
        // si la cellule n'est pas la premi�re de la liste on met � jour le pointeur _pSuiv de sa cellule pr�c�dente
        if (current->_pPred != nullptr) {
            current->_pPred->_pSuiv = current->_pSuiv;
        }
        // si la cellule est la premi�re de la liste, on met � jour le pointeur de la t�te de liste
        else {
            _pListDeb = current->_pSuiv;
        }
        // si la cellule n'est pas la derni�re de la liste, on met � jour le pointeur _pPred de sa cellule suivante
        if (current->_pSuiv != nullptr) {
            current->_pSuiv->_pPred = current->_pPred;
        }
        // si la cellule est la derni�re de la liste, on met � jour le pointeur de la fin de liste
        else {
            _pListFin = current->_pPred;
        }
        // Suprime la cellule current
        delete current;
    }
}

void ListeB::liberer_liste() {
    CelluleB* current = _pListDeb;
    // on parcourt la liste de la t�te � la queue
    while (current != nullptr) {
        // on r�cup�re le pointeur vers la cellule suivante
        CelluleB* next = current->_pSuiv;
        // on lib�re la m�moire occup�e par la cellule courante
        delete current;
        // on passe � la cellule suivante
        current = next;
    }
    // on met � jour les pointeurs de la t�te et de la fin de liste pour signifier que la liste est vide
    _pListDeb = nullptr;
    _pListFin = nullptr;
}
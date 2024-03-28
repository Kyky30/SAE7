#include "Liste.h"
#include <iostream>



void Liste::ajoute_cellule_en_tete(const Cellule &cel) {
	Cellule* cel1 = new Cellule(cel._info);
	cel1->_pSuiv=_pList;
	_pList = cel1;
}

void Liste::affiche_liste() const{
	Cellule* p = _pList;
	while (p != nullptr) {
		std::cout << p->_info << " ";
		p = p->_pSuiv;
	}
	std::cout << std::endl;
}


void Liste::ajoute_cellule_en_queue(const Cellule& cel) {
	// Création d'une nouvelle cellule avec les informations de la cellule donnée en argument
	Cellule* newCell = new Cellule(cel._info);
	// Si la liste est vide
	if (_pList == nullptr) {
		// La nouvelle cellule devient le premier élément de la liste
		_pList = newCell;
	}
	else {
		// Sinon, parcourir la liste jusqu'à atteindre la dernière cellule
		Cellule* current = _pList;
		while (current->_pSuiv != nullptr) {
			current = current->_pSuiv;
		}
		// Ajouter la nouvelle cellule à la fin de la liste
		current->_pSuiv = newCell;
	}
}


int Liste::nbelem() const {
	Cellule* p = _pList;
	int nb = 0;
	while (p != nullptr) {
		nb += 1;
		p = p->_pSuiv;
	}
	return nb;
}


// renvoie le ptr vers cellule avec cle, nullptr si cle absente
Cellule* Liste::recherche_ptr(int cle)const {
	Cellule* p = _pList;
	if (!_pList) return nullptr;  //liste vide
	else {
		while (p != nullptr && p->_info != cle) {
			p = p->_pSuiv;
		}
		if (p)
			return p;
		else return nullptr;
	}
}



// renvoie le ptr vers cellule avant la cellule avec cle. Si cle en 1ere cellule ou absente renvoie nullptr
Cellule* Liste::recherche_ptr_avant_cle(int cle)const {
	Cellule* pred = _pList;
	if (pred == nullptr || pred->_info == cle) return nullptr;
	while ( pred->_pSuiv!=nullptr && pred->_pSuiv->_info!=cle) {
		pred = pred->_pSuiv;
	}
	if (pred->_pSuiv && pred->_pSuiv->_info == cle)
		return pred;
	else return nullptr;
}


void Liste::supprime_cellule(int cle) {
	Cellule* pred = recherche_ptr_avant_cle(cle);  
	Cellule* p;

	if (pred != nullptr) { // cas trouve et pas en tete de liste
		p = pred->_pSuiv;  // p pointe vers la cellule contenant cle donc p->_pSuiv existe
		pred->_pSuiv = p->_pSuiv;
		delete p;
	}
	else{

		if (_pList && _pList->_info==cle) { // suppression en tete de liste
			p = _pList;
			_pList = nullptr;
			delete p;
		}
		
	}

}


void Liste::liberer_liste() {
	Cellule* p = _pList;
	while (_pList != nullptr) {
		Cellule* p = _pList;
		_pList = _pList->_pSuiv;
		delete p;
	}
}
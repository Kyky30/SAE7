#pragma once
#include "CelluleStation.h"

class ListeStation{
	CelluleStation* _pListDeb = nullptr;
	CelluleStation* _pListFin = nullptr;
public:
	CelluleStation* get_tete() { return _pListDeb; }
	CelluleStation* get_queue() { return _pListFin; }

	void ajoute_cellule_en_tete(const CelluleStation& cel);
	void affiche_liste()const;
	void affiche_liste_endroit()const;
	void liberer_liste();
	size_t nbelem() const;
	CelluleStation* recherche_ptr(int cle)const;  
	void supprime_cellule(int cle);

	

};


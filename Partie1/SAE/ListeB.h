#pragma once

#include "CelluleB.h"

class ListeB {
private:
	CelluleB* _pListDeb = nullptr;
	CelluleB* _pListFin = nullptr;
public:
	CelluleB* acces_tete() { return _pListDeb; };
	CelluleB* acces_queue() { return _pListFin; };

	void ajoute_cellule_en_tete(const CelluleB& cel); // attention 2 cas	// Complexit� O(1)
	void ajoute_cellule_en_queue(const CelluleB& cel);						// Complexit� O(1)
	void affiche_liste()const;												// Complexit� O(n)
	void affiche_liste_endroit()const; //parcours depuis la queue			// Complexit� O(n)
	void liberer_liste();													// Complexit� O(n)
	int nbelem() const;														// Complexit� O(n)
	CelluleB* recherche_ptr(int cle)const;									// Complexit� O(n)
	void supprime_cellule(int cle);											// Complexit� O(n)

};
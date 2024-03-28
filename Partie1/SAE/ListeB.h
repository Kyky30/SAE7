#pragma once

#include "CelluleB.h"

class ListeB {
private:
	CelluleB* _pListDeb = nullptr;
	CelluleB* _pListFin = nullptr;
public:
	CelluleB* acces_tete() { return _pListDeb; };
	CelluleB* acces_queue() { return _pListFin; };

	void ajoute_cellule_en_tete(const CelluleB& cel); // attention 2 cas	// Complexité O(1)
	void ajoute_cellule_en_queue(const CelluleB& cel);						// Complexité O(1)
	void affiche_liste()const;												// Complexité O(n)
	void affiche_liste_endroit()const; //parcours depuis la queue			// Complexité O(n)
	void liberer_liste();													// Complexité O(n)
	int nbelem() const;														// Complexité O(n)
	CelluleB* recherche_ptr(int cle)const;									// Complexité O(n)
	void supprime_cellule(int cle);											// Complexité O(n)

};
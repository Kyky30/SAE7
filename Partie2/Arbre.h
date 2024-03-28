#pragma once

#include "CelluleArbre.h"

class Arbre {
	CelluleArbre* _pArbre ;
public:

	Arbre(CelluleArbre* ptr = nullptr) : _pArbre{ ptr }  {}

	CelluleArbre* get_rac() { return _pArbre; }

	void ajoute_cellule(const CelluleArbre& cel);
	void affiche_arbre_prefixe()const;
	
	void affiche_arbre_infixe()const;
	void affiche_arbre_postfixe()const;
	void liberer_arbre();
	size_t nbelem() const;
	float max()const;
	float min()const;
	size_t hauteur()const;
	size_t nbfeuille()const;
	bool non_degenere()const;
	CelluleArbre* recherche_ptr(float cle)const;  
	void supprime_cellule(float cle);
};


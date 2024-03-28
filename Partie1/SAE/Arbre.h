#pragma once


#include "CelluleA.h"

class Arbre {
private :
	CelluleA* _pArbre = nullptr;
public:
	Arbre() {
		_pArbre = nullptr;
	};

	Arbre(CelluleA* ptr) {
		_pArbre = ptr;
	};

	CelluleA* acces_rac() { return _pArbre; };

	void ajoute_cellule(const CelluleA& cel);	// O(log n) Pire des cas (arbre equilibre) | O(n) cas le plus défavorable (arbre desequilibre)
	void affiche_arbre_prefixe()const;			// Complexite O(n)
	void affiche_arbre_infixe()const;			// Complexite O(n)
	void affiche_arbre_postfixe()const;			// Complexite O(n)
	void liberer_arbre();						// Complexite O(n)
	int nbelem() const;							// Complexite O(n)
	int max()const;									// O(log n) Pire des cas (arbre equilibre) | O(n) cas le plus défavorable (arbre desequilibre)
	int min()const;									// O(log n) Pire des cas (arbre equilibre) | O(n) cas le plus défavorable (arbre desequilibre)
	int hauteur()const;							// Complexite O(n)
	int nbfeuille()const;						// Complexite O(n)
	bool non_degenere()const;						// O(n) Pire des cas (arbre dégénéré) | O(log n) Meilleur des cas (arbre equilibre)
	CelluleA* recherche_ptr(int cle)const;		// O(log n) Pire des cas (arbre equilibre) | O(n) cas le plus défavorable (arbre desequilibre)
	void supprime_cellule(int cle);				// O(log n) Pire des cas (arbre equilibre) | O(n) cas le plus défavorable (arbre desequilibre)

};
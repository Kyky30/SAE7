#include "Arbre.h"
#include <iostream>

void Arbre::ajoute_cellule(const CelluleA& cel)
{
	// Initialisation des variables
	CelluleA* ptcel1 = new CelluleA(cel._info);
	CelluleA* p = _pArbre;
	bool nontrouve = true;

	// Si l'arbre est vide on ajoute la nouvelle cellule à la racine
	if (p == nullptr) {
		nontrouve = false;
		_pArbre = ptcel1;
	}

	// Sinon on parcours l'arbre pour trouver l'endroit où insérer la nouvelle cellule
	while (nontrouve) {
		// Si la nouvelle cellule est inférieure à la cellule courante
		if (ptcel1->_info < p->_info) {
			// et que le fils gauche est null on ajoute la nouvelle cellule comme fils gauche de la cellule courante
			if (p->_pFilsG == nullptr) {
				nontrouve = false;
				p->_pFilsG = ptcel1;
			}
			// Sinon on continue de parcourir l'arbre vers la gauche
			else {
				p = p->_pFilsG;
			}
		}
		// Si la nouvelle cellule est supérieure à la cellule courante,
		else {
			// et que le fils droit est null, on ajoute la nouvelle cellule comme fils droit de la cellule courante
			if (p->_pFilsD == nullptr) {
				nontrouve = false;
				p->_pFilsD = ptcel1;
			}
			// Sinon, continue de parcourir l'arbre vers la droite
			else 
				p = p->_pFilsD;
		}
	}
}

void Arbre::affiche_arbre_prefixe()const
{
	// Si l'arbre est non-vide
	if (_pArbre) {
		// Crée deux sous-arbres avec les fils gauche et droit de la racine courante
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);

		// Affiche la cellule courante, puis les sous-arbres en préfixe
		std::cout << _pArbre->_info;
		arbregauche.affiche_arbre_prefixe();
		arbredroit.affiche_arbre_prefixe();
	}
}

// Affiche les valeurs de l'arbre en ordre infixe (gauche, racine, droite)
void Arbre::affiche_arbre_infixe() const {
	if (_pArbre) {
		// Création d'un arbre temporaire pour le sous-arbre gauche
		Arbre arbregauche(this->_pArbre->_pFilsG);
		// Création d'un arbre temporaire pour le sous-arbre droit
		Arbre arbredroit(this->_pArbre->_pFilsD);

		// Affichage du sous-arbre gauche en ordre infixe
		arbregauche.affiche_arbre_infixe();
		// Affichage de la racine
		std::cout << _pArbre->_info << " ";
		// Affichage du sous-arbre droit en ordre infixe
		arbredroit.affiche_arbre_infixe();
	}
}

// Affiche les valeurs de l'arbre en ordre postfixe (gauche, droite, racine)
void Arbre::affiche_arbre_postfixe() const {
	if (_pArbre) {
		// Création d'un arbre temporaire pour le sous-arbre gauche
		Arbre arbregauche(this->_pArbre->_pFilsG);
		// Création d'un arbre temporaire pour le sous-arbre droit
		Arbre arbredroit(this->_pArbre->_pFilsD);

		// Affichage du sous-arbre gauche en ordre postfixe
		arbregauche.affiche_arbre_postfixe();
		// Affichage du sous-arbre droit en ordre postfixe
		arbredroit.affiche_arbre_postfixe();
		// Affichage de la racine
		std::cout << _pArbre->_info << " ";
	}
}



// Todo
int Arbre::max() const {
	// Si l'arbre est vide on renvoie 0
	if (_pArbre == nullptr) {
		return 0;
	}
	// sinon si l'arbre n'a pas de sous-arbre droit, renvoyer la valeur de la racine
	else if (_pArbre->_pFilsD == nullptr) {
		return _pArbre->_info;
	}
	// Sinon, chercher la valeur maximale dans le sous-arbre droit
	else {
		return Arbre(_pArbre->_pFilsD).max();
	}
}

// Todo
int Arbre::min() const {
	// Si l'arbre est vide on renvoie 0
	if (_pArbre == nullptr) {
		return 0;
	}
	// Si l'arbre n'a pas de sous-arbre gauche, renvoyer la valeur de la racine
	else if (_pArbre->_pFilsG == nullptr) {
		return _pArbre->_info;
	}
	// Sinon, chercher la valeur minimale dans le sous-arbre gauche
	else {
		return Arbre(_pArbre->_pFilsG).min();
	}
}

// Todo
// Renvoie la hauteur de l'arbre
int Arbre::hauteur() const {
	// Si l'arbre est vide on renvoie 0
	if (_pArbre == nullptr) {
		return 0;
	}
	// Sinon, on renvoie 1 + le maximum entre la hauteur du sous-arbre gauche et la hauteur du sous-arbre droit
	else {
		return 1 + std::max(Arbre(_pArbre->_pFilsG).hauteur(), Arbre(_pArbre->_pFilsD).hauteur());
	}
}

// Renvoie le nombre d'éléments dans l'arbre
int Arbre::nbelem() const {
	// Si l'arbre est vide on renvoie 0
	if (_pArbre == nullptr) {
		return 0;
	}
	// Sinon, renvoyer 1 + le nombre d'éléments dans le sous-arbre gauche + le nombre d'éléments dans le sous-arbre droit
	else {
		return 1 + Arbre(_pArbre->_pFilsG).nbelem() + Arbre(_pArbre->_pFilsD).nbelem();
	}
}

// Renvoie le nombre de feuilles dans l'arbre
int Arbre::nbfeuille() const {
	// Si l'arbre est vide on renvoie 0
	if (_pArbre == nullptr) {
		return 0;
	}
	// sinon si l'arbre n'a pas de sous-arbres gauche et droit on renvoie 1
	else if (_pArbre->_pFilsG == nullptr && _pArbre->_pFilsD == nullptr) {
		return 1;
	}
	// Sinon on renvoie le nombre de feuilles dans le sous-arbre gauche + le nombre de feuilles dans le sous-arbre droit
	else {
		return Arbre(_pArbre->_pFilsG).nbfeuille() + Arbre(_pArbre->_pFilsD).nbfeuille();
	}
}


bool Arbre::non_degenere()const {
	if (_pArbre == nullptr) return false;
	else {
		// l'arbre est non degenere si au moins 1 noeud possede 2 fils
		if (_pArbre->_pFilsG != nullptr && _pArbre->_pFilsD != nullptr) return true;
		else {
			if (_pArbre->_pFilsG == nullptr) {
				Arbre arbredroit(this->_pArbre->_pFilsD);
				return arbredroit.non_degenere();
			}
			else { //_pArbre->_pFilsD == nullptr
				Arbre arbregauche(this->_pArbre->_pFilsG);
				return arbregauche.non_degenere();
			}
		}
	}
}

// On exploite dans la recherche le fait que l'arbre soit un ABR
// Renvoie le pointeur sur la cellule contenant cle, nullptr si pas trouvé
// Fonction importante
// Todo
CelluleA* Arbre::recherche_ptr(int cle) const {
	CelluleA* p = _pArbre;
	// Parcours de l'arbre tant que le pointeur n'est pas nul et que la clé n'a pas été trouvée
	while (p != nullptr && p->_info != cle) {
		// Si la clé est inférieure à la valeur de la cellule courante on continue la recherche dans le sous-arbre gauche
		if (cle < p->_info) {
			p = p->_pFilsG;
		}
		// Sinon on continue la recherche dans le sous-arbre droit
		else {
			p = p->_pFilsD;
		}
	}
	return p;
}

void Arbre::supprime_cellule(int cle) {
	
	CelluleA* p = _pArbre;
	CelluleA* psauve = _pArbre;
	CelluleA* pred=_pArbre;
	bool nontrouve = true;
	if (p != nullptr && p->_info == cle) { //suppression en tete
		pred = p->_pFilsG; // pour rattachement
		if (p->_pFilsD != nullptr) {
			p = p->_pFilsD;
			while (p && p->_pFilsG)
				p = p->_pFilsG;
			p->_pFilsG = pred;
			_pArbre = _pArbre->_pFilsD;
		}
		else _pArbre = pred; // pas de sous arbre droit
		delete psauve;
		return;	
	}
	
	bool filsdroit = true;;
	while (p!=nullptr && nontrouve) {
		if (cle < p->_info) {
			pred = p;
			filsdroit = false;
			p = p->_pFilsG;
		}
		else
			if (cle > p->_info) {
				pred = p;
				filsdroit = true;
				p = p->_pFilsD;
			}
			else nontrouve = false;  // on a trouve
	}

	if (p && p->_pFilsG ==nullptr && p->_pFilsD == nullptr) {  // si feuille
		if (filsdroit) 
			pred->_pFilsD = nullptr;
		
		else pred->_pFilsG = nullptr;
		delete p;
	}
	else { //si pas feuille
			psauve = p;
			
			if (p && p->_pFilsD != nullptr) {
				p = p->_pFilsD;
				while (p && p->_pFilsG)
					p = p->_pFilsG;
				p->_pFilsG = psauve->_pFilsG;
				if (filsdroit)
					pred->_pFilsD = psauve->_pFilsD;
				else
					pred->_pFilsG = psauve->_pFilsD;
			}
			else 
				if (pred && psauve)
					if (filsdroit)
						pred->_pFilsD = psauve->_pFilsG;
					else
						pred->_pFilsG = psauve->_pFilsG; // pas de sous arbre droit
			delete psauve;

	}	
}


void Arbre::liberer_arbre() {
	if (_pArbre) {
		//Arbre temporaires
		Arbre arbregauche(_pArbre->_pFilsG);
		Arbre arbredroit(_pArbre->_pFilsD);
		// Libération des arbres
		arbregauche.liberer_arbre();
		arbredroit.liberer_arbre();
		// Suppression de la cellule courante
		delete _pArbre;
		// Réinitialisation du pointeur à nullptr
		_pArbre = nullptr;
	}
}

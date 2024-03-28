#include "Arbre.h"
#include <iostream>

void Arbre::ajoute_cellule(const CelluleArbre& cel) {

	CelluleArbre* ptcel1 = new CelluleArbre(cel._deltaT,cel._annee, cel._tempMois, cel._tSigmaMois);
	CelluleArbre* p = _pArbre;
	bool nontrouve = true;
	if (p == nullptr) { nontrouve = false; _pArbre = ptcel1; } //insere en tete
	while (nontrouve) {
		if (ptcel1->_deltaT < p->_deltaT) {
			if (p->_pFilsG == nullptr) {
				nontrouve = false; p->_pFilsG = ptcel1;
			}
			else p = p->_pFilsG;
		}
		else {
			if (p->_pFilsD == nullptr) {
				nontrouve = false; p->_pFilsD = ptcel1;
			}
			else p = p->_pFilsD;

		}
	}
}



void Arbre::affiche_arbre_prefixe()const {
	if (_pArbre) {
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);

		std::cout << _pArbre->_deltaT;
		arbregauche.affiche_arbre_prefixe();
		arbredroit.affiche_arbre_prefixe();
	}
}

// Todo
void Arbre::affiche_arbre_infixe() const
{
	if (_pArbre) {
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);

		arbregauche.affiche_arbre_infixe();
		std::cout << _pArbre->_deltaT;
		arbredroit.affiche_arbre_infixe();
	}
}

// Todo
void Arbre::affiche_arbre_postfixe() const
{
	if (_pArbre) {
		Arbre arbregauche(this->_pArbre->_pFilsG);
		Arbre arbredroit(this->_pArbre->_pFilsD);

		arbregauche.affiche_arbre_prefixe();
		arbredroit.affiche_arbre_prefixe();
		std::cout << _pArbre->_deltaT;
	}
}



// Todo
void Arbre::liberer_arbre() {
	if (_pArbre) {
		Arbre arbregauche(_pArbre->_pFilsG);
		Arbre arbredroit(_pArbre->_pFilsD);
		
		arbregauche.liberer_arbre();
		arbredroit.liberer_arbre();
		
		delete _pArbre;
		_pArbre = nullptr;
	}
}

// Todo
float Arbre::max() const {
	if (_pArbre == nullptr) {
		// Si l'arbre est vide, renvoyer une valeur indéfinie
		return std::numeric_limits<float>::quiet_NaN();
	}
	else if (_pArbre->_pFilsD == nullptr) {
		// Si l'arbre n'a pas de sous-arbre droit, renvoyer la valeur de la racine
		return _pArbre->_deltaT;
	}
	else {
		// Sinon, chercher la valeur maximale dans le sous-arbre droit
		return Arbre(_pArbre->_pFilsD).max();
	}
}

// Todo
float Arbre::min() const {
	if (_pArbre == nullptr) {
		// Si l'arbre est vide, renvoyer une valeur indéfinie
		return std::numeric_limits<float>::quiet_NaN();
	}
	else if (_pArbre->_pFilsG == nullptr) {
		// Si l'arbre n'a pas de sous-arbre gauche, renvoyer la valeur de la racine
		return _pArbre->_deltaT;
	}
	else {
		// Sinon, chercher la valeur minimale dans le sous-arbre gauche
		return Arbre(_pArbre->_pFilsG).min();
	}
}

// Todo
size_t Arbre::hauteur() const {
	if (_pArbre == nullptr) {
		// Si l'arbre est vide, sa hauteur est 0
		return 0;
	}
	else {
		// Sinon, la hauteur de l'arbre est 1 plus la hauteur du sous-arbre le plus haut
		return 1 + std::max(Arbre(_pArbre->_pFilsG).hauteur(), Arbre(_pArbre->_pFilsD).hauteur());
	}
}

// Todo
size_t Arbre::nbelem() const {
	if (_pArbre == nullptr) {
		// Si l'arbre est vide, le nombre d'éléments est 0
		return 0;
	}
	else {
		// Sinon, le nombre d'éléments est 1 plus le nombre d'éléments dans les sous-arbres
		return 1 + Arbre(_pArbre->_pFilsG).nbelem() + Arbre(_pArbre->_pFilsD).nbelem();
	}
}

// Todo
size_t Arbre::nbfeuille() const {
	if (_pArbre == nullptr) {
		// Si l'arbre est vide, le nombre de feuilles est 0
		return 0;
	}
	else if (_pArbre->_pFilsG == nullptr && _pArbre->_pFilsD == nullptr) {
		// Si la cellule courante est une feuille, le nombre de feuilles est 1
		return 1;
	}
	else {
		// Sinon, le nombre de feuilles est la somme des nombres de feuilles dans les sous-arbres
		return Arbre(_pArbre->_pFilsG).nbfeuille() + Arbre(_pArbre->_pFilsD).nbfeuille();
	}
}


bool Arbre::non_degenere()const {
	if (_pArbre == nullptr) 
		return false;
	else {
		if (_pArbre->_pFilsG != nullptr && _pArbre->_pFilsD != nullptr) 
			return true;
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

// Todo
CelluleArbre* Arbre::recherche_ptr(float cle) const {
	CelluleArbre* ptr = _pArbre;

	while (ptr != nullptr && ptr->_deltaT != cle) {
		if (cle < ptr->_deltaT) {
			ptr = ptr->_pFilsG;
		}
		else {
			ptr = ptr->_pFilsD;
		}
	}

	return ptr;
}

void Arbre::supprime_cellule(float cle) {

	CelluleArbre* p = _pArbre;
	CelluleArbre* psauve = _pArbre;
	CelluleArbre* pred = _pArbre;
	bool nontrouve = true;
	if (p != nullptr && p->_deltaT == cle) { //suppression en tete
		pred = p->_pFilsG; // pour rattachement
		if (p->_pFilsD != nullptr) {
			p = p->_pFilsD;
			while (p && p->_pFilsG)
				p = p->_pFilsG;
			p->_pFilsG = pred;
			_pArbre = _pArbre->_pFilsD;
		}
		else
			_pArbre = pred; // pas de sous arbre droit
		delete psauve;
		return;
	}

	bool _pFilsDroit = true;;
	while (p != nullptr && nontrouve) {
		if (cle < p->_deltaT) {
			pred = p;
			_pFilsDroit = false;
			p = p->_pFilsG;
		}
		else
			if (cle > p->_deltaT) {
				pred = p;
				_pFilsDroit = true;
				p = p->_pFilsD;
			}
			else 
				nontrouve = false;  // on a trouve
	}

	if (p && p->_pFilsG == nullptr && p->_pFilsD == nullptr) {  // si feuille
		if (_pFilsDroit)
			pred->_pFilsD = nullptr;
		else
			pred->_pFilsG = nullptr;
		delete p;
	}
	else { //si pas feuille
		psauve = p;

		if (p && p->_pFilsD != nullptr) {
			p = p->_pFilsD;
			while (p && p->_pFilsG)
				p = p->_pFilsG;
			p->_pFilsG = psauve->_pFilsG;
			if (_pFilsDroit)
				pred->_pFilsD = psauve->_pFilsD;
			else
				pred->_pFilsG = psauve->_pFilsD;
		}
		else
			if (pred && psauve)
				if (_pFilsDroit)
					pred->_pFilsD = psauve->_pFilsG;
				else
					pred->_pFilsG = psauve->_pFilsG; // pas de sous arbre droit
		delete psauve;
	}
	
}


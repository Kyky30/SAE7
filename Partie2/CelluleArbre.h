#pragma once

struct CelluleArbre {
	float _deltaT;     // clé pour ordonner les cellules de l'arbre deltaT entre annee et annee+1
	int _annee;      // année du mois en cours
	float _tempMois;   // température moyenne du mois en cours
	float _tSigmaMois; // écart type moyen de la température du mois en cours

	CelluleArbre* _pFilsG;
	CelluleArbre* _pFilsD;

	CelluleArbre(float deltaT = 0.0, int an = 0, float tMoy = 0, float tSigma = 0, CelluleArbre* pFilsG = nullptr, CelluleArbre* pFilsD = nullptr) 
		: _deltaT{ deltaT }, _annee{ an }, _tempMois{ tMoy }, _tSigmaMois{ tSigma }, _pFilsG{ pFilsG }, _pFilsD{ pFilsD } {}
};


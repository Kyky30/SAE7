#pragma once

struct Cellule {
	int _info;
	Cellule* _pSuiv=nullptr;

	Cellule() { _info = 0; };
	Cellule(int elem) { _info = elem; };
};

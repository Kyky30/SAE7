#pragma once


struct CelluleA {
	int _info;
	CelluleA* _pFilsG = nullptr;
	CelluleA* _pFilsD = nullptr;

	CelluleA() { _info = 0; };
	CelluleA(int elem) { _info = elem; };
};

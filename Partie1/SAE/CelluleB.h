#pragma once


struct CelluleB {
	int _info;
	CelluleB* _pSuiv = nullptr;
	CelluleB* _pPred = nullptr;

	CelluleB() { _info = 0; };
	CelluleB(int elem) { _info = elem; };
};

#pragma once

#include "ListeStation.h"
#include "Arbre.h"

#include <vector> // std::vector
#include <string> // std::string
#include <fstream>
#include <sstream>
#include <filesystem>
#include <map> // std::map
#include <utility> // std::pair

class SAE_Datas_Heat {
	// Private Datas
	std::vector<std::map<int, std::pair<float,float> > > _vRawData;
	ListeStation _lListeStations;

	// Private Functions
	std::string readFileIntoString(const std::string& path)const;
	std::vector<std::string> listAllFiles()const;
	std::map<int, std::pair<float, float> > parseContentFile(std::string filename);
	void convertDataInList();
	Arbre calculDeltaT(size_t mois, const std::vector<float>& vTmoyStation, const std::vector<float>& vTSigmaStation);

public:
	// Public Functions
	SAE_Datas_Heat();
	size_t nbMonths()const;
	size_t nbStations()const { return _lListeStations.nbelem(); }
	const ListeStation& getListeStation()const { return _lListeStations; }
};


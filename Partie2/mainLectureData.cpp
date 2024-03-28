#include <iostream> // std::cout
#include "SAE_Datas_Heat.h"
#include "Traitement.h"


int main()
{
	SAE_Datas_Heat myStations;
	std::cout <<"Etude sur " << myStations.nbMonths() << " mois " << "\n" << "\n";
	
	ListeStation lB = myStations.getListeStation();
	std::cout << myStations.nbStations();
	std::cout << "Aff\n";
	lB.affiche_liste();
	std::cout << "\n\n\n\n";
	std::cout << "Test de temperatureMoyenneMois(lB, 3) " << temperatureMoyenneMois(lB, 3) << "\n\n";
	std::cout << "Test de temperatureMoyenneAnnee(lB) " << temperatureMoyenneAnnee(lB) << "\n\n";
	std::cout << "Test de temperatureMaxMois(lB, 3) " << temperatureMaxMois(lB, 3) << "\n\n";
	std::cout << "Test de temperatureMinMois(lB, 3) " << temperatureMinMois(lB, 3) << "\n\n";
	std::cout << "Test de temperatureMaxAnnee(lB) " << temperatureMaxAnnee(lB) << "\n\n";
	std::cout << "Test de temperatureMinAnnee(lB) " << temperatureMinAnnee(lB) << "\n\n";
	std::cout << "Test de  temperatureMoyenneSaison(lB, 1) " << temperatureMoyenneSaison(lB, 4) << "\n\n";
	std::cout << "Test de  temperatureMoyenneToutesAnnees(lB) " << temperatureMoyenneToutesAnnees(lB) << "\n\n";
	return 0;
}
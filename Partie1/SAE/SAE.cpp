// SAE.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#endif // _WIN32

#include <iostream>
#include "Cellule.h"
#include "Liste.h"
#include "CelluleB.h"
#include "ListeB.h"
#include "CelluleA.h"
#include "Arbre.h"

#include <vector>
#include <string>
#include <array>

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32

	std::cout << "*************************************************************\
				  \n*                                                           *\
				  \n*                      Programme de base                    *\
				  \n*                                                           *\
				  \n*************************************************************\n\n";

    // Ecrivez vos tests dans le prog principal que l'on presentera proprement
    // ceux qui suivent sont juste la pour vous montrer comment cela marche
    Cellule cel;
    Cellule cel2(5);
    Cellule cel3(1);
    Cellule cel4(9);
    Cellule cel5(8);
    Cellule cel6(3);

    Liste l;
    l.ajoute_cellule_en_tete(cel);
    l.ajoute_cellule_en_tete(cel2);
    l.ajoute_cellule_en_tete(cel3);
    l.ajoute_cellule_en_tete(cel4);
    l.ajoute_cellule_en_tete(cel5);
    l.ajoute_cellule_en_tete(cel6);

    l.affiche_liste();
    std::cout << "il y a  " << l.nbelem() << " elements \n";
    l.ajoute_cellule_en_queue(cel3);
    l.supprime_cellule(1);
    l.affiche_liste();
    l.liberer_liste();
    std::cout << "Hello World2!\n";
    l.affiche_liste();




	std::cout << "*************************************************************\
				  \n*                                                           *\
				  \n*                      Test class ListeB                    *\
				  \n*                                                           *\
				  \n*************************************************************\n\n";


    ListeB liste;

    // Test de la fonction ajoute_cellule_en_tete
    std::cout << "Test de la fonction ajoute_cellule_en_tete" << "\n";
    liste.ajoute_cellule_en_tete(CelluleB(1));
    liste.ajoute_cellule_en_tete(CelluleB(2));
    liste.ajoute_cellule_en_tete(CelluleB(3));
    liste.affiche_liste();

    // Test de la fonction ajoute_cellule_en_queue
    std::cout << "Test de la fonction ajoute_cellule_en_queue" << "\n";
    liste.ajoute_cellule_en_queue(CelluleB(4));
    liste.ajoute_cellule_en_queue(CelluleB(5));
    liste.ajoute_cellule_en_queue(CelluleB(6));
    liste.affiche_liste();

    // Test de la fonction affiche_liste_endroit
    std::cout << "Test de la fonction affiche_liste_endroit" << "\n";
    liste.affiche_liste_endroit();

    // Test de la fonction nbelem
    std::cout << "Test de la fonction nbelem" << "\n";
    std::cout << "Nombre d'éléments dans la liste : " << liste.nbelem() << "\n";

    // Test de la fonction recherche_ptr
    std::cout << "Test de la fonction recherche_ptr" << "\n";
    CelluleB* cellPtr = liste.recherche_ptr(4);
    if (cellPtr != nullptr) {
        std::cout << "La cellule avec la clé 4 a été trouvée" << "\n";
    }
    else {
        std::cout << "La cellule avec la clé 4 n'a pas été trouvée" << "\n";
    }

    // Test de la fonction supprime_cellule
    std::cout << "Test de la fonction supprime_cellule" << "\n";
    liste.supprime_cellule(4);
    liste.affiche_liste();

    // Test de la fonction liberer_liste
    std::cout << "Test de la fonction liberer_liste" << "\n";
    liste.liberer_liste();
    liste.affiche_liste();
	std::cout << "Il y a " << liste.nbelem() << " élements dans la liste" << "\n";








    std::cout <<  "*************************************************************\
				  \n*                                                           *\
				  \n*                      Test class Arbre                     *\
				  \n*                                                           *\
				  \n*************************************************************\n\n";


	 // Création d'un arbre vide
	Arbre arbre;

	// Ajout de cellule dans l'arbre
	arbre.ajoute_cellule(CelluleA(5));
	arbre.ajoute_cellule(CelluleA(3));
	arbre.ajoute_cellule(CelluleA(7));
	arbre.ajoute_cellule(CelluleA(2));
	arbre.ajoute_cellule(CelluleA(4));
	arbre.ajoute_cellule(CelluleA(6));
	arbre.ajoute_cellule(CelluleA(8));

	// Test de la fonction recherche_ptr
	CelluleA* ptr = arbre.recherche_ptr(7);
	if (ptr != nullptr) {
		std::cout << "La cellule de valeur " << ptr->_info << " a ete trouvee" << "\n";
	}
	else {
		std::cout << "La cellule n'a pas ete trouvee" << "\n";
	}

	ptr = arbre.recherche_ptr(4);
	if (ptr != nullptr) {
		std::cout << "La cellule de valeur " << ptr->_info << " a ete trouvee" << "\n";
	}
	else {
		std::cout << "La cellule n'a pas ete trouvee" << "\n";
	}

	// Test de la fonction nbfeuille
	std::cout << "Nombre de feuilles : " << arbre.nbfeuille() << "\n";

	// Test de la fonction hauteur
	std::cout << "Hauteur de l'arbre : " << arbre.hauteur() << "\n";

	// Test de la fonction nbelem
	std::cout << "Nombre d'éléments dans l'arbre : " << arbre.nbelem() << "\n";

	// Test de la fonction min
	std::cout << "Valeur minimale dans l'arbre : " << arbre.min() << "\n";

	// Test de la fonction affiche_arbre_prefixe
	std::cout << "Affichage de l'arbre en préfixe : ";
	arbre.affiche_arbre_prefixe();
	std::cout << "\n";

	// Test de la fonction non_degenere
	std::cout << "L'arbre est non dégénéré : ";
	if (arbre.non_degenere()) {
		std::cout << "oui" << "\n";
	}
	else {
		std::cout << "non" << "\n";
	}
	//Test de la fonction libérer arbre
	std::cout << "Test de la fonction liberer_arbre() \n";
	arbre.liberer_arbre();
	std::cout << "Il y a " << arbre.nbelem() << " élements dans l'arbre" << "\n";

	/************************************************************
	*                                                           *
	*                      Fin des tests                      *
	*                                                           *
	*************************************************************/

    return 0;

}

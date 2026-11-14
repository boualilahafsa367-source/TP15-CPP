
#include <iostream>
#include <string>
#include "Pile.hpp"

int main() {
    // Test avec des entiers.
    std::cout << "=== PILE D'ENTIERS ===" << std::endl;

    Pile<int> pileEntiers;

    pileEntiers.empiler(137);
    pileEntiers.empiler(284);
    pileEntiers.empiler(419);
    pileEntiers.empiler(563);

    std::cout << "Contenu de la pile : ";
    pileEntiers.afficher();

    std::cout << "Sommet : " << pileEntiers.sommet() << std::endl;
    std::cout << "Element depile : " << pileEntiers.depiler() << std::endl;

    std::cout << "Apres depilage : ";
    pileEntiers.afficher();

    // Test de la methode inverser().
    pileEntiers.inverser();

    std::cout << "Apres inversion : ";
    pileEntiers.afficher();

    // Test avec des chaines de caracteres.
    std::cout << "\n=== PILE DE CHAINES ===" << std::endl;

    Pile<std::string> pileChaines;

    pileChaines.empiler("Essaouira");
    pileChaines.empiler("Ifrane");
    pileChaines.empiler("Ouarzazate");

    std::cout << "Contenu de la pile : ";
    pileChaines.afficher();

    std::cout << "Sommet : " << pileChaines.sommet() << std::endl;

    // Test avec des nombres decimaux.
    std::cout << "\n=== PILE DE DOUBLES ===" << std::endl;

    Pile<double> pileDecimaux;

    pileDecimaux.empiler(18.75);
    pileDecimaux.empiler(42.50);
    pileDecimaux.empiler(67.25);

    std::cout << "Contenu de la pile : ";
    pileDecimaux.afficher();

    std::cout << "Sommet : " << pileDecimaux.sommet() << std::endl;

    // Test de la gestion d'une pile vide.
    std::cout << "\n=== TEST D'EXCEPTION ===" << std::endl;

    Pile<int> pileVide;

    try {
        pileVide.depiler();
    }
    catch (const PileVideException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

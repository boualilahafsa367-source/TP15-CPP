
#include <iostream>
#include "ListeChainee.hpp"

using namespace std;

int main()
{
    cout << "=== EXERCICE 1 : LISTE CHAINEE ===" << endl;

    // Creation d'une liste vide
    ListeChainee liste;

    // Ajout de plusieurs elements au debut et a la fin
    liste.ajouterDebut(57);
    liste.ajouterDebut(34);
    liste.ajouterFin(82);
    liste.ajouterFin(106);
    liste.ajouterFin(149);

    cout << "\nApres les ajouts :" << endl;
    liste.afficher();

    // Affichage du nombre d'elements
    cout << "Taille de la liste : "
         << liste.taille() << endl;

    // Suppression d'un element existant
    cout << "\nSuppression de la valeur 82 :" << endl;
    liste.supprimer(82);
    liste.afficher();

    // Tentative de suppression d'une valeur absente
    cout << "\nSuppression de la valeur 200 :" << endl;
    liste.supprimer(200);

    // Parcours de la liste avec l'iterateur personnalise
    cout << "\nParcours avec l'iterateur : ";

    for (ListeChainee::Iterator it = liste.begin();
         it != liste.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    // Taille apres la suppression
    cout << "Taille finale : "
         << liste.taille() << endl;

    return 0;
}

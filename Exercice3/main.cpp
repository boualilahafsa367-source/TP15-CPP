
#include <iostream>
#include "TableHachage.hpp"

using namespace std;

int main()
{
    cout << "=== EXERCICE 3 : TABLE DE HACHAGE ===" << endl;

    // Creation d'une table de taille 7
    TableHachage table(7);

    // Insertion des associations cle-valeur
    cout << "\n--- Insertion des produits ---" << endl;

    table.inserer(23, "Clavier mecanique");
    table.inserer(30, "Souris sans fil");
    table.inserer(16, "Ecran portable");
    table.inserer(44, "Support ergonomique");
    table.inserer(51, "Casque audio");
    table.inserer(65, "Webcam HD");

    // Affichage de toute la table
    table.afficher();

    // Recherche d'une cle existante
    cout << "\n--- Recherche ---" << endl;

    try
    {
        cout << "Cle 30 : "
             << table.rechercher(30) << endl;

        cout << "Cle 44 : "
             << table.rechercher(44) << endl;
    }
    catch (const exception& e)
    {
        cout << "Erreur : " << e.what() << endl;
    }

    // Recherche d'une cle inexistante
    try
    {
        cout << "Cle 99 : "
             << table.rechercher(99) << endl;
    }
    catch (const exception& e)
    {
        cout << "Recherche impossible : "
             << e.what() << endl;
    }

    // Suppression d'une cle existante
    cout << "\n--- Suppression ---" << endl;

    table.supprimer(30);

    // Affichage apres suppression
    table.afficher();

    return 0;
}

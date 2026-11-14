
#include <iostream>
#include "File.hpp"

using namespace std;

int main()
{
    cout << "=== EXERCICE 2 : GESTION D'UNE FILE ===" << endl;

    // Creation d'une file de capacite maximale 6
    File file(6);

    int choix;
    int valeur;

    do
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Enfiler un element" << endl;
        cout << "2. Defiler un element" << endl;
        cout << "3. Afficher la file" << endl;
        cout << "4. Verifier si la file est vide" << endl;
        cout << "5. Verifier si la file est pleine" << endl;
        cout << "6. Afficher la taille" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix)
        {
        case 1:
            cout << "Valeur a ajouter : ";
            cin >> valeur;

            try
            {
                file.enfiler(valeur);
                cout << "Element ajoute avec succes." << endl;
            }
            catch (const exception& e)
            {
                cout << e.what() << endl;
            }
            break;

        case 2:
            try
            {
                cout << "Element retire : "
                     << file.defiler() << endl;
            }
            catch (const exception& e)
            {
                cout << e.what() << endl;
            }
            break;

        case 3:
            file.afficher();
            break;

        case 4:
            cout << (file.estVide()
                         ? "La file est vide."
                         : "La file contient des elements.")
                 << endl;
            break;

        case 5:
            cout << (file.estPleine()
                         ? "La file est pleine."
                         : "La file n'est pas pleine.")
                 << endl;
            break;

        case 6:
            cout << "Nombre d'elements : "
                 << file.taille() << endl;
            break;

        case 0:
            cout << "Fin du programme." << endl;
            break;

        default:
            cout << "Choix invalide. Reessayez." << endl;
        }

    } while (choix != 0);

    return 0;
}

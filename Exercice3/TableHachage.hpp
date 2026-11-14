
#ifndef TABLE_HACHAGE_HPP
#define TABLE_HACHAGE_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstddef>
#include "Element.hpp"

class TableHachage
{
private:
    Element** table;
    std::size_t tailleTable;

    // Calcule l'indice correspondant a une cle
    std::size_t hachage(int cle) const
    {
        // Gestion des cles negatives
        int resultat = cle % static_cast<int>(tailleTable);

        if (resultat < 0)
        {
            resultat += static_cast<int>(tailleTable);
        }

        return static_cast<std::size_t>(resultat);
    }

public:
    // Constructeur de la table de hachage
    explicit TableHachage(std::size_t taille)
        : table(nullptr), tailleTable(taille)
    {
        if (taille == 0)
        {
            throw std::invalid_argument(
                "La taille de la table doit etre positive."
            );
        }

        // Creation des cases initialisees a nullptr
        table = new Element*[tailleTable]();

    }

    // Insere une nouvelle association cle-valeur
    void inserer(int cle, const std::string& valeur)
    {
        std::size_t indice = hachage(cle);

        Element* courant = table[indice];

        // Si la cle existe deja, on met a jour sa valeur
        while (courant != nullptr)
        {
            if (courant->cle == cle)
            {
                courant->valeur = valeur;

                std::cout << "Cle " << cle
                          << " mise a jour." << std::endl;
                return;
            }

            courant = courant->suivant;
        }

        // Ajout du nouvel element au debut de la chaine
        Element* nouveau = new Element(cle, valeur);

        nouveau->suivant = table[indice];
        table[indice] = nouveau;

        std::cout << "Insertion reussie : cle "
                  << cle << std::endl;
    }

    // Recherche une valeur a partir de sa cle
    std::string rechercher(int cle) const
    {
        std::size_t indice = hachage(cle);

        Element* courant = table[indice];

        while (courant != nullptr)
        {
            if (courant->cle == cle)
            {
                return courant->valeur;
            }

            courant = courant->suivant;
        }

        throw std::out_of_range(
            "Cle introuvable dans la table de hachage."
        );
    }

    // Supprime un element a partir de sa cle
    void supprimer(int cle)
    {
        std::size_t indice = hachage(cle);

        Element* courant = table[indice];
        Element* precedent = nullptr;

        while (courant != nullptr)
        {
            if (courant->cle == cle)
            {
                if (precedent == nullptr)
                {
                    table[indice] = courant->suivant;
                }
                else
                {
                    precedent->suivant = courant->suivant;
                }

                delete courant;

                std::cout << "Suppression reussie : cle "
                          << cle << std::endl;
                return;
            }

            precedent = courant;
            courant = courant->suivant;
        }

        std::cout << "Cle " << cle
                  << " introuvable pour la suppression."
                  << std::endl;
    }

    // Affiche toutes les cases et leurs listes de collision
    void afficher() const
    {
        std::cout << "\n=== CONTENU DE LA TABLE ===" << std::endl;

        for (std::size_t i = 0; i < tailleTable; ++i)
        {
            std::cout << "Case " << i << " : ";

            Element* courant = table[i];

            if (courant == nullptr)
            {
                std::cout << "Vide";
            }

            while (courant != nullptr)
            {
                std::cout << "[" << courant->cle
                          << " : " << courant->valeur << "]";

                if (courant->suivant != nullptr)
                {
                    std::cout << " -> ";
                }

                courant = courant->suivant;
            }

            std::cout << std::endl;
        }
    }

    // Libere toutes les listes de collision
    ~TableHachage()
    {
        for (std::size_t i = 0; i < tailleTable; ++i)
        {
            Element* courant = table[i];

            while (courant != nullptr)
            {
                Element* temporaire = courant;
                courant = courant->suivant;

                delete temporaire;
            }
        }

        delete[] table;
    }

    // Evite les copies superficielles de la table
    TableHachage(const TableHachage&) = delete;
    TableHachage& operator=(const TableHachage&) = delete;
};

#endif

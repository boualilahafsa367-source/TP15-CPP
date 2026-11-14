
#ifndef LISTE_CHAINEE_HPP
#define LISTE_CHAINEE_HPP

#include <iostream>
#include <cstddef>
#include "Noeud.hpp"

class ListeChainee
{
private:
    Noeud* tete;
    std::size_t nbElements;

public:

    // Iterateur permettant de parcourir la liste
    class Iterator
    {
    private:
        Noeud* courant;

    public:
        explicit Iterator(Noeud* noeud = nullptr)
            : courant(noeud)
        {
        }

        // Accede a la valeur du noeud actuel
        int& operator*() const
        {
            return courant->valeur;
        }

        // Passe au noeud suivant
        Iterator& operator++()
        {
            if (courant != nullptr)
            {
                courant = courant->suivant;
            }

            return *this;
        }

        // Compare deux iterateurs
        bool operator!=(const Iterator& autre) const
        {
            return courant != autre.courant;
        }

        bool operator==(const Iterator& autre) const
        {
            return courant == autre.courant;
        }
    };

    // Constructeur : liste initialement vide
    ListeChainee() : tete(nullptr), nbElements(0)
    {
    }

    // Ajoute un element au debut de la liste
    void ajouterDebut(int valeur)
    {
        Noeud* nouveau = new Noeud(valeur);

        nouveau->suivant = tete;
        tete = nouveau;

        ++nbElements;
    }

    // Ajoute un element a la fin de la liste
    void ajouterFin(int valeur)
    {
        Noeud* nouveau = new Noeud(valeur);

        if (tete == nullptr)
        {
            tete = nouveau;
        }
        else
        {
            Noeud* courant = tete;

            // Recherche du dernier noeud
            while (courant->suivant != nullptr)
            {
                courant = courant->suivant;
            }

            courant->suivant = nouveau;
        }

        ++nbElements;
    }

    // Supprime la premiere occurrence de la valeur
    void supprimer(int valeur)
    {
        if (tete == nullptr)
        {
            std::cout << "La liste est vide." << std::endl;
            return;
        }

        // Cas particulier : suppression de la tete
        if (tete->valeur == valeur)
        {
            Noeud* temporaire = tete;
            tete = tete->suivant;

            delete temporaire;
            --nbElements;
            return;
        }

        Noeud* courant = tete;

        // Recherche du noeud a supprimer
        while (courant->suivant != nullptr &&
               courant->suivant->valeur != valeur)
        {
            courant = courant->suivant;
        }

        if (courant->suivant != nullptr)
        {
            Noeud* temporaire = courant->suivant;
            courant->suivant = temporaire->suivant;

            delete temporaire;
            --nbElements;
        }
        else
        {
            std::cout << "Valeur introuvable : "
                      << valeur << std::endl;
        }
    }

    // Affiche tous les elements de la liste
    void afficher() const
    {
        Noeud* courant = tete;

        std::cout << "Liste : ";

        while (courant != nullptr)
        {
            std::cout << courant->valeur;

            if (courant->suivant != nullptr)
            {
                std::cout << " -> ";
            }

            courant = courant->suivant;
        }

        std::cout << " -> nullptr" << std::endl;
    }

    // Retourne le nombre d'elements
    std::size_t taille() const
    {
        return nbElements;
    }

    // Retourne un iterateur vers le premier element
    Iterator begin() const
    {
        return Iterator(tete);
    }

    // Retourne un iterateur de fin
    Iterator end() const
    {
        return Iterator(nullptr);
    }

    // Liberer tous les noeuds de la liste
    ~ListeChainee()
    {
        Noeud* courant = tete;

        while (courant != nullptr)
        {
            Noeud* temporaire = courant;
            courant = courant->suivant;

            delete temporaire;
        }
    }

    // Evite les copies superficielles dangereuses des pointeurs
    ListeChainee(const ListeChainee&) = delete;
    ListeChainee& operator=(const ListeChainee&) = delete;
};

#endif

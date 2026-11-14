
#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <stdexcept>
#include <cstddef>
#include "NoeudFile.hpp"

class File
{
private:
    NoeudFile* premier;
    NoeudFile* dernier;
    std::size_t nombreElements;
    std::size_t capaciteMax;

public:
    // Constructeur avec une capacite maximale
    explicit File(std::size_t capacite)
        : premier(nullptr),
          dernier(nullptr),
          nombreElements(0),
          capaciteMax(capacite)
    {
    }

    // Verifie si la file est vide
    bool estVide() const
    {
        return premier == nullptr;
    }

    // Verifie si la file a atteint sa capacite
    bool estPleine() const
    {
        return nombreElements >= capaciteMax;
    }

    // Ajoute un element a la fin de la file
    void enfiler(int valeur)
    {
        if (estPleine())
        {
            throw std::overflow_error(
                "Erreur : la file a atteint sa capacite maximale."
            );
        }

        NoeudFile* nouveau = new NoeudFile(valeur);

        if (estVide())
        {
            premier = nouveau;
            dernier = nouveau;
        }
        else
        {
            dernier->suivant = nouveau;
            dernier = nouveau;
        }

        ++nombreElements;
    }

    // Retire et retourne le premier element
    int defiler()
    {
        if (estVide())
        {
            throw std::underflow_error(
                "Erreur : impossible de defiler une file vide."
            );
        }

        NoeudFile* temporaire = premier;
        int valeur = temporaire->valeur;

        premier = premier->suivant;

        // Si la file devient vide, les deux pointeurs sont remis a null
        if (premier == nullptr)
        {
            dernier = nullptr;
        }

        delete temporaire;
        --nombreElements;

        return valeur;
    }

    // Affiche les elements de la file
    void afficher() const
    {
        NoeudFile* courant = premier;

        std::cout << "File : ";

        while (courant != nullptr)
        {
            std::cout << courant->valeur << " ";
            courant = courant->suivant;
        }

        std::cout << std::endl;
    }

    // Retourne le nombre d'elements
    std::size_t taille() const
    {
        return nombreElements;
    }

    // Le destructeur libere tous les noeuds
    ~File()
    {
        while (!estVide())
        {
            NoeudFile* temporaire = premier;
            premier = premier->suivant;
            delete temporaire;
        }

        dernier = nullptr;
    }

    // Evite les copies superficielles de pointeurs
    File(const File&) = delete;
    File& operator=(const File&) = delete;
};

#endif

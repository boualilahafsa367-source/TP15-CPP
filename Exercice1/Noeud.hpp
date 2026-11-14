
#ifndef NOEUD_HPP
#define NOEUD_HPP

// Represente un element de la liste chainee
class Noeud
{
public:
    int valeur;
    Noeud* suivant;

    // Constructeur d'un noeud
    explicit Noeud(int v)
        : valeur(v), suivant(nullptr)
    {
    }
};

#endif

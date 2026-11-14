
#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <string>

// Represente un element de la table de hachage
class Element
{
public:
    int cle;
    std::string valeur;
    Element* suivant;

    // Constructeur d'un element
    Element(int c, const std::string& v)
        : cle(c), valeur(v), suivant(nullptr)
    {
    }
};

#endif


#ifndef NOEUD_FILE_HPP
#define NOEUD_FILE_HPP

// Represente un element de la file d'attente
class NoeudFile
{
public:
    int valeur;
    NoeudFile* suivant;

    // Constructeur du noeud
    explicit NoeudFile(int v)
        : valeur(v), suivant(nullptr)
    {
    }
};

#endif

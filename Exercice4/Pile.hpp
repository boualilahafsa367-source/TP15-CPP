
#ifndef PILE_HPP
#define PILE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

// Exception declenchee lorsqu'on manipule une pile vide.
class PileVideException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur : la pile est vide.";
    }
};

template <typename T>
class Pile {
private:
    // Le vector gere automatiquement la memoire de la pile.
    std::vector<T> elements;

public:
    // Ajoute un element au sommet de la pile.
    void empiler(T element) {
        elements.push_back(element);
    }

    // Retire et retourne l'element situe au sommet.
    T depiler() {
        if (estVide()) {
            throw PileVideException();
        }

        T valeur = elements.back();
        elements.pop_back();
        return valeur;
    }

    // Retourne l'element du sommet sans le supprimer.
    T sommet() const {
        if (estVide()) {
            throw PileVideException();
        }

        return elements.back();
    }

    // Verifie si la pile ne contient aucun element.
    bool estVide() const {
        return elements.empty();
    }

    // Inverse l'ordre des elements de la pile.
    void inverser() {
        std::reverse(elements.begin(), elements.end());
    }

    // Affiche les elements du sommet vers la base.
    void afficher() const {
        if (estVide()) {
            std::cout << "Pile vide." << std::endl;
            return;
        }

        for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
            std::cout << *it << " ";
        }

        std::cout << std::endl;
    }
};

#endif

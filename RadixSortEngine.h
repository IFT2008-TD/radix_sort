//
// Created by Pascal Charpentier on 2023-04-12.
//

#ifndef RADIX_SORT_RADIXSORTENGINE_H
#define RADIX_SORT_RADIXSORTENGINE_H

#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>

/**
 * @class RadixSortEngine
 *
 * Classe permettant d'effectuer un tri de base, sur un vecteur d'entiers positifs, dans une base donnée.
 * Le constructeur doit d'abord être invoqué avec le vecteur à trier et la base demandée.
 * La méthode sort() doit ensuite être appelée et le tri s'effectue sur le vecteur à trier, qui sera donc modifié.
 *
 * Le principe du tri de base est le suivant:
 * Calculer le nombre N de chiffres requis pour représenter tous les nombres du vecteur
 * Pour chaque position allant de 0 à N-1:
 *     Effectuer un tri stable du vecteur sur la valeur de ce chiffre.
 * Donc en base 10, on va trier d'abord sur les unités, puis les dizaines, puis les centaines, etc.
 * Pour éviter un gaspillage de mémoire, on va trier d'abord du vecteur original vers un vecteur gauche.  Puis de gauche
 * vers la droite, et de droite vers la gauche, en alternant jusqu'à ce qu'on ait passé toutes les positions.  En dernier
 * on triera de nouveau vers le vecteur original.
 */
class RadixSortEngine {
public:
    // Constructeur
    explicit RadixSortEngine(std::vector<unsigned long>& v, size_t radix) ;

    // Méthode permettant de déclencher le tri.  Le vecteur fourni au constructeur sera modifié.
    void sort() ;

    // Méthodes de débogage permettant d'afficher les deux vecteurs de files.
    std::string outputLeft() const ;
    std::string outputRight() const ;

private:

    // Méthodes pour gérer les chiffres individuels de chaque nombre
    size_t calculateDigitsForNumber(unsigned long n) const ;
    size_t calculateDigits() const ;
    size_t extractDigitAtPosition(size_t pos, unsigned long n) ;

    // Méthodes permettant de faire une passe de tri
    void initialSortToLeft() ;
    void sortLeftToRight(size_t pos) ;
    void sortRightToLeft(size_t pos) ;
    void sortLeftLast() ;
    void sortRightLast() ;

private:
    std::vector<unsigned long>&     result ; // Référence au vecteur à trier
    size_t                          radix ;  // Base dans laquelle on effectuera le tri
    size_t                          digits ; // Nombre de chiffres requis pour représenter tous les nombres triés
    std::vector<size_t>             powers ; // Puissances de la base requises pour les calculs.

    std::vector<std::queue<unsigned long>> left ;
    std::vector<std::queue<unsigned long>> right ;


};


#endif //RADIX_SORT_RADIXSORTENGINE_H

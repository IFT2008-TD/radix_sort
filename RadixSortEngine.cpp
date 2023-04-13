//
// Created by Pascal Charpentier on 2023-04-12.
//

#include "RadixSortEngine.h"

/**
 * Constructeur du moteur de tri de base.
 * @param v Vecteur contenant les nombres à trier.  Il sera modifié.
 * @param radix Base choisie pour le tri.
 */
RadixSortEngine::RadixSortEngine(std::vector<unsigned long> &v, size_t radix) : result(v), radix(radix), digits(calculateDigits()),
powers(digits), left(radix), right(radix) {

}

/**
 * Tri de base.
 */
void RadixSortEngine::sort() {

}

/**
 * Pour débogage: affichage des éléments du vecteur de gauche
 * @return Un objet string
 */
std::string RadixSortEngine::outputLeft() const {
    std::ostringstream os ;

    os  << "Gauche\n" ;
    size_t pos = 0 ;
    for (auto q: left) {
        os  << pos << " -> " ;
        while (!q.empty()) {
            os << q.front() ;
            q.pop() ;
            os << " - " ;
        }
        os << std::endl ;

    }
    return os.str() ;
}

/**
 * Pour débogage: affichage du contenu du vecteur de droite.
 * @return Un objet string contenant cet affichage
 */
std::string RadixSortEngine::outputRight() const {
    std::ostringstream os ;

    os  << "Droite\n" ;
    size_t pos = 0 ;
    for (auto q: right) {
        os  << pos << " -> " ;
        while (!q.empty()) {
            os << q.front() ;
            q.pop() ;
            os << " - " ;
        }
        os << std::endl ;

    }
    return os.str() ;
}

/**
 * Calcule le nombre de chiffres nécessaires pour représenter un nombre dans la base radix.
 * @param n Nombre dont on veut connaître la représentation
 * @return Le nombre de chiffres de la représentation de n en base radix
 */
size_t RadixSortEngine::calculateDigitsForNumber(unsigned long n) const {
    return 0 ;
}

/**
 * Calcule le nombre minimal de chiffres pour représenter tous les nombres à trier
 * @return Le nombre de chiffres nécessaires
 */
size_t RadixSortEngine::calculateDigits() const {
    return 0 ;
}

/**
 * Calcule le chiffre à une position donnée pour un nombre dans la base radix.
 * @param pos Position du chiffre cherché.
 * @param n Nombre à analyser
 * @return
 */
size_t RadixSortEngine::extractDigitAtPosition(size_t pos, unsigned long n) {
   return 0 ;
}

/**
 * Premier tri du vecteur resultat dans le vecteur de files de gauche.
 */
void RadixSortEngine::initialSortToLeft() {

}

/**
 * Trier les éléments de gauche vers la droite, selon le chiffre à une position donnée.
 * @param pos Position donnée dans la base radix.
 */
void RadixSortEngine::sortLeftToRight(size_t pos) {

}

/**
 * Trie les éléments de la droite vers la gauche, selon la position du chiffre demandée.
 * @param pos Position du chiffre utilisée pour le tri
 */
void RadixSortEngine::sortRightToLeft(size_t pos) {

}

/**
 * Transfert du contenu du vecteur de gauche vers les résultats.
 */
void RadixSortEngine::sortLeftLast() {

}

/**
 * Transfert du contenu du vecteur de droite vers les résultats.
 */
void RadixSortEngine::sortRightLast() {

}







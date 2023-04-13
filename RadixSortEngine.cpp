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
    powers.at(0) = 1 ;
    for (size_t i = 1; i < digits; ++i) powers.at(i) = radix * powers.at(i - 1) ;
}

/**
 * Tri de base.
 */
void RadixSortEngine::sort() {
    if (result.size() < 2) return ;
    initialSortToLeft() ;
    size_t pos = 1 ;
    for ( ; pos < digits; ++pos) {
        if (pos % 2) sortLeftToRight(pos);
        else sortRightToLeft(pos);
    }
    if (pos % 2) sortLeftLast() ;
    else sortRightLast() ;
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
    double logNumber = std::log(n + 1) / std::log(radix) ;
    return static_cast<size_t> (std::ceil(logNumber)) ;
}

/**
 * Calcule le nombre minimal de chiffres pour représenter tous les nombres à trier
 * @return Le nombre de chiffres nécessaires
 */
size_t RadixSortEngine::calculateDigits() const {
    if (result.empty()) throw std::runtime_error("Tentative de trier un vecteur vide") ;
    unsigned long maxElem = *(std::max_element(result.cbegin(), result.cend())) ;
    return calculateDigitsForNumber(maxElem);
}

/**
 * Calcule le chiffre à une position donnée pour un nombre dans la base radix.
 * @param pos Position du chiffre cherché.
 * @param n Nombre à analyser
 * @return
 */
size_t RadixSortEngine::extractDigitAtPosition(size_t pos, unsigned long n) {
    unsigned long quotient = n / powers.at(pos) ;
    return static_cast<size_t> (quotient % radix) ;
}

/**
 * Premier tri du vecteur resultat dans le vecteur de files de gauche.
 */
void RadixSortEngine::initialSortToLeft() {
    for (auto i: result) left.at(i % radix).push(i) ;
}

/**
 * Trier les éléments de gauche vers la droite, selon le chiffre à une position donnée.
 * @param pos Position donnée dans la base radix.
 */
void RadixSortEngine::sortLeftToRight(size_t pos) {
    for (auto& q: left) {
        while (!q.empty()) {
            auto& n = q.front() ; q.pop() ;
            right.at(extractDigitAtPosition(pos, n)).push(n) ;
        }
    }
}

/**
 * Trie les éléments de la droite vers la gauche, selon la position du chiffre demandée.
 * @param pos Position du chiffre utilisée pour le tri
 */
void RadixSortEngine::sortRightToLeft(size_t pos) {
    for (auto& q: right) {
        while (!q.empty()) {
            auto& n = q.front() ; q.pop() ;
            left.at(extractDigitAtPosition(pos, n)).push(n) ;
        }
    }
}

/**
 * Transfert du contenu du vecteur de gauche vers les résultats.
 */
void RadixSortEngine::sortLeftLast() {
    auto it = result.begin() ;
    for (auto& q: left) {
        while (!q.empty()) {
            *it = q.front() ;
            q.pop() ;
            ++ it ;
        }
    }
}

/**
 * Transfert du contenu du vecteur de droite vers les résultats.
 */
void RadixSortEngine::sortRightLast() {
    auto it = result.begin() ;
    for (auto& q: right) {
        while (!q.empty()) {
            *it = q.front() ;
            q.pop() ;
            ++ it ;
        }
    }
}







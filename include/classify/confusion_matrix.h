/**
 * @file confusion_matrix.h
 */

#ifndef _CONFUSION_MATRIX_H_
#define _CONFUSION_MATRIX_H_

#include <utility>
#include <string>
#include <unordered_map>
#include <unordered_set>

/**
 * Allows interpretation of classification errors.
 */
class ConfusionMatrix
{
    public:
        /**
         * Creates an empty confusion matrix.
         */
        ConfusionMatrix();

        /**
         * @param predicted
         * @param actual
         */
        void add(const std::string & predicted, const std::string & actual);

        /**
         * Prints this matrix to cout.
         */
        void print() const;

    private:
        /**
         * Implements a hash function for a pair of strings.
         * @param strPair - the pair of strings
         * @return the hash
         */
        static size_t stringPairHash(const std::pair<std::string, std::string> & strPair);

        /** maps predicted class to actual class frequencies */
        std::unordered_map<std::pair<std::string, std::string>, size_t,
            decltype(&ConfusionMatrix::stringPairHash)> _predictions;

        /** keeps track of the number of classes */
        std::unordered_set<std::string> _classes;

        /** how many times each class was predicted */
        std::unordered_map<std::string, size_t> _counts;
};

#endif
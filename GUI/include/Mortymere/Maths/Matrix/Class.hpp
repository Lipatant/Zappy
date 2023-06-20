/*
** EPITECH PROJECT, 2023
** Mortymere/Maths/Matrix/Class.hpp
** File description:
** -
*/

/// @file
/// @brief Templated matrixes used by the engine

#pragma once

#include <SFML/System/Vector3.hpp>

namespace Mortymere { namespace Maths {

using MatrixDefaultVectorType = sf::Vector3f;
using MatrixDefaultContentValueType = float;
using MatrixSizeType = unsigned int;

template <class T, unsigned int N>
class Matrix {

public: // PUBLIC MEMBERS
    /// @brief Values contains inside the matrix
    T content[N][N];
    /// @brief Stored size of the matrix
    Mortymere::Maths::MatrixSizeType const size;

public: // PUBLIC FUNCTIONS
    /// @brief Apply its transformation to a Matrix of same type
    Mortymere::Maths::Matrix<T, N> transformMatrix( \
        Mortymere::Maths::Matrix<T, N> const &other) const;
    /// @brief Apply its transformation to a Vector3
    sf::Vector3<T> transformVector(sf::Vector3<T> const position) const;

public: // OPERATORS
    void operator=(Mortymere::Maths::Matrix<T, N> const &other);
    sf::Vector3<T> operator*(sf::Vector3<T> const position) const;
    Mortymere::Maths::Matrix<T, N> \
        operator*(Mortymere::Maths::Matrix<T, N> const &other) const;
    void operator*=(Mortymere::Maths::Matrix<T, N> const &other);

public: // CONSTRUCTOR AND DESTRUCTOR
    Matrix(void);
    Matrix(Mortymere::Maths::Matrix<T, N> const &other);
    ~Matrix(void);

};

/// @brief Matrix of size 2x2
using Matrix2 = Mortymere::Maths::Matrix \
    <Mortymere::Maths::MatrixDefaultContentValueType, 2>;
/// @brief Matrix of size 3x3
using Matrix3 = Mortymere::Maths::Matrix \
    <Mortymere::Maths::MatrixDefaultContentValueType, 3>;
/// @brief Matrix of size 4x4
using Matrix4 = Mortymere::Maths::Matrix \
    <Mortymere::Maths::MatrixDefaultContentValueType, 4>;

}};

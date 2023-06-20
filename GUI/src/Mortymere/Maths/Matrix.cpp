/*
** EPITECH PROJECT, 2023
** Mortymere/Maths/Matrix.cpp
** File description:
** -
*/

#include "Mortymere/Maths/Matrix.hpp"

#define COMMA ,
#define MATRIX_SIZE_TYPE Mortymere::Maths::MatrixSizeType
#define MATRIX(TYPE) \
    template <class T, unsigned int N> TYPE Mortymere::Maths::Matrix<T, N>

MATRIX()::Matrix(void) : size(N)
{
    for (MATRIX_SIZE_TYPE x = 0; x < N; x++)
        for (MATRIX_SIZE_TYPE y = 0; y < N; y++)
            content[x][y] = (x == y) ? 1 : 0;
}

MATRIX()::Matrix(Mortymere::Maths::Matrix<T, N> const &other) : size(N)
{
    for (MATRIX_SIZE_TYPE x = 0; x < N; x++)
        for (MATRIX_SIZE_TYPE y = 0; y < N; y++)
            content[x][y] = other.content[x][y];
}

MATRIX()::~Matrix(void)
{ }

MATRIX(void)::operator=(Mortymere::Maths::Matrix<T, N> const &other)
{
    for (MATRIX_SIZE_TYPE x = 0; x < N; x++)
        for (MATRIX_SIZE_TYPE y = 0; y < N; y++)
            content[x][y] = other.content[x][y];
}

MATRIX(Mortymere::Maths::Matrix<T COMMA N>)::operator*( \
    Mortymere::Maths::Matrix<T, N> const &other) const
{
    return transformMatrix(other);
}

MATRIX(sf::Vector3<T>)::operator*(sf::Vector3<T> const position) const
{
    return transformVector(position);
}

MATRIX(void)::operator*=(Mortymere::Maths::Matrix<T, N> const &other)
{
    operator=(transformMatrix(other));
}

MATRIX(Mortymere::Maths::Matrix<T COMMA N>)::transformMatrix( \
    Mortymere::Maths::Matrix<T, N> const &other) const
{
    Mortymere::Maths::Matrix<T, N> returned;

    for (MATRIX_SIZE_TYPE x = 0; x < N; x++)
        for (MATRIX_SIZE_TYPE y = 0; y < N; y++)
            returned.content[x][y] = \
                content[x][0] * other.content[0][y] +
                content[x][1] * other.content[1][y] +
                content[x][2] * other.content[2][y] +
                content[x][3] * other.content[3][y];
    return returned;
}

MATRIX(sf::Vector3<T>)::transformVector(sf::Vector3<T> const position) const
{
    T returnedValues[4] = {0, 0, 0, 0};

    if (size < 4)
        return {0, 0, 0};
    for (unsigned char i = 0; i < 3; i++)
        returnedValues[i] = position.x * content[0][i] + position.y * \
            content[1][i] + position.z * content[2][i] + content[3][i];
    return {returnedValues[0], returnedValues[1], returnedValues[2]};
}

template class Mortymere::Maths::Matrix \
    <Mortymere::Maths::MatrixDefaultContentValueType, 2>;
template class Mortymere::Maths::Matrix \
    <Mortymere::Maths::MatrixDefaultContentValueType, 3>;
template class Mortymere::Maths::Matrix \
    <Mortymere::Maths::MatrixDefaultContentValueType, 4>;

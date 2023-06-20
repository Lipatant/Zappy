/*
** EPITECH PROJECT, 2023
** Mortymere/Maths/Matrix/Create.cpp
** File description:
** -
*/

#include <cmath>
#include <initializer_list>
#include "Mortymere/Maths/Matrix/Calls.hpp"
#include "Mortymere/Maths/Matrix/Class.hpp"

#define MATHS Mortymere::Maths
#define VALUE_TYPE Mortymere::Maths::MatrixDefaultContentValueType
#define VECTOR_TYPE Mortymere::Maths::MatrixDefaultVectorType
#define TO_RADIAN (M_PI / 180)

static MATHS::Matrix4 createRotationMatrix(VALUE_TYPE const rotation, \
    unsigned char const coor1, unsigned char const coor2, bool const invert)
{
    MATHS::Matrix4 rotate;
    float rot = rotation * TO_RADIAN;
    unsigned char coordinates[2] = {coor1, coor2};

    for (unsigned char const x: coordinates) {
        for (unsigned char const y: coordinates) {
            if (x == y)
                rotate.content[x][y] = cosf(rot);
            else
                rotate.content[x][y] = sinf(rot) * \
                    (((x < y) ? -1 : 1) * (invert ? -1 : 1));
        }
    }
    return rotate;
}

MATHS::Matrix4 MATHS::createRotationMatrixX(VALUE_TYPE const rotation)
{
    return createRotationMatrix(rotation, 1, 2, true);
}

MATHS::Matrix4 MATHS::createRotationMatrixY(VALUE_TYPE const rotation)
{
    return createRotationMatrix(rotation, 0, 2, false);
}

MATHS::Matrix4 MATHS::createRotationMatrixZ(VALUE_TYPE const rotation)
{
    return createRotationMatrix(rotation, 0, 1, false);
}

MATHS::Matrix4 MATHS::createScalingMatrix(VALUE_TYPE const scale)
{
    MATHS::Matrix4 scaling;

    scaling.content[0][0] = scale;
    scaling.content[1][1] = scale;
    scaling.content[2][2] = scale;
    return scaling;
}

MATHS::Matrix4 MATHS::createScalingMatrix(VECTOR_TYPE const scale)
{
    MATHS::Matrix4 scaling;

    scaling.content[0][0] = scale.x;
    scaling.content[1][1] = scale.y;
    scaling.content[2][2] = scale.z;
    return scaling;
}

MATHS::Matrix4 MATHS::createTranslationMatrix(VECTOR_TYPE const position)
{
    MATHS::Matrix4 translation;

    translation.content[3][0] = position.x;
    translation.content[3][1] = position.y;
    translation.content[3][2] = position.z;
    return translation;
}

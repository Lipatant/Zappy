/*
** EPITECH PROJECT, 2023
** Mortymere/Maths/Matrix/Calls.hpp
** File description:
** -
*/

/// @file
/// @brief Contains function used for generating matrixes

#pragma once

#include <SFML/System/Vector3.hpp>
#include "Mortymere/Maths/Matrix/Class.hpp"

namespace Mortymere { namespace Maths {

/// @brief Create a rotation matrix through the X axis
/// @param rotation (MatrixDefaultContentValueType const) Value of the rotation
///     IN DEGREES
Mortymere::Maths::Matrix4 createRotationMatrixX( \
    Mortymere::Maths::MatrixDefaultContentValueType const rotation);
/// @brief Create a rotation matrix through the Y axis
/// @param rotation (MatrixDefaultContentValueType const) Value of the rotation
///     IN DEGREES
Mortymere::Maths::Matrix4 createRotationMatrixY( \
    Mortymere::Maths::MatrixDefaultContentValueType const rotation);
/// @brief Create a rotation matrix through the Z axis
/// @param rotation (MatrixDefaultContentValueType const) Value of the rotation
///     IN DEGREES
Mortymere::Maths::Matrix4 createRotationMatrixZ( \
    Mortymere::Maths::MatrixDefaultContentValueType const rotation);

Mortymere::Maths::Matrix4 createScalingMatrix( \
    Mortymere::Maths::MatrixDefaultContentValueType const scale);
Mortymere::Maths::Matrix4 createScalingMatrix( \
    Mortymere::Maths::MatrixDefaultVectorType const scale);

/// @brief Create a translation matrix
/// @param position (MatrixDefaultVectorType const) Origin of the translation
Mortymere::Maths::Matrix4 createTranslationMatrix( \
    Mortymere::Maths::MatrixDefaultVectorType const position);

}};

#pragma once

#include <QMatrix4x4>

QMatrix4x4 rotationMatrix(float angle, float x, float y, float z);
QMatrix4x4 translationMatrix(float x, float y, float z);
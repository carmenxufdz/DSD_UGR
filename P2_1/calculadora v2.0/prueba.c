#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y, z;
} vector3d;

// Function to add two vectors
vector3d addVectors(vector3d a, vector3d b) {
    return (vector3d){a.x + b.x, a.y + b.y, a.z + b.z};
}

// Function to subtract two vectors
vector3d subtractVectors(vector3d a, vector3d b) {
    return (vector3d){a.x - b.x, a.y - b.y, a.z - b.z};
}

// Function to calculate the dot product of two vectors
double dotProduct(vector3d a, vector3d b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Function to calculate the cross product of two vectors
vector3d crossProduct(vector3d a, vector3d b) {
    return (vector3d){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

// Function to multiply a vector by a scalar
vector3d multiplyVectorByScalar(vector3d a, double scalar) {
    return (vector3d){a.x * scalar, a.y * scalar, a.z * scalar};
}

#include <iostream>
#include <vector>

template <typename T>
using m = std::vector<std::vector<T>>;

struct matrix {
    int fil;
    int col;
    m<double> m;
};

matrix addMatrices(const matrix &a, const matrix &b) {
    if (a.fil != b.fil || a.col != b.col) {
        throw std::invalid_argument("Matrices must have the same dimensions");
    }
    matrix c;
    c.fil = a.fil;
    c.col = a.col;
    c.m.resize(a.fil, std::vector<double>(a.col));
    for (int i = 0; i < a.fil; i++) {
        for (int j = 0; j < a.col; j++) {
            c.m[i][j] = a.m[i][j] + b.m[i][j];
        }
    }
    return c;
}

matrix subtractMatrices(const matrix &a, const matrix &b) {
    if (a.fil != b.fil || a.col != b.col) {
        throw std::invalid_argument("Matrices must have the same dimensions");
    }
    matrix c;
    c.fil = a.fil;
    c.col = a.col;
    c.m.resize(a.fil, std::vector<double>(a.col));
    for (int i = 0; i < a.fil; i++) {
        for (int j = 0; j < a.col; j++) {
            c.m[i][j] = a.m[i][j] - b.m[i][j];
        }
    }
    return c;
}

matrix multiplyMatrices(const matrix &a, const matrix &b) {
    if (a.col != b.fil) {
       throw std::invalid_argument("Matrices have incompatible dimensions");
    }
    matrix c;
    c.fil = a.fil;
    c.col = b.col;
    c.m.resize(a.fil, std::vector<double>(b.col));
    for (int i = 0; i < a.fil; i++) {
        for (int j = 0; j < b.col; j++) {
            c.m[i][j] = 0;
            for (int k = 0; k < a.col; k++) {
                c.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return c;
}


std::ostream &operator<<(std::ostream &os, const matrix &m) {
    os << "[";
    for (int i = 0; i < m.fil; i++) {
        os << "[";
        for (int j = 0; j < m.col; j++) {
            os << m.m[i][j];
            if (j < m.col - 1) {
                os << ", ";
            }
        }
        os << "]";
        if (i < m.fil - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
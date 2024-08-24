#pragma once
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Ponto;

typedef struct {
    Ponto a;
    Ponto b;
    Ponto c;
} Triangulo;

typedef enum {
    NAO_TRIANGULO = 0,
    TRIANGULO_EQUILATERO = 1,
    TRIANGULO_ISOSCELES = 2,
    TRIANGULO_ESCALENO = 3
} TipoTriangulo;

void imprimeTriangulo(Triangulo t);
bool ehTriangulo(Triangulo t);
bool pontoPertenceAoTriangulo(Triangulo t, Ponto p);
double areaTriangulo(Triangulo t);
double perimetroTriangulo(Triangulo t);
TipoTriangulo tipoTriangulo(Triangulo t);

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangulo.h"

void imprimeTriangulo(Triangulo t) {
    printf("O triangulo tem as seguintes coordenadas:\n");
    const char *format = "Ponto A: (%d, %d)\nPonto B: (%d, %d)\nPonto C: (%d, %d)\n";
    printf(format, t.a.x, t.a.y, t.b.x, t.b.y, t.c.x, t.c.y);
}

bool pontosSaoIguais(Ponto p1, Ponto p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

int abs(int number) {
    return (number < 0) ? -number : number;
}

bool verificaCalculoLado(int diferenca, int lado1, int lado2, int lado3) {
    return diferenca < lado1 && lado1 < (lado2 + lado3);
}

// Recebe dois pontos e devolve a medida de um lado.
double calculaDistancia(Ponto ponto1, Ponto ponto2) {
    return sqrt(pow(ponto1.x - ponto2.x, 2) + pow((ponto1.y - ponto2.y), 2));
}

bool ehTriangulo(Triangulo t) {
    const double lado1 = calculaDistancia(t.a, t.b);
    const double lado2 = calculaDistancia(t.b, t.c);
    const double lado3 = calculaDistancia(t.c, t.a);
    const double diferencaAB = abs(lado1 - lado2);
    const double diferencaBC = abs(lado2 - lado3);
    const double diferencaCA = abs(lado3 - lado1);

    if (verificaCalculoLado(diferencaBC, lado1, lado2, lado3) &&
        verificaCalculoLado(diferencaCA, lado2, lado1, lado3) &&
        verificaCalculoLado(diferencaAB, lado3, lado1, lado2)) {
        return true;
    }

    return false;
}

double produtoCruzado(Ponto p, Ponto p2) {
    return (p.x * p2.y) - (p.y * p2.x);
}

bool pontoPertenceAoTriangulo(Triangulo t, Ponto p) {
    const Ponto figura1 = (Ponto) {p.x - t.a.x, p.y - t.a.y};
    const Ponto figura2 = (Ponto) {p.x - t.b.x, p.y - t.b.y};
    const Ponto figura3 = (Ponto) {p.x - t.c.x, p.y - t.c.y};

    const pc1 = produtoCruzado((Ponto) {t.a.x, t.b.x, t.a.y, t.b.y}, figura1);
    const pc2 = produtoCruzado((Ponto) {t.b.x, t.c.x, t.b.y, t.c.y}, figura2);
    const pc3 = produtoCruzado((Ponto) {t.c.x, t.a.x, t.c.y, t.a.y}, figura3);

    return pc1 >= 0 && pc2 >= 0 && pc3 >= 0;
}



// Produto cruzado = x1p * (y2p - y3p)
double areaTriangulo(Triangulo t) { //Ao implementar uma função, usem o parâmetro que ela recebe. E só pensem nele!
    int ponto1 = t.a.x * (t.b.y - t.c.y);
    int ponto2 = t.b.x * (t.a.y - t.c.y);
    int ponto3 = t.c.x * (t.a.y - t.b.y);

    int areaTriangulo = ponto1 + ponto2 + ponto3;

    return abs(areaTriangulo) * 0.5;
}

// Perimetro = lado1 + lado2 + lado3;
// lado1 = sqrt((x1 - x2)^2 + (y1 - y2)^2);
double perimetroTriangulo(Triangulo t) {
    return calculaDistancia(t.a, t.b) + calculaDistancia(t.b, t.c) + calculaDistancia(t.c, t.a);
}

TipoTriangulo tipoTriangulo(Triangulo t){
    if (!ehTriangulo(t)) {
        return NAO_TRIANGULO;
    } 

    const double lado1 = calculaDistancia(t.a, t.b);
    const double lado2 = calculaDistancia(t.b, t.c);
    const double lado3 = calculaDistancia(t.c, t.a);

    if (lado1 == lado2 && lado2 == lado3 && lado3 == lado1) {
        return TRIANGULO_EQUILATERO;
    }
    if (lado1 != lado2 && lado2 != lado3 && lado1 != lado3) {
        return TRIANGULO_ESCALENO;
    }

    return TRIANGULO_ISOSCELES;
}

#include "dataset.c"
int main() {
    Triangulo t = { (Ponto) {8, 6}, (Ponto) {9, 5}, (Ponto) {2, 4} };
    imprimeTriangulo(t);

    for (int i = 0; i < 21; i++) {
        printf("ehTriangulo: %d\n", ehTriangulo(triangulos[i]));
    }
}

/* A matemática representa assim: (x, y)
printf("(%d) %d", t.a.x, t.a.y);
*/
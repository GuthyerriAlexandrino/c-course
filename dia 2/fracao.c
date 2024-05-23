#include <stdio.h>

// structs x condicional

struct Fracao {
    int numerador;
    int denominador;
};

// altura / 100 = primeiro_digito => 1;
// primeiro_digito * 100 = valor_inteiro => 100;
// altura - valor_inteiro = decimais => 20;
// printf("%d.%d", primeiro_digito, decimais);

// Assume que denominadores são iguais
struct Fracao soma_fracao(struct Fracao f1, struct Fracao f2) {
    return (struct Fracao) { f1.numerador + f2.numerador, f1.denominador};
}

// Assume que denominadores são iguais
struct Fracao subtracao_fracao(struct Fracao f1, struct Fracao f2) { 
    return (struct Fracao) { f1.numerador - f2.numerador, f1.denominador};
}

struct Fracao multiplica_fracao(struct Fracao f1, struct Fracao f2) {
    return (struct Fracao) {f1.numerador * f2.numerador, f1.denominador * f2.denominador};
}

void printa_fracao(struct Fracao* fracao) {
    printf("%d/%d\n", fracao->numerador, fracao->denominador);
}

int main() {
    struct Fracao fracao_1 = {.numerador = 10, .denominador = 20 }; //{.numerador = 10, .denominador = 20}
    struct Fracao fracao_2 = { 50, 20 };  // {50, 20}
    struct Fracao resultado_1 = soma_fracao(fracao_1, fracao_2);
    printa_fracao(&resultado_1);

    struct Fracao resultado_2 = subtracao_fracao(fracao_2, fracao_1);
    printa_fracao(&resultado_2);

    struct Fracao resultado_3 = multiplica_fracao(fracao_1, fracao_2);
    printa_fracao(&resultado_3);
}
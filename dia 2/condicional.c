#include <stdio.h>
#include <stdbool.h>

/* Operadores Relacionais
== Checa igualdade
!= Checa desigualdade
>= Checa se o lado esquerdo é maior ou igual que o lado direito
<= Checa se o lado esquerdo é menor ou igual que o lado direito
< Checa se o lado esquerdo é menor que o lado direito
> Checa se o lado esquerdo é manor que o lado direito
*/


// Manu disse para Guthyerri traga 1 bandeija de ovo, 
// se tiver leite e se a carne de boi estiver a R$ 14.65, traga 4.

void questao1() {
    // Em casa
    int bandeija_ovo = 0;
    int tem_leite = 1; // Tudo que não é 0 = falso
    double carne_boi = 15.00;

    // Cheguei no mercado
    bandeija_ovo += 1;

    if (tem_leite) {
        if (carne_boi == 14.65) {
            bandeija_ovo = 4; // bandeija_ovo = bandeija_ovo + 4;
        }
    }
    printf("Tinha %d\n", bandeija_ovo);
}

bool os_flutuantes_sao_iguais(double x1, double x2) {
    double epsilon = 0.0001; // Tolerância decimal
    double diferenca = (x1 - x2);
    double diferenca_absoluta = (diferenca < 0) ? -diferenca : diferenca;
    return diferenca_absoluta < epsilon;
}
// Querop: -20 => 20
// -(-20) = 40
// -20 * -1 = -(-20) => numero * -1 = -numero

// Manu disse para Guthyerri traga 1 bandeija de ovo, 
// se tiver leite ou se a carne de boi estiver a R$ 14.65, traga 4.
void questao2() {
    // Em casa
    int bandeija_ovo = 0;
    int leite = false;
    double valor_carne = 14.65;

    //Supermercado
    bandeija_ovo = 1;
    if (leite) {
        bandeija_ovo = 4;
    }
    if (os_flutuantes_sao_iguais(valor_carne, 14.65)) {
        bandeija_ovo = 4;   
    }
    printf("Aqui estao %d ovos", bandeija_ovo);
}

int main() {
    questao1();
    questao2();
}
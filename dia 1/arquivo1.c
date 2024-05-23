// MEM00 = MEM02 -> MEM01
// MEM01 = 11111111 11111111 11111111 11111111
// MEM02 = 11111111 11111111 11111111 11111111

// 8 bits
// 16 bits
// 32 bits
// 64 bits

// // C lang
// // Tipos de dados
// int; // Inteiros -> 4 bytes
// char; // Caracteres -> 1 byte
// float; // Numeros quebrados -> 4 bytes
// double; // Numeros quebrados com o dobro de precisão -> 8 bytes
// void; // Nada -> 1 byte
// void*; // Ponteiro para alguma coisa -> 8 bytes

// // Modificadores de tipo
// long;
// short;
// unsigned;

// %d -> Inteiro
// %c -> Caractere
// %x -> Inteiro em Hexadecimal
// %f -> Ponto flutuante (Número quebrado)
// %lf -> Ponto flutuante de dupla precisão

#include <stdio.h> // Inclui a biblioteca de entrada e saída padrão

int soma_int(int a, int b) { // A função soma_int recebe dois argumentos inteiros e retorna um inteiro.
    return a + b;
}

float soma_float(int a, int b) {
    return a + b;
}

void recebe_numeros(int* guthyerri, int* manu) { // { 0x00FB6A -> 0x00FB64 }
    scanf("%d %d", guthyerri, manu);
}

int main() {
    int a = 0; // a = { Endereço e um valor } | 0x00FB64 -> 2
    int b = 0;

    recebe_numeros(&a, &b);
    printf("%d", soma_int(a, b));
    recebe_numeros(&a, &b);
    printf("%d", soma_int(a, b));
}

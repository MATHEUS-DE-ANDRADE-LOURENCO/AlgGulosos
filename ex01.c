# include <stdio.h>

float max(float v[], int n) {
    float maior;
    for(int i = 0; i < n; i++) {
        if(v[i] > maior || i == 0) maior = v[i];
    }

    return maior;
}

float somarConts(int v[], int n) {
    int soma = 0;
    for(int i = 0; i < n; i ++) soma += v[i];
    return soma;
}

void zerarPosicao(float v[], int n, int e) {
    for(int i = 0; i < n; i++) {
        if(v[i] == e) v[i] == 0;
    }
}

void printSolucao(int contNotas[], int contMoedas[]) {
    printf("\nNOTAS\n");
    printf("\nNotas de 2: %d", contNotas[1]);
    printf("\nNotas de 5: %d", contNotas[2]);
    printf("\nNotas de 10: %d", contNotas[3]);
    printf("\nNotas de 20: %d", contNotas[4]);
    printf("\nNotas de 50: %d", contNotas[5]);
    printf("\nNotas de 100: %d", contNotas[6]);

    printf("\n\nMOEDAS: \n");
    printf("\nMoeda de 1: %d", contNotas[0]);
    printf("\nMoeda de 5: %d", contMoedas[0]);
    printf("\nMoeda de 10: %d", contMoedas[1]);
    printf("\nMoeda de 20: %d", contMoedas[2]);
    printf("\nMoeda de 50: %d", contMoedas[3]);
    printf("\nMoeda de 100: %d", contMoedas[4]);
}   

int troco (float valor) {
    float notas[7] = {1, 2, 5, 10, 20, 50, 100};
    float moedas[5] = {0.01, 0.05, 0.1, 0.25, 0.5};

    int solucaoNotas[7] = {0, 0, 0, 0, 0, 0, 0};
    int solucaoMoedas[5] = {0, 0, 0, 0, 0};

    int soma = 0;

    // Dividindo entre parte inteira e fracionária
    int cedulas = valor;
    float coins = valor - cedulas;

    int somaNotas = 0;
    // Enquanto não encontrar o valor para as cédulas
    while(somaNotas <= cedulas || somarConts(solucaoNotas, 7) != 0) {
        int din = max(notas, 6);
        if(somaNotas + din <= cedulas) somaNotas += din;
        else zerarPosicao(notas, 7, din);
        if (somarConts(solucaoNotas, 7)) return -1;
    }

    float somaMoedas = 0;
    // Enquanto não encontrar o valor para as moedas
    while(somaMoedas <= coins || somarConts(solucaoMoedas, 5) != 0) {
        float md = max(notas, 6);
        if(somaNotas + md <= cedulas) somaNotas += md;
        else zerarPosicao(notas, 7, md);
        if (somarConts(solucaoMoedas, 7)) return -1;
    }

    if (somaMoedas != coins) return -1;

    printSolucao(solucaoNotas, solucaoMoedas);

    return 1;
}

int main() {
    int valor = 576.73;

    if(troco(valor)) printf("\nBoa mano, conseguiu");
    else printf("\nNão conseguiu");
}
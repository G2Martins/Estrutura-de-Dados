#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[20];
    int valor;
} Cogumelo;

int main() {
    Cogumelo cogumelos[] = {
        {"Shitake", 10},
        {"Portobello", 8},
        {"Shimeji", 6},
        {"Champignon", 12},
        {"Funghi", 16},
        {"Porcini", 16}
    };

    char escolha[20];
    scanf("%19s", escolha);

    int indice_escolhido = -1;
    for (int i = 0; i < sizeof(cogumelos) / sizeof(cogumelos[0]); i++) {
        if (strcmp(escolha, cogumelos[i].nome) == 0) {
            indice_escolhido = i;
            break;
        }
    }

    if (indice_escolhido == -1) {
        printf("Cogumelo não encontrado.\n");
        return 1;
    }

    int numeroSugestoes = 0;
    for (int i = 0; i < sizeof(cogumelos) / sizeof(cogumelos[0]); i++) {
        if (numeroSugestoes < 2 && cogumelos[i].valor < cogumelos[indice_escolhido].valor) {
            printf("%s - Valor: %d\n", cogumelos[i].nome, cogumelos[i].valor);
            numeroSugestoes++;
        }
    }

    if (numeroSugestoes == 0) {
        printf("Desculpe, não há sugestões disponíveis.\n");
    }

    return 0;
}

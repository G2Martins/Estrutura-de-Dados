#include <stdio.h>
#include <math.h>

int mediaVeiculosHora(int tamanho, int veiculos[]) {
  int i, soma = 0;
  float media;
  for (i = 0; i < tamanho; i++) {
    soma += veiculos[i];
  }
  media = soma / tamanho;
  media = round(media);
  //TODO: Retornar a média arredondando o valor por meio da função "round".
  return media;
}

int main() {
    int tamanho, i;
    float media;

    scanf("%d", &tamanho);

    int veiculos[tamanho];
    for (i = 0; i < tamanho; i++) {
      scanf("%d", &veiculos[i]);
    }

    //TODO: Chamar a função "mediaVeiculosHora" e imprimir a saída de acordo com o enunciado.
    media = mediaVeiculosHora(tamanho, veiculos);
    
    printf("Média de veículos por hora: %.f", media);
    return 0;
}
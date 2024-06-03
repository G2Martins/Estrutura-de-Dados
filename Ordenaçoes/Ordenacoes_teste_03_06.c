#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void bubble(int *V, int n);
void mostrar_vetor(int *vet, int tamanho);
void insertionSort(int *V, int n);
void quicksort(int *vet,  int inicio, int fim);


int main() {
    int menuLoop = 1;
    int opcao;
    
    do{
        system("cls || clear");

        printf("+----------------- MENU ------------------+\n");
        printf("+- Escolha o tipo de ordenacao:          -+\n");
        printf("+- 1. Ordenacao por Bubble Vet 1         -+\n");
        printf("+- 2. Ordenacao por Bubble Vet 2         -+\n");
        printf("+- 3. Ordenacao por InsertionSort Vet 1  -+\n");
        printf("+- 4. Ordenacao por InsertionSort Vet 2  -+\n");
        printf("+- 5. Ordenacao por QuickSort Vet 1      -+\n");
        printf("+- 6. Ordenacao por QuickSort Vet 2      -+\n");
        printf("+- 7. Ordenacao por SelectionSort Vet 1  -+\n");
        printf("+- 8. Ordenacao por SelectionSort Vet 2  -+\n");
        printf("+- 9. Ordenacao por MergeSort Vet 1      -+\n");
        printf("+- 0. Sair                               -+\n");
        printf("+- Digite a opcao: ");
        scanf("%d", &opcao);
        
        // POSIÇÃO                0   1  2   3   4   5   6   7   8   9   10  11
        int vetorDesordenado[] = {28, 1, 37, 45, 22, 83, 98, 76, 24, 69, 17, 13}; 
        //                        1, 13, 17, 22, 24, 28, 37, 45, 69, 76, 83 ,98
        
        // POSIÇÃO                 0   1  2   3   4   5   6  7  8   9   10  11
        int vetorDesordenado2[] = {20, 1, 86, 32, 94, 18, 7, 5, 30, 14, 83, 52}; 
        //                         1,
        
        int n = sizeof(vetorDesordenado) / sizeof(vetorDesordenado[0]);
        
        // sizeof(vetorDesordenado) retorna o tamanho total do array em bytes.
        //sizeof(vetorDesordenado[0]) retorna o tamanho de um único elemento do array (nesse caso, o tamanho de um int).
        // A divisão desses dois valores resulta no número de elementos no array, que é armazenado na variável n
        
        switch(opcao) {
            case 1:
                bubble(vetorDesordenado, n);
                printf("\nArray ordenado por Bubble do vet 1: \n");
                mostrar_vetor(vetorDesordenado, n);
                sleep(4);
                break;

            case 2:
                bubble(vetorDesordenado2, n);
                printf("\nArray ordenado por Bubble do vet 2: \n");
                mostrar_vetor(vetorDesordenado2, n);
                sleep(4);
                break;

            case 3:
                insertionSort(vetorDesordenado, n);
                printf("\nVetor ordenado por InsertionSort do vet 1: \n");
                mostrar_vetor(vetorDesordenado, n);
                sleep(4);
                break;

            case 4:
                insertionSort(vetorDesordenado2, n);
                printf("\nVetor ordenado por InsertionSort do vet 2: \n");
                mostrar_vetor(vetorDesordenado2, n);
                sleep(4);
                break;

            case 5:
                quicksort(vetorDesordenado, 0, 11);
                printf("\nVetor ordenado por QuickSort do vet 1: \n");
                mostrar_vetor(vetorDesordenado, n);
                sleep(4);
                break;
            
            case 6:
                quicksort(vetorDesordenado2, 0, 11);
                printf("\nVetor ordenado por QuickSort do vet 2: \n");
                mostrar_vetor(vetorDesordenado2, n);
                sleep(4);
                break;

            case 0:
                menuLoop = 0;
                break;

            default:
                printf("Opção inválida!\n");
        }

    }while(menuLoop != 0);

    return 0;
}

void bubble(int *V, int n){
    int continua, aux, fim = n;

    do{
        continua = 0;
        for(int i = 0; i < fim - 1; i++)
        {
            if(V[i] > V[i + 1])
            {
                aux = V[i];
                V[i] = V[i + 1];
                V[i + 1] = aux;
                continua = i;
            }

        }
        fim --;
    }while(continua != 0);
}

void mostrar_vetor(int *vet, int tamanho) {
    
    for (int i = 0; i < tamanho; i++) {
        
        printf("%d", vet[i]);
        
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    
    printf("\n\n");
}

void insertionSort(int *V, int n){
    int i, j, aux;

    for(i = 1; i < n; i++)
    {
        aux = V[i];
        
        for(j = i; (j > 0) && (aux < V[j - 1]); j--)
        {
            V[j] = V[j - 1];
        }
        
        V[j] = aux;
    }
}

void quicksort(int *vet,  int inicio, int fim) 
{
    // Verifica se a faixa do vetor possui mais de um elemento
    if (inicio > fim)
        return;

    // Declaração das variáveis para o pivô e para as trocas
     int pivo, aux, troca;

    // Define o pivô como o primeiro elemento da faixa
    pivo = inicio;

    // Define o índice auxiliar como o último elemento da faixa
    aux = fim;

    // Loop enquanto o pivô não alcançar o índice auxiliar
    while (pivo != aux) 
    {
        // Se o pivô for menor que o índice auxiliar
        if (pivo < aux)
        {
            // Se o elemento no pivô for maior que o elemento no índice auxiliar
            if (vet[pivo] > vet[aux]) 
            {
                // Troca os elementos nos índices pivô e auxiliar
                troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = troca;

                // Troca os índices pivô e auxiliar
                troca = pivo;
                pivo = aux;
                aux = troca;
            }
        }
        // Se o pivô for maior que o índice auxiliar
        else 
        {
            // Se o elemento no pivô for menor que o elemento no índice auxiliar
            if (vet[pivo] < vet[aux]) 
            {
                // Troca os elementos nos índices pivô e auxiliar
                troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = troca;

                // Troca os índices pivô e auxiliar
                troca = pivo;
                pivo = aux;
                aux = troca;
            }
        }

        // Move o índice auxiliar em direção ao pivô ou para longe do pivô
        if (pivo < aux) 
        {
            aux--;
        } 
        else 
        {
            aux++;
        }
    }

    // Chamadas recursivas do quicksort para as subfaixas à esquerda e à direita do pivô
    quicksort(vet, inicio, pivo - 1);
    quicksort(vet, pivo + 1, fim);
}

void selectionSort(){
    
}
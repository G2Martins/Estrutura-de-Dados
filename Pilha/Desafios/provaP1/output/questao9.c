#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 10

char pilha[TAM];

int topo=0;

char pop();
int push(char x);

int main(){
    int qtd_teste;

    scanf("%d", &qtd_teste);


    return 0;
}

int push(char x)
{
    if (topo==TAM)
    {
        return 0;
    }

    pilha[topo] = x;
    topo++;
    return 1;
}

char pop()
{
    if (topo==0)
    {
        return ' ';
    }
    else
    {
        topo--;
        return pilha[topo];
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"
#include "queue.h"
#include "grafo.h"

int main(){
    Grafo *g = novoGrafo(7);
    int i;
    adicionarAresta(g, 'A', 'B');
    adicionarAresta(g, 'A', 'D');
    adicionarAresta(g, 'B', 'C');
    adicionarAresta(g, 'B', 'F');
    adicionarAresta(g, 'C', 'E');
    adicionarAresta(g, 'D', 'E');
    adicionarAresta(g, 'E', 'B');
    adicionarAresta(g, 'G', 'C');
    adicionarAresta(g, 'G', 'F');
    marcar(g, 0); //marcando a flag do visitado como 0 pra inidicar que o elemento ainda não foi visitado
    /*for(i = 0; i < g->quantidade; i++){
        if(g->vetor[i].visitado == 0) //se o elemento ainda nao foi visitado
            dfs(g, i + 65);
    }*/
    for(i = 0; i < g->quantidade; i++){
        if(g->vetor[i].visitado == 0) //se o elemento ainda nao foi visitado
            bfs(g, i + 65);
    }
    return 0;
}

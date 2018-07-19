#define MAX 50

typedef struct Vertice{
    int visitado;
    Fila *f;
}Vertice;

typedef struct Grafo{ //vai armazenar vários vértices
    Vertice vetor[MAX];
    int quantidade;
}Grafo;

Grafo * novoGrafo(int quant){
    int i;
    Grafo *novo = (Grafo *)malloc(sizeof(Grafo));
    novo->quantidade = quant;
    for(i = 0; i < quant; i++){
        novo->vetor[i].f = novaFila();
    }
    return novo;
}

void adicionarAresta(Grafo *g, char origem, char destino){
    Elemento elem;
    elem.letra = destino;
    enfileirar(g->vetor[origem-65].f, elem); //diminui 65 porque A (que é o que eu quero como índice 0) vale 65 na tabela ASCII. A = 65 (A = 65-65 = 0, B = 66 - 65 = 1)
}

void marcar(Grafo *g, int valor){
    int i;
    for(i = 0; i < g->quantidade; i++)
        g->vetor[i].visitado = 0;
}

void dfs(Grafo *g, char v){
    char w;
    Elemento *aux;
    g->vetor[v - 65].visitado = 1; //marcar v como visitado
    printf("%c ", v);
    Fila *fila = g->vetor[v - 65].f; //coloquei em uma outra variável pra não precisar ficar escrevendo tudo de novo
    for(aux = fila->inicio; aux != NULL; aux = aux->prox){ //para cada vértice adjacente de v
        w = aux->letra;
        if(g->vetor[w - 65].visitado == 0){ //se w não foi visitado
            dfs(g, w); //chamada recursiva de dfs para w
        }
    }
}

void bfs(Grafo *g, char v){
    char x, y;
    Elemento *aux;
    Elemento elem;
    Fila *f = novaFila();
    g->vetor[v - 65].visitado = 1;
    elem.letra = v;
    enfileirar(f, elem);
    while(f->quant > 0){
        x = f->inicio->letra;
        printf("%c ", x);
        desenfileirar(f);
        Fila *fila = g->vetor[x - 65].f;
        for(aux = fila->inicio; aux != NULL; aux = aux->prox){ //para cada vértice adjacente de x
            y = aux->letra;
            if(g->vetor[y - 65].visitado == 0){ //se y não foi visitado
                g->vetor[y - 65].visitado = 1; //marcando como visitado
                elem.letra = y;
                enfileirar(f, elem); //enfileirando o y
            }
        }
    }
}

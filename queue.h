typedef struct Fila {
    Elemento *inicio, *fim;
    int quant;
} Fila;

Fila * novaFila() {
    Fila *nova = (Fila *)malloc(sizeof(Fila));
    nova->inicio = NULL;
    nova->fim = NULL;
    nova->quant = 0;
    return nova;
}

void enfileirar(Fila *f, Elemento e) {
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    *novo = e;
    if (f->quant == 0) { // fila inicialmente vazia
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    novo->prox = NULL;
    novo->ant = f->fim;
    f->fim = novo;
    f->quant++;
}

void desenfileirar(Fila *f) {
    Elemento *elemento;
    if (f->quant > 0) {
        elemento = f->inicio;
        f->inicio = elemento->prox;
        if (f->quant == 1) { // fila só tem um elemento
            f->fim = NULL;
        } else {
            f->inicio->ant = NULL;
        }
        f->quant--;
        free(elemento);
    }
}

void impressaoFila(Fila *f) {
    Elemento *aux;
    for (aux = f->inicio; aux != NULL; aux = aux->prox) {
        printf("%c \n", aux->letra);
    }
}

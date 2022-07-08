#include <stdio.h>
#include <stdlib.h>
#include "Grafos.h"

void InicializaPilha (TipoPilha *Pilha) {   
  Pilha->n = 0;
}

void ImprimeVertice(TipoVertice *v){
	printf("%s ",v->Item.Nome);
}

void ListaPilha(TipoPilha* Pilha) {
	for(int i = Pilha->n-1; i >=0; i--) {
	    ImprimeVertice(&(Pilha->Reg[i]));		
	}
}

int PilhaVazia(TipoPilha* Pilha) {
	if (Pilha->n > 0) 
		return 0;
	else return 1;	
}

void Empilha(TipoPilha* Pilha, TipoVertice* v) {
	Pilha->Reg[Pilha->n] = *v;	
	Pilha->n++;	
}

TipoVertice* Desempilha(TipoPilha* Pilha) {
	TipoVertice* reg = NULL;
	if (Pilha->n > 0) {
		Pilha->n--;
		reg = &Pilha->Reg[Pilha->n];
	}
	return reg;
}

TipoVertice* VerTopo(TipoPilha* Pilha) {
	TipoVertice* reg = NULL;
	if (Pilha->n > 0) {
		reg = &Pilha->Reg[Pilha->n-1];
	}
	return reg;
}

void InicializaGrafo (TipoGrafo *Grafo) {   
  InicializaPilha(&(Grafo->Pilha));
  Grafo->n = 0;  
  
	for(int i=0; i<MAX_VERT; i++) {
		for(int j=0; j<MAX_VERT; j++) {
			Grafo->MatrizAdj[i][j] = 0;
		}
	}	  
}

void adicionaVertice(TipoGrafo *Grafo, TipoRegistro Reg) {
	
	TipoVertice v;
	v.Ordem = Grafo->n;
	v.Item = Reg;
	v.FoiVisitado = 0;
	
	Grafo->ListaVertices[Grafo->n] = v;
	Grafo->n++;
}

void ListaGrafo(TipoGrafo* Grafo) {
	
	printf("\nGRAFO\n   ");	
	for(int i=0; i < Grafo->n; i++) {
	    ImprimeVertice(&(Grafo->ListaVertices[i]));
	}
	printf("\n----------------------------------------------------------------------------\n");
	
	printf("%-3s", "");
	for(int i=0; i<Grafo->n; i++) {
		printf("%-3d", Grafo->ListaVertices[i].Ordem);
	}
	printf("\n");
	
	for(int i=0; i<Grafo->n; i++) {
		printf("%-3d", Grafo->ListaVertices[i].Ordem);
		for(int j=0; j<Grafo->n; j++) {
			printf("%-3d", Grafo->MatrizAdj[i][j]);
		}
		printf("\n");
	}
	
}

void adicionarAresta(TipoGrafo* Grafo, int inicio, int fim) {
	Grafo->MatrizAdj[inicio][fim] = 1;
}

TipoVertice* AdjNaoVisitado(TipoGrafo* Grafo, TipoVertice* v) {

	for(int j=0; j<Grafo->n; j++) {
		if ( (Grafo->MatrizAdj[v->Ordem][j] == 1) && (Grafo->ListaVertices[j].FoiVisitado == 0) ) {
			return &(Grafo->ListaVertices[j]);
		}
	}
	
	return NULL;
}

void ZerarFlagsVisitado(TipoGrafo* Grafo) {
	for(int j=0; j<Grafo->n; j++) {
		Grafo->ListaVertices[j].FoiVisitado = 0;		
	}
}

bool verificarTodosVisitados(TipoGrafo* Grafo){
	for(int j=0; j<Grafo->n; j++) {
		if (Grafo->ListaVertices[j].FoiVisitado == 0)
			return false;	
	}
	return true;
}

void ArvoreGeradoraMinima(TipoGrafo* Grafo, int inicio, int fim) {

		
	TipoVertice* vertInicio = &(Grafo->ListaVertices[inicio]);
	printf("\nMinimo de arestas: Inicio em ");
	ImprimeVertice(vertInicio);
	
	vertInicio->FoiVisitado = 1;
	printf("\n(");
	ImprimeVertice(vertInicio);
	Empilha(&(Grafo->Pilha), vertInicio);
		
	while(!PilhaVazia(&(Grafo->Pilha))) {
		
		TipoVertice *topo = VerTopo(&(Grafo->Pilha));			
		TipoVertice *v = AdjNaoVisitado(Grafo, topo);
		
		 if (v == NULL) {
		 	Desempilha(&(Grafo->Pilha));
		 } else {
		 	v->FoiVisitado = 1;
		 	ImprimeVertice(v);
		 	printf("\b\b) (");
		 	ImprimeVertice(v);
		 	Empilha(&(Grafo->Pilha), v);
		 }		
	}
	printf("\b\b\b\b    ");
	ZerarFlagsVisitado(Grafo);
	 
	 
}

void testarTodosOsNos(TipoGrafo *grafo){
	for (int i=0; i < grafo->n; i++){
		if (PassaEmTodos(grafo, i)){
			printf("\nEh possivel chegar em qualquer no partindo de ");
		}
		else{
			printf("\nNAO possivel chegar em todos os nos partindo de ");
		}
		ImprimeVertice(&(grafo->ListaVertices[i]));
	}
}

bool PassaEmTodos(TipoGrafo *grafo, int origem){
	for (int i=0; i < grafo->n; i++){
		if (!CaminhoMaisCurto(grafo, origem, i))
			return false;
		else
			return true;
	}
}

bool CaminhoMaisCurto(TipoGrafo *grafo, int origem, int destino)
{
    int i, vert,k, NovaDist, min;
    int *M, *L, *A, *caminho;
    M = (int *)malloc(grafo->n * sizeof(int));
    L = (int *)malloc(grafo->n * sizeof(int));
    A = (int *)malloc(grafo->n * sizeof(int));
    caminho = (int *)malloc(grafo->n * 3 * sizeof(int));
    // incializando vairiaveis
    for (i=0; i < grafo->n; i++)
    {
        M[i] = 0; // false -- determina se um vertice ja foi visitado
        A[i] = -1; // determina o caminho mais curto entre origem e destino
        L[i] = 300000; //infinito determina o comprimento do caminho mais curto
    }
    vert = origem;
    L[vert] = 0;
    while (vert != destino && vert != -1) // não terminou ou caminho inexistente
    {
        for(i=0; i<grafo->n ; i++) // percorre vertices adjacentes de vert
            if (grafo->MatrizAdj[vert][i] != 0 && M[i]==0) // se aresta existe e ela não foi visitada
            {
                NovaDist = L[vert] + grafo->MatrizAdj[vert][i];
                if (NovaDist < L[i])
                {
                    L[i] = NovaDist;
                    A[i] = vert;
                }
            }
            M[vert] = 1; // toda a lista de adjacentes de vert já foi analisada
            min = 300000; //infinito
            vert = -1; // valor invalido
            for (i=0; i<grafo->n; i++) // encontra proximo vertice do caminho
                if (M[i]==0 && L[i] < min) //escolhe o vertice cuja aresta possui o menor peso
                {
                    min = L[i]; // atualiza min
                    vert = i; //atualiza vert
                }
    } //fim while
    // listar o caminho mais curto entre origem e destino
    if (vert == destino) // encontrou um caminho
    {
		return true;
    }
    else return false;
}


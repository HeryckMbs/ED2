#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafos.h"

void InserirItensParaTeste(TipoGrafo* Grafo) {
	TipoRegistro a = {'A'};
	adicionaVertice(Grafo, a);
 	
 	TipoRegistro b = {'B'};
	adicionaVertice(Grafo, b);
	
 	TipoRegistro c = {'C'};
	adicionaVertice(Grafo, c);
	
 	TipoRegistro d = {'D'};
	adicionaVertice(Grafo, d);
	
 	TipoRegistro e = {'E'};
	adicionaVertice(Grafo, e);
	
 	TipoRegistro f = {'F'};
	adicionaVertice(Grafo, f);
	
 	TipoRegistro g = {'G'};
	adicionaVertice(Grafo, g);
	
 	TipoRegistro h = {'H'};
	adicionaVertice(Grafo, h);
	
 	TipoRegistro i = {'I'};
	adicionaVertice(Grafo, i);
	
	TipoRegistro j = {'J'};
	adicionaVertice(Grafo, j);
	
	
	adicionarAresta(Grafo, 0, 1);	 	
	adicionarAresta(Grafo, 0, 2);
	adicionarAresta(Grafo, 0, 5);
	adicionarAresta(Grafo, 1, 6);
	adicionarAresta(Grafo, 2, 7);
	adicionarAresta(Grafo, 3, 4);
	adicionarAresta(Grafo, 3, 8);
	adicionarAresta(Grafo, 4, 9);
	adicionarAresta(Grafo, 5, 9);
	adicionarAresta(Grafo, 6, 9);
	adicionarAresta(Grafo, 7, 8);
	
}

int main(int argc, char *argv[]) {
	
	TipoGrafo Grafo;	 
	InicializaGrafo(&Grafo);
	
	InserirItensParaTeste(&Grafo);	
		 	
 	ListaGrafo(&Grafo);
 	
 	GeradoraMinima(&Grafo, 0);
 	GeradoraMinima(&Grafo, 8);
	return 0;
}


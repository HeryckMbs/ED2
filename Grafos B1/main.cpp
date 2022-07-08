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

	adicionarAresta(Grafo,2,0);					
	adicionarAresta(Grafo,7,1);
	adicionarAresta(Grafo,1,2);
	adicionarAresta(Grafo,7,2);
	adicionarAresta(Grafo,2,3);					
	adicionarAresta(Grafo,1,4);						
	adicionarAresta(Grafo,1,5);
	adicionarAresta(Grafo,3,5);
	adicionarAresta(Grafo,6,5);	
	adicionarAresta(Grafo,0,6);
	adicionarAresta(Grafo,1,6);
	adicionarAresta(Grafo,4,6);			
	adicionarAresta(Grafo,5,7);	
							
}

int main(int argc, char *argv[]) {
	
	TipoGrafo Grafo;	 
	InicializaGrafo(&Grafo);
	
	InserirItensParaTeste(&Grafo);	
		 	
 	ListaGrafo(&Grafo);
 	
 	CaminhoMaisCurto(&Grafo, 0, 1);
 	
 	testarTodosOsNos(&Grafo);
 	

	return 0;
}


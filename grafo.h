/* Leandro Perin de Oliveira - 14100846 */

#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>

#include "vertice.h"

class Grafo {

public:
	Grafo(Vertice* v);
	virtual ~Grafo();

	void adicionaVertice(Vertice* v);
	void removeVertice(Vertice* v);
	void conecta(Vertice* v1, Vertice* v2, int valor);
	void desconecta(Vertice* v1, Vertice* v2);

	int ordem();
	std::list<Vertice*>* vertices();
	Vertice* umVertice();
	std::list<Vertice*>* adjacentes(Vertice* v);
	int grau(Vertice* v);

	void removerConexoes(Vertice* v);

private:
	struct Aresta {
		Vertice* _v1;
		Vertice* _v2;
	};

	std::list<Vertice*>* _vertices;
	std::unordered_map<Aresta*, int> _arestas;

protected:

};

#endif

/* Leandro Perin de Oliveira - 14100846 */

#include "grafo.h"

Grafo::Grafo(Vertice* v) {
	this->_vertices = new std::list<Vertice*>;
	this->_vertices->push_front(v);
	v->adiciona();
}

Grafo::~Grafo() {
	delete this->_vertices;
}

void Grafo::adicionaVertice(Vertice* v) {
	this->_vertices->push_back(v);
	v->adiciona();
}

void Grafo::removeVertice(Vertice* v) {
	if (this->_vertices->size() == 1) {
		std::cout << "ERRO: Não é possível remover o vértice pois ele é o único do grafo!" << std::endl;
	} else {
		this->removerConexoes(v);
		this->_vertices->remove(v);
		v->remove();
	}
}

void Grafo::conecta(Vertice* v1, Vertice* v2, int valor) {
	if (v1->adicionado() && v2->adicionado()) {
		struct Aresta* aresta = new Aresta();

		aresta->_v1 = v2;
		aresta->_v2 = v1;
		this->_arestas.erase(aresta);

		aresta->_v1 = v1;
		aresta->_v2 = v2;
		this->_arestas.erase(aresta);

		this->_arestas.emplace(aresta, valor);
	} else {
		std::cout << "ERRO: Não foi possível conectar pois um dos vértices não pertence ao grafo!" << std::endl;
	}
}

void Grafo::desconecta(Vertice* v1, Vertice* v2) {
	for (auto it = this->_arestas.begin(); it != this->_arestas.end(); ++it) {
		if ((it->first->_v1 == v1 && it->first->_v2 == v2) || (it->first->_v1 == v2 && it->first->_v2 == v1)) {
			Aresta* a = it->first;
			this->_arestas.erase(a);
			delete a;
			break;
		}
	}
}

int Grafo::ordem() {
	return this->_vertices->size();
}

std::list<Vertice*>* Grafo::vertices() {
	return this->_vertices;
}

Vertice* Grafo::umVertice() {
	srand(time(NULL));
	int posicao = rand() % this->ordem();

	std::list<Vertice*>::iterator it = this->_vertices->begin();
	int contador = 0;
	while (posicao > contador) {
		++it;
		contador++;
	}

	return *it;
}

std::list<Vertice*>* Grafo::adjacentes(Vertice* v) {
	std::list<Vertice*>* adj = new std::list<Vertice*>;

	for (auto it = this->_arestas.begin(); it != this->_arestas.end(); ++it) {
    		if (it->first->_v1 == v) {
			adj->push_back(it->first->_v2);
		}
		if (it->first->_v2 == v) {
			adj->push_back(it->first->_v1);
		}
	}

	return adj;
}

int Grafo::grau(Vertice* v) {
	return this->adjacentes(v)->size();
}

void Grafo::removerConexoes(Vertice* v) {
	std::list<Vertice*>* adj = this->adjacentes(v);
	std::list<Vertice*>::iterator it;

	for (it = adj->begin(); it != adj->end(); it++) {
		this->desconecta(v, (*it));
	}
}

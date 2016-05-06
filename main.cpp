/* Leandro Perin de Oliveira - 14100846 */

#include "grafo.h"
#include <stdlib.h>

Grafo* g;

void init() {
	Vertice* sp = new Vertice("São Paulo");
	Vertice* rj = new Vertice("Rio de Janeiro");
	Vertice* es = new Vertice("Espírito Santo");
	Vertice* mg = new Vertice("Minas Gerais");
	Vertice* pr = new Vertice("Paraná");
	Vertice* sc = new Vertice("Santa Catarina");
	Vertice* rs = new Vertice("Rio Grande do Sul");

	g = new Grafo(sp);

	g->adicionaVertice(rj);
	g->adicionaVertice(es);
	g->adicionaVertice(mg);
	g->adicionaVertice(pr);
	g->adicionaVertice(sc);
	g->adicionaVertice(rs);

	g->conecta(mg,es,10);
	g->conecta(mg,rj,15);
	g->conecta(mg,sp,20);
	g->conecta(es,rj,5);
	g->conecta(rj,sp,5);
	g->conecta(sp,pr,10);
	g->conecta(pr,sc,5);
	g->conecta(sc,rs,10);
}

Vertice* busca(int est) {
	std::list<Vertice*>::iterator it;
	std::list<Vertice*>* lista = g->vertices();

	const char* nome;

	switch (est) {
		case 1: nome = "Minas Gerais"; break;
		case 2: nome = "Espírito Santo"; break;
		case 3: nome = "Rio de Janeiro"; break;
		case 4: nome = "São Paulo"; break;
		case 5: nome = "Paraná"; break;
		case 6: nome = "Santa Catarina"; break;
		case 7: nome = "Rio Grande do Sul"; break;
	}

	for (it = lista->begin(); it != lista->end(); it++) {
		if ((*it)->get_nome() == nome) {
			return (*it);
		}
	}
}

bool fazemFronteira(Vertice* v1, Vertice* v2) {
	std::list<Vertice*>* adj = g->adjacentes(v1);
	std::list<Vertice*>::iterator it;

	for (it = adj->begin(); it != adj->end(); it++) {
		if ((*it) == v2)
			return true;
	}

	return false;
}

int main() {
	init();

	char opt = 's';
	while (opt == 's') {
		std::cout << "-------------------------------------------------------" << std::endl;
		std::cout << "     INE5413 - Implementação de Estrutura de Grafos    " << std::endl;
		std::cout << "-------------------------------------------------------" << std::endl << std::endl;
		std::cout << "Quantidade de estados: " << g->ordem() << std::endl;
		std::cout << "Estados: 1:MG - 2:ES - 3:RJ - 4:SP - 5:PR - 6:SC - 7:RS" << std::endl;
		std::cout << "Escolha dois para descobrir se fazem fronteira:        " << std::endl;

		int est1, est2;
		std::cin >> est1;
		std::cin >> est2;

		Vertice* v1 = busca(est1);
		Vertice* v2 = busca(est2);

		if (fazemFronteira(v1,v2))
			std::cout << "SIM" << std::endl;
		else
			std::cout << "NÃO" << std::endl;

		std::cout << "Deseja fazer outra consulta? (s/n)" << std::endl;
		std::cin >> opt;
	}

	delete g;

	return 0;
}

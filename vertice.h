/* Leandro Perin de Oliveira - 14100846 */

#ifndef VERTICE_H
#define VERTICE_H

class Vertice {

public:
	Vertice(const char* nome);
	virtual ~Vertice();

	const char* get_nome();
	bool adicionado();
	void adiciona();
	void remove();

private:
	const char* _nome;
	bool _adicionado;

protected:

};

#endif

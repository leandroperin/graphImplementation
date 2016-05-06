/* Leandro Perin de Oliveira - 14100846 */

#include "vertice.h"

Vertice::Vertice(const char* nome) {
	this->_nome = nome;
	this->_adicionado = false;
}

Vertice::~Vertice() {

}

const char* Vertice::get_nome() {
	return this->_nome;
}

bool Vertice::adicionado() {
	return _adicionado;
}

void Vertice::adiciona() {
	_adicionado = true;
}

void Vertice::remove() {
	_adicionado = false;
}

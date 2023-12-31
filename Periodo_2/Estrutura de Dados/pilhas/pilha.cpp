#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct No {
  int valor;
  No* anterior;
  No* prox;
} No;

typedef struct Pilha {
  No* topo;
  
  int topEl() {
    if(isEmpty()) 
      return -1;
    else 
      return topo->valor;
  };

  void push(int v){
    No* n = new No;
    n->valor = v;
    n->anterior = topo;
    topo = n;
  }

  bool isEmpty(){
    if(topo == nullptr) return true;
    return false;
  };

  void pop(){
    if(isEmpty()) return;
    No* n = topo;
    topo = n->anterior;
    delete n;
  };

  void clear(){
    if(isEmpty()) return;
    while(topo != nullptr) pop();
  };  

  void print(){
    if(isEmpty()) return;
    No* n = topo;
    while(n != nullptr){
      cout << "|" << n->valor << "|" << endl;
      n = n->anterior;
    }
  };

} Pilha;

typedef struct Fila {
  No* inicio;
  No* fim;

  void clear(){};

  void isEmpty(){};

  void enqueue(){};

  void dequeue(){}; 
} Fila;

Pilha* somarDuasPilhas(Pilha* p1, Pilha *p2){
  int i = 0;

  No* noResult = NULL;
  Pilha* pilhaResult = new Pilha;
  pilhaResult->topo = nullptr;
  int resto = 0;
  
  while(!p1->isEmpty() || !p2->isEmpty()){    
    int soma = (!p1->isEmpty() ? p1->topEl() : 0) + (!p2->isEmpty() ? p2->topEl() : 0);
    
    soma+= resto;
    int ultimoDigito = soma % 10;
    pilhaResult->push(ultimoDigito);
    int rest = soma / 10;
    p1->pop();
    p2->pop();
}
  if(resto != 0) pilhaResult->push(resto);
  return pilhaResult;
}

int main() {
  Pilha* pilha = new Pilha;
  No* no = NULL;
  pilha->topo = no;

  No* no2 = NULL;
  Pilha* pilha2 = new Pilha;
  pilha2->topo = no2;

  pilha->push(2);
  pilha->push(1);
  pilha->push(0);
  
  pilha2->push(3);  
  pilha2->push(1);
  pilha2->push(1);
  pilha2->push(5);

  pilha->print();
  pilha2->print();

  Pilha* result = somarDuasPilhas(pilha, pilha2);
  result->print();
  

  return 1;
}
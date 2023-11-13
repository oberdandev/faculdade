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
      return NULL;
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
    delete n;
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
/*
Pilha* topo = NULL;

void push(Pilha* pilha, int valor){
  Pilha *novo = new Pilha;
  novo->valor = valor;
  novo->anterior = pilha;
  topo = novo;
}

void pop(Pilha* pilha){
  if(pilha != NULL){
    Pilha *anterior = pilha->anterior;
    delete pilha;
    topo = anterior;
  }
}
*/

/*
int main(){
  cout << "Pilha" << endl;
  Pilha* novaPilha = new Pilha;
  Pilha* nPilhaTop = NULL;
  
  novaPilha->valor = 1;
  novaPilha->anterior = NULL;
  nPilhaTop = novaPilha;

  cout << nPilhaTop->valor << endl;




  return 0;	
}*/

Pilha* somarDuasPilhas(Pilha* p1, Pilha* p2){
  int i = 0;

  No* noResult = NULL;
  Pilha* pilhaResult = new Pilha;
  pilhaResult->topo = nullptr;
  int resto = 0;
  
  while(!p1->isEmpty() || !p2->isEmpty()){    
    //int v1 = !p1->isEmpty() ? p1->topo->valor : 0; 
    int soma = (!p1->isEmpty() ? p1->topEl() : 0) + (!p2->isEmpty() ? p2->topEl() : 0);
    
    soma+= resto;
    int ultimoDigito = soma % 10;
    pilhaResult->push(ultimoDigito);
    int rest = soma / 10;
/*
    cout << "p1 valor atual: ";
    p1->topEl();
    cout << "p2 valor atual: ";
    p2->topEl();
    cout << i << " - iteracao" << endl;
    p1->pop();
    p2->pop();
    cout << "Soma: " << soma << endl;
    cout << "Ultimo digito: " << ultimoDigito << endl;
    cout << "Resto: " << resto << endl;
    i++;
*/
}
  if(resto != 0) pilhaResult->push(resto);
  return pilhaResult;
  /*
  int soma = p1->topo->valor + p2->topo->valor;
  No* noResult = NULL;

  int ultimoDigito = soma > 10 ? soma % 10 : soma;
  int rest = soma > 10 ? soma / 10 : 0;

  Pilha* pilhaResult = new Pilha;
  p1->pop();
  p2->pop();
  pilhaResult->topo = noResult;
  pilhaResult->push(rest);
  pilhaResult->push(ultimoDigito);

  pilhaResult->print();
  */
}


void interface(){
  int n1, n2, ultimo, rest;
  cout << "Digite uma opcao: ";
  cout << "Digite o primeiro numero: ";
  cin >> n1;
  ultimo = n1 % 10;
  rest = n1 / 10;
  while(rest != 0){

  }
};



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
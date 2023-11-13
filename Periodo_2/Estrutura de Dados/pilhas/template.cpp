#include <iostream>


template <typename T>
struct Node {
    T data;           // Dados armazenados no nó
    Node* next;       // Ponteiro para o próximo nó

    // Construtor para facilitar a criação de nós
    Node(T value) : data(value), next(nullptr) {}
};

/*
Node<int> header = new Node;
Node<int> transporter = new Node;


int main(){
  Node<int>* newNode = new Node;
  newNode->data = 1;
  newNode-> next = NULL;
  header = newNode;
  transporter = newNode;

  Node<int>* novo = new Node;
  novo->data = "Teste";
  novo->next = NULL;
  transporter->next = novo;
  transporter = novo;

  Node<int>* teste = new Node;
  teste = header; 
  while(teste->next){
    std::cout << teste->data << std::endl;
    teste = teste->next;
  }


  return 0;
}; */

int main() {
    //Node<int>* teste;
    Node<int>* newNode(new Node<int>(1));
    //newNode->next = teste;
    Node<int>* novo = new Node<int>(0);

    std::cout << newNode->data << std::endl;
    std::cout << newNode->next << std::endl;

    if(0 == NULL) std::cout << "true" << std::endl;

    std::cout << novo->data;

    if(novo->data == NULL) std::cout << "true" << std::endl;

    return 0;
}
#include <iostream>
#include <stdio.h>
#include <variant>
#include <string.h>
#include <locale.h>
#include <algorithm>

using namespace std;

typedef struct Profissoes
{
  char nome[20];
  char sigla[10];
  char conselho[20];
} Profissoes;


Profissoes listaProfissoes[];
int profissoesInseridas = -1;

int main (){

  Profissoes p1 = {
    .nome = "Enfermeiro",
    .sigla = "ENF",
    .conselho = "COREN"
  };
  profissoesInseridas = profissoesInseridas + 1;
  listaProfissoes[profissoesInseridas] = p1;

 Profissoes p2 = {
    .nome = "Medico",
    .sigla = "MED",
    .conselho = "CRM"
  };
  profissoesInseridas = profissoesInseridas + 1;   
  listaProfissoes[profissoesInseridas] = p2;

  Profissoes p3 = {
    .nome = "Tec. Enfermagem",
    .sigla = "TEC. ENF",
    .conselho = "..."
  };
   profissoesInseridas = profissoesInseridas + 1;
    listaProfissoes[profissoesInseridas] = p3;

  for(int i =0; i <= profissoesInseridas; i++){
    cout << "Digite " << i << " para adicionar " << listaProfissoes[i].nome << "\n";
  }

  int digito = 1;

  if(1){
    
  }

}
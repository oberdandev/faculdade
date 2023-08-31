#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


using namespace std;

typedef struct Profissional {
  char nome[20];
  char idade[3];
  char genero[4]; 
} Profissional;

const char* prof_format_out = "(%s, %i, %s)\n";
const char* prof_format_in  = "(%s, %i, %s)\n";

int main(){
  Profissional p1 = {
    .nome = "George",
    .idade = "18",
    .genero = "M"
  };

  Profissional p2;

  FILE * file;
  int r;

  file = fopen("prof.txt", "r+");
  
  if(file == NULL){ 
    cout << "Erro ao abrir";
    exit(1);
  } 

  for(int i=0; i<3; i++){
  fseek(file, 0, SEEK_END);
  fputs(p1.nome, file);
  fputs(";", file);
  fputs(p1.idade, file);
  fputs(";", file);
  fputs(p1.genero, file);
  fputs("\n", file);
  }

  if(r == EOF){
    cout << "Erro ao adicionar dados";
  }else{
    cout << "Ok. registrado";
  }


  return 0 ;
}
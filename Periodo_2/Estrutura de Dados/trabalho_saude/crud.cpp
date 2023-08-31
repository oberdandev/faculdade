#include <iostream>
#include <stdio.h>
#include <variant>
#include <string.h>
#include <locale.h>
#include <algorithm>

using namespace std;

#define tamanhoConj = 5 ;
#define clientesInseridos = -1 ;
int profissionaisInseridos = -1  ;
#define atendimentosInseridos = -1  ;
/* #define listaAtendimentos[5];
#define listaClientes[5]; */

typedef struct Endereco {
    string logradouro;
    int numero;
    string bairro;
    string cidade;
    string estado;
    string CEP;
} Endereco;

typedef struct Aniversario {
  int dia;
  int mes;
  int ano;
} Aniversario;

typedef struct {
    string matricula;
    string cpf;
    string nome;
    string registro;
    string cbo;
    string sigla;
    string profissao;
    string email;
    string fone;
    string data_nascimento;
    int  idade;
    string estado;
    string CEP;
    int codigo;
} Profissional;

Profissional listaProfissionais[5];

typedef struct {
    string codigo;
    string nome;
    string data_nascimento;
    int idade;
    string email;
    string fone;
    string celular;
    Endereco endereco;
} Cliente;

typedef struct {
    int numero;
    Cliente client;
    string codCliente; 
    Profissional profissional;
    string descricao;
}  Atendimento;

typedef struct {
  string cbo;
  string nome;
  string sigla;  
} Profissao;

union clienteOuProfissional{
  Cliente cliente;
  Profissional profissional;
};

string maisculo(string texto){
  transform(texto.begin(), texto.end(), texto.begin(), ::toupper);
  return texto;
}

void limpaTela() {
  system("cls");
}

//Data criaData(Data data){
//  return data;
//} criaData 

const string nomeMes[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

string verificaCpf(string cpf){
  /* Criar uma verificação para cpf - muito complexo para se preocupar no momento
  após o projeto estar mais robusto irei focar nas validações restantes. */
}
  	
string cadastrarCPF(string tipoPessoa) {
  string cpf;
  cout << "Digite o cpf do Profissional para ser cadastrado. Ex: Joao Pedro \n" << endl;
  cin >> cpf;

  while(cpf.length() < 11) {
   cout << "Digite unm cpf válido para o " << tipoPessoa << "." << endl;
   cin >> cpf;
  }

  return cpf;
};

string cadastrarNome(string tipoPessoa) {
  string nome;
  cout << "Digite o nome do " << tipoPessoa << " para ser cadastrado. Ex: Joao Pedro \n";
  cin >> nome;
 
  while(nome.length() < 3) {
   cout << "Digite um nome válido para o " << tipoPessoa << ". \n";
   cin >> nome;
  }
  return nome;
};

string cadastrarProfissao(){
  string profissao;
  cout << "Digite a profissão do funcionário." << endl;
  cin >> profissao;

  return profissao;
}

string cadastrarSigla(){
  string sigla;
  cout << "Digite a sigla do registro profissional. Ex: COREN, CMM ou CRO" << endl;
  cin >> sigla;
  sigla = maisculo(sigla);
  while(sigla != "COREN" and sigla != "CMM" and sigla != "CRO"){
    cout << "Digite uma sigla válida. Ex: COREN, CMM ou CRO." << endl;
    cin >> sigla;
    sigla = maisculo(sigla);
  }

  return sigla; 
}

int cadastrarIdade(string tipoPessoa){
  int idade;
  cout << "Digite a idade do " << tipoPessoa << " para ser cadastrado." << endl;
  cin >> idade;

  return idade;
};

void exibeDadosProfissional(Profissional profissional) {
  limpaTela();
  cout << "Dados provisórios do profissional: \n" << endl;
  cout << "Nome: " << "\x1b[1;34m" << profissional.nome << endl;
  cout << "\x1b[1;30m" << "Idade: " << profissional.idade << endl;
  cout << "Aniversário: " << profissional.data_nascimento << endl; 
  cout << "CPF: " << profissional.cpf << endl;
  cout << "Matricula: " << profissional.matricula << endl;
  cout << "Profissão: " << profissional.profissao << endl;
  cout << "Registro: " << profissional.registro << endl;
  cout << "Sigla: " << profissional.sigla << endl;
  cout << "CBO: " << profissional.cbo << endl;
  cout << "Email: " << profissional.email << endl; 
  cout << "Fone: " << profissional.fone << endl; 
  cout << "Estado: " << profissional.estado << endl;
  cout << "CEP: " << profissional.CEP << endl;  
  cout << "" << endl;
}

void cadastrarProfissoes() {
  string nomeProfissao;
  cout << "Digite um nome da profissão que você deseja adicionar no sistema: ";
  cin >> nomeProfissao;
  nomeProfissao = maisculo(nomeProfissao);
  
};

void cadastrarProfissional() {
  Profissional profissional;
  profissional.idade = 0;
  profissional.nome = cadastrarNome("profissional");
  exibeDadosProfissional(profissional);
  profissional.idade = cadastrarIdade("profissional");
  exibeDadosProfissional(profissional);
  profissional.cpf = cadastrarCPF("profissional");
  exibeDadosProfissional(profissional);
  profissional.profissao = cadastrarProfissao();
  exibeDadosProfissional(profissional);
  profissional.registro = cadastrarSigla();
  exibeDadosProfissional(profissional);
  
  profissionaisInseridos = profissionaisInseridos + 1;
  listaProfissionais[profissionaisInseridos] = profissional;
  cout << "TESTE PRA VER SE VAI DAR CERTO" << listaProfissionais[0].nome << endl;
};

void deletarProfissional(int id){
  Profissional profissional = listaProfissionais[id];
  exibeDadosProfissional(profissional);
  cout << "Deseja realmente deletar o profissional " << profissional.nome <<  "?" << endl;
  cout << "1 - SIM" << endl;
  cout << "2 - NÃO" << endl;
}

bool validaData(int dia, int mes){
  if(dia <= 0 && dia > 31) {
    return false;
  }
  if(mes <= 0 && mes > 12){
    return false;
  }
  return true;
};

void cadastrarCliente(){
  Cliente client;
  cout << "Digite o nome do cliente para cadastrar \n" << endl;
  cin >> client.nome;
  cout << client.nome;
}

int main(){
  setlocale(LC_ALL, "pt_BR.UTF-8");
  cadastrarProfissional();

  deletarProfissional(0);
  return 0;

}
#include <iostream>
#include <stdio.h>
//#include <variant>
#include <string>
#include <locale.h>
#include <algorithm>
#include <regex>
#include <fstream>

using namespace std;
#define tamanhoConj  5
#define clientesInseridos  -1
#define profissionaisInseridos  -1
#define atendimentosInseridos  -1
/* #define listaAtendimentos[5] //OI GEORGE TA LENDO AI?
#define listaClientes[5]; */ 

//STRUCTS
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
    Endereco endereco;
} Profissional;



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
    string profCPF;
    string descricao;
}  Atendimento;

typedef struct {
  string cbo;
  string nome;
  string sigla;
} Profissao;
//FIM DOS STRUCTS

//variaveis globais aq

const string nomeMes[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
union clienteOuProfissional{
  Cliente cliente;
  Profissional profissional;
};
//Início das funções
string maisculo(string texto);
void limpaTela();
bool Email_check(string email);
string verificaCpf(string cpf);

//INICIO FUNÇÕES CADASTRO
string cadastrarCPF(string tipoPessoa);
string cadastrarNome(string tipoPessoa);
string cadastrarProfissao();
string cadastrarSigla();
int cadastrarIdade(string tipoPessoa);
string cadastrarEmail(string tipoPessoa);
string cadastrarMatriculaProfissional();
Endereco cadastrarEndereco(string tipoPessoa);
void exibeDadosProfissional(Profissional profissional);
void cadastrarProfissoes();
void cadastrarProfissional();
bool validaData(int dia, int mes);
string cadastrarNomeCliente(string tipoPessoa);
int cadastrarIdadeCliente(string tipoPessoa);
string cadastrarFone(string tipoPessoa);
string cadastrarEmailCliente(string tipoPessoa);
void exibeDadosCliente(Cliente cliente);
void cadastrarCliente();

//FUNÇÕES DO ATENDIMENTO
string cadastrarDescricao();
void exibeDadosAtendimento(Atendimento atendimento);
void cadastrarAtendimento();

//FUNÇÕES MENU - talvez não seja preciso
void boasVindas();
//FUNÇAÕ PARA EXIBIR O MENU PRINCIPAL
void exibeMenu();
int exibeOpcoes();
int exibeOpCadastro();
int exibeOpEditar();
int exibeOpExcluir();
int exibeOpConsultar();
//FUNÇÃO CADASTRAR PROFISSÃO

Profissional listaProfissionais[tamanhoConj];
Cliente listaClientes[tamanhoConj];
Atendimento listaAtendimentos[tamanhoConj];
Profissao listaProfissoes[tamanhoConj];
int quantiaRegistrosProfissionais=-1, quantiaRegistrosClientes=-1, quantiaRegistrosAtendimentos=-1, quantiaRegistrosProfissoes=-1;

//INICIO DA FUNÇÃO MAIN
int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    // setlocale(LC_ALL, "PORTUGUESE");

    int opcaoMenu, opCadastro, opEditar, opExcluir, opConsultar;
    boasVindas();
    opcaoMenu = exibeOpcoes(); //chamando a função exibeOpcoes e atribuindo o valor dela a opcaoMenu


    switch(opcaoMenu){
        case 1: //cadastrar
            opCadastro = exibeOpCadastro();
            if(opCadastro == 1){ //switch - trocar
                cadastrarCliente();
                //salvar isso aqui em um arquivos. + implementar função de voltar depois de cadastrar

            }
            else if(opCadastro == 2){
                limpaTela();
                cadastrarProfissional();
            }
            else if(opCadastro == 3){
                cadastrarAtendimento();
            }
            else if(opCadastro == 4){
                cout << "...";
                cadastrarProfissao();
            }

            else if(opCadastro == 5){
                //system("cls");
                limpaTela();
                main(); //problema - chamar o menu de novo
            }
            /* 
            switch(opCadastro){
                case 1: 
                cadastrarCliente();
                break;

                case 2: 
                cadastrarProfissional();
                break;

                case 3: 
                cadastrarAtendimento();
                break;

                case 4: 
                cadastrarProfissao();
                break;

                case 5: 
                limpaTela();
                main();
            }
            */

            break;

        case 2: //Editar
            opEditar = exibeOpEditar();

            if(opEditar == 1){
                //chamar função de cadastrarCliente
            }
            else if(opEditar == 2){
                cout << "...";
            }
            else if(opEditar == 3){
                cout << "...";
            }
            else if(opEditar == 4){
                //system("cls");
                limpaTela();
                main();
            }

            break;

        case 3:  //Excluir
            opExcluir = exibeOpExcluir();

            if(opExcluir == 1){
                //chamar função de cadastrarCliente
            }
            else if(opExcluir == 2){
                cout << "...";
            }
            else if(opExcluir == 3){
                cout << "...";
            }
            else if(opExcluir == 4){
                //system("cls");
                limpaTela();
                main();
            }
            break;

        case 4:  //Consultar
            opConsultar = exibeOpConsultar();

            if(opConsultar == 1){
                //chamar função de cadastrarCliente
            }
            else if(opConsultar == 2){
                cout << "...";
            }
            else if(opConsultar == 3){
                cout << "...";
            }
            else if(opConsultar == 4){
                //system("cls");
                main();
            }

            break;

        case 5:
            cout <<"\nVocê saiu do sistema. Até mais.\n";
            break;


    }
    return 0;

}

string maisculo(string texto){
  transform(texto.begin(), texto.end(), texto.begin(), ::toupper);
  return texto;
}

void limpaTela() {
  system("cls");
}


//função para verificar email
bool Email_check(string email){
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if(regex_match(email,pattern)) return true;
    return false;
}

//Data criaData(Data data){
//  return data;
//} criaData



string verificaCpf(string cpf){
  /* Criar uma verificação para cpf - muito complexo para se preocupar no momento
  após o projeto estar mais robusto irei focar nas validações restantes. */
}

//INICIO FUNÇÕES CADASTRO
string cadastrarCPF(string tipoPessoa) {
  string cpf;
  //cout << "Digite o CPF do Profissional para ser cadastrado.\n" << endl;
  cout << "Digite o CPF do Profissional para ser cadastrado.\n" << endl;
  cin >> cpf;

  while(cpf.length() != 11) {
   cout << "Digite um CPF válido para o " << tipoPessoa << "." << endl;
   cin >> cpf;
  }

  return cpf;
};

string cadastrarNome(string tipoPessoa) {
  string nome;
  cout << "Digite o nome do " << tipoPessoa << " para ser cadastrado. Ex: Joao Pedro \n";
  cin.ignore(); //aparentemente...
  getline(cin,nome); //Antes não estava lendo nomes compostos
  //cin >> nome;

  //cin.ignore();

  while(nome.length() < 3) {
   cout << "Digite um nome válido para o " << tipoPessoa << ". \n";
   cin >> nome;
   //getline(cin,nome);
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

string cadastrarEmail(string tipoPessoa){
    string email;

    cout << "Digite o endereço de E-mail do " << tipoPessoa << " para ser cadastrado. Ex: mariasilva@gmail.com" << endl;
    cin >> email;
    cout << Email_check(email);
    if(Email_check(email)){
        return email;
    }else{
        while(Email_check(email) == false){
             cout << "Digite um endereço de E-mail válido para o " << tipoPessoa << endl;
             cin >> email;
         }
    }
    //(Email_check(email))
    // while(!Email_check(email)){
    //     cout << "Digite um endereço de E-mail válido para o " << tipoPessoa << endl;
    //     cin >> email;
    // }
   

    return email;
}

string cadastrarMatriculaProfissional(){
    string matricula;

    cout << "Digite a matrícula do profissional: ";
    cin >> matricula;

    return matricula;
};


Endereco cadastrarEndereco(string tipoPessoa){
    Endereco endereco;

    cout<< "Cadastro do Endereço do " << tipoPessoa << "." << endl;

    cout << "\nDigite o logradouro do " << tipoPessoa << " a ser cadastrado" << endl;
    cin >> endereco.logradouro;

    cout << "\nDigite o bairro do " << tipoPessoa << " a ser cadastrado" << endl;
    //cin.ignore();
    cin >> endereco.bairro;
    //getline(cin, endereco.bairro);

    cout << "\nDigite o número do endereço " << tipoPessoa << " a ser cadastrado" << endl;
    cin >> endereco.numero;

    cout << "\nDigite a Cidade do " << tipoPessoa << " a ser cadastrado" << endl;
    //cin.ignore();
    cin >> endereco.cidade;
    //getline(cin,endereco.cidade);

    cout << "\nDigite o Estado do " << tipoPessoa << " a ser cadastrado" << endl;
    //cin.ignore();
    cin >> endereco.estado;
    //getline(cin,endereco.estado);

    cout << "\nDigite o CEP do " << tipoPessoa << " a ser cadastrado" << endl;
    cin >> endereco.CEP;

    return endereco;
};



void exibeDadosProfissional(Profissional profissional) {
  limpaTela();
  cout << "\nDados provisórios do profissional: \n" << endl;
  cout << "Nome: " << profissional.nome << endl;
  cout << "Idade: " << profissional.idade << endl;
  cout << "Aniversário: " << profissional.data_nascimento << endl;
  cout << "CPF: " << profissional.cpf << endl;
  cout << "Matricula: " << profissional.matricula << endl;
  cout << "Profissão: " << profissional.profissao << endl;
  cout << "Registro: " << profissional.registro << endl;
  cout << "Sigla: " << profissional.sigla << endl;
  cout << "CBO: " << profissional.cbo << endl;
  cout << "Email: " << profissional.email << endl;
  cout << "Fone: " << profissional.fone << endl;
  cout << "Estado: " << profissional.endereco.estado << endl;
  cout << "Cidade: " << profissional.endereco.cidade << endl;
  cout << "Bairro: " << profissional.endereco.bairro << endl;
  cout << "Logradouro: " << profissional.endereco.logradouro << endl;
  cout << "Número: " << profissional.endereco.numero << endl;
  cout << "CEP: " << profissional.endereco.CEP << endl;
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
  Endereco endereco;
  profissional.idade = 0;
  profissional.nome = cadastrarNome("profissional");
  exibeDadosProfissional(profissional);
  profissional.matricula = cadastrarMatriculaProfissional();
  exibeDadosProfissional(profissional);
  profissional.idade = cadastrarIdade("profissional");
  exibeDadosProfissional(profissional);
  profissional.cpf = cadastrarCPF("profissional");
  exibeDadosProfissional(profissional);
  profissional.profissao = cadastrarProfissao();
  exibeDadosProfissional(profissional);
  profissional.registro = cadastrarSigla();
  exibeDadosProfissional(profissional);
  profissional.email = cadastrarEmail("profissional");
  exibeDadosProfissional(profissional);
  profissional.endereco = cadastrarEndereco("profissional");
  exibeDadosProfissional(profissional);




  listaProfissionais[0] = profissional;
  cout << "TESTE PRA VER SE VAI DAR CERTO " << listaProfissionais[0].nome << endl;


};




bool validaData(int dia, int mes){
  if(dia <= 0 && dia > 31) {
    return false;
  }
  if(mes <= 0 && mes > 12){
    return false;
  }
  return true;
};

string cadastrarNomeCliente(string tipoPessoa){
    string nomeCliente;
    cout << "\nDigite o nome do " << tipoPessoa << " para ser cadastrado. Ex: Maria Silva \n";
    cin.ignore();
    getline(cin, nomeCliente);

    while(nomeCliente.length() < 3){
        cout << "Digite um nome válido para o " << tipoPessoa << ". \n";
        cin.ignore();
        getline(cin, nomeCliente);
    }

    return nomeCliente;

};

int cadastrarIdadeCliente(string tipoPessoa){
    int idade;
    cout << "Digite a idade do " << tipoPessoa << " para ser cadastrado." << endl;
    cin >> idade;

    return idade;
};

string cadastrarFone(string tipoPessoa){
    string fone;
    cout << "Digite o número de telefone do  " << tipoPessoa << " Ex: 559x9xxxxxxxx." << endl;
    cin >> fone;

    while(fone.length() < 13){
        cout << "Digite um número de telefone válido para o " << tipoPessoa << "." << endl;
        cin >> fone;
    }

    return fone;

};

string cadastrarEmailCliente(string tipoPessoa){
    string email;

    cout << "Digite o endereço de E-mail do " << tipoPessoa << " para ser cadastrado. Ex: mariasilva@gmail.com" << endl;
    cin >> email;

    //(Email_check(email))
    while(!Email_check(email)){
        cout << "Digite um endereço de E-mail válido para o " << tipoPessoa << endl;
        cin >> email;
    }

    return email;
}

//colocar endereço do cliente




void exibeDadosCliente(Cliente cliente){
    limpaTela();
    cout << "\nDados provisórios do cliente\n" << endl;
    cout << "Nome: " << cliente.nome << endl;
    cout << "Idade: " << cliente.idade << endl;
    cout << "Email: " << cliente.email << endl;
    cout << "Telefone: " << cliente.fone << endl;
    cout << "Estado: " << cliente.endereco.estado << endl;
    cout << "Cidade: " << cliente.endereco.cidade << endl;
    cout << "Bairro: " << cliente.endereco.bairro << endl;
    cout << "Logradouro: " << cliente.endereco.logradouro << endl;
    cout << "Número: " << cliente.endereco.numero << endl;
    cout << "CEP: " << cliente.endereco.CEP << endl;

}

void cadastrarCliente(){
    //limpaTela();
    Cliente cliente;
    Endereco endereco;
    cliente.idade = 0;
    cliente.nome = cadastrarNomeCliente("cliente");
    exibeDadosCliente(cliente);
    cliente.idade = cadastrarIdadeCliente("cliente");
    exibeDadosCliente(cliente);
    cliente.email = cadastrarEmailCliente("cliente");
    exibeDadosCliente(cliente);
    cliente.fone = cadastrarFone("cliente");
    exibeDadosCliente(cliente);
    cliente.endereco = cadastrarEndereco("cliente");
    exibeDadosCliente(cliente);

};


//FUNÇÕES DO ATENDIMENTO
string cadastrarDescricao(){
    string descricao;
    cout << "Descrição do atendimento: ";
    cin >> descricao;

    return descricao;
};

void exibeDadosAtendimento(Atendimento atendimento){
    limpaTela();
    cout << "Dados do atendimento\n" << endl;
    cout << "Descrição do atendimento: " << atendimento.descricao << endl;

}

void cadastrarAtendimento(){
    Atendimento atendimento;
    atendimento.descricao = cadastrarDescricao();
    exibeDadosAtendimento(atendimento);
}

//FUNÇÕES MENU - talvez não seja preciso
void boasVindas(){
    cout << "---------------------------------------------" << endl;
    cout << "SISTEMA DE CONTROLE DE ATENDIMENTOS CLÍNICOS" << endl;
    cout << "---------------------------------------------" << endl;
}

//FUNÇAÕ PARA EXIBIR O MENU PRINCIPAL
int exibeOpcoes(){
    int opcaoMenu;
    //gotoxy(1,3);
    cout << "\nOlá, seja bem-vindo(a)!" << endl;
    cout << "\nOpções disponíveis:" << endl;
    cout << endl << "1 - Cadastrar" << endl;
    cout << "2 - Editar" << endl;
    cout << "3 - Excluir" << endl;
    cout << "4 - Consultar" << endl;
    cout << "5 - Sair do sistema" << endl;
    while(opcaoMenu < 1 || opcaoMenu > 5){
        cout << "\nDigite o número referente a opção: ";
        cin >> opcaoMenu;
        if(opcaoMenu < 1 || opcaoMenu > 5){
            cout <<"\nOpção inválida, por favor, digite novamente!\n";
        }
    }
    return opcaoMenu;
}

int exibeOpCadastro(){
    int opCadastro;
    limpaTela();
    cout << "\nOpções disponíveis para cadastro:\n";
    cout << endl << "1 - Cadastrar Clientes" << endl;
    cout << "2 - Cadastrar Funcionários" << endl;
    cout << "3 - Cadastrar Atendimento" << endl;
    cout << "4 - Cadastrar Profissão" << endl;
    cout << "5 - Voltar" << endl;
    cout << "\nDigite o número referente a opção: " << endl;
    cin >> opCadastro;

    return opCadastro;
}

int exibeOpEditar(){
    int opEditar;
    limpaTela();
    cout << "\nOpções disponíveis para edição:\n";
    cout << endl << "1 - Editar Clientes" << endl;
    cout << "2 - Editar Funcionários" << endl;
    cout << "3 - Editar Atendimentos" << endl;
    cout << "4 - Voltar" << endl;
    cout << endl << "Digite o número referente a opção: ";
    cin >> opEditar;

    return opEditar;
}

int exibeOpExcluir(){
    int opExcluir;
    cout << "\nOpções disponíveis para exclusão:\n";
    cout << endl << "1 - Excluir Clientes" << endl;
    cout << "2 - Excluir Funcionários" << endl;
    cout << "3 - Excluir Atendimentos" << endl;
    cout << "4 - Voltar" << endl;
    cout << endl << "Digite o número referente a opção: ";
    cin >> opExcluir;

    return opExcluir;
}

int exibeOpConsultar(){
    int opConsultar;
    cout << "\nOpções disponíveis para consulta:\n";
    cout << endl << "1 - Consultar clientes" << endl;
    cout << "2 - Consultar Funcionários" << endl;
    cout << "3 - Consultar Atendimentos" << endl;
    cout << "4 - Voltar" << endl;
    cout << endl << "Digite o número referente a opção: ";
    cin >> opConsultar;

    return opConsultar;
}
//FUNÇÃO CADASTRAR PROFISSÃO

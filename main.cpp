#include<iostream>
#include<string.h>
#include <cstdlib>
#include"Sistema_Educacional.h"
#include <cctype>     //verificar se a matricula digitada tem numero
#include <algorithm> //verificar se a matricula digitada tem numero

#define SUCESSO 0

// g++ -std=c++11 -Wall -o main main.cpp Sistema_Educacional.cpp
// .\main
// descricao de como todos os txt estao organizados no README

int main(){
    
    int opcao = 1, opcao2 = 1;
    bool login1 = true;
    
    while(opcao!=0){
        std::shared_ptr<User> user = nullptr;
        std::string password = " ";
        unsigned int matricula = 0;
        std::string matriculaStr =" ";

        std::cout << "SISTEMA EDUCACIONAL" << std::endl << "Login(n* matricula): ";
        std::cin  >> matriculaStr;
        std::cout << "Senha: ";
        std::cin>> password;
        //verifica se ha somente numeros na matricula
        if(!matriculaStr.empty() && std::all_of(matriculaStr.begin(), matriculaStr.end(), ::isdigit)){
            matricula = std::stoi(matriculaStr);
            user = login(matricula, password);
        }else{
            std::cout <<"Nao digite letras na matricula" << std::endl;
        }
        

        if (user) {
            std::cout << "Login bem-sucedido!" << std::endl;
            // Menu caso usuario for Aluno
            if(std::shared_ptr<Aluno> aluno = std::dynamic_pointer_cast<Aluno>(user)) {
                std::cout << "Bem-vindo, Aluno!" << std::endl;
                    //Preenche o map Alunos com os valores de Alunos.txt
                    if(login1){
                        preencheAlunos();
                        login1 = false;
                    }
                
                std::string materiaDesejada = " ";
                while(opcao2!=0){
                    std::cout << "Digite o valor da opcao desejada." <<
                    std::endl << "1) Visualisar notas" <<
                    std::endl << "2) Visualisar dados da minha matricula " <<
                    std::endl << "3) Visualisar minhas materias matriculadas" <<
                    std::endl << "4) Realizar requerimento" <<
                    std::endl << "0) Logout" << std::endl;
                    std::cin >> opcao2;
                    switch (opcao2){
                        case 1:
                            std::cout << std::endl << "Insira o nome de uma materia para ver as notas: ";
                            getchar();
                            std::getline(std::cin,materiaDesejada);
                            aluno->visuNotas(materiaDesejada);
                            break;
                        case 2:
                            aluno->visuDadosMatricula();
                            break;
                        case 3:
                            aluno->visuMaterias();
                            break;
                        case 4:
                            aluno->realizaRequerimento();
                            break;
                        case 0:
                            opcao2 = 0;
                            break;
                        default:
                            std::cout<<"Opcao digitada nao existe, digite novamente" << std::endl;
                            break;
                    }
                }
                std::cout<< "Obrigado por usar nosso sistema"; 
                opcao2 = 1;
                std::cout << ", deseja fazer login novamente ?" << std::endl << "1) Fazer login novamente" << std::endl << "0) Sair" << std::endl;
                std::cin >> opcao;

            }

            // Menu caso usuario for Professor
            else if (std::shared_ptr<Professor> professor = std::dynamic_pointer_cast<Professor>(user)) {
                //Preenche o map Alunos com os valores de Alunos.txt
                if(login1){
                    preencheAlunos();
                    login1 = false;
                }

                std::cout << "Bem-vindo, Professor!" << std::endl;
                opcao2 = 1;
                    unsigned int matriculaAluno; //precisa fazer um jeito do professor inserir a matricula do aluno
                    float notaAluno= 0; //precisa fazer um jeito do professor inserir a nota
                    long long unsigned int avaliacaoDesejada = 0; // precisa fazer um jeito de inserir qual av deve ser apagada
                    float notaDesejada=0;
                    std::string materiaDesejada;

                while(opcao2!=0){
                    std::cout << "Digite o valor da opcao desejada." <<
                    std::endl << "1) Adicionar notas para um aluno em uma materia" <<
                    std::endl << "2) Atualizar nota de um aluno " <<
                    std::endl << "3) Visualisar dados da minha matricula" <<
                    std::endl << "4) Visualisar avaliacao de todos os alunos ate o momento" <<
                    std::endl<< "0) Logout" << std::endl;
                    std::cin>> opcao2;

                    switch (opcao2){
                        case 1:
                            std::cout << std::endl << "Matricula do aluno: ";
                            std::cin >> matriculaAluno;                            
                            std::cout << std::endl << "Materia: ";
                            getchar();
                            std::getline(std::cin,materiaDesejada);
                            std::cout << std::endl << "Nota do aluno: ";
                            std::cin >> notaAluno;
                            professor->addNota(materiaDesejada,matriculaAluno,notaAluno);
                            break;
                        case 2:
                            std::cout << std::endl << "Matricula do aluno: ";
                            std::cin >> matriculaAluno;
                            std::cout << std::endl << "Materia: ";
                            getchar();
                            std::getline(std::cin,materiaDesejada);

                            std::cout << std::endl << "Avaliacao que deseja atualizar: ";
                            std::cin >> avaliacaoDesejada;
                            std::cout << std::endl << "Nota: ";
                            std::cin >> notaDesejada;

                            professor->update(avaliacaoDesejada, materiaDesejada, notaDesejada ,matriculaAluno);
                            break;
                        case 3:
                            professor->visuDadosMatricula();
                            break;
                        case 4:
                            std::cout << std::endl <<"Insira o nome de uma materia para ver as notas: ";
                            getchar();
                            std::getline(std::cin,materiaDesejada);
                            professor->visuNotasTodos(materiaDesejada);
                            break;
                        case 0:
                            opcao2 = 0;
                            break;
                        default:
                            std::cout<<"Opcao digitada nao existe, digite novamente";
                            break;
                    }
                }
                std::cout<< "Obrigado por usar nosso sistema.";
                professor->salvarDadosnoTXT();
                opcao2 = 1;
                std::cout << "Deseja fazer login novamente ?" << std::endl << "1) Fazer login novamente" << std::endl << "0) Sair" << std::endl;
                std::cin >> opcao;
            }

            // Menu caso usuario for Admin 
            else if (std::shared_ptr<Admin> admin = std::dynamic_pointer_cast<Admin>(user)) {
                std::cout << "Bem-vindo, Admin!" << std::endl;
                admin->preencheDados();

                //declarar parametros, todos os valores devem, o admin deve inserir todos valores antes de chamar a funcao
                    unsigned int matriculaManipulada;
                    std::string nome;
                    std::string senha;      
                    std::string dataNasc;
                    std::string curso;
                    std::string telefone;
                    std::string nacionalidade;
                    std::string email;
                    std::string CPF;
                    std::string sexo;
                    int NSG;
                    bool resEspecial;
                    Informacoes info;
                    std::string materia;                                      
                    std::string horario;
                    int cargaHoraria;
                    std::string aux;
                    std::vector<std::string> dia;
                    bool Booleano = true;
                    int SimNao;
                    bool first = true;

                    while(opcao2!=0){

                        std::cout << "Digite o valor da opcao desejada." <<
                        std::endl << "1) Inserir Admin" <<
                        std::endl << "2) Inserir Aluno" <<
                        std::endl << "3) Inserir Professor" <<
                        std::endl << "4) Inserir Materia" <<
                        std::endl << "5) Alterar regime especial de aluno" <<
                        std::endl << "6) Criar Materia" <<
                        std::endl << "7) Trancar materia de aluno" <<
                        std::endl << "8) Visualisar meus dados de matricula " <<
                        std::endl << "9) Visualisar dados de matricula (inserir matricula)" <<
                        std::endl << "10) Visualisar dados de matricula de todo mundo"<<
                        std::endl << "11) Realizar Trancamento Total de um aluno" <<
                        std::endl << "12) Visualizar Requerimentos" <<
                        std::endl  << "0) Logout" << std::endl;
                        std::cin>> opcao2;
                            
                        
                            
                        switch (opcao2){
                            case 1:  
                                std::cout << std::endl << "***Digite as informacoes do admin para inseri-lo no sistema***";
                                std::cout << std::endl << "Nome: ";
                                getchar();
                                std::getline(std::cin,nome);
                                std::cout << std::endl << "Matricula: ";
                                std::cin >> matriculaManipulada;
                                std::cout << std::endl << "Senha: ";
                                std::cin >> senha;
                                std::cout << std::endl << "Data de nascimento: (ex: 00/00/0000) ";
                                std::cin >> dataNasc;
                                std::cout << std::endl << "Telefone: (DDD) XXXXX-XXXX ";
                                std::cin >> telefone;
                                std::cout << std::endl << "Nacionalidade: ";
                                getchar();
                                std::getline(std::cin,nacionalidade);
                                std::cout << std::endl << "Email: ";
                                std::cin >> email;
                                std::cout << std::endl << "CPF: (Coloque os pontos) ";
                                std::cin >> CPF;
                                std::cout << std::endl << "Sexo: ";
                                std::cin >> sexo;
                                admin->insertAdmin(nome,matriculaManipulada,senha,dataNasc,telefone,nacionalidade,email,CPF,sexo);
                                break;
                            case 2:
                                std::cout << std::endl << "***Digite as informacoes do aluno para inseri-lo no sistema***";
                                std::cout << std::endl << "Nome: ";
                                getchar();
                                std::getline(std::cin,nome);
                                std::cout << std::endl << "Matricula: ";
                                std::cin >> matriculaManipulada;
                                std::cout << std::endl << "Senha: ";
                                std::cin >> senha;
                                std::cout << std::endl << "Data de nascimento: (20/08/2004) ";
                                std::cin >> dataNasc;
                                std::cout << std::endl << "Curso: ";
                                getchar();
                                std::getline(std::cin,curso);
                                std::cout << std::endl << "Telefone: (DDD) XXXXX-XXXX ";
                                std::cin >> telefone;
                                std::cout << std::endl << "Nacionalidade: ";
                                getchar();
                                std::getline(std::cin,nacionalidade);
                                std::cout << std::endl << "Email: ";
                                std::cin >> email;
                                std::cout << std::endl << "CPF: (Coloque os pontos) ";
                                std::cin >> CPF;
                                std::cout << std::endl << "Sexo: ";
                                std::cin >> sexo;
                                std::cout << std::endl << "NSG: ";
                                std::cin >> NSG;
                                std::cout << std::endl << "Esta de regime especial? 0 - Nao; 1 - Sim";
                                std::cin >> resEspecial;
                                admin->insertAluno(nome,matriculaManipulada,senha,dataNasc,curso,telefone,nacionalidade,email,CPF,sexo, NSG, resEspecial);
                                break;
                            case 3:
                                std::cout << std::endl << "***Digite as informacoes do professor para inseri-lo no sistema***";
                                std::cout << std::endl << "Nome: ";
                                getchar();
                                std::getline(std::cin,nome);
                                std::cout << std::endl << "Matricula: ";
                                std::cin >> matriculaManipulada;
                                std::cout << std::endl << "Senha: ";
                                std::cin >> senha;
                                std::cout << std::endl << "Data de nascimento: (20/08/2004) ";
                                std::cin >> dataNasc;
                                std::cout << std::endl << "Curso: ";
                                getchar();
                                std::getline(std::cin,curso);
                                std::cout << std::endl << "Telefone: (DDD) XXXXX-XXXX ";
                                std::cin >> telefone;
                                std::cout << std::endl << "Nacionalidade: ";
                                getchar();
                                std::getline(std::cin,nacionalidade);
                                std::cout << std::endl << "Email: ";
                                std::cin >> email;
                                std::cout << std::endl << "CPF: (Coloque os pontos) ";
                                std::cin >> CPF;
                                std::cout << std::endl << "Sexo: ";
                                std::cin >> sexo;
                                admin->insertProfessor(nome,matriculaManipulada,senha,dataNasc,curso,telefone,nacionalidade,email,CPF,sexo);
                                break;
                            case 4:
                                std::cout << std::endl << "Matricula: ";
                                std::cin >> matriculaManipulada;
                                std::cout << std::endl << "Materia que deseja adicionar: ";
                                getchar();
                                std::getline(std::cin,materia);
                                admin->insertMateria(matriculaManipulada,materia);
                                break;
                            case 5:
                                std::cout << std::endl << "Para qual matricula deseja-se ativar o regime especial? ";
                                std::cin >> matriculaManipulada;
                                admin->ativarRegEsp(matriculaManipulada);
                                break;
                            case 6:
                                std::cout << std::endl << "Materia que deseja adicionar: ";
                                getchar();
                                std::getline(std::cin,materia);
                                while(Booleano != false) {
                                    std::cout << std::endl << "Qual dia da Semana que tem aula da materia: ";
                                    if(!first){getchar();}
                                    first = false;
                                    std::getline(std::cin, aux);
                                    dia.push_back(aux);
                                    std::cout << std::endl << "Mais algum dia? (0 para SIM, qualquer outro para NAO )";
                                    std::cin >> SimNao;
                                    if(SimNao ==  0) {
                                        Booleano = true;
                                    }else{
                                        Booleano= false;
                                    }
                                }
                                std::cout << std::endl << "Horario: ";
                                std::cin >> horario;
                                std::cout << std::endl << "Carga horaria: ";                      
                                std::cin >> cargaHoraria;
                                admin->CriaMateria(materia, dia, horario, cargaHoraria);
                                break;
                            case 7:
                                std::cout << std::endl << "Matricula: ";
                                std::cin >> matriculaManipulada;
                                std::cout << std::endl << "Materia que deseja trancar: ";
                                std::cin >> materia;
                                admin->trancarMateria(matriculaManipulada,materia);
                                break;
                            case 8:
                                admin->visuDadosMatricula();
                                break;
                            case 9:
                                std::cout << std::endl << "Quer ver os dados de qual matricula? ";
                                std::cin >> matriculaManipulada;
                                admin->visuDadosMatriculaOutros(matriculaManipulada);
                                break;
                            case 10:
                                admin->visuDadosMatriculaTodos();
                                break;
                            case 11:
                                std::cout << std::endl << "Matricula: ";
                                std::cin >> matriculaManipulada;
                                admin->trancarTotal(matriculaManipulada);
                                break;
                            case 12:
                                admin->visuRequerimentos();
                                break;
                            case 0:
                                opcao2 = 0;
                                break;
                            default:
                                std::cout<<"Opcao digitada nao existe, digite novamente";
                                break;
                        }  
                    }
                std::cout<< "Obrigado por usar nosso sistema.";
                admin->salvarDadosnoTXT();
                opcao2 = 1;
                std::cout << "Deseja fazer login novamente ?" << std::endl << "1) Fazer login novamente" << std::endl << "0) Sair" << std::endl;
                std::cin >> opcao;
                }

            }
            // Caso não for nenhum das anteriores ocorreu um erro
            else{
                std::cout << "Matricula ou senha incorretas." << std::endl;
                
                
            } 
        }
        
        return SUCESSO;
}
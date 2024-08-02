#include<iostream>
#include<string.h>
#include <cstdlib>
#include"Sistema_Educacional.h"

#define SUCESSO 0

int main(){
    std::string password = " ";
    unsigned int matricula = 0;
    int opcao = 1, opcao2 = 0;
    
    while(opcao!=0){
    std::cout << "SISTEMA EDUCACIONAL" << std::endl << "Login(n* matricula): ";
    std::cin>> matricula;
    std::cout << std::endl << "Senha: ";
    std::cin>> password;
    
    
    std::shared_ptr<User> user = login(matricula, password);

    if (user) {
        std::cout << "Login bem-sucedido!" << std::endl;


        if (std::shared_ptr<Aluno> aluno = std::dynamic_pointer_cast<Aluno>(user)) {
            // Operações específicas do Aluno
            std::cout << "Bem-vindo, Aluno!" << std::endl;
            std::string materiaDesejada = "";
            while(opcao2!=0){
                std::cout << "Digite o valor da opcao desejada." << std::endl << "1) Visualisar notas" << std::endl << "2) Visualisar dados da minha matricula " << std::endl << "3) Visualisar minhas materias matriculadas" << std::endl << "0) Sair" << std::endl;
                std::cin>> opcao2;
                switch (opcao2)
                {
                case 1:
                    aluno->visuNotas(materiaDesejada);
                    break;
                case 2:
                    aluno->visuDadosMatricula();
                    break;
                case 3:
                    aluno->visuMaterias();
                    break;
                case 0:
                    opcao2 = 0;
                    break;
                default:
                    std::cout<<"Opcao digitada não existe, digite novamente" << std::endl;
                    break;
                }
            }
            opcao2 = 1;
            std::cout<< "Obrigado por usar nosso sistema"; 

        } else if (std::shared_ptr<Professor> professor = std::dynamic_pointer_cast<Professor>(user)) {
            // Operações específicas do Professor
            std::cout << "Bem-vindo, Professor!" << std::endl;
                while(opcao2!=0){
                    std::cout << "Digite o valor da opcao desejada." << std::endl << "1) Adicionar notas para um aluno em uma materia" << std::endl << "2) Apagar nota de aluno " << std::endl << "3) Visualisar dados da matricula de um aluno" << std::endl << "4) Visualisar avaliacao de todos os alunos ate o momento" << std::endl<< "0) Sair" << std::endl;
                    std::cin>> matricula;

                    unsigned int matriculaAluno; //precisa fazer um jeito do professor inserir a matricula do aluno
                    int notaAluno= 0; //precisa fazer um jeito do professor inserir a nota
                    int avaliacaoDesejada = 0; // precisa fazer um jeito de inserir qual av deve ser apagada
                    std::string materiaDesejada = "";
                    switch (opcao2)
                    {
                    case 1:
                        professor->addNota(materiaDesejada,matriculaAluno,notaAluno);
                        break;
                    case 2:
                        professor->apagar(avaliacaoDesejada, materiaDesejada, matriculaAluno);
                        break;
                    case 3:
                        professor->visuDadosMatricula();
                        break;
                    case 4:
                        professor->visuNotasTodos();
                        break;
                    case 0:
                        opcao2 = 0;
                        break;
                    default:
                        std::cout<<"Opcao digitada não existe, digite novamente";
                        break;
                    }
                }
                opcao2 = 1;
                std::cout<< "Obrigado por usar nosso sistema";
        } else if (std::shared_ptr<Admin> admin = std::dynamic_pointer_cast<Admin>(user)) {
            // Operações específicas do Admin
            std::cout << "Bem-vindo, Admin!" << std::endl;
                while(opcao2!=0){
                    std::cout << "Digite o valor da opcao desejada." << std::endl << "1) Visualisar notas" << std::endl << "2) Visualisar dados da minha matricula " << std::endl << "3) Visualisar minhas materias matriculadas" << std::endl<< "0) Sair" << std::endl;
                    std::cin>> matricula;
                    
                    //declarar parametros, todos os valores devem, o admin deve inserir todos valores antes de chamar a funçao
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
                    
                    switch (opcao2)
                    {
                    case 1:
                        admin->insertAdmin(nome,matriculaManipulada,senha,dataNasc,curso,telefone,nacionalidade,email,CPF,sexo);
                        break;
                    case 2:
                        admin->insertAluno(nome,matriculaManipulada,senha,dataNasc,curso,telefone,nacionalidade,email,CPF,sexo);
                        break;
                    case 3:
                        admin->insertProfessor(nome,matriculaManipulada,senha,dataNasc,curso,telefone,nacionalidade,email,CPF,sexo);
                        break;
                    case 4:
                        admin->insertMateria(matriculaManipulada,materia);
                        break;
                    case 5:
                        admin->ativarRegEsp(matriculaManipulada);
                        break;
                    case 6:
                        admin->CriaMateria(materia,info);
                        break;
                    case 7:
                        admin->trancarMateria(matriculaManipulada,materia);
                        break;
                    case 8:
                        admin->visuDadosMatricula(matriculaManipulada);
                        break;
                    case 9:
                        admin->visuDadosMatriculaTodos();
                        break;
                    case 0:
                        opcao2 = 0;
                        break;
                    default:
                        std::cout<<"Opcao digitada não existe, digite novamente";
                        break;
                    }  
                }
                opcao2 = 1;
                std::cout<< "Obrigado por usar nosso sistema";
        }
    } else {
        std::cout << "Matrícula ou senha incorretas." << std::endl;
    } 

    }

    std::exit(0);
    return SUCESSO;
}
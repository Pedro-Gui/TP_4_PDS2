
#include "Sistema_Educacional.h"
#include <iostream>

std::shared_ptr<User> Banco_de_dados::getUser(unsigned int matricula) {
    

    return nullptr;
}

bool Banco_de_dados::validPassword(const std::string& password) const {
   
    return true;
}

bool Banco_de_dados::validMatricula(unsigned int matricula) const {
   
    return true;
}


Aluno::Aluno(unsigned int matricula, const std::string& senha){}

void Aluno::visuNotas(const std::string& materia) {
    
    std::cout << "Visualizando notas da matéria: " << materia << std::endl;
}

void Aluno::visuDadosMatricula() const {

  
}

void Aluno::visuMaterias() {

    
}


Professor::Professor(unsigned int matricula, const std::string& senha){}

void Professor::addNota(const std::string& materia,unsigned int matricula, const float nota) {

    
}

void Professor::visuNotasTodos() {

    std::cout << "Visualizando notas de todos os alunos." << std::endl;
}

void Professor::apagar(int avaliacao, const std::string& materia,unsigned int matriculaAluno) {

    std::cout << "Apagando avaliação: " << avaliacao << std::endl;
}

void Professor::visuDadosMatricula() const {

    std::cout << "Visualizando dados da matrícula do professor." << std::endl;
}

Admin::Admin(unsigned int matricula, const std::string& senha){}

bool Admin::insertAluno(const std::string& nome, unsigned int matricula, const std::string& senha, const std::string& dataNasc, const std::string& curso,
                        const std::string& telefone, const std::string& nacionalidade, const std::string& email, const std::string& CPF, const std::string& sexo) {
    std::cout << "Inserindo aluno: " << nome << std::endl;
    return true;
}

bool Admin::insertProfessor(const std::string& nome, unsigned int matricula, const std::string& senha, const std::string& dataNasc, const std::string& curso,
                            const std::string& telefone, const std::string& nacionalidade, const std::string& email, const std::string& CPF, const std::string& sexo) {
    std::cout << "Inserindo professor: " << nome << std::endl;
    return true;
}

bool Admin::insertAdmin(const std::string& nome, unsigned int matricula, const std::string& senha, const std::string& dataNasc, const std::string& curso,
                        const std::string& telefone, const std::string& nacionalidade, const std::string& email, const std::string& CPF, const std::string& sexo) {
    std::cout << "Inserindo administrador: " << nome << std::endl;
    return true;
}

void Admin::insertMateria(unsigned int matricula, const std::string& materia) {
    std::cout << "Inserindo matéria com informações." << std::endl;
}

void Admin::trancarMateria(unsigned int matricula, const std::string& materia) {
    std::cout << "Trancando matéria: " << materia << std::endl;
}

void Admin::CriaMateria(const std::string& materia, Informacoes info){

}

void Admin::ativarRegEsp(unsigned int matricula) {
    std::cout << "Ativando regime especial." << std::endl;
}

void Admin::visuDadosMatriculaTodos() {
    std::cout << "Visualizando dados da matrícula de todos os usuários." << std::endl;
}

void Admin::visuDadosMatricula(unsigned int matricula){
    std::cout << "Visualizando dados da matrícula de ******" << std::endl;
}

std::shared_ptr<User> login(unsigned int matricula, const std::string& senha) {
    Banco_de_dados db;
    
    if(db.validPassword(senha) && db.validMatricula(matricula)){
    std::shared_ptr<User> user = db.getUser(matricula);
    return user;
    }
        return nullptr;
    }

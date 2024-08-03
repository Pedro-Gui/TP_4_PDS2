
#include "Sistema_Educacional.h"
#include <iostream>

std::shared_ptr<User> Banco_de_dados::getUser(unsigned int matricula) {//prioridade
    

    return nullptr;
}

bool Banco_de_dados::validPassword(const std::string& password) const {
   
    return true;
}

bool Banco_de_dados::validMatricula(unsigned int matricula) const {
   
    return true;
}


Aluno::Aluno(unsigned int matricula, const std::string& senha){} //prioridade

void Aluno::visuNotas(const std::string& materia) {
    
    std::cout << "Visualizando notas da matéria: " << materia << std::endl;

}

void Aluno::visuDadosMatricula() const {

    std::cout <<"Nome: "<< nome <<std::endl;
    std::cout <<"Matricula: "<< matricula <<std::endl;
    std::cout <<"Data de Nascimento: " << dataNasc <<std::endl;
    std::cout <<"Curso: "<< curso <<std::endl;
    std::cout <<"Telefone: "<< telefone <<std::endl;
    std::cout <<"Nacionalidade: " << nacionalidade <<std::endl;
    std::cout <<"Email: " << email <<std::endl;
    std::cout <<"CPF: " << CPF <<std::endl;
    std::cout <<"Sexo: " << sexo <<std::endl;
    std::string aux = regEspecial ? "SIM" : "NAO";
    std::cout << "Regime especial: "<< aux <<std::endl;
    std::cout <<"NSG: "<< NSG <<std::endl;
  
}

void Aluno::visuMaterias() {
    for(auto it : materias){
        std::cout << "Matéria:" << it.first << std::endl;
        for(auto x : it.second.dia){
            std::cout << "Dia: " << x << ", Horario: " << it.second.horario << std::endl;

        }
        std::string aux = it.second.condTrancado ? "SIM" : "NAO";
        std::cout << "Carga Horaria: " << it.second.cargaHoraria << std::endl;   
        std::cout << "Trancado: " << aux << std::endl;

    }
    
}


Professor::Professor(unsigned int matricula, const std::string& senha){} //prioridade

void Professor::addNota(const std::string& materia,unsigned int matricula, const float nota) {

    
}

void Professor::visuNotasTodos(std::string materia) {

    std::cout << "Visualizando notas de todos os alunos." << std::endl;
    for(auto it : Aluno){
        it.second->visuNotas(materia);
    }
}

void Professor::apagar(int avaliacao, const std::string& materia,unsigned int matriculaAluno) {

    std::cout << "Apagando avaliação: " << avaliacao << std::endl;
}

void Professor::visuDadosMatricula() const {

    std::cout << "Visualizando dados da matrícula do professor." << std::endl;
    std::cout <<"Nome: "<< nome <<std::endl;
    std::cout <<"Matricula: "<< matricula <<std::endl;
    std::cout <<"Data de Nascimento: " << dataNasc <<std::endl;
    std::cout <<"Curso: "<< curso <<std::endl;
    std::cout <<"Telefone: "<< telefone <<std::endl;
    std::cout <<"Nacionalidade: " << nacionalidade <<std::endl;
    std::cout <<"Email: " << email <<std::endl;
    std::cout <<"CPF: " << CPF <<std::endl;
    std::cout <<"Sexo: " << sexo <<std::endl;

}

Admin::Admin(unsigned int matricula, const std::string& senha){} //prioridade

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
    for(auto it : DadosAll){
        if (std::shared_ptr<Aluno> aluno = std::dynamic_pointer_cast<Aluno>(it.second)){
            aluno->visuDadosMatricula();
            }
        }
    for(auto it : DadosAll){
        if(std::shared_ptr<Professor> professor = std::dynamic_pointer_cast<Professor>(it.second)){
            professor->visuDadosMatricula();
        }
    }
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

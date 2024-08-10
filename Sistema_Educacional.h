#ifndef _SISTEMA_EDUCACIONAL_H
#define _SISTEMA_EDUCACIONAL_H

//Bibliotecas
#include <map>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
   
struct Informacoes{
    std::vector<std::string> dia;
    std::string horario;
    std::vector<float> notas;
    bool condTrancado;
    int cargaHoraria;
    int NumeroAvaliacoes;
};

class User {
    protected:
        std::string nome;
        unsigned int matricula; // 2023 ano 95 curso 1627 ident
        std::string senha;
        std::string dataNasc;
        std::string telefone;
        std::string nacionalidade;
        std::string email;
        std::string CPF;
        std::string sexo;
        

    public:
        virtual ~User() = default;
        
        /// @brief Imprime todos os dados de matricula sequencialmente;
        /// nome: nome \n matricula: matricula \n ... 
        virtual void visuDadosMatricula() = 0;
};

class Banco_de_dados {
    public:
        /// @brief identifica se é aluno, professor ou admin e acessa seu respectivo *.txt, apos isso cria uma classe aluno/professor/admin e usa seu construtor para inicializar a classe -
        /// @param matricula 
        /// @return aluno, admin ou professor
        std::shared_ptr<User> getUser(unsigned int matricula);
        /// @brief retorna uma struct materia preenchida com os dados de Materia.txt referente a materia desejada
        Informacoes getMateria(const std::string& materia);

        /// @brief verificar se a senha segue os seguintes requisitos:
        /* 
    * Condicao 1: A senha nao pode ter a seguencia '123456'.
    * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
    * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
    * Condicao 4: A senha nao pode ter caracteres em branco ' '.
    */
    /// @param password
    /// @return 0 - senha invalida; 1 - senha valida
        bool validPassword(const std::string& password) const;

        /// @brief verificar se a matricula segue os seguintes requisitos:
        /*
        * Condicao 1: 4 primeiros digitos serem maior que 2010.
        * Condicao 2: Digitos 5 e 6 serem digitos de identificacao de curso.
        * Condicao 3: 4 ultimos digitos serem de: 0-100 = (admin); 101-2000 = (professor); 2001-9999 = (aluno).
        */
        /// @param matricula
        /// @return 0 - matricula invalida; 1 - matricula valida
        bool validMatricula(unsigned int matricula) const;
    
};

class Aluno : public User {
    private:

            friend class Professor;
            friend class Admin;

            int NSG;
            bool regEspecial;
            std::string curso;
    std::map<std::string, Informacoes> materiasMap;

    public:
        Aluno(const std::string& nome2, unsigned int matricula2, const std::string& senha2, const std::string& dataNasc2, const std::string& curso2,
        const std::string& telefone2, const std::string& nacionalidade2, const std::string& email2, const std::string& CPF2, const std::string& sexo2, int NSG2,
            bool regEspecial2, const std::string& materia2);

        /// @brief permite o aluno visualizar suas notas de determinada materia
        /// @param materia
        void visuNotas(const std::string& materia);

        void visuDadosMatricula() override;

        /// @brief permite o aluno visualizar quais materias ele esta cursando, juntamente com o dia e horario da mesma
        void visuMaterias();

        /// @brief permite o aluno fazer um requerimento de trancamento, (Parcial ou Total), ou para entrar em regime especial;
        void realizaRequerimento();
};

class Professor : public User {
private:
    friend class Admin;
   // materia e dados do aluno
   std::string curso;
   float novaNota;
public:
    /// @brief preenche todos os parametros de user baseado nos dados vinculados a matricula no professor.txt
    /// @param matricula 
    /// @param senha 
    Professor(const std::string& nome2, unsigned int matricula2, const std::string& senha2, const std::string& dataNasc2, const std::string& curso2,
    const std::string& telefone2, const std::string& nacionalidade2, const std::string& email2, const std::string& CPF2, const std::string& sexo2);
   
    /// @brief cria avaliacoes e da notas a mesma ou modifica a nota de uma avaliacao ja existente
    /// @param avaliacao
    /// @param notas
    void addNota(const std::string& materia,unsigned int matricula, const float nota);

    void PreencheAlunos(const std::string& materia);

    /// @brief permite a visualizacao das notas de todos os alunos, especificados pelo numero de matricula
    void visuNotasTodos(std::string materia);

    /// @brief deleta determinada avaliacao do sistema 1,2,3 ou quarta avaliaçao, deve apagar e atualizar esta nota de  os alunos matriculados nesta materia.
    /// @param avaliacao
    void update(long long unsigned int avaliacao, const std::string& materia, float novaNota,unsigned int matriculaAluno);

    void visuDadosMatricula() override;

    void salvarDadosnoTXT();
    
    
};

class Admin : public User {
private:
    std::map<std::string, std::shared_ptr<User>> DadosAll;
public:
    /// @brief Preenche o map DadosAll com cada tipo de usuario
    void preencheDados();
    /// @brief preenche todos os parametros de user baseado nos dados vinculados a matricula no admin.txt
    /// @param matricula 
    /// @param senha 
    Admin(const std::string& nome, unsigned int matricula, const std::string& senha, const std::string& dataNasc, const std::string& telefone,
    const std::string& nacionalidade, const std::string& email, const std::string& CPF, const std::string& sexo);

    /// @brief Insere um novo aluno em alunos.txt, retorna 1 se o aluno foi inserido devidamente no txt, 0 c.c
    /// @param nome 
    /// @param matricula 
    /// @param senha 
    /// @param dataNasc 
    /// @param curso 
    /// @param telefone 
    /// @param nacionalidade 
    /// @param email 
    /// @param CPF 
    /// @param sexo 
    /// @return 
    void insertAluno(const std::string& nome, unsigned int matricula, const std::string& senha, const std::string& dataNasc, const std::string& curso,
                     const std::string& telefone, const std::string& nacionalidade, const std::string& email, const std::string& CPF, const std::string& sexo, int NSG,
        bool regEspecial);
    /// @brief Insere um novo aluno em professores.txt, retorna 1 se o professor foi inserido devidamente no txt, 0 c.c
    /// @param nome
    /// @param matricula
    /// @param senha
    /// @param dataNasc
    /// @param curso
    /// @param telefone
    /// @param nacionalidade
    /// @param email
    /// @param CPF
    /// @param sexo
    /// @return
    void insertProfessor(const std::string& nome, unsigned int matricula, const std::string& senha, const std::string& dataNasc, const std::string& curso,
                         const std::string& telefone, const std::string& nacionalidade, const std::string& email, const std::string& CPF, const std::string& sexo);
    /// @brief Insere um novo aluno em Admin.txt, retorna 1 se o admin foi inserido devidamente no txt, 0 c.c
    /// @param nome 
    /// @param matricula 
    /// @param senha 
    /// @param dataNasc 
    /// @param curso 
    /// @param telefone 
    /// @param nacionalidade 
    /// @param email 
    /// @param CPF 
    /// @param sexo 
    /// @return 
    void insertAdmin(const std::string& nome, unsigned int matricula, const std::string& senha, const std::string& dataNasc,const std::string& telefone, 
                    const std::string& nacionalidade, const std::string& email, const std::string& CPF, const std::string& sexo);

    /// @brief inseri a materia no aluno matriculado em aluno.txt 
    /// @param matricula 
    /// @param materia 
    void insertMateria(unsigned int matricula, const std::string& materia);


    /// @brief inseri uma materia nova em materia.txt
    /// @param matricula 
    /// @param materia 
    void CriaMateria(const std::string& materia, std::vector<std::string> dia, const std::string& horario, int cargaHoraria);
    /// @brief Tranca a materia do aluno possuidor de matricula, para isso mudar o numero referente ao trancamento em aluno.txt
    /// @param materia 
    /// @param matriculaAluno
    void trancarMateria(unsigned int matriculaAluno, const std::string& materia);
    /// @brief Ativa o reg esp do aluno possuidor de matricula, para isso mudar o numero referente ao reg esp em aluno.txt
    /// @param matriculaAluno
    void ativarRegEsp(unsigned int matriculaAluno);

    /// @brief Tranca todas materias do aluno
    /// @param matriculaAluno 
    void trancarTotal(unsigned int matriculaAluno);

    /// @brief Visualiza Requerimentos
    void visuRequerimentos();
    
    /// @brief imprime os dados de matricula de cada aluno, por exemplo imprime de um aluno, quando apertar enter imprime de outro aluno e assim por diante, quando apertar 0 sai da função.
    void visuDadosMatriculaTodos();
    
    /// @brief imprime os dados de matricula do aluno/professor possuidor da matricula
    void visuDadosMatriculaOutros(unsigned int matricula);

    ///@brief impreme os dados de matricula do admin atualmente logado
    void visuDadosMatricula() override;

    ///@brief salva todos os dados sobre escrevendo Admin.txt Professores.txt Alunos.txt Login.txt
    void salvarDadosnoTXT();
};

/// @brief 
/// @param matricula 
/// @param senha 
/// @return 
std::shared_ptr<User> login(unsigned int matricula, const std::string& senha);
void preencheAlunos();
#endif // _SISTEMA_EDUCACIONAL_H
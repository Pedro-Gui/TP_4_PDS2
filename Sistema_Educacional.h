#ifndef _SISTEMA_EDUCACIONAL_H
#define _SISTEMA_EDUCACIONAL_H

#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class User : public Banco_de_dados, public Materia{
   private:
   
      string Nome;              // String de nome completo no max 100 
      unsigned int matricula;   // 2023076559 -> 2023 ano de ingresso / 07 numero do curso / 6559 identificador de aluno // 0000000000 -> Admin
      string senha;             // Sem sequencia, menor que 50 caracteres, maior que 6 caracteres, sem espaco em branco  // Admin0 -> Senha Admin
      string data_Nasc;          //Data  nascimento dd/mm/aa
      string curso;
      int telefone;
      string nacionalidade;
      string email;
      int CPF;
      string sexo;              //Masc ou Fem
      int NSG; //Nota Semestral Global --> média ponderada , peso baseado na carga horária semanal da matéria
      bool Reg_Especial; //Se o usuário está em Regime Especial
   
   struct informacoes{
      map<string, vector<int>> horario; /* dia e horario da materia, "Sexta" -> vector[0] horario de inicio da aula
                                                                                vector[1] horario de fim da aula */      
      map<string, vector<int>> notas; /*map de provas e suas notas, "P1" -> vector[0] nota tirada
                                                                            vector[1] nota maxima*/
      bool CondTrancado;
      int CargaHoraria; /* Carga horária semanal da matéria */
   };
      
   map<string, informacoes> Materias;
   //map<string, informacoes> passwords_;

   public:
      void cadastro(string nome,
                     unsigned int matricula,
                     int funcaoID,
                     string datanasc,
                     string curso,
                     int telefone,
                     string Nacionalidade,
                     string email,
                     int CPF,
                     string sexo);

      bool validPassword(const string& password) const;

      bool login(string matricula, string Senha);

       
};

class Banco_de_dados {
   public:
   Aluno get_aluno(unsigned int matricula);
   Professor get_professor(unsigned int matricula);
   Admin get_admin(unsigned int matricula);

};

class Materia : public Banco_de_dados{
      public:
      User get_user(unsigned int matricula);
      void condicao(bool CondTrancado);                                   /* Professor deleta avaliacao ja existente */
};

 
class Aluno : public User{
    void visu_avaliacoes(Materia param);                      // Aluno pode visualizar quais as avaliacoes da materia
    void visu_notas(Materia param); // Aluno pode visualizar as notas da materia
    void visu_dados_matricula();    
    void visu_materias(Materia param);
    void visu_horarios(Materia param);
};

class Professor : public User{
   public:
      void add_avaliacoes(const string &avaliacao);  //Professor pode adicionar avaliacoes e modifica-las 
      void add_notas(const string &avaliacao, const vector<int> &notas); //Professor pode adicionar notas e modifica-las
      void visu_notas_todos();
      void apagar(const string &avaliacao);
};

class Admin : public User{
public:
   bool insert_aluno(Aluno param);
   bool insert_professor(Professor param);
   void insert_materia(Materia param);
   void trancar_materia(Materia param);
   void Ativar_Reg_Esp(Aluno param);
   void visu_dados_matricula_todos();
};

#endif
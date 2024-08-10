#include "Sistema_Educacional.h"
std::map<std::string, std::shared_ptr<Aluno>> Alunos;

std::shared_ptr<User> Banco_de_dados::getUser(unsigned int matricula) {

    int identificacao = std::stoi(std::to_string(matricula).substr(6, 10)); //admin 0-100, professor 101-2000, aluno 2001-9999
    //std::cout << "Ident: " << identificacao << std::endl;

    if (identificacao >= 0 && identificacao <= 100) {
        std::ifstream AdminFile("Admin.txt");
        std::string linha;

        if (!AdminFile.is_open()) {
            std::cerr << "Erro ao abrir o arquivo dos Admin!" << std::endl;
            return nullptr;
        }

        while (std::getline(AdminFile, linha)) {
            //std::cout << " ..Rodando..";
            std::size_t pos = linha.find(';');
            if (pos != std::string::npos) {

                std::string matriculaTXT = linha.substr(pos + 1, 10);
                //std::cout << "...;" << matriculaTXT << " ...";
                if (std::to_string(matricula) == matriculaTXT) {
                    // std::cout << "Achou!" << std::endl;

                    size_t pos2 = 0, new_pos = linha.find(';');
                    std::string nome = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    unsigned int matriculaAdm = std::stoi(linha.substr(pos2, new_pos - pos2));
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string senha = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string dataNasc = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string sexo = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string CPF = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string telefone = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string email = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string nacionalidade = linha.substr(pos2, new_pos - pos2);

                    //std::cout << nome << " " << matriculaAdm << " " << senha << " " << dataNasc << " " << telefone << " " << nacionalidade << " " << email << " " << CPF << " " << sexo << std::endl;
                    std::shared_ptr<Admin> admin = std::make_shared<Admin>(nome, matriculaAdm, senha, dataNasc, telefone, nacionalidade, email, CPF, sexo);
                    return admin;
                }
            }
        }
        AdminFile.close();

        return nullptr;

    }

    if (identificacao >= 101 && identificacao <= 2000) {
        std::ifstream ProfFile("Professores.txt");
        std::string linha;

        if (!ProfFile.is_open()) {
            std::cerr << "Erro ao abrir o arquivo dos Professores!" << std::endl;
            return nullptr;
        }

        while (std::getline(ProfFile, linha)) {
            //std::cout << " ..Rodando..";
            std::size_t pos = linha.find(';');
            if (pos != std::string::npos) {

                std::string matriculaTXT = linha.substr(pos + 1, 10);
                //std::cout << "...;" << matriculaTXT << " ...";
                if (std::to_string(matricula) == matriculaTXT) {
                    // std::cout << "Achou!" << std::endl;

                    size_t pos2 = 0, new_pos = linha.find(';');
                    std::string nome = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    unsigned int matriculaProf = std::stoi(linha.substr(pos2, new_pos - pos2));
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string senha = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string dataNasc = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string sexo = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string curso = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string CPF = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string telefone = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string email = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string nacionalidade = linha.substr(pos2, new_pos - pos2);

                    // std::cout << nome << " " << matriculaProf << " " << senha << " " << dataNasc << " " << curso << " " << telefone << " " << nacionalidade << " " << email << " " << CPF << " " << sexo << std::endl;
                    std::shared_ptr<Professor> professor = std::make_shared<Professor>(nome, matriculaProf, senha, dataNasc, curso, telefone, nacionalidade, email, CPF, sexo);

                    return professor;
                }
            }
        }
        ProfFile.close();

        return nullptr;

    }

    if (identificacao >= 2001 && identificacao <= 9999) {
        std::ifstream AlunoFile("Alunos.txt");
        std::string linha;

        if (!AlunoFile.is_open()) {
            std::cerr << "Erro ao abrir o arquivo dos Alunos!" << std::endl;
            return nullptr;
        }

        while (std::getline(AlunoFile, linha)) {
            //std::cout << " ..Rodando..";
            std::size_t pos = linha.find(';');
            if (pos != std::string::npos) {

                std::string matriculaTXT = linha.substr(pos + 1, 10);
                //std::cout << "...;" << matriculaTXT << " ...";
                if (std::to_string(matricula) == matriculaTXT) {
                    // std::cout << "Achou!" << std::endl;

                    size_t pos2 = 0, new_pos = linha.find(';');
                    std::string nome = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    unsigned int matriculaAluno = std::stoi(linha.substr(pos2, new_pos - pos2));
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string senha = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string dataNasc = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string sexo = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string curso = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string CPF = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string telefone = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string email = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    unsigned int NSGaluno = std::stoi(linha.substr(pos2, new_pos - pos2));
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    bool RegEspAluno = (std::stoi(linha.substr(pos2, new_pos - pos2)) != 0) ? true : false;
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string materiasAluno = linha.substr(pos2, new_pos - pos2);
                    pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                    std::string nacionalidade = linha.substr(pos2, new_pos - pos2);

                    //std::cout << nome << " " << matriculaAluno << " " << senha << " " << dataNasc << " " << sexo << " " << curso << " " << CPF << telefone << " " << email << " " << NSGaluno << " " << RegEspAluno << " " << materiasAluno << " " << nacionalidade << std::endl;
                    std::shared_ptr<Aluno> aluno = std::make_shared<Aluno>(nome, matriculaAluno, senha, dataNasc, curso, telefone, nacionalidade, email, CPF, sexo, NSGaluno, RegEspAluno, materiasAluno);

                    return aluno;
                }
            }
        }
        AlunoFile.close();

        

    }
    return nullptr;
}

bool Banco_de_dados::validPassword(const std::string& password) const {
    std::vector<std::string> excecoes = {"012", "123", "234", "345", "456", "567", "678", "789"};
    for(const auto& ij : excecoes) {
        if(password.find(ij) != std::string::npos){ 
            std::cout << "Contem sequencia numerica!" << std::endl;
            return false;
        }
    }
    if (password.length() > 50 || password.length() < 6) {
        std::cout << "A senha deve ter no minimo 6 e no maximo 50 caracteres!" << std::endl;
        return false;
    }
    if (password.find(' ') != std::string::npos) {
        std::cout << "Nao eh permitido uso de espaco!" << std::endl;
        return false;
    }
    if (password.find(';') != std::string::npos) {
        std::cout << "Nao eh permitido uso de ; " << std::endl;
        return false;
    }
    return true;
}

bool Banco_de_dados::validMatricula(unsigned int matricula) const {
    std::string matricula_ = std::to_string(matricula);
    int ano = std::stoi(matricula_.substr(0, 4));

    if (matricula_.length() != 10) {
        return false;
    }
    if (ano <= 2010) {
        return false;
    }

    return true;
}

Informacoes Banco_de_dados::getMateria(const std::string& materia) {
    Informacoes info;
    
    std::ifstream MateriaFile("Admin.txt");
        std::string linha;

        if (!MateriaFile.is_open()) {
            std::cerr << "Erro ao abrir o arquivo dos MateriaTXT!" << std::endl;
        }

        while (std::getline(MateriaFile, linha)) {
            std::size_t pos = linha.find(';');
            if (pos != std::string::npos) {
                std::string materiaTXT = linha.substr(0, pos);
                if (materia == materiaTXT) {
                        //Probabilidade;60;segunda,quarta;9;
                        
                        size_t pos2 = 0, new_pos = linha.find(';');
                        std::string nome = linha.substr(pos2, new_pos - pos2); //nao quero essa informacao
                        pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                        info.cargaHoraria = std::stoi(linha.substr(pos2, new_pos - pos2)); // Carga Horaria
                        pos2 = new_pos + 1; new_pos = linha.find(';', pos2);

                        while (linha.find(',', pos2) != std::string::npos) {
                        info.dia.push_back(linha.substr(pos2, new_pos - pos2)); 
                        pos2 = new_pos + 1; new_pos = linha.find(',', pos2);

                        }new_pos = linha.find(';', pos2);
                        info.dia.push_back(linha.substr(pos2, new_pos - pos2)); 
                        pos2 = new_pos + 1; new_pos = linha.find(';', pos2);
                        pos2 = linha.find(';', pos2);
                        info.horario = linha.substr(pos2, new_pos - pos2); // 9

                        return info;

                    }
            }
        }

    return info;
}

void preencheAlunos(){
    Banco_de_dados db;
    std::ifstream Logins("Login.txt");
    std::string linha;


        if (!Logins.is_open()) {
            std::cout << "Erro ao abrir o arquivo!" << std::endl;
        }else{

        while (std::getline(Logins, linha)) {

                std::size_t pos = linha.find(';');
            if (pos != std::string::npos) {

                std::string matriculaTXT = linha.substr(0, pos);
                std::string senhaTXT = linha.substr(pos + 1, linha.length() - pos - 2);

                int identificacao = std::stoi(matriculaTXT.substr(6, 10)); //admin 0-100, professor 101-2000, aluno 2001-9999

                if (identificacao >= 2001 && identificacao <= 9999) { //se for aluno.....
                    
                    std::shared_ptr<User> user = db.getUser(std::stoi(matriculaTXT));
                    std::shared_ptr<Aluno> aluno = std::dynamic_pointer_cast<Aluno>(user);
                    
                    Alunos.insert({matriculaTXT,aluno});
                }
            }
        }
        Logins.close();
        }
    std::cout << std::endl;
    /*
    for(auto it: Alunos){
        std::cout << "Matricula:" << it.first << std::endl;
    }
    */
}


Aluno::Aluno(const std::string& nome2, unsigned int matricula2, const std::string& senha2, const std::string& dataNasc2, const std::string& curso2,
    const std::string& telefone2, const std::string& nacionalidade2, const std::string& email2, const std::string& CPF2, const std::string& sexo2, int NSG2,
    bool regEspecial2, const std::string& materia2) {
    nome = nome2;
    matricula = matricula2;
    senha = senha2;
    dataNasc = dataNasc2;
    curso = curso2;
    telefone = telefone2;
    nacionalidade = nacionalidade2;
    email = email2;
    CPF = CPF2;
    sexo = sexo2;
    NSG = NSG2;
    regEspecial = regEspecial2;
    //Separando a string materia, a cada " " é uma nova materia.
    // materia2 = "PDS2,0,10,15,22,40 Probabilidade,0,15,15,15,15 Calculo2,0,10,20,30,01 "
    std::vector<std::string> VectorMaterias;
    size_t pos = 0, new_pos = materia2.find(' ');

    while (materia2.find(' ', pos) != std::string::npos) {
        VectorMaterias.push_back(materia2.substr(pos, new_pos - pos));
        pos = new_pos + 1; new_pos = materia2.find(' ', pos);
       

    }VectorMaterias.push_back(materia2.substr(pos, materia2.length() - pos - 1));

    //agora que as materias estão separadas, cada posição do vetor está assim: PDS2,0,10,15,22,40 -> materia, trancado?, nota1, nota2,nota3,nota4

    std::ifstream MateriaFile("Materia.txt");
    std::string linha;

    if (!MateriaFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo dos Materia!" << std::endl;
    }
    while (std::getline(MateriaFile, linha)) {
        //std::cout << " ..Rodando..";
        size_t posTXT = 0, new_posTXT = linha.find(';');
        if (posTXT != std::string::npos) {
            for (auto it : VectorMaterias) {

                // std::cout << "String do Vector: " << it << std::endl;
                std::string materiaTXT = linha.substr(posTXT, new_posTXT - posTXT);//string materia que estava no materia.txt
                std::size_t posVector = it.find(",");
                std::string MateriaVectorTXT = it.substr(0, posVector); // string materia que estava no vetor MateriaVector
                // std::cout << "Materia:" << MateriaVectorTXT << " .. " << materiaTXT << std::endl;
                if (MateriaVectorTXT == materiaTXT) {
                    //std::cout << "Achou!" << std::endl;
                    Informacoes info;

                    size_t posVECTOR = 0, new_posVECTOR = it.find(',');
                    posTXT = 0, new_posTXT = linha.find(';');

                    posVECTOR = new_posVECTOR + 1; new_posVECTOR = it.find(',', posVECTOR);
                    posTXT = new_posTXT + 1; new_posTXT = linha.find(';', posTXT);

                    info.cargaHoraria = stoi(linha.substr(posTXT, new_posTXT - posTXT));

                    info.condTrancado = (std::stoi(it.substr(posVECTOR, new_posVECTOR - posVECTOR)) != 0) ? true : false;
                    posVECTOR = new_posVECTOR + 1; new_posVECTOR = it.find(',', posVECTOR);
                    posTXT = new_posTXT + 1; new_posTXT = linha.find(',', posTXT);
                    // std::cout << "Carga Hor " << info.cargaHoraria << std::endl << " CondTranc " << info.condTrancado << std::endl;


                    while (linha.find(',', posTXT) != std::string::npos) {
                        info.dia.push_back(linha.substr(posTXT, new_posTXT - posTXT));
                        posTXT = new_posTXT + 1; new_posTXT = linha.find(',', posTXT);

                    }new_posTXT = linha.find(';', posTXT);
                    info.dia.push_back(linha.substr(posTXT, new_posTXT - posTXT));
                    posTXT = new_posTXT + 1; new_posTXT = linha.find(';', posTXT);

                    /*for(auto x:info.dia){
                        std::cout << "Dia: " << x << std::endl;
                    }*/

                    new_posTXT = linha.find(';', posTXT);
                    info.horario = linha.substr(posTXT, new_posTXT - posTXT);

                    //std::cout << "Horario: " << info.horario << std::endl;

                    int num = 0;
                    while (it.find(',', posVECTOR) != std::string::npos) {
                        info.notas.push_back(stoi(it.substr(posVECTOR, new_posVECTOR - posVECTOR)));
                        posVECTOR = new_posVECTOR + 1; new_posVECTOR = it.find(',', posVECTOR);
                        num++;
                    }info.notas.push_back(stoi(it.substr(it.find_last_of(",") + 1, it.length() - it.find_last_of(","))));
                    num++;
                    /*
                    for(auto x:info.notas){
                        std::cout << "Nota " << x << std::endl;
                    }
                    */

                    info.NumeroAvaliacoes = num;

                    //std::cout << "Num av: " << info.NumeroAvaliacoes << std::endl;

                    materiasMap.insert({ MateriaVectorTXT,info });

                }
            }
        }
    }
    MateriaFile.close();

}

void Aluno::visuNotas(const std::string& materia) {
    auto it = materiasMap.find(materia);
    if (it != materiasMap.end()) {
        const Informacoes& info = it->second;
        std::cout << "Notas da materia: " << materia << std::endl;
        for (float nota : info.notas) {
            std::cout << "Nota: " << nota << std::endl;
        }
    }
    else {
        std::cout << "Materia " << materia << " nao encontrada." << std::endl;
    }
}

void Aluno::visuDadosMatricula() {
    
    float somaNotasCargaH = 0;  
    float somaCargaH = 0;       
    float somaNotasMateria;  

    for (const auto& jt : materiasMap) {
        const Informacoes& info = jt.second;

        somaNotasMateria = 0;  
        for (float nota : info.notas) {
            somaNotasMateria += nota;
        }
        somaNotasCargaH += somaNotasMateria * info.cargaHoraria; 
        somaCargaH += info.cargaHoraria;                          
    }
        NSG = (somaNotasCargaH / somaCargaH); 

   
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matricula: " << matricula << std::endl;
    std::cout << "Data de Nascimento: " << dataNasc << std::endl;
    std::cout << "Curso: " << curso << std::endl;
    std::cout << "Telefone: " << telefone << std::endl;
    std::cout << "Nacionalidade: " << nacionalidade << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "CPF: " << CPF << std::endl;
    std::cout << "Sexo: " << sexo << std::endl;
    std::string aux = regEspecial ? "SIM" : "NAO";
    std::cout << "Regime especial: " << aux << std::endl;
    std::cout << "NSG: " << NSG << std::endl;  

}

void Aluno::visuMaterias() {
    for (auto it : materiasMap) {
        std::cout << "Materia:" << it.first << std::endl;
        for (auto x : it.second.dia) {
            std::cout << "Dia: " << x << ", Horario: " << it.second.horario << std::endl;

        }
        std::string aux = it.second.condTrancado ? "SIM" : "NAO";
        std::cout << "Carga Horaria: " << it.second.cargaHoraria << std::endl;
        std::cout << "Trancado: " << aux << std::endl;

    }

}

void Aluno::realizaRequerimento(){
    std::string NomeArquivo = "Requerimento.txt";
    int Requerimento;
    std::string MateriaReq;
    std::string ReqRealizado;
    std::string Justificativa;
    bool encontrou = false;
    bool MenuReq = true;
    std::string StrMatricula = std::to_string(matricula);
    std::string Separador = "|";

    std::ofstream file2(NomeArquivo, std::ios::app);
    if (!file2.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << NomeArquivo << "." << std::endl;
        return;
    }

    while (MenuReq) {
        std::cout << "Digite o valor do Requerimento desejado." <<
        std::endl << "1) Regime Especial" << 
        std::endl << "2) Trancamento Parcial " <<
        std::endl << "3) Trancamento Total" << 
        std::endl << "0) Sair da aba de Requerimentos" << std::endl;

        std::cin >> Requerimento;
        std::cin.ignore(); // Ignora o '\n' deixado por std::cin
        
        switch (Requerimento){
            case 1:
                MateriaReq = "Nao Consta";
                ReqRealizado = "Regime Especial";
                std::cout << "Digite sua justificativa." << std::endl;
                std::getline(std::cin, Justificativa);
                break;
            case 2:
                encontrou = false;
                while (!encontrou){
                    visuMaterias();
                    std::cout << "Digite qual dessas materias deseja trancar." << std::endl;
                    std::getline(std::cin, MateriaReq);
                    
                    for (auto materia_it = materiasMap.begin(); materia_it != materiasMap.end(); materia_it++) {
                        if (materia_it->first == MateriaReq) {
                            encontrou = true;
                            MateriaReq = materia_it->first;
                            break; // Sai do loop assim que encontrar a matéria
                        }
                    }

                    if (!encontrou) {
                        std::cout << "Materia " << MateriaReq << " nao encontrada." << std::endl;
                    }
                }
                ReqRealizado = "Trancamento Parcial";
                std::cout << "Digite sua justificativa." << std::endl;
                std::getline(std::cin, Justificativa);
                break;
            case 3:
                MateriaReq = "Total";
                ReqRealizado = "Trancamento Total";
                std::cout << "Digite sua justificativa." << std::endl;
                std::getline(std::cin, Justificativa);
                break;
            case 0:
                std::cout << "Saindo da aba Requerimentos..." << std::endl;
                MenuReq = false;
                break;
            default:
                std::cout << "Opcao digitada nao existe, digite novamente" << std::endl;
                break;
        }

        if (MenuReq) {
            std::string ReqAdicionada = nome + Separador + StrMatricula + Separador + ReqRealizado + Separador + MateriaReq + Separador + Justificativa + Separador;
            file2 << ReqAdicionada << std::endl;
            std::cout << "Seu requerimento foi realizado em " << NomeArquivo << " com sucesso!" << std::endl;
        }
    }

    file2.close();
}


Professor::Professor(const std::string& nome2, unsigned int matricula2, const std::string& senha2, const std::string& dataNasc2, const std::string& curso2,
    const std::string& telefone2, const std::string& nacionalidade2, const std::string& email2, const std::string& CPF2, const std::string& sexo2) {
    nome = nome2;
    matricula = matricula2;
    senha = senha2;
    dataNasc = dataNasc2;
    curso = curso2;
    telefone = telefone2;
    nacionalidade = nacionalidade2;
    email = email2;
    CPF = CPF2;
    sexo = sexo2;
}

void Professor::addNota(const std::string& materia, unsigned int matriculaAluno, const float nota) {
    bool encontrou = false;
    for (auto it = Alunos.begin(); it != Alunos.end(); ++it) {
        auto aluno = it->second; 

        if (aluno->matricula == matriculaAluno) {
            auto materia_it = aluno->materiasMap.find(materia);
            if (materia_it == aluno->materiasMap.end()) {
                std::cout << "Materia " << materia << " nao encontrada para o aluno com matricula " << matriculaAluno << "." << std::endl;
                
            }
            else {
              //   Adiciona a nota na lista de notas da matéria
                Informacoes& info = materia_it->second;
                info.NumeroAvaliacoes=info.NumeroAvaliacoes + 1;
                info.notas.push_back(nota);
                encontrou = true;
               //  Mensagem de sucesso (opcional)
                std::cout << "Nota " << nota << " adicionada com sucesso para a materia " << materia << " do aluno com matricula " << matriculaAluno << "." << std::endl;
                
            }
        }
    }
    if(!encontrou){
        std::cout << "Aluno com matricula " << matriculaAluno << " nao encontrado." << std::endl;
    }
    
}

void Professor::visuNotasTodos(std::string materia) {
    std::cout << "Visualizando notas de todos os alunos." << std::endl;
    for (auto it : Alunos){
        std::cout << it.second->nome << " " << it.first << std::endl;
        it.second->visuNotas(materia);
    }
}

void Professor::update(int avaliacao, const std::string& materia, float novaNota, unsigned int matriculaAluno) {
    bool encontrou = false;
    for (auto it = Alunos.begin(); it != Alunos.end(); ++it) {
        auto aluno = it->second; 
            
        if (aluno->matricula == matriculaAluno) {
            auto materia_it = aluno->materiasMap.find(materia);
            if (materia_it == aluno->materiasMap.end()) {
                std::cout << "Materia " << materia << " nao encontrada para o aluno com matricula " << matricula << "." << std::endl;   
            }
            else {
                Informacoes& info = materia_it->second;
                    if(avaliacao<info.notas.size()){
                        info.notas[avaliacao-1]=novaNota;
                        encontrou = true;
                        std::cout << "Nota " << novaNota << " atualizada com sucesso para a materia " << materia << " do aluno com matricula " << matriculaAluno << "." << std::endl;
                }
                else{
                        std::cout << "Essa avaliacao nao existe" << std::endl ;
                }
            }
        }
    }
    if(!encontrou){
        std::cout << "Aluno com matricula " << matriculaAluno << " nao encontrado." << std::endl;
    }
}

void Professor::visuDadosMatricula() {

    std::cout << "Visualizando dados da matricula do professor." << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matricula: " << matricula << std::endl;
    std::cout << "Data de Nascimento: " << dataNasc << std::endl;
    std::cout << "Curso: " << curso << std::endl;
    std::cout << "Telefone: " << telefone << std::endl;
    std::cout << "Nacionalidade: " << nacionalidade << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "CPF: " << CPF << std::endl;
    std::cout << "Sexo: " << sexo << std::endl;

}

void Professor::salvarDadosnoTXT(){
    std::string fileName = "Alunos.txt";
    std::string linha;
    std::ofstream file2(fileName, std::ios::out);

    std::cout << "Salvando Dados, nao feche a aplicacao!" << std::endl;
    if (file2.is_open()) {  
    std::cout << "Salvando."; 
    for(auto ForAluno : Alunos){
    std::cout << ".";  
    //Teste Aluno;2024009999;testealuno;01/01/0001;Masculino;Engenharia;123.456.789-01;(01)92345-6789;AlunoTeste@gmail.com;00;0;PDS2,0,00,00,00,00 Probabilidade,0,00,00,00,00 Calculo2,0,00,00,00,00 ;brasileiro;
            ForAluno.second->nome;
            linha = ForAluno.second->nome +";"+std::to_string(ForAluno.second->matricula)+";"+ForAluno.second->senha+";"+ForAluno.second->dataNasc+";"+
            ForAluno.second->sexo +";" + ForAluno.second->curso + ";" + ForAluno.second->CPF + ";" + ForAluno.second->telefone + ";" + ForAluno.second->email + ";" + std::to_string( ForAluno.second->NSG)+ ";"+
            std::to_string(ForAluno.second->regEspecial)+ ";";
            for(auto ForMateria : ForAluno.second->materiasMap){
                linha+= ForMateria.first +","+ std::to_string(ForMateria.second.condTrancado)+",";
                    for(auto ForNotas : ForMateria.second.notas){
                        linha+=std::to_string(ForNotas)+",";
                    }
                linha.pop_back();//tira a ultima virgula
                linha+= " ";
            } 
            linha += ";"+ForAluno.second->nacionalidade+";";
            file2 << linha << std::endl;   
        }
        file2.close();
    }
    std::cout << std::endl << "Salvamento de dados Finalizado."<< std::endl;
}

Admin::Admin(const std::string& nome2, unsigned int matricula2, const std::string& senha2, const std::string& dataNasc2, const std::string& telefone2,
    const std::string& nacionalidade2, const std::string& email2, const std::string& CPF2, const std::string& sexo2) {
    nome = nome2;
    matricula = matricula2;
    senha = senha2;
    dataNasc = dataNasc2;
    telefone = telefone2;
    nacionalidade = nacionalidade2;
    email = email2;
    CPF = CPF2;
    sexo = sexo2;
}

void Admin::preencheDados(){
   Banco_de_dados db;
    std::ifstream Logins("Login.txt");
    std::string linha;
        if (!Logins.is_open()) {
            std::cerr << "Erro ao abrir o arquivo!" << std::endl;
           
        }

        while (std::getline(Logins, linha)) {
            std::size_t pos = linha.find(';');
            if (pos != std::string::npos) {
                std::string matriculaTXT = linha.substr(0, pos);
                std::string senhaTXT = linha.substr(pos + 1, linha.length() - pos - 2);

                // std::cout << "Linha: " << linha <<", Matricula: " << matriculaTXT << ", senha: " << senhaTXT << std::endl; //Verificando as entradas
                std::shared_ptr<User> user = db.getUser(stoi(matriculaTXT));
                DadosAll.insert({matriculaTXT,user});    
                
            }
        }
        Logins.close();
   /*for(auto x: DadosAll){
        std::cout << "Matricula:" << x.first << std::endl;
    }*/ 
    
}

void Admin::insertAluno(const std::string& nome, unsigned int matricula, const std::string& senha, const std::string& dataNasc, const std::string& curso,
    const std::string& telefone, const std::string& nacionalidade, const std::string& email, const std::string& CPF, const std::string& sexo, int NSG,
    bool regEspecial) {
        std::string materias = " ";
        if (DadosAll.find(std::to_string(matricula)) == DadosAll.end()) {
            std::shared_ptr<Aluno> aluno = std::make_shared<Aluno>(nome, matricula, senha, dataNasc, curso, telefone, nacionalidade, email, CPF, sexo, NSG, regEspecial, materias);
            DadosAll.insert({std::to_string(matricula),aluno});
            std::cout<< nome << " adicionado como aluno com sucesso!" << std::endl;
        }
        else{
            std::cout << "Erro: Aluno com matricula " << matricula << " ja existe." << std::endl;
        }       
}

void Admin::insertProfessor(const std::string& nome, unsigned int matricula, const std::string& senha, const std::string& dataNasc, const std::string& curso,
    const std::string& telefone, const std::string& nacionalidade, const std::string& email, const std::string& CPF, const std::string& sexo) {
        if (DadosAll.find(std::to_string(matricula)) == DadosAll.end()) {
            std::shared_ptr<Professor> professor = std::make_shared<Professor>(nome, matricula, senha, dataNasc, curso, telefone, nacionalidade, email, CPF, sexo);
            DadosAll.insert({std::to_string(matricula),professor});
            std::cout << nome << " adicionado como professor com sucesso!" << std::endl;
        }else{
             std::cout << "Erro: Professor com matricula " << matricula << " ja existe." << std::endl;
        }
}

void Admin::insertAdmin(const std::string& nome, unsigned int matricula, const std::string& senha, const std::string& dataNasc, const std::string& telefone,
    const std::string& nacionalidade, const std::string& email, const std::string& CPF, const std::string& sexo) {
        
        if (DadosAll.find(std::to_string(matricula)) == DadosAll.end()) {
            std::shared_ptr<Admin> admin = std::make_shared<Admin>(nome, matricula, senha, dataNasc, telefone, nacionalidade, email, CPF, sexo);
             DadosAll.insert({std::to_string(matricula),admin});
             std::cout<< nome << " adicionado como admin com sucesso!" << std::endl;
        }
        else{
            std::cout << "Erro: Admin com matricula " << matricula << " ja existe." << std::endl;
        }

}

void Admin::insertMateria(unsigned int matricula, const std::string& materia) {
    Banco_de_dados db;
    auto it = DadosAll.find(std::to_string(matricula));
    

    if (it != DadosAll.end()) {
        std::shared_ptr<Aluno> alunoPtr = std::dynamic_pointer_cast<Aluno>(it->second);
        if (alunoPtr) {                           //db.getMateria retorna um struct informacoes da materia
            alunoPtr->materiasMap.insert({materia,db.getMateria(materia)});   
        } else {
            std::cout << "A matricula " << matricula << " nao corresponde a um aluno.\n";
        }
    } else {
        std::cout << "A matricula " << matricula << " nao foi encontrada.\n";
    }
} 

void Admin::trancarMateria(unsigned int matriculaAluno, const std::string& materia) {
    bool encontrou = false;
    // Itera sobre todos os alunos para encontrar o aluno com a matrícula correta
    for (auto it = Alunos.begin(); it != Alunos.end(); ++it) {
        auto aluno = it->second; 

        // Verifica se a matrícula corresponde
        if (aluno->matricula == matriculaAluno) {
            auto materia_it = aluno->materiasMap.find(materia);
            if (materia_it == aluno->materiasMap.end()) {
                std::cout << "Materia " << materia << " nao encontrada para o aluno com matricula " << matriculaAluno << "." << std::endl;
                
            }
            else {
              //   Tranca a matéria;
                Informacoes& info = materia_it->second;
                info.condTrancado = true;
                encontrou = true;

               //  Mensagem de sucesso (opcional)
                std::cout << "Materia " << materia << " trancada com sucesso." << std::endl;
                
            }
        }
    }
    if(!encontrou){
        std::cout << "Aluno com matricula " << matriculaAluno << " nao encontrado." << std::endl;
    }
}

void Admin::trancarTotal(unsigned int matriculaAluno){
    bool encontrou = false;
    // Itera sobre todos os alunos para encontrar o aluno com a matrícula correta
    for (auto it = Alunos.begin(); it != Alunos.end(); ++it) {
        auto aluno = it->second; 

        // Verifica se a matrícula corresponde
        if (aluno->matricula == matricula) {
            for (auto materias = aluno->materiasMap.begin(); materias != aluno->materiasMap.end(); ++materias){
                trancarMateria(matriculaAluno,materias->first);
            }
            encontrou = true;
        }
    }
    if(!encontrou){
        std::cout << "Aluno com matricula " << matriculaAluno << " nao encontrado." << std::endl;
    }
}

void Admin::CriaMateria(const std::string& materia, std::vector<std::string> dia, const std::string& horario, int cargaHoraria) {
            Informacoes info;
            info.dia = dia;
            info.horario = horario;
            info.cargaHoraria = cargaHoraria;
            info.condTrancado = false;
            info.NumeroAvaliacoes = 0;

    std::string fileName = "Materia.txt";
    std::ifstream file(fileName, std::ios::app);
    std::string linha;
    bool materiaExiste = false;
    if (file.is_open()) {
                while (std::getline(file, linha)) {
                    std::size_t pos = linha.find(';');
                    if (pos != std::string::npos) {

                        std::string MateriaTXT = linha.substr(0,pos-1);

                        if (materia == MateriaTXT) {
                           materiaExiste = true;

                        }
                    }
                }
        file.close();
    }

    if(!materiaExiste){
        std::ofstream file2(fileName, std::ios::app);
        std::string MateriaAdicionada = materia+";"+ std::to_string(cargaHoraria)+";"; // "Probabilidade;60;segunda,quarta;9;";
                    for(auto diax : dia){
                        MateriaAdicionada += diax+",";
                    }MateriaAdicionada.pop_back();
                    MateriaAdicionada += ";"+horario+";";
                    


        if (file2.is_open()) {
            file2 << MateriaAdicionada << std::endl;
            file2.close();

            std::cout << "String adicionada ao final de " << fileName << " com sucesso!" << std::endl;
        } else {
            std::cerr << "Erro ao abrir o arquivo " << fileName << "." << std::endl;
        }
    }
}

void Admin::ativarRegEsp(unsigned int matriculaAluno) {
    bool encontrou = false;
    // Itera sobre todos os alunos para encontrar o aluno com a matrícula correta
    for (auto it = Alunos.begin(); it != Alunos.end(); ++it) {
        auto aluno = it->second; 

        // Verifica se a matrícula corresponde
        if (aluno->matricula == matriculaAluno) {
            aluno->regEspecial = true;
            encontrou = true;
        }
    }
    if(!encontrou){
        std::cout << "Aluno com matricula " << matriculaAluno << " nao encontrado." << std::endl;
    }
}

void Admin::visuDadosMatriculaTodos() {
    std::cout << "Visualizando dados da matricula de todos os usuarios." << std::endl;
    std::cout << "Alunos:" << std::endl;
    for (auto it : DadosAll) {
        if (std::shared_ptr<Aluno> aluno = std::dynamic_pointer_cast<Aluno>(it.second)) {
            aluno->visuDadosMatricula();
            std::cout<< std::endl << "Pressione enter para ver a proxima matricula" << std::endl;
            getchar();
        }
    }
    std::cout << "Professores:" << std::endl;
    for (auto it : DadosAll) {
        if (std::shared_ptr<Professor> professor = std::dynamic_pointer_cast<Professor>(it.second)) {
            professor->visuDadosMatricula();
            std::cout<< std::endl << "Pressione enter para ver a proxima matricula" << std::endl;
            getchar();
        }
    }
    std::cout << "Admins:" << std::endl;
    for (auto it : DadosAll) {
        if (std::shared_ptr<Admin> admin = std::dynamic_pointer_cast<Admin>(it.second)) {
            admin->visuDadosMatricula();
            std::cout<< std::endl << "Pressione enter para ver a proxima matricula" << std::endl;
            getchar();
        }
    }
    std::cout<< "Matriculas finalizadas." << std::endl;
           
}

void Admin::visuDadosMatriculaOutros(unsigned int matricula) {

    auto it = DadosAll.find(std::to_string(matricula));

    if (it != DadosAll.end()) {
        it->second->visuDadosMatricula();
    } else {
        std::cout << "Erro: Matricula " << matricula << " nao encontrada." << std::endl;
    }
}

void Admin::visuDadosMatricula() {

    std::cout << "Visualizando dados da matricula do Admin." << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matricula: " << matricula << std::endl;
    std::cout << "Data de Nascimento: " << dataNasc << std::endl;
    std::cout << "Telefone: " << telefone << std::endl;
    std::cout << "Nacionalidade: " << nacionalidade << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "CPF: " << CPF << std::endl;
    std::cout << "Sexo: " << sexo << std::endl;

}

void Admin::visuRequerimentos(){
    std::ifstream ReqFile("Requerimento.txt");
    std::string linha;

    if (!ReqFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de Requerimentos!" << std::endl;
    }else{
    //Glauber Silva|2024060810|Trancamento Parcial|Fundamentos de Mecanica| Justificativa|
        while (std::getline(ReqFile, linha)) {
            size_t pos = 0, new_pos = linha.find("|");
            std::string nomeAlunoReq = linha.substr(pos, new_pos - pos); //nome
            pos = new_pos + 1; new_pos = linha.find("|", pos);
            std::string matriculaAlunoReq = (linha.substr(pos, new_pos - pos)); //matricula
            pos = new_pos + 1, new_pos = linha.find("|", pos);
            std::string Requerimento = linha.substr(pos, new_pos - pos); //tranc parcial
            pos = new_pos + 1, new_pos = linha.find("|", pos);
            std::string MateriaReq = linha.substr(pos, new_pos - pos); // fund mec
            pos = new_pos + 1, new_pos = linha.find("|", pos);
            std::string Justificativa = linha.substr(pos, new_pos - pos); // Justificativa
            
            if (Requerimento == "Regime Especial"){
                std::cout << "Nome: " << nomeAlunoReq << "| Matricula: " << matriculaAlunoReq <<
                std::endl <<"Requerimento : " << Requerimento <<
                std::endl <<"Justificativa : " << Justificativa << std::endl;
               
            }else{
                std::cout << "Nome: " << nomeAlunoReq << "| Matricula: " << matriculaAlunoReq <<
                std::endl <<"Requerimento : " << Requerimento << "| Materia: " << MateriaReq <<
                std::endl <<"Justificativa : " << Justificativa << std::endl;
            }
            std::cout << std::endl;
        }
        ReqFile.close();
        std::ofstream Limpeza("Requerimento.txt", std::ios::out);
        Limpeza.close();
    }
}

void Admin::salvarDadosnoTXT(){
    std::cout << "Salvando Dados, nao feche a aplicacao!" << std::endl;
    //Limpando os arquivos antes de salvar
    std::ofstream Limpeza("Alunos.txt", std::ios::out);
    Limpeza.close();
    std::ofstream Limpeza2("Professores.txt", std::ios::out);
    Limpeza2.close();
    std::ofstream Limpeza3("Admin.txt", std::ios::out);
    Limpeza3.close();
    std::ofstream Limpeza4("Login.txt", std::ios::out);
    Limpeza4.close();
    std::cout << "Salvando.";

    for(auto ForUser : DadosAll){
        std::cout << ".";  
        int identificacao = std::stoi(ForUser.first.substr(6, 10)); //admin 0-100, professor 101-2000, aluno 2001-9999
        //std::cout << "Ident: " << identificacao << std::endl;
        if (identificacao >= 0 && identificacao <= 100) {
            std::string fileName = "Admin.txt";
            std::string linha;
            std::ofstream file2(fileName, std::ios::app);
            std::shared_ptr<Admin> ForUser2 = std::dynamic_pointer_cast<Admin>(ForUser.second);
            if (file2.is_open()) {   
                //Glauber;2024000000;testeadmin;01/01/0001;Masculino;123.456.789-01;(12)93456-7890;Admin@gmail.com;brasileiro; 
                linha = ForUser2->nome +";"+std::to_string(ForUser2->matricula)+";"+ForUser2->senha+";"+ForUser2->dataNasc+";"+
                ForUser2->sexo +";" + ForUser2->CPF + ";" + ForUser2->telefone + ";" + ForUser2->email +";"+ForUser2->nacionalidade+";";
                file2 << linha << std::endl;
                std::cout << linha << std::endl;   
                file2.close();  
            }
            
            std::string LoginName = "Login.txt";
            std::string linhaLogin;
            std::ofstream file(LoginName, std::ios::app);
            if (file.is_open()) {   
            
                //2024000000;testeadmin;
                linhaLogin = std::to_string(ForUser2->matricula)+";"+ForUser2->senha+";";
                file << linhaLogin << std::endl;   
                file.close();  
            }
            
            
        }

        if (identificacao >= 101 && identificacao <= 2000) {
            std::string fileName = "Professores.txt";
            std::string linha;
            std::ofstream file2(fileName, std::ios::app);
            std::shared_ptr<Professor> ForUser2 = std::dynamic_pointer_cast<Professor>(ForUser.second);
            if (file2.is_open()) {   
                //Teste Prof;2024002000;testeprofessor;01/01/0001;Masculino;Programacao;123.456.789-01;(01)92345-6780;Prof@gmail.com;brasileiro;
                linha = ForUser2->nome +";"+std::to_string(ForUser2->matricula)+";"+ForUser2->senha+";"+ForUser2->dataNasc+ ";" +
                ForUser2->sexo +";" + ForUser2->curso + ";" + ForUser2->CPF + ";" + ForUser2->telefone + ";" + ForUser2->email +";"+ForUser2->nacionalidade+";";
                file2 << linha << std::endl;   
                
                file2.close();
            }

            std::string LoginName = "Login.txt";
            std::string linhaLogin;
            std::ofstream file(LoginName, std::ios::app);
            if (file.is_open()) {   
            
                //2024000000;testeadmin;
                linhaLogin = std::to_string(ForUser2->matricula)+";"+ForUser2->senha+";";
                file << linhaLogin << std::endl;   
                file.close();  
            }

        }

        if (identificacao >= 2001 && identificacao <= 9999) {
            std::string fileName = "Alunos.txt";
            std::string linha;
            std::ofstream file2(fileName, std::ios::app);
            std::shared_ptr<Aluno> ForUser2 = std::dynamic_pointer_cast<Aluno>(ForUser.second);
            if (file2.is_open()) {   
            
            //Teste Aluno;2024009999;testealuno;01/01/0001;Masculino;Engenharia;123.456.789-01;(01)92345-6789;AlunoTeste@gmail.com;00;0;PDS2,0,00,00,00,00 Probabilidade,0,00,00,00,00 Calculo2,0,00,00,00,00 ;brasileiro; 
                    linha = ForUser2->nome +";"+std::to_string(ForUser2->matricula)+";"+ForUser2->senha+";"+ForUser2->dataNasc+ ";"+
                    ForUser2->sexo +";" + ForUser2->curso + ";" + ForUser2->CPF + ";" + ForUser2->telefone + ";" + ForUser2->email + ";" + std::to_string( ForUser2->NSG)+ ";"+
                    std::to_string(ForUser2->regEspecial)+ ";";
                    for(auto ForMateria : ForUser2->materiasMap){
                        linha+= ForMateria.first +","+ std::to_string(ForMateria.second.condTrancado)+",";
                            for(auto ForNotas : ForMateria.second.notas){
                                linha+=std::to_string(ForNotas)+",";
                            }
                        linha.pop_back();//tira a ultima virgula
                        linha+= " ";
                    } 
                    linha += ";"+ForUser2->nacionalidade+";";
                    file2 << linha << std::endl;   
                
                file2.close();
            }

            std::string LoginName = "Login.txt";
            std::string linhaLogin;
            std::ofstream file(LoginName, std::ios::app);
            if (file.is_open()) {   
            
                //2024000000;testeadmin;
                linhaLogin = std::to_string(ForUser2->matricula)+";"+ForUser2->senha+";";
                file << linhaLogin << std::endl;   
                file.close();  
            }
        }
    }
    std::cout << std::endl << "Salvamento de dados Finalizado." << std::endl;  
}


std::shared_ptr<User> login(unsigned int matricula, const std::string& senha) {
    Banco_de_dados db;
    std::ifstream Logins("Login.txt");
    std::string linha;

    if (db.validPassword(senha) && db.validMatricula(matricula)) {
        if (!Logins.is_open()) {
            std::cerr << "Erro ao abrir o arquivo!" << std::endl;
            return nullptr;
        }

        while (std::getline(Logins, linha)) {
            std::size_t pos = linha.find(';');
            if (pos != std::string::npos) {
                std::string matriculaTXT = linha.substr(0, pos);
                std::string senhaTXT = linha.substr(pos + 1, linha.length() - pos - 2);

                // std::cout << "Linha: " << linha <<", Matricula: " << matriculaTXT << ", senha: " << senhaTXT << std::endl; //Verificando as entradas

                if (std::to_string(matricula) == matriculaTXT && senha == senhaTXT) {
                    Logins.close();
                    std::shared_ptr<User> user = db.getUser(matricula);
                    return user;
                }
            }
        }
        Logins.close();

    }
    return nullptr;
}
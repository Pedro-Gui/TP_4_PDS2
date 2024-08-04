#include "Sistema_Educacional.h"


std::shared_ptr<User> Banco_de_dados::getUser(unsigned int matricula) {


    Banco_de_dados db;
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

        return nullptr;

    }

}

bool Banco_de_dados::validPassword(const std::string& password) const {
    if (password.find("123") != std::string::npos) {
        std::cout << "A sequencia 123 nao eh permitida!" << std::endl;
        return false;
    }
    if (password.length() > 50 || password.length() < 6) {
        std::cout << "A senha deve ter no minimo 6 e no maximo 50 caracteres!" << std::endl;
        return false;
    }
    if (password.find(' ') != std::string::npos) {
        std::cout << "Nao eh permitido uso de espaco!" << std::endl;
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
        std::cout << "Notas da matéria: " << materia << std::endl;
        for (float nota : info.notas) {
            std::cout << "Nota: " << nota << std::endl;
        }
    }
    else {
        std::cout << "Matéria não encontrada: " << materia << std::endl;
    }
}

void Aluno::visuDadosMatricula() const {

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
        std::cout << "Matéria:" << it.first << std::endl;
        for (auto x : it.second.dia) {
            std::cout << "Dia: " << x << ", Horario: " << it.second.horario << std::endl;

        }
        std::string aux = it.second.condTrancado ? "SIM" : "NAO";
        std::cout << "Carga Horaria: " << it.second.cargaHoraria << std::endl;
        std::cout << "Trancado: " << aux << std::endl;

    }

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
    //falta preencher o map Alunos
}

void Professor::addNota(const std::string& materia, unsigned int matricula, const float nota) {
    // Itera sobre todos os alunos para encontrar o aluno com a matrícula correta
    for (auto it = Alunos.begin(); it != Alunos.end(); ++it) {
        auto aluno = it->second; 

        // Verifica se a matrícula corresponde
        if (aluno->matricula == matricula) {
            auto materia_it = aluno->materiasMap.find(materia);
            if (materia_it == aluno->materiasMap.end()) {
                std::cout << "Matéria " << materia << " não encontrada para o aluno com matrícula " << matricula << "." << std::endl;
                return;
            }
            else {
                // Adiciona a nota na lista de notas da matéria
                Informacoes& info = materia_it->second;
                info.notas.push_back(nota);

                // Mensagem de sucesso (opcional)
                std::cout << "Nota " << nota << " adicionada com sucesso para a matéria " << materia << " do aluno com matrícula " << matricula << "." << std::endl;
                return;
            }
        }
    }
    std::cout << "Aluno com matrícula " << matricula << " não encontrado." << std::endl;
}

void Professor::visuNotasTodos(std::string materia) {
    std::cout << "Visualizando notas de todos os alunos." << std::endl;
    for (auto it : Alunos) {
        std::cout << it.first << std::endl;
        it.second->visuNotas(materia);
    }
}

void Professor::apagar(int avaliacao, const std::string& materia, unsigned int matriculaAluno) {
    for (auto it = Alunos.begin(); it != Alunos.end(); ++it) {
        auto materia_it = it->second->materiasMap.find(materia);
        Informacoes info = materia_it->second;
        auto pos = info.notas.begin() + (avaliacao - 1);
        info.notas.erase(pos);
    }
    std::cout << "Apagando avaliação: " << avaliacao << std::endl;
}

void Professor::visuDadosMatricula() const {

    std::cout << "Visualizando dados da matrícula do professor." << std::endl;
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
    //preencher o map Dados all em outra função e chamar-la antes de visu dados todos
}

bool Admin::insertAluno(const std::string& nome, unsigned int matricula, const std::string& senha, const std::string& dataNasc, const std::string& curso,
    const std::string& telefone, const std::string& nacionalidade, const std::string& email, const std::string& CPF, const std::string& sexo, int NSG,
    bool regEspecial) {
    std::cout << "Inserindo aluno: " << nome << std::endl;
    return true;
}

bool Admin::insertProfessor(const std::string& nome, unsigned int matricula, const std::string& senha, const std::string& dataNasc, const std::string& curso,
    const std::string& telefone, const std::string& nacionalidade, const std::string& email, const std::string& CPF, const std::string& sexo) {
    std::cout << "Inserindo professor: " << nome << std::endl;
    return true;
}

bool Admin::insertAdmin(const std::string& nome, unsigned int matricula, const std::string& senha, const std::string& dataNasc, const std::string& telefone,
    const std::string& nacionalidade, const std::string& email, const std::string& CPF, const std::string& sexo) {
    //...
    return true;
}

void Admin::insertMateria(unsigned int matricula, const std::string& materia) {
    //...
}

void Admin::trancarMateria(unsigned int matricula, const std::string& materia) {
    //...
}

void Admin::CriaMateria(const std::string& materia, Informacoes info) {

}

void Admin::ativarRegEsp(unsigned int matricula) {
    //...
}

void Admin::visuDadosMatriculaTodos() {
    std::cout << "Visualizando dados da matrícula de todos os usuários." << std::endl;
    std::cout << "Alunos:" << std::endl;
    for (auto it : DadosAll) {
        if (std::shared_ptr<Aluno> aluno = std::dynamic_pointer_cast<Aluno>(it.second)) {
            aluno->visuDadosMatricula();
        }
    }
    std::cout << "Professores:" << std::endl;
    for (auto it : DadosAll) {
        if (std::shared_ptr<Professor> professor = std::dynamic_pointer_cast<Professor>(it.second)) {
            professor->visuDadosMatricula();
        }
    }
    std::cout << "Admins:" << std::endl;
    for (auto it : DadosAll) {
        if (std::shared_ptr<Admin> admin = std::dynamic_pointer_cast<Admin>(it.second)) {
            admin->visuDadosMatricula();
        }
    }
}

void Admin::visuDadosMatriculaOutros(unsigned int matricula) {
    //...
}

void Admin::visuDadosMatricula() const {

    std::cout << "Visualizando dados da matrícula do professor." << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matricula: " << matricula << std::endl;
    std::cout << "Data de Nascimento: " << dataNasc << std::endl;
    std::cout << "Telefone: " << telefone << std::endl;
    std::cout << "Nacionalidade: " << nacionalidade << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "CPF: " << CPF << std::endl;
    std::cout << "Sexo: " << sexo << std::endl;

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

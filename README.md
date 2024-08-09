**Sistema educacional de notas**

**Descrição:** Como aluno ou professor, desejo poder ter o controle do meu curso em um meio digital unificado.

**Critérios de Aceitação:** 

Posso fazer login com meu numero de identificação e senha; (Pedro G)

Posso ver dados da minha matricula;            (Bruno)

Posso visualizar as notas das avaliações como aluno e adiconar/modificar como professor;   (Henrique)

Posso ver minhas materias vigentes e seus respectivos horarios; (Wallace)

Posso fazer requerimentos de ocorrencias (trancamento parcial/total, regime especial) do meu curso; (Leonardo)

**Cartão CRC:**
| Classe | Responsabilidade | Colaborador |
| :---         |     :---:      |          ---: |
| User  | Dados gerais de todos os usuários  | ---  |
| Banco_de_dados   | Armazenar dados | ---  |
| Professor  | Funções utilizadas por professores | User |
| Admin    | Funções utilizadas por administradores | User |
| Aluno   | Funções utilizadas por alunos | User |

**Descrição do Projeto**
<p align="justify">
  O mundo acadêmico está crescendo cada vez mais, sendo intimamente relacionado a busca por melhores condições de vida. Em um sistema acadêmico há diversas necessidades diárias por parte dos alunoes e também dos professores. Em um ambiente com poucas pessoas é viável possuir alguém que atende todos os alunos presencialmente para ajudá-los com seus problemas, porém, em um ecossistema com mais pessoas, isso se torna inviável. Há muita informação necessária no dia a dia, sendo que nem sempre é possível adquiri-las por si de modo fácil. A comunicação entre professores e alunos se torna mais complicada, até mesmo situações de controle de notas torna-se dificil. Muitas informações importantes precisam ser decoradas, ou então carregadas junto a si, mas sem uso o uso recorrente, é apenas mais um desconforto na vida de pessoas que já possuem muitas preocupações. 
<p align="justify">
  Dessa forma, decidimos criar um sistema digital unificado que permite a utilização segura de alunos, professores e administradores por meio de um número de identificação e senha. Apresenta os dados relacionados ao usuário, tais quais nome, número de identificação da universidade, período (no caso dos alunos) e tempo de instituição no caso de professores, ano de ingresso na universidade, curso e departamento ao qual pertence, estado da matricula (jubilado, cursando ou trancado), e-mail, entre outros. Essa parte do sistema permitira o usuário ter acesso a algumas informações básicas, mas importantes de maneira fácil e rápida para situações de necessidade.
 <p align="justify">
  O sistema permitirá que os alunos visualizem os pontos obtidos por ele em determinada materia, os dados essenciais do seu perfil, como dados pessoais e informações sobre a matricula e informações relacionadas a determinada matéria, como o dia e horário da aula e se ele trancou ou não a matéria. Os professores poderam adicionar notas individuais para cada aluno, vê se determinado aluno cursa a sua matéria, vê as notas de todos alunos, visualiza os seus dados pessoais e dados relacionados ao número de identificação e visualiza as notas de todos os alunos. O administrador conseguirá inserir professores, alunos e outros administradores no sistema, além de criar matérias e inseri-las no sistema. Há, também, a possibilidade de visualização dos próprios dados do admin, dos outros usuários e de todos ao mesmo tempo. Por fim, ele consegue ativar regime especial para determinado aluno, assim como, trancar parcialmente ou totalmente.

**Descrição do funcionamento do Projeto**

<p align="justify">
Na funcao main, aparece uma mensagem indicando que você está tentando entrar no sistema educacional e pede para que seja inserido a matricula e senha. Estando tudo certo, o login é bem sucedido e aparece uma mensagem de "Bem vindo" juntamente com a sua função dentro do sistema (aluno, professor ou admin). Após isso, lhe são dadas as opções do que deseja fazer e são pedidas as informações necessárias para realizar o que foi pedido, como por exemplo, se como aluno, quiser visualizar suas notas em determinada matéria, lhe é pedido para escrever o nome da matéria.
<p align="justify">
O .cpp lê os arquivos para adquirir os dados e adiciona-los no sistema. A seguir apresento o formato no qual os dados devem estar no .txt para que o programa funcione:
<p align="justify">  
Admin.txt:   
  
Nome;Matricula;Senha;Dia/Mês/Ano;Sexo;CPF(XXX.XXX.XXX);Telefone(DDD)XXXXX-XXXX;Email;Nacionalidade;

  
Aluno.txt:
<p align="justify">
Nome;Matricula;Senha;Dia/Mês/Ano;Sexo;Curso;CPF(XXX.XXX.XXX);Telefone(DDD)XXXXX-XXXX;Email;NSG;Regime Especial(0 = Não, 1 = Sim);Matéria;Matéria Trancada(0 = Não, 1 = Sim);Notas da Materia(Quantas quiser, mas sempre separadas por ;);Nacionalidade;


Login.txt:

Matricula;Senha;


Materia.txt:

Matéria;Carga Horária;Dias da semana que tem a materia(quantas quiser, separadas por ;);Horário;


Professor.txt:

Nome;Matricula;Senha;Dia/Mês/Ano;Sexo;Curso;CPF(XXX.XXX.XXX);Telefone(DDD)XXXXX-XXXX;Email;Nacionalidade;


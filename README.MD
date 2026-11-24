# SISTEMA DE ADOÇÃO DE ANIMAIS PATAS

## Sobre o projeto

Sistema desenvolvido em liguagem em c para gerenciamento de animais disponivéis para adoção

## Autoria
Nome: Jéssica veiga 

Matricula: 202210503705

## Instituição 

A instituição escolhida foi uma ONG de adoção de pets localizada na Palhoça,APRAP (Amigos e Protetores dos Animais de Palhoça.
Ela foi escolhida por ser próxima à região, ele possibilita uma orgaização dos animais por cadastro, sendo possível a procura 
tanto pelo código que o animal possui quanto pela idade desejada.


## Funcionalidades

- cadastro de animais 
- busca por idade 
- busca por código 
- remoção do animal
- listagem dos animais 

## Estruras de dados 

- lista encadeada
- Árvore AVL

## Tecnologias utilizadas 

- linguagem c
- CLion
- CMake

## Execução e compilação

Baixe ou clone o repositório do projeto.

Abra a pasta do projeto no CLion.

Aguarde o CMake carregar e configurar os arquivos.

Clique em Build para compilar o projeto.

Clique em Run para executar o programa.

O menu principal será exibido no terminal, permitindo acessar as funcionalidades do sistema.


## Pasta imagens

Local que estarão salvas as 4 imagens que serão usadas para demonstração do código, ao ser requisitado dentro estrutura cadastro a
imagem, será escrita o nome das imagens armazenando assim o caminho do arquivo da imagem.

## Pasta dados 

Guarda o arquivo TXT dos cadastros

## Pasta main.c 

Inicializa as estruturas de dados, carrega os cadastros salvos anteriormente,
e disponibiliza um menu interativo para realizar operações de cadastro, consulta, listagem e remoção de animais.

No ínicio da pasta main são inicializadas a raiz da árvore AVL e a lista encadeada com NULL, também são declaradas as
variáveis necessárias para armazenar os cadastros e as opções escolhidas pelo usuário.
Chama-se a função carregar_arquivo(&lista, &raiz) para abrir o arquivo TXT que contem os cadastros salvos anteriormente.
Exibe um menu de opções utilizando uma estrutura do while e utiliza switch para executar a operação correspondente à opção selecionada.
Repete a exibição do menu até que o usuário escolha a opção zero para sair.

Opção 1:
Novo cadastro.

Usa a função cadastrar_ficha() para coletar os dados do animal e utilizando a função inserir_ficha() insere o novo cadastro dentro da lista encadeada
após isso mostra o novo cadastro com a função apresentar_ficha() para o usuário, usando a função a inserir() insere também na árvore e salva o cadastro 
num arquivo TXT.

Opção 2:
Apresenta os cadastros existentes.

Usa a função listar_ficha(lista) para percorrer a lista e apresentar os cadastros existentes.

Opção 3:
Procura animal pelo código.

Usa a função buscar_ficha(listar,código) para percorrer a lista procurando o animal pelo código e devolve o endereço do 
cadastro, que é apresentado pela função listar_ficha(encontrado).

Opção 4:
Remove o animal pelo código.

Usa a função remover_ficha(&lista, código) para remover o cadastro correspondente ao código solicitado na lista e chama a 
função remover(raiz,código) para remover o cadastro da árvore AVL também, chama-se a função salvar_arquivo(lista) para uma atualização
quando apagado algum cadastro.

Opção 5:
Busca o animal pela idade

Usa a função busca(raiz, idade) percorre a árvore AVL para localizar a animais com a idade solicitada.

Opção 0:
Encerra a repetição do menu e finaliza a execução do programa.


## Pasta cadastro.h

Arquivo responsável pela definição da estrutura cadastro e pela declaração das funções relacionadas ao cadastro
e à apresentação das informações dos animais

Dentro da estrutura cadastro:

Armazena-se os dados dos animal cadastro no sistema.

Código, identificador único do animal no sistema.

Especie, espécie do animal, como gato ou cachorro.

Nome, nome do animal.

Raça, raça do animal.

Idade, idade do animal.

Sexo, sexo do animal.

Porte, porte físico do animal, como pequeno, médio ou grande.

Vacinado, informa se o animal está vacinado.

Castrado, informa se o animal está castrado.

Personalidade, descrição das características comportamentais do animal.

Foto, armazena o nome ou caminho do arquivo de imagem do animal.

Foram declaradas as funções:

Cadastrar_ficha(void): realiza a coleta das informações do animal e retorna uma variável do tipo cadastro preenchida com os dados informados.

Apresentar_ficha(cadastro animal): recebe uma variável do tipo cadastro e apresenta as informações correspondentes ao animal.


## Pasta cadastro.c 


* Função cadastrar_ficha()

A função é responsável por realizar o cadastro de um novo animal no sistema de adoção.

Lógica

É declarada uma variável chamada animal, do tipo cadastro, que será utilizada para armazenar todas as informações fornecidas pelo usuário,
em seguida, a função solicita ao usuário os dados do animal, como código, espécie ...
para receber os dados, são utilizados comandos printf(), que exibem as mensagens na tela, 
scanf(), que recebem as informações digitadas pelo usuário.
Após receber todas as informações, é utilizado o comando return animal para retornar a estrutura preenchida.

* Função apresentar_ficha()

A função é responsável por apresentar o cadastro realizado

Parâmetro 

Cadastro animal, variavel do tipo cadastro que recebe os dados do animal que será inserido

lógica 

Ela recebe como parâmetro uma variável do tipo cadastro, chamada animal, que contém os dados armazenados anteriormente 
pela função de cadastro. Inicialmente, utiliza o comando printf() para apresentar um título, identificando que as informações
exibidas correspondem à ficha do animal, em seguida, são utilizados comandos printf() para mostrar individualmente 
cada campo da estrutura, como código, espécie..

## Pasta lista.h

Arquivo responsável pela definição da estrutura do nó da lista encadeada e pela declaração das funções utilizadas para manipular os cadastros dos animais.

Estrutura No:

Define cada nó da lista encadeada, sendo composto por:

Animal, Armazena os dados do animal por meio da estrutura cadastro.

Prox, Ponteiro que armazena o endereço do próximo nó da lista.

Funções declaradas:

Inserir_ficha(No*lista, cadastro animal): recebe os dados de um animal, realizando a inserção de um novo cadastro na lista.

Listar_ficha(No*lista): percorre a lista encadeada e apresenta os cadastros dos animais armazenados.

Remover_ficha(No**lista, int código): remove da lista o cadastro correspondente ao código informado. 

Buscar_ficha(No*lista, int código): percorre a lista procurando um animal pelo código e retorna o endereço do nó encontrado. Caso não encontre, retorna NULL.

## Pasta lista.c

* Função inserir_ficha()

Insere um novo cadastro a lista encadeada 

Paramêtros 

Ponteiro lista, guarda o endereço do ínicio da lista
Cadastro animal, variável do tipo cadastro que recebe os dados do animal que será inserido 

Lógica 

Usa-se o ponteiro novo para guardar o endereço da memória alocada para o novo elemento
verifica se o malloc conseguiu alocar memória, caso não, volta para endereço original do ínicio da lista,
se bem-sucedido copia os dados recebidos pelo parâmetro animal e atribui ao campo animal do novo nó
o campo do prox do nó recebe o endereço do antigo nó, tendo assim uma ligação para poder percorrer a lista,
retorna o endereço do novo nó e é atualizado na variavel lista por meio da funçao inserir_ficha ,incluindo assim o outro nó dentro da lista encadeada,
ele retorna o endereço do novo ínicio da lista, considerando que todos os novos nós serão inseridos no começo da lista 

* Função listar_ficha()

Apresenta todos os cadastros presentes na lista encadeada

Parâmetros

Ponteiro lista, guarda o endereço do ínicio da lista

Lógica

O ponteiro atual que usamos para percorrer os nós começa apontando para o ínicio da lista,ele serve para não perder o endereço
do primeiro nó da lista,
e enquanto for diferente de NULL continua percorrendo e apresentando as fichas com a função apresentar_ficha 
o ponteiro atual recebe o endereço do proximo nó para continuar percorrendo até chegar ao final da lista encadeada (NULL)

* Função buscar_ficha()

Busca o cadastro do animal pelo código.

Parâmetros

Ponteiro lista, guarda o endereço do ínicio da lista

Variável código, o ID que cada animal recebe

Lógica

O código do animal que pretende encontrar será solicitado,
o ponteiro atual recebe o endereço do ínicio da lista que vai percorrer os nós enquanto o ponteiro atual for diferente 
de NULL, enquanto percorre ele compara o código solicitado com o código de cada nó percorrido, se encontrado ele retorna
o endereço do nó, caso contrario, continua percorrendo, se não encontrado retorna NULL.


* Função remover_ficha()

Remove o cadastro do animal pesquisando pelo código.

Parâmetros 

Ponteiro para o ponteiro lista = guarda o endereço do ínicio da lista

Variável código = o ID que cada animal recebe

Lógica

O ponteiro anterior ele inicia como NULL, pois começa no ínicio da lista e não possui nó anterior.
O ponteiro atual começa no ínicio da lista, ele percorre os elementos enquanto ele for diferente de NULL 
(NULL = aponta para o fim da lista) ele verifica se o código do animal é igual ao solicitado, se verdadeiro, 
ele verifica se o anterior é igual a NULL, nesse caso estamos no começo da fila e o endereço do ponteiro lista é atribuido ao proximo nó, 
caso não seja o primeiro estamos no meio ou final da lista, e então o campo prox do anterior recebe o endereço do prox do atual, isso permite que não perca a ligação entre os nós, e por fim libera a memória alocada. 
Caso não seja encontrado a função informará que o animal não foi encontrado.

## Pasta Árvore.h


Arquivo responsável pela definição da estrutura dos nós da árvore AVL e pela declaração das funções utilizadas para inserir, consultar, remover e balancear os animais cadastrados.

Estrutura Noarv

Define cada nó da árvore AVL, sendo composto por:


Animal, Armazena os dados do animal por meio da estrutura cadastro.

Esquerda, Ponteiro para o filho esquerdo do nó. 

Direita, Ponteiro para o filho direito do nó. 


Funções declaradas:

- altura(Noarv *raiz): calcula e retorna a altura da árvore ou subárvore.

- fatorbalanceamento(Noarv *raiz): calcula o fator de balanceamento do nó, utilizando a diferença entre as alturas das subárvores esquerda e direita.

- rotacaodir(Noarv *raiz): realiza a rotação simples à direita para corrigir o desbalanceamento da árvore.

- rotacaoesq(Noarv *raiz): realiza a rotação simples à esquerda para corrigir o desbalanceamento da árvore.

- rotacaoesdi(Noarv *raiz): realiza a rotação dupla esquerda-direita.

- rotacaodies(Noarv *raiz): realiza a rotação dupla direita-esquerda.

- balancear(Noarv *raiz): verifica o fator de balanceamento e identifica a rotação necessária para corrigir possíveis desbalanceamentos.

- inserir(Noarv *raiz, cadastro animal): recebe a raiz da árvore e os dados do animal, realizando a inserção de acordo com a idade 

- busca(Noarv *raiz, int idade): procura os animais cadastrados de acordo com a idade informada e apresenta suas fichas.

- removermenor(Noarv *raiz): remove o nó de menor idade de uma árvore ou subárvore.

- encontrarmenor(Noarv *raiz): localiza e retorna o endereço do nó de menor idade de uma árvore ou subárvore.

- remover(Noarv *raiz, int codigo): procura e remove um animal utilizando seu código de identificação

**Organização da árvore:**

A árvore AVL é organizada pela idade dos animais. O balanceamento é realizado por meio de rotações simples e duplas, mantendo a estrutura equilibrada após as operações de inserção e remoção.
## Pasta Árvore.c

* Função altura()

Parâmetros 

Ponteiro raiz, do tipo Noarv, que indica o início da árvore ou de uma subárvore.

Lógica

Verifica-se a raiz é NULL, se verdadeiro retorna 0, altura igual a 0.
São declaradas duas variáveis inteiras:
- alturaesq: recebe a altura da subárvore esquerda.
- alturadir: recebe a altura da subárvore direita.

Usa-se de recursividade para encontrar a altura de cada subarvore, com raiz sendo um nó da subarvore esquerdo ou direita
depois de calcular os dois lados, a função compara as alturas.
Se a esquerda for maior, retorna a altura esquerda acrescida de 1. Caso contrário, retorna a altura direita 
acrescida de 1, o mais 1 serve para incluir o nó atual.


*Função fatorbalanceamento()

Parâmetro

Ponteiro raiz, que indica o início da árvore ou de uma subárvore.

Lógica 

Inicialmente verifica-se o valor da raiz é igual a NULL, que significa a árvore está vazia, retornando o valor 0 se verdadeiro,
caso contrario ele utiliza a função feita anteriormente altura(),para verificar o balanceamento entre as subárvores, 
a altura da subárvore da esquerda subtrai da altura da subárvore da direita, retornando o nível de desbalanceamento 


* Função rotacaoesq()

Utilizada para reorganizar quando a raiz está desbalanceada para direita

Parâmetros 

Ponteiro y, que representa a raiz antes do balanceamento

Lógica 

Utiliza-se de três ponteiros, inicialmente o ponteiro x aponta para o filho direito do ponteiro y, que representa a raiz 
o ponteiro temp é utilizado para apontar para o filho esquerdo de x, guarda se ele para que não se perca parte da árvore,
o x se torna a nova raiz, y passa a ser o filho esquerdo de x e o ponteiro temp passa ser o filho direito de y 
retorna o valor de x, que se torna a nova raiz da função balanceada.


* Função rotacaodir()

Utilizada para reorganizar quando a raiz está desbalanceada para esquerda

Parâmetro

ponteiro x,que representa a raiz antes do balanceamento

Lógica 

Utiliza-se de três ponteiros, inicialmente o ponteiro y aponta o filho esquerdo de x, que representa a raiz, o ponteiro
temp a ponta para o filho direito de y, o y passa a ser a nova raiz, o x passa a ser o filho direito de y e temp passa
a ser filho esquerdo de x, retorna-se y a nova raiz.

* Função rotacaoesdi()

Nessa função é necessaria duas rotações primeiro a esquerda e após a direita.

Parâmetro 

Ponteiro raiz, que indica o início da árvore ou de uma subárvore.

Lógica 

Utiliza-se duas funções produzidas anteriormente para auxiliar nessa função, a primeira função é a rotacaoesq() que realiza uma rotação para
esquerda, logo após utiliza-se a segunda função rotacaodir() que realiza a rotação a direita.

* Função rotaçãodies()

Nessa função é necessaria duas rotações primeiro a direita e após a esquerda.

Parâmetro

Ponteiro raiz, que indica o início da árvore ou de uma subárvore.

Lógica

Utiliza-se duas funções produzidas anteriormente para auxiliar nessa função, a primeira função é a rotacaodir() que realiza uma rotação para
direita, logo após utiliza-se a segunda função rotacaoesq() que realiza a rotação a esquerda.

* Função balancear ()

"Feita com o auxiÍlio de IA"

Parâmetro

Ponteiro raiz, que indica o início da árvore ou de uma subárvore.

Lógica

Calcula-se a diferença entre a altura da subárvore esquerda e a direita atraves da função fatorbalanceamento() se:
- Maior que 1: árvore pesada à esquerda.
fator do filho esquerdo maior ou igual a zero. Significa que o filho esquerdo está equilibrado ou também está pesado à esquerda,
chama-se a função rotacaodir()
fator do filho esquerdo menor que zero. Significa que o filho esquerdo está pesado à direita, chama-se a função rotacaoesdi().
- Menor que -1: árvore pesada à direita.
fator do filho direito menor ou igual a zero, significa que o filho direito está equilibrado ou pesado à direita. chama-se a função rotacaoesq()
fator do filho direito maior que zero, significa que o filho direito está pesado à esquerda. chama-se a função rotacaodies()
- Entre -1 e 1: árvore balanceada.
nesse caso retorna somente a raiz 


* Função inserir()

Insere um novo nó na árvore

Parâmetros

Ponteiro raiz, que indica o início da árvore ou de uma subárvore;

Cadastro animal, variavel do tipo cadastro que recebe os dados do animal que será inserido na árvore;

Lógica

Trabalha-se com dois casos:
1º caso - está vazia:
Verifica-se a árvore está vazia, caso esteja, cria-se um ponteiro para a memória reservada do novo nó, que é feita atravez do malloc
após isso insere-se os dados do animal no nó e aponta se que tanto o ponteiro direito quanto o esquerdo estão vazios, indicando assim que 
a raiz não possui filhos, e então retorna o novo criado para a árvore.
2º caso - já possui nós:
aplica-se uma regra para a inserção, se a idade do animal inserido for menor que a idade do animal da raiz ele é inserido a esquerda 
caso contrário ele é inserido a direita, logo animais da mesma idade ou superior serão inseridos a direita.
Após a inserção verifica-se o fator de balanceamento do nó atual.
E por fim ele utiliza uma outra função auxiliar balancear() para fazer o balanceamento da árvore, caso desbalanceada.

*Função busca()

Busca o animal pela idade.

Parâmetro

Ponteiro raiz, que indica o início da árvore ou de uma subárvore

Idade, variavel que representa a idade do animal.

Lógica

Verifica-se inicialmente a raiz está vazia, se verdadeiro, apresentar "animal não encontrado",para a busca.
Se falso verificar se a idade que procura a igual a do animal do nó comparado, se verdadeiro apresentar a ficha dele 
utilizado a função feita anteriormente apresentar_ficha().
Se falso, verificar se idade que procura é menor do que o animal comparado, se verdadeiro continuar procurando pela 
esquerda, mesmo se encontrar,continuar procurando, pois pode haver mais de um animal como a mesma idade,
Se falso, verificar se idade que procura é maior do que o animal comparado, se verdadeiro continuar procurando pela
direita, mesmo se encontrar, continuar procurando, pois pode haver mais de um animal como a mesma idade,
em caso de ser achado ele vai apresentar com a função apresentar_ficha().

* Função removermenor()

Tem como função remover o menor valor da árvore ou subarvore.

Parâmetro

Ponteiro raiz, que indica o início da árvore ou de uma subarvore.

Lógica

Verifica-se inicialmente se o nó possui algum filho a esquerda caso não possua, ele é o menor valor da árvore ou subarvore
guarda-se o endereço do nó direito do que será removido, para que não se perca o restante da árvore, liber-se o nó menor
e retorna o nó da direita substituindo-o, caso contrário ele continua a procura do nó mais a esquerda e ao encontrar o libera, após
isso se chama a funcão balancear() para balancear a raiz.


* Função encontrarmenor()

Tem como função encontrar o menor valor da árvore ou subarvore.

Parâmetro

Ponteiro raiz, que indica o início da árvore ou de uma subarvore.

Lógica

Começamos no ínicio da árvore, e percorremos os nós da esquerda enquanto for diferente de NULL, ao encontrar o
NULL, representando que não tem mais filhos, retorna o endereço desse nó, é percorrido os valores a esquerda devido à ordenação
da nossa árvore, os menores valores ficam a esquerda.

* Função remover()

Parâmetros 

Ponteiro raiz, que indica o ínicio da árvore ou de uma subarvore;

Código, que indica o ID do animal.


Lógica

A busca é feita atraves do código do animal que você deseja remover.
Verifica se a raiz está vazia, se verdadeiro, ele retorna NULL, não aponta para nenhum valor válido.
Se a raiz não estiver vazia e ele encontrar o codigo solicitado, ocorrem 4 casos:

1º caso - sem filhos:
Se o ponteiro que a ponta para a esquerda e o ponteiro para direita apontarem para NULL, isso significa que eles não
possuem filhos, se apaga o nó e retorna o valor NULL.

2º caso- somente filho a direita:
O ponteiro à esquerda do nó aponta para o NULL, logo ele só possui filhos a direita, nesse caso é utilizado um ponteiro auxiliar
que aponta para o filho direito e libera a memória do nó que se deseja remover, após isso o filho direito toma o lugar do removido
retornando o valor que o auxiliar guardou.

3º caso- somente filho a esquerda:
O ponteiro à direita do nó aponta para o NULL, logo ele possui somente o filho a esquerda, nesse caso é utilizado um ponteiro auxiliar 
que aponta para o filho esquerda e libera a memória do nó que se deseja remover, após isso o filho esquerdo toma o lugar do removido
retornando o valor que o auxiliar guardou.

4º caso- possui 2 filhos:
Utiliza-se um ponteiro para receber o endereço do nó que é encontrado utilizando a função encontrarmenor(), ele encontra o menor
valor da subárvore da direita, após isso copiamos os dados presentes no menor valor da subarvore direita para o nó que queremos apagar,
e apagamos o menor valor.

a busca é realizada nas duas subárvores porque a árvore está organizada pela idade, e não pelo código. Após encontrar o animal, realiza-se a remoção e o rebalanceamento da árvore.

## Pasta arquivo.h

Foram declaradas as funções:

- void salvar_arquivo(No *lista), transfere os dados da lista para arquivo TXT
- void carregar_arquivo(No **lista, Noarv **raiz), recupera os dados do TXT e reconstrói a lista e a árvore AVL

## Pasta arquivo.c

  "Feita com auxilio de IA"

* Função salvar_arquivo()

  salvar todos os cadastros dos animais armazenados na lista encadeada num arquivo de texto

Parâmetro

Ponteiro lista, guarda o endereço do ínicio da lista;

Lógica
Inicialmente recebe o ponteiro para o início da lista, após abre o arquivo no modo escrita ("w").
Verifica se o arquivo é igual a NULL, se verdadeiro ele avisa que ocorreu um erro.
Percorre a lista utilizando while, acessando os dados de cada animal e utiliza fprintf para gravar os campos do cadastro,
por fim fecha o arquivo com fclose após finalizar a gravação.

*Função carregar_arquivos()

Recuperar os cadastros dos animais armazenados no arquivo de texto e reconstruir a lista encadeada e a árvore AVL.

Parâmetros

ponteiro para o ponteiro lista;

ponteiro para o ponteiro raiz

Lógica

Inicialmente recebe o endereço do ponteiro da lista e o endereço do ponteiro da raiz da árvore.
Abre o arquivo no modo leitura ("r") e verifica se o arquivo foi encontrado e aberto corretamente.
Utiliza fscanf para ler os dados de cada animal e insere cada cadastro recuperado na lista encadeada por meio da função inserir_ficha.
Insere cada cadastro também na árvore AVL por meio da função inserir, por fim fecha o arquivo após concluir a leitura.

## Estruturas de dados utilizadas

O projeto utiliza duas estruturas de dados principais: lista encadeada e árvore AVL. Cada uma possui uma finalidade específica no gerenciamento dos cadastros dos animais.

| Estrutura | Onde foi utilizada | Justificativa da escolha |
|---|---|---|
| Lista encadeada | Armazenamento dos cadastros, listagem, inserção e remoção de animais. | Foi escolhida por permitir inserções e remoções dinâmicas, sem a necessidade de definir previamente um tamanho fixo, diferentemente de um vetor estático. |
| Árvore AVL | Organização dos animais por idade e realização de buscas utilizando esse critério. | Foi escolhida por ser uma árvore binária de busca balanceada, mantendo a altura controlada e proporcionando operações de busca, inserção e remoção eficientes, diferentemente de uma árvore binária de busca não balanceada. |


As duas estruturas trabalham em conjunto para oferecer diferentes formas de organização e consulta dos animais cadastrados.

Projeto Final em C – Caça ao Tesouro
Descrição

Este projeto consiste no desenvolvimento de um jogo em linguagem C denominado Caça ao Tesouro. O objetivo é controlar um jogador num mapa representado por uma matriz, explorando o cenário para encontrar a chave e, posteriormente, o tesouro, evitando obstáculos e armadilhas.

O projeto foi desenvolvido de forma faseada, seguindo uma metodologia de desenvolvimento incremental, com registo da evolução através de commits no GitHub e atualizações no ficheiro LOG.md.

Objetivos

Este projeto tem como principal objetivo aplicar os conteúdos estudados durante o módulo de Programação em C, nomeadamente:

Utilização de funções;
Manipulação de matrizes;
Utilização de strings;
Estruturas de decisão e repetição;
Implementação de recursão;
Organização modular do código;
Utilização do Git e GitHub para controlo de versões.
Funcionalidades

Atualmente o jogo inclui:

Menu principal;
Início de um novo jogo;
Visualização das regras;
Sistema de pontuações;
Mapa representado por uma matriz;
Movimento do jogador através das teclas W, A, S e D;
Paredes que impedem a passagem;
Chave (K);
Tesouro (T);
Sistema de pontuação;
Estrutura preparada para adicionar armadilhas, vidas e novas funcionalidades.
Estrutura do Projeto

O projeto está organizado da seguinte forma:

main.c – Contém a função principal e o menu da aplicação.
jogo.c – Implementa a lógica do jogo.
jogo.h – Contém os protótipos das funções.
LOG.md – Registo das sessões de desenvolvimento.
README.md – Documentação do projeto.
.gitignore – Ficheiros ignorados pelo Git.
Tecnologias Utilizadas
Linguagem C
GCC (GNU Compiler Collection)
Git
GitHub
Visual Studio Code
Compilação

Para compilar o projeto execute:

gcc main.c jogo.c -o jogo
Execução

Depois da compilação execute:

./jogo
Desenvolvimento

O projeto foi desenvolvido por sessões de trabalho, permitindo acompanhar a evolução do código através dos commits realizados no GitHub. Em cada sessão foram implementadas novas funcionalidades e atualizado o ficheiro LOG.md, conforme solicitado no enunciado do projeto.

Melhorias Futuras

Entre as funcionalidades previstas para versões futuras encontram-se:

Sistema de vidas;
Armadilhas;
Melhorias na pontuação;
Recursão aplicada ao jogo;
Reinício automático do jogo;
Melhorias na interface do utilizador.
Autor

Nome: Kathleen

Projeto desenvolvido para a unidade curricular de Programação em C.
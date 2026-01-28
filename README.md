# 📚 Sistema de Gerenciamento de Biblioteca em C

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Status](https://img.shields.io/badge/Status-Concluído-success?style=for-the-badge)

Este é um projeto desenvolvido em **Linguagem C** focado na gestão automatizada de uma biblioteca. O objetivo principal foi aplicar conceitos fundamentais de lógica de programação, manipulação de arquivos e estruturação de dados.

O sistema permite o controle completo do acervo, usuários e fluxo de empréstimos, substituindo processos manuais por persistência de dados em arquivos de texto.

---

## 🚀 Funcionalidades

O sistema gerencia o ciclo de vida completo de uma biblioteca:

* **Cadastro de Livros:** Registro detalhado com Título, Autor, Código e Quantidade Disponível.
* **Gestão de Usuários:** Cadastro de leitores com ID único.
* **Controle de Empréstimos:** Vincula um livro a um usuário, decrementando o estoque automaticamente.
* **Sistema de Devolução:** Restaura o estoque e atualiza o status do empréstimo.
* **Persistência de Dados:** Todos os registros são salvos automaticamente em arquivos `.txt` ou binários, garantindo que nada se perca ao fechar o programa.
* **Busca e Listagem:** Relatórios rápidos de livros disponíveis e usuários cadastrados.

---

## 🛠️ Tecnologias e Conceitos Aplicados

Este projeto serviu para consolidar conhecimentos técnicos essenciais:

- **Structs:** Para modelagem de entidades complexas (Livro, Usuário, Empréstimo).
- **Manipulação de Arquivos (FILE*):** Leitura e escrita de dados para persistência.
- **Alocação de Memória:** Gestão eficiente de recursos.
- **Ponteiros:** Manipulação direta de endereços de memória para otimização.

---

## 💻 Como Compilar e Executar

Para rodar este projeto, você precisará de um compilador C (como o `GCC`).

### 1. Clone o repositório
Abra o terminal e digite:
```bash
git clone https://github.com/gdruzian/biblioteca-C.git
2. Entre na pasta do projeto
Bash
cd Biblioteca-C
3. Compile o código
Este comando gera o executável do sistema:

Bash
gcc main.c -o biblioteca
4. Execute o programa
No Windows:

Bash
./biblioteca.exe
No Linux/Mac:

Bash
./biblioteca

📂 Estrutura dos Arquivos
A organização do projeto segue a seguinte lógica:

main.c: Código fonte principal com a lógica do sistema e menus.

biblioteca.h: (Opcional) Cabeçalhos e definições de structs.

livros.txt: Banco de dados dos livros (gerado automaticamente).

usuarios.txt: Banco de dados dos usuários.

emprestimos.txt: Histórico de movimentações.

👨‍💻 Autor
Gustavo Druzian

Estudante de Engenharia de Software focado em desenvolvimento Backend C#/.NET e Segurança da Informação.

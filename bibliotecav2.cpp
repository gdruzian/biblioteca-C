#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Livro {
	int codigo;
	char titulo[100];
	char autor[100];
	int total;
	int disponivel;
};

struct Usuario {
	int codigo;
	char nome[100];
	int idade;
};

struct Emprestimo {
	int codigo_usuario;
	int codigo_livro;
};

#define maxemprestimos 100

struct Emprestimo prateleira_emprestimo[maxemprestimos];
int totemprestimos = 0;

#define maxlivros 100

struct Livro prateleira[maxlivros];
int totlivroscadastrados = 0;

#define maxusuarios 50

struct Usuario prateleira_usuarios[maxusuarios];
int totusuarios = 0;

void salvarDados() {
    FILE *f;

    f = fopen("livros.txt", "w");
    for (int i = 0; i < totlivroscadastrados; i++) {
    	fprintf(f, "%d;%s;%s;%d;%d\n",
        prateleira[i].codigo,
    	prateleira[i].titulo,
    	prateleira[i].autor,
        prateleira[i].total,
        prateleira[i].disponivel);
    }
    fclose(f);

    f = fopen("usuarios.txt", "w");
    for (int i = 0; i < totusuarios; i++) {
		fprintf(f, "%d;%s;%d\n",
        prateleira_usuarios[i].codigo,
        prateleira_usuarios[i].nome,
        prateleira_usuarios[i].idade);
    }
	fclose(f);

	f = fopen("emprestimos.txt", "w");
	for (int i = 0; i < totemprestimos; i++) {
		fprintf(f, "%d;%d\n",
    	prateleira_emprestimo[i].codigo_usuario,
		prateleira_emprestimo[i].codigo_livro);
    }
    fclose(f);
}

void carregarDados() {
    FILE *f;

    f = fopen("livros.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%d;%100[^;];%100[^;];%d;%d\n",
			&prateleira[totlivroscadastrados].codigo,
        	prateleira[totlivroscadastrados].titulo,
            prateleira[totlivroscadastrados].autor,
        	&prateleira[totlivroscadastrados].total,
            &prateleira[totlivroscadastrados].disponivel) != EOF) {
            totlivroscadastrados++;
        }
        fclose(f);
    }

    f = fopen("usuarios.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%d;%100[^;];%d\n",
            &prateleira_usuarios[totusuarios].codigo,
        	prateleira_usuarios[totusuarios].nome,
			&prateleira_usuarios[totusuarios].idade) != EOF) {
            totusuarios++;
        }
        fclose(f);
    }

	f = fopen("emprestimos.txt", "r");
	if (f != NULL) {
		while (fscanf(f, "%d;%d\n",
			&prateleira_emprestimo[totemprestimos].codigo_usuario,
			&prateleira_emprestimo[totemprestimos].codigo_livro) != EOF) {
			totemprestimos++;
        }
        fclose(f);
    }
}

void listar_emprestimos() {
	printf("\n--- Exibindo Todos os Emprestimos (%d) ---\n", totemprestimos);

	if(totemprestimos == 0) {
		printf("Nenhum emprestimo feito ainda!\n");
		return;
	}
	
	for(int i = 0; i < totemprestimos; i++) {
		printf("--- Exibindo emprestimo %d ---\n", i);
		printf("Usuario (Código): %d\n", prateleira_emprestimo[i].codigo_usuario);
		printf("Livro (Código): %d\n", prateleira_emprestimo[i].codigo_livro);
		printf("---------------------------\n");
	}
}

void emprestimo_livro() {
	int codUsuario, codLivro;

	printf("\n--- Realizar Emprestimo ---\n");
	printf("Digite o código do Usuario: ");
	scanf("%d", &codUsuario);
	printf("Digite o código do Livro: ");
	scanf("%d", &codLivro);
	
	int indice_livro = -1;
	
	for(int i = 0; i < totlivroscadastrados; i++){
		if(prateleira[i].codigo == codLivro) {
			indice_livro = i;
			break;
		}
	}
	
	if (indice_livro == -1) {
		printf("Erro: Livro com código %d não encontrado.\n", codLivro);
		return;
	}
	
	if (totemprestimos < maxemprestimos){
	
		if(prateleira[indice_livro].disponivel > 0) {
			prateleira[indice_livro].disponivel--;
			prateleira_emprestimo[totemprestimos].codigo_usuario = codUsuario;
			prateleira_emprestimo[totemprestimos].codigo_livro = codLivro;
			totemprestimos++;
			printf("Emprestimo do livro '%s' para o usuario %d realizado com sucesso!\n", prateleira[indice_livro].titulo, codUsuario);
		} else {
			printf("Erro: Livro '%s' indisponível no momento (sem cópias).\n", prateleira[indice_livro].titulo);
		}
	}
}

void cadastrarlivro() {
	if (totlivroscadastrados >= maxlivros) {
		printf("Erro: Prateleira de livros cheia!\n");
		return;
	}
	
	int prox_gavetalivre = totlivroscadastrados;
	
	printf("\n---Cadastro de Novo Livro (Gaveta %d) ---\n", prox_gavetalivre);
	
	printf("Digite o código: ");
	scanf("%d", &prateleira[prox_gavetalivre].codigo);
	
	getchar();
	
	printf("Digite o titulo: ");
	scanf(" %[^\n]", prateleira[prox_gavetalivre].titulo);

	getchar();
	
	printf("Digite o autor: ");
	scanf(" %[^\n]", prateleira[prox_gavetalivre].autor);
	
	printf("Digite a quantidade total: ");
	scanf("%d", &prateleira[prox_gavetalivre].total);
	
	prateleira[prox_gavetalivre].disponivel = prateleira[prox_gavetalivre].total;
	
	totlivroscadastrados++;
	
	printf("Livro cadastrado com sucesso! Total de livros agora: %d\n", totlivroscadastrados);
}

void cadastrarusuario() {
	if (totusuarios >= maxusuarios){
		printf("Erro! Maximo de usuarios atingidos!");
		return;
	}
	
	int prox_gavetalivre = totusuarios;
	
	printf("\n---Cadastro de Novo Usuario ---\n");
	
	printf("Digite o código: ");
	scanf("%d", &prateleira_usuarios[prox_gavetalivre].codigo);
	
	getchar();
	
	printf("Digite o Nome: ");
	scanf(" %[^\n]", prateleira_usuarios[prox_gavetalivre].nome);

	getchar();
	
	printf("Digite a idade do usuario: ");
	scanf("%d", &prateleira_usuarios[prox_gavetalivre].idade);
		
	totusuarios++;
	
	printf("Usuario cadastrado com sucesso! Total de Usuarios no momento: %d", totusuarios);
}

void exibir_tdslivros() {
	printf("\n--- Exibindo Todos os Livros Cadastrados (%d) ---\n", totlivroscadastrados);

	if(totlivroscadastrados == 0) {
		printf("Nenhum livro cadastrado ainda!\n");
		return;
	}
	
	for(int i = 0; i < totlivroscadastrados; i++) {
		printf("--- Livro na Gaveta %d ---\n", i);
		printf("Codigo: %d\n", prateleira[i].codigo);
		printf("Titulo: %s\n", prateleira[i].titulo);
		printf("Autor: %s\n", prateleira[i].autor);
		printf("Total: %d | Disponivel: %d\n", prateleira[i].total, prateleira[i].disponivel);
		printf("---------------------------\n");
	}
}

void exibir_tdsusuarios() {
	printf("\n--- Exibindo Todos os Usuarios Cadastrados (%d) ---\n", totusuarios);

	if(totusuarios == 0) {
		printf("Nenhum usuario cadastrado ainda!\n");
		return;
	}
	
	for(int i = 0; i < totusuarios; i++) {
		printf("--- Exibindo Usuario %d ---\n", i);
		printf("Nome: %s\n", prateleira_usuarios[i].nome);
		printf("Código: %d\n", prateleira_usuarios[i].codigo);
		printf("Idade: %d\n", prateleira_usuarios[i].idade);
		printf("---------------------------\n");
	}
}

int main() {
	setlocale(LC_ALL, "");
	
	carregarDados();
	
	int opcao;
	
	do{
		printf("\n\n===== BIBLIOTECA - GESTAO DE LIVROS =====\n");
		printf("1. Cadastrar novo livro\n");
		printf("2. Listar todos os livros\n");
		printf("3. Cadastrar novo usuario\n");
		printf("4. Listar todos os usuarios\n");
		printf("5. Realizar Emprestimo\n");
		printf("6. Listar Emprestimos\n");
		printf("0. Sair do programa\n");
		printf("============================================\n");
		printf("Escolha sua opção: ");
		scanf("%d", &opcao);
	
		switch (opcao) {
			case 1:
				cadastrarlivro();
				salvarDados();
				break;
			case 2:
				exibir_tdslivros();
				break;
			case 3:
				cadastrarusuario();
				salvarDados();
				break;
			case 4:
				exibir_tdsusuarios();
				break;
			case 5: 
				emprestimo_livro();
				salvarDados();
				break;
			case 6:
				listar_emprestimos();
				break;
			case 0:
				printf("Encerrando o programa!\n");
				break;
			default:
				printf("Opção inválida! Tente novamente.\n");
				break;
			}
		}while (opcao != 0);
	return 0;
}

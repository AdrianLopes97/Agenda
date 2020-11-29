//Adrian Juvenal Luz Lopes - Laboratório de Programação -  ULBRA CANOAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct stNo {
 	int info;
 	char nome[50];
	int idade;
	char sexo;
	char endereco[100];
	char cidade[40];
	char email[60];
	char celular[12];
 	struct stNo *prox;
};

struct stNo *cria_no() {
	struct stNo *p;
 	if ((p = (struct stNo *) malloc(sizeof(struct stNo))) == NULL)
 		return NULL;
 	else {
 		p->prox = NULL;
 		return p;
 	}
}
/**
* @param list
*/
void insereListaInicio(struct stNo **list){
	struct stNo *p,*q;
	int n = 0;
	
	srand(time(NULL));
	
	if(*list==NULL){ //lista vazia
 		p = cria_no();
 		*list = p;
 		p->prox = NULL;
 		n = rand() % 1000;
 		p->info = n;
 		
		do{
			fflush(stdin);
			printf("\nDigite o nome: ");
	 		gets(p->nome);
	 		strupr(p->nome);
	 		if(strlen(p->nome) == 0)
				printf("\nNOME INVÁLIDO DIGITE NOVAMENTE\n"); 		
 		}while(strlen(p->nome) == 0);
 		
 		printf("\nDigite sua idade: ");
 		fflush(stdin);
 		scanf("%i",&p->idade);
 		
 		do{
			printf("\nInforme seu sexo M/F: ");
			fflush(stdin);
			p->sexo = getche();
			p->sexo = toupper(p->sexo);
			if ((p->sexo != 'M') && (p->sexo != 'F'))
				printf("\nOpção inválida DIGITE NOVAMENTE");						
		}while ((p->sexo != 'M') && (p->sexo != 'F'));
		
		printf("\n\nInforme seu endereço: ");
		fflush(stdin);
		gets(p->endereco);
		strupr(p->endereco);

		printf("\nInforme sua cidade: ");
		fflush(stdin);
		gets(p->cidade);
		strupr(p->cidade);
		
		printf("\nInforme seu nº celular: ");
		fflush(stdin);
		gets(p->celular);
		
		printf("\nInforme seu E-mail: ");
		fflush(stdin);
		gets(p->email);
		strupr(p->email);		
 	}
 	else{
 		p=*list;
		q=cria_no();
		q->prox = p;
		n = rand() % 1000;
		q->info = n;
		*list = q;
		
		do{
			fflush(stdin);
			printf("\nDigite o nome: ");
 			gets(q->nome);
 			strupr(q->nome);
 			if(strlen(q->nome) == 0)
				printf("\nNOME INVÁLIDO DIGITE NOVAMENTE\n"); 		
 		}while(strlen(q->nome) == 0);
	 		
 		printf("\nDigite sua idade: ");
 		fflush(stdin);
 		scanf("%i",&q->idade);
	 		
 		do{
			printf("\nInforme seu sexo M/F: ");
			fflush(stdin);
			q->sexo = getche();
			q->sexo = toupper(q->sexo);
			if ((q->sexo != 'M') && (q->sexo != 'F'))
			printf("\nOpção inválida DIGITE NOVAMENTE");						
		}while ((q->sexo != 'M') && (q->sexo != 'F'));
			
		printf("\n\nInforme seu endereço: ");
		fflush(stdin);
		gets(q->endereco);
		strupr(q->endereco);
	
		printf("\nInforme sua cidade: ");
		fflush(stdin);
		gets(q->cidade);
		strupr(q->cidade);
			
		printf("\nInforme seu nº celular: ");
		fflush(stdin);
		gets(q->celular);
			
		printf("\nInforme seu E-mail: ");
		fflush(stdin);
		gets(q->email);
		strupr(q->email);
	};
}
void insereListaMeio(struct stNo **list){
	struct stNo *p,*q,*z;
	int n = 0,i = 0;
	char pesquisa[60];
	
	srand(time(NULL));
	
 	if(*list==NULL){ //lista vazia
 		p = cria_no();
 		*list = p;
 		p->prox = NULL;
 		n = rand() % 1000;
 		p->info = n;
 		
		do{
			fflush(stdin);
			printf("\nDigite o nome: ");
	 		gets(p->nome);
	 		strupr(p->nome);
	 		if(strlen(p->nome) == 0)
				printf("\nNOME INVÁLIDO DIGITE NOVAMENTE\n"); 		
 		}while(strlen(p->nome) == 0);
 		
 		printf("\nDigite sua idade: ");
 		fflush(stdin);
 		scanf("%i",&p->idade);
 		
 		do{
			printf("\nInforme seu sexo M/F: ");
			fflush(stdin);
			p->sexo = getche();
			p->sexo = toupper(p->sexo);
			if ((p->sexo != 'M') && (p->sexo != 'F'))
				printf("\nOpção inválida DIGITE NOVAMENTE");						
		}while ((p->sexo != 'M') && (p->sexo != 'F'));
		
		printf("\n\nInforme seu endereço: ");
		fflush(stdin);
		gets(p->endereco);
		strupr(p->endereco);

		printf("\nInforme sua cidade: ");
		fflush(stdin);
		gets(p->cidade);
		strupr(p->cidade);
		
		printf("\nInforme seu nº celular: ");
		fflush(stdin);
		gets(p->celular);
		
		printf("\nInforme seu E-mail: ");
		fflush(stdin);
		gets(p->email);
		strupr(p->email);		
 	}
 	else{
 		p=*list;
 		i = rand() % 1000;
 		printf("\nNesse menu você irá passar um nome como referência,\no novo cadastro vai ficar a frente do usado como referência");
 		printf("\nDigite o nome do cadastro REFERÊNCIA --> ");
 		fflush(stdin);
		gets(pesquisa);
		strupr(pesquisa);
		for(p = *list; p != NULL;p = p->prox){
			if(strcmp(pesquisa,p->nome) == 0){
				n = p->info;
			}
		}
		p = *list;
		while(p->prox!=NULL&&p->info!=n){
			p=p->prox;
		}
		if(p->info==n&&p->prox!=NULL){
			q = cria_no();
			z = p->prox;
			q->info = i;
			p->prox = q;
			q->prox = z;
			
					do{
			fflush(stdin);
			printf("\nDigite o nome: ");
	 		gets(q->nome);
	 		strupr(q->nome);
	 		if(strlen(q->nome) == 0)
					printf("\nNOME INVÁLIDO DIGITE NOVAMENTE\n"); 		
	 		}while(strlen(q->nome) == 0);
	 		
	 		printf("\nDigite sua idade: ");
	 		fflush(stdin);
	 		scanf("%i",&q->idade);
	 		
	 		do{
				printf("\nInforme seu sexo M/F: ");
				fflush(stdin);
				q->sexo = getche();
				q->sexo = toupper(q->sexo);
				if ((q->sexo != 'M') && (q->sexo != 'F'))
					printf("\nOpção inválida DIGITE NOVAMENTE");						
			}while ((q->sexo != 'M') && (q->sexo != 'F'));
			
			printf("\n\nInforme seu endereço: ");
			fflush(stdin);
			gets(q->endereco);
			strupr(q->endereco);
	
			printf("\nInforme sua cidade: ");
			fflush(stdin);
			gets(q->cidade);
			strupr(q->cidade);
			
			printf("\nInforme seu nº celular: ");
			fflush(stdin);
			gets(q->celular);
			
			printf("\nInforme seu E-mail: ");
			fflush(stdin);
			gets(q->email);
			strupr(q->email);
		}else if(p->info==n&&p->prox==NULL){
		q = cria_no();
		p->prox = q;
		q->prox = NULL;
		q->info = i;
 			
		do{
			fflush(stdin);
			printf("\nDigite o nome: ");
 			gets(q->nome);
 			strupr(q->nome);
 			if(strlen(q->nome) == 0)
				printf("\nNOME INVÁLIDO DIGITE NOVAMENTE\n"); 		
 		}while(strlen(q->nome) == 0);
	 		
 		printf("\nDigite sua idade: ");
 		fflush(stdin);
 		scanf("%i",&q->idade);
	 		
 		do{
			printf("\nInforme seu sexo M/F: ");
			fflush(stdin);
			q->sexo = getche();
			q->sexo = toupper(q->sexo);
			if ((q->sexo != 'M') && (q->sexo != 'F'))
			printf("\nOpção inválida DIGITE NOVAMENTE");						
		}while ((q->sexo != 'M') && (q->sexo != 'F'));
			
		printf("\n\nInforme seu endereço: ");
		fflush(stdin);
		gets(q->endereco);
		strupr(q->endereco);
	
		printf("\nInforme sua cidade: ");
		fflush(stdin);
		gets(q->cidade);
		strupr(q->cidade);
			
		printf("\nInforme seu nº celular: ");
		fflush(stdin);
		gets(q->celular);
			
		printf("\nInforme seu E-mail: ");
		fflush(stdin);
		gets(q->email);
		strupr(q->email);
		}
	 }
}
void insereListaFim(struct stNo **list){
	struct stNo *p,*q;
	int n = 0;

	srand(time(NULL));
	
 	if(*list==NULL){ //lista vazia
 		p = cria_no();
 		*list = p;
 		p->prox = NULL;
 		n = rand() % 1000;
 		p->info = n;
 		
		do{
			fflush(stdin);
			printf("\nDigite o nome: ");
	 		gets(p->nome);
	 		strupr(p->nome);
	 		if(strlen(p->nome) == 0)
				printf("\nNOME INVÁLIDO DIGITE NOVAMENTE\n"); 		
 		}while(strlen(p->nome) == 0);
 		
 		printf("\nDigite sua idade: ");
 		fflush(stdin);
 		scanf("%i",&p->idade);
 		
 		do{
			printf("\nInforme seu sexo M/F: ");
			fflush(stdin);
			p->sexo = getche();
			p->sexo = toupper(p->sexo);
			if ((p->sexo != 'M') && (p->sexo != 'F'))
				printf("\nOpção inválida DIGITE NOVAMENTE");						
		}while ((p->sexo != 'M') && (p->sexo != 'F'));
		
		printf("\n\nInforme seu endereço: ");
		fflush(stdin);
		gets(p->endereco);
		strupr(p->endereco);

		printf("\nInforme sua cidade: ");
		fflush(stdin);
		gets(p->cidade);
		strupr(p->cidade);
		
		printf("\nInforme seu nº celular: ");
		fflush(stdin);
		gets(p->celular);
		
		printf("\nInforme seu E-mail: ");
		fflush(stdin);
		gets(p->email);
		strupr(p->email);		
 	}
 	else{
 		n = rand() % 1000;
 		p=*list;
 		while(p->prox!=NULL)
 			p=p->prox;// posiciona no final da lista
		q = cria_no();
		p->prox = q;
		q->prox = NULL;
		q->info = n;
 			
		do{
			fflush(stdin);
			printf("\nDigite o nome: ");
 			gets(q->nome);
 			strupr(q->nome);
 			if(strlen(q->nome) == 0)
				printf("\nNOME INVÁLIDO DIGITE NOVAMENTE\n"); 		
 		}while(strlen(q->nome) == 0);
	 		
 		printf("\nDigite sua idade: ");
 		fflush(stdin);
 		scanf("%i",&q->idade);
	 		
 		do{
			printf("\nInforme seu sexo M/F: ");
			fflush(stdin);
			q->sexo = getche();
			q->sexo = toupper(q->sexo);
			if ((q->sexo != 'M') && (q->sexo != 'F'))
			printf("\nOpção inválida DIGITE NOVAMENTE");						
		}while ((q->sexo != 'M') && (q->sexo != 'F'));
			
		printf("\n\nInforme seu endereço: ");
		fflush(stdin);
		gets(q->endereco);
		strupr(q->endereco);
	
		printf("\nInforme sua cidade: ");
		fflush(stdin);
		gets(q->cidade);
		strupr(q->cidade);
			
		printf("\nInforme seu nº celular: ");
		fflush(stdin);
		gets(q->celular);
			
		printf("\nInforme seu E-mail: ");
		fflush(stdin);
		gets(q->email);
		strupr(q->email);
	 			
 		};
};
 
void mostraLista(struct stNo **list){
 	struct stNo *p;
 	if(*list!=NULL){
 		p=*list;
 		while(p->prox!=NULL){
 			printf(" %s %d->",p->nome,p->info);
 			p = p->prox;
 		};
 		printf(" %s %d->",p->nome,p->info);
 	}
 	else printf("\nLista Vazia");
};

void visualizarLista(struct stNo **list){
 	struct stNo *p;
 	char pesquisa[60];

 	if(*list!=NULL){
 		p=*list;
 		printf("\nDigite o nome: ");
 		fflush(stdin);
		gets(pesquisa);
		strupr(pesquisa);
 		for(p = *list; p != NULL;p = p->prox){
 			if(strcmp(pesquisa,p->nome) == 0){
 				printf("\nCódigo: %d",p->info);
				printf("\nNome: %s",p->nome);
				printf("\nIdade: %i",p->idade);
				printf("\nSexo: %c",p->sexo);
				printf("\nEndereço: %s",p->endereco);
				printf("\nCidade: %s",p->cidade);
				printf("\nNº Celular: %s",p->celular);
				printf("\nE-mail: %s\n\n",p->email);
				break;
			}
		}
 	}
 	else printf("\nLista Vazia");
};
void ExluirLista(struct stNo **list){
 	struct stNo *p,*q;
 	int n;
 	char pesquisa[60];
	
	if(*list != NULL){
		p=*list;
 		printf("\nDigite o nome: ");
 		fflush(stdin);
		gets(pesquisa);
		strupr(pesquisa);
		for(p = *list; p != NULL;p = p->prox){
			if(strcmp(pesquisa,p->nome) == 0){
				n = p->info;
			}
		}
		p = *list;
		if(p->info == n){
			if(p->prox != NULL){
				q = p->prox;
				free(p);
				*list = q;
			}else{
				free(p);
				*list = NULL;
			}	
		}else{
			while(p->prox != NULL && p->info != n){
				q = p;
				p = p->prox;
			};
			if(p->prox != NULL){
				q->prox = p->prox;
				free(p);
			}else{
				q->prox = NULL;
				free(p);
			}	
		}					
	}else printf("\nLista Vazia");
}

main(){
	setlocale(LC_ALL,"Portuguese");
 	struct stNo *lista;
 	int menu;
	lista = NULL; // inicializando a lista vazia

	do{
		system("cls");
		printf("\n");
		mostraLista(&lista);
		printf("\n\n");
		printf("[1-Inserir Inicio]\n");
		printf("[2-Inserir Meio]\n");
		printf("[3-Inserir Fim]\n");
		printf("[4-Visualizar]\n");
		printf("[5-Excluir]\n");
		printf("[6-Sair]\n\n");
		printf("Opção:");
		scanf("%i",&menu);
		switch(menu){
			case 1 :	insereListaInicio(&lista);
						break;
			case 2 :	insereListaMeio(&lista);
						break;
			case 3 :	insereListaFim(&lista);
						break;
			case 4 :	visualizarLista(&lista);
						break;
			case 5 : 	ExluirLista(&lista);
						break;
			case 6 :	printf("\nSaindo...\n\n");
						break;					
			default: 	printf("\nCódigo Inválido\n");
		}
		printf("\n");system("pause");
	}while(menu!=6);
}

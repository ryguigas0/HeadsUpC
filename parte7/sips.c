#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *question;
	struct node *yes;
	struct node *no;
} node;

int yes_no(char *question) /* pega uma string para a pergunta de sim ou não*/
{
	char answer[3]; /* sim ou não */
	printf("%s? (y/n)\n", question);
	fgets(answer, 3, stdin);
	return answer[0] == 'y'; /* retorna se a resposta foi sim */
}

node *create(char *question) /* Cria um nodo com uma pergunta */
{
	node *n = malloc(sizeof(node)); /* Aloca a memória */
	n->question = strdup(question); /* Duplica a string da pegunta e pego o endereço */
	n->yes, n->no = NULL;			/* Prepara os as ligações com os nodes de respostas de sim e não */
	return n;
}

void release(node *n) /* Libera da memória um node*/
{
	if (n) /* Se não for NULL */
	{
		if (n->no)			   /* Se tiver um node de não */
			release(n->no);	   /* Libera ele */
		if (n->yes)			   /* Se tiver um node de sim*/
			release(n->yes);   /* Libera ele */
		if (n->question)	   /* Se tiver a duplicata da pergunta */
			free(n->question); /* Libera o espaço da pergunta */
		free(n);			   /* Libera o espaço que esse node ocupa*/
	}
}

int main()
{
	/* Prepara as variáveis que vão mudar */
	char question[80];
	char suspect[20];
	node *current;

	node *start_node = create("Does suspect have a mustache?"); /* Cria a primeira pergunta */
	node *no_node = create("Loretta Barnsworth");				/* Caso não */
	start_node->no = no_node;									/* Liga na primeira pergunta */
	node *yes_node = create("Vinny the Spoon");					/* Caso sim */
	start_node->yes = yes_node;									/* Liga na primeira pergunta */

	do /* Primeiro loop */
	{
		current = start_node;		 /* Analise a primeira pergunta */
		while (1) /* Segundo loop */ /* Percorra a arvore de perguntas e respostas */
		{
			if (yes_no(current->question)) /* Pergunte a pergunta e retorne true ou false */
			{							   /* Se a for true */
				if (current->yes)		   /* E tiver um nodo para caso a reposta for sim */
				{
					current = current->yes; /* Analise ele */
				}
				else /* Se não */
				{
					printf("SUSPECT CONFIRMED\n"); /* Esse é o suspeito */
					break;						   /* Saia do segundo loop */
				}
			}
			else if (current->no) /* Se a pergunta retornar false e tiver um node de não */
			{
				current = current->no; /* analise ele */
			}
			else /* Se a pergunta retornar false e não tiver um node de não */
			{
				printf("Current name: %s", current->question);
				printf("Who's the suspect?\n");
				fgets(suspect, 20, stdin);		/* Pegue o nome do suspeito */
				current->yes = create(suspect); /* Coloque ele como a reposta de sim */

				current->no = create(current->question); /* Caso não for ele faça a pergunta que tinha antes */

				/* Crie uma pergunta que: true -> suspeito, false -> outro suspeito */
				printf("Give me a question that is TRUE for %s but not for %s\n",
					   suspect, current->question);
				fgets(question, 80, stdin);
				free(current->question);
				current->question = strdup(question); /* Duplique e aponte para a pergunta no node */
				break;								  /* Saia do segundo loop */
			}
		}
	} while (yes_no("Run again!")); /* Pergunte se é para rodar de novo, se não saia */
	release(start_node);			/* Libere a memória */
	return 0;						/* Encerre o programa */
}

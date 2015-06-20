#include <stdio.h>
#include <stdlib.h>

typedef struct SNo *TArvBin;

typedef struct SNo {
    int Item;
	int reps;
    TArvBin Esq, Dir;
} TNo;

int Insere(TArvBin *pNo, int x)
{ /** função recursiva de inserção em árvore, sem balanceamento **/
    if (*pNo == NULL) {
        *pNo = (TArvBin) malloc(sizeof(TNo));
        (*pNo)->Item = x;
        (*pNo)->reps = 1;
        (*pNo)->Esq = NULL;
        (*pNo)->Dir = NULL;
        return 1;
    }
    else if (x < (*pNo)->Item)
    {
        return Insere(&(*pNo)->Esq, x); // caso insira à esquerda, efetivamente,
    }
    else if (x > (*pNo)->Item)
    {
        return Insere(&(*pNo)->Dir, x); // caso insira à direita, efetivamente,
    }
    else {
        (*pNo)->reps ++;
        return 0; // retorna 0 caso o item ja estiver na arvore
    }
}

void Carrega(TArvBin *No)
{
    int n, i, x;
	scanf("%d", &n);
    for (i = 0; i < n ; i++) {
		scanf("%d", &x);
		Insere(No, x);
	}
}

void Imprime(TArvBin No)
{
	if (No != NULL) {
	    Imprime(No->Esq);
		printf("%d aparece %d vez(es)\n", No->Item, No->reps);
		Imprime(No->Dir);
	}
}

void Libera(TArvBin *pNo)
{
	TArvBin No;

	No = *pNo;
	if (No != NULL) {
		Libera(&No->Esq);
		Libera(&No->Dir);
		free(No);
		(*pNo) = NULL;
	}
}

int main()
{
    TArvBin Raiz;
    int x;
    Raiz = NULL;
    Carrega(&Raiz);

	Imprime(Raiz);
    Libera(&Raiz);

	return 0;
}

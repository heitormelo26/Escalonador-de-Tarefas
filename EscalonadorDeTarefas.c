#include<stdio.h>
#include<malloc.h>
#define QtdProcessos 10 // QUANTOS PROCESSOS SERÃO CRIADOS 

struct process{
	int id;
	int filaAnterior;
	int estado;// 0=pront0;1=exec;2=i/o
	int tempo; // tempo para executar
	int filaAnteriorIO;
	struct process *prox;
};

typedef struct process process;

int processID=0;
int contTempo=0;
int contIO=0;
int contFila=0;
int contEscolha=0;
int qtdExec=0;


struct tabela{
 	struct tabela *t;
 	process *process;
 	int m; // tamnaho 
};

typedef struct tabela tabela;

tabela* criaTabela(tabela *T, int x){ // CRIA O VETOR DE LISTAS

	T = (tabela*)malloc(sizeof(tabela));
	
	T->m=x;	
	T->t = (tabela*)malloc(sizeof(tabela)*x);
	
	int i=0;
	for(i;i<x;i++){
		T->t[i].process=(process*)malloc(sizeof(process));
		T->t[i].process->prox=NULL;
	}
	
	if(T != NULL && T->t != NULL)	return T;
	
}
// Heitor Melo
int* gera_aleatorios(int tam){ // GERA UM VETOR DE NÚMEROS ALEATÓRIOS,para evitar que o rand sempre gere os mesmos números em requisoções diferentes
	srand(time(NULL));	
	int *aleatorios = malloc(sizeof(int)*QtdProcessos);
	int i=0;
	 for(i;i<QtdProcessos;i++){
	 	aleatorios[i] = (int)rand()%tam;
	 }
	 return aleatorios;
}

process* criaFila(process* F){
	F = (process*)malloc(sizeof(process));
	F->prox = NULL;
	return F;	
}

void insereprocessFinal(process *L,process *x){
	
	if(L == NULL){
		printf("process = NULL\n");
		return;	
	}
	
	process *p=L->prox;
	
	if(p==NULL){
	    L->prox=x;
	    L->prox->prox=NULL;
	}else{
    	while(p->prox!=NULL){
    		p=p->prox;
    	}
    p->prox=x;
    x->prox=NULL;
	}
}
// Heitor Melo
void transferirParaExec(process *p,tabela *T,tabela *T2){ // IO->EXEC
	int pos=p->filaAnterior;
	int dispositivo=p->filaAnteriorIO;
	process *aux=p;
	T2->t[dispositivo].process->prox=aux->prox;
	aux->estado=1;
	insereprocessFinal(T->t[pos].process,aux);
}

void promoverProcess(tabela *T){
	int i=1;
	process *aux;
	for(i;i<16;i++){
		if(T->t[i].process->prox!=NULL){
		aux=T->t[i].process->prox;
		T->t[i].process->prox=aux->prox;
		insereprocessFinal(T->t[i-1].process,aux);
		}
	}
}

void criaProcesso(process* F,int *niveisPrioridade){
	process *P = malloc(sizeof(process));
	P->id = processID;
	P->estado=0;
	int x=niveisPrioridade[contFila];
	contFila++;
	P->filaAnterior=x;
	P->filaAnteriorIO= -1;
	P->tempo= rand() %5; // sorteia o tempo de execução
	if(P->tempo==0) P->tempo=1;
	processID++;
	insereprocessFinal(F,P); 
}

void insereTabela(tabela *T,process *filaPronto){	 
	if(T == NULL){
		printf("Tabela = NULL\n");
		return;	
	}
	process* aux=filaPronto->prox;
	filaPronto->prox=aux->prox;	
	aux->estado=1;
	insereprocessFinal(T->t[aux->filaAnterior].process,aux);	
}
// Heitor Melo
void imprimeFila(process *T, int x){
	if(x==0){
		if(T->prox==NULL){
			printf("NULL");
			return;	
		}
		int i=0;
		process *p=T->prox;
		while(p!=NULL){
			printf(" %d || %d || %d",p->id,p->filaAnterior,p->tempo);
			p=p->prox;
			if (p!=NULL) printf("\n");
		}
	}else{
		if(T->prox==NULL){
			printf("NULL");
			return;	
		}
		int i=0;
		process *p=T->prox;
		while(p!=NULL){
			printf("%d ",p->id,p->filaAnterior);
			p=p->prox;
			if (p!=NULL) printf("-> ");
		}
	}
}

void imprimeTabela(tabela *T){
	if(T==NULL){
		printf("Tabela = NULL");
		return;	
	}
	
	int i=0;
	
	
	for(i;i<T->m;i++){
	printf("%d: ",i);
	imprimeFila(T->t[i].process,1);
	printf("\n");	
	}
	
}
// Heitor Melo
void execucao(tabela* T,tabela* T2,int n,int *escolhas,int *dispositivos){
	int escolha=0;
	int flag=0;
	int nivel=0;
	while(n>0){
		nivel=0;
		if(qtdExec==5){
			printf("PROMOVER PROCESSOS...");
		 	promoverProcess(T); 
		 	nivel--;
		 	qtdExec=0;
		}else{// PROMOVER DPS DE UM CERTO NUMERO DE EXECUÇÕES
		while(T->t[nivel].process->prox==NULL)
		{
		 nivel++;
			 if(nivel>15) {
			 	flag =1;
			 	break;
			 }
		 }
		 if(flag) break;
		T->t[nivel].process->prox->tempo--;
		printf("Processo executado: %d\n",T->t[nivel].process->prox->id);
		int x = rand()%2; // 0-> programa continua no escalonador e 1-> programa vai para IO
		printf("Escolha =  %d\n", x);
		if(T->t[nivel].process->prox->tempo==0){
			printf("Processo terminado, sai da fila \n");
			process *aux = T->t[nivel].process->prox;
			T->t[nivel].process->prox = aux->prox;
			free(aux);
		}else{
			if(x==0){
				printf("Continuou no escalonador(vai para o fina da fila)\n");
				process *aux = T->t[nivel].process->prox;
				T->t[nivel].process->prox = aux->prox;
				insereprocessFinal(T->t[aux->filaAnterior].process,aux);
			}
			if(x==1){
				process *aux = T->t[nivel].process->prox;
				T->t[nivel].process->prox = aux->prox;
				printf("Foi para IO\n");
				int y = dispositivos[contIO];
				aux->filaAnteriorIO = y;
				contIO++;
				printf("Dispositivo escolhido: %d\n",y);
				insereprocessFinal(T2->t[y].process,aux);
			}
		}
	}
		printf("\nESCALONADOR (POS EXECUCAO): \n");
		imprimeTabela(T);
	//	printf("\nTABELA IO(POS EXECUCUAO):\n");
	//	imprimeTabela(T2);
		qtdExec++;
		n--;
	}
}

void esvaziarIO(tabela *T,tabela *T2){
	int i=0;
	for(i;i<8;i++){
		while(T2->t[i].process->prox!=NULL){
			transferirParaExec(T2->t[i].process->prox,T,T2);
		}
	}
}
// Heitor Melo
int main(){
	
	int j=0;
	
	int *posTabela = gera_aleatorios(15);
	int *dispositivos = gera_aleatorios(7);
	int *escolhas = gera_aleatorios(2);// CRIAM UM VETOR DE NUMERO ALEATORIOS DE 0 ATE O VALOR DO PARANMETRO
	
	
	tabela *TabelaProcess = criaTabela(TabelaProcess,16);
	tabela *TabelaIO = criaTabela(TabelaProcess,8);
	process* filaPronto = criaFila(filaPronto);
	
	int i=0;
	
	for(i;i<QtdProcessos;i++){ // 100 processos serão criados
		criaProcesso(filaPronto,posTabela);
	}
	
	printf("Fila de Prontos: (PROCESS ID || PRIORIDADE || TEMPO ) \n");
	imprimeFila(filaPronto,0);
	printf("\n\nEsvaziando fila de prontos e carregando escalonador...\n");
	for(i=0;i<QtdProcessos;i++){ // carrega-se os 100 processos.
		insereTabela(TabelaProcess,filaPronto);
	}
	
	printf("\nTabela de Escalonamento(INICIAL): (NIVEL PRIORIDADE: PROCESS ID)\n");
	imprimeTabela(TabelaProcess);
	
	printf("\nComecar execucao dos processos...\n");
	
	printf("Quantos processos vao ser executados? ");
	int qtdProcessosExec;
	scanf("%d",&qtdProcessosExec);
	
	execucao(TabelaProcess,TabelaIO,qtdProcessosExec,escolhas,dispositivos);
	
	printf("\n APOS EXECUCAO \n");
	
	printf("\nTabela de Escalonamento: (NIVEL PRIORIDADE: PROCESS ID)\n");
	imprimeTabela(TabelaProcess);
	printf("\nTabela de IO: (DISPOSITIVO: PROCESS ID)\n");
	imprimeTabela(TabelaIO);
	
	printf("\nTERMINAR O I0:\n");
	
	esvaziarIO(TabelaProcess,TabelaIO);
	
	printf("Escalonador (FINAL) POS LIBERACAO DE IO:\n");
	imprimeTabela(TabelaProcess);
	printf("\nIO:\n");
	imprimeTabela(TabelaIO);	
	
}

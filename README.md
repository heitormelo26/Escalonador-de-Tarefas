# Escalonador-de-Tarefas
O sistema simula o processo de escalonador de Tarefa presente em um processador. <br/>
Esse escalonador escalona as tarefas baseado na prioridade desta e no tempo de execução que leva para finalizar tal processo <br/>
Um processo com x tempo de processo, após ser tratada pelo processador esse tempo descerá para x-1.<br/><br/>

<h1> Exemplo de execução para 10 processos criados.</h1>

Fila de Prontos: (PROCESS ID || PRIORIDADE || TEMPO )
 0 || 7 || 1
 1 || 3 || 2
 2 || 9 || 1
 3 || 4 || 4
 4 || 10 || 3
 5 || 7 || 4
 6 || 14 || 4
 7 || 7 || 4
 8 || 11 || 3
 9 || 3 || 2

Esvaziando fila de prontos e carregando escalonador...

Tabela de Escalonamento(INICIAL): (NIVEL PRIORIDADE: PROCESS ID)
0: NULL
1: NULL
2: NULL
3: 1 -> 9
4: 3
5: NULL
6: NULL
7: 0 -> 5 -> 7
8: NULL
9: 2
10: 4
11: 8
12: NULL
13: NULL
14: 6
15: NULL

Comecar execucao dos processos...
Quantos processos vao ser executados? 2
Processo executado: 1
Escolha =  0
Continuou no escalonador(vai para o fina da fila)

ESCALONADOR (POS EXECUCAO):
0: NULL
1: NULL
2: NULL
3: 9 -> 1
4: 3
5: NULL
6: NULL
7: 0 -> 5 -> 7
8: NULL
9: 2
10: 4
11: 8
12: NULL
13: NULL
14: 6
15: NULL
Processo executado: 9
Escolha =  0
Continuou no escalonador(vai para o fina da fila)

ESCALONADOR (POS EXECUCAO):
0: NULL
1: NULL
2: NULL
3: 1 -> 9
4: 3
5: NULL
6: NULL
7: 0 -> 5 -> 7
8: NULL
9: 2
10: 4
11: 8
12: NULL
13: NULL
14: 6
15: NULL

 APOS EXECUCAO

Tabela de Escalonamento: (NIVEL PRIORIDADE: PROCESS ID)
0: NULL
1: NULL
2: NULL
3: 1 -> 9
4: 3
5: NULL
6: NULL
7: 0 -> 5 -> 7
8: NULL
9: 2
10: 4
11: 8
12: NULL
13: NULL
14: 6
15: NULL

Tabela de IO: (DISPOSITIVO: PROCESS ID)
0: NULL
1: NULL
2: NULL
3: NULL
4: NULL
5: NULL
6: NULL
7: NULL

TERMINAR O I0:
Escalonador (FINAL) POS LIBERACAO DE IO:
0: NULL
1: NULL
2: NULL
3: 1 -> 9
4: 3
5: NULL
6: NULL
7: 0 -> 5 -> 7
8: NULL
9: 2
10: 4
11: 8
12: NULL
13: NULL
14: 6
15: NULL

IO:
0: NULL
1: NULL
2: NULL
3: NULL
4: NULL
5: NULL
6: NULL
7: NULL

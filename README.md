# Escalonador-de-Tarefas
O sistema simula o processo de escalonador de Tarefa presente em um processador. <br/>
Esse escalonador escalona as tarefas baseado na prioridade desta e no tempo de execução que leva para finalizar tal processo <br/>
Um processo com x tempo de processo, após ser tratada pelo processador esse tempo descerá para x-1.<br/><br/>

<h1> Exemplo de execução para 10 processos criados.</h1>
<br/>
Fila de Prontos: (PROCESS ID || PRIORIDADE || TEMPO )<br/>
 0 || 7 || 1<br/>
 1 || 3 || 2<br/>
 2 || 9 || 1<br/>
 3 || 4 || 4<br/>
 4 || 10 || 3<br/>
 5 || 7 || 4<br/>
 6 || 14 || 4<br/>
 7 || 7 || 4<br/>
 8 || 11 || 3<br/>
 9 || 3 || 2<br/>
<br/>
Esvaziando fila de prontos e carregando escalonador...<br/>
<br/>
Tabela de Escalonamento(INICIAL): (NIVEL PRIORIDADE: PROCESS ID)<br/>
0: NULL<br/>
1: NULL<br/>
2: NULL<br/>
3: 1 -> 9<br/>
4: 3<br/>
5: NULL<br/>
6: NULL<br/>
7: 0 -> 5 -> 7<br/>
8: NULL<br/>
9: 2<br/>
10: 4<br/>
11: 8<br/>
12: NULL<br/>
13: NULL<br/>
14: 6<br/>
15: NULL<br/>
<br/>
Comecar execucao dos processos...<br/>
Quantos processos vao ser executados? 2<br/>
Processo executado: 1<br/>
Escolha =  0<br/>
Continuou no escalonador(vai para o fina da fila)<br/>
<br/>
ESCALONADOR (POS EXECUCAO):<br/>
0: NULL<br/>
1: NULL<br/>
2: NULL<br/>
3: 9 -> 1<br/>
4: 3<br/>
5: NULL<br/>
6: NULL<br/>
7: 0 -> 5 -> 7<br/>
8: NULL<br/>
9: 2<br/>
10: 4<br/>
11: 8<br/>
12: NULL<br/>
13: NULL<br/>
14: 6<br/>
15: NULL<br/>
Processo executado: 9<br/>
Escolha =  0<br/>
Continuou no escalonador(vai para o fina da fila)<br/>
<br/>
ESCALONADOR (POS EXECUCAO):<br/>
0: NULL<br/>
1: NULL<br/>
2: NULL<br/>
3: 1 -> 9<br/>
4: 3<br/>
5: NULL<br/>
6: NULL<br/>
7: 0 -> 5 -> 7<br/>
8: NULL<br/>
9: 2<br/>
10: 4<br/>
11: 8<br/>
12: NULL<br/>
13: NULL<br/>
14: 6<br/>
15: NULL<br/>
<br/>
 APOS EXECUCAO<br/>
<br/>
Tabela de Escalonamento: (NIVEL PRIORIDADE: PROCESS ID)<br/>
0: NULL<br/>
1: NULL<br/>
2: NULL<br/>
3: 1 -> 9<br/>
4: 3<br/>
5: NULL<br/>
6: NULL<br/>
7: 0 -> 5 -> 7<br/>
8: NULL<br/>
9: 2<br/>
10: 4<br/>
11: 8<br/>
12: NULL<br/>
13: NULL<br/>
14: 6<br/>
15: NULL<br/>
<br/>
Tabela de IO: (DISPOSITIVO: PROCESS ID)<br/>
0: NULL<br/>
1: NULL<br/>
2: NULL<br/>
3: NULL<br/>
4: NULL<br/>
5: NULL<br/>
6: NULL<br/>
7: NULL<br/>
<br/>
TERMINAR O I0:<br/>
Escalonador (FINAL) POS LIBERACAO DE IO:<br/>
0: NULL<br/>
1: NULL<br/>
2: NULL<br/>
3: 1 -> 9<br/>
4: 3<br/>
5: NULL<br/>
6: NULL<br/>
7: 0 -> 5 -> 7<br/>
8: NULL<br/>
9: 2<br/>
10: 4<br/>
11: 8<br/>
12: NULL<br/>
13: NULL<br/>
14: 6<br/>
15: NULL<br/>
<br/>
IO:<br/>
0: NULL<br/>
1: NULL<br/>
2: NULL<br/>
3: NULL<br/>
4: NULL<br/>
5: NULL<br/>
6: NULL<br/>
7: NULL<br/>

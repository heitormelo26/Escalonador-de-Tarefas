# Escalonador-de-Tarefas
O sistema simula o processo de escalonador de Tarefa presente em um processador. <br/>
Esse escalonador escalona as tarefas baseado na prioridade desta e no tempo de execução que leva para finalizar tal processo <br/>
Um processo com x tempo de processo, após ser tratada pelo processador esse tempo descerá para x-1.<br/><br/>

<h1> Exemplo de execução para 10 processos criados.<h1/>

Fila de Prontos: (PROCESS ID || PRIORIDADE || TEMPO ) <br/>
 0 || 1 || 1 <br/>
 1 || 1 || 3 <br/>
 2 || 7 || 2 <br/>
 3 || 7 || 4 <br/>
 4 || 11 || 2<br/>
 5 || 12 || 1<br/>
 6 || 10 || 1<br/>
 7 || 0 || 1<br/>
 8 || 5 || 1<br/>
 9 || 13 || 1<br/>

Esvaziando fila de prontos e carregando escalonador...  <br/>

Tabela de Escalonamento(INICIAL): (NIVEL PRIORIDADE: PROCESS ID)<br/>
0: 7<br/>
1: 0 -> 1<br/>
2: NULL<br/>
3: NULL<br/>
4: NULL<br/>
5: 8<br/>
6: NULL<br/>
7: 2 -> 3<br/>
8: NULL<br/>
9: NULL<br/>
10: 6<br/>
11: 4<br/>
12: 5<br/>
13: 9<br/>
14: NULL<br/>
15: NULL <br/>

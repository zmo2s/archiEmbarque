# archiEmbarque

compilation : 
v1 gcc -Wall -o thread thread_v1.c; ./thread 5 <br />
v2 gcc -Wall -o thread thread_v2.c; ./thread 5 <br />
v3 gcc -Wall -o thread showAffinity.c -lpthread; ./thread ;  <br />
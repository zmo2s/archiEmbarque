# archiEmbarque

compilation : 
v1 gcc -Wall -o thread thread_v1.c; ./thread 5
v2 gcc -Wall -o thread thread_v2.c; ./thread 5
v3 gcc -Wall -o thread showAffinity.c -lpthread; ./thread ;
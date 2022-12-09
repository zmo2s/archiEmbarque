# archiEmbarque

compilation :  <br />

Pour Kali Linux : le faire en 2 temps (;) et ./thread 5

v1 gcc -Wall -o thread thread_v1.c; ./thread 5 <br />       
v2 gcc -Wall -o thread thread_v2.c; ./thread 5 <br />
v3 gcc -Wall -o thread show_affinity.c -lpthread; ./thread   <br />
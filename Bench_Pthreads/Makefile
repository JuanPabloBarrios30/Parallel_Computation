#*************************************************
#Fecha: 09-agosto-2022
#Autor: Juan Pablo Barrios Suarez
#Materia: Parallel and Distribuited Computing
#Tema: Construcción Benchmark Multiplicación de matrices
#Tòpico: Script Automatizacion Compilacion
#*************************************************/

GCC = gcc
FLAGS = -ansi -std=c11 -pedantic -Wall -Wno-unknown-pragmas -D_POSIX_C_SOURCE=199309L
MATHFLAG = -lm -lpthread -fopenmp

PROGRS = mm_main_double mm_main_double_rnd mm_main_clasica mm_main_filas

all: $(PROGRS) 

mm_main_double: 
	$(GCC) $(FLAGS) -c $@.c $(MATHFLAG)
	$(GCC) $(FLAGS) -c mm_lib.c $(MATHFLAG)
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)

mm_main_double_rnd: 
	$(GCC) $(FLAGS) -c $@.c $(MATHFLAG)
	$(GCC) $(FLAGS) -c mm_lib.c $(MATHFLAG)
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)

mm_main_clasica:
	$(GCC) $(FLAGS) -c $@.c $(MATHFLAG)
	$(GCC) $(FLAGS) -c mm_lib.c $(MATHFLAG)
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)

mm_main_filas:
	$(GCC) $(FLAGS) -c $@.c $(MATHFLAG)
	$(GCC) $(FLAGS) -c mm_lib.c $(MATHFLAG)
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)
	
clean: 
	$(RM) *.o $(PROGRS)
	
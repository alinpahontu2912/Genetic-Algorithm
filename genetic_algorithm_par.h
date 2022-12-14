#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include "sack_object.h"
#include "individual.h"
#include "my_struct.h"

// reads input from a given file
int read_input(sack_object **objects, int *object_count, int *sack_capacity, int *generations_count, int *P, int argc, char *argv[]);

//thread function
void *thread_function(void *arg);

// displays the individual with the best fitness in a generation
void print_best_fitness(const individual *generation);

// computes the fitness function for each individual in a generation
void compute_fitness_function(const sack_object *objects, individual *generation, int object_count, int sack_capacity, int thread_id, int P);
// compares two individuals by fitness and then number of objects in the sack (to be used with qsort)
int cmpfunc(const void *a, const void *b);

// performs a variant of bit string mutation
void mutate_bit_string_1(const individual *ind, int generation_index);

// performs a different variant of bit string mutation
void mutate_bit_string_2(const individual *ind, int generation_index);

// performs one-point crossover
void crossover(individual *parent1, individual *child1, int generation_index);

// copies one individual
void copy_individual(const individual *from, const individual *to);

// deallocates a generation
void free_generation(individual *generation, int thread_id, int P);

#endif

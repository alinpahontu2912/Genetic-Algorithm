#include <string.h>

#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

#include "genetic_algorithm_par.h"


int main(int argc, char * argv[]) {
    // array with all the objects that can be placed in the sack
    sack_object * objects = NULL;

    // number of objects
    int object_count = 0;

    // maximum weight that can be carried in the sack
    int sack_capacity = 0;

    // number of generations
    int generations_count = 0;

    // number of threads
    int P = 0;
    int i;

    if (!read_input( & objects, & object_count, & sack_capacity, & generations_count, & P, argc, argv)) {
        return 0;
    }

    // initialising barrier	
    pthread_barrier_t barrier;
    pthread_barrier_init( & barrier, NULL, P);
    pthread_t tid[P];

    // arguments struct
    my_struct args[P];
    individual * current_generation = (individual * ) calloc(object_count, sizeof(individual));
    individual * next_generation = (individual * ) calloc(object_count, sizeof(individual));
    individual * tmp = NULL;
    for (i = 0; i < P; i++) {
        args[i].objects = objects;
        args[i].object_count = object_count;
        args[i].generations_count = generations_count;
        args[i].sack_capacity = sack_capacity;
        args[i].thread_id = i;
        args[i].P = P;
        args[i].barrier = & barrier;
        args[i].current_generation = current_generation;
        args[i].next_generation = next_generation;
        args[i].tmp = tmp;
        pthread_create( & tid[i], NULL, thread_function, & args[i]);

    }

    for (i = 0; i < P; i++) {
        pthread_join(tid[i], NULL);
    }

    free(objects);

    pthread_barrier_destroy( & barrier);
    return 0;
}

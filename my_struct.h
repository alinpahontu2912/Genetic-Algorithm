#ifndef MY_STRUCT
#define MY_STRUCT

// struct storing the arguments for the thread function

typedef struct _my_struct {
	sack_object *objects;
	individual *current_generation;
	individual *next_generation;
	individual *tmp;
	int object_count;
	int generations_count;
	int sack_capacity;
	int thread_id;
	int P;
	pthread_barrier_t *barrier;
} my_struct;

#endif

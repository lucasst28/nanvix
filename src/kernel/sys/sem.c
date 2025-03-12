#include <nanvix/const.h>
#include <sys/sem.h>

/**
 * @brief Tableau de sémaphores.
 */
PUBLIC struct semaphore semaphores[NR_SEMS];


/**
 * @brief Initializes semaphores.
 */
PUBLIC void sem_init(void){

	disable_interrupts();

	for (int i = 0; i < NR_SEMS; i++)
	{
		semaphores[i].key = -1;
		semaphores[i].valid = 0;
		semaphores[i].value = 0;
		semaphores[i].waiting = NULL;
	}

	enable_interrupts();
}
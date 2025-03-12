#include <nanvix/const.h>
#include <nanvix/pm.h>
#include <sys/sem.h>

/**
 * @brief La fonction semop permet d’effectuer des opérations atomiques incrémentant
 * ou décrémentant la variable associée au sémaphore identifié par semid.
 * Une valeur négative pour op spécifie l’opération down() et une valeur
 * positive l’opération up().
 * @param semid Identificateur du sémaphore.
 * @param op Opération.
 */
PUBLIC int semop(int semid, int op){
    if (op == 0)
        return -1;
    if (!semaphores[semid].valid)
        return -1;
    
    disable_interrupts();

    if(op > 0){
        if(semaphores[semid].value == 0){
            if(semaphores[semid].waiting != NULL){
                wakeup(&semaphores[semid].waiting);
            }
        } else {
            semaphores[semid].value++;
        }
    } else {
        if(semaphores[semid].value > 0){
            semaphores[semid].value--;
        } else {
            sleep(&semaphores[semid].waiting, curr_proc->priority); 
        }
    }

    enable_interrupts();

    return 0;
}
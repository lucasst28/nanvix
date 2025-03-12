#include <nanvix/const.h>
#include <sys/sem.h>

/**
 * @brief La fonction semget permet à un processus d’utiliser un sémaphore associé
 * à une clé ( texttt key). Si aucun sémaphore n’est associé à key, un 
 * nouveau sémaphore doit être créé.
 * En cas de réussite, la fonction retournera l’identificateur du sémaphore
 * associé à la clé. En cas d’erreur, −1 doit être retourné.
 * @param key Clé du sémaphore.
*/
PUBLIC int semget(unsigned key){
    for(int i = 0; i < NR_SEMS; i++){
        if(semaphores[i].key == key){
            return i;
        }
    }
    for(int i = 0; i < NR_SEMS; i++){
        if(semaphores[i].valid == 0){
            semaphores[i].valid = 1;
            semaphores[i].value = 0;
            semaphores[i].waiting = NULL;
            return i;
        }
    }
    return -1;
}
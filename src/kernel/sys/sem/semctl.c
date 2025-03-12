#include <nanvix/const.h>
#include <sys/sem.h>

/** 
 * @brief Cette fonction permet une série d’opérations de contrôle sur le
 * sémaphore identifié par semid. Ces opérations sont spécifiées par cmd
 * et peuvent être :
    — GETVAL, renvoie la valeur actuelle du sémaphore ;
    — SETVAL, définit la valeur du sémaphore sur val ;
    — IPC RMID, supprime le sémaphore et le détruit s’il n’est plus
    utilisé.
 * La valeur de retour de la fonction dépend de cmd. Si c’est GETVAL, la
 * valeur actuelle du sémaphore est retournée. Dans tous les autres cas
 * d’achèvement réussi, 0 doit être retourné. En cas d’erreur, −1 doit être
 * retourné.
 * @param semid Identificateur du sémaphore.
 * @param cmd Commande de contrôle.
 * @param val Valeur.
*/

PUBLIC int semctl(int semid, int cmd, int val){
    switch (cmd)
    {
    case GETVAL:
        return semaphores[semid].value;
    case SETVAL:
        semaphores[semid].value = val;
        return 0;
    case IPC_RMID:
        if(semaphores[semid].waiting == NULL){
            semaphores[semid].valid = 0;
            return 0;
        } else {
            return -1;
        }
    default:
        return -1;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct nodo{
    char nome[10];
    char numero[10];
    struct nodo *pt;
};

//prototypes
void crearubrica(struct nodo **head);                                   
void visualize(struct nodo ** head);                                   
int finditem(struct nodo **head, char nome[], char numero[]);           
int removeitem(struct nodo **head, char nome[]);                       
void insertitem(struct nodo **head, char nome[], char numero[]);        
int updateitem(struct nodo **head, char nome[], char numero[]);        

//le int danno 0 se ok ,-1 altrimenti

int main(void){

    struct nodo *lista;
    crearubrica(&lista);



    insertitem(&lista,"Zippo","3234");
    insertitem(&lista,"Aippi","3234");
    insertitem(&lista,"Pippo","1234");
    insertitem(&lista,"Rippa","2234");
    insertitem(&lista,"Gippi","3234");
    insertitem(&lista,"Bippe","4234");
    
    visualize(&lista);

    //char num[10];
    //finditem(&lista, "Bippe", num);
    //printf("num is %s", num);

    /*printf("---------------\n");
    updateitem(&lista,"Rippa", "9999");
    visualize(&lista);
    
    printf("---------------\n");
    removeitem(&lista,"Aippi");
    visualize(&lista);*/

    return 0;

}


void crearubrica(struct nodo **head){
    *head = NULL;
}

    
void insertitem(struct nodo **head, char nome[], char numero[]){
    struct nodo *prec = NULL, *curr = (*head);
    int flag = -1;
    struct nodo *newnodo;
    //creazione nodo
    newnodo = (struct nodo*)malloc(sizeof(struct nodo));
    strcpy(newnodo->nome,nome);
    strcpy(newnodo->numero,numero);
    //scorrimento lista fino a posizione trovata (flag = 1)
    while(curr != NULL && flag == -1){
        if(strcmp(curr->nome, newnodo->nome) < 0 ){  //compara le stringhe : < 0 se curr->nome è "minore" di newnodo->nome
            prec = curr;
            curr = curr->pt;
        }else{
            flag = 0;
        }
    }
    if(prec == NULL){  //inserimento in testa
        newnodo->pt = *head;
        *head = newnodo;
    }else{             //inserimento non in testa
        prec->pt = newnodo;
        newnodo->pt = curr;
    }
}

 void visualize(struct nodo **head){
    struct nodo *tmp = (*head); //nodo per lo scorrimento
    while(tmp != NULL ){  //tmp NULL = dopo ultimo nodo
        printf("Nome = %s , Numero = %s\n", tmp->nome, tmp->numero);  //stampa
        tmp = tmp->pt;   //scorrimento lista
    }
 }


int removeitem(struct nodo **head, char nome[]){
    struct nodo *prec = NULL, *curr = (*head);
    int flag = -1;
    while(curr!=NULL && flag==-1){
        if(strcmp(curr->nome,nome)!=0){
            prec = curr;
            curr = curr->pt;
        }else{
            flag = 0;
        }
    }
    if(curr!=NULL){
        flag = 0;
        if(prec == NULL){  //rimozione in testa
            *head = curr->pt;
        }else{
            prec->pt = curr->pt;
        }
        free(curr);     //rimozione nodo dalla memoria
    }
    return flag;
}


int updateitem(struct nodo **head, char nome[], char numero[]){
    struct nodo *prec = NULL, *curr = (*head);
    int flag = -1;
    while(curr!=NULL && flag==-1){
        if(strcmp(curr->nome,nome)!=0){
            prec = curr;
            curr = curr->pt;
        }else{
            flag = 0;
            strcpy(curr->numero, numero);  //modifica numero
        }
    }
    return flag;
}


int finditem(struct nodo **head, char nome[], char numero[]){
    struct nodo *prec = NULL, *curr = (*head);
    int flag = -1;
    while(curr!=NULL && flag==-1){
        if(strcmp(curr->nome,nome)!=0){
            prec = curr;
            curr = curr->pt;
        }else{
            flag = 0;
        }
    }
    if(curr!=NULL){
        flag = 0;
        //strcpy(numero, curr->numero);
        printf("Number : %s", curr->numero);
    }
    return flag;
}




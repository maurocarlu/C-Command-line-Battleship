#ifndef OPERAZIONIDIGIOCO_H_
#define OPERAZIONIDIGIOCO_H_
#include "Strutture.h"

void IniziaPartita(char NomePartita[], char NomePlayer1[], char NomePlayer2[],BattleFieldPos TabPos1, BattleFieldPos TabellaPos2, BattleFieldAtt TabellaAtt1, BattleFieldAtt TabellaAtt2, Abilita Ab1, Abilita Ab2, int Turno);
//funzione utilizzata per far inserire i nomi ai giocatori, inizializzare le tabelle di entrambi ed iniziare una nuova partita

void Gioca (char NomePlayer1[], char NomePlayer2[],char NomePartita[],BattleFieldPos TabellaPos1, BattleFieldPos TabellaPos2, BattleFieldAtt TabellaAtt1, BattleFieldAtt TabellaAtt2, Abilita Ab1, Abilita Ab2, int Turno);
//funzione che permette di visualizzare le tabelle di gioco, le abilità rimanenti ed attaccare

int TraduzioneColonna(char Lettera);
//funzione che serve per convertire la lettera inserita dall'utente, che rappresenta la colonna, in un intero

char TraduzioneColonnaInversa(int Numero);
//funzione che serve per convertire il numero della colonna in lettera quando quest'ultima deve comparire a schermo per l'utente

int LeggereIntero();
//funzione d'appoggio utilizzata per leggere un valore inserito dall'utente che verrà utilizzato in varie funzioni

BattleFieldPos InserisciNavi(BattleFieldPos TabellaPos, char NomePlayer[]);
//funzione che serve ai giocatori per far inserire loro le navi nelle tabelle di posizionamento

#endif /* OPERAZIONIDIGIOCO_H_ */

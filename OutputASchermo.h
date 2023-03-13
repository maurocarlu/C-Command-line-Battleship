
#ifndef OUTPUTASCHERMO_H_
#define OUTPUTASCHERMO_H_
#include "Strutture.h"

void MostraMenu(int sceltaMenu);	//procedura che mostra un menu in base all'intero ricevuto in input

void MostraRegole();	//procedura che stampa a video le regole di gioco

void StampaGrigliaAttacco(BattleFieldAtt TabellaAtt);	//procedura che stampa a video la griglia di attacco del giocatore attuale

void StampaGrigliaPosizione(BattleFieldPos TabellaPos); //procedura che stampa a video la griglia di posizionamento del giocatore attuale

void MenuInserimento(int Navi1, int Navi2, int Navi3, int Navi4, int Navi5); //procedura che stampa a video il menu utilizzato durante l'inserimento delle navi

#endif /* OUTPUTASCHERMO_H_ */

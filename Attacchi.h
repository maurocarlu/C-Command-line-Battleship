
#ifndef ATTACCHI_H_
#define ATTACCHI_H_
#include "Strutture.h"
#include "OperazioniDiGioco.h"

BattleFieldAtt ControlloNaveAffondata(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos, int riga, int colonna); //funzione che viene usata nel momento in cui la cella colpita risulta occupata da una nave e che controlla se in seguito al colpo la nave è stata affondata

BattleFieldAtt Attacco(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos);	//funzione usata per attaccare una cella del campo avversario

BattleFieldAtt ModificaCellaAttacco(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos, int riga, int colonna); //funzione usata per modificare la TabellaAtt con l'esito dell'attacco

BattleFieldAtt ColpoALargoRaggio(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos); //funzione usata per eseguire un colpo a largo raggio

BattleFieldAtt BombardamentoAereo(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos); //funzione usata per eseguire un bombardamento aereo

BattleFieldAtt Radar(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos); //funzione usata per utilizzare il colpo speciale radar

BattleFieldAtt ModificaCelleRadar(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos, int riga, int colonna); //funzione richiamata dalla funzione radar per modificare le celle visionate in TabellaAtt

int ControlloAdiacente(BattleFieldPos TabellaPos, int riga, int colonna); //funzione che verifica se vi è una nave adiacente alla cella scelta


#endif /* ATTACCHI_H_ */

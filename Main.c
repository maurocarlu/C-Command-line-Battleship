#include <stdio.h>
#include <stdlib.h>
#include "OutputASchermo.h"
#include "OperazioniDiGioco.h"
#include "Strutture.h"
#include "SalvaECarica.h"


int main(void){
	int Turno=1;
	BattleFieldPos TabellaPos1;	//oggetto di tipo battlefieldpos per il giocatore1 - battlefieldpos
	BattleFieldPos TabellaPos2; //oggetto di tipo battlefieldpos per il giocatore2 - battlefieldpos
	BattleFieldAtt TabellaAtt1; //oggetto di tipo battlefieldlatt per il giocatore1 - battlefieldatt
	BattleFieldAtt TabellaAtt2; //oggetto di tipo battlefieldlatt per il giocatore2 - battlefieldatt
	char NomePartita[40]; //nome della partita
	char NomePlayer1[40]; //nome del giocatore 1
	char NomePlayer2[40]; //nome del giocatore 2
	Abilita ab1; //oggetto di tipo abilita per il giocatore 1 - abilita
	Abilita ab2; //oggetto di tipo abilita per il giocatore 2 - abilita
	int scelta;	//intero usato per scegliere quale operazione eseguire - intero - >0 e 5<
	int esito; //esito della funzione di caricamento - intero - 0 o 1


	//Scrittura di righe e colonne di tutte le tabelle utilizzate
	TabellaPos1= ScrivereRighePos(TabellaPos1,16);
	TabellaPos2= ScrivereRighePos(TabellaPos2,16);
	TabellaPos1= ScrivereColonnePos(TabellaPos1,16);
	TabellaPos2= ScrivereColonnePos(TabellaPos2,16);
	TabellaAtt1= ScrivereRigheAtt(TabellaAtt1,16);
	TabellaAtt2= ScrivereRigheAtt(TabellaAtt2,16);
	TabellaAtt1=ScrivereColonneAtt(TabellaAtt1,16);
	TabellaAtt2=ScrivereColonneAtt(TabellaAtt2,16);


	printf("Benvenuto nella battaglia navale\n\n");
	do{
		//scelta dell'operazione da eseguire tra Inizia Nuova Partita, Carica una partita precedente mostra regole e esci dal gioco
		MostraMenu(1);
		scelta=LeggereIntero();
		if(scelta==3){
			MostraRegole();
		}
		if(scelta==2){
			esito=CaricamentoPartita(NomePlayer1,NomePlayer2,TabellaPos1,TabellaPos2,TabellaAtt1,TabellaAtt2,ab1,ab2,Turno,NomePartita);
		}
	}while(scelta!=1 &&  scelta!=4 && esito!=1);
	if(scelta==1){
		IniziaPartita(NomePartita,NomePlayer1,NomePlayer2,TabellaPos1,TabellaPos2,TabellaAtt1,TabellaAtt2,ab1,ab2,Turno);
	}

	if(scelta==4 || esito == 1){
		printf("Grazie per aver giocato!\n");
	}
	system("PAUSE");
	return 0;
}

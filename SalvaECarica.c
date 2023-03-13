#include "OperazioniDiGioco.h"
#include "Strutture.h"
#include <stdio.h>
#include <stdlib.h>
#include "OutputASchermo.h"
int SalvaPartita(char NomePlayer1[], char NomePlayer2[], BattleFieldPos TabellaPos1, BattleFieldPos TabellaPos2, BattleFieldAtt TabellaAtt1, BattleFieldAtt TabellaAtt2, Abilita ab1, Abilita ab2, char NomePartita[], int turno){
	int esito=0; //intero che indica se il salvataggio è avvenuto con successo o no - intero - 0 o 1
	int r=0; //contatore per scorrere le righe - intero - >=0 e 15<=
	int c=0; //contatore per scorrere le colonne - intero - >=0 e 15<=
	FILE *fp; //puntatore al file da aprire - puntatore

	fp=fopen(NomePartita, "w");

	if (fp != NULL) {

		//i comandi fprintf servono per salvare i dati della partita (nome del giocatore1, giocatore2, ...)

		fprintf(fp, "%s %s ", NomePlayer1, NomePlayer2);

		fprintf(fp, "%d %d %d ", turno, LeggereContNavi(TabellaAtt1), LeggereContNavi(TabellaAtt2));

		fprintf(fp, "%d %d ", LeggereRadar(ab1), LeggereRadar(ab2));

		fprintf(fp, "%d %d ", LeggereColpoALargoRaggio(ab1), LeggereColpoALargoRaggio(ab2));

		fprintf(fp, "%d %d ", LeggereBombardamentoAereo(ab1), LeggereBombardamentoAereo(ab2));

		//i cicli servono per salvare i valori delle tabelle dei giocatori

		//Scorro righe e colonne di TabellaAtt1 per salvarne i valori su file
		while(r<LeggereRigheAtt(TabellaAtt1)){
			c=0;
			while(c<LeggereColonneAtt(TabellaAtt1)){
				fprintf(fp, "%d ", LeggereCellaAtt(TabellaAtt1, r, c));
				c++;
			}
			r++;
		}

		r=0;
		//Scorro righe e colonne di TabellaPos1 per salvarne i valori su file
		while(r<LeggereRighePos(TabellaPos1)){
		    c=0;
			while(c<LeggereColonnePos(TabellaPos1)){
				fprintf(fp, "%d ", LeggereCellaPos(TabellaPos1, r, c));
				c++;
			}
			r++;
		}

		r=0;
		//Scorro righe e colonne di TabellaAtt2 per salvarne i valori su file
		while(r<LeggereRigheAtt(TabellaAtt2)){
			c=0;
			while(c<LeggereColonneAtt(TabellaAtt2)){
				fprintf(fp, "%d ", LeggereCellaAtt(TabellaAtt2, r, c));
				c++;
			}
			r++;
		}

		r=0;
		//Scorro righe e colonne di TabellaPos2 per salvarne i valori su file
		while(r<LeggereRighePos(TabellaPos2)){
		   c=0;
		   while(c<LeggereColonnePos(TabellaPos2)){
			  fprintf(fp, "%d ", LeggereCellaPos(TabellaPos2, r, c));
			  c++;
			}
			r++;
		}
		esito=1;
		fclose(fp);
		return esito;


	}else{
		printf("Errore nell'apertura del file \n");
	}
	return esito;
}




int CaricamentoPartita(char NomePlayer1[], char NomePlayer2[], BattleFieldPos TabellaPos1, BattleFieldPos TabellaPos2, BattleFieldAtt TabellaAtt1, BattleFieldAtt TabellaAtt2, Abilita ab1, Abilita ab2, int turno, char NomePartita[]){

	FILE *fp; //puntatore al file da aprire - puntatore
	int esito=2; //intero che indica l'esito della ricerca del file da aprire - intero - Può valere 0-1-2
	int scelta; //intero che indica se l'utente vuole riprovare a inserire un nome - intero - Può valere 1-2
	int app; //intero di appoggio letto dal file - intero
	int r=0; //contatore per scorrere le righe - intero - >=0 e 15<=
	int c=0; //contatore per scorrere le colonne - intero - >=0 e 15<=


	//serve per verificare che il giocatore inserisca il nome di una partita che esiste
	do{
		printf("Inserisci il nome della partita che vuoi caricare\n");
		scanf("%s", NomePartita);

		fp=fopen(NomePartita, "r");
		if (fp == NULL){													//Se la partita esiste viene caricata
			MostraMenu(4);													//altrimenti l'utente sceglie se riprovare o tornare al menu principale
			scanf("%d",&scelta);
			printf("\n");
			if(scelta == 2){
				esito=0;
			}
		}else{
			esito=1;
		}
	}while(esito == 2);

	//se il nome della partita inserito dall'utente esiste (quindi esito è 1), verranno caricati i dati della partita
	if(esito == 1){

		//caricamento dei nomi dei giocatori, turno, numero di navi rimaste, numero di abilità rimaste
		fscanf(fp, "%s %s ", NomePlayer1, NomePlayer2);
		fscanf(fp, "%d ", &app);
		turno=app;

		fscanf(fp, "%d ", &app);
		TabellaAtt1=ScriviContNavi(TabellaAtt1, app);
		fscanf(fp, "%d ", &app);
		TabellaAtt2=ScriviContNavi(TabellaAtt2, app);

		fscanf(fp, "%d ", &app);
		ab1=ScrivereRadar(ab1, app);
		fscanf(fp, "%d ", &app);
		ab2=ScrivereRadar(ab2, app);

		fscanf(fp, "%d ", &app);
		ab1=ScrivereColpoALargoRaggio(ab1, app);
		fscanf(fp, "%d ", &app);
		ab2=ScrivereColpoALargoRaggio(ab2, app);

		fscanf(fp, "%d ", &app);
		ab1=ScrivereBombardamentoAereo(ab1, app);
		fscanf(fp, "%d ", &app);
		ab2=ScrivereBombardamentoAereo(ab2, app);

		//Scorro righe e colonne di TabellaAtt1 per caricare i valori dal file
		while(r<LeggereRigheAtt(TabellaAtt1)){
			c=0;
			while(c<LeggereColonneAtt(TabellaAtt1)){
				fscanf(fp, "%d ", &app);
				TabellaAtt1=ScrivereCellaAtt(TabellaAtt1, r, c, app);
				c++;
			}
			r++;
		}

		r=0;
		//Scorro righe e colonne di TabellaPos1 per caricare i valori dal file
		while(r<LeggereRighePos(TabellaPos1)){
			c=0;
			while(c<LeggereColonnePos(TabellaPos1)){
				fscanf(fp, "%d ", &app);
				TabellaPos1=ScrivereCellaPos(TabellaPos1, r, c, app);
				c++;
			}
			r++;
		}

		r=0;
		//Scorro righe e colonne di TabellaAtt2 per caricare i valori dal file
		while(r<LeggereRigheAtt(TabellaAtt2)){
			c=0;
			while(c<LeggereColonneAtt(TabellaAtt2)){
				fscanf(fp, "%d ", &app);
				TabellaAtt2=ScrivereCellaAtt(TabellaAtt2, r, c, app);
				c++;
			}
			r++;
		}

		 r=0;
		 //Scorro righe e colonne di TabellaAtt2 per caricare i valori dal file
		 while(r<LeggereRighePos(TabellaPos2)){
			 c=0;
			 while(c<LeggereColonnePos(TabellaPos2)){
				 fscanf(fp, "%d ", &app);
				 TabellaPos2=ScrivereCellaPos(TabellaPos2, r, c, app);
				 c++;
			 }
			 r++;
		  }
		 //una volta caricati tutti i dati si viene rimandati alla funzione di gioco
		 Gioca(NomePlayer1,NomePlayer2, NomePartita, TabellaPos1, TabellaPos2, TabellaAtt1, TabellaAtt2, ab1, ab2, turno);
		 return 1;
	}
	//se l'utente non vuole riprovare a inserire il nome della partita torna al menù principale
	if(esito==0)
	{
		printf("Torna al menu' principale\n");
	}
	return 0;
}

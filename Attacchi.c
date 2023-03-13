#include "Attacchi.h"
#include "OutputAschermo.h"
#include <stdio.h>
#include <stdlib.h>

BattleFieldAtt ControlloNaveAffondata(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos, int riga, int colonna){
	int flag=1; //variabile di controllo utilizzata per entrare nei cicli-intero- 0 o 1
	int k=1; //intero per muoversi lungo le righe o le colonne-intero- >=1 e 16<=
	int orizzontale=0; //variabile di controllo per stabilire se la nave è posizionata orizzontalmente- intero- 0 o 1
	int verticale=0;  //variabile di controllo per stabilire se la nave è posizionata verticalmente – intero - 0 o 1
	int contpos=1; //contatore usato per indicare da quante celle è composta la nave colpita-intero (parte da 1 perchè se la funzione è stata richiamata signfica che un punto è stato colpito)- >0
	int contatt=1; //contatore usato per indicare quante celle sono state colpite della nave- intero (parte da 1 perchè se la funzione è stata richiamata signfica che un punto è stato colpito)- >0


	//controlla in quale verso è presente la nave partendo dal punto colpito guardando nella tabella dell'avversario (TabellaPos)

	//controllo verso l'alto
	if(riga!=0){
		//se nella cella controllata c'è un pezzo di nave il verso in cui controllare è verticale
		if(LeggereCellaPos(TabellaPos, riga-1,colonna)==1){
			verticale=1;
		}
	}
	//controllo verso il basso (se il precedente non è andato a buon fine)
	if(riga!=LeggereRighePos(TabellaPos)-1 && verticale !=1){
		//se nella cella controllata c'è un pezzo di nave il verso in cui controllare è verticale
		if(LeggereCellaPos(TabellaPos, riga+1,colonna)==1){
			verticale=1;
		}
	}
	//Controllo verso sinistra(se i controlli precedenti non sono andati a buon fine)
	if(colonna!=0 && verticale!=1){
		//se nella cella controllata c'è un pezzo di nave il verso in cui controllare è orizzontale
		if(LeggereCellaPos(TabellaPos,riga,colonna-1)==1){
			orizzontale=1;
		}
	}
	//controllo verso destra(se i controlli precedenti non sono andati a buon fine)
	if(colonna!=LeggereColonnePos(TabellaPos)-1 && verticale!=1 && orizzontale!=1){
		//se nella cella controllata c'è un pezzo di nave il verso in cui controllare è orizzontale
		if(LeggereCellaPos(TabellaPos,riga,colonna+1)==1){
			orizzontale=1;
		}
	}

	//una volta stabilito se la nave è in verticale o in orizzontale conta
	//se orizzontale a destra e a sinistra, se verticale in basso e in alto
	//quanto è lunga la nave effettuando i controlli su TabellaPos del giocatore avversario

	//Se la nave è in verticale controlla in alto e in basso
	if(verticale==1){
		//controllo verso l'alto
		//fino a quando non raggiunge il bordo superiore della tabella e trova un pezzo di nave
		while((riga-k) != -1 && flag==1){
			//se trova un pezzo di nave aumenta il contatore della lunghezza della nave di 1 e k di 1
			if(LeggereCellaPos(TabellaPos, riga-k, colonna)==1){
				contpos++;
				k++;
			//se non c'è una nave flag=0 e smetti di cercare
			}else{
				flag=0;
			}
		}
		k=1;
		flag=1;
		//controllo verso il basso
		//fino a quando non raggiunge il bordo inferiore della tabella e trova un pezzo di nave
		while((riga+k)!=LeggereRighePos(TabellaPos) && flag==1){
			//se trova un pezzo di nave aumenta il contatore della lunghezza della nave di 1 e k di 1
			if(LeggereCellaPos(TabellaPos, riga+k, colonna)==1){
				contpos++;
				k++;
			//se non c'è una nave flag=0 e smetti di cercare
			}else{
				flag=0;
			}
		}
	//Se la nave è in orizzontale conta a destra e a sinistra
	}else if(orizzontale==1){
		//controllo verso sinistra
		//fino a quando non raggiunge il bordo sinistro della tabella e trova un pezzo di nave
		while((colonna-k)!=-1 && flag==1){
			//se trova un pezzo di nave aumenta il contatore della lunghezza della nave di 1 e k di 1
			if(LeggereCellaPos(TabellaPos,riga,colonna-k)==1){
				contpos++;
				k++;
			//se non c'è una nave flag=0 e smetti di cercare
			}else{
				flag=0;
			}
		}
		k=1;
		flag=1;
		//controllo verso destra
		//fino a quando non raggiunge il bordo destra della tabella e trova un pezzo di nave
		while((colonna+k)!=LeggereColonnePos(TabellaPos) && flag==1){
			//se trova un pezzo di nave aumenta il contatore della lunghezza della nave di 1 e k di 1
			if(LeggereCellaPos(TabellaPos,riga,colonna+k)==1){
				contpos++;
				k++;
			//se non c'è una nave flag=0 e smetti di cercare
			}else{
				flag=0;
			}
		}
	}

	//una volta contato quanto è lunga la nave in TabellaPos avversaria,
	//viene verificato quanti punti di quella nave sono stati effettivamente colpiti utilizzando
	//la propria TabellaAtt
	k=1;
	flag=1;

	//Se la nave è in verticale controllo verso l'alto e verso il basso
	if(verticale==1){
		//controllo in alto
		//fino a quando non raggiunge il bordo superiore della tabella e trova un pezzo di nave
		while(riga-k!=-1 && flag==1){
			//se trova un pezzo di nave aumenta il contatore dei punti colpiti della nave di 1 e k di 1
			if(LeggereCellaAtt(TabellaAtt,riga-k,colonna)==1){
				contatt++;
				k++;
			//se non c'è una nave flag=0 e smetti di cercare
			}else{
				flag=0;
			}
		}
		k=1;
		flag=1;
		//controllo verso  il basso
		//fino a quando non raggiunge il bordo inferiore della tabella e trova un pezzo di nave
		while((riga+k)!=LeggereRigheAtt(TabellaAtt) && flag==1){
			//se trova un pezzo di nave aumenta il contatore dei punti colpiti della nave di 1 e k di 1
			if(LeggereCellaAtt(TabellaAtt, riga+k,colonna)==1){
				contatt++;
				k++;
			//se non c'è una nave flag=0 e smetti di cercare
			}else{
				flag=0;
			}
		}
		k=1;
		flag=1;
	//Se il verso è orizzontale controlla verso sinistra e verso destra
	}else if(orizzontale==1){
		//controlla verso sinistra
		//fino a quando non raggiunge il bordo sinistro della tabella e trova un pezzo di nave
		while((colonna-k)!=-1 && flag==1){
			//se trova un pezzo di nave aumenta il contatore dei punti colpiti della nave di 1 e k di 1
			if(LeggereCellaAtt(TabellaAtt,riga,colonna-k)==1){
				contatt++;
				k++;
			//se non c'è una nave flag=0 e smetti di cercare
			}else{
				flag=0;
			}
		}
		k=1;
		flag=1;
		//controlla verso destra
		//fino a quando non raggiunge il bordo destro della tabella e trova un pezzo di nave
		while((colonna+k)!=LeggereColonneAtt(TabellaAtt) && flag==1){
			//se trova un pezzo di nave aumenta il contatore dei punti colpiti della nave di 1 e k di 1
			if(LeggereCellaAtt(TabellaAtt,riga,colonna+k)==1){
				contatt++;
				k++;
			//se non c'è una nave flag=0 e smetti di cercare
			}else{
				flag=0;
			}
		}
	}
	//Se la lunghezza della nave in TabellaPos coincide con
	//il numero di punti colpiti in TabellaAtt allora la nave è stata affondata
	if(contpos==contatt){
		TabellaAtt=DecrementaNavi(TabellaAtt);
		printf("Nave Affondata!\n");
	}

	return TabellaAtt;
}



BattleFieldAtt Attacco(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos){
	int colonna=0; //colonna scelta dal giocatore per attaccare- intero- >0 e <17
	int riga=0; //riga scelta dal giocatore per attaccare-intero- >0 e <17
	char carattere; //carattere inserito dall’utente che indica quale colonna colpire- carattere
	do{
		//scelta della riga da colpire
		do{
			printf("Inserisci un numero tra 1 e 16 per indicare quale riga colpire: ");
			riga=LeggereIntero();
		}while(riga<1 || riga>LeggereRigheAtt(TabellaAtt)); //fino a quando non viene inserita una riga corretta
		riga--;
		do{
		//scelta della colonna da colpire
			printf("Inserisci una lettera maiuscola da A a P per indicare quale colonna colpire: ");
			scanf("%c",&carattere);
			printf("\n");
			fflush(stdin);
			colonna=TraduzioneColonna(carattere);
		}while(colonna==-1); //fino a quando non viene inserita una colonna corretta

		//Se la cella selezionata non è 0 oppure 3, l'utente deve reinserire riga e colonna in quanto ha già colpito la cella selezionata
		if(LeggereCellaAtt(TabellaAtt,riga,colonna)!=0 && LeggereCellaAtt(TabellaAtt,riga,colonna)!=3){
			printf("La cella selezionata e' gia' stata colpita, inserire un'altra riga o colonna\n");
		}
	}while(LeggereCellaAtt(TabellaAtt,riga,colonna)!=0 && LeggereCellaAtt(TabellaAtt,riga,colonna)!=3); //ripeti se l'utente inserisce una cella colpita
	//modifica la cella in base all'esito del colpo
	TabellaAtt=ModificaCellaAttacco(TabellaAtt, TabellaPos,riga,colonna);

	return TabellaAtt;
}

BattleFieldAtt ModificaCellaAttacco(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos, int riga, int colonna){
	//Se nel punto selezionato vi è una nave allora nave colpita
	if(LeggereCellaPos(TabellaPos,riga,colonna)==1){
		TabellaAtt=ScrivereCellaAtt(TabellaAtt,riga,colonna,1); //Aggiornamento di TabellaAtt in base all'esito
		printf("Nave colpita!\n");
		TabellaAtt=ControlloNaveAffondata(TabellaAtt,TabellaPos,riga,colonna);
	//Se nel punto selezionato non vi è una nave allora colpo a vuoto
	}else{
		TabellaAtt=ScrivereCellaAtt(TabellaAtt,riga,colonna,2); //Aggiornamento di TabellaAtt in base all'esito
		printf("Colpo a vuoto!\n");
	}
	return TabellaAtt;
}

BattleFieldAtt ColpoALargoRaggio(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos){
	int riga;//riga scelta dal giocatore per attaccare-intero- >0 e <17
	int colonna;//colonna scelta dal giocatore per attaccare- intero- >0 e <17
	char carattere;//carattere letto da tastiera per la colonna scelta dall'utente - carattere

	//inserimento della riga
	do{
		printf("Inserisci un numero tra 1 e 16 per indicare quale riga colpire: ");
		riga=LeggereIntero();
	}while(riga<1 || riga>LeggereRigheAtt(TabellaAtt)); //fino a quando non viene inserita una riga corretta
	riga--;

	//inserimento della colonna
	do{
		printf("Inserisci una lettera maiuscola tra A e P per indicare quale colonna colpire: ");
		scanf("%c",&carattere);
		printf("\n");
		fflush(stdin);
		colonna=TraduzioneColonna(carattere);
	}while(colonna==-1); //fino a quando non è inserito un carattere corretto

	//cella di partenza
	printf("Cella %d %c: ",riga+1,carattere);
	//Se la cella di partenza è gia stata colpita
	if(LeggereCellaAtt(TabellaAtt,riga,colonna)==1 || LeggereCellaAtt(TabellaAtt,riga,colonna)==2){
		printf("Cella gia' colpita\n");
	//Se la cella non è già stata colpita controlla il contenuto
	}else{
		TabellaAtt=ModificaCellaAttacco(TabellaAtt,TabellaPos,riga,colonna);
	}
	//controllo in alto a sinistra se la cella è nei limiti
	if(riga-1>=0 && colonna-1>=0){
		carattere=TraduzioneColonnaInversa(colonna-1);
		printf("Cella %d %c: ",riga,carattere);
		//Se questo punto è già stato colpito cella già colpita
		if(LeggereCellaAtt(TabellaAtt,riga-1,colonna-1)==1 || LeggereCellaAtt(TabellaAtt,riga-1,colonna-1)==2){
			printf("Cella gia' colpita\n");
		//Se la cella non è già stata colpita controlla il contenuto
		}else{
			TabellaAtt=ModificaCellaAttacco(TabellaAtt,TabellaPos,riga-1,colonna-1);
		}
	//se la cella è fuori dai limiti
	}else{
		printf("cella in alto a sinistra fuori dai limiti\n");
	}
	//controllo a sinistra se la cella è nei limiti
	if(colonna-1>=0){
		carattere=TraduzioneColonnaInversa(colonna-1);
		printf("Cella %d %c: ",riga+1,carattere);
		//Se questo punto è già stato colpito cella già colpita
		if(LeggereCellaAtt(TabellaAtt,riga,colonna-1)==1 || LeggereCellaAtt(TabellaAtt,riga,colonna-1)==2){
			printf("Cella gia' colpita\n");
		//Se la cella non è già stata colpita controlla il contenuto
		}else{
			TabellaAtt=ModificaCellaAttacco(TabellaAtt,TabellaPos,riga,colonna-1);
		}
	//se la cella è fuori dai limiti
	}else{
		printf("cella a sinistra fuori dai limiti\n");
	}
	//controllo in basso a sinistra se la cella è nei limiti
	if(riga+1<LeggereRigheAtt(TabellaAtt) && colonna-1>=0){
			carattere=TraduzioneColonnaInversa(colonna-1);
			printf("Cella %d %c: ",riga+2,carattere);
			//Se questo punto è già stato colpito cella già colpita
			if(LeggereCellaAtt(TabellaAtt,riga+1,colonna-1)==1 || LeggereCellaAtt(TabellaAtt,riga+1,colonna-1)==2){
				printf("Cella gia' colpita\n");
			//Se la cella non è già stata colpita controlla il contenuto
			}else{
				TabellaAtt=ModificaCellaAttacco(TabellaAtt,TabellaPos,riga+1,colonna-1);
			}
	//se la cella è fuori dai limiti
	}else{
			printf("cella in basso a sinistra fuori dai limiti\n");
	}
	//controllo in alto se la cella è nei limiti
	if(riga-1>=0){
			carattere=TraduzioneColonnaInversa(colonna);
			printf("Cella %d %c: ",riga,carattere);
			//Se questo punto è già stato colpito cella già colpita
			if(LeggereCellaAtt(TabellaAtt,riga-1,colonna)==1 || LeggereCellaAtt(TabellaAtt,riga-1,colonna)==2){
				printf("Cella gia' colpita\n");
			//Se la cella non è già stata colpita controlla il contenuto
			}else{
				TabellaAtt=ModificaCellaAttacco(TabellaAtt,TabellaPos,riga-1,colonna);
			}
	//Se la cella è fuori dai limiti
	}else{
		printf("cella in alto fuori dai limiti\n");
	}
	//controllo in basso se la cella è nei limiti
	if(riga+1<LeggereRigheAtt(TabellaAtt)){
		carattere=TraduzioneColonnaInversa(colonna);
		printf("Cella %d %c: ",riga+2,carattere);
		//Se questo punto è già stato colpito cella già colpita
		if(LeggereCellaAtt(TabellaAtt,riga+1,colonna)==1 || LeggereCellaAtt(TabellaAtt,riga+1,colonna)==2){
			printf("Cella gia' colpita\n");
		//Se la cella non è già stata colpita controlla il contenuto
		}else{
			TabellaAtt=ModificaCellaAttacco(TabellaAtt,TabellaPos,riga+1,colonna);
		}
	//Se la cella è fuori dai limiti
	}else{
		printf("cella in basso fuori dai limiti\n");
	}
	//controllo in alto a destra se la cella è nei limiti
	if(riga-1>=0 && colonna+1<LeggereColonneAtt(TabellaAtt)){
		carattere=TraduzioneColonnaInversa(colonna+1);
		printf("Cella %d %c: ",riga,carattere); //RIGA-1
		//Se questo punto è già stato colpito cella già colpita
		if(LeggereCellaAtt(TabellaAtt,riga-1,colonna+1)==1 || LeggereCellaAtt(TabellaAtt,riga-1,colonna+1)==2){
			printf("Cella gia' colpita\n");
		//Se la cella non è già stata colpita controlla il contenuto
		}else{
			TabellaAtt=ModificaCellaAttacco(TabellaAtt,TabellaPos,riga-1,colonna+1);
		}
	//Se la cella è fuori dai limiti
	}else{
		printf("cella in basso a destra fuori dai limiti\n");
	}
	//controllo a destra se la cella è nei limiti
	if(colonna+1<LeggereColonneAtt(TabellaAtt)){
		carattere=TraduzioneColonnaInversa(colonna+1);
		printf("Cella %d %c: ",riga+1,carattere);
		//Se questo punto è già stato colpito cella già colpita
		if(LeggereCellaAtt(TabellaAtt,riga,colonna+1)==1 || LeggereCellaAtt(TabellaAtt,riga,colonna+1)==2){
			printf("Cella gia' colpita\n");
		//Se la cella non è già stata colpita controlla il contenuto
		}else{
			TabellaAtt=ModificaCellaAttacco(TabellaAtt,TabellaPos,riga,colonna+1);
		}
	//Se la cella è fuori dai limiti
	}else{
		printf("cella a destra fuori dai limiti\n");
	}
	//controllo in basso a destra se la cella è nei limiti
	if(riga+1<LeggereRigheAtt(TabellaAtt) && colonna+1<LeggereColonneAtt(TabellaAtt)){
			carattere=TraduzioneColonnaInversa(colonna+1);
			printf("Cella %d %c: ",riga+2,carattere);//RIGA+1
			//Se questo punto è già stato colpito cella già colpita
			if(LeggereCellaAtt(TabellaAtt,riga+1,colonna+1)==1 || LeggereCellaAtt(TabellaAtt,riga+1,colonna+1)==2){
				printf("Cella gia' colpita\n");
			//Se la cella non è già stata colpita controlla il contenuto
			}else{
				TabellaAtt=ModificaCellaAttacco(TabellaAtt,TabellaPos,riga+1,colonna+1);
			}
		//Se la cella è fuori dai limiti
		}else{
			printf("cella in basso a destra fuori dai limiti\n");
		}

	return TabellaAtt;
}

BattleFieldAtt BombardamentoAereo(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos){
	int riga=0; //riga scelta dal giocatore per attaccare-intero- >0 e <17
	int colonna=0; //colonna scelta dal giocatore per attaccare- intero- >0 e <17
	char carattere; //Carattere- carattere inserito dall’utente che indica quale colonna colpire- carattere
	int scelta; //numero che indica se colpire una riga o una colonna-intero- 1 o 2

	//scegliere se colpire tutta una riga o tutta una colonna
	do{
		MostraMenu(5);
		scelta=LeggereIntero();
	}while(scelta!=1 && scelta!=2); //fin quando scelta non è 1 o 2

	//se si sceglie di colpire una riga
	if(scelta==1){
		//inserimento della riga che si vuole colpire
		do{
			printf("Inserisci un numero tra 1 e 16 per indicare quale riga colpire: ");
			riga=LeggereIntero();
		}while(riga<1 || riga>LeggereRigheAtt(TabellaAtt));
		riga--;
		//Ciclo per colpire tutte le celle della riga scelta scorrendo le colonne
		do{
			carattere=TraduzioneColonnaInversa(colonna);//viene tradotto il carattere partendo da un numero per poter stampare a video la lettera
			printf("Cella %d %c: ",riga+1,carattere);
			//Se questo punto è gia stato colpito allora cella già colpita
			if(LeggereCellaAtt(TabellaAtt,riga,colonna)==1 || LeggereCellaAtt(TabellaAtt,riga,colonna)==2){
				printf("Gia' colpita!\n");
			//Se la cella non è già stata colpita controlla il contenuto
			}else{
				TabellaAtt=ModificaCellaAttacco(TabellaAtt,TabellaPos,riga,colonna);
			}
			colonna++;
		}while(colonna<LeggereColonneAtt(TabellaAtt)); //fino alla fine delle colonne

	//se è stata scelto di colpire una colonna
	}else{
		//inserimento della colonna da colpire
		do{
			printf("Inserisci una lettera da A a P in maiuscolo per indicare quale colonna colpire: ");
			scanf("%c",&carattere);
			printf("\n");
			fflush(stdin);
			colonna=TraduzioneColonna(carattere);	//il carattere viene tradotto tramite la funzione in numero per verificare che sia un carattere accettato
		}while(colonna==-1); //fino a quando non viene inserita una colonna corretta

		//Ciclo per colpire tutte le celle della colonna scelta scorrendo le righe
		do{
			printf("Cella %d %c: ",riga+1,carattere);
			//Se questo punto è gia stato colpito allora cella già colpita
			if(LeggereCellaAtt(TabellaAtt,riga,colonna)==1 || LeggereCellaAtt(TabellaAtt,riga,colonna)==2){
				printf("Gia' colpita!\n");
			//Se la cella non è già stata colpita controlla il contenuto
			}else{
				TabellaAtt=ModificaCellaAttacco(TabellaAtt,TabellaPos,riga,colonna);
			}
			riga++;
		}while(riga<LeggereRigheAtt(TabellaAtt));	//fino alla fine delle righe
	}
	return TabellaAtt;
}

BattleFieldAtt Radar(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos){
	int riga;
	int colonna;
	char carattere;
	//inserimento della riga di partenza
	do{
		printf("Inserisci un numero (tra 1 e 16) per indicare quale Riga scansionare: ");
	    riga=LeggereIntero();
	    riga-- ;
	}while(riga<0 || riga >= LeggereRigheAtt(TabellaAtt)); //fino a quando non viene inserita una riga corretta
	//inserimento della colonna di partenza
	do{
		printf("Inserisci una lettera maiuscola (tra A e P) per indicare quale colonna scansionare: ");
	    scanf("%c",&carattere);
	    printf("\n");
	    fflush(stdin);
	    colonna=TraduzioneColonna(carattere);
	}while(colonna==-1); //fino a quando non viene inserita una colonna corretta


	//controllo per verificare se la cella di partenza sia stata colpita precedentemente
	printf("Cella %d %c: ", riga+1, carattere);
	if(LeggereCellaAtt(TabellaAtt, riga, colonna)==1 || LeggereCellaAtt(TabellaAtt, riga, colonna)==2){
		printf("Gia' colpita\n");
	}
	//altrimenti controllo il contenuto della cella
	else{
		TabellaAtt=ModificaCelleRadar(TabellaAtt, TabellaPos, riga, colonna);
	}

	//I seguenti controlli servono per verificare se nelle celle circostanti a quella scelta inizialmente dall'utente siano presenti delle navi nemiche, se si esce dai limiti oppure se la cella e' stata colpita

	//controllo in alto a sinistra se la cella è nei limiti
	if(riga-1>=0 && colonna-1>=0){
		carattere=TraduzioneColonnaInversa(colonna-1);
	    printf("Cella %d %c: ", riga, carattere);
	    //Se il punto selezionato è già stato colpito, cella già colpita
	    if(LeggereCellaAtt(TabellaAtt, riga-1, colonna-1)==1 || LeggereCellaAtt(TabellaAtt,riga-1,colonna-1)==2){
	    	printf("Gia' colpita\n");
	    //Se la cella non è già stata colpita controlla il contenuto
	    }else{
	    	TabellaAtt=ModificaCelleRadar(TabellaAtt, TabellaPos, riga-1, colonna-1);
	    }
	//Se la cella è fuori dai limiti
	}else{
		printf("Cella in alto a sinistra fuori dai limiti\n");
	}
	//controllo a sinistra se la cella è nei limiti
	if(colonna-1>=0){
		carattere=TraduzioneColonnaInversa(colonna-1);
	    printf("Cella %d %c: ", riga+1, carattere);
	    //Se il punto selezionato è già stato colpito, cella già colpita
	    if(LeggereCellaAtt(TabellaAtt, riga, colonna-1)==1 || LeggereCellaAtt(TabellaAtt,riga,colonna-1)==2){
	    	printf("Gia' colpita\n");
	    //Se la cella non è già stata colpita controlla il contenuto
	    }else{
	    	TabellaAtt=ModificaCelleRadar(TabellaAtt, TabellaPos, riga, colonna-1);
	    }
	//Se la cella è fuori dai limiti
	}else{
		printf("Cella a sinistra fuori dai limiti\n");
	}
	//controllo in basso a sinistra se la cella è nei limiti
	if(riga+1<LeggereRigheAtt(TabellaAtt) && colonna-1 >=0){
		carattere=TraduzioneColonnaInversa(colonna-1);
	    printf("Cella %d %c: ", riga+2, carattere);
	    //Se il punto selezionato è già stato colpito, cella già colpita
	    if(LeggereCellaAtt(TabellaAtt, riga+1, colonna-1)==1 || LeggereCellaAtt(TabellaAtt,riga+1,colonna-1)==2){
	    	printf("Gia' colpita\n");
	   	//Se la cella non è già stata colpita controlla il contenuto
	    }else{
	    	TabellaAtt=ModificaCelleRadar(TabellaAtt, TabellaPos, riga+1, colonna-1);
	    }
	//Se la cella è fuori dai limiti
	}else{
		printf("Cella in basso a sinistra fuori dai limiti\n");
	}

	//controllo in alto se la cella è nei limiti
	if(riga-1>=0){
		carattere=TraduzioneColonnaInversa(colonna);
	    printf("Cella %d %c: ", riga, carattere);
	    //Se il punto selezionato è già stato colpito, cella già colpita
	    if(LeggereCellaAtt(TabellaAtt, riga-1, colonna)==1 || LeggereCellaAtt(TabellaAtt,riga-1,colonna)==2){
	    	printf("Gia' colpita\n");
	   	//Se la cella non è già stata colpita controlla il contenuto
	    }else{
	    	TabellaAtt=ModificaCelleRadar(TabellaAtt, TabellaPos, riga-1, colonna);
	    }
	//Se la cella è fuori dai limiti
	}else{
		printf("Cella in alto fuori dai limiti\n");
	}
	//controllo in basso se la cella è nei limiti
	if(riga+1<LeggereRigheAtt(TabellaAtt)){
		carattere=TraduzioneColonnaInversa(colonna);
	    printf("Cella %d %c: ", riga+2, carattere);
	    //Se il punto selezionato è già stato colpito, cella già colpita
	    if(LeggereCellaAtt(TabellaAtt, riga+1, colonna)==1 || LeggereCellaAtt(TabellaAtt,riga+1,colonna)==2){
	    	printf("Gia' colpita\n");
	   	//Se la cella non è già stata colpita controlla il contenuto
	    }else{
	    	TabellaAtt=ModificaCelleRadar(TabellaAtt, TabellaPos, riga+1, colonna);
	    }
	//Se la cella è fuori dai limiti
	}else{
		printf("Cella in basso fuori dai limiti\n");
	}
	//controllo in alto a destra se la cella è nei limiti
	if(riga-1>=0 && colonna+1<LeggereColonneAtt(TabellaAtt)){
		carattere=TraduzioneColonnaInversa(colonna+1);
	    printf("Cella %d %c: ", riga, carattere);
	    //Se il punto selezionato è già stato colpito, cella già colpita
	    if(LeggereCellaAtt(TabellaAtt, riga-1, colonna+1)==1 || LeggereCellaAtt(TabellaAtt,riga-1,colonna+1)==2){
	    	printf("Gia' colpita\n");
	    //Se la cella non è già stata colpita controlla il contenuto
	    }else{
	    	TabellaAtt=ModificaCelleRadar(TabellaAtt, TabellaPos, riga-1, colonna+1);
	    }
	//Se la cella è fuori dai limiti
	}else{
		printf("Cella in alto a destra fuori dai limiti\n");
	}
	//controllo a destra se la cella è nei limiti
	if(colonna+1<LeggereColonneAtt(TabellaAtt)){
		carattere=TraduzioneColonnaInversa(colonna+1);
	    printf("Cella %d %c: ", riga+1, carattere);
	    //Se il punto selezionato è già stato colpito, cella già colpita
	    if(LeggereCellaAtt(TabellaAtt, riga, colonna+1)==1 || LeggereCellaAtt(TabellaAtt,riga,colonna+1)==2){
	    	printf("Gia' colpita\n");
	   	//Se la cella non è già stata colpita controlla il contenuto
	    }else{
	    	TabellaAtt=ModificaCelleRadar(TabellaAtt, TabellaPos, riga, colonna+1);
	    }
	//Se la cella è fuori dai limiti
	}else{
		printf("Cella  a destra fuori dai limiti\n");
	}
	//controllo in basso a destra se la cella è nei limiti
	if(riga+1<LeggereRigheAtt(TabellaAtt) && colonna+1<LeggereColonneAtt(TabellaAtt)){
		carattere=TraduzioneColonnaInversa(colonna+1);
	    printf("Cella %d %c: ", riga+2, carattere);
	    //Se il punto selezionato è già stato colpito, cella già colpita
	    if(LeggereCellaAtt(TabellaAtt, riga+1, colonna+1)==1 || LeggereCellaAtt(TabellaAtt,riga+1,colonna+1)==2){
	    	printf("Gia' colpita\n");
	   	//Se la cella non è già stata colpita controlla il contenuto
	    }else{
	    	TabellaAtt=ModificaCelleRadar(TabellaAtt, TabellaPos, riga+1, colonna+1);
	    }
	//Se la cella è fuori dai limiti
	}else{
		printf("Cella in basso a destra fuori dai limiti\n");
	}

	return TabellaAtt;
}

BattleFieldAtt ModificaCelleRadar(BattleFieldAtt TabellaAtt, BattleFieldPos TabellaPos, int riga, int colonna){

	//se nella cella selezionata vi è una nave nemica scrivo 1 nella tabellaatt del giocatore che attacca
	if(LeggereCellaPos(TabellaPos,riga,colonna)==1){
		printf("Nave\n");
		TabellaAtt=ScrivereCellaAtt(TabellaAtt,riga,colonna,3);
	//se nella cella selezionata non vi è alcuna nave scrivo 2 nella tabellaatt del giocatore che attacca
	}else{
		printf("vuoto\n");
		TabellaAtt=ScrivereCellaAtt(TabellaAtt,riga,colonna,2);
	}
	return TabellaAtt;
}

int ControlloAdiacente(BattleFieldPos TabellaPos, int riga, int colonna){
	int flag=1; //variabile che indica l’esito della funzione- intero- 0 o 1

	//controllo in alto a sinistra se la cella è nei limiti
	if(riga-1>=0 && colonna-1 >=0){
		//se nella cella selezionata vi è un pezzo di nave allora c'è una nave adiacente e quindi flag=0
		if(LeggereCellaPos(TabellaPos,riga-1,colonna-1)==1){
			flag=0;
		}
	}
	//controllo a sinistra se la cella è nei limiti
	if(colonna-1>=0 && flag==1){
		//se nella cella selezionata vi è un pezzo di nave allora c'è una nave adiacente e quindi flag=0
		if(LeggereCellaPos(TabellaPos,riga,colonna-1)==1){
			flag=0;
		}
	}
	//controllo in basso a sinistra se la cella è nei limiti
	if(riga+1<LeggereRighePos(TabellaPos) && colonna-1>=0 && flag==1){
		//se nella cella selezionata vi è un pezzo di nave allora c'è una nave adiacente e quindi flag=0
		if(LeggereCellaPos(TabellaPos,riga+1,colonna-1)==1){
			flag=0;
		}
	}
	//controllo in alto se la cella è nei limiti
	if(riga-1>=0 && flag==1){
		//se nella cella selezionata vi è un pezzo di nave allora c'è una nave adiacente e quindi flag=0
		if(LeggereCellaPos(TabellaPos,riga-1,colonna)==1){
			flag=0;
		}
	}
	//controllo in basso se la cella è nei limiti
	if(riga+1<LeggereRighePos(TabellaPos) && flag==1){
		//se nella cella selezionata vi è un pezzo di nave allora c'è una nave adiacente e quindi flag=0
		if(LeggereCellaPos(TabellaPos,riga+1,colonna)==1){
			flag=0;
		}
	}
	//controllo in alto a destra se la cella è nei limiti
	if(riga-1>=0 && colonna+1<LeggereColonnePos(TabellaPos) && flag==1){
		//se nella cella selezionata vi è un pezzo di nave allora c'è una nave adiacente e quindi flag=0
		if(LeggereCellaPos(TabellaPos,riga-1,colonna+1)==1){
			flag=0;
		}
	}
	//controllo a destra se la cella è nei limiti
	if(colonna+1<LeggereColonnePos(TabellaPos) && flag==1){
		//se nella cella selezionata vi è un pezzo di nave allora c'è una nave adiacente e quindi flag=0
		if(LeggereCellaPos(TabellaPos,riga,colonna+1)==1){
			flag=0;
		}
	}
	//controllo in basso a destra se la cella è nei limiti
	if(riga+1<LeggereRighePos(TabellaPos) && colonna+1<LeggereColonnePos(TabellaPos) && flag==1){
		//se nella cella selezionata vi è un pezzo di nave allora c'è una nave adiacente e quindi flag=0
		if(LeggereCellaPos(TabellaPos,riga+1,colonna+1)==1){
			flag=0;
		}
	}
	return flag;
}

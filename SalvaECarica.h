#ifndef SALVAECARICA_H_
#define SALVAECARICA_H_

int SalvaPartita (char NomePlayer1[20], char NomePlayer2[20], BattleFieldPos TabellPos1, BattleFieldPos TabellaPos2, BattleFieldAtt TabellAtt1, BattleFieldAtt TabellaAtt2, Abilita ab1, Abilita ab2, char NomePartita[20],int turno);
/*funzione per memorizzare i dati della partita in un file che, su richiesta del giocatore, potranno essere caricati successivamente
NomePlayer1 - nome del giocatore 1
NomePlayer2 - nome del giocatore 2
TabellaPos1 - tabella dove sono presenti le navi del giocatore 1
TabellaPos2 - tabella dove sono presenti le navi del giocatore 2
TabellaAtt1 - tabella dove il giocatore 1 segnerà i punti colpiti
TabellaAtt2 - tabella dove il giocatore 2 segnerà i punti colpiti
ab1 - numero di abilità ancora a disposizione del giocatore 1
ab2 - numero di abilità ancora a disposizione del giocatore 2
turno - indica chi deve effettuare l'azione tra il 1 e 2 giocatore
NomePartita - indica il nome di come la partita debba essere salvata
*/


int CaricamentoPartita (char NomePlayer1[20], char NomePlayer2[20], BattleFieldPos TabellPos1, BattleFieldPos TabellaPos2, BattleFieldAtt TabellAtt1, BattleFieldAtt TabellaAtt2, Abilita ab1, Abilita ab2, int turno, char NomePartita[20]);
/*funzione che carica i dati della partita salvata precedentemente dall'utente

NomePlayer1 - nome del giocatore 1
NomePlayer2 - nome del giocatore 2
TabellaPos1 - tabella dove sono presenti le navi del giocatore 1
TabellaPos2 - tabella dove sono presenti le navi del giocatore 2
TabellaAtt1 - tabella dove il giocatore 1 segnerà i punti colpiti
TabellaAtt2 - tabella dove il giocatore 2 segnerà i punti colpiti
ab1 - numero di abilità ancora a disposizione del giocatore 1
ab2 - numero di abilità ancora a disposizione del giocatore 2
turno - indica chi deve effettuare l'azione tra il 1 e 2 giocatore
NomePartita - indica il nome della partita che deve essere caricata
*/


#endif /* SALVAECARICA_H_ */

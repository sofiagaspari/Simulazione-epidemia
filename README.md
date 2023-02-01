# Simulazione dell'evoluzione di un'epidemia 

Bonali Elena, Capano Giovanni Guido, Gaspari Sofia 

Il progetto studia l’espandersi di un’epidemia nel corso del tempo all’interno di una popolazione chiusa; esso si basa sul modello teorico SIR, dalle iniziali Suscettibili, Infetti e Rimossi. Il progetto, scritto in C++, è suddiviso in due parti: la prima riguarda l’implementazione del modello SIR e la seconda la simulazione grafica di un’epidemia tramite automa cellulare.  

# Come compilare, eseguire e testare il programma 

Per compilare ed eseguire il programma, all'interno della cartella simulation, i comandi sono: 

$ g++ -Wall -Wextra -fsanitize=address main.cpp epidemic.cpp board.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system 

$ ./main 

Fatto ciò, compariranno sul terminale alcune indicazioni; viene chiesto di inserire il numero di suscettibili, infetti e rimossi all’inizio della simulazione, i parametri beta β e gamma γ e i giorni di simulazione.  

Inseriti i valori, compare sul terminale una tabella con il numero dei suscettibili, infetti e rimossi giorno per giorno e si apre una finestra grafica la cui spiegazione dei colori è stampata sul terminale. 

Per testare il programma, all'interno della cartella tests, i comandi sono: 

$ g++ -Wall -Wextra -fsanitze=address test.cpp ../simulation/epidemic.cpp -o test 

$ ./test 

Un’altra modalità per compilare ed eseguire sia la simulazione sia i test è utilizzando CMake.

Prima di tutto bisogna creare una nuova directory build: 

$ mkdir build 

$ cd build 

$ cmake .. 

Poi per compilare: 

$ make sir       (per compilare la simulazione) 

$ make sir-test  (per compilare i test)

$ make           (per compilare entrambi)

Infine, per eseguire: 

$ ./sir          (per eseguire la simulazione)

$ ./sir-test     (per eseguire i test) 

 

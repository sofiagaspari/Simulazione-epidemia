# Simulazione dell'evoluzione di un'epidemia 

Bonali Elena, Capano Giovanni Guido, Gaspari Sofia 

Il progetto studia l’espandersi di un’epidemia nel corso del tempo all’interno di una popolazione chiusa; esso si basa sul modello teorico SIR, dalle iniziali Suscettibili, Infetti e Rimossi. Il progetto, scritto in C++, è suddiviso in due parti: la prima riguarda l’implementazione del modello SIR e la seconda la simulazione grafica di un’epidemia tramite automa cellulare. 

# Il modello SIR 

Il modello SIR divide l’intera popolazione in tre gruppi: i Suscettibili, cioè coloro che si possono infettare, gli Infetti, cioè gli ammalati e quelli che possono infettare e i Rimossi, i quali comprendono indistintamente i guariti o i deceduti, che non possono infettarsi e infettare. Il numero totale della popolazione N è costante e pari alla somma dei tre sottogruppi. Una persona può unicamente passare da suscettibile a infetto e da infetto a rimosso. 

Il modello si fonda su tre equazioni differenziali: 

dSdt=−βSNI
dSdt=−𝛽SNI
 
          
dIdt=βSNI−γI
dIdt=𝛽SNI−𝛾I
 
          
dRdt=γI
dRdt=𝛾I
 
 

Il parametro β ∈ [0,1] misura la probabilità di contagio in seguito a contatti tra infetti e suscettibili, il parametro γ ∈ [0,1] è la probabilità di guarigione (o morte) di un infetto ed è l'inverso del tempo medio di risoluzione dell'infezione. 

Nel progetto si utilizzano le precedenti equazioni differenziali discretizzate, considerando intervalli di tempo di una giornata: 

Si=Si−1 −βSi−1 N  
Si=Si−1 −𝛽Si−1 N  
 
          
Ii=Ii−1+βSi−1NIi−1−γ Ii−1
Ii=Ii−1+𝛽Si−1NIi−1−𝛾 Ii−1
 
         
 Ri=Ri−1+γ Ii−1
 Ri=Ri−1+𝛾 Ii−1
 
 

# Descrizione del progetto 

Il progetto è composto da cinque translation unit, due header file denominati “epidemic.hpp”, “board.hpp” e quattro source file dai nomi “epidemic.cpp”, “board.cpp”, “main.cpp” e “test.cpp”. 

epidemic.hpp  

In questo header file è dichiarata e definita la struct State, la quale raggruppa le tre variabili che rappresentano i sospetti, gli infetti e i rimossi. È presente, inoltre, la classe Epidemic, nella quale viene creato il vettore memory di tipo State, nel quale viene raccolto ogni giorno l’andamento dell’epidemia in termini di suscettibili, infetti e rimossi. Sono dichiarati i parametri del modello SIR beta e gamma, il numero di persone che compongono la popolazione (tot) e i giorni di diffusione dell’epidemia (days). Sempre all’interno della classe, nella parte pubblica, si dichiara il costruttore Epidemic e le cinque funzioni Evolve, Update, S_get, I_get ed R_get, che sono definiti nel file epidemic.cpp.  

epidemic.cpp 

La funzione Evolve implementa le tre equazioni differenziali alla base del modello SIR, discretizzandole; la funzione Update, successivamente, con un ciclo for aggiunge alla fine del vettore memory il risultato della funzione Evolve per ogni giorno della simulazione. Essendo il vettore memory all’interno della parte privata della classe, per rendere visibili i risultati precedenti si utilizzano le funzioni S_get, I_get ed R_get. Sono presenti, inoltre, degli assert che terminano il programma nel caso in cui i risultati della funzione Evolve diventino negativi a causa di un errato inserimento dei valori iniziali. 

test.cpp 

Nel file vengono testate la classe Epidemic e le funzioni Update, S_get, R_get e I_get. Per rendere possibile ciò, gli oggetti precedentemente inseriti nella sezione privata della classe Epidemic sono resi pubblici.  

board.hpp 

Viene definita una enum class Diag, che contiene tre char rappresentanti i tre stati di diagnosi previsti nel modello SIR. È stata poi creata una classe Board, contenente una serie di parametri privati, necessari per disegnare l’automa cellulare; mentre nella sezione pubblica sono dichiarati il costruttore della classe e quattro metodi. 

board.cpp 

Vengono qui definiti il costruttore Board e i quattro metodi. All’interno del costruttore vengono inizializzate le variabili private. Fra queste ultime, il vettore grid, che identifica la posizione di ciascuna cella sulla finestra grafica, viene inizializzato posizionando casualmente gli infetti e i rimossi, il cui numero iniziale è fornito da input. La funzione evolve gestisce l’evoluzione delle celle secondo alcune semplici regole: gli individui suscettibili contraggono la malattia con una probabilità beta se in una delle celle a loro adiacenti è presente almeno un infetto; gli infetti guariscono con una probabilità gamma, mentre i rimossi rimangono tali. Le probabilità sono gestite attraverso i metodi di Board return_beta e return_gamma, che compiono estrazioni su distribuzioni uniformi. Infine, il metodo Draw sfrutta le funzionalità di SFML per disegnare di volta in volta la griglia di celle, a partire dalle coordinate e dalle informazioni di diagnosi fornite da grid, modificato in loop da evolve. 

main.cpp 

La funzione main permette di inserire in input i valori iniziali necessari dei parametri (numero di suscettibili, d’infetti, di rimossi, beta, gamma e i giorni), stampa in output il contenuto del vettore memory giorno per giorno e apre la finestra grafica implementata nel file “board.cpp”. 

Avendo i parametri in input un determinato dominio, sono presenti delle exception per avvertire il fruitore del programma di un’errata scelta dei parametri iniziali.  

# Come compilare, eseguire e testare il programma 

Per compilare ed eseguire il programma i comandi sono: 

g++ -Wall -Wextra -fsanitize=address main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system 

./main 

Fatto ciò, compariranno sul terminale alcune indicazioni; viene chiesto di inserire il numero di suscettibili, infetti e rimossi all’inizio della simulazione, i parametri beta β e gamma γ e i giorni di simulazione.  

Inseriti i valori, compare sul terminale una tabella con il numero dei suscettibili, infetti e rimossi giorno per giorno e si apre una finestra grafica la cui spiegazione dei colori è stampata sul terminale. 

Per testare il programma i comandi sono: 

 

g++ -Wall -Wextra -fsanitze=address test.cpp -o test 

./test 

Un’altra modalità per compilare ed eseguire sia la simulazione sia i test è utilizzando CMake 

Prima di tutto bisogna creare una nuova directory build: 

mkdir build 

cd build 

cmake .. 

Poi per compilare: 

make sir       per compilare la simulazione 

make sir-test  per compilare i test 

make           per compilare entrambi 

Infine, per eseguire: 

./sir  per eseguire la simulazione 

./sir-test per eseguire i test 

 

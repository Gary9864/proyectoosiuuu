#include "header.h"
#include <iostream>
#include <fstream>
#include <conio.h>

// Variables globales
bool aventurasJugadas[3] = {false, false, false};
string premiosJugador[20];
int cantidadPremios = 0;
string nombreJugador;

// Aventuras definidas

//aventura uno

Aventura nerysia = {
   "Nerysia (Water World)",
    {
        // Level 1 – Coral Reef
        { "The pufferfish have found their home destroyed. They are furious and are attacking the octopus village.\nWhat weapon do you recommend using?",
          { 
              {"Their spines", "The fish get confused and stop attacking for a moment."},
              {"A sword", "The sword is useless underwater, you waste time."},
              {"The octopus ink", "The ink blinds them and they manage to escape in time."}
          },
          "Ancient Ink", 1 },

        // Level 2 – Eternal Algae Caves
        { "As you move through a cave covered in glowing algae, you hear a hypnotic singing. You realize it comes from dark mermaids trying to distract you to steal your life energy.",
          {
              {"You follow the singing, maybe it leads to a clue", "You get hypnotized and lose energy."},
              {"You cover your ears with algae", "You resist the song and move forward successfully."},
              {"You throw a stone toward the sound to distract them", "You confuse them and manage to escape unseen."}
          },
          "Luminous Pearl", 2 },

        // Level 3 – Abyssal Trench of Oblivion
        { "You reach an area so deep that light disappears. You find an old fish trapped in a black coral cage begging for help.",
          {
              {"You free it without asking", "It was a trap, the fish betrays you."},
              {"You ask questions before deciding", "The fish shows wisdom and gives you an ancient fragment."},
              {"You ignore it and move on", "You feel guilty, but avoid trouble."}
          },
          "Ancient Coral Fragment", 2 },

        // Level 4 – Fields of Wild Currents
        { "A violent current pulls you, and you must choose which creature to ally with to help you swim safely.",
          {
              {"A giant squid", "It helps you, but demands a favor in return."},
              {"A group of sea turtles", "They transport you calmly and safely."},
              {"A very fast lone dolphin", "You arrive quickly but get separated from the group."}
          },
          "Current Amulet", 2 },

        // Level 5 – The Palace of Corruption
        { "You reach the heart of darkness: a gigantic creature made of oil and shadows is corrupting the water.\nHow do you decide to face it?",
          {
              {"You use a sacred pearl you found on the way", "The creature weakens and retreats."},
              {"You summon all the creatures you helped before", "They fight with you and manage to contain it."},
              {"You use your own life energy as a last resort", "The creature disappears, but you're left badly injured."}
          },
          "Heart of Nerysia", 1 }
    }
    
};


//aventura dos
Aventura infernum = {
    "Infernum (Mundo de Fuego)",
    {
        {"Nivel 1 - Llanuras de ceniza: El suelo tiembla bajo tus pies, unos lagartos ígneos han comenzado a atacar caravanas de comerciantes de roca volcánica. ¿Que haces para salvar a los comerciantes?",
             {{"Tratas de hablar con los lagartos", "Los lagartos no entienden y se alteran aún más."},
              {"Les arrojas agua congelada", "Los lagartos se enfurecen y comienzan atacar a todos."},
              {"Los distraes con una antorcha brillante", "Los lagartos se confunden con la luz y se quedan quietos, salvando a los comerciantes."}},
        "Espada de lava", 2},

        {"Nivel 2 - Cañón del Trueno Ardiente: Encuentras una grieta con vapor envenenado que está afectando a los pájaros de lava. Algunos te rodean confundidos. ¿Que decision tomas para ayudar a los pajaros?",
             {{"Tapa la grieta con rocas", "La presión al taparla provoca una explosión y todos mueren." },
             {"Guias a los pájaros fuera del humo", "Salvas a los pajaros y te agradecen con un pan para recargar energias."},
             {"Los enfrentas, pensando que son hostiles", "Los pajaros te atacan."}},
        "corazon de fuego encantado", 1},

        {"Nivel 3 - Volcán Dormido: Subes a un volcán para investigar su energía. Descubres una grieta que lleva a una caverna secreta, pero está protegida por golems de magma. ¿Como accedes? a la caverna secreta?",
             {{"Imitas los movimientos de los golems", "Te confunden con uno de ellos y te dejan pasar."},
             {"Te camuflas con barro volcánico", "El barro te quema y mueres."},
             { "Esperas a que se duerman para pasar", "Te duermes y los golems te atrapan"}},
        "Cetro de magma", 0}, 

        {"Nivel 4 - Río de Lava Eterna: Para cruzar al siguiente territorio, debes atravesar un río de lava sobre plataformas que se derriten con el tiempo. ¿Como logras cruzar el rio?",
             {{"Un caparazón de escarabajo ignífugo", "Te proteges de la lava y cruzas sin problemas"},
             {"Saltar lo más rapido posible", "Te quemas porque no alcanzas a saltar."},
             {"Usar un fragmento de hielo antiguo para congelar partes de la lava", "El hielo se derrite muy rapido y caes al rio"}},
       "Escudo de roca volcanica", 0},

       {"Nivel 5 - Núcleo del Coloso Ardiente: En lo más profundo del mundo, te enfrentas al Coloso Ardiente, una criatura que parece hecha del núcleo del planeta. Está enloquecido. ¿Como derrotas al coloso?",
             {{"Usas un mineral especial que absorbe calor", "El mineral es muy debil y se derite."},
              {"Le haces recordar quién era antes con un artefacto antiguo", "El coloso se conmueve y se duerme en paz."},
              {"Intentas luchar contra el coloso", "El coloso es demasiado fuerte y te aplasta"}},
        "Amuleto del coloso", 1},
     }                  
};

Aventura thornia = {//declaramos el la aventura a la que vamos a añadirle datos
    "thornia (El mundo olvidado)",//nombre de la aventura como en la estructura pide
    {
//situación 1 (nivel 1)
        { "Despiertas en unas ruinas cubiertas de niebla y una estatua emite un sonido.", 
//decisión y consecuencia
          { {"Tocar la estatua", "Te paralisas unos segundos y pierdes tiempo."}, 
//decisión y consecuencia
            {"Tocar simbolo en forma de triangulo en la pared", "Aparece portal de luz ante ti."}, 
//decisión y consecuencia
            {"Caminar hacia la niebla", "Escuchas unos murmuros y te alejas."}
          },
//premio obtenido y opcion que te da ese premio
          "Escudo abismal", 1 },
//repetimos la estructura para los niveles siguientes
//todo esto es un ejemplo
        { "Sales de la cueva por el portal y encuentras una torre que susurra tus pensamientos sin sesar. ",
          { {"Te quedas en silencio. ", "No logras soportar la voz de tus pensamientos y pierdes cordura. "},
            {"Subes a la cima de la torre. ", "No encuentras nada y regresas. "},
            {"Investigas debajo de la torre acercandote a los susurros. ", "Encuentras entrada subterrania y un cofre. "}
          },
          "Hacha en mal estado", 2 },
        { "Al descender encuentras una sala con 3 estatuas encapuchadas con diferentes simbolos.",
          { {"Tocar primer estatua con un simbolo cuadrado. ", "Activas una trampa y no escapaste a tiempo. "},
            {"Tocar segunda estatua con un simbolo circular. ", "Aparece una neblina y terminas inconciente. "},
            {"Tocar tercera estatua con simbolo triangular. ", "La estatua se desplaza, tomas su capucha y se abre un camino con 3 puertas atras de ella. "}
          },
          "Capucha vieja. ", 2 },
        { "Sigues el camino y te encuentras una sala oscura llena de armas con escombros y simbolos en las paredes. ",
          { {"Investiga los escombros. ", "Al acercarte a los escombros encuentras un libro y se activan las runas con la capucha apareciendo una puerta . "},
            {"Vuelves a la sala anterior. ", "No logras nada. "},
            {"Investiga las armas. ", "Te tropiezas y te atraviesa una espada de forma humillante. "}
          },
          "Libro desconocido. ", 0 },
        { "Tras cruzar la puerta, entras en una cámara iluminada por cristales flotantes. En el centro, el Guardián del Olvido despierta de su letargo. Solo una acción puede debilitarlo para tener oportunidad de vencerlo.",
          { {"Atacar directamente con el hacha. ", "El guardián bloquea tu ataque y te lanza contra la pared, dejándote herido."},
            {"Leer en voz alta la inscripción del libro desconocido. ", "La sala tiembla. El guardián parece debilitado y tambalea, pero sigue en pie."},
            {"Cubrirte con la capucha vieja.", "La capucha se quema al contacto con la energía del guardián y quedas desprotegido."}
          },
          "Totem de inmortalidad", 1 }
}
};


// Funciones

//agrega premio segun gane
void agregarPremio(string premio) {
    if (cantidadPremios < 20) {//si la cantidad es menor a 20 premios
        premiosJugador[cantidadPremios++] = premio; //se guarda en el arreglo sumando los premios
    }
}
//muestra los premios que ha obtenido
void mostrarPremios() {
    cout << "\n--- Premios obtenidos ---\n";
    if (cantidadPremios == 0) {//si la cantidad de premios es igual a cero muestra el mensaje
        cout << "No tienes premios aún.\n";
    } else {
        for (int i = 0; i < cantidadPremios; i++) { //si tiene premio entonces se recorre el arreglo y se muestran los premio ganados
            cout << i + 1 << ". " << premiosJugador[i] << "\n";
        }
    }
    cout << endl;
}
//guardar progresoo
void guardarProgreso() {
    ofstream archivo("src./progreso.txt");
    if (archivo.is_open()) {
        archivo << nombreJugador << endl;
        
        // Contar cuántas aventuras jugó
        int totalAventuras = 0;
        for (int i = 0; i < 3; i++) {
            if (aventurasJugadas[i]) {
                totalAventuras++;
            }
        }
        archivo << totalAventuras << endl;

        // Guardar nombres de aventuras jugadas
        if (aventurasJugadas[0]) archivo << "Nerysia (Mundo de Agua)" << endl;
        if (aventurasJugadas[1]) archivo << "Infernum (Mundo de Fuego)" << endl;
        if (aventurasJugadas[2]) archivo << "thornia (El mundo olvidado)" << endl;

        // Guardar premios
        archivo << cantidadPremios << endl;
        for (int i = 0; i < cantidadPremios; i++) {
            archivo << premiosJugador[i] << endl;
        }

        archivo.close();
        cout << "\nProgreso guardado exitosamente.\n";
    } else {
        cout << "No se pudo abrir el archivo para guardar.\n";
    }
}//mostrar progreso
void mostrarProgreso() {
    ifstream archivo("src/progreso.txt");
    if (archivo.is_open()) {
        string linea;
        getline(archivo, nombreJugador);
        cout << "\nNombre: " << nombreJugador << endl;

        getline(archivo, linea);
        int aventuras = stoi(linea);
        cout << "Aventuras jugadas: " << aventuras << endl;

        cout << "\n--- Aventuras jugadas ---\n";
        for (int i = 0; i < aventuras; i++) {
            getline(archivo, linea);
            cout << i + 1 << ". " << linea << endl;
        }

        getline(archivo, linea);
        cantidadPremios = stoi(linea);

        cout << "\n--- Premios obtenidos ---\n";
        if (cantidadPremios == 0) {
            cout << "No tienes premios aún.\n";
        } else {
            for (int i = 0; i < cantidadPremios; i++) {
                getline(archivo, premiosJugador[i]);
                cout << i + 1 << ". " << premiosJugador[i] << endl;
            }
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para leer el progreso.\n";
    }
}

//añadiendo minijuegos mamalones
//minijuego 1 uno 
void minijuegoMemoria() {
    char tablero[2][2] = {{'A', 'B'}, {'B', 'A'}};
    char visible[2][2] = {{'*', '*'}, {'*', '*'}};

    int f1, c1, f2, c2;

    cout << "\n--- Minijuego de Memoria (versión fija) ---\n";
    cout << "Encuentra el par igual para ganar un premio.\n";

    do {
        // Mostrar tablero visible
        cout << "  0 1\n";
        for (int i = 0; i < 2; i++) {
            cout << i << " ";
            for (int j = 0; j < 2; j++) {
                cout << visible[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Selecciona primera carta (fila y columna): ";
        cin >> f1 >> c1;
        cout << "Selecciona segunda carta (fila y columna): ";
        cin >> f2 >> c2;

        // Mostrar temporalmente
        visible[f1][c1] = tablero[f1][c1];
        visible[f2][c2] = tablero[f2][c2];

        cout << "\nTablero actualizado:\n";
        cout << "  0 1\n";
        for (int i = 0; i < 2; i++) {
            cout << i << " ";
            for (int j = 0; j < 2; j++) {
                cout << visible[i][j] << " ";
            }
            cout << endl;
        }

        if (tablero[f1][c1] == tablero[f2][c2]) {
            cout << "¡Encontraste el par!\n";
            break;
        } else {
            cout << "No son iguales, intenta de nuevo.\n";
            visible[f1][c1] = '*';
            visible[f2][c2] = '*';
        }
    } while (true);

    cout << "Minijuego terminado.\n";
}

//minijuego 2 
void minijuegoTesoro() {
    char tablero[3][3] = {
        {' ', ' ', ' '},
        {' ', 'T', ' '},
        {' ', ' ', ' '}
    };

    int fila, col;

    cout << "\n--- Minijuego: Busca el Tesoro ---\n";
    cout << "Encuentra el tesoro escondido en la matriz 3x3.\n";

    do {
        // Mostrar tablero
        cout << "  0 1 2\n";
        for (int i = 0; i < 3; i++) {
            cout << i << " ";
            for (int j = 0; j < 3; j++) {
                cout << "* ";
            }
            cout << endl;
        }

        cout << "Elige fila (0-2): ";
        cin >> fila;
        cout << "Elige columna (0-2): ";
        cin >> col;

        if (tablero[fila][col] == 'T') {
            cout << "¡Encontraste el tesoro!\n";
            break;
        } else {
            cout << "Nada aquí. Sigue buscando.\n";
        }
    } while (true);

    cout << "Minijuego terminado.\n";
} 
//minijeugo  3 q dislexia dios mio

void minijuegoSimon() {
    char secuencia[3] = {'A', 'B', 'C'};
    char respuesta[3];

    cout << "\n--- Minijuego: Simón Dice ---\n";
    cout << "Memoriza esta secuencia: A B C\n";

    // Mostrar la secuencia
    cout << "Presiona enter cuando estés listo...";
    cin.ignore();
    cin.get();

    // Borrar pantalla (opcional, puedes pedir al jugador que no mire)
    for (int i = 0; i < 20; i++) cout << endl;

    cout << "Ingresa la secuencia (3 letras): \n";
    for (int i = 0; i < 3; i++) {
        cout << "Letra " << i + 1 << ": ";
        cin >> respuesta[i];
    }

    bool correcto = true;
    for (int i = 0; i < 3; i++) {
        if (respuesta[i] != secuencia[i]) {
            correcto = false;
            break;
        }
    }

    if (correcto) {
        cout << "¡Correcto! Superaste el reto.\n";
    } else {
        cout << "¡Secuencia incorrecta! Fallaste.\n";
    }

    cout << "Minijuego terminado.\n";
}

//minijuego 3

void minijuegoContar() {
    char tablero[4][4] = {
        {'O', 'X', 'O', ' '},
        {' ', 'O', ' ', 'X'},
        {'X', ' ', 'O', ' '},
        {' ', 'X', ' ', 'O'}
    };

    int contador = 0;

    cout << "\n--- Minijuego: Cuenta las O ---\n";

    // Mostrar tablero
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }

    cout << "¿Cuántas 'O' hay en el tablero? ";
    int respuesta;
    cin >> respuesta;

    // Contar las O
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (tablero[i][j] == 'O')
                contador++;

    if (respuesta == contador) {
        cout << "¡Correcto! Contaste bien.\n";
    } else {
        cout << "¡Incorrecto! Había " << contador << " O.\n";
    }

    cout << "Minijuego terminado.\n";
}
string minijuegoDuelo() {
    char runas[5] = {'A', 'S', 'D', 'F', 'J'};
    int posicion = 0;

    cout << "\n--- Minijuego: Duelo de Runas ---\n";
    cout << "Instrucciones: se mostrará una letra (A, S, D, F o J).\n";
    cout << "Presiona esa tecla. 4 aciertos = victoria, 2 fallos = reinicio.\n";

    while (true) { // Repetir hasta que gane
        int aciertos = 0;
        int fallos = 0;
        posicion = 0;

        while (aciertos < 4 && fallos < 2) {
            char runa = runas[posicion];
            posicion = (posicion + 1) % 5;

            cout << "\nRuna enemiga: " << runa << "\n";
            char tecla;
             // VALIDACIÓN: repetir hasta que no meta un número
            while (true) {
                cout << "Presiona la tecla correcta: ";
                tecla = _getch();
                cout << tecla << endl;

                if (tecla >= '0' && tecla <= '9') {
                    cout << "No puedes usar números. Intenta de nuevo.\n";
                } else {
                    break;  // Sale del while si no es número
                }
            }

            if (tecla == runa || tecla == runa + 32) {
                cout << "¡Correcto!\n";
                aciertos++;
            } else {
                cout << "¡Fallaste!\n";
                fallos++;
            }

            cout << "Aciertos: " << aciertos << " | Fallos: " << fallos << "\n";
        }

        if (aciertos == 4) {
            cout << "\n ¡Has ganado el duelo de runas!\n";
            return "";
        } else {
            cout << "\n Has fallado... el duelo comienza de nuevo.\n";
        }
    }
}
//minijuego neryrisia para nivel 2

void minijuegoPesca() {
    int x = rand() % 3;
    int y = rand() % 3;

    int intentoX, intentoY;
    string entrada;

    cout << "\n--- Minijuego: Pesca en Aguas Cristalinas ---\n";
    cout << "Adivina en qué punto (x, y) está el pez (valores entre 0 y 2):\n";

    // Validar X
    while (true) {
        cout << "Ingresa coordenada X: ";
        cin >> entrada;

        bool esNumero = true;
        for (char c : entrada) {
            if (!isdigit(c)) {
                esNumero = false;
                break;
            }
        }

        if (esNumero) {
            intentoX = stoi(entrada);
            if (intentoX >= 0 && intentoX <= 2) break;
        }

        cout << "Entrada inválida. Ingresa un número entre 0 y 2.\n";
    }

    // Validar Y
    while (true) {
        cout << "Ingresa coordenada Y: ";
        cin >> entrada;

        bool esNumero = true;
        for (char c : entrada) {
            if (!isdigit(c)) {
                esNumero = false;
                break;
            }
        }

        if (esNumero) {
            intentoY = stoi(entrada);
            if (intentoY >= 0 && intentoY <= 2) break;
        }

        cout << "Entrada inválida. Ingresa un número entre 0 y 2.\n";
    }

    if (intentoX == x && intentoY == y) {
        cout << "¡Pescaste al pez dorado!\n";
    } else {
        cout << "Nada aquí... El pez estaba en (" << x << ", " << y << ")\n";
    }

    cout << "Minijuego terminado.\n";
}



// Minijuego Nerysia para nivel 4
void minijuegoObjetosPerdidos() {
    char objetos[5] = {'F', 'R', 'F', 'L', 'T'}; // 'F' se repite
    char respuesta;

    cout << "\n--- Minijuego: Objetos Perdidos ---\n";
    cout << "Observa los objetos: ";
    for (int i = 0; i < 5; i++) cout << objetos[i] << " ";
    cout << "\nUno de ellos está repetido. ¿Cuál es? ";

    bool correcto = false;
    while (!correcto) {
        cin >> respuesta;

        // Validar si es letra
        if ((respuesta >= 'A' && respuesta <= 'Z') || (respuesta >= 'a' && respuesta <= 'z')) {
            // Verificar si es la correcta
            if (respuesta == 'F' || respuesta == 'f') {
                correcto = true;
            } else {
                cout << "Incorrecto. Intenta de nuevo: ";
            }
        } else {
            cout << "Entrada inválida. Ingresa solo UNA letra (A-Z): ";
        }
    }

    // Cuando sale del ciclo, significa que ya dio la correcta
    cout << "¡Correcto! El objeto duplicado era F.\n";
    cout << "Minijuego terminado.\n";
}

void abrirCofre() {
    const int clave[3] = {3, 1, 5}; // combinación secreta
    int intento[3];
    bool abierto = false;

    cout << "====== DESAFÍO DEL COFRE SELLADO ======\n";
    cout << "Encuentra la combinación secreta de 3 dígitos (0-9).\n";
    cout << "Recibirás pistas después de cada intento.\n";
    cout << "Buena suerte, valiente jugador.\n";

    while (!abierto) {
        // --- Entrada del jugador ---
        cout << "Introduce tu intento (3 números entre 0 y 9): ";
        cin >> intento[0] >> intento[1] >> intento[2];

        // Validación de entrada
        while (intento[0] < 0 || intento[0] > 9 ||
               intento[1] < 0 || intento[1] > 9 ||
               intento[2] < 0 || intento[2] > 9) {
            cout << "Error: Todos los números deben estar entre 0 y 9.\n";
            cout << "Vuelve a intentarlo: ";
            cin >> intento[0] >> intento[1] >> intento[2];
        }

        // --- Evaluación del intento ---
        int correctos = 0;
        int desordenados = 0;
        bool usadoClave[3] = {false, false, false};
        bool usadoIntento[3] = {false, false, false};

        // Comparar en posición exacta
        for (int i = 0; i < 3; i++) {
            if (intento[i] == clave[i]) {
                correctos++;
                usadoClave[i] = true;
                usadoIntento[i] = true;
            }
        }

        // Comparar en posiciones diferentes
        for (int i = 0; i < 3; i++) {
            if (!usadoIntento[i]) {
                for (int j = 0; j < 3; j++) {
                    if (!usadoClave[j] && intento[i] == clave[j]) {
                        desordenados++;
                        usadoClave[j] = true;
                        break;
                    }
                }
            }
        }

        // --- Resultado del intento ---
        if (correctos == 3) {
            cout << "\nPerfecto has adivinado la combinación perfecta.\n";
            cout << "El cofre se abre y revela un objeto en el fondo.\n";
            abierto = true;
        } else {
            cout << "\nPistas del intento:\n";
            cout << " - Números en posición correcta: " << correctos << "\n";
            cout << " - Números correctos pero en otra posición: " << desordenados << "\n";
            cout << "Sigue intentando...\n";
        }

        cout << "----------------------------------------\n";
    }
}
void elegirPuerta() {
    int eleccion;
    const int puertaCorrecta = 2; // esta es la puerta correcta
    bool paso = false;

    cout << "================ PUERTAS DEL DESTINO ================\n";
    cout << "Estás frente a 3 puertas misteriosas...\n";
    cout << "Solo una de ellas te dejará continuar.\n";
    cout << "Elige sabiamente (puerta 1, 2 o 3).\n\n";

    while (!paso) {
        cout << "Elige una puerta (1, 2 o 3): ";
        cin >> eleccion;

        // Validación de entrada
        while (eleccion < 1 || eleccion > 3) {
            cout << "Esa no es una puerta válida. Intenta con 1, 2 o 3: ";
            cin >> eleccion;
        }

        // Evaluar elección
        if (eleccion == puertaCorrecta) {
            cout << "\n Correcto la puerta se abre con un chirrillo antiguo...\n";
            cout << "Pasas al siguiente nivel del misterio. \n";
            paso = true;
        } else {
            cout << "\nEsa puerta está sellada. Un murmullo oscuro te detiene.\n";
            cout << "Intenta con otra puerta...\n";
        }

        cout << "-----------------------------------------------------\n";
    }
}


// Configuraciones de minijuegos para cada aventura
ConfigMinijuegos obtenerConfigNerysia() {
    return ConfigMinijuegos{
        {false, true, false, true, false}, // niveles con minijuego
        {0, 7, 0, 6, 0}                   // tipo de minijuego: 1 = Tesoro, 3 = Contar
    };
}

ConfigMinijuegos obtenerConfigInfernum() {
    return ConfigMinijuegos{
        {true, false, false, true, false},
        {2, 0, 0, 4, 0}  // 2 = Simon, 4 = otro
    };
}

ConfigMinijuegos obtenerConfigThornia() {
    return ConfigMinijuegos{
        {false, true, true, false, true},
        {0, 8, 9, 0, 5}
    };
}

//jugar nivel de aventura
bool jugarNivel(const Nivel& nivel, const ConfigMinijuegos& config, int indiceNivel) {
    cout << "\nSituacion: " << nivel.situacion << "\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << nivel.decisiones[i].texto << "\n";
    }
 string entrada;
    int opcion;
    do {
        cout << "Elige una opcion: ";
        cin >> entrada;
        bool esNumero = true;
        for (char c : entrada) {
            if (c < '0' || c > '9') {
                esNumero = false;
                break;
            }
        }
if (!esNumero) {
            cout << "Entrada invalida. Debes ingresar solo números.\n";
            continue;
        }
                opcion = stoi(entrada);

        if (opcion < 1 || opcion > 3) {
            cout << "Opcion invalida. Intenta de nuevo con 1 2 3.\n";
        }
    } while (opcion < 1 || opcion > 3);

    cout << "\n" << nivel.decisiones[opcion - 1].consecuencia << "\n";

    if ((opcion - 1) == nivel.opcionGanadora) {
        // Primero jugar minijuego si existe
        if (config.activar[indiceNivel]) {
            switch (config.tipo[indiceNivel]) {
                case 1: minijuegoTesoro(); break;
                case 2: minijuegoSimon(); break;
                case 3: minijuegoContar(); break;
                case 4: minijuegoMemoria(); break;
                case 5: minijuegoDuelo(); break;
                case 6: minijuegoPesca(); break;
                case 7: minijuegoObjetosPerdidos(); break;
                case 8: abrirCofre(); break;
                case 9: elegirPuerta(); break;
                default: break;
            }
        }
        
        // Ahora mostrar y agregar premio
        cout << "¡Ganaste el premio: " << nivel.premio << "!\n";
        agregarPremio(nivel.premio);

        return true;  //  Pasó el nivel
    } else {
                cout << "Opción incorrecta. ¡Debes intentarlo de nuevo!\n";

        return false; //  Repetir nivel
}
}
//funcion de jugar aventura 
void jugarAventura(const Aventura& aventura, const ConfigMinijuegos& config) {
    cout << "\n--- Bienvenido a " << aventura.nombre << " ---\n";
    for (int i = 0; i < 5; i++) { //recorremos el arreglo de la funcion 
        cout << "\n--- Nivel " << i + 1 << " ---";
        bool pasoNivel = false;
        do {
            pasoNivel = jugarNivel(aventura.niveles[i], config, i);
        } while (!pasoNivel); // 🔁 Repite hasta que el jugador acierte
       // jugarNivel(aventura.niveles[i]);
      // jugarNivel(aventura.niveles[i], config, i); // ✅ Pasas config y el índice actual

      
    }
    cout << "\n¡Has completado la aventura!\n";
    
}

//ConfigMinijuegos config;  // variable global en def.cpp

void intentarJugarAventura(const Aventura& aventura, int indiceAventura, const ConfigMinijuegos& config) {
    if (indiceAventura < 0 || indiceAventura >= 3) {
        cout << "Indice de aventura invalido.\n";
        return;
    }
    if (aventurasJugadas[indiceAventura]) {
        cout << "\nYa jugaste la aventura \"" << aventura.nombre << "\" anteriormente.\n";
    } else {
     
        jugarAventura(aventura, config);
        aventurasJugadas[indiceAventura] = true;
    }
}
void introduccionJuego() {
    cout << "Antes de comenzar, dime tu nombre: ";
   do{
     cin >> nombreJugador;
     bool soloLetras = true;
     for (char c : nombreJugador){
        if (c >= '0' && c <= '9'){
            soloLetras = false;
            break;
        }
     }
     if (soloLetras) break;
     else cout << "El nombre no puede contener numeros. Intenta de nuevo: ";
} while (true);
}
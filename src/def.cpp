#include "header.h"
#include <iostream>
#include <fstream>

// Variables globales
bool aventurasJugadas[3] = {false, false, false};
string premiosJugador[20];
int cantidadPremios = 0;
string nombreJugador;

// Aventuras definidas

//aventura uno
Aventura nerysia = {
    "Nerysia (Mundo de Agua)",
    
    
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
          "Escudo abismal", 2 },
//repetimos la estructura para los niveles siguientes
//todo esto es un ejemplo
        { "Sales de la cueva por el portal y encuentras una torre que susurra tus pensamientos sin sesar. ",
          { {"Te quedas en silencio. ", "No logras soportar la voz de tus pensamientos y pierdes cordura. "},
            {"Subes a la cima de la torre. ", "No encuentras nada y regresas. "},
            {"Investigas debajo de la torre acercandote a los susurros. ", "Encuentras entrada subterrania y un cofre. "}
          },
          "Hacha en mal estado", 3 },
        { "Al descender encuentras una sala con 3 estatuas encapuchadas con diferentes simbolos.",
          { {"Tocar primer estatua con un simbolo cuadrado. ", "Activas una trampa y no escapaste a tiempo. "},
            {"Tocar segunda estatua con un simbolo circular. ", "Aparece una neblina y terminas inconciente. "},
            {"Tocar tercera estatua con simbolo triangular. ", "La estatua se desplaza y abre un camino atras de ella y te llevas su capucha. "}
          },
          "Capucha vieja. ", 3 },
        { "Sigues el camino y te encuentras una sala oscura llena de armas con escombros y puerta con simbolos en las paredes. ",
          { {"Investiga los escombros. ", "Encuentras un libro en otro idioma. "},
            {"Fuerzas la puerta con el escudo. ", "No logras nada. "},
            {"Investigas los simbolos en las paredes. ", "Reaccionan con la capucha y se abre ante ti la puerta. "}
          },
          "Libro desconocido. ", 3 },
        { "Continuara.",
          { {"Pelea o algo", "sigilo."},
            {"atributos", "ganas un arma ."},
            {"Escapar con un artefacto robado", "Obtienes una maldicion."}
          },
          "maldicion", 0 }// no le pongan atencion al ultimo lo puse por poner falta plantear
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
// Configuraciones de minijuegos para cada aventura
ConfigMinijuegos obtenerConfigNerysia() {
    return ConfigMinijuegos{
        {false, true, false, false, true}, // niveles con minijuego
        {1, 0, 0, 0, 3}                   // tipo de minijuego: 1 = Tesoro, 3 = Contar
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
        {false, false, false, false, false},
        {0, 0, 0, 0, 0}
    };
}

//jugar nivel de aventura
void jugarNivel(const Nivel& nivel, const ConfigMinijuegos& config, int indiceNivel) {
    cout << "\nSituacion: " << nivel.situacion << "\n";
    for (int i = 0; i < 3; i++) { //si los niveles son menores a 3
        cout << i + 1 << ". " << nivel.decisiones[i].texto << "\n"; //manda el arreglo de decisiones
    }

    int opcion;//declaramos un entero para la opcion de las decisiones
    do {
        cout << "Elige una opcion: ";
        cin >> opcion;
        if (opcion < 1 || opcion > 3) { //una condicional que elija solamente entre la opcion  1 a 3
            cout << "Opcion invalida. Intenta de nuevo.\n";
        }
    } while (opcion < 1 || opcion > 3); //todo eso lo hara mientras sean esas opciones

    cout << "\n" << nivel.decisiones[opcion - 1].consecuencia << "\n"; //mostramos el arreglo de opciones -1 y la consecuencia que es correspndiente

    if ((opcion - 1) == nivel.opcionGanadora) { //si la opcion que eligio es igual a la opcion ganadora muestra el mensaje
        cout << "¡Ganaste el premio: " << nivel.premio << "!\n";
        agregarPremio(nivel.premio); // agregamos premio al arreglo
        if (config.activar[indiceNivel]) {
            switch (config.tipo[indiceNivel]) {
                case 1: minijuegoTesoro(); break;
                case 2: minijuegoSimon(); break;
                case 3: minijuegoContar(); break;
                case 4: minijuegoMemoria(); break;
                default: break; // ningún minijuego
            }
        }
    } else {
        cout << "Sobreviviste, pero sin premio.\n";
    }
}
//funcion de jugar aventura 
void jugarAventura(const Aventura& aventura, const ConfigMinijuegos& config) {
    cout << "\n--- Bienvenido a " << aventura.nombre << " ---\n";
    for (int i = 0; i < 5; i++) { //recorremos el arreglo de la funcion 
        cout << "\n--- Nivel " << i + 1 << " ---";
       // jugarNivel(aventura.niveles[i]);
       jugarNivel(aventura.niveles[i], config, i); // ✅ Pasas config y el índice actual

      
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
    cin >> nombreJugador;
    cout << "\nMuy bien, " << nombreJugador << ". Preparate para tu destino...\n";
}
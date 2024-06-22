//Author: Jean Valencia
//fecha: 202-06-20
/*
4) Diseñe el programa que permita generar 3 cartas aleatorias, con las siguientes consideraciones:
- Se puede comenzar a jugar, si luego de generar las 3 cartas, las 3 son diferentes, es decir, si salen, 
por ejemplo dos cartas K de brillo, no se puede continuar. 
- El jugador gana si la sumatoria de sus cartas es 21. La carta A se la considera como 1, las cartas J, Q, K 
se las considera como 10.
- Si al generar las 3 primeras cartas el jugador no ha ganado, tiene la posibilidad de cambiar hasta 2 cartas.
   Se debe preguntar al usuario: Cuántas cartas desea cambiar 1 o 2?
    Luego de este cambio se vuelven a sumar y si suman 21 , ya hay ganador. También gana cuando salen 3 cartas 
    iguales. Por ejemplo  A de brillo, A de trébol, A de corazón.
- Después de cada partida, debe preguntar al usuario: Desea seguir Jugando (S/N) ?
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

const vector<string> PALOS = {"♥", "♦", "♣", "♠"};
const vector<string> VALORES = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

struct Carta {
    string valor;
    string palo;
};

int valorCarta(const string& valor) {
    if (valor == "A") return 1;
    if (valor == "J" || valor == "Q" || valor == "K") return 10;
    return stoi(valor);
}

Carta generarCarta() {
    Carta carta;
    carta.valor = VALORES[rand() % VALORES.size()];
    carta.palo = PALOS[rand() % PALOS.size()];
    return carta;
}

bool cartasDiferentes(const vector<Carta>& cartas) {
    for (size_t i = 0; i < cartas.size(); ++i) {
        for (size_t j = i + 1; j < cartas.size(); ++j) {
            if (cartas[i].valor == cartas[j].valor && cartas[i].palo == cartas[j].palo) {
                return false;
            }
        }
    }
    return true;
}

bool cartasIguales(const vector<Carta>& cartas) {
    return cartas[0].valor == cartas[1].valor && cartas[1].valor == cartas[2].valor;
}

int sumarCartas(const vector<Carta>& cartas) {
    int suma = 0;
    for (const auto& carta : cartas) {
        suma += valorCarta(carta.valor);
    }
    return suma;
}

void impcrt(string ncarta1="",string nsimbolo1=""){
    cout<<"╔════════════╗ "<<endl;
    cout<<"║        "<<nsimbolo1<<ncarta1<<"  ║ "<<endl;
    cout<<"║            ║ "<<endl;
    cout<<"║            ║ "<<endl;
    cout<<"║     "<<ncarta1<<"      ║ "<<endl;
    cout<<"║            ║ "<<endl;
    cout<<"║            ║ "<<endl;
    cout<<"║ "<<nsimbolo1<<ncarta1<<"         ║ "<<endl;
    cout<<"╚════════════╝ "<<endl;
}

void imprimirCartas(const vector<Carta>& cartas) {
    for (const auto& carta : cartas) {
        impcrt(carta.valor,carta.palo);
    }
}


int main() {
    srand(time(0));
    char continuar = 'S';
    while (continuar == 'S' || continuar == 's') {
        vector<Carta> cartas;
        // Generar 3 cartas diferentes
        do {
            cartas.clear();
            for (int i = 0; i < 3; ++i) {
                cartas.push_back(generarCarta());
            }
        } while (!cartasDiferentes(cartas));
        cout << "Tus cartas iniciales son:\n";
        imprimirCartas(cartas);
        // Verificar si el jugador ganó con las primeras 3 cartas
        if (sumarCartas(cartas) == 21 || cartasIguales(cartas)) {
            cout << "¡Has ganado con las cartas iniciales!\n";
        } else {
            // Permitir al jugador cambiar cartas
            int cambios;
            cout << "No has ganado con las cartas iniciales. ¿Cuántas cartas deseas cambiar (1 o 2)? ";
            cin >> cambios;
            for (int i = 0; i < cambios; ++i) {
                int indice;
                cout << "¿Qué posición de carta deseas cambiar (1, 2 o 3)? ";
                cin >> indice;
                cartas[indice - 1] = generarCarta();
            }
            cout << "Tus nuevas cartas son:\n";
            imprimirCartas(cartas);
            // Verificar si el jugador ganó después de cambiar cartas
            if (sumarCartas(cartas) == 21 || cartasIguales(cartas)) {
                cout << "¡Has ganado con las nuevas cartas!\n";
            } else {
                cout << "No has ganado.\n";
            }
        }
        // Preguntar si el jugador quiere seguir jugando
        cout << "¿Deseas seguir jugando (S/N)? ";
        cin >> continuar;
    }

    return 0;
}

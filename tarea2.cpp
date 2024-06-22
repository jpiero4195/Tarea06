//Author: Jean Valencia
//fecha: 202-06-20
/*
Una función recibe como parámetro un entero que indica las filas de una figura. 
Adicionalmente, recibe como parámetro un string que indica el relleno de la figura a dibujar. 
Por ejemplo, si filas es 4 y el relleno es '+', la figura sería:
+
++
+++
++++
*/

#include <iostream>
#include <string>
using namespace std;

void otradibujarfig(int num, string& figura) {
    for (int k=1;k<=num;++k) {
        string linea(k, figura[0]);
        cout<<linea<<endl;
    }
}

void dibujarfig(int filas, string figura) {
    for (int k=1;k<=filas;++k) {
        for (int l=0;l<k;++l) {
            cout<<figura;
        }
        cout<<endl;
    }
}

int main() {
    int num;
    string figura;
    cout<<"Ingrese el número de filas: ";
    cin>>num;
    cout<<"Ingrese que relleno se pondrán en las filas: ";
    cin>>figura;
    dibujarfig(num, figura);
    return 0;
}
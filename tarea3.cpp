//Author: Jean Valencia
//fecha: 202-06-20
/*
Una función recibe 3 números enteros. La función devuelve verdadero si uno de esos números es la suma de los otros 2.
*/
#include <iostream>
using namespace std;

bool sumadetodos(int a, int b, int c) {
    return (a == b + c) || (b == a + c) || (c == a + b);
}

int main() {
    int x, y, z;
    cout << "Ingrese tres números enteros seperado por espacio: ";
    cin >> x >> y >> z;
    if (sumadetodos(x, y, z)) {
        cout<<"Verdadero"<<endl;
    } else {
        cout<<"falso"<<endl;
    }
    return 0;
}

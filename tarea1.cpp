//Author: Jean Valencia
//fecha: 202-06-20
/*
1) Diseñe la función que calcule el resultado de la ecuación cuadrática.
La función debe retornar un string:
- Cuando a vale 0, debe devolver "Error, división por cero"
- Cuando el discriminante es negativo, debe devolver "No se puede calcular la raíz cuadrada de un número negativo"
- Si la ecuación no tiene errores, debe devolver "Correcto". 
- Recuerde que el tipo string(cadena de caracteres) se escribe entre comillas.
Además, los resultados x1 y  x2 se devuelven como referencias.
x1=(-b + raiz(b*b -4*a*c)) /(2*a)
x2=(-b + sqrt(b*b -4*a*c)) /(2*a)
*/

#include <iostream>
#include <math.h>
using namespace std;

//Ejemplo de paso de parámetros por referencia
string ecuacioncuadratica(double a,double b,double c, double &x1, double &x2){
    if(a==0){return "Error, división por cero";}//divicion por 0
    //cálculo del descriminante
    double d= (b*b) - (4*a*c);
    if(d<0){return "No se puede calcular la raíz cuadrada de un número negativo";}//raiz cuadrada negativa
    //calcular x1 y x2
    x1=(-b + sqrt(d)) /(2*a);
    x2=(-b + sqrt(d)) /(2*a);
    return "Correcto";//ecuación correcta
}

int main(){
    double x1, x2;
    cout<<ecuacioncuadratica(1,-4,4,x1,x2);
    return 0;
}
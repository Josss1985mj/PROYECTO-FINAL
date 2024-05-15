#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    int arregloNotas[5];
    string arregloNombres[5];
    vector<int> vectorNotas;
    int suma = 0;
    ofstream ArchivoSalida;

    // Abrir el archivo de salida
    ArchivoSalida.open("listado.txt");

    // Ciclo para llenar el arreglo de nombres y notas
    for (int i = 0; i < 5; i++)
    {
        cout << "Ingrese el nombre del estudiante No. " << i + 1 << ": ";
        cin >> arregloNombres[i];
        cout << "Ingrese la nota del estudiante No. " << i + 1 << ": ";
        cin >> arregloNotas[i];
        suma += arregloNotas[i];
    }

    // Inserción de los valores en orden inverso
    for (int i = 4; i >= 0; i--)
    {
        vectorNotas.push_back(arregloNotas[i]);
    }

    // Mostrar los nombres y las notas en el orden de ingreso
    cout << "\nNombres y Notas (Orden de ingreso):\n";
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << arregloNombres[i] << " - " << arregloNotas[i] << endl;
        // Escribir en el archivo de salida
        ArchivoSalida << i + 1 << ". " << arregloNombres[i] << " - " << arregloNotas[i] << endl;
    }

    // Mostrar los nombres y las notas en orden inverso
    cout << "\nNombres y Notas (Orden inverso):\n";
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << arregloNombres[i] << " - " << vectorNotas[i] << endl;
    }

    // Calcular y mostrar el promedio de las notas
    cout << "\nEl promedio de las notas es de: " << suma / 5 << endl;
    // Escribir en el archivo de salida
    ArchivoSalida << "-------------------------------------------------------" << endl;
    ArchivoSalida << "El promedio de las notas es de: " << suma / 5 << endl;

    // Cerrar el archivo de salida
    ArchivoSalida.close();

    return 0;
}

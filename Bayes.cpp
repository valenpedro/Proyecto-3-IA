#include <iomanip> // Para el formato de impresión
#include <iostream>
#include <vector>
using namespace std;

// Definir estructura
struct Tabla {
  int cantiVariables;
  vector<float> probabilidad;
  vector<string> atributosTabla;
  string nombre;
};

int main() {
  int x;

  cout << "Ingrese la cantidad de tablas a analizar: ";
  cin >> x;

  vector<Tabla> tabla(x); // Usar vector en lugar de arreglo de tamaño dinámico

  for (int i = 0; i < x; i++) {
    cout << "Ingrese el nombre de la tabla " << i + 1 << ": ";
    cin >> tabla[i].nombre;

    cout << "Ingrese la cantidad de variables de la tabla " << i + 1 << ": ";
    cin >> tabla[i].cantiVariables;

    // Redimensionar los vectores según el número de variables
    tabla[i].atributosTabla.resize(tabla[i].cantiVariables);
    tabla[i].probabilidad.resize(tabla[i].cantiVariables);

    float sumaProbabilidades = 0;
    bool probabilidadesValidas = false;

    // Repetir el proceso de ingreso de probabilidades hasta que sumen 1
    while (!probabilidadesValidas) {
      sumaProbabilidades = 0; // Reiniciar la suma de probabilidades

      for (int j = 0; j < tabla[i].cantiVariables; j++) {
        cout << "Ingrese el nombre de la variable " << j + 1 << ": ";
        cin >> tabla[i].atributosTabla[j];

        cout << "Ingrese la probabilidad de la variable " << j + 1
             << " de la tabla " << i + 1 << ": ";
        cin >> tabla[i].probabilidad[j];

        sumaProbabilidades += tabla[i].probabilidad[j];
      }

      // Verificar que la suma de las probabilidades sea igual a 1
      if (sumaProbabilidades == 1) {
        probabilidadesValidas = true;
      } else {
        cout << "La suma de las probabilidades no es igual a 1. Por favor, "
                "ingrese las probabilidades nuevamente.\n";
      }
    }
  }

  // Imprimir las tablas en formato de tabla
  for (int i = 0; i < x; i++) {
    cout << "\nTabla: " << tabla[i].nombre << endl;

    // Imprimir la fila de nombres de variables
    cout << left << setw(15) << "Variable: ";
    for (int j = 0; j < tabla[i].cantiVariables; j++) {
      cout << setw(15) << tabla[i].atributosTabla[j];
    }
    cout << endl;

    // Imprimir la fila de probabilidades
    cout << left << setw(15) << "Probabilidad: ";
    for (int j = 0; j < tabla[i].cantiVariables; j++) {
      cout << setw(15) << tabla[i].probabilidad[j];
    }
    cout << endl;
  }

  return 0;
}
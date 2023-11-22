#include "Lista.h"
#include "Sucursal.h"
#include <bits/stdc++.h>

using namespace std;

class Ciudad {
private:
  string nombre;
  string departamento;
  Lista<Sucursal> sucursales;

public:
  // Constructor
  Ciudad(string nombre, string departamento) {
    this->nombre = nombre;
    this->departamento = departamento;
  }

  // Métodos para acceder a los atributos
  string getNombre() { return nombre; }

  string getDepartamento() { return departamento; }

  Lista<Sucursal> getSucursales() { return sucursales; }

  void agregarSucursal(Sucursal sucursal) { sucursales.endInsert(sucursal); }

  // Método para pedir al usuario la cantidad de sucursales y empleados a crear
  void PedirCantidadSucursalesYEmpleados() {
    int cantidadSucursales, cantidadEmpleados;

    cout << "Ingrese la cantidad de sucursales que desea crear: ";
    cin >> cantidadSucursales;

    for (int i = 0; i < cantidadSucursales; i++) {
      string nombreSucursal, direccionSucursal, barrioSucursal;

      cout << "Ingrese el nombre de la sucursal " << i + 1 << ": ";
      cin >> nombreSucursal;

      cout << "Ingrese la dirección de la sucursal " << i + 1 << ": ";
      cin >> direccionSucursal;

      cout << "Ingrese el barrio de la sucursal " << i + 1 << ": ";
      cin >> barrioSucursal;

      // Crear una instancia de la clase Sucursal con los datos ingresados
      Sucursal sucursal(nombreSucursal, direccionSucursal, barrioSucursal);

      // Pedir al usuario la cantidad de empleados para esta sucursal
      cout << "Ingrese la cantidad de empleados que desea crear para la "
              "sucursal "
           << i + 1 << ": ";
      cin >> cantidadEmpleados;

      for (int j = 0; j < cantidadEmpleados; j++) {
        Empleado empleado;
        // Llamar al método LlenarFormulario de la clase Sucursal para crear un
        // empleado
        sucursal.llenarFormulario(empleado);
      }

      // Agregar la sucursal a la lista de sucursales de la ciudad
      agregarSucursal(sucursal);
    }
  }
};

#include "Lista.h"
#include "Empleado.h"
#include <bits/stdc++.h>

using namespace std;

class Sucursal {
private:
  string nombre;
  string direccion;
  string barrio;
  Lista<Empleado> empleados;
  string nombreGerente;

public:
  // Constructor

  Sucursal(){};

  Sucursal(string nombre, string direccion, string barrio) {
    this->nombre = nombre;
    this->direccion = direccion;
    this->barrio = barrio;
  }

  // M�todos para acceder a los atributos
  string getNombre() { return nombre; }

  string getDireccion() { return direccion; }

  string getBarrio() { return barrio; }

  Lista<Empleado> getEmpleados() { return empleados; }

  void agregarEmpleado(Empleado empleado) { empleados.endInsert(empleado); }
  // M�todo para establecer el nombre del gerente
  void setNombreGerente(string nombreGerente) {
    this->nombreGerente = nombreGerente;
  }

  // M�todo para obtener el nombre del gerente
  string getNombreGerente() { return nombreGerente; }

  // M�todo para llenar el formulario y crear un objeto Empleado
void llenarFormulario() {
  // Crear una instancia de la clase Empleado con los datos ingresados
  Empleado empleado;

  // Pedir los datos al usuario con manejo de errores
  do {
    try {
      cout << "Ingrese el nombre del empleado: ";
      cin >> ws; // Limpiar el buffer antes de getline
      getline(cin, nombre);
      empleado.setNombre(nombre);

      cout << "Ingrese el apellido del empleado: ";
      cin >> ws;
      getline(cin, apellido);
      empleado.setApellido(apellido);

      cout << "Ingrese el tipo de identificaci�n del empleado (CC, CE, TI): ";
      cin >> tipoIdentificacion;
      empleado.setTipoIdentificacion(tipoIdentificacion);

      cout << "Ingrese el n�mero de identificaci�n del empleado: ";
      cin >> numeroIdentificacion;
      empleado.setNumeroIdentificacion(numeroIdentificacion);

      cout << "Ingrese el sexo del empleado (F, M): ";
      cin >> sexo;
      empleado.setSexo(sexo);

      cout << "Ingrese el tel�fono celular del empleado: ";
      cin >> telefonoCelular;
      empleado.setTelefonoCelular(telefonoCelular);

      cout << "Ingrese el tel�fono fijo del empleado: ";
      cin >> telefonoFijo;
      empleado.setTelefonoFijo(telefonoFijo);

      cout << "Ingrese el correo electr�nico del empleado: ";
      cin >> email;
      empleado.setEmail(email);

      cout << "Ingrese la fecha de nacimiento del empleado (DD/MM/AAAA): ";
      cin >> fechaNacimiento;
      empleado.setFechaNacimiento(fechaNacimiento);

      cout << "Ingrese el pa�s de nacimiento del empleado: ";
      cin >> paisNacimiento;
      empleado.setPaisNacimiento(paisNacimiento);

      cout << "Ingrese la ciudad de residencia del empleado: ";
      cin >> ciudadResidencia;
      empleado.setCiudadResidencia(ciudadResidencia);

      cout << "Ingrese la direcci�n del empleado: ";
      cin >> ws;
      getline(cin, direccion);
      empleado.setDireccion(direccion);

      cout << "Ingrese el barrio del empleado: ";
      cin >> ws;
      getline(cin, barrio);
      empleado.setBarrio(barrio);

      cout << "Ingrese la actividad laboral del empleado: ";
      cin >> actividadLaboral;
      empleado.setActividadLaboral(actividadLaboral);

      cout << "�Tiene hijos? (S/N): ";
      cin >> tieneHijos;

      if (tieneHijos == "S") {
        cout << "Ingrese el n�mero de hijos del empleado: ";
        cin >> numeroHijos;
        empleado.setNumeroHijos(numeroHijos);

        // Pedir al usuario la informaci�n de cada hijo
        for (int k = 0; k < numeroHijos; ++k) {
          string nombreHijo, fechaNacimientoHijo;

          cout << "Ingrese el nombre del hijo " << k + 1 << ": ";
          cin >> ws;
          getline(cin, nombreHijo);

          // Validar el nombre del hijo
          if (nombreHijo.empty()) {
            throw invalid_argument("El nombre del hijo no puede estar vac�o.");
          }

          cout << "Ingrese la fecha de nacimiento del hijo " << k + 1 << " (DD/MM/AAAA): ";
          cin >> fechaNacimientoHijo;

          // Validar la fecha de nacimiento del hijo
          if (!validarFecha(fechaNacimientoHijo)) {
            throw invalid_argument("Fecha de nacimiento inv�lida.");
          }

          // Crear una instancia de la clase Hijo con los datos ingresados
          Hijo hijo(nombreHijo, fechaNacimientoHijo);

          // Agregar el hijo a la lista de hijos del empleado
          empleado.agregarHijo(hijo);
        }
      }

      // Si llegamos aqu�, todos los datos han sido ingresados correctamente
      break;
    } catch (const exception &e) {
      cerr << "Error: " << e.what() << " Intente nuevamente." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  } while (true);

  // Agregar el empleado a la lista de empleados de la sucursal
  agregarEmpleado(empleado);
}
};

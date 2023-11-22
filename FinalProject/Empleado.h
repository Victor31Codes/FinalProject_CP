#include "Lista.h"
#include <bits/stdc++.h>
#include <regex>
#include <thread>


using namespace std;

class Empleado {
private:
  string nombre;
  string apellido;
  string tipoIdentificacion;
  string numeroIdentificacion;
  string sexo;
  string telefonoCelular;
  string telefonoFijo;
  string email;
  string fechaNacimiento;
  string paisNacimiento;
  string ciudadResidencia;
  string direccion;
  string barrio;
  string actividadLaboral;
  string tieneHijos;
  int numeroHijos;
  Lista<Hijo> hijos;
  int idSucursal;

  // !!! Falta agregar la lista de hijos.

  string nombreSucursal;

public:
  // Métodos set
  void setNombre(string nombre) { this->nombre = nombre; }

  void setApellido(string apellido) { this->apellido = apellido; }

  void setTipoIdentificacion(string tipoIdentificacion) {
    // Verificar que el tipo de identificación sea válido
    if (tipoIdentificacion == "CC" || tipoIdentificacion == "CE" ||
        tipoIdentificacion == "TI") {
      this->tipoIdentificacion = tipoIdentificacion;
    } else {
      cout << "Tipo de identificación inválido" << endl;
    }
  }

  void setNumeroIdentificacion(string numeroIdentificacion) {
    this->numeroIdentificacion = numeroIdentificacion;
  }

  void setSexo(string sexo) {
    // Verificar que el sexo sea válido
    if (sexo == "F" || sexo == "M") {
      this->sexo = sexo;
    } else {
      cout << "Sexo inválido" << endl;
    }
  }

  void setTelefonoCelular(string telefonoCelular) {
    this->telefonoCelular = telefonoCelular;
  }

  void setTelefonoFijo(string telefonoFijo) {
    this->telefonoFijo = telefonoFijo;
  }

  // Método set para validar el correo electrónico
  void setEmail(string email) {
    regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (regex_match(email, pattern)) {
      this->email = email;
    } else {
      cout << "Correo electrónico inválido" << endl;
    }
  }

  // Método set para validar la fecha de nacimiento
  void setFechaNacimiento(string fechaNacimiento) {
    regex pattern(
        "^(?:(?:31(\\/|-|\\.)(?:0?[13578]|1[02]))\\1|(?:(?:29|30)(\\/"
        "|-|\\.)(?:0?[13-9]|1[0-2])\\2))(?:(?:1[6-9]|[2-9]\\d)?\\d{2})$|^(?:29("
        "\\/"
        "|-|\\.)0?2\\3(?:(?:(?:1[6-9]|[2-9]\\d)?(?:0[48]|[2468][048]|[13579]["
        "26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\\d|2[0-8])("
        "\\/"
        "|-|\\.)(?:(?:0?[1-9])|(?:1[0-2]))\\4(?:(?:1[6-9]|[2-9]\\d)?\\d{2})$");
    if (regex_match(fechaNacimiento, pattern)) {
      this->fechaNacimiento = fechaNacimiento;
    } else {
      cout << "Fecha de nacimiento inválida" << endl;
    }
  }

  void setPaisNacimiento(string paisNacimiento) {
    this->paisNacimiento = paisNacimiento;
  }

  void setCiudadResidencia(string ciudadResidencia) {
    this->ciudadResidencia = ciudadResidencia;
  }

  void setDireccion(string direccion) { this->direccion = direccion; }

  void setBarrio(string barrio) { this->barrio = barrio; }

  void setActividadLaboral(string actividadLaboral) {
    transform(actividadLaboral.begin(), actividadLaboral.end(),
              actividadLaboral.begin(), ::tolower);
    if (actividadLaboral == "artes" ||
        actividadLaboral == "ciencias sociales" ||
        actividadLaboral == "ingenierías" ||
        actividadLaboral == "areas de la salud" ||
        actividadLaboral == "otros") {
      this->actividadLaboral = actividadLaboral;
    } else {
      cout << "Actividad laboral inválida." << endl;
    }
  }

  void setTieneHijos(string tieneHijos) {
    // Verificar que la respuesta sea válida
    if (tieneHijos == "S" || tieneHijos == "N") {
      this->tieneHijos = tieneHijos;
    } else {
      cout << "Respuesta inválida" << endl;
    }
  }

  void setNumeroHijos(int numeroHijos) { this->numeroHijos = numeroHijos; }

  void setNombreSucursal(string nombreSucursal) {
    this->nombreSucursal = nombreSucursal;
  }
  
  // Método para establecer el ID de la sucursal
  void setIdSucursal(int idSucursal) { this->idSucursal = idSucursal; }

  // Métodos get
  string getNombre() { return nombre; }

  string getApellido() { return apellido; }

  string getTipoIdentificacion() { return tipoIdentificacion; }

  string getNumeroIdentificacion() { return numeroIdentificacion; }

  string getSexo() { return sexo; }

  string getTelefonoCelular() { return telefonoCelular; }

  string getTelefonoFijo() { return telefonoFijo; }

  string getEmail() { return email; }

  string getFechaNacimiento() { return fechaNacimiento; }

  string getPaisNacimiento() { return paisNacimiento; }

  string getCiudadResidencia() { return ciudadResidencia; }

  string getDireccion() { return direccion; }

  string getBarrio() { return barrio; }

  string getActividadLaboral() { return actividadLaboral; }

  string getTieneHijos() { return tieneHijos; }

  int getNumeroHijos() { return numeroHijos; }

  string getNombreSucursal() { return nombreSucursal; }

  int getIdSucursal() { return idSucursal; }
};

// Método para agregar un hijo al empleado
  void agregarHijo(Hijo hijo) { hijos.endInsert(hijo); }

  // Método para obtener la lista de hijos
  Lista<Hijo> getHijos() { return hijos; }

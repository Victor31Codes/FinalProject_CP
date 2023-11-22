class Hijo {
private:
  string nombre;
  string fechaNacimiento;
  int idEmpleado;

public:
  // Constructor
  Hijo(string nombre, string fechaNacimiento, int idEmpleado) {
    this->nombre = nombre;
    this->fechaNacimiento = fechaNacimiento;
    this->idEmpleado = idEmpleado;
  }

  // Métodos get
  int getIdEmpleado() { return idEmpleado; }
};


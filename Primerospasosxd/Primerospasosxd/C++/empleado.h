#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>

using namespace std;

class Empleado {
	public:
    int id_sucursal, id_empleado, num_hijos; 
	long int ident,cel,tel;
    string nombre_empleado, apellido_empleado, tipo_ident, correo,
		fecha_nac_empleado, ciudad_nac_empleado, pais_nac_empleado,
		ciudad_res_empleado, dir_empleado, barrio_empleado;
	string act_lab;
	char sexo, tiene_hijos;
	string nombre_sucursal;
	int edad;
	
void calcularEdad() {
    // Obtener la fecha y hora actuales
    auto ahora = std::chrono::system_clock::now();
    auto tiempo_actual = std::chrono::system_clock::to_time_t(ahora);
    std::tm tm_actual = *std::localtime(&tiempo_actual);

    // Obtener la fecha de nacimiento
    std::istringstream ss(fecha_nac_empleado);
    char dash;  // Carácter para almacenar el guion '-'
    int dia, mes, anio;
    ss >> dia >> dash >> mes >> dash >> anio;

    if (ss.fail()) {
        cerr << "Error al leer la fecha de nacimiento." << endl;
        return;
    }

    // Configurar la estructura tm con la fecha de nacimiento
    std::tm tm_nac = {};
    tm_nac.tm_mday = dia;
    tm_nac.tm_mon = mes - 1;  // Restar 1, ya que en struct tm, los meses van de 0 a 11
    tm_nac.tm_year = anio - 1900;  // Restar 1900, ya que struct tm cuenta los años desde 1900

    // Calcular la diferencia de años
    auto edad_chrono = std::chrono::duration_cast<std::chrono::hours>(ahora - std::chrono::system_clock::from_time_t(std::mktime(&tm_nac)));
    int edad_en_anios = static_cast<int>(edad_chrono.count()) / (24 * 365);

    edad = edad_en_anios;
}
};

#endif

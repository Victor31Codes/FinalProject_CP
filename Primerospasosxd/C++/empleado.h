#ifndef EMPLEADO_H
#define EMPLEADO_H

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
};

#endif

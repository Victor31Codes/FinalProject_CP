#include <iostream>
#include <fstream>
#include <sstream>
#include "lista.h"
#include "hijo.h"
#include "empleado.h"
using namespace std;

void cargarDatos_hijos(const string& nombreArchivo, Lista<Hijo>& lista_hijos);
void cargarDatos_empleados(const string& nombreArchivo, Lista<Empleado>& lista_empleados);

int main(int argc, char** argv) {
	
	Lista<Hijo> lista_hijos;
    cargarDatos_hijos("DB//Hijos.txt", lista_hijos);
    nodo<Hijo>* actual_hijo = lista_hijos.obtener_cabecera();
    while (actual_hijo != nullptr) {
        cout << actual_hijo->Dato.id_empleado << " "
                << actual_hijo->Dato.id_hijo << " "
                << actual_hijo->Dato.nombre_hijo << " "
                << actual_hijo->Dato.nac_hijo << endl;
        actual_hijo = actual_hijo->sig;
    }
    Lista<Empleado> lista_empleados;
    cargarDatos_empleados("DB//Empleados.txt", lista_empleados);
    nodo<Empleado>* actual_empleado =lista_empleados.obtener_cabecera();
    while (actual_empleado != nullptr) {
        cout << actual_empleado->Dato.id_sucursal <<" "
        		<<actual_empleado->Dato.id_empleado <<" "
        		<<actual_empleado->Dato.nombre_empleado <<" "
        		<<actual_empleado->Dato.apellido_empleado<<" "
        		<<actual_empleado->Dato.tipo_ident<<" "
        		<<actual_empleado->Dato.ident<<" "
				<<actual_empleado->Dato.sexo<<" "
				<<actual_empleado->Dato.cel<<" "
				<<actual_empleado->Dato.tel<<" "
				<<actual_empleado->Dato.correo<<" "
				<<actual_empleado->Dato.fecha_nac_empleado<<" "
				<<actual_empleado->Dato.ciudad_nac_empleado<<" "
				<<actual_empleado->Dato.pais_nac_empleado<<" "
				<<actual_empleado->Dato.ciudad_res_empleado<<" "
				<<actual_empleado->Dato.dir_empleado<<" "
				<<actual_empleado->Dato.barrio_empleado<<" "
				<<actual_empleado->Dato.act_lab<<" "
				<<actual_empleado->Dato.tiene_hijos<<" "
				<<actual_empleado->Dato.num_hijos<<" "
				<<actual_empleado->Dato.nombre_sucursal<<" "<<endl;
        actual_empleado = actual_empleado->sig;
    }

    return 0;
}

#include <fstream>
#include <sstream>
#include "lista.h"
#include "hijo.h"
#include "empleado.h"
using namespace std;

void cargarDatos_hijos(const string& nombreArchivo, Lista<Hijo>& lista_hijos){
	ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream iss(linea);
            Hijo nuevo_hijo;
            if (iss >> nuevo_hijo.id_empleado >> nuevo_hijo.id_hijo >> nuevo_hijo.nombre_hijo >> nuevo_hijo.nac_hijo) {
                lista_hijos.insertar_final(nuevo_hijo);
            } else {
                cerr << "No se pudieron leer los atributos correctamente." << std::endl;
            }
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

void cargarDatos_empleados(const string& nombreArchivo, Lista<Empleado>& lista_empleados) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream iss(linea);
            Empleado nuevo_empleado;
            if (iss >> nuevo_empleado.id_sucursal>>nuevo_empleado.id_empleado>>nuevo_empleado.nombre_empleado
				>>nuevo_empleado.apellido_empleado>>nuevo_empleado.tipo_ident>>nuevo_empleado.ident>>
				nuevo_empleado.sexo>>nuevo_empleado.cel>>nuevo_empleado.tel>>nuevo_empleado.correo>>
				nuevo_empleado.fecha_nac_empleado>>nuevo_empleado.ciudad_nac_empleado>>nuevo_empleado.pais_nac_empleado>>
				nuevo_empleado.ciudad_res_empleado>>nuevo_empleado.dir_empleado>>nuevo_empleado.barrio_empleado>>
				nuevo_empleado.act_lab>>nuevo_empleado.tiene_hijos>>nuevo_empleado.num_hijos>>nuevo_empleado.nombre_sucursal) {
                lista_empleados.insertar_final(nuevo_empleado);
            } else {
                cerr << "No se pudieron leer los atributos correctamente, sad." <<endl;
            }
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo." << endl;
    }
}

#Programa de gestión de hospitales de Mario
Este proyecto consiste en la creación de un programa con el que se puedan crear, eliminar, editar o buscar pacientes , doctores o citas de un hospital
El proyecto ha sido creado usando C++, y usa CMake y JSON

Las características del programa:
	Funcionalidades
		-Gestión de Doctores:
			*Crear, eliminar, editar y buscar doctores
			*Detalles incluidos: nombre, especialidad, disponibilidad, salario, etc...
		-Gestión de Pacientes:
			*Crear, eliminar, editar y buscar pacientes
			*Detalles incluidos: nombre, enfermedad, fechas de alta y baja, etc...
		-Gestión de Citas:
			*Crear, eliminar, editar y buscar citas relacionadas con pacientes y doctores
		-Búsqueda Avanzada:
			*Realizar búsquedas de registros por atributos como ID, nombre, enfermedad, especialidad, etc...
		-Generación de Reportes:

			*Reportes específicos, como:
				**Citas pendientes
				**Pacientes con enfermedades crónicas
				**Doctores disponibles
		-Copia de Seguridad y Restauración:
			*Copias de seguridad automáticas y restauración en caso de pérdida de datos

Instalación
	1.Usa el repositorio de github:
		https://github.com/mario123412345/AB-Programacion
	2.Abre el proyecto en visual studio
	3.Selecciona el cpp llamado *AB Programacion.cpp*
	4.Arriba hay una opcion para seleccionar ejecutar el .exe, si no funciona, selecciona la opción de documento actual en cualquier cpp y se ejecutará el main
	5.El proyecto se compilará y una vez terminada la compilación , podrás empezar a usar el programa


Estructura del Código
El código se encuentra organizado en varios archivos .cpp, cada uno con una responsabilidad específica. Aquí tienes una descripción general:
		-AB Programacion.cpp:
			Contiene la función main() y el menú principal del programa
		-Crear.cpp:
			Gestiona la creación de registros (doctores, pacientes y citas)
		-Eliminar.cpp:
			Permite eliminar registros y enviarlos a una papelera virtual
		-Editar.cpp:
			Permite modificar los datos de citas, pacientes o doctores
		-Buscar.cpp:
			Permite realizar búsquedas avanzadas por atributos específicos
		-Reporte.cpp:
			Genera reportes detallados sobre citas, pacientes y doctores
		-Restaurar.cpp:
			Restaura los registros desde una copia de seguridad
		-Crear documentos de texto.cpp:
			Genera y administra los archivos JSON, además de realizar copias de seguridad


Archivos JSON
El sistema utiliza tres archivos JSON para almacenar la información:
		-pacientes.json:
			Datos almacenados:
				*ID único del paciente
				*Nombre y apellidos
				*Enfermedad
				*Fecha de alta y baja
		-doctores.json:
			Datos almacenados:
				*ID único del doctor
				*Nombre, apellidos y especialidad
				*Disponibilidad y salario
		-citas.json:
			Datos almacenados:
				*ID único de la cita
				*Fecha y hora
				*ID del paciente (y sus datos)
				*ID del doctor (y sus datos)


Ejemplo de uso
Al ejecutar el programa, el sistema presentará un menú con las siguientes opciones:
		-Crear:	
			Permite crear nuevos doctores, pacientes y citas
		-Buscar: 
			Permite buscar pacientes, doctores o citas por atributos específicos
		-Editar: 
			Permite modificar la información de los registros existentes
		-Eliminar: 
			Permite eliminar registros, enviándolos a la papelera
		-Generar 
			Reportes: Permite generar reportes según criterios definidos
		-Salir: 
			Para salir del programa
#Programa de gesti�n de hospitales de Mario
Este proyecto consiste en la creaci�n de un programa con el que se puedan crear, eliminar, editar o buscar pacientes , doctores o citas de un hospital
El proyecto ha sido creado usando C++, y usa CMake y JSON

Las caracter�sticas del programa:
	Funcionalidades
		-Gesti�n de Doctores:
			*Crear, eliminar, editar y buscar doctores
			*Detalles incluidos: nombre, especialidad, disponibilidad, salario, etc...
		-Gesti�n de Pacientes:
			*Crear, eliminar, editar y buscar pacientes
			*Detalles incluidos: nombre, enfermedad, fechas de alta y baja, etc...
		-Gesti�n de Citas:
			*Crear, eliminar, editar y buscar citas relacionadas con pacientes y doctores
		-B�squeda Avanzada:
			*Realizar b�squedas de registros por atributos como ID, nombre, enfermedad, especialidad, etc...
		-Generaci�n de Reportes:

			*Reportes espec�ficos, como:
				**Citas pendientes
				**Pacientes con enfermedades cr�nicas
				**Doctores disponibles
		-Copia de Seguridad y Restauraci�n:
			*Copias de seguridad autom�ticas y restauraci�n en caso de p�rdida de datos

Instalaci�n
	1.Usa el repositorio de github:
		https://github.com/mario123412345/AB-Programacion
	2.Abre el proyecto en visual studio
	3.Selecciona el cpp llamado *AB Programacion.cpp*
	4.Arriba hay una opcion para seleccionar ejecutar el .exe, si no funciona, selecciona la opci�n de documento actual en cualquier cpp y se ejecutar� el main
	5.El proyecto se compilar� y una vez terminada la compilaci�n , podr�s empezar a usar el programa


Estructura del C�digo
El c�digo se encuentra organizado en varios archivos .cpp, cada uno con una responsabilidad espec�fica. Aqu� tienes una descripci�n general:
		-AB Programacion.cpp:
			Contiene la funci�n main() y el men� principal del programa
		-Crear.cpp:
			Gestiona la creaci�n de registros (doctores, pacientes y citas)
		-Eliminar.cpp:
			Permite eliminar registros y enviarlos a una papelera virtual
		-Editar.cpp:
			Permite modificar los datos de citas, pacientes o doctores
		-Buscar.cpp:
			Permite realizar b�squedas avanzadas por atributos espec�ficos
		-Reporte.cpp:
			Genera reportes detallados sobre citas, pacientes y doctores
		-Restaurar.cpp:
			Restaura los registros desde una copia de seguridad
		-Crear documentos de texto.cpp:
			Genera y administra los archivos JSON, adem�s de realizar copias de seguridad


Archivos JSON
El sistema utiliza tres archivos JSON para almacenar la informaci�n:
		-pacientes.json:
			Datos almacenados:
				*ID �nico del paciente
				*Nombre y apellidos
				*Enfermedad
				*Fecha de alta y baja
		-doctores.json:
			Datos almacenados:
				*ID �nico del doctor
				*Nombre, apellidos y especialidad
				*Disponibilidad y salario
		-citas.json:
			Datos almacenados:
				*ID �nico de la cita
				*Fecha y hora
				*ID del paciente (y sus datos)
				*ID del doctor (y sus datos)


Ejemplo de uso
Al ejecutar el programa, el sistema presentar� un men� con las siguientes opciones:
		-Crear:	
			Permite crear nuevos doctores, pacientes y citas
		-Buscar: 
			Permite buscar pacientes, doctores o citas por atributos espec�ficos
		-Editar: 
			Permite modificar la informaci�n de los registros existentes
		-Eliminar: 
			Permite eliminar registros, envi�ndolos a la papelera
		-Generar 
			Reportes: Permite generar reportes seg�n criterios definidos
		-Salir: 
			Para salir del programa
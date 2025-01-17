# CMakeList.txt: proyecto de CMake para CMakeProject2, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.8)

# Habilite Recarga activa para los compiladores de MSVC si se admiten.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("AB Programacion")

# Agregue un origen al ejecutable de este proyecto.
add_executable (AB_Programacion "AB Programacion.cpp" "AB Programacion.h" "Crear.cpp" "Crear Cita.cpp" "Crear Doctor.cpp" "Crear Paciente.cpp" "Editar.cpp" "Editar Cita.cpp" "Editar Doctor.cpp" "Editar Paciente.cpp" "Eliminar.cpp" "Eliminar Cita.cpp" "Eliminar Doctor.cpp" "Eliminar Paciente.cpp" "Registro.cpp" "Registro Citas.cpp" "Registro Doctores.cpp" "Registro Pacientes.cpp"   "Crear documentos de texto.cpp"    "Buscar.cpp" "Buscar paciente.cpp" "Buscar doctor.cpp" "Buscar cita.cpp"  "Restaurar.cpp" "Reporte.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AB_Programacion PROPERTY CXX_STANDARD 20)
endif()

include_directories("${CMAKE_SOURCE_DIR}/include")

# Configurar las rutas para MySQL Connector




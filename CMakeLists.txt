# CMakeList.txt: archivo del proyecto de CMake de nivel superior, establezca la configuración global
# e incluya los subproyectos aquí.
#
cmake_minimum_required (VERSION 3.8)

# Habilite Recarga activa para los compiladores de MSVC si se admiten.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("AB Programacion")

# Incluya los subproyectos.
add_subdirectory ("AB Programacion")


cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(AB_Programacion)

# Agregar los directorios de cabeceras
include_directories(${CMAKE_SOURCE_DIR}/include)

# Agregar las bibliotecas
link_directories(${CMAKE_SOURCE_DIR}/lib64)

# Archivos fuente
file(GLOB SOURCES "src/*.cpp")

# Crear el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Enlazar bibliotecas necesarias (las de MySQL)
target_link_libraries(${PROJECT_NAME} mysqlcppconn)


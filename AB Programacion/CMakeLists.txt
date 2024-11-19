# CMakeList.txt: proyecto de CMake para AB Programacion, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

# Agregue un origen al ejecutable de este proyecto.
add_executable (CMakeTarget "AB Programacion.cpp" "AB Programacion.h" "Editar.cpp" "Crear.cpp" "CrearP.cpp" "CrearD.cpp" "CrearC.cpp" "EditarP.cpp" "EditarD.cpp" "EditarC.cpp" "EliminarP.cpp" "EliminarD.cpp" "EliminarC.cpp"  "Eliminar.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.

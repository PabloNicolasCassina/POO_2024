## Ejercicio 1:
Instalar Qt. Lo cual incluye las herramientas de compilación C++, la biblioteca Qt y Qt Creator.
Crear un primer programa que muestre por la consola de QtCreator 10 números aleatorios en el intervalo [ 2, 20 ]
Cada vez que se ejecute el programa, los números deberán ser aleatorios y distintos en cada ejecución.

## Ejercicio 2:
**Objetivo:** Familiarización con librerías, archivos DLL y variable de entorno PATH. Tener presente la distinción entre biblioteca, librería y library.

**Descripción:** Crear un programa simple en C++ que utilice una librería externa (en forma de archivo DLL o similar en otros sistemas operativos) y que haga uso de la variable de entorno PATH para ubicar dicha librería.

**Pasos a seguir:**
1. Crear una librería en C++ y compilarla como un archivo DLL (o similar en otros sistemas operativos). Programar en la librería una función que imprima un mensaje simple, como "Hola, desde la biblioteca".
2. Crear un programa principal en C++ que utilice esta librería. Hacer referencia (o linkear) a la librería de manera dinámica.
3. Incluir la ruta al archivo DLL en la variable de entorno PATH.
4. En el programa principal, cargar la librería, invocar a la función y mostrar el mensaje.

## Ejercicio 3:
Elija un nombre para su propio espacio de nombres para todo lo que se haga en este asignatura.
Luego de elegido el nombre para su namespace, defina una función dentro de ese namespace para devolver el número de versión junto con la fecha de la última actualización de la biblioteca.

QString getVersion();  // Devuelve un texto como "v0.0.1 - 20240318"

## Ejercicio 4:
Crear un `std::vector` para contener `int`.
Cargar 30 valores pseudo aleatorios entre 1 y 15.
Publicar la moda.

## Ejercicio 5:
Crear un `std::vector` para contener objetos de la clase `std::string`.
Cargar 5 expresiones idiomáticas, como por ejemplo: "pan comido".
Publicar por consola ordenado alfabéticamente.

## Ejercicio 6:
En un Empty qmake Project.
Crear una nueva clase (que no sea `Persona`, ni `Cliente`, ni `Poste`). Invente una clase.
Agregar uno o más constructores, agregar sus métodos y sus atributos.
Crear algunos objetos de esta clase en la función `main`.

## Ejercicio 7:
Empty qmake Project.
Utilizar la clase creada en el ejercicio anterior para crear objetos y almacenarlos en un `std::vector`.
¿Se pueden ordenar? Qué estrategia utilizaría para ordenarlos de menor a mayor?

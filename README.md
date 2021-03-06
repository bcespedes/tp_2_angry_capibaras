# Trabajo Práctico II de Algoritmos y Programación II - Facultad de Ingeniería Universidad de Buenos Aires
## Cátedra Juárez

## Integrantes 👩‍💻 👨‍💻
- Maira Argüelles
- Martin Morono
- Brian Céspedes

### Temática del TP
Este proyecto nos fue encargado por **Sid** ya que nuestra ayuda durante el primer trabajo práctico realizado fue tan exitosa que incrementó la cantidad de socios de su club de lectura. A raíz de esto nos encargaron tareas un poco más complicadas para que la calidad esté al nivel de un establecimiento tan prestigioso como el de nuestro amigo dormilón.
Los miembros del club se reúnen todos los martes y jueves a las 13hs. Luego se encargan de elegir lo que les gustaría leer durante las siguientes tres horas. Además de esto, para que nuestros amigos del club se puedan organizar mucho mejor, las posibles lecturas están ordenadas en una lista por año, de menor a mayor. Los tipos de lecturas van desde novelas (de distintos géneros), hasta cuentos y poemas.
A través de nuestros conocimientos en programación orientada a objetos y con una pizca de creatividad, hacemos entrega de este software, esperando que sea del agrado de los miembros del club de lectura de Sid. ¡Gracias por confiar en nosotros!


#### Opciones disponibles en el Menú Principal:
- Agregar una nueva lectura a la lista.
- Quitar una lectura de la lista.
- Agregar un nuevo escritor a la lista.
- Cambiar dato de un escritor (año de fallecimiento).
- Listar los escritores.
- Sortear una lectura aleatoria para leer en una de las tertulias.
- Listar las lecturas.
- Listar las lecturas entre determinados años ingresados por el usuario.
- Listar las lecturas de un determinado escritor ingresado por el usuario.
- Listar las novelas de determinado género.
- Crear una cola de lecturas ordenadas por tiempo de lectura, de menor a mayor.
- Salir del menú.

#### Manual de usuario:
Diseñado tanto para windows como para linux, el programa cuenta con un menu con el que el usuario podra interactuar con las diversas opciones ya mencionadas. El programa puede contar o no con los archivos `escritores.txt` y `lecturas.txt`, en caso de no encontrarse, se le informara al usuario y se podran agregar manualmente  nuevas lecturas o escritores desde las opciones correspondientes. Las instrucciones que se dan en cada instancia estan validadas lo maximo posible para evitar que el programa colapse. Ademas cuenta con algun Easter Egg que sera descubierto a medida que se explore el codigo.

```
El programa debe compilar por terminal con el comando: g++ *.cpp -Wall -Werror -Wconversion 
```

#### División de tareas en el trabajo:
Establecimos un grupo de trabajo consolidado, por lo que no hubo una division de tareas muy marcada. A traves de reuniones planteamos las diferentes problematicas y las resolvimos juntos. En algunos momentos, para agilizar y aprovechar tiempos, utilizamos la extension del Vscode "Live Share" con lo que podiamos acceder todos al mismo codigo en tiempo real e ir modificandolo. Esta tematica se aprovecho mucho conjunto a la modalidad pair programming. Sobre el final hubo mas independencia y trabajo individual, con tareas puntuales, puliendo y optimizando el codigo con la finalidad de entregar un producto lo mas completo posible.
# ejercicio13-gaboandres1

### Ejercicio 2: No compila debido a que la declaración const hace que el valor de la variable no pueda cambiar. Al hacer a = r en la función addition, se genera un error.

### Ejercicio 4: La función getMax() distingue cuando su argumento es tipo entero o double. El programa al llamar una de estas funciones, dependiendo los argumentos que se le den, llamará a la función que coincida con los argumentos que se le indicó.

### Ejercicio 5: Si se compila con -fsanitize=address, al correr el ejecutable con N=10000000 se obtiene el error stackOverflow. La bandera lo que hace es detectar errores en la memoria. En este caso el error es que se está intentando reservar un espacio en la memoria mayor al que el sistema deja reservar. Al usar Heap no hay ningún problema. Se concluye que el espacio máximo reservado para un stack es limitado y fijo. Por otro lado, un Heap es dinámico y su tamaño máximo solo dependería del tamaño de la memoria de la máquina.
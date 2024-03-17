# So_Long

<div>

  ![Proyecto](https://img.shields.io/badge/Proyecto-So_Long-blue)
  ![Licencia](https://img.shields.io/badge/Licencia-MIT-orange)
  ![Versión](https://img.shields.io/badge/Versión-1.0-green)
  <a href="https://github.com/MiMendiola/So_long/tree/main/README.md" >
    <img src="https://img.shields.io/badge/Change_Language-English-purple" align="right">
  </a>
  
</div>

![video](../../video/video.gif)

El objetivo del proyecto es la creacion de un `juego en 2D` facilitandonos la introduccion al desarrollo de videojuegos, trabajando con `texturas`, `sprites` y `gestion de eventos` mediante el uso de la `librería gráfica MiniLibX`. Esto nos enseña a manejar elementos gráficos y eventos de usuario, asi comprendiendo con mas profundidad las `estructuras` de datos.

La parte bonus incluye funcionalidades adicionales como: 

- Añadir algunas animaciones de sprites.
- La penalizacion de cuando tocas a un enemigo.
- Visualizar el contador de pasos en la pantalla.

Si necesitas mas informacion en la seccion `Tabla de Contenidos` podras encontrar una `explicacion mas detallada` de cada parte.

Para el desarrollo del juego me he enfocado en realizarlo de forma mas modular, dividiendo el archivo **`so_long.h`** en varios archivos: **`structs.h`** para definir mis estructuras, **`defines.h`** para constantes y utilidades y **`so_long.h`** para las funciones del proyecto, asi mejorando la legibilidad y el orden del codigo.

El mapa representa el nucleo del juego siendo asi su creacion y analisis primordial. Utilizamos la estructura  **`t_map`** para el parseo y modificacion del mapa, y **`t_game`** para la representacion grafica del juego y la gestion de movimientos del `P(Jugador)`. En la validacion del mapa utilizamos un algoritmo de `relleno por inundacion` comprobando si hay camino valido, implementado de fomra recursiva.

La jugabilidad consiste en una `representacion mediante sprites`, cuyo `tamaño` se deriva en las `dimensiones del mapa` y de las `imagenes utilizadas`. Los movimientos de `P(Jugador)` se realiza a traves de los `eventos de teclado` complementado con un bucle para las `animaciones` y una funcion para la visualizacion de los pasos realizados, todo gestionado por la `MLX`. Ademas tenddremos que gestionar la salida del juego mediante `cierre de la ventana` o la pulsacion de la tecla `ESC`.

Finalmente, los `sprites` se optimizaran `almacenandolos` en una `estructura dedicada`, lo que simplifica su manejo en el juego. Esto facilitara la modificacion y actualizacion de la posicion del `P(Jugador)` dependiendo de la interaccion del usuario con el teclado, asegurando un experiencia del juego dinamica y fluida.

---

## Tabla de Contenidos

[MAP](https://github.com/MiMendiola/So_long/tree/main/Documentation/es/MAP.es.md)

[GAME](https://github.com/MiMendiola/So_long/tree/main/Documentation/es/GAME.es.md)

[SPRITES](https://github.com/MiMendiola/So_long/tree/main/Documentation/es/SPRITES.es.md)

---

## Recomendaciones

Consultar [42Docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) para obtener informacion detallada sobre la libreria.

Organiza las tareas pendientes en una `lista separada`.

Desde el inicio del proyecto `system("leaks -q so_long")` y añadir las flags `-g3 -fsanitize=address` en el makefile. Esenciales para gestionar los problemas que surjan.

El uso de la funcion `exit` en el programa para salir de forma correcta.

Mantener `dos copias` distintas del `mapa` dentro del proyecto, permitiendo su uso para diferentes propositos.

Inicializar las `estructuras` al inicio del proyecto. Incluir estructuras anidadas dentro de las principales para minimizar la necesidad de asignar memoria posteriormente.

Empezar por la `creacion y analisis` del mapa. Es funcdamental aprender el `algoritmo` de `relleno por inundacion`.

Almacena `las imagenes` desde el principio en una estructura, asegurandonos que todas tengan el `mismo tamaño`.

---

## Contacto

Si tienes alguna pregunta, sugerencia o comentario sobre So_long, no dudes en ponerte en contacto conmigo:

- Correo Electrónico:
[mglmendiol@gmail.com](mailto:mglmendiol@gmail.com)
- LinkedIn:
[https://www.linkedin.com/in/mimendiola/](https://www.linkedin.com/in/mimendiola/)
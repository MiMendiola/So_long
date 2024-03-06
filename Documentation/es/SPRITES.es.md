# Sprites

Las reglas que tenemos que seguir para nuestro juego son:

- El programa `mostrará` la imagen en una `ventana`.
- La `gestión de tu ventana` debe ser `limpia` (cambiar de ventana,
minimizar, etc).
- Pulsar la `tecla ESC` debe cerrar la ventana y `cerrar el programa`
limpiamente.
- Hacer `clic en la cruz roja` de la ventana debe `cerrar la ventana` y
terminar el programa limpiamente.
- El uso de `images` de la `miniLibX` es obligatorio.

Tendremos 3 archivos dedicados para los sprites del mapa:

**SPRITE_GENERATOR.C**: Este archivo contendra las funciones para `mostrar nuestros sprites` por la ventana del juego.

- **void		sprite_map(t_game** ***game):** Se encargara de `dibujar en bucle` los elementos juego. Iniciamos verificando con una flag que la cover no se ha realizado una cierta cantidad de veces. Posteriormente, dibujaremos sera los `caracteres(sprite_characters)` y mostraremos la `E(Salida)` cuando no queden `C(Coleccionables)` en el mapa.
- **void		sprite_player(t_game** ***game, int row, int col):** En esta funcion dependemos de la `direccion de movimiento` del `P(Jugador)`, la cual se almacena en una `flag`, para determinar como dibujar el sprite del jugador en el juego.
- **void		sprite_exit(t_game** ***game, int i, int j)**: Esta función decide cómo dibujar la salida en función de la cantidad de `C(Coleccionables)` en el juego.
- **void		sprite_balls(t_game** ***game, int i, int j)**: Esta función se utiliza para dibujar los `C(Coleccionables)` en el juego, dependiendo de la cantidad que haya.
- **void		sprite_characters(t_game** ***game):** Realizaremos un bucle para `pintar` los `sprite` correspondientes dependiendo del `caracter` encontrado. Si se encuentra un `P(Jugador)` usaremos la funcion `sprite_player` para dibujar sus animaciones.

**SPRITE_COVERS.C**: Generacion de la pantalla de carga del juego

- **void 	sprite_covers(t_game** ***game, int posx)**: Lo utilizaremos para `pintar la pantalla de carga` del juego, ajustando la imagen en base a la `posicion x` proporcionada. Conseguiremos la `mitad de pantalla` y `modificando su posicion lateral` de la imagen para crear una sensacion de movimiento.

**SPRITE_CREATOR.C**: Creacion y almacenamiento de las imagenes usadas en el juego.

- **void 		creator_sprites(t_game** ***game)**: Primero se `asigna el tamaño` necesario a `las imagenes` que guardaremos en la estructura `t_init_sprites`. Despues continuamos con la `creacion y almacenado de los sprites` utilizados en el juego.
- **static void	create_sprites_objs(t_game** ***game)**: Se crean los `sprites` de todos los `objetos` del juego.

- **static void	create_sprites_gokubase(t_game** ***game)**: Se generan los `sprites` del `P(Jugador)` para su uso cuando lo necesitemos.

- **static void	*load_cover(t_game *game, char *path)**: Funcion que `genera` la imagen `cover` para la `pantalla de carga`, incluyendo una `comprobacion` de la existencia de la imagen.
- **static void	*load_image(t_game *game, char *path)**: Destinada a `crear la imagen` que necesitemos `dependiendo` de la `direccion de la imagen` que le demos, con una `comprobacion` de la existencia de la imagen.

**FRAMES_CHARGER.C**: Contiene las `funciones para las animaciones del juego`. El `numero de frames` que veis puede ser modificado segun tus preferencias. En el caso de `frame_stay` siempre estara activo sin necesidad de un bucle, mientras que las demas necesitaran realizar un ciclo entero, por lo que forzamos dicho bucle.

- **void		frames_stay(t_game** ***game, int x, int y)**: Representa la animacion en reposo o `IDLE` de cualquier juego normal, con un movimiento continuo.
- **void		frames_move_up(t_game** ***game, int x, int y):** Anima el movimiento hacia arriba.
- **void		frames_move_down(t_game** ***game, int x, int y):** Anima el movimiento hacia abajo.
- **void		frames_move_left(t_game** ***game, int x, int y):** Anima el movimiento hacia la izquierda.
- **void		frames_move_right(t_game** ***game, int x, int y):** Anima el movimiento hacia la derecha.
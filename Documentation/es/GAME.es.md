# Game

Las reglas que tenemos que seguir para nuestro juego son:

- El objetivo del `P(Jugador)` es recolectar todos los `C(Coleccionables)` presentes en el mapa y salir por la `E(Exit)`.
- Usar teclas `W, A, S y D` o `las teclas de dirección` se utilizarán para mover al personaje principal.
- El jugador debe poder moverse en 4 direcciones.
- El jugador no puede entrar dentro de las paredes.
- Tras cada movimiento, el número real de `movimientos` debe `mostrarse en un terminal`.
- Utilizarás una perspectiva 2D (vista de pájaro o lateral).
- El juego no necesita ser en tiempo real.
- Puedes crear el mundo que quieras.

Tengo 3 archivos diferentes donde cada uno se encarga de una parte del juego:

**GAME.C** : Este archivo centraliza la gestión de eventos y la lógica principal del juego.

- **void		game_init(t_game *game, t_map *map)**: La funcion mas importante de nuestro codigo. Primero iniciaremos nuestro juego con la `mlx_init()`, y con `mlx_loop(mlx)` lo mantendremos en bucle. Iniciaremos la ventana con `mlx_new_window` con el tamaño de nuestro mapa multiplicando por el tamaño de imagen (mostraremos las imagenes, no solo la matriz).
    
    Continuaremos `creando e inicializando los sprites(**creator_sprites**)` que necesita nuestro juego. Usaremos `mlx_hook` para realizar ciertas funciones cuando ocurre un evento como cuando pinchamos en la `X` (cerraremos el programa), presionamos alguna de las teclas con `mlx_key_hook` o que ejecutamos en bucle una funcion hasta cerrar el programa con `mlx_loop_hook`.
    
- **int		frame_executor(t_game *game)**: Funcion que se `llamara de manera recursiva` hasta que terminemos nuestro programa. Con esta funcion `volveremos a pintar el mapa` con todos sus caracteres, actualizando los `pasos` por pantalla y ejecutando nuestro `contador de frames` para poder crear nuestras `animaciones`.

- **int		frames_counter(t_game *game)**: Esta funcion sera nuestro `contador de frames` , al que le asigaremos una cantidad de `60ms`. Cuando sobrepasemos de esta cantidad, volveremos a `iniciar el contador` a 0. Esto nos proporcionara la posibilidad de `variar` entre `imagenes`, dependiendo del frame.

- **int		key_press(int keycode, t_game *game)**: Dependiendo de la `tecla presionada` nos proporcionara su codigo, y se enviaran las nuevas coordenadas de nuestro `P(Jugador)`, modificada hacia la `direccion` correspondiente.

- **void		walls_detector(t_game *game, int flag, int row, int col)**: Antes de modificar las cordenadas de nuestro `P(Jugador)`, comprobamos que en la nueva posicion no sea un `1(Muro)`. Proseguimos averiguando, segun la `flag` que nos pasan como parametro, la direccion que tomara el `P(Jugador)` y ejecutaremos la funcion de movimiento correspondiente.

**MOVEMENTS.C** : Este archivo detalla la implementación de los movimientos en el juego.

- **void		movement_goku_base(t_game *game, int posx, int posy)**: Esta función constituye la `base` para `gestionar` el `movimiento` del personaje `P(Jugador)` . Se encarga de `actualizar` las `coordenadas` del jugador en función de la acción de movimiento ejecutada. Además, incrementa el contador de pasos realizados a lo largo de la partida. Esta función incluye verificaciones para distintos eventos, como:
    - Recolección de `C(Coleccionables)`
    - Alcance de la `E(Salida)`
    - Encuentro con `F(Enemigos)`

- **void		move_player_up(t_game *game)**: Administra el `desplazamiento` del jugador `hacia arriba`. Previamente a efectuar el movimiento, se `verifica` si la `siguiente` posición corresponde a un `1(Muro)`. Posteriormente, se `actualiza` la `posición` del `P(Jugador)` y se visualiza el movimiento en la terminal utilizando **`ft_printf`**.

- **void		move_player_down(t_game *game)**: Controla el `movimiento` del `P(Jugador)` `hacia abajo`. Similar al movimiento hacia arriba, se `chequea` si la posición siguiente es un `1(Muro)` antes de mover al jugador. La actualización de la posición y la representación del movimiento en la terminal se realizan a continuación.

- **void		move_player_left(t_game *game)**: Gestiona el `desplazamiento` del jugador `hacia la izquierda`. Se efectúa una comprobación para `asegurar` que la `siguiente` coordenada no sea un `1(Muro)` antes de proceder con el movimiento del jugador. El movimiento se muestra en la terminal mediante **`ft_printf`**.

- **void		move_player_right(t_game *game)**: Se encarga del `movimiento` del jugador `hacia la derecha`. Se realiza una `verificación` similar a las `anteriores` para confirmar que la siguiente posición no sea un `1(Muro)`. Tras esto, se `actualiza` la `posición` del `P(Jugador)` y se escribe el movimiento en la terminal.

**MESSAGE.C :** Este archivo contiene los mensajes que usaremos en el juego. Estos mensajes los tendremos definidos en nuestro `define.h`.

- **void		show_moves(t_game *game)**: Esta funcion se utiliza para mostrar en pantalla el `conteo` de `movimientos realizados`. Emplea la función **`mlx_string_put`** para representar el número de movimientos contenidos en la estructura `game`. Dado que esta funcion `requiere` una `cadena de caracteres` y no un numero, se utiliza **`ft_itoa`** para convertir antes de visualizarlo.

- **void		show_error(char *str)**: Muestra como `mensaje de error` el `argumento` que nos dan. Utilizaremos `**ft_putstr_fd**` permitiendo visualizarlo por la terminal.

- **void		show_win(void):** Enseña un `mensaje de victoria` cuando el `P(Jugador)` llegemos a nuestra `E(Salida)`.

- **void		show_lose(void)**: Presenta un `mensaje de derrota` cuando `toquemos a un enemigo`, indicando el final de la partida.
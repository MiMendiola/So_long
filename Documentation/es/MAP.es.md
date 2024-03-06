# Map

Tengamos claro las reglas que tenemos que seguir para la creacion de nuestro mapa:

- La extension del mapa tiene que finalizar en `.ber`.
- Debe ser rectangular.
- Debera estar rodeado por muros.
- Debe tener una salida, un objeto y una posicion inicial.
- 5 caracteres: 0(Espacio), 1(Muro), C(Coleccionable), E(Salida) y P(Jugador).
- Tienes que comprobar si hay un camino válido en el mapa.

Deberemos procesar culquier tipo de mapa siempre y cuando no contenga duplicados de (salida o posición inicial) y que respete todas las reglas anteriores. 

En caso de fallos de cualquier tipo encontrados en el archivo, el programa debe terminar y devolver “Error” seguido de un mensaje de tu elección. Para esto tengo una funcion creada que la podeis encontrar en [GAME](https://www.notion.so/So_Long-69200d7098fd438986ac72d413ac6abf?pvs=21).

Teniendo presentes estas reglas ya podremos `comenzar a crear y parsear` nuestro mapa. Tengo dividido en 2 archivos mis funciones:

**MAP_READ.C**: Contiene las `funciones principales` de nuestra lectura.

- **void		map_read(t_map *map, t_game *game, char *file)**: Es la funcion mas importante de nuestra lectura de mapa, donde llamaremos a todas las demas funciones que hemos creado. Primero comprobaremos la `extension del mapa(**map_ext**)` , proseguiremos consiguiendo las `dimensiones(**map_dimensions**)` para poder utilizarlas al crear la copia. Ahora `copiaremos el mapa(**map_copy**)` en una string y usaremos el `ft_split` para poder `guardar` esa `string` en la `matriz` de la `estructura mapa` y `game` dividiendola por `'\n'` y librearemos nuestra string.
    
    Con nuestro mapa ya guardado podremos hacer la `comprobacion` de `bordes(**map_borders**)` y `caracteres(**map_characters**)`. Despues guardaremos en nuestra `estructura game` la posicion del `P(Jugador)` y la `E(Salida)` con **`check_player`**. Ya finalizando comprobaremos si hay un `camino valido(**map_floodfill_path**)` modificando la matriz de nuestra `estructura map`  y comprobaremos si ha llegado a recoger todos los coleccionables y a podido llegar a la salida con nuestra funcion `**map_collect**`.
    
- **static char	*map_copy(t_map *map, int fd)**: Crearemos una `copia del mapa`. Haremos un bucle de la `altura del mapa` donde leeremos la linea y sacaremos el ancho de la linea leida. Usando la `anchura` que tenemos `guardada en nuestra estructura`, la compararemos a la anchura sacada por cada linea, y con esto hacemos la `comprobacion del mapa rectangular`.
    
    Proseguiremos guardando una `copia de cmap en cmap_aux` con `ft_strdup` y limpiaremos nuestro `cmap antiguo`, para hacer una `nueva string` con la `cmap_aux` y la `nueva linea leida`. Tras esto limpiaremos nuestra `cmap_aux` y nuestra `linea leida` , y seguiremos haciendo esto hasta que nuestro archivo mapa se haya `leido por completo`. 
    
    Por ultimo, haremos una `comprobacion` de que nuestra `primera posicion(primera linea)` y `ultima posicion(ultima linea)` sean distintos de salto de linea(’\n’). De ser um salto de line, podriamos deducir que el mapa no es rectangular o que no esta todo el mapa rodeado por muros.
    
- **static void	map_collect(t_map *map)**: Recorreremos el mapa ya modificado en busca de algun `C(Coleccionable) o E(Salida)` . Si encontramos alguno de estos caracteres, retornaremos el error correspondiente, porque significaria que no ha podido llegar a recoger todos los coleccionables y/o llegar a la salida.

- **static void	map_floodfill_path(t_map *map, int x, int y)**: Realizaremos el `algoritmo` de `relleno por inundacion`. Primero le pasaremos como parametro nuestra estructura map y la posicion exacta de nuestro jugador. Desde este punto iremos recorriendo hacia todos los lados de movimiento posible (Arriba, Abajo, Derecha o Izquierda), rellenando con `' '` aquellas casillas que nuestro `P(jugador)` podria llegar. Restringiremos los movimientos posibles del Jugador definiendo que:
    - No podra atravesar los `1(Muros)`
    - No podra cruzarse a los `F(Enemigos)` ya que al tocarlos nos matan
    - No podra volver a pasar por donde ya hemos pasado ( `' '(Blancos)`)

- **static void	check_player(t_game *game)**: guardaremos las coordenadas de nuestro `P(Jugador)` y nuestra `E(Salida)` en nuestra `estructura game`.

**MAP_CHECKER.C**: En este archivo tendremos `funciones utiles` para nuestra lectura de mapa.

- **void		map_ext(const char *str, const char *to_find)**: Vamos a buscar que en nuestro `argumento` ingresado tenga la extension `“.ber”` como final. Para encontrar si la extension del mapa es valida, utilizaremos una modificacion de una de las funciones de nuestra libreria `ft_strnstr`. Si la extension es diferente devolveremos un error.
- **void		map_dimensions(t_map *map, char *file)**: Se abrira el archivo y usando el `Get_next_line` leeremos la primera linea con un `ft_strlen`, consiguiendo la `anchura` del mapa y seguiremos haciendo esto con un bucle hasta que el `gnl` termine de leer el archivo. De ahi sacaremos la `altura` del mapa. Posteriormente como estas funciones se ejecutaran al principio de nuestro programa, podremos `inicializar variables` de la estructura del mapa (si no lo hacemos podrian igualarse a valores sin sentido).
- **void		map_borders(t_map *map)**: Con la `copia del mapa` en nuestra estructura `map` iremos `recorriendo los bordes`, comprobando que ninguno de los caracteres sea distinto a un muro `(map->map[0][j] != '1')`.
- **void		map_characters(t_map *map, t_game *game)**: Usaremos un bucle para `recorrer` nuestra `matriz` y usaremos la funcion **map_characters_small(map, i, j)**. Le pasaremos como parametros nuestra `estructura map` y las coordenadas de posicion donde bascara en la matriz:
    - Si es `P(Jugador) / E(Salida) / C(Coleccionable) / F(Enemigo)` tendremos un contador en nuestra estructura de cuantos caracteres hay.
    - Si es `P(Jugador)` tambien obtendremos su `posicion X e Y` para utilizarlo mas tarde.
    - En caso que no sea ninguno de los anteriores, tendra que ser un `1(Muro) o 0(Espacio)`.
    - Si es alguno distinto de esos mostraremos un `error`.
    
    Terminando ya con esta funcion mas adelante tendremos una comprobacion para ver que haya solo `1 P(Jugador) / 1 E(Salida) / Entre 1 y 7 C(coleccionables)` (podeis hacer que haya minimo 1 coleccionable, pero yo quise darle por la tematica un maximo de 7).
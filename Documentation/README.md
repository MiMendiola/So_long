# So_Long

<div>

  ![Proyecto](https://img.shields.io/badge/Proyecto-So_Long-blue)
  ![Licencia](https://img.shields.io/badge/Licencia-MIT-orange)
  ![Versión](https://img.shields.io/badge/Versión-1.0-green)
  <a href="https://github.com/MiMendiola/Ft_printf/tree/main/Documentation/README.es.md" >
    <img src="https://img.shields.io/badge/Change_Language-English-purple" align="right">
  </a>

</div>

Este proyecto es un pequeño juego en 2D. Está diseñado para hacerte trabajar con texturas y sprites y algunos otros elementos básicos de jugabilidad.

Ser desarrollador es genial si quieres crear tu propio juego. Pero un buen juego necesita recursos gráficos buenos. Para juegos 2D, debes buscar tiles, tilesets, sprites y sprite sheets. Por suerte para ti, algunos artistas con talento están dispuestos a compartir su trabajo en plataformas como:

itch.io

Hagas lo que hagas, respeta el trabajo de otros.

---

¡Llegó el momento de crear un proyecto de diseño gráfico básico! so_long te ayudará a mejorar tus habilidades en estas áreas: ventanas, colores, eventos, texturas, etc. Vas a usar la librería gráfica del campus MiniLibX. Esta librería se ha desarrollado
internamente e incluye las herramientas básicas necesarias para abrir una ventana, crear imágenes y trabajar con eventos de teclado y ratón. Los objetivos de este proyecto son similares a los de este primer año: rigor, uso de C, uso de algoritmos básicos, búsqueda de información, etc.

SoLong And thanks for all the fish!

---

Tu proyecto debe cumplir con las siguientes normas:

• Debes usar la miniLibX. Ya sea la versión disponible en el sistema operativo, o su fuente. Si eliges trabajar con la fuente, deberás compilar siguiendo las mismas. normas que con tu libft, descritas en la parte de Instrucciones generales.

• Debes entregar un Makefile que compile con tus archivos fuente.

• Tu programa debe aceptar como primer argumento un archivo con la descripción
del mapa de extensión .ber.

---

IV.1. Juego

• El objetivo del jugador es recolectar todos los objetos presentes en el mapa y salir eligiendo la ruta más corta posible.

• Las teclas W, A, S y D se utilizarán para mover al personaje principal.

• El jugador debe poder moverse en 4 direcciones: subir, bajar, ir a la izquierda o ir a la derecha.

• El jugador no puede entrar dentro de las paredes.

• Tras cada movimiento, el número real de movimientosdebe mostrarse en un terminal.

• Utilizarás una perspectiva 2D (vista de pájaro o lateral).

• El juego no necesita ser en tiempo real.

• Aunque los ejemplos dados se refieren a una temática de delfín, puedes crear el mundo que quieras.

Si lo prefieres, puedes utilizar ZQSD o las teclas de dirección para mover el personaje principal.

---

IV.2. Gestión de gráficos

• El programa mostrará la imagen en una ventana.

• La gestión de tu ventana debe ser limpia (cambiar de ventana, minimizar, etc)

• Pulsar la tecla ESC debe cerrar la ventana y cerrar el programa limpiamente.

• Hacer clic en la cruz roja de la ventana debe cerrar la ventana y terminar el programa limpiamente.

• El uso de images de la miniLibX es obligatorio

---

IV.3. Mapa

• El mapa estará construido de 3 componentes: paredes, objetos y espacio abierto.

• El mapa estará compuesto de solo 5 caracteres: 0 para un espacio vacío, 1 para un muro, C para un coleccionable, E para salir del mapa y P para la posición inicial del jugador.

• El mapa debe tener una salida, al menos un objeto y una posición inicial.

Si el mapa contiene caractéres duplicados (salida o posición inicial), deberás mostrar un mensaje de error.

• El mapa debe ser rectangular.

• El mapa deberá estar cerrado/rodeado de muros, en caso contrario el programa deberá devolver un error.

• Tienes que comprobar si hay un camino válido en el mapa.

• Debes poder procesar cualquier tipo de mapa, siempre y cuando respete las anteriores normas.

• En caso de fallos de configuración de cualquier tipo encontrados en el archivo, el programa debe terminar correctamente y devolver “Error\n” seguido de un mensaje explícito de tu elección.

---

Parte extra

Normalmente te animaríamos a que desarrollaras algunas funcionalidades extras originales tuyas. Sin embargo, habrá proyectos gráficos mucho más interesantes más adelante. ¡Te están esperando! ¡No pierdas demasiado tiempo en este encargo!
Se permite el uso de otras funciones para completar la parte extra, siempre y cuando su uso se justifique durante la evaluación. Sé inteligente.

Conseguirás puntos extra si:

• Haces que el jugador pierda cuando toque una patrulla de enemigos

• Añades algunas animaciones de sprites.

• Muestras el contador de movimiento directamente en la pantalla en lugar de en el terminal.

---

## Tabla de Contenidos

<div style="display:flex;">
	<div style="width:50%; margin-left: 5%">
		SOURCES
		<ul style="list-style-type:none;">
			<li style="margin-bottom: 10px">
				<details>
				<summary><a href="https://example.com">So_long.c</a></summary>
					Aqui tendremos nuestro programa principal donde iniciaremos nuestras <code>estructuras</code> e <code>iniciaremos nuestro juego</code> y comprobaremos nuestro <code>mapa</code>.
				</details>
			</li>
			<li style="margin-bottom: 10px">
				<details>
					<summary><a href="https://example.com">Game</a></summary>
					Aqui algo de texto
					<ul>
						<li>
							<a href="https://example.com">Game.c</a>
						</li>
						<li>
							<a href="https://example.com">Message.c</a>
						</li>
					</ul>
				</details>
			</li>
			<li style="margin-bottom: 10px">
				<details>
					<summary><a href="https://example.com">Map Parse</a></summary>
					Aqui algo de texto
					<ul>
						<li>
							<a href="https://example.com">Map_read.c</a>
						</li>
						<li>
							<a href="https://example.com">Map_checker.c</a>
						</li>
					</ul>
				</details>
			</li>
			<li style="margin-bottom: 10px">
				<details>
					<summary><a href="https://example.com">Movements</a></summary>
					Aqui algo de texto
					<ul>
						<li>
							<a href="https://example.com">Movements.c</a>
						</li>
						<li>
							<a href="https://example.com">Frames_Charger.c</a>
						</li>
					</ul>
				</details>
			</li>
			<li style="margin-bottom: 10px">
				<details>
					<summary><a href="https://example.com">Sprites</a></summary>
					Aqui algo de texto
					<ul>
						<li>
							<a href="https://example.com">Sprite_Generator.c</a>
						</li>
						<li>
							<a href="https://example.com">Sprite_Creator.c</a>
						</li>
					</ul>
				</details>
			</li>
		</ul>
	</div>
	<div style="width:50%; margin-left: 5%">
		BONUS
		<ul style="list-style-type:none;">
			<li style="margin-bottom: 10px">
				<details>
				<summary><a href="https://example.com">So_long.c</a></summary>
					En el bonus tendremos una funcion adicional donde <code>cerraremos la ventana con la equis</code>.
				</details>
			</li>
			<li style="margin-bottom: 10px">
				<details>
					<summary><a href="https://example.com">Game</a></summary>
					Aqui algo de texto
					<ul>
						<li>
							<a href="https://example.com">Game.c</a>
						</li>
						<li>
							<a href="https://example.com">Message.c</a>
						</li>
					</ul>
				</details>
			</li>
			<li style="margin-bottom: 10px">
				<details>
					<summary><a href="https://example.com">Map Parse</a></summary>
					Aqui algo de texto
					<ul>
						<li>
							<a href="https://example.com">Map_read.c</a>
						</li>
						<li>
							<a href="https://example.com">Map_checker.c</a>
						</li>
					</ul>
				</details>
			</li>
			<li style="margin-bottom: 10px">
				<details>
					<summary><a href="https://example.com">Movements</a></summary>
					Aqui algo de texto
					<ul>
						<li>
							<a href="https://example.com">Movements.c</a>
						</li>
						<li>
							<a href="https://example.com">Frames_Charger.c</a>
						</li>
					</ul>
				</details>
			</li>
			<li style="margin-bottom: 10px">
				<details>
					<summary><a href="https://example.com">Sprites</a></summary>
					Aqui algo de texto
					<ul>
						<li>
							<a href="https://example.com">Sprite_Generator.c</a>
						</li>
						<li>
							<a href="https://example.com">Sprite_Covers.c</a>
						</li>
						<li>
							<a href="https://example.com">Sprite_Creator.c</a>
						</li>
					</ul>
				</details>
			</li>
		</ul>
	</div>
</div>

---

## Recomendaciones

Investigate how to work with `variadic functions` and what possibilities of use we have with them.

Have a clear idea of what `type of conversions` we need to perform and how to make those conversions. For this, you can seek help from some functions in the library, but remember that you cannot include `Libft`.

Find out and understand how `hexadecimal numbers` work, how they became what they are, and how we can use them to our advantage. Similarly, with `pointer addresses`, understand how they are formed and how to use them.

Keep in mind that we have to return the total sum of what is printed on the screen, so it would be good to have a `counter` that helps us.

---

## Contacto

Si tienes alguna pregunta, sugerencia o comentario sobre ft_printf, no dudes en ponerte en contacto conmigo:

- Correo Electrónico: <a href="mailto:mglmendiol@gmail.com" style="text-decoration: none; color:#fff">mglmendiol@gmail.com</a>
- LinkedIn: <a href="https://www.linkedin.com/in/mimendiola/" style="text-decoration: none; color:#fff;">https://www.linkedin.com/in/mimendiola/</a>

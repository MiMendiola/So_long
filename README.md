# So_Long

<div>

  ![Project](https://img.shields.io/badge/Project-So_Long-blue)
  ![Licence](https://img.shields.io/badge/Licence-MIT-orange)
  ![Version](https://img.shields.io/badge/Version-1.0-green)
  <a href="https://github.com/MiMendiola/So_long/tree/main/Documentation/es/README.es.md" >
    <img src="https://img.shields.io/badge/Cambiar_Idioma-Español-purple" align="right">
  </a>

</div>

![video](https://github.com/MiMendiola/So_long/assets/98388947/d7297805-0d39-43b6-a6ef-76c4b5b1bbd1)

The objective of the project is the creation of a **`2D game`**, providing an introduction to video game development by working with **`textures`**, **`sprites`**, and **`event management`** through the use of the **`MiniLibX graphic library`**. This teaches us how to handle graphical elements and user events, understanding better data **`structures`**.

The bonus part includes additional functionalities such as:

- Adding some sprite `animations`.
- Penalization when `touching an enemy`.
- Displaying the `step` counter on the `screen`.

For more information, you can find a **`more detailed explanation`** of each part in the **`Table of Contents`** section.

For the development of the game, I focused on making it more modular, dividing the **`so_long.h`** file into several files: **`structs.h`** to define my structures, **`defines.h`** for constants and utilities, and **`so_long.h`** for the project's functions, improving the code's readability and organization.

The map represents the core of the game, making its creation and analysis crucial. We use the **`t_map`** structure for parsing and modifying the map, and **`t_game`** for the graphical representation of the game and the management of the **`P(Player)`** movements. In the map validation, we use a **`flood fill`** algorithm to check if there is a valid path, implemented recursively.

The gameplay consists of a **`representation through sprites`**, whose **`size`** is derived from the **`dimensions of the map`** and the **`images used`**. The movements of `P(Player)` are made through **`keyboard events`**, complemented by a loop for **`animations`** and a function for displaying the steps taken, all managed by the **`MLX`**. Additionally, we will have to manage the game's exit through **`window closing`** or pressing the **`ESC`** key.

Finally, the **`sprites`** will be optimized by **`storing`** them in a **`dedicated structure`**, simplifying their management in the game. This will facilitate the modification and updating of the `P(Player)` position depending on the user's interaction with the keyboard, ensuring a dynamic and fluid game experience.

---

## **Table of Contents**

[MAP](https://github.com/MiMendiola/So_long/tree/main/Documentation/MAP.md)

[GAME](https://github.com/MiMendiola/So_long/tree/main/Documentation/GAME.md)

[SPRITES](https://github.com/MiMendiola/So_long/tree/main/Documentation/SPRITES.md)

---

## **Recommendations**

Check [42Docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) for detailed information about the library.

Organize pending tasks in a **`separate list`**.

From the beginning of the project, use **`system("leaks -q so_long")`** and add the flags **`-g3 -fsanitize=address`** in the makefile. Essential for managing any issue.

Use the **`exit`** function in the program for proper termination.

Maintain **`two separate copies`** of the **`map`** within the project, allowing its use for different purposes.

Initialize **`structures`** at the start of the project. Include nested structures within the main ones to minimize the need for later memory allocation.

Begin with the **`creation and analysis`** of the map. It's crucial to learn the **`flood fill algorithm`**.

Store **`images`** from the beginning in a structure, ensuring they all have the **`same size`**.

---

## **Contact**

If you have any questions, suggestions, or comments about So_long, feel free to contact me:

- Email:
[mglmendiol@gmail.com](mailto:mglmendiol@gmail.com)
- LinkedIn:
[https://www.linkedin.com/in/mimendiola/](https://www.linkedin.com/in/mimendiola/)

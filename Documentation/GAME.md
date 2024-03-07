# Game

The rules we must follow for our game are:

- The goal of the `P(Player)` is to collect all `C(Items)` present on the map and exit through the `E(Exit)`.
- The `W, A, S, and D` keys or `arrow keys` will be used to move the main character.
- The player must be able to `move in 4 directions`.
- The player `cannot enter walls`.
- After each move, the actual number of `moves` must be `displayed in a terminal`.
- Use a `2D perspective` (top-down or side view).
- The game does not need to be in real-time.
- You can create the world as you wish.

I have 3 different files, each responsible for a part of the game:

**GAME.C**: This file centralizes `event management` and the main `game logic`.

- **void game_init(t_game *game, t_map *map)**: We could not run the game without it. We will first start our game with **`mlx_init()`**, and keep it in a loop with **`mlx_loop(mlx)`**. We will initiate the window with **`mlx_new_window`** with the size of our map multiplied by the image size (displaying the images, not just the matrix).
    
    We will continue by **`creating and initializing the sprites(creator_sprites)`** needed for our game. We will use **`mlx_hook`** to perform certain functions when an event occurs, such as when clicking on the `X(closing the program)`, pressing any of the keys with **`mlx_key_hook`**, or executing a function in a loop until closing the program with **`mlx_loop_hook`**.
    
- **int frame_executor(t_game *game)**: A function that will be `called recursively` until we finish our program. With this function, we will `repaint the map` with all its characters, updating the `steps` on the screen and running our `frame counter` to create our `animations`.

- **int frames_counter(t_game *game)**: This will be our `frame counter`, to which we will assign an amount of `60ms`. When we exceed this amount, we will `restart the counter` to 0. This will provide us with the possibility to `vary` between `images`, depending on the frame.

- **int key_press(int keycode, t_game *game)**: Depending on the `key pressed`, it will provide us with its code, and the new coordinates of our `P(Player)` will be sent, modified towards the corresponding `direction`.

- **void walls_detector(t_game *game, int flag, int row, int col)**: Before modifying the coordinates of our `P(Player)`, we check that the new position is not a `1(Wall)`. We proceed to find out, according to the `flag` passed as a parameter, the direction the `P(Player)` will take and execute the corresponding movement function.

**MOVEMENTS.C**: This file details the `implementation of movements` in the game.

- **void movement_goku_base(t_game *game, int posx, int posy)**: This function serves as the `base` for `managing` the `movement` of the character `P(Player)`. It is responsible for `updating` the `coordinates` of the player based on the executed movement action. Additionally, it increases the step counter throughout the game. This function includes checks for various events, such as:
    - Collecting `C(Items)`
    - Reaching the `E(Exit)`
    - Encountering `F(Enemies)`

- **void move_player_up(t_game *game)**: Manages the `movement` of the player `upwards`. Before executing the move, it `verifies` if the `next` position corresponds to a `1(Wall)`. After that, the `position` of the `P(Player)` is `updated`, and the movement is displayed in the terminal using **`ft_printf`**.

- **void move_player_down(t_game *game)**: Controls the `movement` of the `P(Player)` `downwards`. Similar to the upward movement, it `checks` if the next position is a `1(Wall)` before moving the player. The position update and the depiction of the movement in the terminal are then carried out.

- **void move_player_left(t_game *game)**: Handles the `movement` of the player `to the left`. A check is performed to `ensure` that the `next` coordinate is not a `1(Wall)` before proceeding with the player's movement. The movement is shown in the terminal through **`ft_printf`**.

- **void move_player_right(t_game *game)**: Manages the `movement` of the player `to the right`. A similar `verification` to the `previous` ones is carried out to confirm that the next position is not a `1(Wall)`. After this, the `position` of the `P(Player)` is `updated`, and the movement is written in the terminal.

**MESSAGE.C**: This file contains the messages we will use in the game. These messages will be defined in our `define.h`.

- **void show_moves(t_game *game)**: This function is used to display on the screen the `count` of `moves made`. It uses the **`mlx_string_put`** function to represent the number of movements contained in the `game` structure. Since this function `requires` a `string of characters` and not a number, **`ft_itoa`** is used to convert before displaying.

- **void show_error(char *str)**: Displays an `error message` with the `argument` given. We will use **`ft_putstr_fd`**, allowing it to be viewed through the terminal.

- **void show_win(void)**: Shows a `victory message` when the `P(Player)` reaches our `E(Exit)`.

- **void show_lose(void)**: Presents a `defeat message` when `we touch an enemy`, indicating the end of the game.
# Sprites

For our game, we need to follow this rules:

- The program `will display` the image in a `window`.
- The `management of your window` must be `clean` (switching windows, minimizing, etc).
- Pressing the `ESC key` must close the window and `exit the program` cleanly.
- Clicking the `red cross` on the window should `close the window` and cleanly terminate the program.
- The use of `images` from `miniLibX` is mandatory.

We will have 3 files dedicated to the map's sprites:

**SPRITE_GENERATOR.C**: This file will contain the functions for `displaying our sprites` through the game window.

- **void		sprite_map(t_game** ***game):** Will be responsible for `loop drawing` the game elements. We start by verifying with a flag that the cover has not been done a certain number of times. Subsequently, we will draw the **`character sprites(sprite_characters)`** and display the `E(Exit)` when there are no `C(Items)` left on the map.

- **void		sprite_player(t_game** ***game, int row, int col):** In this function, we depends on the `direction of movement` of the `P(Player)`, which is stored in a `flag`, to determine how to draw the player's sprite in the game.

- **void sprite_exit(t_game *game, int i, int j)**: This function decides how to draw the exit depending on the number of `C(Items)` in the game.

- **void sprite_balls(t_game *game, int i, int j)**: This function is used to draw the `C(Items)` in the game, depending on their quantity.

- **void		sprite_characters(t_game** ***game):** We will loop through to `paint` the corresponding `sprites` depending on the `character` found. If a `P(Player)` is found, we will use the **`sprite_player`** function to draw its animations.

**SPRITE_COVERS.C**: Generation of the game's loading screen

- **void sprite_covers(t_game *game, int posx)**: We will use this to `paint the loading screen` of the game, adjusting the image based on the `x position` provided. We will achieve the `middle of the screen` and by `modifying its side position` of the image to create a sense of movement.

**SPRITE_CREATOR.C**: `Creation and storage` of the `images` used in the game.

- **void creator_sprites(t_game *game)**: First, we `assign the necessary size` to the `images` that we will store in the structure `t_init_sprites`. Then we continue with the `creation and storage of the sprites` used in the game.

- **static void create_sprites_objs(t_game *game)**: The `sprites` of all the `objects` in the game are created.

- **static void create_sprites_gokubase(t_game *game)**: The `sprites` of the `P(Player)` are generated for use when needed.

- **static void *load_cover(t_game *game, char *path)**: Function that `generates` the `cover` image for the `loading screen`, including a `check` for the image's existence.

- **static void *load_image(t_game *game, char *path)**: Focus to `create the image` we need `depending` on the `image path` given to us, with a `check` for the image's existence.

**FRAMES_CHARGER.C**: Contains the `functions` for the `game animations`. The `number of frames` you see can be modified according to your preferences. In the case of **`frame_stay`**, it will always be active without the need for a loop, while the others will need to complete a full cycle, so we force this loop.

- **void frames_stay(t_game *game, int x, int y)**: Represents the idle or `IDLE` animation of any normal game, with continuous movement.

- **void		frames_move_up(t_game** ***game, int x, int y):** Animates upward movement.

- **void		frames_move_down(t_game** ***game, int x, int y):** Animates downward movement.

- **void frames_move_left(t_game** ***game, int x, int y):** Animates leftward movement.

- **void frames_move_right(t_game** ***game, int x, int y):** Animates rightward movement.


























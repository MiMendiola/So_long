# Map

Let's be clear about the rules we must follow for creating our map:

- The map's file extension must end with **`.ber`**.
- It must be `rectangular`.
- It should be `surrounded by walls`.
- There must be `one exit`, `one item`, and `one starting position`.
- Five characters are used: `0(Space)`, `1(Wall)`, `C(Item)`, `E(Exit)`, and `P(Player)`.
- You must ensure there is a valid path on the map.

We should be able to process any map as long as it does not contain duplicates of the exit or starting position and respects all the above rules.

In the event of any kind of error found in the file, the program must terminate and return "Error" followed by a message of your choice. For this, I have a function you can find on [GAME](https://github.com/MiMendiola/So_long/tree/main/Documentation/GAME.md).

With these rules in mind, we can now **`start creating and parsing`** our map. I have divided my functions into 2 files:

**MAP_READ.C**: Contain the **`main functions`** for our map reading.

- **void map_read(t_map *map, t_game *game, char *file)**: Is the most important function for our map reading, where we will call all other functions we have created. We'll first check the **`map's extension(map_ext)`**, then proceed to obtain the **`dimensions(map_dimensions)`** to use them when creating the copy. Next, we'll **`copy the map(map_copy)`** into a string and use **`ft_split`** to `store` that `string` in the `matrix` of the `map` and `game` structures by splitting it by `'\n'` and freeing our string.
    
    With our map stored, we can then perform the **`border check(map_borders)`** and **`character check(map_characters)`**. Afterwards, we'll store the `P(Player)` and `E(Exit)` positions in our `game` structure with **`check_player`**. Finally, we'll check for a **`valid path(map_floodfill_path)`** by modifying the matrix of our `map` structure and check if it has collected all collectibles and reached the exit with our **`map_collect`** function.
    
- **static char *map_copy(t_map *map, int fd)**: We will create a `copy of the map`. We'll loop over the `map's height`, reading each line and extracting the width of the read line. Using the `width` stored in our structure, we'll compare it to the width extracted from each line, performing the `rectangular map check`.
    
    We'll proceed by saving a `copy of cmap in cmap_aux` with **`ft_strdup`** and clearing our `old cmap`, to create a `new string` with `cmap_aux` and the `newly read line`. After this, we'll clear our `cmap_aux` and our `read line`, and continue doing this until our map file has been `completely read`.
    
    Finally, we'll perform a `check` to ensure our `first position(first line)` and `last position(last line)` are not equal to a newline (`'\n'`). If it's a newline, we might deduce that the map is not rectangular or that not all of the map is surrounded by walls.

- **static void map_collect(t_map *map)**: We'll go through the modified map in search of any `C(Collectible) or E(Exit)`. If we find any of these characters, we'll return the corresponding error, because it would mean that it has not been able to collect all the collectibles and/or reach the exit.

- **static void map_floodfill_path(t_map *map, int x, int y)**: We'll perform the **`flood fill algorithm`**. We'll first pass our map structure and the exact position of our player as parameters. From this point, we'll go through in all possible movement directions (Up, Down, Right, or Left), filling with `' '` those squares that our `P(player)` could reach. We'll restrict the player's possible movements by defining that:
    - They cannot pass through `1(Walls)`
    - They cannot cross to `F(Enemies)` as touching them would kill us
    - They cannot pass where we have already been (`' '` (Whites))

- **static void check_player(t_game *game)**: We'll store the coordinates of our `P(Player)` and our `E(Exit)` in our `game` structure.

**MAP_CHECKER.C**: We will have `useful functions` for our map reading.

- **void map_ext(const char *str, const char *to_find)**: We will check that our `input argument` has the `.ber` extension at the end. To find if the map extension is valid, we'll use a modification of one of our library functions **`ft_strnstr`**. If the extension is different, we'll return an error.

- **void map_dimensions(t_map *map, char *file)**: We'll open the file and use **`Get_next_line`** to read the first line with a **`ft_strlen`**, obtaining the `width` of the map, and we'll continue doing this with a loop until the `gnl` finishes reading the file. From there, we'll obtain the `height` of the map. As these functions will run at the beginning of our program, we can `initialize variables` of the map structure(if we don't, they could be equal to nonsensical values).

- **void map_borders(t_map *map)**: With the `copy of the map` in our `map` structure, we'll `traverse the borders`, checking that none of the characters are different from a wall `(map->map[0][j] != '1')`.

- **void map_characters(t_map *map, t_game *game)**: We'll use a loop to `traverse` our `matrix` and we'll use the function **map_characters_small(map, i, j)**. We'll pass as parameters our `map` structure and the coordinates of the position to search in the matrix:After finishing with this function, later on, we'll have a check to see that there is only `1 P(Player) / 1 E(Exit) / Between 1 and 7 C(collectibles)` (you can make it so there's a minimum of 1 collectible, but I wanted to give a maximum of 7 for thematic reasons).
    - If it's `P(Player) / E(Exit) / C(Collectible) / F(Enemy)`, we'll have a counter in our structure for how many characters there are.
    - If it's `P(Player)`, we'll also get its `X and Y position` for later use.
    - If it's none of the above, it has to be a `1(Wall) or 0(Space)`.
    - If it's any different from those, we'll show an `error`.
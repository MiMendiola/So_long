/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:33:55 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/18 16:00:24 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// IMAGE SIZE
#define PIXELS 64

// SETTINGS KEYS
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_UP 126
#define KEY_LEFT 123
#define KEY_DOWN 125
#define KEY_RIGHT 124
#define ON_DESTROY 17

// ERRORS MESSAGES
#define WINS "\nGOKU ALWAYS WINS!\n\n"
#define LOSE "YOU ARE NOT A TRUE HERO"

#define ERROR_LOADING_IMG "Error loading image\n"
#define ERROR_EXTENSION_MAP "Please, check the map extension\n"
#define ERROR_FILE "File error\n"
#define ERROR_NOT_RECTANGULAR "Map is not rectangular\n"
#define ERROR_FIRST_LAST_LINE "Check the first or last line of your map\n"
#define ERROR_NOT_WALLS "Map not surrounded by walls\n"
#define ERROR_MAP_ELEMENTS "Some elements are incorrect\n"
#define ERROR_CHARACTERS_NOT_VALID "Characters invalid\n"

// IMAGES PATH
#define WALLS "./textures/floors&walls/wall.xpm"
#define FLOOR "./textures/floors&walls/floor 1.xpm"

#define BALL1 "./textures/balls/1.xpm"
#define BALL2 "./textures/balls/2.xpm"
#define BALL3 "./textures/balls/3.xpm"
#define BALL4 "./textures/balls/4.xpm"
#define BALL5 "./textures/balls/ball5.xpm"
#define BALL6 "./textures/balls/ball6.xpm"
#define BALL7 "./textures/balls/ball7.xpm"

#define EXIT1 "./textures/exit/ball1.xpm"
#define EXIT2 "./textures/exit/exit2.xpm"
#define EXIT3 "./textures/exit/exit3.xpm"
#define EXIT4 "./textures/exit/exit4.xpm"
#define EXIT5 "./textures/exit/exit5.xpm"
#define EXIT6 "./textures/exit/exit6.xpm"
#define EXIT7 "./textures/exit/exit7.xpm"

#define GOKUBASE "./textures/goku_base/0.xpm"
#define GOKUBASE1 "./textures/goku_base/1.xpm"
#define GOKUBASE2 "./textures/goku_base/2.xpm"
#define GOKUBASE3 "./textures/goku_base/goku_base.xpm"
#define GOKUBASE4 "./textures/goku_base/4.xpm"
#define GOKUBASE5 "./textures/goku_base/5.xpm"
#define GOKUBASE6 "./textures/goku_base/6.xpm"
#define GOKUBASE7 "./textures/goku_base/7.xpm"
#define GOKUBASE8 "./textures/goku_base/8.xpm"
#define GOKUBASE9 "./textures/goku_base/9.xpm"
#define GOKUBASE10 "./textures/goku_base/10.xpm"
#define GOKUBASE11 "./textures/goku_base/11.xpm"
#define GOKUBASE12 "./textures/goku_base/12.xpm"
#define GOKUBASE13 "./textures/goku_base/13.xpm"
#define GOKUBASE14 "./textures/goku_base/14.xpm"
#define GOKUBASE15 "./textures/goku_base/15.xpm"

#define GOKUN	0
#define GOKUS1	1
#define GOKUS2	2
#define GOKUS3	3

// SETTINGS COLORS
#define BLACK "\x1B[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1B[37m"
#define ORANGE "\x1B[38;2;255;128;0m"
#define ROSE "\x1B[38;2;255;151;203m"
#define LBLUE "\x1B[38;2;53;149;240m"
#define LGREEN "\x1B[38;2;17;245;120m"
#define GRAY "\x1B[38;2;176;174;174m"
#define CLEAR "\x1b[0m"

// SETTINGS BACKGROUND COLORS
#define BG_BLACK "\x1B[40m"
#define BG_RED "\x1B[41m"
#define BG_GREEN "\x1B[42m"
#define BG_YELLOW "\x1B[43m"
#define BG_BLUE "\x1B[44m"
#define BG_MAGENTA "\x1B[45m"
#define BG_CYAN "\x1B[46m"
#define BG_WHITE "\x1B[47m"
#define BG_ORANGE "\x1B[48;2;255;128;0m"
#define BG_LBLUE "\x1B[48;2;53;149;240m"
#define BG_LGREEN "\x1B[48;2;17;245;120m"
#define BG_GRAY "\x1B[48;2;176;174;174m"
#define BG_ROSE "\x1B[48;2;255;151;203m"
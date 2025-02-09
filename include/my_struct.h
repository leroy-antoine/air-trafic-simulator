/*
** EPITECH PROJECT, 2024
** my_struct.h
** File description:
** struct for this project
*/

#ifndef MY_STRUCT
    #define MY_STRUCT
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #define ERROR 84
    #define SUCCESS 0
    #define H_FLAG 24
    #define OPEN_ERROR -1
    #define END_LIST 9.8
    #define BACKGROUND "png/background.png"
    #define PLANE "png/plane.png"
    #define TOWER "png/tower.png"
    #define SIZE 20
    #define SIZEx 0.075
    #define SIZEy 0.070

typedef struct sprite {
    sfTexture *texture;
    sfSprite *sprite;
} sprite_t;

typedef struct plane {
    sfVector2f position;
    sfVector2f arrival;
    sfRectangleShape *plane_shape;
    sprite_t plane_sprite;
    float entity_time;
    int speed;
    int delay;
    int ID;
    float end;
    bool alive;
} plane_t;

typedef struct tower {
    sfVector2f position;
    sfCircleShape *tower_shape;
    sprite_t tower_sprite;
    int ID;
    int radius;
    float end;
} tower_t;

int h_flag(void);
int parse_argument(char **argv);
int how_to_use(void);
int my_radar(plane_t *plane, tower_t *tower);
int handle_sprite(plane_t *plane, tower_t *tower, sprite_t *background,
    int handle_errors);
sfRenderWindow *create_window(void);
void handle_event(sfRenderWindow *window);
int parse_infos(char **argv);
sfRectangleShape *set_rect_shape(sfRectangleShape *plane_shape,
    sfVector2f position);
sfCircleShape *set_circle_shape(tower_t *tower, int ID);
void modify_position(plane_t *plane, float dt);
sfVector2f lerp_vector(sfVector2f begin, sfVector2f end, float progression);

#endif /* MY_STRUCT */

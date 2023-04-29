/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** include
*/

#ifndef MYHUNTER_H_
    #define MYHUNTER_H_

    #include <SFML/Config.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <stdio.h>
    #include <stdlib.h>

#define IMAGE_BG        "./assets/mountains.jpg"
#define DUCK_SPRITE     "./assets/spritesheet.png"
#define MENU_BUTTON     "./assets/menu2.png"
#define MENU_FONT       "./assets/play.ttf"
#define AIM_PNG         "./assets/aim.png"
#define GAMEOVER_FONT   "./assets/GrinchedRegular.otf"

void duck_game_over(sfVideoMode mode, sfRenderWindow *window,
                    sfVector2f position);

void move_rect(sfIntRect *rect);

void manage_mouse_move(sfRenderWindow *window);

void duck_movement(sfTexture *texture, sfSprite *sprite,
                    sfIntRect *rect, sfClock *clock);

void manage_mouse_click(sfMouseButtonEvent mouse_event, sfSprite *sprite,
                        sfVector2f position, sfVector2f origin);

void analyse_events(sfRenderWindow *window, sfSprite *sprite,
                    sfVector2f position);

void duck_loop(sfVideoMode mode, sfSprite *sprite,
                sfVector2f position);

int my_strcmp(char const *s1, char const *s2);

void manage_mouse_menu(sfMouseButtonEvent mouse_event,
                        sfRenderWindow *window_menu);

void analyse_event_menu(sfRenderWindow *window_menu);

void render_window(sfRenderWindow *window, sfSprite *sprite);

void create_window(sfRenderWindow *window);

void text_game_over(sfRenderWindow *window_game_over);

void text_play_again(sfRenderWindow *window_game_over);

#endif /* !MYHUNTER_H_ */

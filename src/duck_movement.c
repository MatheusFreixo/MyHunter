/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** Functions to move the duck
*/

#include "./../include/myhunter.h"

void create_game_over(sfRenderWindow *window_game_over);

void move_rect(sfIntRect *rect)
{
    rect->left = rect->left + 110;
    if (rect->left == 330){
        rect->left = 0;
    }
}

void duck_movement(sfTexture *texture, sfSprite *sprite,
                    sfIntRect *rect, sfClock *clock)
{
    float seconds;
    sfTime time;
    sfVector2f vector = {10, 0};

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 100000.0;
    if (seconds > 0.5){
        move_rect(rect);
        sfClock_restart(clock);
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, *rect);
    sfSprite_move(sprite, vector);
}

void duck_loop(sfVideoMode mode, sfSprite *sprite,
                sfVector2f position)
{
    sfVector2f origin = {0, rand() % 500};
    if (position.x == mode.width){
        sfSprite_setPosition(sprite, origin);
    }
}

void duck_game_over(sfVideoMode mode, sfRenderWindow *window,
                    sfVector2f position)
{
    sfRenderWindow *window_game_over;
    if (position.x == mode.width){
        sfRenderWindow_close(window);
        create_game_over(window_game_over);
    }
}

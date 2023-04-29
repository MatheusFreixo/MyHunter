/*
** EPITECH PROJECT, 2022
** BS my_hunter
** File description:
** ...
*/

#include "./../include/myhunter.h"

void auxiliar_window(sfVideoMode mode, sfRenderWindow *window,
                    sfSprite *sprite, sfVector2f pos)
{
    duck_loop(mode, sprite, pos);
    duck_game_over(mode, window, pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    analyse_events(window, sprite, pos);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

void background (sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile(IMAGE_BG, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void create_window(sfRenderWindow *window)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfClock *clock;
    window = sfRenderWindow_create(
        mode, "My Hunter", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 100);
    sfTexture *texture = sfTexture_createFromFile(DUCK_SPRITE, NULL);
    sfSprite *sprite = sfSprite_create();
    sfIntRect rect = {0,0,110, 110};
    sfVector2f pos;
    sfVector2f origin = {-250, rand() % 800};
    sfSprite_setPosition(sprite, origin);
    clock = sfClock_create();
    while (sfRenderWindow_isOpen(window)){
        background(window);
        duck_movement(texture, sprite, &rect, clock);
        pos = sfSprite_getPosition(sprite);
        auxiliar_window(mode, window, sprite, pos);
    }sfRenderWindow_destroy(window);
}

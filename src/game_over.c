/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** Functions to display the window when the game is over
*/

#include "./../include/myhunter.h"

void manage_mouse_game_over(sfMouseButtonEvent mouse_event,
                            sfRenderWindow *window_game_over)
{
    sfRenderWindow *window;
    sfVector2f play_again_position = {500, 500};
    sfVector2f quit_position = {1100, 500};

    if (mouse_event.x <= play_again_position.x + 400 &&
        mouse_event.x >= play_again_position.x &&
        mouse_event.y <= play_again_position.y + 150 &&
        mouse_event.y >= play_again_position.y){
        sfRenderWindow_close(window_game_over);
        create_window(window);
    }
    if (mouse_event.x <= quit_position.x + 400 &&
        mouse_event.x >= quit_position.x &&
        mouse_event.y <= quit_position.y + 150 &&
        mouse_event.y >= quit_position.y){
        sfRenderWindow_close(window_game_over);
    }
}

void analyse_event_game_over(sfRenderWindow *window_game_over)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window_game_over, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window_game_over);
        if (event.type == sfEvtMouseButtonPressed){
            manage_mouse_game_over(event.mouseButton, window_game_over);
        }
    }
}

void images_game_over(sfRenderWindow *window_game_over)
{
    sfTexture *texture = sfTexture_createFromFile(IMAGE_BG, NULL);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture_button = sfTexture_createFromFile(MENU_BUTTON, NULL);
    sfSprite *sprite_button = sfSprite_create();
    sfVector2f position = {500, 500};
    sfSprite_setPosition(sprite_button, position);
    sfTexture *texture_button2 = sfTexture_createFromFile(MENU_BUTTON, NULL);
    sfSprite *sprite_button2 = sfSprite_create();
    sfVector2f position2 = {1100, 500};
    sfSprite_setPosition(sprite_button2, position2);

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window_game_over, sprite, NULL);
    sfSprite_setTexture(sprite_button, texture_button, sfTrue);
    sfRenderWindow_drawSprite(window_game_over, sprite_button, NULL);
    sfSprite_setTexture(sprite_button2, texture_button2, sfTrue);
    sfRenderWindow_drawSprite(window_game_over, sprite_button2, NULL);
    text_play_again(window_game_over);
    text_game_over(window_game_over);
    analyse_event_game_over(window_game_over);
}

void create_game_over(sfRenderWindow *window_game_over)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_game_over = sfRenderWindow_create(
        mode, "Game Over My Hunter", sfDefaultStyle, NULL);
    sfEvent event;

    while (sfRenderWindow_isOpen(window_game_over)){
        images_game_over(window_game_over);
        sfRenderWindow_display(window_game_over);
        sfRenderWindow_clear(window_game_over, sfBlack);
    }sfRenderWindow_destroy(window_game_over);
}

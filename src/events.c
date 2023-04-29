/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** Functions for the events
*/

#include "./../include/myhunter.h"

void manage_mouse_move(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile(AIM_PNG, NULL);
    sfSprite *sprite = sfSprite_create();
    sfIntRect rect = {0, 0, 90, 90};

    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfMouseMoveEvent mouse = {sfEvtMouseMoved, pos.x, pos.y};
    sfVector2f position = {mouse.x - 45, mouse.y - 45};
    sfSprite_setPosition(sprite, position);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void manage_mouse_click(sfMouseButtonEvent mouse_event, sfSprite *sprite,
                        sfVector2f position, sfVector2f origin)
{
    if (mouse_event.x <= position.x + 110 && mouse_event.x >= position.x
        && mouse_event.y <= position.y + 110 && mouse_event.y >= position.y){
        sfSprite_setPosition(sprite, origin);
    }
}

void click_sound(void)
{
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile("./assets/shot.wav");
    sfSound *sound = sfSound_create();
    
    sfSound_setBuffer(sound, buff);
    sfSound_play(sound);
}

void analyse_events(sfRenderWindow *window, sfSprite *sprite,
                    sfVector2f position)
{
    sfEvent event;
    sfVector2f origin = {-250, rand() % 500};

    manage_mouse_move(window);
    while (sfRenderWindow_pollEvent(window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);

        if (event.type == sfEvtMouseButtonPressed){
            click_sound();
            manage_mouse_click(event.mouseButton, sprite, position, origin);
        }
    }
}

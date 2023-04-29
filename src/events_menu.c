/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** Functions to manage events in the menu window
*/

#include "./../include/myhunter.h"

void create_window(sfRenderWindow *window);

void manage_mouse_menu(sfMouseButtonEvent mouse_event,
                        sfRenderWindow *window_menu)
{
    sfRenderWindow *window;
    sfVector2f position = {760, 500};
    if (mouse_event.x <= position.x + 400 && mouse_event.x >= position.x
        && mouse_event.y <= position.y + 150 && mouse_event.y >= position.y){
        sfRenderWindow_close(window_menu);
        create_window(window);
    }
}

void analyse_event_menu(sfRenderWindow *window_menu)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window_menu, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window_menu);
        if (event.type == sfEvtMouseButtonPressed){
            manage_mouse_menu(event.mouseButton, window_menu);
        }
    }
}

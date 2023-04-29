/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** functions to create the menu
*/

#include "./../include/myhunter.h"

void text_menu(sfRenderWindow *window_menu)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(MENU_FONT);
    sfVector2f position = {875, 520};

    sfText_setFillColor(text, sfWhite);
    sfText_setCharacterSize(text, 80);
    sfText_setFont(text, font);
    sfText_setString(text, "PLAY");
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window_menu, text, NULL);
}

void images_menu(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile(IMAGE_BG, NULL);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture_button = sfTexture_createFromFile(MENU_BUTTON, NULL);
    sfSprite *sprite_button = sfSprite_create();
    sfVector2f position = {760, 500};
    sfSprite_setPosition(sprite_button, position);

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_setTexture(sprite_button, texture_button, sfTrue);
    sfRenderWindow_drawSprite(window, sprite_button, NULL);
}

void create_menu(sfRenderWindow *window_menu)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_menu = sfRenderWindow_create(
        mode, "Menu My Hunter", sfDefaultStyle, NULL);
    sfEvent event;

    while (sfRenderWindow_isOpen(window_menu)){
        images_menu(window_menu);
        text_menu(window_menu);
        analyse_event_menu(window_menu);
        sfRenderWindow_display(window_menu);
        sfRenderWindow_clear(window_menu, sfBlack);
    }sfRenderWindow_destroy(window_menu);
}

int main(int ac, char **av)
{
    sfRenderWindow *window_menu;

    if (!window_menu){
        return(84);
    }
    if (ac == 1){
        create_menu(window_menu);
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0){
        printf("info\n");
    }

    return (0);
}

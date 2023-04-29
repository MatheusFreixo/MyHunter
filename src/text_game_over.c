/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** Functions to put text in the game over window
*/

#include "./../include/myhunter.h"

void text_game_over(sfRenderWindow *window_game_over)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(GAMEOVER_FONT);
    sfVector2f position = {750, 200};

    sfText_setFillColor(text, sfRed);
    sfText_setCharacterSize(text, 100);
    sfText_setFont(text, font);
    sfText_setString(text, "GAME OVER");
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window_game_over, text, NULL);
}

void text_play_again(sfRenderWindow *window_game_over)
{
    sfText *play_again_text = sfText_create();
    sfFont *play_again_font = sfFont_createFromFile(MENU_FONT);
    sfVector2f play_again_position = {525, 535};
    sfText *quit_text = sfText_create();
    sfFont *quit_font = sfFont_createFromFile(MENU_FONT);
    sfVector2f quit_position = {1220, 530};

    sfText_setFillColor(play_again_text, sfWhite);
    sfText_setCharacterSize(play_again_text, 65);
    sfText_setFont(play_again_text, play_again_font);
    sfText_setString(play_again_text, "PLAY AGAIN");
    sfText_setPosition(play_again_text, play_again_position);
    sfRenderWindow_drawText(window_game_over, play_again_text, NULL);
    sfText_setFillColor(quit_text, sfWhite);
    sfText_setCharacterSize(quit_text, 70);
    sfText_setFont(quit_text, quit_font);
    sfText_setString(quit_text, "QUIT");
    sfText_setPosition(quit_text, quit_position);
    sfRenderWindow_drawText(window_game_over, quit_text, NULL);
}

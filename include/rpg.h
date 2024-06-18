/*
** EPITECH PROJECT, 2023
** paint
** File description:
** Header
*/

#pragma once
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdbool.h>
#include <string.h>
#include "csfml.h"
#include "my.h"

#include "rpg/menu.h"
#include "rpg/anim.h"
#include "rpg/player.h"
#include "rpg/maps.h"
#include "rpg/inventory.h"
#include "rpg/quests.h"
#include "rpg/parse.h"
#include "rpg/fight.h"
#include "rpg/chest.h"
#include "rpg/save.h"

typedef struct pig_s {
    bool is_active;
    bool complete;
    bool left;
    int found[3];
    sfClock *clock;
    sfRectangleShape *pig_s[3];
    sfRectangleShape *rpig_s[3];
} pig_t;

typedef struct mapboss_s {
    sfClock *clock;
    bool frog;
    bool pyro;
    bool cryo;
    bool cyclop;
    bool rajah;
    bool monkey;
    bool dog;
    sfSprite *s_frog;
    sfSprite *s_pyro;
    sfSprite *s_cryo;
    sfSprite *s_cyclop;
    sfSprite *s_rajah;
} mapboss_t;

typedef struct key_board_s {
    sfKeyCode up;
    sfKeyCode down;
    sfKeyCode left;
    sfKeyCode right;
    bool left_bool;
    bool right_bool;
    button_t *left_btn;
    button_t *right_btn;
    button_t *left_param;
    button_t *right_param;
} key_board_t;


typedef struct store_s {
    bool is_active;
    int nb;
    sfRectangleShape *bck;
    sfSprite *logo;
    sfTexture *t_coin;
    sfSprite *coin;
    sfText *val_coin;
    sfSprite *asset[6];
    sfText *product[6];
    button_t *items[6];
    button_t *buy;
    sfText *effect[6];
    sfRectangleShape *description;
    sfClock *clock;
} store_t;

typedef struct skilltree_s {
    bool is_active;
    bool unlock;
    int atk_progress;
    int hp_progress;
    sfRectangleShape *bck;
    sfRectangleShape *atk_btn[5];
    sfRectangleShape *hp_btn[5];
    sfText *atk_effect[5];
    sfText *hp_effect[5];
    sfText *val_gpa;
    sfText *gpa;
    sfText *val_atk;
    sfText *val_hp;
    sfText *atk;
    sfText *hp;
    button_t *btn[2];
} skilltree_t;

typedef struct game_s {
    bool is_active;
    int esc;
    int vol_music;
    int vol_sound;
    sfMusic *music;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock_mv;
    sfClock *clock_menu;
    sfView *view;
    sfVideoMode mode;
} game_t;

typedef struct chatbox_s {
    bool is_active;
    sfVector2f position;
    sfTexture *texture;
    sfSprite *sprite;
} chatbox_t;

typedef struct info_bar_s {
    bool is_active;
    sfSprite *sprite;
    sfSprite *exp[2];
    sfSprite *face;
    sfSprite *box;
    sfText *name;
    sfText *quest;
    sfText *lvl;
} info_bar_t;

typedef struct splash_s {
    sfSprite *sprite;
    bool splash_active;
    sfClock *splash_clock;
    sfClock *delay_clock;
    sfClock *clock;
    float scale;
} splash_t;


typedef struct assets_s {
    char *music_menu;
    char *music_village;
    char *music_beach;
    char *music_lighthouse;
    char *music_shop;
    char *music_swamp;
    char *music_museum;
    char *music_cave;
    char *music_donjon;
    char *music_maze;
    char *music_fight;
    char *music_boss;
    char *music_rajah;
    char *music_final;
    sfFont *font;
    sfTexture *swamp;
    sfTexture *dungeon;
    sfTexture *grocery;
    sfTexture *box1;
    sfTexture *box2;
    sfTexture *box3;
    sfTexture *box1h;
    sfTexture *box2h;
    sfTexture *bar0;
    sfTexture *bar20;
    sfTexture *bar40;
    sfTexture *bar60;
    sfTexture *bar80;
    sfTexture *bar100;
    sfTexture *barback;
    sfTexture *expbar;
    sfTexture *animals;
    sfTexture *btn1;
    sfTexture *btn2;
    sfTexture *btn3;
    sfTexture *btn4;
    sfTexture *slime;
    sfTexture *mole;
    sfTexture *larva;
    sfTexture *shroom;
    sfTexture *bamboo;
    sfTexture *burner;
    sfTexture *freezer;
    sfTexture *skull;
    sfTexture *eye;
    sfTexture *blob;
    sfTexture *frog;
    sfTexture *bfire;
    sfTexture *bice;
    sfTexture *cyclop;
    sfTexture *rajah;
    sfTexture *frog_hit;
    sfTexture *bfire_hit;
    sfTexture *bice_hit;
    sfTexture *cyclop_hit;
    sfTexture *rajah_hit;
    sfTexture *frog_attack;
    sfTexture *fire_spell;
    sfTexture *ice_spell;
    sfTexture *stone_spell;
    sfTexture *arrow0;
    sfTexture *arrow1;
    sfTexture *arrow2;
    sfTexture *arrow3;
    sfTexture *info_bar;
    sfTexture *wrong;
    sfTexture *settings_bg;
    sfTexture *splash;
} assets_t;

typedef struct rpg_s {
    game_t *game;
    assets_t *assets;
    characters_t *characters;
    chatbox_t *chatbox;
    menu_t *menu;
    maps_t *maps;
    begin_t *begin;
    inventory_t *inv;
    fight_t *fight;
    animations_t *anim;
    quests_t *quests;
    char *name;
    char *font;
    skilltree_t *skilltree;
    store_t *store;
    dialogue_t *dialogue;
    info_bar_t *info_bar;
    key_board_t *key_board;
    chest_t *chest;
    mapboss_t *boss;
    splash_t *splash;
    pig_t *pig;
} rpg_t;

void my_rpg(void);
void rpg_is_open(rpg_t *rpg);
void find_pnj_upt(rpg_t *rpg);
int event_handler(rpg_t *rpg);
void find_cow(rpg_t *rpg, main_player_t *player);
sfText *my_set_text(rpg_t *rpg, char *str, int size, sfVector2f pos);
void int_anim(rpg_t *rpg);
game_t *fill_game_params(rpg_t *rpg);
chatbox_t *fill_chatboxes(rpg_t *rpg);
void which_map(rpg_t *rpg, main_player_t *main);
void map_chatbox(rpg_t *rpg);
void wait_relapse(void);
float time_elapsed(sfClock *clock);
maps_t *fill_maps(rpg_t *rpg);
void update_name(rpg_t *rpg, sfClock **clock, char c);
void my_alpha(rpg_t *rpg, sfClock **clock, float f);
void update_pos_quests(quests_t *quests, sfVector2f pos);
void my_alpha_maj(rpg_t *rpg, sfClock **clock, float f);
void my_put_alphabet(rpg_t *rpg, sfClock **clock, float f);
void chara_chosen(rpg_t *rpg);
void init_keys(rpg_t *rpg);
void fill_anim_layer(rpg_t *rpg);
assets_t *fill_assets_struct(rpg_t *rpg);
inventory_t *create_inventory(rpg_t *rpg);
info_bar_t *fill_infobar(rpg_t *rpg);
void draw_infobar(rpg_t *rpg);
conso_t *fill_conso_item(assets_t *assets, rpg_t *rpg);
void test_assets(rpg_t *rpg);
int find_and_chdir_to_repo(const char *repo_name, char *path, size_t path_len);
sett_t *fill_settings_menu(assets_t *assets);
skilltree_t *fill_skilltree(assets_t *assets);
void draw_settings_inv(rpg_t *rpg);
sfVector2f get_pos(sfVideoMode res, sfVector2f pos, sfVector2u old_size);
int is_animal(main_player_t *main);
mapboss_t *fill_mapboss(rpg_t *rpg);

//splash screen
splash_t *init_splash_screen(rpg_t *rpg);
void preload_splash_screen(rpg_t *rpg, sfClock *clock);

//menu
void key_arrows(rpg_t *rpg);
void key_zqsd(rpg_t *rpg);
void draw_key_game(rpg_t *rpg);
void update_pos(inv_btn_t *btn, sfVector2f pos, sfVector2f pos2);
void hover_clicked(rpg_t *rpg, inv_btn_t *btn);
inv_btn_t *create_btn(char *str, bool bin, assets_t *assets);
button_t *create_button_arrow_game(sfVector2f pos, assets_t *assets,
    sfVector2f pos_text, char *name);
void modify_key_pos(rpg_t *rpg, sfVector2f left, sfVector2f right);
button_t *create_button_arrow(sfVector2f pos, assets_t *assets,
    sfVector2f pos_text, char *name);
void draw_title_screen(rpg_t *rpg);
void draw_start_menu(rpg_t *rpg);
void draw_settings(rpg_t *rpg);
void hover_choose_chara(rpg_t *rpg);
void select_anim(rpg_t *rpg, int i);
void validate_hover(rpg_t *rpg, begin_t *btn);

void adjust_all(rpg_t *rpg, sfVideoMode res, sfVector2u old_size);
void set_new_pos_sprite(sfSprite *sprite, sfVideoMode res, sfVector2u oldsize);
void open_chest_maze(rpg_t *rpg, main_player_t *player);
void set_new_pos_btn(button_t *btn, sfVideoMode res, sfVector2u old_size);
void set_new_pos_rect(sfRectangleShape *rect, sfVideoMode res,
    sfVector2u old_size);
void set_new_pos_text(sfText *text, sfVideoMode res, sfVector2u old_size);
menu_t *fill_menu(rpg_t *rpg, assets_t *assets);
begin_t *fill_beginning_menu(assets_t *assets);
void male_hover(rpg_t *rpg, begin_t *btn);
void female_hover(rpg_t *rpg, begin_t *btn);
void hover_textbox(rpg_t *rpg, float f);
void textbox_hover(rpg_t *rpg, begin_t *btn);
sfRenderWindow *change_res(rpg_t *rpg, sfVideoMode res, int fm_limit);
void draw_resolutions_params(rpg_t *rpg);
void draw_skilltree(rpg_t *rpg, skilltree_t *tree);
void apply_atk_effect(rpg_t *rpg, skilltree_t *tree, int i);
void apply_hp_effect(rpg_t *rpg, skilltree_t *tree, int i);
store_t *fill_store(rpg_t *rpg);
void draw_store(rpg_t *rpg, store_t *store);
void modif_music(rpg_t *rpg, char *path);
void draw_item_menu(rpg_t *rpg, items_fight_t *menu);
info_bar_t *create_info_bar(rpg_t *rpg, sfVector2f pos, assets_t *assets);
void set_new_pos_sprite(sfSprite *sprite, sfVideoMode res, sfVector2u oldsize);
void set_new_pos_text(sfText *text, sfVideoMode res, sfVector2u old_size);
void set_new_pos_rect(sfRectangleShape *rect, sfVideoMode res,
    sfVector2u old_size);
void set_new_pos_btn(button_t *btn, sfVideoMode res, sfVector2u old_size);
void setup_maze_chest(rpg_t *rpg);
void update_bag(rpg_t *rpg, conso_t *item);

//move player
void move_player(sfClock *clock, main_player_t *player, rpg_t *rpg);

//functions for pf arrows
int move_key_up(sfClock *clock, main_player_t *player, rpg_t *rpg);
int move_key_down(sfClock *clock, main_player_t *player, rpg_t *rpg);
int move_key_left(sfClock *clock, main_player_t *player, rpg_t *rpg);
int move_key_right(sfClock *clock, main_player_t *player, rpg_t *rpg);
int move_right_up(sfClock *clock, main_player_t *player, rpg_t *rpg);
int move_left_up(sfClock *clock, main_player_t *player, rpg_t *rpg);
int move_right_down(sfClock *clock, main_player_t *player, rpg_t *rpg);
int move_left_down(sfClock *clock, main_player_t *player, rpg_t *rpg);
int select_an(sfClock *clock);
int select_ani(sfClock *clock);
void find_market(rpg_t *rpg);


//modify view to render the maps
void map_chatbox(rpg_t *rpg);
void modif_center(sfVector2f *center, sfVector2f view_center,
    sfFloatRect area);
void map_view(rpg_t *rpg, sfFloatRect area);

//choose under maps and pose player
void choose_under_map(rpg_t *rpg, main_player_t *main);
int wich_room(rpg_t *rpg, main_player_t *player, sfVector2f position);

//teleportation
void rest_upstairs(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x);
void rest_beach(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x);
void else_swamp(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x);
void else_beach(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x);
void else_upt(rpg_t *rpg, main_player_t *player,
    sfVector2f position, int x);
void zoom_out_trans(rpg_t *rpg, room_t *room);
int find_where_swamp(rpg_t *rpg, main_player_t *player, sfVector2f position);
int find_where_beach(rpg_t *rpg, main_player_t *player, sfVector2f positionn);
int find_where_upstairs(rpg_t *rpg, main_player_t *player,
    sfVector2f position);
int find_where_downstairs(rpg_t *rpg, main_player_t *player,
    sfVector2f position);
int is_white(sfColor color_pixel);
int wich_room2(rpg_t *rpg, main_player_t *player, sfVector2f position);
int find_where_house(rpg_t *rpg, main_player_t *player, sfVector2f position);
int find_where_bathroom(rpg_t *rpg, main_player_t *player,
    sfVector2f position);
int find_where_weapon(rpg_t *rpg, main_player_t *player, sfVector2f position);
int find_where_noodle(rpg_t *rpg, main_player_t *player, sfVector2f position);
int find_where_maze(rpg_t *rpg, main_player_t *player, sfVector2f position);
int find_where_village(rpg_t *rpg, main_player_t *player, sfVector2f position);
void draw_inv_menu(rpg_t *rpg);
void draw_armor(rpg_t *rpg);
void drag_n_drop(rpg_t *rpg, sfVector2f pos);
void draw_items_inv(rpg_t *rpg);
void render_trans(rpg_t *rpg, room_t *room, int windowWidth,
    sfVector2f position);
int find_where_upstairs(rpg_t *rpg, main_player_t *player,
    sfVector2f position);
int find_where_beach(rpg_t *rpg, main_player_t *player, sfVector2f position);
int find_where_museum(rpg_t *rpg, main_player_t *player,
    sfVector2f position);
int find_where_grotte(rpg_t *rpg, main_player_t *player, sfVector2f position);
int find_where_dungeon(rpg_t *rpg, main_player_t *player, sfVector2f position);
int wich_room3(rpg_t *rpg, main_player_t *player, sfVector2f position);
int wich_room2(rpg_t *rpg, main_player_t *player, sfVector2f position);

//animations
void init_sprite(rpg_t *rpg, animations_t *anim);
void init_anim(rpg_t *rpg, animations_t *anim);
void init_rain(anim_t *anim, rpg_t *rpg);
void anim_rain(anim_t *anim, rpg_t *rpg);
void update_rain(anim_t *anim, rpg_t *rpg);
void updtate_pudlle(anim_t *anim, rpg_t *rpg);
void anim_coin(conso_t *conso);

//quests
void draw_quests(rpg_t *rpg, sfVector2f pos);
int button_hover(rpg_t *rpg, button_t *btn);
int button_view_hover(rpg_t *rpg, button_t *btn);
button_t *create_button(sfVector2f pos, assets_t *assets,
    sfVector2f pos_text, char *name);
button_t *create_button2(sfVector2f pos, assets_t *assets);
button_t *create_button3(assets_t *assets);
quests_t *fill_quests(rpg_t *rpg);

//destroy assets
void destroy_assets(rpg_t *rpg);

//int pnjs
void find_weapon(rpg_t *rpg);
void find_if_print(rpg_t *rpg, dialog_player_t *dialogue);
void find_key_interactions(rpg_t *rpg,
    main_player_t *player, dialog_player_t *dialogue);
void draw_text_in_chatbox(rpg_t *rpg,
    dialog_player_t *dialogue);
char **read_text_file(const char *filename, int *line_count);
void find_museum_red(rpg_t *rpg, main_player_t *player, room_t *room);
void find_qna(rpg_t *rpg, main_player_t *player);
void find_pnjs(rpg_t *rpg);
void find_beach(rpg_t *rpg, main_player_t *player);
void find_museum_blue(rpg_t *rpg, main_player_t *player, room_t *room);
void find_if_pnjs(rpg_t *rpg, main_player_t *player, room_t *room);
void load_assets(rpg_t *rpg, room_t *room);
void render_pnjs(rpg_t *rpg);
void create_all_pnj(rpg_t *rpg);
void render_chatbox(rpg_t *rpg, main_player_t *player, room_t *room);

// void activate_chatbox(rpg_t *rpg);
void find_swamp(rpg_t *rpg, main_player_t *player);
void find_bp_kid(rpg_t *rpg, main_player_t *player);
void find_old_bp(rpg_t *rpg, main_player_t *player);
void find_key_interactions_beach(rpg_t *rpg,
    main_player_t *player, dialog_player_t *dialogue);
void find_kid_beach(rpg_t *rpg, main_player_t *player);
void find_old_beach(rpg_t *rpg, main_player_t *player);
void find_if_pnjs(rpg_t *rpg, main_player_t *player, room_t *room);

// items
void atk_plus(main_player_t *main);
void hp_plus(main_player_t *main);
void potion(main_player_t *main);
void potion_plus(main_player_t *main);
void potion_max(main_player_t *main);
void water(main_player_t *main);
void milk(main_player_t *main);
void shrimp(main_player_t *main);
void sushi(main_player_t *main);
void octopus(main_player_t *main);
void fortune(main_player_t *main);
void medikit(main_player_t *main);
void medikit2(rpg_t *rpg);

//fight
fight_t *create_fight(rpg_t *rpg);
void draw_fight(rpg_t *rpg);
bool fight_trigger(rpg_t *rpg);
void manage_fight(rpg_t *rpg);
void e_attack(rpg_t *rpg);
void draw_lifebar(rpg_t *rpg, sfVector2f pos);
void main_button_effect(rpg_t *rpg);
enemy_t **create_enemies(assets_t *assets);
scroll_t *fill_scroll_menu(rpg_t *rpg);
void draw_scrolls(rpg_t *rpg, scroll_t *scroll);
void draw_boss(rpg_t *rpg, enemy_t *enemy, sfVector2f center);
void draw_frog(rpg_t *rpg);
void draw_pyro(rpg_t *rpg);
void draw_cryo(rpg_t *rpg);
void draw_cyclop(rpg_t *rpg);
void draw_rajah(rpg_t *rpg);
void draw_dog(rpg_t *rpg);
void draw_monkey(rpg_t *rpg);
void get_reward(rpg_t *rpg);
void update_level(main_player_t *main);
rpg_t *find_map(rpg_t *rpg);


//music
void init_music(rpg_t *rpg);

// save
char **read_file(char *filename);
void write_file(char *filename, char **array);
rpg_t *get_gender(char *str, rpg_t *save);
rpg_t *get_name(char *str, rpg_t *save);
rpg_t *get_position(char *str, rpg_t *save);
rpg_t *get_map(char *str, rpg_t *save);
rpg_t *get_inventory(char *str, rpg_t *save);
rpg_t *get_skilltree(char *str, rpg_t *save);
rpg_t *get_quests(char *str, rpg_t *save);
rpg_t *get_pos_view(char *str, rpg_t *save);
rpg_t *get_hp(char *str, rpg_t *save);
rpg_t *get_level(char *str, rpg_t *save);
rpg_t *get_experience(char *str, rpg_t *save);
rpg_t *get_attack(char *str, rpg_t *save);
rpg_t *get_money(char *str, rpg_t *save);
rpg_t *get_gpa(char *str, rpg_t *save);
rpg_t *get_access(char *str, rpg_t *save);
rpg_t *fill_field(char *str, rpg_t *save);
void check_fields(main_player_t *player);
rpg_t *parse_save(rpg_t *save, char **arr);
char **prepare_save(rpg_t *to_save);
rpg_t *get_boss(char *str, rpg_t *save);
void music_fight(rpg_t *rpg);
char *put_access(maps_t *maps);

void wait_clock(rpg_t *rpg, bool trigger);
//chests
int check_bag_size(rpg_t *rpg, int size);
void find_chest_two(rpg_t *rpg, main_player_t *player);
void find_kei_released(rpg_t *rpg, main_player_t *player, chest_open_t *chest);
void find_if_pritable(rpg_t *rpg, chest_open_t *chest);
void open_chest(rpg_t *rpg, main_player_t *player, chest_open_t *chest);
void find_kei_releaseds(rpg_t *rpg, main_player_t *player,
    chest_open_t *chest);
void find_chest_in_maze(rpg_t *rpg, main_player_t *player);
void check_chest_dungeon(rpg_t *rpg, main_player_t *player);
void find_if_level_upt(rpg_t *rpg);

void setup_piggies(rpg_t *rpg);
void draw_pig1(rpg_t *rpg);
void draw_pig2(rpg_t *rpg);
void draw_pig3(rpg_t *rpg);
void clock_management(rpg_t *rpg);
void draw_reward(rpg_t *rpg, dialog_player_t *dialogue);
void render_reward_kid(rpg_t *rpg);
void render_reward_pigs(rpg_t *rpg);

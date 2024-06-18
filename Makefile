##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to compil the -lmy
##

CC	=	gcc

NAME	=	my_rpg

LIB1	=	libmy.a

LIB2	=	libcsfml.a

UNIT_TESTS	=	unit_tests

CSFML	=	-lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window

LIB = -L. -lcsfml -lmy -lm

CFLAGS	=	-I ./include -Werror -Wall -Wshadow $(CSFML) $(LIB)

CRITERION	=	--coverage -lcriterion

SRC		=	main.c								\
			src/find_assets.c 			    	\
			src/event_handler.c 			    \
			src/hover_buttons.c 				\
			src/wait_relapce.c 					\
			src/my_rpg.c 						\
			src/map_view.c 						\
			src/alphabet.c 						\
			src/my_alpha.c 						\
			src/my_alpha_maj.c					\
			src/modify_view.c 					\
			src/music_handler.c 				\
			src/key_handler.c 					\
			src/clock_management.c 				\
			src/setup/setup_assets.c 			\
			src/setup/setup_game_params.c 		\
			src/setup/setup_player.c  			\
			src/setup/setup_chatbox.c 			\
			src/setup/setup_menu.c 				\
			src/setup/setup_maps.c 				\
			src/setup/setup_beginning.c 		\
			src/setup/setup_inventory.c 		\
			src/setup/setup_buttons.c 			\
			src/setup/setup_consos.c 			\
			src/setup/setup_settings_inv.c		\
			src/setup/setup_boss.c 				\
			src/setup/items/setup_item1.c       \
			src/setup/items/setup_item2.c       \
			src/setup/items/setup_item3.c       \
			src/setup/setup_skilltree.c 		\
			src/setup/setup_store.c 			\
			src/setup/setup_fight.c				\
			src/setup/setup_infobar.c			\
			src/setup/setup_monsters.c 			\
			src/setup/setup_scrolls.c 			\
			src/setup/setup_chest.c 			\
			src/setup/setup_splash.c			\
			src/player/moves.c					\
			src/player/pnj.c 					\
			src/player/arrow_pf.c				\
			src/player/arrow2_pf.c				\
			src/player/under_map.c				\
			src/player/move_up.c				\
			src/player/move_down.c				\
			src/player/left_down.c				\
			src/player/rigth_up.c				\
			src/save/edit_file.c				\
			src/save/get_basics.c				\
			src/save/get_qi.c					\
			src/save/get_stats.c				\
			src/save/parse_save.c				\
			src/save/save_game.c				\
			src/save/save_game2.c				\
			src/save/get_boss.c					\
			src/menu/draw_title_screen.c		\
			src/menu/draw_start_menu.c			\
			src/menu/draw_settings.c			\
			src/menu/draw_beginning.c			\
			src/menu/draw_begin_hovers.c		\
			src/menu/adjust.c					\
			src/menu/set_new_pos.c				\
			src/menu/my_set_text.c 				\
			src/menu/draw_keys.c 				\
			src/teleportation/find_where.c		\
			src/teleportation/downstair_tel.c	\
			src/teleportation/upt_tel.c			\
			src/teleportation/rest_tel.c		\
			src/teleportation/transition.c		\
			src/teleportation/find_which.c 		\
			src/teleportation/swamp_tel.c		\
			src/teleportation/maze_tel.c		\
			src/teleportation/zoom_out.c 		\
			src/animations/swamp_anims.c		\
			src/animations/bp_anim.c			\
			src/animations/init_anim.c    		\
			src/inventory/draw_background.c		\
			src/inventory/draw_armor.c			\
			src/inventory/drag_drop.c			\
			src/inventory/draw_items.c			\
			src/inventory/coin_animation.c		\
			src/inventory/draw_setting.c		\
			src/inventory/draw_params.c    	    \
			src/inventory/draw_infobar.c		\
			src/parse/parser.c					\
			src/quests/init_quests.c			\
			src/quests/draw_quests.c			\
			src/pnj/init_pnj.c 					\
			src/pnj/render_chat_box.c			\
			src/pnj/create_pnj.c 				\
			src/pnj/find_if_pnjs.c 				\
			src/pnj/render_pnjs.c 				\
			src/pnj/find_weapon.c 				\
			src/pnj/create_chatboxes.c 			\
			src/pnj/beach_pnj.c  			 	\
			src/pnj/choose_wich_pnj.c 			\
			src/pnj/render_cats.c 				\
			src/pnj/chest/find_chest.c 			\
			src/pnj/chest/chest_maze_two.c		\
			src/pnj/chest/chest_three.c 		\
			src/pnj/chest/global_chest_func.c 	\
			src/pnj/chest/chest_dubngeon.c  	\
			src/pnj/chest/reward_pigs.c 		\
			src/destroy_assets/destroy_player.c	\
			src/teleportation/museum_tel.c		\
			src/skilltree/draw_skilltree.c		\
			src/skilltree/tree_effect.c			\
			src/store/draw_store.c        		\
			src/fight/fight_trigger.c			\
			src/fight/draw_fight.c				\
			src/fight/manage_fight.c			\
			src/fight/draw_menus.c				\
			src/fight/draw_scrolls.c			\
			src/fight/draw_boss_anim.c			\
			src/fight/draw_boss.c				\
			src/fight/update_level.c			\
			src/monster/draw_animals.c			\
			src/monster/setup_piggies.c			\
			src/monster/draw_piggies.c

SRCTEST	=	$(filter-out main.c, $(SRC))

OBJ		=	$(SRC:.c=.o)

FILETEST=	tests/test_save.c

all:	$(LIB1) $(LIB2) $(NAME)

$(LIB1):
	@$(MAKE) -C ./lib/my
	@cp -f ./lib/my/my.h ./include

$(LIB2):
	@$(MAKE) -C ./lib/csfml
	@cp -f ./lib/csfml/csfml.h ./include

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\e[1;36m{ Binary ready !! }\e[00;37m"

$(UNIT_TESTS):
	@$(MAKE) fclean > /dev/null 2>&1
	@$(MAKE) -C ./lib/csfml > /dev/null 2>&1
	@$(MAKE) -C ./lib/my > /dev/null 2>&1
	@cp -f ./lib/csfml/csfml.h ./include
	@cp -f ./lib/my/my.h ./include
	@$(CC) -o $(UNIT_TESTS) $(SRCTEST) $(CFLAGS) $(CRITERION) $(FILETEST)

tests_run: $(UNIT_TESTS)
	@./$(UNIT_TESTS)
	@gcovr --exclude tests/

clean:
	@$(RM) *~
	@$(RM) *.gc*
	@$(RM) $(OBJ)
	@$(MAKE) clean -C ./lib/csfml
	@$(MAKE) clean -C ./lib/my
	@echo -e "\e[1;33m[ Useless files have been deleted ]\e[00;37m"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(UNIT_TESTS)
	@$(MAKE) fclean -C ./lib/csfml
	@$(MAKE) fclean -C ./lib/my
	@echo -e "\e[1;33m[ Binary has been deleted ]\e[00;37m"

norm:
	@$(MAKE) fclean > /dev/null 2>&1
	@coding-style . .
	@cat coding-style-reports.log
	@$(RM) coding-style-reports.log

re: fclean all

.PHONY: all clean fclean re norm tests_run

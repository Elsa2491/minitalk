SERVER = server
CLIENT = client
#BONUS_NAME = fractol_bonus
PRINTF = ./printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS_PATH = srcs/
OBJS_PATH = objs/
#BONUS_SRCS_PATH = bonus/srcs/
#BONUS_OBJS_PATH = bonus/objs/
GREEN 	:= \e[32m
BLUE 	:= \e[34m
RESET 	:= \e[0m
MAKEFLAGS    +=    --no-print-directory

SRCS = string_functions.c /
SRCS_SERVER = server.c /
SRCS_CLIENT = client.c /

#BONUS_SRCS = 

OBJ = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
OBJ_SERVER = $(addprefix $(OBJS_PATH), $(SRCS_SERVER:.c=.o))
OBJ_CLIENT = $(addprefix $(OBJS_PATH), $(SRCS_CLIENT:.c=.o))
#BONUS_OBJ = $(addprefix $(BONUS_OBJS_PATH), $(BONUS_SRCS:.c=.o))

all: $(SERVER) $(CLIENT)

#$(OBJS_PATH):
#	@mkdir -p $(OBJS_PATH)

#$(BONUS_OBJS_PATH):
#	@mkdir -p $(BONUS_OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@

#$(BONUS_OBJS_PATH)%.o: $(BONUS_SRCS_PATH)%.c
#	cc $(CFLAGS) -c $< -o $@

$(SERVER): $(OBJ_PATH) $(OBJ_SERVER) $(OBJ)
	@echo "\nCompilation mandatory part server: $(GREEN)success$(RESET)\n"
	make --no-print-directory -C "./printf"
	cc $(CFLAGS) $(OBJ_SERVER) $(OBJ) -Inc $(PRINTF) -o $(SERVER)
	@echo "\nCompilation $(BLUE)server $(GREEN)finished$(RESET)!\n"

$(CLIENT): $(OBJ_CLIENT)
	@echo "\nCompilation mandatory part client: $(GREEN)success$(RESET)\n"
	make --no-print-directory -C "./printf"
	cc $(CFLAGS) $(OBJ_CLIENT) -Inc $(PRINTF) -o $(CLIENT)
	@echo "\nCompilation $(BLUE)client $(GREEN)finished$(RESET)!\n"


#$(BONUS_NAME): $(BONUS_OBJS_PATH) $(BONUS_OBJ)
#	@echo "\nCompilation bonus part: $(GREEN)success$(RESET)\n"
#	cc $(CFLAGS) $(BONUS_OBJ) -Inc $(PRINTF) -Inc $(MLX) -Lminilibx-linux -lX11 -lXext -o $(BONUS_NAME)
#	@echo "\nCompilation minilibx: $(GREEN)success$(RESET)\n"
#	@echo "\nCompilation $(GREEN)finished$(RESET)!\n"

#bonus:
#	@make $(BONUS_NAME)

clean:
	/bin/rm -rf $(OBJS_PATH)
	@echo "\nMandatory files objects and associated directories removed\n"
	#/bin/rm -rf $(BONUS_OBJ)
#	/bin/rm -rf $(BONUS_OBJS_PATH)
	@echo "\nBonus files objects and associated directories removed\n"

fclean: clean
	/bin/rm -rf $(SERVER) $(CLIENT) $(PRINTF) #$(BONUS_NAME)
	@echo "\nServer and client destroyed\n"

re: fclean all

.PHONY: all clean fclean re bonus

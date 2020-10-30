# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kde-wint <kde-wint@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/09/18 13:55:17 by kde-wint      #+#    #+#                  #
#    Updated: 2020/10/30 13:03:18 by kde-wint      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME_ASSEMBLER = asm
NAME_COREWAR = corewar
LIBFT = libft/libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
ASSEMBLER_SRCDIR = asm_files
ASSEMBLER_OBJDIR = .obj-assembler
COREWAR_SRCDIR = corewar_files
COREWAR_OBJDIR = .obj-corewar
SHARED_SRCDIR = shared_files
SHARED_OBJDIR = .obj-shared
EXEDIR = ./

RED=\033[0;31m
GREEN=\033[0;32m
CYAN=\033[0;36m
NC=\033[0m

SRC_ASSEMBLER =	\
		asm.c \
		asm_errors.c \
		exit_asm.c \
		exit_asm2.c \
		get_commands.c \
		check_name_command.c \
		check_command_begin.c \
		check_comment_command.c \
		check_command_end.c \
		placeholder.c \
		utils.c \
		asm_op.c \
		write_data1.c \
		write_data2.c	\
		get_operations.c \
		handle_instruction.c \
		free_and_return1.c \
		get_args.c \
		get_arg_size.c \
		find_matching_label.c \
		handle_label.c	\
		validate_arg.c \
		backpatching_args.c \
		handle_instruction_utils.c \
		get_args_checks.c \
		get_args_checks2.c \
		commands_utils.c \
		create_label.c \
		asm_checks.c \
		remove_spaces.c

SRC_COREWAR =	\
		corewar.c \
		cursors.c \
		free_memory.c \
		init_arena.c \
		is_flag.c \
		env.c \
		handle_error.c \
		op.c \
		op_add.c \
		op_aff.c \
		op_and.c \
		op_fork.c \
		op_ld.c \
		op_ldi.c \
		op_lfork.c \
		op_live.c \
		op_lld.c \
		op_lldi.c \
		op_or.c \
		op_st.c \
		op_sti.c \
		op_sub.c \
		op_xor.c \
		op_zjmp.c \
		parse_args.c \
		printing.c \
		player.c \
		player_id.c \
		game_loop.c\
		check.c \
		set_op_arg.c \
		get_op_arg.c \
		exe_op.c \
		decode_op.c \
		write_mem.c \
		reverse_mem.c \
		read_champion1.c \
		read_champion2.c

OBJ_ASSEMBLER = $(SRC_ASSEMBLER:%.c=$(ASSEMBLER_OBJDIR)/%.o)
OBJ_COREWAR = $(SRC_COREWAR:%.c=$(COREWAR_OBJDIR)/%.o)
OBJ_SHARED = $(SRC_SHARED:%.c=$(SHARED_OBJDIR)/%.o)

INCL = libft/libft.a

all: $(EXEDIR)$(NAME_ASSEMBLER) $(EXEDIR)$(NAME_COREWAR)

$(LIBFT):
	@echo "${CYAN} [ * ] ${NC}Calling libft makefile"
	@$(MAKE) -C libft

$(EXEDIR)$(NAME_ASSEMBLER): $(OBJ_ASSEMBLER) $(OBJ_SHARED) $(LIBFT)
	@echo "${GREEN} [ + ] ${NC}Creating assembler object files"
	@echo "${GREEN} [ + ] ${NC}Creating assembler executable"
	@$(CC) $(FLAGS) $(OBJ_ASSEMBLER) $(OBJ_SHARED) -o $(EXEDIR)\
	$(NAME_ASSEMBLER) $(INCL)

$(EXEDIR)$(NAME_COREWAR): $(OBJ_COREWAR) $(OBJ_SHARED) $(LIBFT)
	@echo "${GREEN} [ + ] ${NC}Creating corewar object files"
	@echo "${GREEN} [ + ] ${NC}Creating corewar executable"
	@$(CC) $(FLAGS) $(OBJ_COREWAR) $(OBJ_SHARED) -o $(EXEDIR)\
	$(NAME_COREWAR) $(INCL)

$(SHARED_OBJDIR)/%.o: $(SHARED_SRCDIR)/%.c $(INCL)
	@mkdir -p $(SHARED_OBJDIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(ASSEMBLER_OBJDIR)/%.o: $(ASSEMBLER_SRCDIR)/%.c $(INCL)
	@mkdir -p $(ASSEMBLER_OBJDIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(COREWAR_OBJDIR)/%.o: $(COREWAR_SRCDIR)/%.c $(INCL)
	@mkdir -p $(COREWAR_OBJDIR)
	@$(CC) $(FLAGS) -c -o $@ $<

.PHONY: clean

clean:
	@echo "${RED} [ - ] ${NC}Deleting assembler object files"
	@rm -rf $(ASSEMBLER_OBJDIR)
	@echo "${RED} [ - ] ${NC}Deleting corewar object files"
	@rm -rf $(COREWAR_OBJDIR)
	@echo "${RED} [ - ] ${NC}Deleting shared object files"
	@rm -rf $(SHARED_OBJDIR)
	@$(MAKE) clean -C libft

fclean: clean
	@echo "${RED} [ - ] ${NC}Deleting assembler executable"
	@rm -f $(EXEDIR)$(NAME_ASSEMBLER)
	@echo "${RED} [ - ] ${NC}Deleting corewar executable"
	@rm -f $(EXEDIR)$(NAME_COREWAR)
	@echo "${RED} [ - ] ${NC}Deleting the libft.a file"
	@rm -f $(LIBFT)

re: fclean all

lldb: re
	gcc -g main.c -L. -lft

norm:
	norminette $(SRC) $(INCL) | grep -e "Error" -e "Warning" -B 1

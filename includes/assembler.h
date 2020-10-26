/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assembler.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 11:05:53 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:54:49 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "asm_op.h"

/*
**	Error types
*/

# define SUCCESS 0
# define ERROR -1

# define GEN_ERR 0
# define INV_EXT -1
# define MALL_ERR -2
# define INV_LINE -3
# define NO_INPUT -4
# define NO_CODE -5

# define READ_ERR 1
# define INV_FD	-1
# define INV_READ -2
# define WR_ERR -3

# define CMD_ERR 2
# define DBL_NM -1
# define DBL_COMM -2
# define INV_CMD -3
# define NM_LEN -4
# define COMM_LEN -5
# define NO_NAME -6
# define NO_COMM -7

# define ARG_ERR 3
# define INV_NUM_ARGS -1
# define LBL_REF_INV -2
# define INV_REG -3
# define INV_TYPE_ARGS -4
# define INV_ARG -5

# define SYNT_ERR 4
# define INV_CHAR -1
# define NO_NEWL -2
# define INV_SEP -3

/*
** Struct that represents the operation information
** given in the op_tab array of op.c file
*/

typedef struct		s_op
{
	char			*op_name;
	size_t			args_amount;
	size_t			args_type[3];
	size_t			opcode;
	size_t			cycles_amount;
	char			*op_description;
	size_t			octal_code;
	int				carry;
	size_t			t_dir_size;
}					t_op;
extern t_op			g_op_tab[17];

typedef	struct		s_label
{
	char			*name;
	int				id;
	int				position;
	struct s_label	*next;
	struct s_label	*prev;
	struct s_label	*tail;
}					t_label;

typedef	struct		s_ins
{
	int				index;
	int				opcode;
	size_t			max_arg;
	size_t			ins_id;
	size_t			position;
	size_t			t_dir_size;
	size_t			ins_size;
	size_t			encoding_byte;
	int				args_type[3];
	int				arguments[3];
	struct s_ins	*next;
	struct s_ins	*prev;
	struct s_ins	*tail;
}					t_ins;

typedef struct		s_wcc_wrap
{
	size_t			i;
	size_t			k;
	struct s_ins	*ins;
	size_t			max_arg;
	int				ret;
}					t_wcc_wrap;

typedef	struct		s_ph
{
	size_t			ins_id;
	size_t			arg_id;
	char			*label_name;
	struct s_ph		*next;
	struct s_ph		*prev;
	struct s_ph		*tail;
}					t_ph;

typedef struct		s_data
{
	char			*name_cmd;
	char			*comment_cmd;
	int				opcode;
	size_t			args_amount;
	size_t			total_size;
	struct s_ph		*ins_placeholders;
	int				ins_id;
	int				label_id;
	struct s_ins	*ins_lst;
	struct s_label	*label_lst;
	int				num_lines;
}					t_data;

typedef struct		s_asm
{
	char			*origin_file;
	struct s_data	*data;
	char			*file;
	char			*file_name;
	int				fd;
	int				fd_rw;
	int				nl_last;
}					t_asm;

int					get_name_comment(t_asm *asm_var, t_data *data);
int					synt_err(int err, int line);
int					asm_error(int type, int err, int line);
int					ft_isspace(char c);
int					enc_byte(int *arr);
int					ft_exit_asm(t_asm *asm_var, t_data *data, int ret);
int					check_commands(t_asm *asm_var, t_data *data, char *line);
void				ft_rnputstr(int fd, unsigned char *str, int len);
int					ft_strchri(const char *str, char c);
int					ft_strchr_count(char *str, char c);
int					make_twoscomplement(int value);
int					write_data(t_asm *asm_var, t_data *data);
void				write_null(int fd);
int					main(int argc, char **argv);
int					arg_type_validation(int opcode, \
									int arg_type, size_t arg_index);
int					remove_comment(char **str);
int					remove_spaces(char **str);
int					is_comment_or_empty(char *line);
int					get_operations(t_asm *asm_var, t_data *data);
int					handle_instruction(t_data *data, char *line);
int					find_non_label_char(char *str);
int					get_args_ins(t_data *data, t_ins *ins, char *arguments);
int					get_arg_size(t_ins *ins, int arg_type);
t_label				*find_matching_label(t_data *data, char *arg);
int					insert_placeholder(t_data *data, t_ins *ins, char *label);
int					handle_label(t_data *data, char *line);
int					backpatching_ins_lst(t_ph *ph_lst, t_data *data);
int					end_handle_instruction(const int ret,
										char *arguments,
										char *op,
										t_ins *new);
int					end_get_args_ins(const int ret, char **args);
int					end_get_operations(const int ret, char **line);
int					end_handle_label(const int ret, char *instr, \
									char *label_name, t_label *label);
int					check_champion_name(t_asm *asm_var, \
										t_data *data, char *command);
int					check_champion_comment(t_asm *asm_var, \
										t_data *data, char *command);
int					finish_comment(t_data *data, char **comment, char *buff);
int					finish_name(t_data *data, char **name, char *buff);
void				free_ins(t_ins **ins_lst);
void				free_data(t_data **data);
int					clean_line(char **line);
int					create_instr(t_ins **new, t_data *data, char *op);
void				ft_instruction_addend(t_ins **ins_lst, t_ins *new);
void				find_opcode_args(t_ins *ins, char *op);
int					check_dir_arg(t_data *data, t_ins *ins, char *arg);
int					check_ind_arg(t_data *data, t_ins *ins, char *arg);
int					check_dir_lbl(t_data *data, t_ins *ins, char *arg);
int					check_ind_lbl(t_data *data, t_ins *ins, char *arg);
int					init_args(char ***args, t_data *data, char *arguments);
int					clean_arguments(char **arguments);
int					get_args_loop(char ***args, t_data *data, t_ins *ins);
int					check_lbl(char ***args, t_data *data, t_ins *ins);
int					check_reg(t_data *data, t_ins *ins, char *arg);
int					check_valid(char *tmp);
int					join_cmd(char **prev, char *add);
int					check_error_cmds(t_data *data, int closing_quote_found, \
									int rd);
int					create_label(t_label **label, char *label_name, \
								t_data *data);
int					check_exec_code(t_asm *asm_var, t_data *data);
int					check_name_comment(t_asm *asm_var, t_data *data);
#endif

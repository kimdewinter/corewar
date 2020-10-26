/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm_errors.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/18 10:58:55 by kde-wint      #+#    #+#                 */
/*   Updated: 2020/10/26 14:54:49 by kim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int			gen_err(int err, int line)
{
	ft_printf(ANSI_COLOR_RED);
	if (err == INV_EXT)
		ft_dprintf(STDERR_FILENO, "ERROR: INVALID FILE TYPE\n");
	else if (err == MALL_ERR)
		ft_dprintf(STDERR_FILENO, "ERROR: MEMORY ALLOCATION FAILED\n");
	else if (err == INV_LINE)
		ft_dprintf(STDERR_FILENO, "ERROR: INVALID TOKEN FOUND ON LINE %d\n",
			line);
	else if (err == NO_INPUT)
		ft_dprintf(STDERR_FILENO, "ERROR: NO CHAMPION FILE SPECIFIED\n");
	else if (err == NO_CODE)
		ft_dprintf(STDERR_FILENO, "ERROR: NO OPERATIONS SPECIFIED\n");
	ft_printf(ANSI_COLOR_RESET);
	return (ERROR);
}

static int			read_err(int err)
{
	ft_printf(ANSI_COLOR_RED);
	if (err == INV_FD)
		ft_dprintf(STDERR_FILENO, "ERROR: INVALID FILE DESCRIPTOR\n");
	else if (err == INV_READ)
		ft_dprintf(STDERR_FILENO, "ERROR: COULD NOT READ FILE\n");
	else if (err == WR_ERR)
		ft_dprintf(STDERR_FILENO, "ERROR: FAILED TO CREATE .cor FILE\n");
	ft_printf(ANSI_COLOR_RESET);
	return (ERROR);
}

static int			cmd_err(int err)
{
	ft_printf(ANSI_COLOR_RED);
	if (err == DBL_NM)
		ft_dprintf(STDERR_FILENO, "ERROR: .name CAN BE SET ONLY ONCE\n");
	else if (err == DBL_COMM)
		ft_dprintf(STDERR_FILENO, "ERROR: .comment CAN BE SET ONLY ONCE\n");
	else if (err == NM_LEN)
		ft_dprintf(STDERR_FILENO, "ERROR: CHAMPION NAME IS TOO LONG\n");
	else if (err == COMM_LEN)
		ft_dprintf(STDERR_FILENO, "ERROR: CHAMPION COMMENT IS TOO LONG\n");
	else if (err == NO_NAME)
		ft_dprintf(STDERR_FILENO, "ERROR: NO NAME SPECIFIED FOR CHAMPION\n");
	else if (err == NO_COMM)
		ft_dprintf(STDERR_FILENO, "ERROR: NO COMMENT SPECIFIED FOR CHAMPION\n");
	ft_printf(ANSI_COLOR_RESET);
	return (ERROR);
}

static int			arg_err(int err, int line)
{
	ft_printf(ANSI_COLOR_RED);
	if (err == INV_NUM_ARGS)
		ft_dprintf(STDERR_FILENO,
			"ERROR: INVALID NR OF ARGS FOR INS ON LINE %d\n", line);
	else if (err == LBL_REF_INV)
		ft_dprintf(STDERR_FILENO,
			"ERROR: REFERENCE TO UNDEFINED LABEL ON LINE %d\n", line);
	else if (err == INV_REG)
		ft_dprintf(STDERR_FILENO,
			"ERROR: REFERENCE TO INVALID REGISTRY ON LINE %d\n", line);
	else if (err == INV_NUM_ARGS)
		ft_dprintf(STDERR_FILENO,
			"ERROR: INVALID NUMBER OF ARGUMENTS ON LINE %d\n", line);
	else if (err == INV_TYPE_ARGS)
		ft_dprintf(STDERR_FILENO,
			"ERROR: INVALID ARGUMENT TYPE FOR OPERATION ON LINE %d\n", line);
	else if (err == INV_ARG)
		ft_dprintf(STDERR_FILENO,
			"ERROR: INVALID ARGUMENT FOUND ON LINE %d\n", line);
	ft_printf(ANSI_COLOR_RESET);
	return (ERROR);
}

int					asm_error(int type, int err, int line)
{
	if (type == GEN_ERR)
		return (gen_err(err, line));
	if (type == READ_ERR)
		return (read_err(err));
	if (type == CMD_ERR)
		return (cmd_err(err));
	if (type == ARG_ERR)
		return (arg_err(err, line));
	if (type == SYNT_ERR)
		return (synt_err(err, line));
	return (ERROR);
}

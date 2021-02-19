/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:26:54 by nayran            #+#    #+#             */
/*   Updated: 2021/02/17 16:12:00 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINISHELL_H
#	define MINISHELL_H

#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <fcntl.h>

#	ifndef ARG_MAX
#	define ARG_MAX 4096
#	endif

typedef struct			s_vars
{
	char				*name;
	char				*value;
	int					exported;
	int					aftercmd;
	struct s_vars		*next;
}						t_vars;

/*
**		ARGS.C
*/
char					*ft_handleenv(char *env, char *exec);
char					*ft_handlepath(char *buff);
int						ft_handleargs(char *buff, int x);
int						ft_initialargs(char *buff, int num);
void					ft_args(char *buff);

/*
**		CD.C
*/
char					*ft_homedir(void);
char					*ft_path(void);
void					ft_changeenv(void);
int						ft_cd(char *buff);

/*
**		ECHO.C
*/
char					*ft_excludevar(char *buff, char *aux, char *value);
char					*ft_changebuff(char *buff, char *name);
char					*ft_putargs(char *buff);
char					**ft_avflags(char **av, char *aux, int flags);
char					**ft_echo(char *buff, char *path);

/*
**		EXEC.C
*/

char					**ft_pwd(char *buff, char *path);
char					**ft_otherexecs2(char **av, char *aux, int n);
char					**ft_otherexecs(char *buff, char *path);
char					**ft_handleexecargs(char *buff, char *path);
int						ft_exec(char *buff, char *path);

/*
**		EXIT.C
*/
int						ft_exit(char *buff);

/*
**		EXPORT.C
*/
void					ft_putvarlst(char *name, char **env);
int						ft_exportvar(char *name);
char					*ft_getvarname(char *name);
int						ft_export(char *buff);
int						ft_isexec(char *path);

/*
**		HANDLER.C
*/
char					**ft_separator2(char *buff, char **dest, char c);
char					**ft_separator(char *buff, char **dest, char c, int n);
void					ft_handler3(int semicols, char **semicolbuff);
void					ft_handler2(char *buff);
void					ft_handler(char *buff);

/*
**		MAIN.C
*/
extern char				**g_envp;
extern t_vars			*g_vars;
void					ft_prompt(char *argv);

/*
**		PIPES.C
*/
void					ft_pipe1(int *pipefd, char *buff, int num);
void					ft_pipe2(int *pipefd, char *buff, int num);
int						ft_closepipes(int *pipefd, int num, pid_t p1, pid_t p2);
int						ft_pipes2(char *b1, char *b2, int *pipefd, int num);
void					ft_pipes(char **buff, int pipesnum, int argnum);

/*
**		PROFILEENV.C
*/
char					*ft_returnenvvar(char *name);
int						ft_allenv(void);

/*
**		QUOTES.C
*/
int						ft_specounter(char *buff);
char					*ft_specialhandler(char *buff);
char					**ft_changedollarsign(char **buff, int n);
char					**ft_spcheck2(char **newbuff, int c, int x, char *buff);
char					**ft_specharcheck(char *buff, int semicols);

/*
**		REDIRECTIONS.C
*/
char					*ft_returnfilename(char *buff);
int						ft_returnfd(char *filename, int redirtype);
char					*ft_secondredir(char *filename);
int						ft_redirargs2(char *buff, int filefd, int redirtype);
void					ft_redirargs(char *buff);

/*
**		REDIRECTIONS2.C
*/
void					ft_redirpipe1(int *pipefd, char *buff);
void					ft_redirpipe2(int *pipefd, char *buff);

/*
**		SIGNALS.C
*/
void					ft_readout(int r, char *argv);
void					ft_sighandler(int sig);

/*
**		UNSET.C
*/
int						ft_excludeenvvar2(char *name);
int						ft_excludeenvvar(char *name);
int						ft_unset(char *buff);

/*
**		UTILS.C
*/
char					*ft_firstword(char *buff);
int						ft_issameend(char *str1, char *str2);
int						ft_isfile(char *path);
int						ft_isinitargs(char *buff);
void					ft_gvarsinit(void);

/*
**		UTILS2.C
*/
int						ft_isflag(char *buff);
int						ft_isechovar(char *buff);
char					*ft_istheredollsign(char *buff);
int						ft_numberofspaces(char *buff);
int						ft_isspace(char c);

/*
**		UTILS3.C
*/
char					*ft_antispace(char *buff);
int						ft_counter(char *buff, char c);
char					*ft_removeallspaces(char *buff);
char					*ft_removelinebreak(char *buff);
char					*ft_removelineendspace(char *buff);

/*
**		UTILS4.C
*/
t_vars					*ft_lastnode(t_vars *lst);
int						ft_isvar(char *buff);
int						ft_exactstr(char *str1, char *str2);
int						ft_isitvar(char *name);
char					*ft_checkinit(char *buff, char c);

/*
**		UTILS5.C
*/
int						ft_isquoted(char *buff);
int						ft_returnposition(char *buff, char c, int pos);
int						ft_isredirection(char *buff);
char					*ft_removefilename(char *buff);
int						ft_isallquote(char *buff);

/*
**		VARS.C
*/
void					ft_callvars(char *buff, int num);
char					*ft_returnvalue(char *name);
void					ft_varupdate(char *name, char *value);
char					*ft_returnname(char *buff);
int						ft_vars(char *buff);

#	endif

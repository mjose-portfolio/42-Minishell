/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:49:46 by mjose             #+#    #+#             */
/*   Updated: 2018/10/31 05:24:57 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/get_next_line.h"
# include <stdio.h>
# include <sys/stat.h>

# define NAME_SHELL "MINISHELL"
# define VERSION "v.1.beta.01"

typedef struct	s_error
{
	char		**error;
	int			err_envvar;
	int			err_return_com;
}				t_error;

typedef struct	s_split
{
	char		*s;
	char		*s_dirt;
	char		c;
	char		**tab;
	int			n_parts;
	int			i;
	int			pos;
	int			error;
	int			ctrl_quotes;
	int			to;
}				t_split;

typedef struct	s_com
{
	int			fd;
	char		*str_command;
	char		**tab_command;
	int			arguments;
	int			error_fd;
	t_error		error;
	t_split		split;
}				t_com;

typedef struct	s_env_tmp
{
	char		**tab_env;
	char		**tab_exec;
	char		*path_shell;
	char		*path_home;
	char		*path_current;
	char		*path_prev;
	char		*command_checked;
	int			err_env_home;
	int			err_env_oldpwd;
	int			is_removed;
	char		*tmp_var;
	char		*tmp_value;
	t_com		env_com;
}				t_env_tmp;

typedef struct	s_env
{
	char		**tab_env;
	char		**tab_exec;
	char		*path_shell;
	char		*path_home;
	char		*path_current;
	char		*path_prev;
	int			err_env_home;
	int			err_env_oldpwd;
	int			is_removed;
	t_env_tmp	env_tmp;
}				t_env;

typedef struct	s_prompt
{
	char		*prompt;
	int			is_written;
	char		*line;
	int			have_line;
}				t_prompt;

typedef struct	s_proc
{
	int			stat_process;
}				t_proc;

typedef struct	s_shell
{
	t_env		environ;
	t_prompt	prompt;
	t_com		command;
	t_proc		process;
	t_error		error;
}				t_shell;

typedef struct	s_count_parts
{
	char		*s;
	char		c;
	int			cnt;
	int			i;
	int			subs;
}				t_count_parts;

typedef struct	s_cd
{
	int			opt_l;
	int			opt_p;
	int			no_opt;
	char		*arg;
	int			last_flag;
	int			error;
}				t_cd;

typedef	struct	s_built_opt
{
	t_cd		cd;
}				t_built_opt;

/*
**	Core/exec.c
*/
void			exec_command(t_env *env, t_prompt *prompt, t_com *com,
					t_proc *proc);
void			exec_child(t_com *com, t_env *env, t_proc *proc);
void			exec_child_other(t_com *com, t_env *env, t_proc *proc);
void			exec_child_command_path(t_com *com, t_env *env, t_proc *proc);
int				test_existence_and_clean(t_proc *proc, char *tmp_path,
					char *tmp_com);
/*
**	Core/Display/prompt.c
*/
void			put_prompt(t_env *env, t_prompt *prompt);
void			put_prompt_clean_line(t_env *env, t_prompt *prompt,
					t_com *command);
/*
**	Core/Display/error.c
*/
void			put_err_comnf(t_com	*com, t_proc *proc, char *tmp_com);
void			put_err_comnp(char *path, t_proc *proc);
void			put_err_com_quotes_not_closed(void);
/*
**	Core/Environ/environ.c
*/
void			crt_environ(t_env *env);
void			setenv_shell(t_env *env);
void			crt_exectab(t_env *env);
void			rmv_environ(t_env *env);
void			rmv_exectab(t_env *env);
/*
**	Core/Command/command.c
*/
void			create_command(t_env *env, t_prompt *prompt, t_com *com);
int				count_com_arguments(char **command);
void			chk_tab_command(t_env *env, t_com *com);
void			rmv_comtab(t_com *com);
void			chk_error_quotes(t_com *com);
/*
**	Core/Command/com_str.c
*/
char			*conv_whites_str(char *s);
char			chg_ifwhitespace(char c);
char			*chg_simple_quotes(char *s);
char			*prepare_new_string(char *s);
/*
**	Core/Command/com_tab.c
*/
char			**split_line(char *s, char c, char *s_dirt, t_split *split);
t_split			cut(t_split split);
t_split			select_to_cut(t_split split);
int				countparts(char *s, char c);
t_count_parts	chk_forcountparts(t_count_parts counts);
/*
**	Core/Command/init_split.c
*/
void			init_split(char *s, char c, char *s_dirt, t_split *split);
/*
**	Core/Command/com_tab_arg.c
*/
char			**fill_tab(t_split *split);
void			fill_arg(t_split *split);
void			fill_with_quotes(t_split *split);
void			fill_without_quotes(t_split *split);
void			scan_for_quotes(t_split *split);
/*
**	Core/Command/tol_tab_arg.c
*/
void			init_with_quotes(t_split *split);
void			init_without_quotes(t_split *split);
void			fill_next_quote(t_split *split);
void			replace_home_char(t_com *com, t_env *env, int i);
/*
**	Core/Command/tol_tab_arg_crt.c
*/
void			init_crt_with_quotes(t_split *split);
void			init_crt_without_quotes(t_split *split);
void			go_to_next_quote(t_split *split);
void			skip_quote(t_split *split);
/*
**	Core/Command/com_tab_arg_crt.c
*/
void			crt_with_quotes(t_split *split);
void			crt_without_quotes(t_split *split);
void			check_for_null(t_split *split);
/*
**	Core/Command/types.c
*/
int				check_type_cmd(char *cmd);
/*
**	Core/Environ/path.c
*/
char			*giveme_curpath(void);
/*
**	Core/Environ/Tools/searches.c
*/
int				search_index_tab_env(t_env *env, char *value);
/*
**	Core/Environ/Tools/sets.c
*/
void			set_new_oldpwd_in_environment(t_env *env, char *new_oldpwd,
					char *to);
void			env_set_new_oldpwd(t_env *env);
void			set_pwd_to_curdir(t_env *env);
void			set_new_env_var(t_env *env, char *var, char *desc);
char			**copy_env_and_set_new_var(t_env *env, char *desc, char *var,
					int i);
/*
**	Core/Tools/shell.c
*/
void			init_shell(t_env *env, t_prompt *prompt, t_com *com);
void			clean_shell(t_env *env, t_prompt *prompt, t_com *com);
/*
**	Core/Tools/checks.c
*/
void			check_arg_for_child(t_com *com, t_env *env);
void			check_path_var_and_crt_exec_tab(char *exec, t_env *env);
/*
**	builtins/Core/exec.c
*/
void			exec_builtin(t_com *com, t_env *env);
/*
**	builtins/Core/init.c
*/
void			init_envtmp(t_env_tmp *env);
/*
**	builtins/ENV/Core/exec.c
*/
void			exec_env(t_env *env, t_com *com);
void			exec_env_command(t_env_tmp *env_tmp, t_com *com, int arg);
void			exec_envchild_command_path(t_com *com, t_env_tmp *env,
					t_proc *proc);
void			exec_envchild_other(t_com *com, t_env_tmp *env, t_proc *proc);
void			exec_envchild(t_env_tmp *env_tmp);
/*
**	builtins/ENV/Core/Display/display.c
*/
void			print_env_tmp(t_env_tmp *env);
/*
**	builtins/ENV/Core/Display/error.c
*/
void			put_err_env_comnf(t_com	*com, t_proc *proc);
/*
**	builtins/ENV/Core/environ.c
*/
void			crt_environ_tmp(t_env *env, t_env_tmp *env_tmp,
					char *first_arg);
void			setenv_tmp_shell(t_env *env, t_env_tmp *env_tmp);
void			crt_exectab_tmp(t_env_tmp *env);
void			rmv_environ_tmp(t_env_tmp *env);
void			rmv_exectab_tmp(t_env_tmp *env);
/*
**	builtins/ENV/Core/Environ/Tools/sets.c
*/
void			set_envtmpvar(t_env_tmp *env_tmp, char *arg);
void			fill_new_var(t_env_tmp *env_tmp, char *arg);
void			set_new_envtmp_var(t_env_tmp *env, char *var, char *desc);
char			**cp_evtmp_and_set_new_var(t_env_tmp *env, char *var,
					char *desc, int i);
/*
**	builtins/ENV/Core/Environ/Tools/sets.c
*/
void			set_sysvar_envtmp(t_env_tmp *env_tmp);
void			set_var_whithout_envtmp(t_env_tmp *env_tmp);
/*
**	builtins/ENV/Core/Environ/Tools/searches.c
*/
void			search_envtmpvar_and_replace(t_env_tmp *env, char *var,
					char *value);
int				search_index_tab_envtmp(t_env_tmp *env, char *value);
/*
**	builtins/ENV/Core/Environ/Checks/checks.c
*/
int				is_for_chg_env_tmp(char *arg);
void			check_arg_for_envchild(int fst_arg, int i,
					t_env_tmp *ev_tmp, t_com *cm);
void			check_env_and_and_cpy_to_tmp(t_env *env, t_env_tmp *env_tmp);
void			check_path_vartmp_and_crt_tmp_exec_tab(char *exec,
					t_env_tmp *env);
/*
**	builtins/CD/Core/exec.c
*/
void			check_and_chg_dir(t_env *env, t_com *com);
void			init_cd(t_cd *cd, t_com *com);
void			check_cd_args(t_cd *cd, t_com *com);
void			check_if_flag(t_com *com, t_cd *cd, int i, int j);
void			check_args(int i, t_cd *cd);
/*
**	builtins/CD/Core/chg_dir.c
*/
void			chg_dir_to_home(t_env *env, t_com *com, t_cd *cd);
void			chg_dir_to_oldpwd(t_env *env, t_com *com);
void			chg_dir_to_envvar(t_env *env, t_com *com, t_cd *cd);
void			chg_dir_to_input(t_env *env, t_cd *cd);
void			chg_dir(char *new_dir, t_env *env);
/*
**	builtins/CD/Core/chg_dir_with_return.c
*/
char			*chg_dir_and_return_oldpwd(char *new_dir, t_env *env);
char			*chg_dir_to_envvar_and_return_oldpwd(char *envr, t_env *env,
					t_com *com, t_cd *cd);
/*
**	builtins/CD/Core/Display/display.c
*/
void			display_cur_dir(t_env *env);
void			aply_flag(t_cd *cd, char *dir);
void			check_prev_dir(t_cd *cd, char *dir, t_env *env);
void			check_if_root_dir(t_cd *cd, char *new_dir, char *tmp);
/*
**	builtins/CD/Core/Display/error.c
*/
void			put_err_cd_var_notset(t_com *com, char *envvar, t_env *env);
void			put_err_cd_file_or_dir_noexist(char *obj);
void			put_err_cd_no_dir(char *obj);
void			put_err_cd_no_permission(char *obj);
void			put_err_cd_str_not_pwd(t_cd *cd);
/*
**	builtins/CD/Core/Display/error_arg.c
*/
void			put_err_cd_many_args(void);
/*
**	builtins/CD/Core/Environ/Checks/chk_home_pwd.c
*/
int				env_home_not_set(t_env *env);
int				env_oldpwd_not_set(t_env *env);
void			check_and_exec_setenv(t_env *env, t_com *com);
/*
**	builtins/SETENV/Core/exec.c
*/
void			check_and_exec_setenv(t_env *env, t_com *com);
/*
**	builtins/SETENV/Core/Checks/var_name.c
*/
int				check_var_name_is_alphanum(t_com *com);
/*
**	builtins/SETENV/Core/Display/display.c
*/
void			print_env(t_env *env);
/*
**	builtins/SETENV/Core/Display/error.c
*/
void			put_err_setenv_arguments(t_error *com_error);
void			put_err_setenv_alpha(t_error *com_error);
void			put_err_setenv_not_valid_name(t_error *com_error);
/*
**	builtins/SETENV/Core/Environ/Tools/create.c
*/
void			create_new_path_var(char *value, t_env *env);
/*
**	builtins/SETENV/Core/Environ/Tools/sets.c
*/
void			set_envvar_to_nothing(t_env *env, t_com *com);
void			set_envvar_to_something(t_env *env, t_com *com);
/*
**	builtins/SETENV/Core/Environ/Tools/sets.c
*/
void			set_sysvar(t_env *env, char *envvar, char *new_value);
void			set_sysvar_home(t_env *env, char *new_value);
void			set_sysvar_oldpwd(t_env *env, char *new_value);
void			set_sysvar_path(t_env *env, char *new_value);
/*
**	builtins/SETENV/Core/Environ/Tools/searches.c
*/
void			search_envvar_and_replace(t_env *env, char *envvar,
					char *new_value);
/*
**	builtins/UNSETENV/Core/exec.c
*/
void			unset_envvar_while_arguments(t_env *env, t_com *com);
void			check_and_exec_unsetenv(t_env *env, t_com *com);
/*
**	builtins/UNSETENV/Core/Environ/Tools/unset.c
*/
void			delete_var_from_env(t_env *env, char *var);
char			**copy_env_without_var(t_env *env, char *var, int i);
/*
**	builtins/UNSETENV/Core/Display/error.c
*/
void			put_err_unsetenv_no_arguments(t_error *com_error);
/*
**	builtins/ECHO/Core/exec.c
*/
void			check_and_exec_echo(t_env *env, t_com *com);
void			exec_echo(t_env *env, t_com *com);
/*
**	builtins/ECHO/Core/Display/display.c
*/
void			print_varenv_echo(t_env *env, char *string, char *arg);
void			print_value(char *value, char *real_value, t_env *env);

#endif

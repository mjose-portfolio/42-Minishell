# 21sh

This project consists of creating a complete shell and uses the work done on minishell project. We build our own shell. This project involves a large variety of standard UNIX (and POSIX) functionalities.

## 1. Project Partners

------

- [Brendan Siche](https://github.com/BrendanSiche)
- [Marc Jose](https://github.com/mjose-portfolio)

## 2. Install
------

- `make`

![alt text](README_resources/make.gif)

### 2.1. Make Options

- `make`: Compiles the files and creates the executable 21sh
- `make clean`: Remove binary files.
- `make fclean`: Deletes the binary files and the 21sh executable file.
- `make re`: Deletes the binary files and the 21sh executable file and recompiles them.

## 3. Features
------
### 3.1 Builtins

- [3.1.1 cd](./builtins#311-cd)
- [3.1.2 echo](./builtins#312-echo)
- [3.1.3 env](./builtins#313-env)
- [3.1.4 exit](./builtins#314-exit--n-)
- [3.1.5 setenv](./builtins#315-setenv)
- [3.1.6 unsetenv](./builtins#316-unsetenv)

### 3.2 Prompt

The prompt is displayed as follows:

- `["user"]<"current directory">21sh $/>`

The current directory is updated live, each time you change directory, of course, the information is collected from the environment variable `PWD`.

### 3.3 Execution of Commands

The command shall be searched for using the PATH environment variable.

It is possible to specify the paths where the command to execute resides (in case you want to execute a command that does not reside in any directory of the PATH variable, or the variable is not defined).

The parameters of each command are taken into account.

### 3.4 Redirections

- [3.4.1 Redirecting Input](./redirections#341-redirecting-input)
- [3.4.2 Redirecting Output](./redirections#342-redirecting-output)
- [3.4.3 Here-Document](./redirections#343-here-document)
- [3.4.4 Duplicating an Input File Descriptor](./redirections#344-duplicating-an-input-file-descriptor)
- [3.4.5 Duplicating an Output File Descriptor](./redirections#345-duplicating-an-output-file-descriptor)

### 3.5 Pipelines

The format for a pipeline is:

```
command1 [ | command2 ...]
```

The standard output of `command1` shall be connected to the standard input of `command2`. The standard input, standard output, or both of a command shall be considered to be assigned by the pipeline before any redirection specified by redirection operators that are part of the command.

### 3.6 `;` Operand

it is possible to separate commands using the operand `;`.

```
command1 ; command2 ...
```

### 3.7 Management Of Internal Variables

- List the internal variables of the shell via the built-in [env](./builtins#313-env).
- Removal of internal and environmental variables, via the built-in [unsetenv](./builtins#316-unset).
- Creation of environment variables for a single command, example :

### 3.8 Inhibitors

- Single-quotes: `'`

  Enclosing characters in single-quotes ( `''` ) shall preserve the literal value of each character within the single-quotes. A single-quote cannot occur within single-quotes.

- Double-quotes:`"`

  Enclosing characters in double-quotes ( `""` ) shall preserve the literal value of all characters within the double-quotes, with the exception of the characters backquote, <dollar-sign>, and <backslash>.

### 3.9 Parameter Expansions

```
~
```

**HOME path of the current user.** Is replaced by the HOME path of the current user

```
~[user name]
```

**HOME path of the user name.**  The tilde-prefix is replaced with the home directory associated with the specified user name.

```
~+
```

**PWD value**. the value of the [shell variable] `PWD` replaces the tilde-prefix.

```
~-
```

**OLDPWD value**. the value of the [shell variable] `OLDPWD` replaces the tilde-prefix.

### 3.10 Contextual Dynamic Completion

It is possible to autocomplete variables, file commands, by pressing the 'TAB key', whether or not the command has been typed.

### 3.11 Command line

The command line features are:

- Edit the line where the cursor is located.
- Move the cursor left and right to be able to edit the line at a specific location.
- Use up and down arrows to navigate through the command history able to edit if we feel like it.
- Cut, copy, and/or paste all or part of a line whit cmd+f1 cmd+f2 cmd+f3
- Move directly by word towards the left or the right using shift+LEFT and shift+RIGHT.
- Go directly to the beginning or the end of a line by pressing fn+left and fn+right.
- Write AND edit a command over a few lines.
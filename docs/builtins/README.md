# Builtins

- [3.1.1 cd](#311-cd)
  * [3.1.1.1 Options](#3111-options)
- [3.1.2 echo](#312-echo)
- [3.1.3 env](#313-env)
  * [3.1.3.1 Options](#3131-options)
- [3.1.4 exit](#314-exit)
- [3.1.5 setenv](#315-setenv)
- [3.1.6 unsetenv](#316-unsetenev)

#### 3.1.1 cd

------

Change the current working directory to `directory`. If `directory` is not supplied, the value of the `HOME` shell variable is used.

##### 3.1.1.1 Options

`-L`: symbolic links in directory are resolved after `cd` processes an instance of ‘`..`’ in directory.

`-P`: not follow symbolic links: symbolic links are resolved while `cd` is traversing `directory` and before processing an instance of ‘`..`’ in directory.

Return to index: [Builtins](#Builtins), [Minishell](../#minishell)

#### 3.1.2 echo

------

Outputs it's args to stdout, separated by spaces, followed by a newline. The return status is always 0.

Return to index: [Builtins](#Builtins), [Minishell](../#minishell)

#### 3.1.3 env

------

Set the environment for command invocation.

##### 3.1.3.1 Options

`-i`: Invoke utility with exactly the environment specified by the arguments; the inherited environment shall be ignored completely.

Return to index: [Builtins](#Builtins), [Minishell](../#minishell)

#### 3.1.4 exit

------

Shall cause the shell to exit with the exit status specified by the unsigned decimal integer n.

Return to index: [Builtins](#Builtins), [Minishell](../#minishell)

#### 3.1.5 setenv

------

Change the value of a shell option and set the positional parameters, or display the names and values of shell variables.

Syntax:

```
setenv [parameter name] [parameter value]
```

Return to index: [Builtins](#Builtins), [Minishell](../#minishell)

#### 3.1.6 unsetenv

------

Remove variable.

Syntax:

```
unsetenv [parameter name]
```

Return to index: [Builtins](#Builtins), [Minishell](../#minishell)
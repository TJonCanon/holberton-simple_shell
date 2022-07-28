# [<center>0x17. C - Simple Shell - 1142</center>](https://intranet.hbtn.io/projects/1142)
 ---
## About:
This is an interpretation of the original shell used in LINUX terminals in a simpler form. This simple shell can perform a set list of commands from the environment and can use built-in functions in the interactive and non-interactive modes. 
## Compilation:
The simple shell is compiled using the following command:
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Interactive Mode:
The simple shell is initiated in interactive mode with the command:
```sh
./hsh
$
```
## Non-Interactive Mode
The simple shell is initiated in non-interactive mode with the command:
```sh
echo "/bin/ls" | ./OUR_SHELL
```
## ***Built-in Commands***

|Built-in Command| Use |
|-----|------|
|**cd** | Changes directory|
|**env** | prints list of environmental variables|
|**clear** | clears any previous output|
|**exit** | exits the shell

***

## Authors
Dave Corley
Taylor Joyner

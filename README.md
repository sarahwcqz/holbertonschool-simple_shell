Compile using following command : 
```c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```


## Structure of files
+ .gitignore                            //	file containing all the tests and executable files
+ _gentenv.c               				//	function to get the value of the passed env variable
+ AUTHORS                				 //	files containing info about the people who contributed
+ checkarg.c				             //	function to analyzes the first argument passed to the program
+ get_path.c                      		 //	finds directory in which the passed command has been found
+ hsh_man								//	manual page of hsh
+ main.c                             	//	main function (entry point of the prog)
+ pr_env.c								//	function that prints the environement variables to the stdout
+ README.md                             //	explanation of the project
+ simple_shell.h                        //	header containing all used fonctions and librairies
+ spoon.c								//	function to launches a fork process


## Authors
Sarah Wacquiez
Priam Demailly
# minishell
work in progress

les entrées peuvent être stdin mais aussi:
- l'éxecution d'un programme
~$ ./toto
lol

ou idem avec

~$ < toto sh
lol
- ...
~$ echo "echo lol" | sh
lol
- ...
~$ sh
sh-5.0$ echo lol
lol
sh-5.0$ exit
- ...
~$ sh toto
lol

voir readline pour lire la commande d'entrée
fonctions autorisees :
- printf, malloc, free, write, open, read, close, fork, wait, waitpid, exit, execve, strerror, perror, dup, dup2, pipe, getenv,
- readline : char *readline(const char *prompt)
	couramment utilisée pour lire une ligne de texte depuis l'entrée standard (typiquement le clavier). #include stdio.h
	prompt : Une chaîne de caractères affichée à l'utilisateur pour l'inviter à saisir une entrée. Si prompt est NULL, aucun message n'est affiché.
	Retourne : Un pointeur vers une chaîne de caractères contenant la ligne lue. La mémoire pour cette chaîne est allouée dynamiquement et doit être libérée par l'appelant en utilisant free() lorsque la ligne n'est plus nécessaire.
- rl_clear_history : void rl_clear_history(void);
	Efface l'intégralité de l'historique des commandes en mémoire. Après l'appel de cette fonction, toutes les commandes précédemment stockées dans l'historique sont perdues et ne peuvent plus être rappelées.

=> les 3 fonctions suivantes sont souvent utilisées dans des programmes qui doivent gérer des événements asynchrones, tels que des interruptions ou des signaux (ctrl + C), où la ligne de commande actuelle doit être réaffichée proprement après l'événement.
	- rl_on_new_line(); // Indique à Readline qu'une nouvelle ligne commence : void rl_on_new_line(void);
	- rl_replace_line("", 0); // Efface la ligne actuelle (si nécessaire) :
	void rl_replace_line(const char *text, int clear_undo);
	text : Une chaîne de caractères représentant le nouveau contenu de la ligne.
	clear_undo : Un entier indiquant si l'historique d'annulation (undo) doit être effacé. Si clear_undo est non nul, l'historique d'annulation sera effacé, sinon il ne le sera pas.
	- rl_redisplay(); // Réaffiche le prompt et la ligne de commande
	void rl_redisplay(void);
- add_history : int add_history(const char *line);
	fait partie de la bibliothèque GNU Readline et est utilisée pour ajouter une ligne de commande à l'historique des commandes.
	line : Une chaîne de caractères représentant la ligne de commande à ajouter à l'historique. La chaîne doit être allouée dynamiquement (par exemple, retournée par readline), car Readline ne copie pas cette chaîne.
	Retourne : Un entier indiquant le succès de l'opération. La fonction retourne 0 si la ligne n'a pas été ajoutée (par exemple, si line est NULL ou vide) et un nombre non nul en cas de succès.
- access : int access(const char *pathname, int mode);
	est utilisée pour vérifier les permissions d'accès à un fichier ou un répertoire. #include <unistd.h>
	pathname : Un pointeur vers une chaîne de caractères qui spécifie le chemin du fichier ou du répertoire à vérifier.
	mode : Un entier qui spécifie le type de test à effectuer : F_OK, Vérifie l'existence du fichier; R_OK, Vérifie si le fichier est lisible; W_OK, Vérifie si le fichier est inscriptible; X_OK, Vérifie si le fichier est exécutable.
	retourne : 0, Si le fichier satisfait les tests spécifiés par mode; -1, Si le fichier ne satisfait pas les tests spécifiés par mode, et errno est mis à jour pour indiquer l'erreur.
- wait3,
- wait4,
- signal,
- sigaction,
- sigemptyset,
- sigaddset,
- kill,
- getcwd,
- chdir,
- stat,
- lstat,
- fstat,
- unlink,
- opendir,
- readdir,
- closedir,
- isatty,
- ttyname,
- ttyslot,
- ioctl,
- tcsetattr,
- tcgetattr,
- tgetent,
- tgetflag,
- tgetnum,
- tgetstr,
- tgoto,
- tputs

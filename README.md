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

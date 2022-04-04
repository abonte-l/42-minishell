# 42-minishell

[X] Afficher un prompt en l’attente d’une nouvelle commande.  

[X] Posséder un historique fonctionnel.  

[X] Chercher et lancer le bon exécutable (en se basant sur la variable d’environnement
PATH, ou sur un chemin relatif ou absolu).  

[] Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non
demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).  
[] Gérer ’ (single quote) qui doit empêcher le shell d’interpréter les méta-caractères
présents dans la séquence entre guillemets.  
[] Gérer " (double quote) qui doit empêcher le shell d’interpréter les méta-caractères
présents dans la séquence entre guillemets sauf le $ (signe dollar).  
[] Implémenter les redirections  
		[] < doit rediriger l’entrée  
		[] > doit rediriger la sortie  
		[]  << doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour !  
		[] >> doit rediriger la sortie en mode append  
		
[] Implémenter les pipes (caractère |)  
[] Gérer les variables d’environnement  
[] Gérer $? qui doit être substitué par le statut de sortie de la dernière pipeline
exécutée au premier plan.  
[] Gérer ctrl-C, ctrl-D et ctrl-\  
		[] ctrl-C  
		[X] ctrl-D  
		[] ctrl-\  

[X] les builtins suivantes
		[X] echo et l’option -n
		[X] cd uniquement avec un chemin relatif ou absolu
		[X] pwd sans aucune option
		[X] export sans aucune option
		[X] unset sans aucune option
		[X] env sans aucune option ni argument
		[X] exit sans aucune option
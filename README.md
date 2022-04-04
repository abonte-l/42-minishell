# 42-minishell

- [x] Afficher un prompt en l’attente d’une nouvelle commande.  

- [x] Posséder un historique fonctionnel.  

- [x] Chercher et lancer le bon exécutable (en se basant sur la variable d’environnement
PATH, ou sur un chemin relatif ou absolu).  

- [ ] Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non
demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).  
- [ ] Gérer ’ (single quote) qui doit empêcher le shell d’interpréter les méta-caractères
présents dans la séquence entre guillemets.  
- [ ] Gérer " (double quote) qui doit empêcher le shell d’interpréter les méta-caractères
présents dans la séquence entre guillemets sauf le $ (signe dollar).  
- [ ] Implémenter les redirections  
		- [ ] < doit rediriger l’entrée  
		- [ ] > doit rediriger la sortie  
		- [ ]  << doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour !  
		- [ ] >> doit rediriger la sortie en mode append  
		
- [ ] Implémenter les pipes (caractère |)  
- [ ] Gérer les variables d’environnement  
- [ ] Gérer $? qui doit être substitué par le statut de sortie de la dernière pipeline
exécutée au premier plan.  
- [ ] Gérer ctrl-C, ctrl-D et ctrl-\  
		- [ ] ctrl-C  
		- [x] ctrl-D  
		- [ ] ctrl-\  

- [x] les builtins suivantes
		- [x] echo et l’option -n  
		- [x] cd uniquement avec un chemin relatif ou absolu  
		- [x] pwd sans aucune option  
		- [x] export sans aucune option  
		- [x] unset sans aucune option  
		- [x] env sans aucune option ni argument  
		- [x] exit sans aucune option  
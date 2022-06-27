# 42-minishell

- [x] Afficher un prompt en l’attente d’une nouvelle commande.  
- [x] Posséder un historique fonctionnel.  
- [x] Chercher et lancer le bon exécutable 
    
- [ ] Gérer ’ (single quote)  
- [ ] Gérer " (double quote)  
- [ ] Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non
demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).
  
- [ ] Implémenter les redirections  
	- [ ] <   
	- [ ] >  
	- [ ] <<  
	- [ ] >>  
  
- [ ] Implémenter les pipes (caractère |)  
  
- [ ] Gérer les variables d’environnement  (pourquoi : 🌸minishell $> echo "$PATH"
/home/anma/.local/bin:/u� <--premiere entree de la commande  
🌸minishell $> echo "$PATH"
/home/anma/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin <--deuxieme entree de la commande )  
- [ ] Gérer $?  
  
- [x] Gérer ctrl-C, ctrl-D et ctrl-\  
	- [x] ctrl-C  
	- [x] ctrl-D  
	- [x] ctrl-\  
  
- [x] les builtins suivantes
	- [x] echo et l’option -n  
	- [x] cd uniquement avec un chemin relatif ou absolu  
	- [x] pwd sans aucune option  
	- [x] export sans aucune option  
	- [x] unset sans aucune option  
	- [x] env sans aucune option ni argument  
	- [x] exit sans aucune option  

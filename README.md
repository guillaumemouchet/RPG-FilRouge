# CPP_FilRouge_ISCc_Mouchetg
Ce projet à pour but de créer un RPG de toutes pièces
C'est un projet fait sur le deuxième semestre de la he-arc (celui de printemps)
les DEV jusqu'à environ V5 seront un travail suivi par un fil rouge, ensuite ce sera du travail autonome ((DEV): travail autonome ajout de XXX)

Pour comprendre comment fonctionne le jeu:
il y a trois type de Héros, les Warriors, les Wizards et les Necromancers:
les Warriors n'ont pas de mana et utilise principalement la Force pour combattre, ils commencent le jeu avec un bouclier ce qui leur aide pour une de leur attaque, ils auront aussi dans leur sac une épée et une potion.

les Wizards et Necromancers ont du mana et chaque sort leur coûte du mana, si il n'y a pas assez de mana il frappera l'ennemi avec ses poings ou une armes si il en a une d'équipée.Ils commenceront tous les deux avec une épée en main et auront dans leur sac un bouclier et une potion.

Pour ce qui est de la création du personnage, il sera possible de choisir parmis les 3 classes et donner 30 points de compétances à répartir parmis strength, agility, intelligence, Health, et Mana (sauf pour les Warriors). il n'est pour l'instant pas possible de choisir le nom du héro.

Maintenant pour le système de combat il faut comprendre que c'est un système de tour par tour qui commence par le monstre, il suivra un pattern prédéfini d'attaque (sauf pour Azazel qui attaque de manière aléatoire), ensuite vient au tour du joueur, ou il pourra choisir parmis 3 actions, Attaquer, abondonner, ou ouvrir son sac. 
Si il abondonne c'est la fin et on arrête la partie.
si il combat il aura le choix parmis ces différentes attaques, qui marcheront de la manière suivant, les dégats seront calculé sur une constante de dégats de l'attaque et sur le strength ou intelligence du héro (avec un ajout de l'objet équipé dans les cas nécessaire).
Si il ouvre son sac suivant l'objet il lui proposer de la boire (ou l'équiper) ou non, ou de le jeter, si l'objet est jeter il est perdu à tout jamais.

Une fois le combat fini le héro trouve un objet aléatoire par terre avec des statistiques allant de 5 à 15, il peut choisir de le mettre ou non dans son sac.
Après il se repose, il soignera ses points de vie et regagnera un peu de mana, il pourra ensuite réorgnaniser son sac avec comme valeur 0 le fond du sac. (il n'y a pas la possibilité de jeter des objets pendant le tri car le sac étant infini il suffit de mettre les objets inutiles dans le fond)

Ensuite il reprend sa course et rentre dans la prochaine salle du dongeon, tout ça jusqu'à ce que le combat de boss ou si il remporte c'est la fin du jeu.























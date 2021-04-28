# CPP_FilRouge_ISCc_Mouchetg
Ce projet à pour but de créer un RPG de toutes pièces
C'est un projet fait sur le deuxième semestre de la he-arc (celui de printemps)
les DEV jusqu'à environ V5 seront un travail suivi par un fil rouge, ensuite ce sera du travail autonome ((DEV): travail autonome ajout de XXX)

Pour comprendre comment fonctionne le jeu:
il y a trois type de Héros, les Warriors, les Wizards et les Necromancers:
les Warriors n'ont pas de mana et utilise principalement la strength pour combattre, ils commencent le jeu avec un bouclier ce qui leur aide pour une de leur attaque.

les Wizards et Necromancers ont du mana et chaque sort leur coûte du mana, si il n'y a pas assez de mana il frappera l'ennemi avec ses poings ou une armes si il en a une d'équiper. le Wizard aura une épée alors que le Necromancer aura une potion.

Pour ce qui est de la création du personnage, il sera possible de choisir parmis les 3 classes et donner 30 points de compétances à répartir parmis strength, agility, intelligence, Health, et Mana (sauf pour les Warriors). il n'est pour l'instant pas possible de choisir le nom du héro.

Maintenant pour le système de combat il faut comprendre que c'est un système de tour par tour qui commence par le monstre, il suivra un patterne prédéfini d'attaque (peut être qu'il y aura une petite IA ou alors de l'aléatoire dans l'attaque du monstre), ensuite vient au tour du joueur, ou il pourra choisir parmis 3 actions, se battre, abondonner, ou ouvrir son sac. 
Si il abondonne c'est la fin et on arrête la partie.
si il combat il aura le choix parmis ces différentes attaques, qui marcheront de la manière suivant, les dégats seront calculé sur une constante de dégats de l'attaque et sur le strength ou intelligence du héro (avec un ajout de l'arme équipée dans les cas nécessaire).

Pour l'instant vu qu'il n'y a qu'un seul combat il ne se passe rien à la fin, pas de loot ni de repos.
Mais il faudrait implémenter un système de loot que le héro puisse améliorer son équipement mais aussi un moment de repos entre deux combats, ou le héros sera un peu soigné de ses blessures et de ses pertes de mana mais ou il pourra aussi réorganiser son sac pour le mettre dans un ordre pratique de combat (ou abondonner des affaires mais le sac étant infini il a qu'à les ranger dans le fond).

(PAS ENCORE FAIT)
si il ouvre son sac il pourra prendre l'objet en haut de son sac et si c'est une arme (donc Sword ou Shield) il pourra échanger entre son sac et sa main, mais si c'est une potion il pourra directement la boire ce qui rend de la vie.























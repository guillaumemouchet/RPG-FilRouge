 # cpp_filrouge_isc1c_mouchetg 


Ce projet fait partie du cours de C++ de la He-arc au semestre de printemps, le but est de créer un simple RPG.

Les cinqs premières version faisait partie d'un fil rouge ou il a juste eu un suivi du cours, tout ce qui est fait par la suite est du travail autonome et des choix d'ajouts personnel.
Pour ce qui est des push sur le git tout ce qui comporte une version (qui va jusqu'à V5) sera ce qui a été fait en cours sinon ce sera le travail personnel. les commentaire auront la forme (DEV): ajout de XXX.

## Déroulement du jeu

Dans ce RPG il vous sera possible de choisir parmis 3 classes qui sont le Warrior, le Wizard et le Necromancer, votre but sera de tuer une suite de monstre, qui sont un Goblin et un Undead, jusqu'à arriver au boss final Azazel et de le vaincre.

Le jeu se passe en tour par tour avec le monstre qui attaque en premier, le Goblin et le Undead marchent sur un pattern prédéfini alors que Azazel attaque de manière aléatoire. 

Ensuite c'est au tour du joueur, il pourra choisir parmis 3 actions, attaquer, sac ou abondonner:
1) Attaquer permet ensuite de choisir parmis une des 3 attaques du héro choisi
2) Sac permet d'ouvrir le sac et de voir ce qu'il y a en haut, puis de soit l'équiper ou non, ou le jeter.
3) Abondonner permet d'arrêter le jeu complétement
Ces actions seront donc faite en boucle jusqu'à qu'un des personnages meurt.

Si le joueur meurt alors la partie s'arrête et le programme avec, si le monstre meurt le héro ramasse du butin et passe à la suite.

Une fois que le monstre est vaincu et que le héro ait ramassé l'objet, il se repose, ce qui lui rend 30% de sa vie total et de son mana total. Il pourra aussi trier son sac ou 0 sera le fond et x (x étant la taille du sac - 1) sera le dessus. vu que le sac est infini les objets inutiles pourront être mis au fond, et les objets plus utile vers le haut.
Puis il commencera le deuxième combat etc.


## Explication

### Compétences:

Le joueur doit distribuer 30 points de compétences dans son héros, il peut mettre des compétences au minimum 1 point par compétence. 
<ul>
<li>La Strength permet de faire des attaques physiques plus puissante</li>
<li>L'Agility permet de potentiellement esquiver des attaques ennemies</li>
<li>Les Hps determinent vos points de vie avec un facteur 10</li>
<li>L'Intelligence permet de faire des attaques magiques plus puissante</li>
<li>Le nom est par défaut et détermine votre class (Chandra = warrior, Lilianna = Necromancer, Jace = Wizard)</li>
<li>Le IObject défini l'objet que vous avez en main, soit une épée ou un bouclier, les potions ne peuvent que être bue depuis le haut du sac.</li>
<li>Le Mana determine ce qui peut être lancé comme sort, car les Necromancers et Wizards devront dépenser du mana pour pouvoir lancer des sorts, il y a aussi un facteur 10. </li>
</ul>

<p>

### Combat:

Toutes les actions pendant un combat utilisent le tour, si on ouvre le sac et qu'on jette l'objet le tour sera utilisé, si on l'utilise aussi, c'est uniquement en cas de non qu'un retour en arrière est fait.</p>

Pour ce qui est des calculs de dégats, il est pris en compte la compétences de l'attaque (soit Strength ou Intelligence), une constante de dégat du sort et aussi quand nécessaire l'objet qui est équipé dans votre main.

Pour ce qui est de la perte de dégats, elle est calculée sur la compétences de l'attaque (soit Strength ou Intelligence), une constante de dégat et à laquel il est soustrait une partie des dégats si vous avez un bouclier d'équipé.

Si le Wizard ou Necromancer ne possède plus de mana pendant un combat il devra choisir un sort et vu qu'il aura plus de mana il attaquera avec une attaque simple, dépendant de son objet équipé.

### Autre:

Le jeu est interactif donc il est possible de choisir un peu prêt toute ses actions, qui seront toujours numérique.
Ce sera les valeurs entre crochets [] ou des valeurs proposées dans une phrases:

    Exemple:
    [0] Warrior
    ou
    Veuillez entrer une valeur entre 0 et 3, 0 étant le fond du sac.


le Warrior commence avec un bouclier en main, et une potion en haut de son sac et une épée au fond.
Le Wizard et le Necromancien commencent avec une épée en main, une potion en haut de son sac et un bouclier au fond.



## Amélioration
liste les améliorations et modifications futur du projet
### Idée 1:
Mettre en place un système de dictionnaire qui compléterait le fichier d'Enum déjà présent avec comme structure de map Personnage-->Attaque-->valeur.
Personnage, {
    {
        Attaque1, {
            {Mana, x},
            {Dégats, y}
        }
        Attaque2, {
            {Mana, x},
            {Dégats, y}
        }
    }
}
### Idée 2:
 Un équilibrage total du jeu avec une réflexion différente du calcul du dégat, ou il y aurait un ajout de stat de défence qui prendrait en compte la force et l'agilité.
### Idée 3:
Faire un jeu multi joueur ou soit deux héros combattent entre eux ou alors que un joueur joue les héros et l'autre joue les monstres.
Ce qui fait qu'en début de partie, le joueur  choisi entre les deux modes, et suivant la réponse il y aura un changement de comportement.

### Idée 4:
Faire des niveaux de difficulté, qui rendent les monstres plus fort, comme avant ou en début de partie le joueur choisi la difficulté ce qui changerait la construction par paramêtre des monstres.
Soit des monstres préfait qu'on choisi suivant la difficulté ou que leur stat corresponde à x+difficulté, par exemple:
<ul>
<li>très facile =-1</li>
<li>facile = 0</li>
<li>difficile = 1</li>
<li>Cauchemar = 2</li>
</ul>

## UML

Le diagramme de class se trouve dans le fichier [UML.uxf](UML.uxf) pour plus d'informations.

## Versions

Liste des versions : [Cliquer pour afficher](https://gitlab-etu.ing.he-arc.ch/guillaum.mouchet/cpp_filrouge_iscc_mouchetg)

## Auteurs
 **Guillaume Mouchet** _alias_ [@guillaum.mouchet](https://github.com/guillaum.mouchet)

_mail_:<a href="mailto:guillaume.mouchet@he-arc.ch">
  guillaume.mouchet@he-arc.ch </a>

















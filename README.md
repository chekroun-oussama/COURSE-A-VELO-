# PROJET-EN-C++
## Description de jeux : 
CYCLIST DODGER est un jeu d’arcade dans lequel le joueur incarne un cycliste roulant sur une route semée d’obstacles (pierres). 
Le but du jeu est de **parcourir la plus longue distance possible** en **évitant les obstacles** qui apparaissent progressivement à l’écran. 

Le joueur peut **se déplacer latéralement** (gauche/droite) à l’aide des touches du clavier pour esquiver les obstacles. 
Une collision avec une pierre met fin à la partie. 

Le jeu comprend : 

- Un **menu principal** pour démarrer ou quitter ou A propre . 
- Un **système de score ou de chronomètre** qui mesure la performance du joueur. 
- DES **interfaces simple** en 2D basée sur SDL2.
  
Ce jeu allie **réactivité, coordination** et **anticipation**, tout en restant accessible et amusant. 
## L’architucture de code : 
**Organization générale** : 
Le jeu CYCLIST DODGER est développé en C++ selon une **architecture orientée objet**. 
Chaque entité principale du jeu (joueur, obstacles, interface, etc.) est représentée par une **classe dédiée**, ce qui permet une séparation claire des responsabilités et facilite la maintenance et l'évolution du code. 
Les responsabilités sont réparties comme suit : 
- **Menu** : affiche le menu principal et gère la navigation entre les états du jeu. 
- **About** :affiche bref explication sur le jeux. 
- **Game** : gère la boucle principale du jeu, les événements SDL, et le rendu général. 
- **Player** : contrôle le cycliste (position, mouvements, affichage). 
- **Pierre** : gère les obstacles que le joueur doit éviter. 
- **Compteur** : mesure le temps. 

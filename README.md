# Narcotic Nights

Projet du LIFAPCD de Smail YAHIOUNE (12103134) et Malick SOW (12312542). Narcotic Nights est un jeu en vue de dessus ou vous incarnez un policier chargé d'éradiquer un cartel de drogue.
Le jeu est de type roguelike, le "donjon" dans lequel le joueur évolue est générée procéduralement à chaque nouvelle partie.

Les deplacements se font avec les flèches diréctionelles, l'idée est de rejoindre la salle du boss (la plus éloignée de la salle de départ) et affronter les ennemies sur le passage.
La touche "T" permet d'ouvrir un menu de debug.

# Compilation

Le projet est compilable sur GNU/Linux et Windows. 

## GNU/Linux

**Pré-réquis:** 
- gcc / g++ : compilateur
- cmake et ninja
- Bibliothèques: ``sdl2`` ``sdl2_image`` ``SDL2_mixer`` ``sdl2_ttf_ ``json``

Une commande pour tout installer sur Fedora : ``sudo dnf install gcc cmake ninja-build SDL2-devel SDL2_image-devel SDL2_mixer-devel SDL2_ttf-devel_``

1) Ensuite à la racine du projet, configurer le projet: ``cmake --preset linux-x64-debug`` (ou linux-x64-release pour compiler en mode Release)
2) Et finalement compiler : ``cd build/linux-x64-debug && ninja all`` (ou release...)

## Windows
- Visual Studio avec le module Developpement C++ installé
- vcpkg (inclus normalement dans Visual Studio) et définir la variable d'environement ``VCPKG_ROOT`` avec le chemin vers la racine du dossier vcpkg
  
1) Ouvrir le projet avec Visual Studio et configurez le avec un des deux presets proposés (debug et release)
2) VCPKG s'occupera de récuperer toutes les dépendences lui même
3) Compiler et executer

## Générer la doc

- Faire ``ninja doc`` depuis le dossier de build

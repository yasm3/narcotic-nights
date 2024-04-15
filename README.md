# Narcotic Nights

Projet du LIFAPCD

# Compilation

Le projet est compilable sur GNU/Linux et Windows. 

## GNU/Linux

**Pré-réquis:** 
- gcc / g++ : compilateur
- cmake et ninja
- Bibliothèques: ``sdl2`` ``sdl2_image`` ``SDL2_mixer`` ``json``

Une commande pour tout installer sur Fedora : ``sudo dnf install gcc cmake ninja-build SDL2-devel SDL2_image-devel SDL2_mixer-devel``

1) Ensuite à la racine du projet, configurer le projet: ``cmake --preset linux-x64-debug`` (ou linux-x64-release pour compiler en mode Release)
2) Et finalement compiler : ``cd build/linux-x64-debug && ninja all`` (ou release...)

## Windows
- Visual Studio avec le module Developpement C++ installé
- vcpkg (inclus normalement dans Visual Studio) et définir la variable d'environement ``VCPKG_ROOT`` avec le chemin vers la racine du dossier vcpkg
  
1) Ouvrir le projet avec Visual Studio et configurez le avec un des deux presets proposés (debug et release)
2) VCPKG s'occupera de récuperer toutes les dépendences lui même
3) Compiler et executer

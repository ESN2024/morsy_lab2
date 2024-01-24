# Lab 2 : Afficheur 7 segment counter 
## Introduction

Ce Tp a pour objectif de créer un système Nios II de base, d'implémenter un compteur décimal à un chiffre et de l'afficher sur un afficheur 7 segments.Ensuite, on doit realiser apres un compteur utilisant 3 afficheurs 7 segment et gerer le compteur avec un timer. 

## Architecture 

![Architecture_7_seg drawio (1)](https://github.com/ESN2024/morsy_lab2/assets/74385250/334beb8d-2ff2-445b-be1a-9d3ebadc84a4)

Tout d'abord, j'ai inclus les composants nécessaires pour reconstruire mon système de base.
* RAM
* NIOS-2
* CLOCK
* JTAG

Apres, on ajoute :
* 3xPIO 4 bits pour l'aficheur 7 segment

## Platform Designer

voici mon architecture sous Platform Designer (QSYS)

![image](https://github.com/ESN2024/morsy_lab2/assets/74385250/5932dd5c-32d8-436e-8551-75ec39aa8de7)

## Questions de Tps
J'ai commence par ajouter un nouveau composant VHDL permettant de convertir la valeur du compteur en valuer affiché sur le 7 segment "BCD_2_7SEG.vhd"

Apres dans mon "timer.c", à l'aide d'une boucle while, je manipule un compteur, divisant successivement ses unités, dizaines et centaines. Les chiffres obtenus sont stockés dans un tableau. Enfin, j'utilise ces chiffres pour afficher dynamiquement le compteur sur trois afficheurs 7 segments distincts à l'aide de la fonction 'IOWR_ALTERA_AVALON_PIO_DATA'.Aussi j'ai une fonction interrup qui s'emploie a afficher les valeurs du compteurs sur le 7-segments chaque 1 seconde. 

Dès que le programme est téléchargé sur la cible, la fonction d'interruption du Timer est appelé et l'intérruption est déclenchée, ce qui a pour effet de démarrer le comptage et l'affichage des valeurs sur le 7-segment.

## Résultat

Les vidéos ci-dessous montrent une démonstration du fonctionnement du système. La 1ère montre le compteur au démarrage du système et la seconde montre le comptage du Timer à des valeurs avancées.

https://github.com/ESN2024/morsy_lab2/assets/74385250/b21db64b-9496-4010-bf70-29097dbb4088

https://github.com/ESN2024/morsy_lab2/assets/74385250/4394184f-bd46-4cd0-b61f-fb0e66e05abf

## Conclusion 
Ce lab a été utile, notamment pour comprendre l'utilisation du Timer, la gestion des interruptions, ainsi que l'utilisation de l'afficheur 7 segments. J'ai également appris comment afficher une valeur au-dessus de celui-ci.




Voici la documentation pour le script bash : 
Description 
Ce script permet à l'utilisateur de sélectionner les colonnes et les lignes d'un fichier .csv en utilisant des options de ligne de commande. Il utilise AWK pour extraire les données spécifiées et les imprimer dans la sortie standard. 
Utilisation 
Pour utiliser ce script, vous devez d'abord donner les bons droits d'exécution au fichier en utilisant la commande suivante: 
chmod +x script.sh 
Ce script utilise AWK pour extraire les colonnes et les lignes spécifiées. Les options sont -f pour spécifier le fichier .csv, -c pour spécifier les colonnes à conserver et -r pour spécifier la plage de lignes à conserver. Il utilise des arguments de ligne de commande pour récupérer les options et les valeurs spécifiées par l'utilisateur. 
Il est important de noter que pour utiliser ce script, vous devez donner les bons droits d'exécution au fichier et l'appeler en précisant les options nécessaires . 
Ensuite, vous pouvez exécuter le script en utilisant les options suivantes : ./script.sh -f meteo_filtered_data_v1.csv -c column1,column2 -r start,end 
-f meteo_filtered_data_v1.csv : spécifie le fichier .csv d'entrée 
-c column1,column2 : spécifie les colonnes à conserver séparées par des virgules -r start,end : spécifie la plage de lignes à conserver, où "start" est le numéro de ligne de départ et "end" est le numéro de ligne de fin 
Exemple 
Voici un exemple d'utilisation du script 
./script.sh -f meteo_filtered_data_v1.csv -c column1,column3 -r 2,5 
Cela extrait les colonnes column1 et column3 pour les lignes 2 à 5 dans le fichier data.csv et les imprime dans la sortie standard. 
Pour le tracer des graphiques : 
Ce script triera le fichier .csv sur la colonne spécifiée par l'utilisateur, puis générera un diagramme à barres en utilisant les colonnes spécifiées pour les abscisses et les ordonnées.
description du programme en c : 
Le but de notre programme en C est très simple. Le programme en C va se charger de récupérer les données du fichier csv contenant toutes les données météo pour les stocker dans une liste chaînée. Ensuite, le programme va se charger de trier la liste chaînée contenant les données du fichier csv pour enfin créer un fichier de sortie avec les données qui ont été triées auparavant. 
Pour pouvoir réaliser toutes ces actions nous avons créé plusieurs fonctions. Tout d’abord une fonction qui permet d'insérer les mots dans la liste chainée. En effet, il sera beaucoup plus simple par la suite de trier les données si on les stocke dans une liste. On aurait pu choisir l'arbre ou le tableau aussi. 
Ensuite une nouvelle fonction va ici permettre d’ouvrir le fichier que nous voulons trier justement grâce à la fonction fopen. On va parcourir l’ensemble de ce fichier et grâce à la fonction évoquée précédemment on va pouvoir mettre les mots qui composent le fichier csv dans une liste chaînée. 
Par la suite, une fois que les données du fichier csv auront été stockées grâce aux listes chainées, nous pouvons désormais passer à l'étape du triage de données. La fonction que nous avons créé est basée sur la méthode du tri à bulle. C'est-à-dire que cette fonction va comparer 2 données consécutives d’une liste chaînée et de les inverser si elles ne sont pas rangées dans l’ordre croissant. 
Enfin la dernière fonction que nous avons créée permet cette fois-ci de créer un nouveau fichier dans lequel il y aura les données qui auront été créées précédemment par la fonction de triage à bulle. Pour ce faire, la fonction va d’abord créer le fichier qui va contenir les données puis grâce à fputs elle va pouvoir écrire à l’intérieur de ce fichier les données triées précédemment.
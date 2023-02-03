#!/bin/bash

# Message pour l'utlisation du script
usage() {
  echo "Usage: $0 -f file.csv -c column1,column2 -r start,end"
  echo " -f : The input CSV file"
  echo " -c : Comma-separated list of columns to keep"
  echo " -r : Range of rows to keep in the format of 'start,end'"
  exit 1
}

# Check for missing arguments
if [ $# -lt 6 ]; then
  usage
fi

# Get input arguments
while getopts "f:c:r:" opt; do
  case $opt in
    f) file="$OPTARG"
    ;;
    c) columns="$OPTARG"
    ;;
    r) range="$OPTARG"
    ;;
    *) usage
    ;;
  esac
done

# Extrait les colonne spécifié et les lignes 
start=$(echo $range | cut -d ',' -f1)
end=$(echo $range | cut -d ',' -f2)
awk -v cols="$columns" -v start="$start" -v end="$end" 'BEGIN {
    split(cols,col_arr,",");
    for(i in col_arr) cols_to_keep[col_arr[i]]
}
{
    if(NR >= start && NR <= end) {
        for(i=1;i<=NF;i++) if(i in cols_to_keep) printf "%s,",$i
        print ""
    }
}' $file

chmod +x script.sh
./script.sh -f file.csv -c column1,column2 -r 1,10


#!/bin/bash

# Vérifiez si le fichier .csv est fourni en argument
if [ $# -eq 0 ]; then
  echo "Aucun fichier .csv n'a été fourni."
  exit 1
fi

# Stocker le nom de fichier dans une variable
file=$1

# Demandez à l'utilisateur quelles colonnes trier
echo "Sur quelle colonne souhaitez-vous trier le fichier .csv?"
read -p "Colonne numéro: " column

# Trier le fichier .csv sur la colonne choisie
sort -t, -k$column $file > sorted.csv

# Demandez à l'utilisateur quelle colonne utiliser pour les abscisses et les ordonnées du diagramme
echo "Quelle colonne souhaitez-vous utiliser pour les abscisses du diagramme?"
read -p "Colonne numéro: " x_column
echo "Quelle colonne souhaitez-vous utiliser pour les ordonnées du diagramme?"
read -p "Colonne numéro: " y_column

# Générer le diagramme à barres
gnuplot <<- EOF
  set datafile separator ","
  set xlabel "Colonne $x_column"
  set ylabel "Colonne $y_column"
  set title "Diagramme des données triées"
  plot "sorted.csv" using $x_column:$y_column with boxes
EOF

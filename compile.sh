PURPLE='\033[0;35m'
NC='\033[0m'

if [ $# -ne 1 ]
then
    echo "usage: $0 fonction"
    exit 1
fi

echo "\n${PURPLE}===== Génération de l'exécutable =====${NC}\n"
gcc -Wall -g $1.c -o exec_files/$1.out -lm

read -p "Exécuter $1.out ? [o/n] " input
until [ $input = o ] || [ $input = n ]
do
   read -p "Exécuter $1.out ? [o/n] " input
done


if [ $input = o ]
then
    echo "\n${PURPLE}============== Exécution =============${NC}\n"
    ./exec_files/$1.out
else
    echo "\n${PURPLE}======================================${NC}\n"
    exit 0
fi


read -p "Envoyer sur le dépôt distant ? [o/n] " input
until [ $input = o ] || [ $input = n ]
do
   read -p "Envoyer sur le dépôt distant ? [o/n] " input
done


if [ $input = o ]
then
    echo "\n${PURPLE}================ Envoi ===============${NC}\n"
    git add $1.c

    read -p "Message du Commit : " input

    git commit -m "$input"
    git push
else
    echo "\n${PURPLE}======================================${NC}\n"
    exit 0
fi
# Robot-SAE-S1-G4-B11
Programme du robot lors de la SAE 2 en GEII a IUT3 Toulouse


ce placer dans le fichier



commande pour compiler le programme principal
g++ -Wall -Wextra -Wduplicated-cond -Wduplicated-branches -Wsign-conversion -Wlogical-op -Wuseless-cast -Werror -pedantic -std=gnu++2a -o main main.cpp -lsensehat-c++ -lpng -li2c -lm -lRTIMULib -lgpiod my_lib/*

pour executer:
./main



commande pour pour le programme de creation de trajet
g++ -o creeTrajet creeTrajet.cpp

pour executer:
./creeTrajet


commande pour pour compiler chaque jeu de teste
remplacer [filename] et [filename.cpp] par le nom et le fichier dans 'Jeux_de_test/'

~~~
g++ -Wall -Wextra -Wduplicated-cond -Wduplicated-branches -Wsign-conversion -Wlogical-op -Wuseless-cast -Werror -pedantic -std=gnu++2a -o [filename] Jeux_de_test/[filename.cpp] -lsensehat-c++ -lpng -li2c -lm -lRTIMULib -lgpiod my_lib/*
~~~

exemple:
g++ -Wall -Wextra -Wduplicated-cond -Wduplicated-branches -Wsign-conversion -Wlogical-op -Wuseless-cast -Werror -pedantic -std=gnu++2a -o testAvance_compose Jeux_de_test/testAvance_compose.cpp -lsensehat-c++ -lpng -li2c -lm -lRTIMULib -lgpiod my_lib/*

pour executer ./[filename]

exemple:
./testAvance_compose



CC = gcc
# Définit le compilateur à utiliser (GCC).

CFLAGS = -Wall -Wextra -Werror -Iinclude
# Options de compilation :
# - -Wall, -Wextra, -Werror : Activent divers avertissements lors de la compilation.
# - -Iinclude : Indique à GCC d'inclure le répertoire 'include' pour les fichiers d'en-tête.

SRCS = src/main.c src/deci_to_bin.c 
# Liste des fichiers sources du projet.

OBJS = $(addprefix obj/,$(notdir $(SRCS:.c=.o)))
# Liste des fichiers objets à créer :
# - $(SRCS:.c=.o) : Remplace l'extension .c par .o pour chaque fichier source.
# - $(notdir ...) : Récupère uniquement les noms de fichiers (sans chemin).
# - $(addprefix obj/,...) : Ajoute le préfixe 'obj/' à chaque nom de fichier objet.

TARGET = deci_to_bin
# Nom de l'exécutable à générer.

$(TARGET): obj $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
# Règle de construction de l'exécutable 'bsq' :
# - 'obj' : Dépendance pour s'assurer que le répertoire 'obj' existe.
# - $(OBJS) : Dépendance des fichiers objets.
# - Compile les fichiers objets pour créer l'exécutable 'deci_to_bin'.

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
# Règle de compilation des fichiers objets :
# - Pour chaque fichier source .c dans $(SRCS), compile le fichier correspondant en un fichier objet .o dans le répertoire 'obj'.

obj:
	mkdir -p obj
# Règle pour créer le répertoire 'obj' s'il n'existe pas.

all: $(TARGET)
# Règle par défaut pour construire l'exécutable spécifié par $(TARGET).

clean:
	rm -f $(OBJS)
# Règle pour supprimer les fichiers objets.

fclean: clean
	rm -f $(TARGET)
# Règle pour supprimer l'exécutable en plus des fichiers objets.

re: fclean all
# Règle pour reconstruire complètement le projet en supprimant d'abord tous les fichiers générés précédemment.

.PHONY: clean fclean re all obj
# Déclare les cibles 'clean', 'fclean', 're', 'all' et 'obj' comme étant des cibles phony, 
# c'est-à-dire qu'elles ne correspondent pas à des fichiers réels et doivent toujours être exécutées.

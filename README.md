# Exercice 1 : Liste chaînée personnalisée

Figure 1 : Compilation et exécution de la liste chaînée
<img width="1920" height="628" alt="image" src="https://github.com/user-attachments/assets/f328667b-6b7d-42e5-9f9e-e6b7db6b5661" />

Dans cet exercice, nous avons développé une liste chaînée personnalisée composée de deux classes : Noeud et ListeChainee. Chaque nœud contient une valeur entière et un pointeur vers le nœud suivant. La classe ListeChainee permet d'ajouter des éléments au début ou à la fin de la liste, de supprimer une valeur et d'afficher son contenu. Nous avons également implémenté la méthode taille() pour connaître le nombre d'éléments présents. Le destructeur libère automatiquement la mémoire occupée par les nœuds. Enfin, un itérateur personnalisé permet de parcourir les éléments de la liste.

# Exercice 2 : Gestion d’une file d’attente (Queue) orientée objet

Figure 2 : Compilation et exécution de la file
<img width="1920" height="946" alt="image" src="https://github.com/user-attachments/assets/efe7477a-a9ab-472c-9608-14c43f2c89f5" />
<img width="1920" height="942" alt="image" src="https://github.com/user-attachments/assets/245b70e9-3f8e-4176-90ff-d404c198d62e" />
<img width="1920" height="954" alt="image" src="https://github.com/user-attachments/assets/d9a6960c-79b1-4f13-91ec-42bf40845ba5" />
<img width="1920" height="942" alt="image" src="https://github.com/user-attachments/assets/ebf52ffd-9e0d-45fd-93d7-cf419f90ef2e" />

Cet exercice consiste à implémenter une structure de données de type file en utilisant une liste chaînée dynamique. La classe File respecte le principe FIFO (First In, First Out), selon lequel le premier élément ajouté est le premier à être retiré. Nous avons développé les méthodes enfiler() et defiler() pour gérer respectivement l'ajout et le retrait des éléments. Les méthodes estVide() et estPleine() permettent de vérifier l'état de la file. Un menu interactif permet à l'utilisateur de réaliser ces opérations et de consulter le contenu de la file. Des exceptions sont utilisées pour gérer les tentatives de retrait lorsque la file est vide ou d'ajout lorsqu'elle atteint sa capacité maximale.

# Exercice 3 : Table de hachage simple
Figure 3 : Compilation et exécution de la table de hachage
<img width="1920" height="946" alt="image" src="https://github.com/user-attachments/assets/070aec85-3557-47cd-9395-c72385ac8a98" />
<img width="1920" height="933" alt="image" src="https://github.com/user-attachments/assets/4e7dd1db-c1be-47aa-9243-f26c4747ec55" />

Dans cet exercice, nous avons créé une table de hachage permettant d'associer une clé entière à une chaîne de caractères. La classe TableHachage utilise une fonction de hachage basée sur le reste de la division de la clé par la taille de la table. Pour gérer les collisions, nous avons choisi la méthode du chaînage, qui consiste à stocker plusieurs éléments dans une même case à l'aide de listes chaînées. Les méthodes inserer(), rechercher() et supprimer() permettent respectivement d'ajouter, de retrouver et de retirer une association. La méthode afficher() présente le contenu de chaque case et permet d'observer les collisions. Le destructeur libère les éléments alloués dynamiquement.

# Exercice 4 : Pile générique avec template

Figure 4 : Compilation et exécution de la pile générique
<img width="1920" height="728" alt="image" src="https://github.com/user-attachments/assets/b29f64a5-7297-4809-8f4e-41934feaeb59" />

Dans cet exercice, nous avons développé une classe générique Pile<T> à l'aide des templates C++. Cette approche permet d'utiliser la même structure avec différents types de données, notamment les entiers, les chaînes de caractères et les nombres décimaux. La classe propose les méthodes empiler(), depiler(), sommet() et estVide() pour gérer les opérations principales d'une pile, qui suit le principe LIFO (Last In, First Out). Nous avons également ajouté la méthode inverser() pour modifier l'ordre des éléments. Une exception personnalisée PileVideException permet de gérer correctement les opérations effectuées sur une pile vide. Les tests réalisés vérifient le fonctionnement des différentes opérations et la réutilisation de la classe avec plusieurs types.

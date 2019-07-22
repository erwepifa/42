Bonsoir THEO,

Trie par ordre ASCII = OK ca marche mais verifie quand meme

Tout est en norme sauf quelques petit truc faut que tu check

./ft_ls -s segfault

./ft_ls -d marche pas sur deux dossier genre ./ft_ls -d libft/ list/

dans ft_ls -l j'ai changer la ligne 70
`ft_printf(" %s %2s %.5s ", result[0], result[1], result[2]);`
pour inverser le jour et le mois check si cest ok bg
il faudra tu rajoutes des espaces look bien

juste gerer les erreurs

genre dire que le dossier est inaccessible pour tester creer un dossier
tu lui chmod - tout les droits et tu fais ls dossier
ca va te montrer l'erreur et tu fais appel a st_mode :petit:

et faut gerer le cas comme quoi si t'ecrit ./ft_ls -- taputedemere -a

faut que ca affiche comme le vrai ls juste inverser l'erreur

./ft_ls -1 faut enlever le \n de fin

ET VOILA ON AURA FINIS LS FDP

En esperant que mon README TES FAIS PLAISIR

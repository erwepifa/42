# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    save.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/05 14:58:00 by erwepifa          #+#    #+#              #
#    Updated: 2019/07/05 15:04:56 by erwepifa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

message="Auto commit $(date)"

git add .
git status
git commit -m "$message"
git push origin master

#rm -rf $path

printf '\n\e[32mAll done!\n'


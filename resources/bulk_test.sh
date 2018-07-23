# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    bulk_test.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 17:37:41 by zbatik            #+#    #+#              #
#    Updated: 2018/07/23 18:24:05 by zbatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

play_filler () {
	echo PLAYING\ AS\ P$1\ AGAINSTS\ $3\ ON\ MAP\ $4 >> result.log
	for count in {1..5}
	do
		./filler_vm -p$1 ./zbatik.filler -p$2 ./players/$3.filler -f ./maps/map0$4
		cat filler.trace | sed -n '2p' >> result.log
	done
}

rm result.log
touch result.log

players='carli grati champely hcao superjeannot abanlin'

for player in $players
do
	play_filler 1 2 $player 0
	play_filler 2 1 $player 0
done

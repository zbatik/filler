# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    bulk_test.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 17:37:41 by zbatik            #+#    #+#              #
#    Updated: 2018/07/30 11:18:06 by zbatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

play_filler () {
	echo PLAYING\ AS\ P$1\ AGAINSTS\ $3\ ON\ MAP\ $4 >> result.log
	wins=0
	for count in {1..5}
	do
		./filler_vm -p$1 ./zbatik.filler -p$2 ./players/$3.filler -q -f ./maps/map0$4
		winner=$(sed -n '2p' filler.trace)
		echo $winner >> result.log
		if [ "$winner" == "./zbatik.filler won" ]; then
			wins=$(echo $wins + 1 | bc)
		fi
		if [ $wins == 3 ]; then
			break
		fi
	done
}

rm result.log
touch result.log

players='champely abanlin hcao grati carli superjeannot'

for	map in {0..2}
do
	play_filler 1 2 champely $map
	play_filler 2 1 abanlin $map
	play_filler 2 1 hcao $map
	play_filler 2 1 grati $map
	play_filler 1 2 carli $map
	play_filler 1 2 superjeannot $map
done

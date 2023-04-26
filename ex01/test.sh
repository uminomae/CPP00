#!/bin/bash

#=======================================================
#定数 color
#=======================================================
ESC=$(printf '\033') 
GREEN=$(printf '[32m')
PINK=$(printf '[38;5;199m')
#=======================================================
#test pdf case
#=======================================================
timeout=10
cmd='./PhoneBook'
first="\${i}pre_cure"
last="12345678-\${i}"
nickname="12345678901234567890123456789"
phone="\${i}-012-345-678"
secret="secret\$i"
max_r=10

expect -c "
	set timeout ${timeout}
	spawn ${cmd}

	set i 0
	while {\$i < $max_r} {
		expect \"CMD\"
		send \"ADD\n\"
		send \"${first}\n\"
		send \"${last}\n\"
		send \"${nickname}\n\"
		send \"${phone}\n\"
		send \"${secret}\n\"
		incr i 1
	}

	expect \"CMD\"
	send \"SEARCH\n\"
	expect \"|\"
	send \"0\n\"

	expect \"CMD\"
	send \"SEARCH\n\"
	expect \"|\"
	send \"10\n\"

	# expect \"CMD\"
	send \"EXIT\n\"
	expect \"CMD\"
	exit 0
"
#=======================================================

expect -c "
	set timeout ${timeout}
	spawn ${cmd}

	set i 0
	while {\$i < $max_r} {
		expect \"CMD\"
		send \"ADD\n\"
		send \"${first}\n\"
		send \"${last}\n\"
		send \"${nickname}\n\"
		send \"${phone}\n\"
		send \"${secret}\n\"
		incr i 1
	}


	expect \"CMD\"
	send \"SEARCH\n\"
	expect \"|\"
	send \"0\n\"

	expect \"CMD\"
	send \"SEARCH\n\"
	expect \"|\"
	send \"1\n\"

	expect \"CMD\"
	send \"SEARCH\n\"
	expect \"|\"
	send \"abc\n\"

	expect \"CMD\"
	send \"EXIT\n\"
	expect \"CMD\"
	exit 0
"
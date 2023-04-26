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

#=======================================================


expect -c "
	set timeout ${timeout}
	spawn ${cmd}

	set i 0
	while {\$i < $max_r} {
		expect \"Please enter command\"
		send \"ADD\n\"
		expect \"name\"
		send \"${first}\n\"
		expect \"name\"
		send \"${last}\n\"
		expect \"name\"
		send \"${nickname}\n\"
		expect \"num\"
		send \"${phone}\n\"
		expect \"sec\"
		send \"${secret}\n\"
		incr i 1
	}

	expect \"Please enter command\"
	send \"SEARCH\n\"
	expect \"Please\"
	send \"a\n\"
	
	expect \"Please\"
	send \"13\n\"

	expect \"Please\"
	send \"0\n\"

	expect \"Please enter command\"
	send \"SEARCH\n\"
	expect \"Please\"
	send \"6\n\"

	expect \"Please enter command\"
	send \"SEARCh\n\"

	expect \"Please enter command\"
	send \"\n\"
	send \"a\n\"

	expect \"Please\"
	send \"EXIT\n\"
	expect \"Please\"
	exit 0
"
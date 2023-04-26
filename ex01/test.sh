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

# expect -c "
# 	set timeout ${timeout}
# 	spawn ${cmd}

# 	set i 0
# 	while {\$i < $max_r} {
# 		expect \"Please enter command\"
# 		send \"ADD\n\"
# 		send \"${first}\n\"
# 		send \"${last}\n\"
# 		send \"${nickname}\n\"
# 		send \"${phone}\n\"
# 		send \"${secret}\n\"
# 		incr i 1
# 	}

# 	expect \"Please enter command\"
# 	send \"SEARCH\n\"
# 	expect \"|\"
# 	send \"0\n\"

# 	expect \"Please enter command\"
# 	send \"SEARCH\n\"
# 	expect \"|\"
# 	send \"10\n\"

# 	# expect \"Please enter command\"
# 	send \"EXIT\n\"
# 	expect \"Please enter command\"
# 	exit 0
# "
# #=======================================================

# expect -c "
# 	set timeout ${timeout}
# 	spawn ${cmd}

# 	set i 0
# 	while {\$i < $max_r} {
# 		expect \"Please enter command\"
# 		send \"ADD\n\"
# 		send \"${first}\n\"
# 		send \"${last}\n\"
# 		send \"${nickname}\n\"
# 		send \"${phone}\n\"
# 		send \"${secret}\n\"
# 		incr i 1
# 	}


# 	expect \"Please enter command\"
# 	send \"SEARCH\n\"
# 	expect \"|\"
# 	send \"0\n\"

# 	expect \"Please enter command\"
# 	send \"SEARCH\n\"
# 	expect \"|\"
# 	send \"9\n\"

# 	expect \"Please enter command\"
# 	send \"SEARCH\n\"
# 	expect \"|\"
# 	send \"abc\n\"

# 	# expect \"Please enter command\"
# 	send \"EXIT\n\"
# 	expect \"Please enter command\"
# 	exit 0
# "
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
	expect \"|\"
	send \"a\n\"
	
	# expect \"Please enter command\"
	send \"EXIT\n\"
	expect \"Please enter command\"
	exit 0
"
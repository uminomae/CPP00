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
./megaphone \
"shhhhh... I think the students are asleep..." 
./megaphone \
"shhhhh... I think the students are asleep..." \
> out01
diff ./test01 ./out01 \
&& echo "${ESC}${GREEN}"'  OK'"${ESC}[m" || echo  "${ESC}${PINK}"'  NG'"${ESC}[m"
#=======================================================
./megaphone \
Damnit " ! " "Sorry students, I thought this thing was off." 
./megaphone \
Damnit " ! " "Sorry students, I thought this thing was off." \
> out02
diff ./test02 ./out02 \
&& echo "${ESC}${GREEN}"'  OK'"${ESC}[m" || echo  "${ESC}${PINK}"'  NG'"${ESC}[m"
#=======================================================
./megaphone
./megaphone \
> out03
diff ./test03 ./out03 \
&& echo "${ESC}${GREEN}"'  OK'"${ESC}[m" || echo  "${ESC}${PINK}"'  NG'"${ESC}[m"
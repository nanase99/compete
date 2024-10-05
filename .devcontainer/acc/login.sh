username="sgmdq729"
password="mss311112"

expect -c "
spawn acc login
expect \"username:\"
send \"${username}\r\"

expect \"password:\"
send \"${password}\r\"
interact
"

expect -c "
spawn oj login https://beta.atcoder.jp/
expect \"Username:\"
send \"${username}\r\"

expect \"Password:\"
send \"${password}\r\"
interact
"
exit 0
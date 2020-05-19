cd script
chmod +x com.sh
chmod +x reset.sh
./reset.sh
./com.sh
cd -
chmod +x access.sh
gnome-terminal -e "bash -c \"cd server; ./a.out; exit; exec bash\""

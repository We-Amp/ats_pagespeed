sudo rm *.so *.lo
tsxs -o gzip.so -I /home/oschaaf/code/trafficserver/lib/ts/  gzip.cc configuration.cc misc.cc
sudo tsxs -o gzip.so -i


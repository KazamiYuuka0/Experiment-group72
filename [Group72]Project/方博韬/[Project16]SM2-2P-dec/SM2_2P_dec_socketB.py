from SM2_2P_dec import KDF,alice1,bob1,alice2
import socket
h=1#SM2固定参数，表示椭圆曲线群中的所有点都属于主要子群
p=0x8542D69E4C044F18E8B92435BF6FF7DE457283915C45517D722EDB8B08F1DFC3
a=0x787968B4FA32C3FD2417842E73BBFEFF2F3C848B6831D7E0EC65228B3937E498
b=0x63E4C6D3B23B0C849CF84241484BFE48F61D59A5B16BA06E6E12D1DA27C5249A
xG=0x421DEBD61B62EAB6746434EBC3CC315E32220B3BADD50BDC4C4E6C147FEDD43D
yG=0x0680512BCBB42C07D47349D2153B70C4E5D7FDFCBFA36EA1A85841B9E46E09A2
n=0x8542D69E4C044F18E8B92435BF6FF7DD297720630485628D5AE74EE7C32E79B7

d2=0x84c2f88319c7d6e5dc9094afe891e85acf5197c7d94db720e7af3e6566fc84ab
C=b"\x04\x0e\xbd\x02N\x13\xf6\xbd\xcb~\x8c\x9b\x9b\x14_\xce[\xbdE;H80\xc8\xbd-\x8dVcp\xc1\x8e\xff;\x9c\xf5r\xa3.\x9c\x1d\xef\xe1\x02\xf7\x17\x00\xdaj\x86#W\xa4\xa5p8\xb8\xf4G\x94+\x81\x081\x92b\xb0L\xd4J\xcf\xc5\xc9\xa9\xf7I\xcej\x80\xe8Z\xd3\x9a\xcc5\xb6\r\xa0{\x84\xe63w\xa1\xca7\x8b/\xd2\t\xbd\xa0\x0e\x93e\x80\xbd~'F\xc7N]JI\xcc\x17\xe0Ga\xb3\xbd?\xc4Q\x88\xffy\xa3"


s=socket.socket()
host='127.0.0.1'
port=65535
s.bind((host,port))
s.listen(1)
while True:
    conn,addr=s.accept()
    print('Connected')
    T1=conn.recv(1024)
    T2=bob1(a,p,n,d2,T1)
    conn.sendall(T2)

    conn.close()
    print('Closed')

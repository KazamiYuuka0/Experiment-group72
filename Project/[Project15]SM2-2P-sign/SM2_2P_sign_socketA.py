from SM2_2P_sign import alice1,alice2,alice3
p = 0x8542D69E4C044F18E8B92435BF6FF7DE457283915C45517D722EDB8B08F1DFC3
a = 0x787968B4FA32C3FD2417842E73BBFEFF2F3C848B6831D7E0EC65228B3937E498
b = 0x63E4C6D3B23B0C849CF84241484BFE48F61D59A5B16BA06E6E12D1DA27C5249A
xG = 0x421DEBD61B62EAB6746434EBC3CC315E32220B3BADD50BDC4C4E6C147FEDD43D
yG = 0x0680512BCBB42C07D47349D2153B70C4E5D7FDFCBFA36EA1A85841B9E46E09A2
n = 0x8542D69E4C044F18E8B92435BF6FF7DD297720630485628D5AE74EE7C32E79B7
h = 1
M = 'message digest'
ZA= 'Identity of A&B'
import socket

s=socket.socket()
host='127.0.0.1'
port=65535
s.connect((host,port))

P1,d1=alice1(a,p,n,xG,yG)
s.sendall(P1)

P=s.recv(1024)
textA2B,k1=alice2(a,p,n,xG,yG,ZA,M)
s.sendall(textA2B)

textB2A=s.recv(1024)
r,s=alice3(a,p,n,k1,textB2A,d1)
print('r:',hex(r))
print('s:',hex(s))
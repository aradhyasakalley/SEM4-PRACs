import socket

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

udp_host = socket.gethostname()
udp_port = 12345


msg = "hello"

print("UDP Target host : ",udp_host)
print("UDP Target port : ",udp_port)

sock.sendto(msg.encode('utf-8'),(udp_host,udp_port))

import socket

HOST = "127.0.0.1"
PORT = 1234

with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as server_socket : 
    
    server_socket.bind((HOST,PORT))
    server_socket.listen()
    print('waiting for client..')
    conn,addr = server_socket.accept()

    with conn : 
        print(f'connect to {addr}')
        while True : 
            data = conn.recv(1024)
            if not data : 
                break
            print(f'received message from client: {data.decode()}')
            response = "message was recieved"
            conn.sendall(response.encode())





    
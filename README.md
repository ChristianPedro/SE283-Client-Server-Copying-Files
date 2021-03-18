# SE283-Client-Server-Copying-Files
This repository contains client/server files for transferring flies. The client sends a file name; and the server reads the file name and sends back the contents of the file. 

## Make 
To easily run this program you can use the make file to compile the server and client files. 
```
make all 
```

## Calling Sever and Client programs.
The server program takes a port.

```
./server <port>
```

The client program takes a host, port and filename.

```
./client <host> <port> <filename>
```

## Sample server calls.
```
./server 8080
```


## Sample client calls:

The server needs to started first, however this will read the test.txt file that is provided. 

```
./client localhost 8080 test.txt 
```



This will reach out to my personal website and will return the index.html file printed to the commandline. The program will hang since the connection is told to persist by CloudFlare.

```
./client www.christianpedro.dev 80 index.html
```
```
./client www.google.com 80 index.html
```


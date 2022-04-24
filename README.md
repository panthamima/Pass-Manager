![Awestruck Logotype](https://github.com/panthamima/Pass-Manager/raw/master/img/logotype.png)

Awestruck is a simple project that is a password manager. <br>Uses txt files to store passwords. The project uses the SHA256 and AES128-256 for hash master password and encrypt entries.

## Features
-  upgrade cipher
-  refactoring
-  add online database
-  add  cli / gui

## Quick Start Linux
before compiling, you need to install the following dependencies: <br>
`sudo apt-get update && apt-get upgrade` <br>
`sudo apt install -y libx11-dev libuv1-dev libsodium-dev`
```
git clone https://panthamima/Pass-Manager.git && cd Pass-Manager/core
```
```
make build
```
`./awe.out init`

## Awestruck file structure
```sh
pass-man/
├── core
│   ├── crypt
│   │   ├── rijndael.c
│   │   ├── rijndael.h
│   │   ├── sha256.c
│   │   └── sha256.h
│   ├── include
│   │   ├── clipboard.h
│   │   ├── defs.h
│   │   ├── dir_handle.h
│   │   ├── entries_handle.h
│   │   ├── global.h
│   │   ├── pass_handle.h
│   │   ├── tools.h
│   │   └── validation.h
│   ├── main.c
│   ├── Makefile
│   └── src
│       ├── clipboard.c
│       ├── dir_handle.c
│       ├── entries_handle.c
│       ├── global.c
│       ├── pass_handle.c
│       ├── tools.c
│       └── validation.c
├── img
│   └── logo.png
├── README.md
└── templates
    ├── help.c
    └── test.c
``` 

## Contributors
- panthamima (https://github.com/panthamima)
- equitans (https://github.com/equitans)

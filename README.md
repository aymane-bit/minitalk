# Minitalk

Minitalk is a 42 project designed to explore inter-process communication (IPC) in Unix systems. The project implements a simple client-server system where messages are transmitted using **signals** (`SIGUSR1` and `SIGUSR2`).

## Features

- Send and receive messages between client and server using Unix signals.
- Support for ASCII and Unicode characters.
- Robust error handling for invalid process IDs or interrupted signals.
- Bonus: Concurrent message handling for long messages or multiple clients.

## Table of Contents

- [Overview](#overview)
- [How It Works](#how-it-works)
- [Installation](#installation)
- [Usage](#usage)
- [Bonus Features](#bonus-features)
- [Examples](#examples)
  
## Overview

Minitalk consists of two main components:
- **Server**: Listens for signals, decodes the binary data, and reconstructs the message.
- **Client**: Encodes the message into signals and sends them to the server.

This project demonstrates the basics of signal handling, process communication, and the use of low-level system calls.

## How It Works

1. The client encodes a message into binary format.
2. Each bit of the message is sent as a signal to the server:
   - `SIGUSR1` for a binary `0`.
   - `SIGUSR2` for a binary `1`.
3. The server receives the signals and reconstructs the message bit by bit.
4. The server displays the complete message on the terminal.

### Bonus

- The server acknowledges every message received by sending back a signal to the client.
- Unicode characters support!

## Installation

Clone the repository and compile the project using the provided `Makefile`:

```bash
git clone https://github.com/yourusername/minitalk.git
cd minitalk
make
```

This will generate the `client` and `server` executables.

## Usage

1. **Start the Server**  
   Run the server to display its Process ID (PID):
   ```bash
   ./server
   ```

2. **Send a Message**  
   Use the client to send a message to the server:
   ```bash
   ./client [server-pid] "Your message here"
   ```

### Example

- Start the server:
  ```bash
  $ ./server
  Server PID: 12345
  ```

- Send a message using the client:
  ```bash
  $ ./client 12345 "Hello, Minitalk!"
  ```

- Server output:
  ```bash
  Received message: Hello, Minitalk!
  ```

## Bonus Features

- **Unicode Support**: Send messages containing Unicode characters like emojis.  
- **Robustness**: Handles large messages and multiple simultaneous clients.

## Examples

- Sending a Unicode message:
  ```bash
  $ ./client 12345 "Hello, 🌍!"
  ```

- Handling long messages:
  ```bash
  $ ./client 12345 "This is a very long message to demonstrate the robustness of the Minitalk server."
  ```


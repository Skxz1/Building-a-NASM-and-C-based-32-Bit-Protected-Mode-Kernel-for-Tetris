# Building a NASM and C-Based 32-Bit Protected Mode Kernel for Tetris

This project is a custom 32-bit protected mode kernel written in **NASM (x86 Assembly)** and **C**, designed to run a fully-playable game of **Tetris** directly on bare-metal hardware — without an operating system.

The kernel includes:

- A custom **bootloader (MBR)** written in NASM  
- A **Global Descriptor Table (GDT)** and protected-mode switch  
- A custom **Interrupt Descriptor Table (IDT)** and **ISR/IRQ handlers**
- **Keyboard driver** for game input  
- **Graphics written in C using VGA Mode 13h (320×200, 256-colour)**  
- A full **Tetris engine**: movement, rotation, collision, line clearing, and game-over detection  

This project demonstrates how low-level programming can be used to build real, interactive software directly on hardware — making it both a fun retro game experience and an educational kernel-development exercise.

---

## 🎮 Gameplay Controls

| Key | Action |
|-----|--------|
| ⬅️ Left Arrow | Move left |
| ➡️ Right Arrow | Move right |
| ⬆️ Up Arrow | Rotate piece |
| ⬇️ Down Arrow | Soft drop |
| Space | Hard drop |

The game ends when a new tetromino collides on spawn.

---

## 🖥️ Build & Run (macOS)

To run this kernel you will need to install the following tools using **Homebrew**:

### 1️⃣ Install Homebrew
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

### 2️⃣ Install i386 ELF binutils
```bash
brew install i386-elf-binutils
```

### 3️⃣ Install i386 ELF GCC compiler
```bash
brew install i386-elf-gcc
```

### 4️⃣ Install i386 ELF GDB debugger
```bash
brew install i386-elf-gdb
```

### 5️⃣ Install QEMU and NASM
```bash
brew install qemu nasm
```

### 6️⃣ Build and run the kernel
```bash
make run
```

This will compile the bootloader and kernel, then launch the OS in **QEMU**.

---

## 🧠 What This Project Covers

This kernel explores:

- Bootloader & MBR design  
- Memory segmentation with **GDT**
- Switching the CPU to **32-bit protected mode**
- **Interrupt handling & PIC remapping**
- **Bare-metal VGA graphics**
- **Keyboard input drivers**
- **Game-engine logic inside a kernel**
- Debugging low-level systems

It’s ideal for anyone interested in:

✔ operating systems  
✔ systems programming  
✔ assembly language  
✔ retro gaming  
✔ hardware-level computing  

---

## 📘 Full NEA Documentation

The full coursework report explaining analysis, design, implementation, testing and evaluation is included here:

📄 **32-bit Kernel Document.pdf**

---

## 🙌 Author

**Sam Kierdelewicz**  
Computer Science NEA Project

---

## ⚠️ Disclaimer

This project runs at a very low level and interacts closely with hardware-like environments.  
Always run it in a virtual machine such as **QEMU** — do **not** run directly on real hardware.

---

Enjoy exploring low-level programming and building games from scratch 🙂

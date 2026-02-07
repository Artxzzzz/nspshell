<p align="center">
  <img width="445" height="134" alt="NSPSh logo" src="https://github.com/user-attachments/assets/e0fbb677-8cb6-49e4-8b1c-5bedb96a6d7a" />
</p>

<br><br>

<p align="center">
  <img src="https://img.shields.io/badge/language-C-blue" alt="C">
  <a href="LICENSE">
    <img src="https://img.shields.io/github/license/Artxzzzz/nspshell" alt="License">
  </a>
  <img src="https://img.shields.io/github/stars/Artxzzzz/nspshell" alt="GitHub stars">
  <img src="https://img.shields.io/github/v/release/Artxzzzz/nspshell" alt="Latest release">
</p>

<br><br>

# NSPShell

## ⚠️ Warning

*External commands will only work if you add them to the user's or system **PATH**.*

## 📝 Description

**NSPShell** is a **C** program that does amazing things quickly and efficiently.

## ⚙️ Requirements

* **GCC** or **Clang**
* Operating System: **Windows**

  <br>

## 💻 How to compile

```bash
# Clone the repository
git clone https://github.com/Artxzzzz/nspshell.git
cd NSPShell
```

<br>

```bash
# Compile with GCC
gcc main.c -o nspsh
```

Or

```bash
# Using Git Bash or MINGW
make
```

<br>

## ▶️ How to run

```bash
# After compiling, run with
./nspsh.exe

# Or
make run
```

<br>

## ✍️ How to contribute

* Fork or clone the repository:

  ```bash
  git clone https://github.com/Artxzzzz/nspshell.git
  ```
* Create a branch for your changes:

  ```bash
  git checkout -b my-feature
  ```
* Make your changes, commit, and push:

  ```bash
  git add .
  git commit -m "description of your changes"
  git push origin my-feature
  ```

- Now just open a **Pull Request**.

<br><br>

## 📂 Project structure

#### 📂 NSPShell/

* `src/`

  * `main.c`
  * `builtin/`        - Internal commands: `cd`, `exit`, `help`, `pwd`
  * `exec/`           - Command execution
  * `helpers/`        - Helper functions
  * `packages/`       - Settings and utilities
  * `welcome/`        - Welcome messages
* `externals/`         - External programs used (`ls`, `clear`, `color`)
* `Makefile`           - Automates compilation
* `LICENSE`
* `README.md`

<br>

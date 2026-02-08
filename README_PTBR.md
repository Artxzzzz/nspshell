<p align="center">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://github.com/user-attachments/assets/e0fbb677-8cb6-49e4-8b1c-5bedb96a6d7a">
    <source media="(prefers-color-scheme: light)" srcset="https://github.com/user-attachments/assets/e1a33172-506a-4a4f-914d-3076500ea5a6">
    <img width="445" height="134" alt="NSPSh logo" src="https://github.com/user-attachments/assets/e1a33172-506a-4a4f-914d-3076500ea5a6" />
  </picture>
</p>
<br><br>

<p align="center">
  <img src="https://img.shields.io/badge/language-C-blue" alt="C">
  <a href="LICENSE">
    <img src="https://img.shields.io/github/license/Artxzzzz/nspshell?cacheSeconds=300" alt="License">
  </a>
  <img src="https://img.shields.io/github/stars/Artxzzzz/nspshell?cacheSeconds=300" alt="GitHub stars">
  <a href="https://github.com/Artxzzzz/nspshell/releases/latest">
    <img src="https://img.shields.io/github/v/release/Artxzzzz/nspshell?cacheSeconds=300" alt="Latest release">
  </a>
</p>

<br><br> 

# NSPShell

## ⚠️ Aviso
  _Comandos externos apenas funcionarão se você os adicioná-los na **PATH** do usuário ou sistema._

## 📝 Descrição
 **NSPShell** é um shell feito em **C**, inspirado em shells **UNIX-like**, desenvolvido para estudo e uso em ambiente **Windows**. Possui comandos internos e suporte à execução de programas externos via **PATH**.

🌐 [Read this README in English](README.md)


## ⚙️ Requisitos
- **GCC** ou **Clang**
- Sistema operacional: **Windows**
<br>

## 💻 Como compilar
```bash
# Clonar o repositório
git clone https://github.com/Artxzzzz/nspshell.git
cd NSPShell
```
<br>

``` bash
# Compilar com GCC
gcc main.c -o nspsh
```

Ou

``` bash 
# No git bash ou MINGW
make
```
<br>

## ▶️ Como executar
```bash
# Depois de compilar, execute com
./nspsh.exe

# Ou
make run
```

<br>

## ✍️ Como contribuir

 - Faça um fork ou clone o repositório:
	``` bash
	git clone https://github.com/Artxzzzz/nspshell.git
	```
 - Crie uma branch para suas alterações:
	``` bash
	git checkout -b minha-feature
	```
 
 - Faça suas alterações, commit e push:	
	``` bash
	git add .
	git commit -m "descrição do que fez"
	git push origin minha-feature
	```
* Agora é só abrir uma **Pull Request**

<br><br>

## 📂 Estrutura do projeto


#### 📂 NSPShell/

* `src/`
  * `main.c`
  * `builtin/`        - Comandos internos: `cd`, `exit`, `help`, `pwd`
  * `exec/`           - Execução de comandos
  * `helpers/`        - Funções auxiliares
  * `packages/`       - Configurações e utilitários
  * `welcome/`        - Mensagens de boas-vindas
* `externals/`         - Programas externos usados (`ls`, `clear`, `color`)
* `Makefile`           - Automatiza compilação
* `LICENSE`
* `README.md`

<br>
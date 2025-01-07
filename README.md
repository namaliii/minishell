# **Minishell**

## **Project Overview**

Minishell is a simplified version of a Unix shell, developed as part of the 42 School curriculum to deepen our understanding of **Parsing**, **process management**, **system calls**, **file descriptors**, and **signal handling** in a Unix-like environment. This shell replicates core functionalities of bash, supporting **commands**, **piping**, **redirections**, **environment variables**, and a few **built-in** commands.



### **Key Features**
1. **CRUD Operations:** Create, Read, Update, and Delete tasks.  
2. **Database Integration:** Store task data using **PostgreSQL**.  
3. **Containerization:** Use **Docker** and **Docker Compose** for simplified deployment.  
4. **Scalability:** Deploy and scale the application with **Kubernetes**.  

---

## Technologies Used

- **Programming Language:** C  
- **System Calls:** fork, execve, waitpid, pipe, dup2, signal ...
- **Makefile:** for build automation  
- **Valgrind** (Memory Leak Checker during development)
- **Docker** To test it on different systems
---

## Key Features
- **Command Execution:** Supports both built-in and external commands.
- **Piping:** Ability to chain commands using pipes (|).
- **Redirections:** Input (<) and output (> and >>) redirection support and heredoc (<<).
- **Environment Variables:** Access and modify environment variables.
- **Signal Handling:** Proper handling of Ctrl+C, Ctrl+D, and Ctrl+\.
- **Built-in Commands:** Implemented commands such as: 


  - echo
  - cd
  - pwd
  - export
  - unset
  - env
  - exit
- **Error Handling:** Informative error messages for invalid syntax or commands.

##  **Setup Instructions **

###  1. Clone the Repository and compile the project using Makefike


```bash

git clone git@github.com:Mimadfaoussi/minishell
cd minishell
make
```

Run the shell:
```bash
./minishell
```


### Usage Examples

***Basic Commands:***

```bash
ls -la
echo "Hello, World!"
pwd
```

***Piping Commands:***

```bash
ls | grep minishell
cat file.txt | wc -l
```

***Redirections:***

```bash
echo "Test" > output.txt
cat < input.txt
```

***Environment Variables:***

```bash
export MY_VAR="Hello"
echo $MY_VAR
unset MY_VAR
```

***Built-in Commands:***

```bash
cd ..
pwd
env | grep PATH > path.txt
exit
```


***Signal Handling:***

- **Ctrl+C →** Stops the current process.
- **Ctrl+D →** Exits the shell.
- **Ctrl+\ →** Does nothing if properly handled.



**Authors:**
- imad faoussi : https://github.com/Mimadfaoussi
- Alicja Namięta : https://github.com/namaliii
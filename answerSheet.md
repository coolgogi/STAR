### (1) Read and write a file as binary (not as text)

+ __fread()__ : <http://www.cplusplus.com/reference/cstdio/fread/>  
+ __fwrite()__ : <http://www.cplusplus.com/reference/cstdio/fwrite/>  
+ What's the other file interfaces that read and write a file as text?
```C
char * fgetc (FILE *stream);
int fputc (int c, FILE *stream);
char * fgets (char *restrict s, int size, FILE *restrict stream);
int fputs (const char *restrict s, FILE *restrict stream);
int fscanf (FILE *restrict stream, const char *restrict format, ...);
```

+ How accessing a file as binary is defferent from accessing it as text?  
```markdown
Accessing a file as binary reads data from file per bytes.
But accessing a file as text reads data from file per characters or strings.
```
+ Write a program that shows each byte of a given file as a hexadecimal number (like xxd does)  
```C
size_t
read_file (FILE * file) {

    

    do {
        


    }
    while () ;
}
```

### (2) Accessing a directory
+ Opening a directory  <https://www.gnu.org/software/libc/manual/html_node/Opening-a-Directory.html>
+ Reading a directroy  <https://www.gnu.org/software/libc/manual/html_node/Reading_002fClosing-Directory.html>  
+ Simple directory lister  <https://www.gnu.org/software/libc/manual/html_node/Simple-Directory-Lister.html>  
+ What is the _path_ of a file? How it is different from the _name_ of a file?  
```markdown

```
+ Write a program that enumerates the paths of all files under a given directory and its subdirectories recursively.  
```markdown

```
+ Write a program that copies the entire files and the directory structure of a given path to another specified path.  
```markdown

```
### (3) Retrieving file attributes  
+ Stat system call  <https://linuxhint.com/stat-system-call-linux/>    

+ What is a regular file? How one can check if a file is a regular file or not?    
```markdown

```
+ How one can find the size of a file?    
```markdown

```
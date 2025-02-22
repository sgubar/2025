# Homework №1  
## Variant №5  

### Task  
Create a mathematical functions module: `dk_tool.h` (.c).  

In `main.c`, organize input/output of parameters—console input/output is not mandatory.  

Avoid code duplication—if there are repeating code segments, they should be moved to separate functions, such as:  
- Printing an array to the console  
- Filling a matrix/array  
- Inputting data from the terminal with validation, etc.  

Find the transposed matrix.  

### Compilation & Run  
```sh
gcc HW1/main.c HW1/dk_tool.c -o HW1/program && HW1/program
```

### Project Structure  
```
/HW1
│── main.c        # Main program logic
│── dk_tool.h     # Header file with function prototypes
│── dk_tool.c     # Function implementations
│── README.md     # Project documentation
```

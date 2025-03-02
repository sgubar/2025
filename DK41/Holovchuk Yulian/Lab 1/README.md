# Laboratory Work #1  
## Variant #5  

### Task  
Implement a mathematical functions module: `MathFX.h` and `MathFX.c`.  

In `main.c`, organize user input and output with validation. The program should prevent incorrect input and handle errors such as division by zero.  

The expression to compute:  

\[ Q \leftarrow \frac{A^2 + B^2}{B + 5^C} + B! \]  

where the input values are `A`, `B`, and `C`.

### Requirements  
- Implement a separate module for calculations including:  
  - Exponentiation (`power`)  
  - Factorial (`factorial`)  
- Provide user interaction with input validation:  
  - Prompt the user for `A`, `B`, and `C`  
  - Ensure correct data format (e.g., integers for factorial calculations)  
  - Handle errors such as division by zero  


### Project Structure  
```
/LAB1  
│── main.c        # Main program logic  
│── MathFX.h      # Header file with function prototypes  
│── MathFX.c      # Function implementations  
│── README.md     # Project documentation  
│── .vscode/      # VS Code configuration files  
```  

### Example Usage  
```
The code is designed to calculate Q using the formula: Q = (A^2 + B^2) / (B + 5^C) + B!
Enter rational number A: 3.5  
Enter rational number B: 2.0  
Enter integer number C: 2  
Q = 10.25  
Press any key to continue . . .  
```  


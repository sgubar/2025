# Laboratory Work #2  
## Variant #5  

### Task  
Implement a program that processes a sequence of numbers using a linked list. The program should:  
1. Calculate the arithmetic mean of the sequence elements.  
2. Remove the first element that is smaller than the calculated mean.  

### Requirements  
- Use a singly linked list structure with the following functionalities:  
  - Adding elements to the list (`append`)  
  - Calculating the arithmetic mean (`calculateAverage`)  
  - Removing the first element below the average (`removeFirstBelowAverage`)  
  - Printing the list (`printList`)  
  - Freeing allocated memory (`freeList`)  
- Ensure correct memory management to prevent leaks.  

### Project Structure  
```
/LAB2
│── main.c        # Main program logic  
│── my_list.h     # Header file with function prototypes  
│── my_list.c     # Function implementations  
│── README.md     # Project documentation  
│── .vscode/      # VS Code configuration files  
```  

### Example Usage  
```
Enter integer number for the list (type 's' to stop input):
Enter a number: 1
Enter a number: 1
Enter a number: -3
Enter a number: 12
Enter a number: 2
Enter a number: s
List: 1 -3 12 2
Average: 3.00
Removed first element below average: 1
List: -3 12 2  
```  

### Memory Management  
- Every allocated node must be freed using `freeList(head)` at the end of the program to avoid memory leaks.  
- Ensure correct handling of an empty list scenario.



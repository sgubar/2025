# Laboratory Work #3  
## Variant #5  

### Task  
Implement a binary search tree that stores elements of type `float`. The program must support the following operations:

- Tree creation and deletion  
- Insertion of a new element  
- Deletion of an existing element  
- Searching for an element  
- Tree traversal (pre-order)

All operations should be accessible via a user-friendly text menu.  
Each input must include a prompt and validation (e.g., correct number format, protection from invalid input).  

### Requirements  
- Data structure: binary search tree with `float` values  
- Use pre-order traversal for printing the tree  
- Implement input validation and error messages:
  - Prevent entry of invalid types (e.g., letters instead of numbers)
  - Handle operations on an empty tree
- Allow continuous interaction with the tree via a menu loop  

### Project Structure  
/LAB2
│── main.c # Main program logic with menu and validation
│── README.md # Project documentation
│── .vscode/ # VS Code configuration (optional)

shell
Copy
Edit

### Example Usage  
========== Binary Tree ==========

Insert element

Delete element

Search element

Print tree (pre-order)

Delete entire tree

Exit
Choose option: 1
Enter a number to insert (e.g., 3.14): 4.5
Inserted 4.50 into the tree.

Choose option: 4
Tree (pre-order): 4.50

Choose option: 3
Enter a number to search: 4.5
Element 4.50 was found in the tree.

Choose option: 0
Exiting program. Goodbye!

Copy
Edit


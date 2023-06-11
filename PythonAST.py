# Define a class named Node
class Node:
    # Constructor to initialize the node
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

# Function to print the AST
def print_ast(node, level=0):
    # Create a prefix string to indent the node based on the level of recursion
    prefix = '    ' * level
    # Print the value of the current node with appropriate indentation
    print(f'{prefix} {node.value}')
    # Check if the node has a left child
    if node.left:
        # Print a forward slash and a backward slash with appropriate indentation
        print(f'{prefix} / \\')
        # Recursively call the function with the left child node and increment the level by 1
        print_ast(node.left, level + 1)
    # Check if the node has a right child
    if node.right:
        # Print a backward slash and a forward slash with appropriate indentation
        print(f'{prefix} \\ /')
        # Recursively call the function with the right child node and increment the level by 1
        print_ast(node.right, level + 1)

#Create a root node with a value of '=' and left and right child nodes
root = Node('=', Node('z'), Node('+', Node('x'), Node('y')))
#Call the function to print the AST starting from the root node
print_ast(root) # prints the AST
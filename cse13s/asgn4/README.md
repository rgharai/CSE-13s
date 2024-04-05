# The assignment

<p> Is creating these files which implement a graph, stack, and path in order to use dfs to find the most optimal path based on a user defined input graph by optimal path its a hamiltonian path so it has to reach every single vertex once
<p>

# the program

<p>
stack.c:- to perform all of the logic needed by the path data structure. It is used to hold all of the vertices.

path.c :- to perform all of the logic to track the current path or shortest path.

graph.c :-to perform all of the logic needed to track the edges and vertices for a graph.

tsp.c :- to handle all of the input and output logic as well as the Depth First Search(DFS) recursive function to calculate all possible hamiltonian paths.

• -h : Prints out a help message describing the purpose of the graph and the command-line options it accepts, exiting the program afterwards. Refer to the reference program in the resources repo for an idea of what to print. 
 
• -v : Enables verbose printing. If enabled, the program prints out all Hamiltonian paths found as well as the total number of recursive calls to dfs(). 
 
• -u : Specifies the graph to be undirected.
 
 • -i infile : Specify the input file path containing the cities and edges of a graph. If not specified, the default input should be set as stdin
 
. • -o outfile : Specify the output file path to print to. If not specified, the default output should be set as stdout.

<p>

# how to run program

<p>Enter "make clean" in the terminal

Enter "make format" in the terminal

 Enter "make" in the terminal

Enter "./tsp -[INSERT COMMANDs HERE]". To insert an input file for the program to read user must type " < [insert input file here]" or "-i [insert input file here]" and if the user wishes to use an output file other than stdout they must type "-o [insert input file here]"
<p>

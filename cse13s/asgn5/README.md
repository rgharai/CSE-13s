# The purpose of the program
<p> The purpose of this assignment is to make a Huffman encoder and a  Huffman decoder. This encoder will read in an input file, find the Huffman encoding of its contents, and use the encoding to compress the file. This decoder will read in a compressed input file and decompress it, expanding it back to its original, uncompressed size. There are multiple files that will help to implement these tasks of the encoder and the decoder.
<p>

# Makefile
<p> 1) Make clean
    2) Make format
    3)Enter "make" in the terminal
    4)Enter "./encode" -[INSERT COMMANDs HERE]". 
    To insert an input file for the program to read user must type " < [insert input file here]" or "-i [insert input file here]" and if the user wishes to use an output file other than stdout they must type "-o [insert input file here]".
    Possible commands for ./encode i.e. "-h". Possible commands for ./decode i.e. "-h" for help message and "-v" for printing statistiics. 
<p>

# Files
    <p>
        encode.c contains the c program to perform all of the logic needed to encode a file containing characters. It reads with a buffer to generate a histogram, codes, and a huffman tree.

decode.c contains the c progra mto read in the codes and huffman tree given a tree dump. Ultimately, it reads bit by bit until it has decoded the file.

code.c contains the logic needed to maintain readable code.

huffman.c contains the logic needed to construct and reconstruct a huffman tree as well as building codes for each unique symbol in a file.

io.c contains the logic needed to write code to a file, read bytes, and write bytes.

node.c contains the logic needed to maintain nodes and join nodes together into one parent node.

pq.c contains the logic needed to maintain a huffman tree. It organizes nodes by priority.

stack.c contains logic needed to hold nodes and is used to rebuild a huffman tree.

<p>


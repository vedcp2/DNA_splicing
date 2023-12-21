The DNAstrand Library is a C++ implementation for managing and manipulating linked lists that represent DNA strands. This library provides various functionalities such as splicing in DNA sequences, deleting specific patterns, and more.

Features:
- Destructor (~DNAstrand): Safely deallocates memory used by the DNA strand.
- PatternSize (PatternSize): Counts the number of characters in a given DNA pattern.
- StrandSize (StrandSize): Determines the length of the DNA strand.
- SetTail (SetTail): Sets the tail of the linked list to the last node.
- CleanUp (CleanUp): Helper function to manage nodes during splicing.
- DeletePattern (DeletePattern): Removes a specific pattern from the DNA strand.
- SpliceIn (SpliceIn): Inserts a new DNA strand into the current strand at the location of a specified pattern.
- PushBack (PushBack): Adds a new node to the end of the DNA strand.

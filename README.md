# Biomedical-Informatics-String-Algorithms
Academic Projects largely based on Dan Gusfields book Algorithms on Strings, Trees, and Sequences. Plus other newer algorithms.



naive-approx-matching:
Given text T and pattern P, we want to find the first (i.e., left-most) approximate occurrence of the pattern P in the text T. Here approximate occurrence is defined as follows: a substring S is an approximate match for P if S and P differ at no more than α positions, where 0 < α < n is a parameter of the algorithm. For example, consider text T=ACCCTTATTA, pattern P=ATT, and α=1. There are two approximate matches of P in T: one at position 4 and one at position 7. Hence, the algorithm should return 4. The program takes three command line arguments, where the first argument is full path to a file storing text T, the second argument is pattern P and the third is integer corresponding to α.



horspool-stats:
Given text T and pattern P we want to assess how efficient, in terms of basic operations, is Boyer-Moore-Horspool algorithm. To this end, we want to gather and report several basic statistics. For example, how many times P occurred in T, how many times Bad Character Rule kicked-in allowing P to be shifted by more than one position, etc. This is the goal of this assignment. The program takes two command line arguments, where the first argument is pattern P, and the second is a path to a file storing text T. The output generated per line is: length of T, length of P, effective size of the input alphabet, number of times pattern P has been shifted by one position only, number of times pattern P has been shifted by more than one position, number of times a character in T has been accessed for comparison, index (with indexing starting at 1) of the character in P that mismatched most-frequently (if there is a tie, largest index is returned), probability of drawing pattern P assuming the same distribution of letters as in T (if letter does not occur in T its probability is 0).



suffix-tree-stats:
Given some text T from alphabet Σ we want to assess memory complexity of the resulting suffix tree. One way to do it is by computing how many internal nodes, and how many total outgoing edges, does the suffix tree K(T) constructed from T have. The program takes one command line argument, which is full path to a file storing input text T. The input file contains only one line with text T$ from alphabet Σ={A,C,G,T,N}, and $ is special terminating character. The output generated per line
is: the number of internal nodes in suffix tree from the input text, the total number of outgoing edges in suffix tree from the input text.



kasai-algo:
Given a set of texts T={T1,T2,…,Tz} from alphabet Σ and the corresponding generalized suffix array GSA we want to efficiently build Longest Common Prefix array or LCP array in short. The program takes three command line arguments, where the first is full path to a file storing input texts T, the second is full path to a file storing the corresponding GSA, and the third is full path to the output file that will contain LCP array after program execution. The inputs contain characters from alphabet Σ={A,C,G,T,N}, and $ is special terminating character. The file with input texts contains only one line that is a concatenation of texts from T in the form: T1$T2$…Tz$. The file with suffix array is a binary file storing GSA, where each entry in the GSA is represented using 32-bit signed integer (4 bytes) in little-endian format. The GSA references only one $. The program creates a binary output file (name given as the third command line argument) in which the LCP array you computed should be stored using 32-bit signed integers (4 bytes) in little-endian format. There is a helper script gen_SA that can be used for creating the GSA file in little-endian format.



bwt-fm-index:
Given BWT of some text T, and compacted matrix of character ranks, we want to reconstruct T, and then count occurrences of pattern P and its consecutive sub-patterns. The program takes two command line arguments, where the first argument is full path to a file storing BWT of input text T, and the second argument is pattern P. The inputs contain characters from   alphabet Σ={A,C,G,T,N}, and $ is special terminating character. The BWT file per line should be of form as give. First line contains BWT string (column L of LF-mapping). Second line contains column F of LF-mapping, represented by six integers (sometimes called table C[]), where the first integer is offset of $ (we use indexing from 0), the second integer is offset of As, hence always 1, the third is offset of Cs, hence count of all As and $, and so on. Keep in mind that the fifth integer is offset of N and the sixth is offset of T. Third line stores spacing factor used to compact matrix Occ. The following six lines store compacted matrix Occ, with the first line corresponding to $ and the sixth line corresponding to T. The program print to standard output first T, and then in the next m lines, where m=|P|, counts of how many times each sub-pattern of P matches in T. Specifically in line i count of matches of P[m−i+1..m] in T.



fast-containment-approximation:
Given a large set of texts we want to quickly identify pairs of texts such that one of the texts is contained in the other using MinHash and similar techniques. three command line arguments, where the first argument is full path to a file storing input texts T, second is parameter w∈[3,64] used for shingling (we are using individual letters to create shingles, i.e., a string of length w is a shingle), and the third argument is containment threshold  tc∈[0,1]. All texts in T are from alphabet Σ={A,C,G,T}. To estimate containment, you must use sketching scheme with modulo operation, assuming parameter m=10. The program prints to standard output all pairs whose estimated containment is strictly greater than tc. To generate sketches 64bit FNV-1a hashing function used.



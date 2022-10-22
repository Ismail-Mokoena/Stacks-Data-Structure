# Stack Implementation
The purpose of this program  is to ensure that xml tags are balanced; Meaning for every opening tag '<' there should be a closing tag '>'. 
If a closing tag is missing output will be given indicating where the missing tag should be.

This is accomplished through a templated stack.

<ins>Implement the XML syntax checker</ins><br />
* Read the input file {sample.txt} character-by-character to find the “<” character that marks the beginning of an
  XML tag, and the “>” character that marks the end of the XML tag.<br />
* When an XML start tag is found, it is  pushed on the StringStack. When an XML end tab is found, 
  program looks at the top of the stack, and if the tags match, the start tag is popped off the stack.
  If the end tag does not match the start tag,a syntax error has been found.

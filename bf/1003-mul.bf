[->+<]       // Move value from cell 1 to cell 0 and set cell 1 to 0 (addition)

++++++       // Cell 0 becomes 6

>, >, <<    // Read two characters into cells 1 and 2

[            // Loop to subtract 6 from the ASCII values to get numeric values
  >--------  // Subtract 6 from cell 1
  >--------  // Subtract 6 from cell 2
  <<         // Move back to cell 1
]

>            // Move to cell 2

[            // Loop to multiply the two numbers
  >          // Move to cell 2
  [->+>+<<]  // Copy the value to cell 3 and cell 4
]
>>           // Move to cell 4
[
  -<<+>>     // Multiply and move the result back to cell 2
]
<<<          // Move back to cell 0
-

]
>>
>>++++++++++<<   // Add 10 to cell 2

[->+>-[>+>>]>[+[-<+>]>+>>]<<<<<<]   // Divide by 10 and convert to ASCII

++++++       // Move to cell 3

[            // Loop to print the result
  >>>++++++++ // Add 8 to cell 3
  >++++++++   // Add 10 to cell 3
  <<<<-       // Move back to cell 1
]

>>>>.        // Print the character in cell 3

<.           // Print the character in cell 2

>[-]         // Clear cell 1

++++++++++.  // Print a newline

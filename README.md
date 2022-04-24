<h1 align="center">Data Analysis</h1>

<p>This program will analyze a .CSV file and write to an output file some analytical data based on the input. The program assumes there will be one of three course numbers 
  - 1115, 3115, or 3130. The user will enter which course they would like to analyze. Afterward, the program will print to a file the pass rate per professor, the
withdraw rate per professor, the pass rate per course number, the withdraw rate per course number, and the semester pass rate per course separated into the Spring 
and Fall seasons.</p>  

<h2 align="center">Explanation of the Problem</h2>

<p>The program must be able to read from a CSV file. Those CSV files will contain course information from either the 1115 course, the 3115 course, or the 3130 course.
 The program must analyze the course information from the CSV files and print to an external file some analytical data. This data includes the pass rate per professor, 
the withdraw rate per professor, the pass rate per course number, the withdraw rate per course number, and the semester pass rate per course separated into the
 Spring and Fall seasons </p>
 
<h2 align="center">Techniques Used</h2>

<h3 align="center">Introduction/Program Start</h3>

<p> This program primarily requires the use of the unordered map data structure to complete its purpose, along with the necessary utilities to parse the CSV files
and write to an external text file. First, the user is asked to enter the name of the course they would like to analyze; the program will indicate that the only
valid inputs are 1115, 3115, and 3130. If the user has not entered one of the three valid inputs, the program will state that the input was not valid and will
create a file with that input, but it will have text stating that the input was invalid. If, however, the user has entered a valid input, then the program will call
an analyze_data function which will call several other functions that will analyze and write the necessary data.</p>

<h3 align="center">Calculate Withdraw/Pass Rate Per Professor</h3>

<p>Since the functions to calculate the withdraw rate per professor and to calculate the pass rate per professor are very similar, I will explaining the general
idea behind both functions. There are three necessary function calls, which I will be explaining in a bottoms-up manner. First, the program must count
the number of students that have passed/withdrawn per instructor. The program will first open the file that it must read. It will then get rid of the headings that
are on the first line of each CSV file. The program will then create an unordered map with the key having a datatype of string and the value having a data type
of float. The string will be the instructor and the float will be the number of students that have passed/withdraw.</p>

<p>Then, the program will utilize a while loop that continues until there are no more lines to parse in the CSV file. The program will initialize a counter to keep
track of which column it is on while parsing. If it is on the third column, which is the instructor id, the program will try to find the instructor in the 
unordered map. If it does not find the instructor, it will insert the instructor into the unordered map and give it a value of 0, indicating the current number
of passed/withdrawn students. The program does not need to do anything if the instructor is already in the unordered map.</p>

<p>If, while parsing, the program is reading the 6th column, which is the student's grade, the program will store the grade in a variable. When reading the
grade, the program will only need to save the first character to determine whether the student has passed or withdrawn. This is because, if the first character is
not an 'F,' the student has passed. The + or - after the letter is irrelevant. Furthermore, if the first element is a 'W,' the student has withdrawn. Whether
they withdrew officially, unofficially, or without academic penalty is irrelevant.</p>

<p>Once the program has determined whether the current student has passed or withdrawn, the program will erase the current value at the instructor's index and
place the updated value into the instructor's key. The program will do this by saving how many passes/withdrawals the instructor originally had and incrementing
it by one. Once the program has finished with a row, it will set the column back to 1 to prepare for the next row parsing. The function will finally return an 
unordered map with all of the instructors along with how many students they passed.</p>

<p>Another function is necessary to calculate the withdrawal/pass rate per professor. This function will calculate the total number of students each professor has. 
The program needs this function because, evenentually divide the total withdrawn/passed students with the total students to obtain the ratio. This function is
very similar to the previous function. The program will parse the entire CSV file. If it is on the third column (instructor id), it will check if the instructor
is in the unordered map. If they are, the total number of students they have is incremented by one. If they aren't, they are put into the map and are given a key
of 1 student.</p>

<p>Finally, all of this information is used together in a final method. The program will save the two unordered maps into two variables, one for the 
pass/withdraw rate per professor and one for the total number of students per professor. Then, the program will create a third unordered map to store the
data we have been trying to obtain - the pass/withdraw rate per professor. The program will loop through both unordered maps simultaneously. As it goes through
each unordered map, it will insert into the third unordered map the instructor, along with the number of students that have passed/withdrawn divided by the
total number of students (this is the ratio we want). Once this is completed, the program writes the data and list of instructors along with the pass rate to
the output text file.</p>

<h3 align="center">Calculate Withdraw/Pass Rate Per Course Overall & Per Season</h3>

<p>Again, since the withdrawa/pass rate per course functions are very similar, for both the overall rate and the rate per season, I will only be focusing on
the general idea. This time, the progrma will not need an unordered map because in the function, the program will only need the total students and the number
of students that passed/withdrew. There is no need for the instructor this time.</p>

<p>Like before, the overall function will parse through the CSV file. If the function has reached the sixth dolumn (the student's grade), the program will save the grade into a variable like before and only consider this first character for the same reason. The total number of students is incremented no matter what. The total number of passed/withdrawn students, however, will only be incremented if the conditions are correct. Finally, the function will return the passed/withdrawn students divided by the total number of students and write it to the output file.</p>

<p>There are some slight differences between the overall function and the functions that calculate the pass/withdrawal rate per term (Spring or Fall). One primary
difference is that the per season functions will store an array of terms the function will check and match. The program did not do this in the previously described overall functions. The contents of the array of terms depends on whether the program is looking for the Spring or the Fall semester.</p>

<p>Another difference is that, now, the function must also check the fourth column (the term id) along with the sixth column (the student's grade). When checking the term id, the function must now save the term id into a variable. Once the program has done this and has reached the student's grade, the program must also check that the previously saved term id variable is contained in the term array that must be checked. If this condition is true, the program executes as normal.</p>

<p>Finally, there is another additional condition that the program most execute before printing the percent to the output file. If the count returned a value that is not a number (nan), this means that, in the CSV file, there were no terms that matched with the terms that were given in the terms array. In this case, a unique indication is written to the output file stating that there were no terms found for the provided season. Otherwise, the program will simply print the percent like usual.</p>

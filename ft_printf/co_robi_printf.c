#include <stdio.h>

/*		
		Format specifiers
The character after a '%' has different meanings. Let's just look at the ones we need to realize this project for school 42.

%- Prints a % character.

d, i- Print an int as a signed integer. 
	%d and %i are synonymous for output, but are different when used with scanf for input 
	(where using %i will interpret a number as hexadecimal if it's preceded by 0x, and octal if it's preceded by 0.)

u- Print decimal unsigned int.

x, X- Print an unsigned int as a hexadecimal number. x uses lower-case letters and X uses upper-case.

s- Print a null-terminated (\0) string.

c- Print a single character (char).

p- Print the address of a pointer or any other variable. The output is displayed in hexadecimal value. It's a format specifier which is used if we want to print data of type (void *).


// do zrobienia ft_printf użyjemy - malloc, free, write, va_start, va_arg, va_copy, va_end

// musimy zrobić też Makefile oraz header file
//
// 1. funkcja printf wypisze nam znak(character) po znaku, od początkowego stringa. dopóki nie znajdzie "%".
// 2. Kiedy znajdzie "%" zacznie szukać elementu w kolejnym index/position. Znajdzie znak który będzie definiować typ dla pierwszego argumentu zmiennej.
// np - %s = leo.
// 3. Zależnie co ft_printf znajdzie, it will call a method that will display argment of the particular type at output.
// jeśli będzie to "s" po %, to będziemy potrzebować funkcji która wyświetli strings.
// jeśli będzie to "d" po %, będziemy potrzebować funkcji któta wyświetli numery.
// i tak dalej.(mamy jak wiesz, %zu, %lf, %2.lf, %c itd :) ).
// 4. Po zapisaniu pierwszego argumentu zmiennej, wracamy do step 1. aż do końca stringa (aka, aż znajdziemy null znak '\0').
//
// 5. Nie zapomnij policzyć numerów znaków wydrukowanych za każdym razem, aby na końcu funkcji zwrócić ostateczną liczbę znaków.
//
// 				PROTOTYP
//
//	printf("hi my name is %s i mam %d lat", "leo", 22);
//	
//	INDEX - "hi my name is %s i mam %d lat"\0
//		 01234567891123456789212345678 29
//	output- "hi my name is leo i mam 22 lat"
// 		 012345678911234567892123456789 
// 	COUNT
// 	(of characters)	
// 			  
//	1. Nasz program wypisze znaki z INDEXU od 0 do 13, jeden po drugim, podczas
//	inkrementcji count variable. (count++;) 
//	 -> W tym etapie program ft_printf powinien wyświetlić "hi my name is "
//	 i funkca zwróci numer 14
//	 
//	 2. Jeśli napotka znak '%', stopuje writng and it will look one position dalej.
//	 ->Na tym etapie wskazujemy na pozycję 15 w INDEXIE
//	 
//	 3.Program will now check the type of the element in this position(the position after %) W naszym przypadku jest to 's'.
//	 
//	 4.Będziemy musieli print one by one, the charactrs of the type the program has just found. 
//	 As it is a string, możemy na przykład użyć FUNKCJI "putstr" that we created in the "libft" project to print each character. 
//	 Nie zapomij również policzyć the number of characters that will be printed from this string i dodać do początkowego liczenia.
//	 
//	 5.PO tym jak pierwszy dynamiczny argument (ten który corresponding to %s) został wyświetlony, możesz wrócić to initial zdania i kontynuować robotę.
//	 -> Na tym etapie program powinien wyświetlić "hi my name is leo" i wyświetlić numer którą funkcja zwraca = 16. (total of character displayed)
//	 
//	 6. Nasz program will then write again each character, one by one, z INDEXU 17 do 22, while incrementing the count variabe (coun++)
//	 
//	 7. - program z nowu znajdzie % (pozycja 23), stopuje writing szuka kolejnego elementu po %.
//	 
//	 8. - Program w naszym przypadku typ drugiego DYNAMICZNEGO ARGUMENTU jest 'd' (%d). That means that you will call a function która printuje numer.
//
//	 9. - Nasz program will then write again each character, one by one, z INDEXU 25 do końca while incrementing the "count" zmienną.
//	 -> At this stage of the program the printf function powinien wyświetić "hi my name is leo i mam 22 lat" 
//	 		and the number the function returns is 29 (29 znaków printed in total).
//
//		SPOILER - display a pointer or hexadecimal is a bit harder than displaying just a character).
//

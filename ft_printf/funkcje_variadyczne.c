#include <stdarg.h>

/*
 ft_printf

	Funkcje wariadyczne (Variadic functions)

  To jest nowy temat, którego uczymy się w tym projekcie. Ważne jest, żeby dobrze go zrozumieć, zanim przejdziemy dalej.

  
  Do tej pory wszystkie funkcje, których używałeś lub tworzyłeś na kursie, miały stałą liczbę argumentów. Mogło ich być kilka, ale zawsze wiedziałeś wcześniej, jakie argumenty są potrzebne.

  Przykład:

	strlen przyjmuje tylko jeden argument – string (int ft_strlen(char *str)),

	split przyjmuje dwa argumenty (ft_split(char const *s, char c)).


  Czyli zawsze wiedziałeś, ile i jakiego typu są argument


   		Funkcja wariadyczna

 	Funkcja wariadyczna to funkcja, która może przyjmować zmienną liczbę argumentów.
	Rozpoznaje się ją po "..." w definicji funkcji.

*/
	int	ft_printf(const char *format, ...);
/*

  const char *format to obowiązkowy argument funkcji printf.

  Funkcja wariadyczna musi mieć przynajmniej jeden obowiązkowy argument, ale liczba dodatkowych argumentów może być dowolna.

  Kiedy ktoś wywołuje funkcję printf, nie wiemy wcześniej, ile argumentów zostanie użytych. Nie wiemy, ile razy w stringu formatowania użyje się %s, %d itp.


  Na szczęście w C nie musimy przepisywać printf za każdym razem, gdy zmienia się liczba argumentów.
	Wystarczy użyć biblioteki stdarg, która pozwala korzystać z nowego typu zmiennej */va_list/* oraz trzech bardzo przydatnych makr:
*/
 	va_start

 	va_arg

 	va_end
/*


 */va_list - typ nowego objektu , jest to lista zawierająca wszystkie dynamiczne argumenty
 przetrzymuje on informacje potrzebne dla makr -va_start, va_copy, va_arg  va_end/*

  Tworzenie zmiennej (variable)

	va_list leo;

	va_list args;

	printf("czesc moje imie to %s i mam %d lat", "leo", 22);

					args = ["leo", 22];

	printf przyjmuje 2 argumenty. Te 2 argumenty są zmiennymi argumentami i będą przechowywane we wcześniej stworzonej zmiennej typu va_list dzięki va_start.


  */va_start - function macro - va_start inicjalizuje zmienną va_list, zanim zaczniemy z niej korzystać./*

  to makro będzie inicjalizowało wszystko before we start moving through our variable arguments list (va_list).

  PISZEMY GO TAK

  va_start( va_list var, parameterN );

  Nasz przykład:
   va_start( args, format);
	var jest zmienną typu arg_list (args dla naszego przykładu)
	parameterN jest nazwą parametru poprzedzającego pierwszy dynamiczny parametr ( w naszym przypadku z printf będzie to początkowy string)
	innymi słowa - jest to MANDATORY ARGUMENT

	va_start ustawia scenę: mówi, które argumenty są stałe, a które zmienne. Po wywołaniu tej funkcji, va_list będzie zawierać wszystkie dodatkowe argumenty.
⚠️ Ważne: va_start musi być wywołane przed użyciem va_arg, inaczej lista argumentów będzie pusta.
 
 	*/va_arg – makro/funkcja/*
 	
	va_arg pozwala dostęp do kolejnych argumentów dynamicznych funkcji.
 	
	Każde wywołanie va_arg przechodzi do następnego argumentu.
 
 	Wywołanie wygląda tak:

	*/va_arg(va_list var, type_of_variable);/*


	Wracając do naszego przykładu:

	printf("hello my name is %s and i am %d old\n", "laura", 23);


	Lista dynamicznych argumentów (args) ma 2 elementy:

	string ("laura")

	int (23)

	Aby dostać się do pierwszego argumentu:

	va_arg(args, char *)  // -> "Laura"
 
 	Aby dostać się do drugiego argumentu:

	va_arg(args, int)  // -> 23

	W praktyce nie zawsze wiemy, ile argumentów będzie, więc trzeba sprawdzać typ argumentu według formatu.
 
 
 	*/va_end – makro/funkcja/*

	Po zakończeniu korzystania z va_list trzeba posprzątać pamięć:

	va_end(va_list var);

	
	W naszym przykładzie:

	va_end(args);

	va_end zwalnia pamięć zajętą przez zmienną va_list.


*/

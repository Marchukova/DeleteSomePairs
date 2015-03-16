# DeleteSomePairs
Multithreading program solves follin problem:
Дана последовательность отсчетов, представляющих собой пары (int Х : int Y). Отсчеты упорядочены по значениям Х.
В этой последовательности могут встречаться подпоследовательности, состоящие из идентичных отсчетов. 
Идентичные отсчеты имеют одинаковые значения Y. 

Проредить исходную последовательность следующим образом:
В каждой подпоследовательности идентичных отсчетов оставить только первый и последний отсчеты, 
а так же каждый n-ный отсчет (n > 2). 
Вывести на экран исходную последовательность и результат.

Язык программирования: C++.
Тип приложения: консольное.

Пример.
Исходная: (1, 10) (2, 11), (3, 11), (4, 11), (5, 11) (6, 10)
Результат при n = 3: (1, 10) (2, 11), (4, 11), (5, 11) (6, 10)
Результат при n = 4: (1, 10) (2, 11), (5, 11) (6, 10)

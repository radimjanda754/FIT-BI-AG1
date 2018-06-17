Děti ve školce si oblíbily skládání matrjošek, aniž by si uvědomily, jakou mají matrjošky vlastně krásnou rekurzivní definici:

Prázdná posloupnost je matrjoška.
Matrjoška je schránka o jisté velikosti V, sestávající z levé a pravé poloviny (obě velikosti V), která obsahuje posloupnost dalších matrjošek, součet jejichž velikostí je nejvýše V. Velikost matrjošky je daná pouze velikostí obalu, nezávisle na tom, co všechno je uvnitř.
Děti do řady položily kousky matrjošek, levé a pravé, a od vás chtějí poradit, jestli tato řada lze poskládat do korektní matrjošky. Složit do sebe lze pouze dílky stejné velikosti. Pořadí dílků v této řadě však nelze měnit. Zároveň je potřeba zjistit, které z dětí výslednou matrjošku dostane, což bude takové, které přispělo nejvíce. To znamená součet velikostí dílků, které toto dítě celkem položilo (v případě rovnosti rozhoduje lexikografické pořadí jmen dle ASCII). Výslednou složeninu toto dítě dostane i tehdy, pokud z ní nelze poskládat korektní matrjošku.

Formát vstupu:

na prvním řádku je číslo N udávající počet kousků matrjošek,
pak následuje N řádků, na i-tém řádku je číslo Mi popisující část matrjošky, mezera, a potom jméno dítěte Ji, které tam tento díl položilo,
pokud je číslo Mi záporné, je to levá část matrjošky, pokud kladné, tak pravá,
absolutní hodnota Mi udává velikost daného dílku matrjošky,
1 ≤ N ≤ 1000000,
-220< Mi < 220, Mi ≠ 0,
|Ji| < 1024 a sestává z tisknutelných znaků,
můžete se spolehnout, že vstup je zadán korektně.
Formát výstupu:

první řádek obsahuje buďto "Ano" nebo "Ne" (bez uvozovek) podle toho, zda je řada složitelná do matrjošky či není,
druhý řádek obsahuje jméno dítěte, které matrjošku dostane.
V mateřské školce platí přísná hygienická nařízení, která bohužel knihovna STL nesplňuje, takže ji ve svých programech nemůžete používat.

Příklad vstupu:
6
-10 Pepa
-3 Kuba
3 Kuba'); DROP TABLE Kids;
-8 Roman
8 Kuba
10 Roman
Příklad výstupu:
Ne
Roman
Příklad vstupu:
6
-6 l33t h4x0r
-4 l33t h4x0r
4 l33t h4x0r
-2 script kiddie
2 script kiddie
6 script kiddie
Příklad výstupu:
Ano
l33t h4x0r
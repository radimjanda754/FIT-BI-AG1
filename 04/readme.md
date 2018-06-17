Aerolinie Vžum & Bum se rozhodly modernizovat své služby pro obsluhu N letišť, která si můžeme představovat jako body v dvourozměrném prostoru. Vedení firmy přišlo s novou strategií:

Každá trojice letišť, dejme tomu A,B,C, bude obsluhována dvěma letadly. První letadlo bude létat z letiště A do B, z něj do C a z něj opět do A. Druhé letadlo bude létat přesně v opačném směru. Každé letiště bude navštěvováno mnoha letadly, podle toho, v kolika trojicích letiště leží.
Cena za letenku mezi dvěma letišti bude nastavena jako druhá mocnina euklidovské vzdálenosti obou letišť.
Záhy se experimentálně přišlo na to, že pro některé trojice letišť lidé nevyužívají všech linek. Například pro polohy letišť A=(1,2), B=(3,1), C=(5,2), D=(2,3), E=(4,4), ve trojici ABC žádný pasažér nevyužíval letu mezi A a C a všichni létali raději oklikou z A do B a teprve z B potom do C. Pochopitelně - cena za přímou letenku z A do C je 16, kdežto z A do B i z B do C stojí jen 5. Oproti tomu v trojici ABD se žádná taková oklika nevyplatí.

Trojici letišť, kde je cena cesty mezi každými dvěma letišti ostře menší než cena cesty oklikou přes třetí bod, nazveme dobrou trojicí.

Aerolinie pochopitelně chtějí linky provozovat pouze na dobrých trojicích letišť, protože jen na nich se vyplatí používat skutečně všechny spoje. Napište program, který zjistí počet dobrých trojic letišť!

Formát vstupu:

na prvním řádku je číslo N (3≤N≤2000)
pak následuje N řádek, kde na i-tém jsou 2 celá čísla x_i a y_i (0 ≤ x_i, y_i ≤ 10000) udávající kartézské souřadnice i-tého letiště
můžete předpokládat, že žádná tři letiště neleží na přímce
vstup je zadaný korektně
Formát výstupu:

jedna řádka obsahující počet dobrých trojic letišť
Vzorový vstup:

5
1 2
3 1
5 2
2 3
4 4
Vzorový výstup:

3
Vzorový vstup:

4
1 1
2 1
1 2
2 2
Vzorový výstup:

0
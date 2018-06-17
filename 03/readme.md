Všem jistě dobře známá rodinná farma Vidlák & syn se po fiasku s výstavbou ohradníku pro ovce (kdy z úsporných důvodů byl zvolen ohradník s nulovým obsahem) rozhodla rozjet jiný byznys. Na obřích pozemcích farmy se nachází rozsáhlá síť potoků, potůčků, řek a říček. Pan Vidlák by na části této říční sítě chtěl vysadit pstruhy.

Říční síť je dána pomocí N význačných bodů na řekách a obousměrně propojených úseků mezi nimi. Mezi význačné body patří i prameny, ústí do moře, či soutoky několika řek. Víte, že říční síť tvoří strom. To znamená, že mezi každými dvěma význačnými body vede právě jedna říční cesta.

Pstruhy však chce pan Vidlák chovat pouze na takové podsíti říční sítě, která je souvislá, tedy jsou v ní propojeny každé dva body říční cestou. (Podsíť může být i jednobodová.)

Jak už je páně Vidlákovým dobrým zvykem, rád by nejprve spočítal, kolik možností, kde začít pstruhy chovat, vlastně má. Protože mohou vycházet ve výsledcích dosti velká čísla, bude nám stačit, pokud místo přesného výsledku vypíšete pouze zbytek po dělení jistým velkým prvočíslem. Pan Vidlák dále odmítá používat nástroje, kterým nerozumí, knihovnu STL tudíž ve svých programech nemůžete použít.

Formát vstupu:

Na prvním řádku je číslo N.
Poté následuje N řádků, kde i-tý obsahuje číslo s_i, udávající počet význačných bodů, se kterými je propojen význačný bod číslo i-1 (body číslujeme od nuly), a dále na řádku následuje mezerami oddělený seznam s_i těchto bodů.
1 ≤ N ≤ 106
Vstup je zadán korektně
Formát výstupu:

Jeden řádek obsahující číslo s výsledkem modulo 536870909 (což je, jak každý vidí, prvočíslo).
Příklad vstupu:

5
1 2
1 2
4 0 3 4 1
1 2
1 2
Příklad výstupu:

20
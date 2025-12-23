# Teksto analizės programa #
## Programos aprašymas ##

Ši programa skirta *teksto analizės atlikimui*, *nuskaitant tekstą iš failo* ir *apdorojant jame esančią informaciją*. Programa analizuoja tekstą eilutė po eilutės, suskaido jį į žodžius, *skaičiuoja jų pasikartojimų skaičių*, sudaro *žodžių ir eilučių numerių (cross-reference) lentelę*, taip pat aptinka tekste esančius *URL adresus*.

Programa parašyta `C++ programavimo kalba`, naudojant standartines bibliotekas ir asociatyvius konteinerius.

## Programos funkcionalumas ##
**Programa atlieka šias užduotis:**

 - Nuskaito tekstą iš vartotojo nurodyto failo
 - Suskaičiuoja, kiek kartų kiekvienas žodis pasikartoja tekste
 - Sudaro žodžių ir eilučių numerių lentelę
 - Atpažįsta tekste esančius URL adresus (pvz. https://www.vu.lt, www.vu.lt, saitas.xyz)

**Leidžia vartotojui pasirinkti:**
 - ar rezultatus išvesti į terminalą
 - ar išsaugoti į failus

Leidžia pasirinkti **vieną** arba **kelis veiksmus** vienu metu

## Naudojami duomenų tipai ir struktūros ##
**Programoje naudojami šie konteineriai:**

`map<string, int>` – žodžių pasikartojimų skaičiui saugoti 

`map<string, set<int>>` – žodžių eilučių numeriams (cross-reference)

`set<string>` – unikaliems URL adresams saugoti


**Naudojamos standartinės C++ bibliotekos:**
`<string>`
`<map>`
`<set>`
`<fstream>`
`<sstream>`
`<cctype>`
`<iostream>`

## Failai ##
**.txt failai:** `VU_gpt.txt` ir `Vilnius.txt`, tai programos testavimo failai.

**.cpp failai** `main.cpp`, tai pagrindinis funkcijos main() failas, kuriame pateiktas programos meniu. Ir `functions.cpp`, tai failas su programoje naudojamomis funkcijomis.

**.h failas** `header.h`, tai antraštės (header.h) failas, kuriame deklaruotos programoje naudojamos funkcijos ir globalūs kintamieji.


 
## Programos paleidimas ##
**Sukompiliuokite programą:**

`g++ main.cpp functions.cpp -o programa`

**Paleiskite programą:**

`./programa`



## Išvesties failai ##
Pasirinkus išvedimą į failus, sukuriami šie failai:

`word_count.txt` – žodžiai ir jų pasikartojimų skaičius

`cross_reference.txt` – žodžiai ir eilučių numeriai

`urls.txt` – rasti URL adresai

## Pastabos ##
Programa palaiko *lietuviškas raides*

*Skaičiai, skyrybos ženklai* ir *santrumpos* nėra laikomi žodžiais

*URL adresai* filtruojami pagal domeno ir protokolo struktūrą

Failas nuskaitomas tik vieną kartą, siekiant geresnio našumo

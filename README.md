# GeresnisTheHashRacer
## Įvadas
GeresnisTheHashRacer - tai hash funkcijų testavimo įrankis. 

Galima ištestuoti šių autorių hash funkcijas:

BlackDude22<br>
RytisGit<br>
agnuss7<br>
SimonasValkiunas<br>
PauliusKu<br>
RaimundV<br>

Kiti hash'ai nebuvo įtraukti dėl bent vienos iš šių priežasčių: neradau github paskyros, slepiamas kodas, kodas parašytas ne C++, nepavyko pasileisti hash'o, išvis neatliko užduoties. Jei norite, kad įtraukčiau hash'ą susisiekite su manim.

## Testai

Atliekami 4 testai skirti išbandyti įvarias hash funkcijų savybes.

### A Konstitucijos testas

100 kartų suhash'uoja failą `konstitucija.txt`. Skaičiuoja visą ir vidutinį hash'avimo laiką. 

`A1` - vidutinis hash'avimo laikas.<br>

### B Greičio ir kolizijų testas su trumpais string'ais

Suhash'uojami 1 000 000 unikalūs 8 simbolių ilgio string'ai. Skaičiuojamas kolizijų skaičius tarp visų gautų hash'ų. Taip pat visas ir vidutinis hash'avimo greitis.

`B1` - Kolizijų skaičius.<br>
`B2` - Vidutinis hash'avimo greitis (hash/s).<br>

### C Greičio ir kolizijų testas su ilgais string'ais

Suhash'uojami 500 000 unikalūs 1000 simbolių ilgio string'ai. Skaičiuojamas kolizijų skaičius tarp visų gautų hash'ų. Taip pat visas ir vidutinis hash'avimo greitis.

`C1` - Kolizijų skaičius.<br>
`C2` - Vidutinis hash'avimo greitis (hash/s).<br>

### D Simbolių panašumo testas

Suhash'uojama 100 000 porų, vienu simboliu besiskiriančių stringų. Gauti hash'ai palyginami simbolių lygmenyje. Skaičiuojamas minimalus, vidutinis ir maksimalus panašumo koeficientai. 

`D1` - Minimalus panašumo koeficientas<br>
`D2` - Maksimalus panašumo koeficientas<br>
`D3` - Vidutinis panašumo koeficientas<br>

## Rezultatai


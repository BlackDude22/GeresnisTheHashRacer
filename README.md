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

`A1` - vidutinis hash'avimo laikas (s).<br>

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

| Autorius | A1 | B1 | B2 | C1 | C2 | D1 | D2 | D3 |
|----------|----|----|----|----|----|----|----|----|
| SHA256 | 0.002 | 0 | 545 137 | 0 | 123 797 | 0 | 0.23 | 0.06 |
| BlackDude22 | 0.0079 | 0 | 769 868 | 0 | 26 066 | 0 | 0.25 | 0.06 |
| RytisGit | 0.05 | 0 | 271 501 | 0 | 3755 | 0.33 | 0.5 | 0.34 |
| agnuss7 | 0.4 | 0 | 61 842 | 499 704 | 421 | 0 | 0.1 | 0.01 |
| SimonasValkiunas | 1.38 | 40 948 | 12 418 | 6463* | 135 | 0 | 0.09 | 0.03 |
| PauliusKu | 0.0004 | 264 | 10 800 000 | 23 197 | 642 681 | 0.125 | 0.875 | 0.812 |
| RaimundV | 0.0078 | 0 | 90 797 | 0 | 80 579 | 0.58 | 0.92 | 0.75 |

* Testas nutrauktas po 200 000 string'ų, nes būtų trukęs 2h.

Da bi se projekat uspešno kompajlirao potrebno je pokrenuti build.sh skriptu pomoću komande

./build.sh

Ukoliko fali neki paket, skripta će tražiti sudo privilegiju od korisnika naknadno da unese
da bi komanda "sudo apt-get -qq install ime_paketa -y" prošla.
Flag -qq označava da je u tihom modu gde ne štampa poruke tokom instalacije, 
dok -y označava da se automatski pristaje na instalaciju paketa.

Paketi su svi sa oficijalnih Ubuntu repozitorijuma.

Ukoliko dođe do greške, skripta će ih ispisati crvenim slovima i prekinuti sa radom.

Nakon uspešnog završetka, pokrenuti run.sh skriptu  pomoću komande

./run.sh

da bi se program startovao, ili dvoklikom na Salira datoteku u direktorijumu build. 

Za brisanje kompajliranog Salira projekta pokrenuti clean.sh skriptu pomoću komande 

./clean.sh


NAPOMENA: Skripta je predviđena za debian-based Linux distribucije, pošto se oslanja na dpkg i apt-get alate 
za proveru i instalaciju potrebnih biblioteka i paketa.
Listu takvih distribucija možete pogledati na https://www.debian.org/misc/children-distros
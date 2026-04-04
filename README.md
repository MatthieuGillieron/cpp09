
## ex00 — Bitcoin Exchange

Programme qui calcule la valeur d'un montant de bitcoin à une date donnée.

**Container :** `std::map`
```bash
make && ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 1.2 = 0.36
Error: not a positive number.
Error: bad input => 2001-42-42
```

**Format input.txt :**
```
date | value
2011-01-03 | 3
2012-01-11 | 1.5
```

---

## ex01 — Reverse Polish Notation

Évalue une expression mathématique en notation polonaise inversée.

**Container :** `std::stack`
```bash
make && ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
./RPN "7 7 * 7 -"
42
./RPN "(1 + 1)"
Error
```

Opérateurs supportés : `+ - * /`

---

## ex02 — PmergeMe

Tri d'une séquence d'entiers via l'algorithme **Ford-Johnson** (merge-insert sort).

**Containers :** `std::vector` + `std::deque`
```bash
make && ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : 16.00000 us
Time to process a range of 5 elements with std::deque  : 30.00000 us
```

**Ford-Johnson en bref :**
1. Former des paires grand/petit
2. Trier récursivement les grands
3. Réinsérer les petits via binary search dans l'ordre de Jacobsthal

---


## Règles globales

- C++98 uniquement
- Orthodox Canonical Form
- Pas de `printf`, `alloc`, `free`, `using namespace`

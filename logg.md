## log text processing in lunix 

```$ awk -F, '{ count[$9]++} END { for (wrd in count) print wrd, count[wrd] }' test_log-commas ```

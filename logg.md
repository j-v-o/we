## log text processing in lunix 

```$ awk -F, '{ count[$9]++} END { for (wrd in count) print wrd, count[wrd] }' test_log-commas ```

### google-ing  
- https://catonmat.net/awk-one-liners-explained-part-three
- https://www.gnu.org/software/gawk/manual/html_node/Very-Simple.html
- 


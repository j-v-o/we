## log text processing in lunix 

```awk -F, '{ count[$9]++} END { for (wrd in count) print wrd, count[wrd] }' test_log-commas ```

### google-ing 1  
- https://catonmat.net/awk-one-liners-explained-part-three 
- https://www.gnu.org/software/gawk/manual/html_node/Very-Simple.html
- https://www.computerhope.com/unix/ugrep.htm 
- https://stackoverflow.com/questions/27986425/using-awk-to-count-the-number-of-occurrences-of-a-word-in-a-column
- 

```__e2```

### google-ing 2
- https://superuser.com/questions/711017/how-do-i-pipe-output-to-date-d-value
- 


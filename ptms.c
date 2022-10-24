{
For the log sample below please create two shell scripts (either one-line command or as a script) that would produce the following output - (defining the correct separator first):

1. Assuming that hz-void.internal is an internal FQDN (domain name) you need to parse the log and list only unique subdomain names (including domain) and the count (amount of times) this subdomain is present in the log.

2. One of the fields in the log is a epoch timestamp. You need to convert the timestamp into an ISO (human-readable) format and write the output of the following fields into a newly created CSV (comma-separated) file:
- Date in ISO format (dd/mm/yyyy hh:mm:ss) or other human readable format
- IP address
- userNN field
}
	MyFiles/Downloads/test_log_task.txt
	
	1.
(grep%) | awk% | sed% | >>	
https://www.cyberciti.biz/faq/grep-regular-expressions/	
https://phoenixnap.com/kb/grep-regex	
https://linuxize.com/post/regular-expressions-in-grep/
	[sed - Search column and store inside variable using grep or awk - Stack Overflow](https://stackoverflow.com/questions/64628733/search-column-and-store-inside-variable-using-grep-or-awk) 
	[Linux Grep Command Help and Examples](https://www.computerhope.com/unix/ugrep.htm) 
	[Grep or awk a unique and specific word across many fields](https://www.unix.com/unix-for-beginners-questions-and-answers/273003-grep-awk-unique-specific-word-across-many-fields.html) 
	[linux - Grep command to extract unique words - Stack Overflow](https://stackoverflow.com/questions/17565137/grep-command-to-extract-unique-words) 
	[Using sed to replace special characters - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/212925/using-sed-to-replace-special-characters) 
.....
	sed 's/@/,/g' test_log_task.txt > test_log-commas	;<replace-delimiters @ for ,>
	ubunter@uiron-3552:~/Downloads$ awk -F, '{c[$7]++} END{for (i in c) print i, c[i]}' test_log-commas 
domain000110.hz-void.internal 3
 15
domain00010.hz-void.internal 12
domain000120.hz-void.internal 5

	
	2.
awk% | date -d @ +%d/%m/%Y% | grep% >>	

  http://www.timestamp-converter.com/
https://stackoverflow.com/questions/2371248/how-to-convert-timestamps-to-dates-in-bash {
"On systems with GNU Coreutils >= 5.3.0, e.g. Linux you can use:
	date -d @1267619929 +%_format_ 
"One-liner: date -d @$(date -u +%s) – Mike Atlas Jan 5, 2016 at 17:30
}                                                                          
	https://serverfault.com/questions/310098/how-to-add-a-timestamp-to-bash-script-log
  https://unix.stackexchange.com/questions/164826/date-command-iso-8601-option
.....
	awk -F, '{c[$7]++} END{for (i in c) print i }' test_log-commas
	grep -E "[[:digit:]]{10}" test_log-commas -o | { read utt ; date -d "@$utt" ;  } 
	awk -F, '{ count[$8]++; print $2, $10, $8 } END { }' test_log-commas 
	grep -E "[[:digit:]]{1,3}+\.+[[:digit:]]{1,3}" test_log-commas 
	grep -E "([[:digit:]]{10}+\,|user[[:digit:]]{1,3}+\,|[[:digit:]]{1,3}+\.+[[:digit:]]{1,3}+\.+[[:digit:]]{1,3}+\.+[[:digit:]]{1,3})" test_log-commas 
	

}

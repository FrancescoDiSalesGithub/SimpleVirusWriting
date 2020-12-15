find / -type f -perm -04000 -ls 2>/dev/null
echo "check for SUID binaries"
strace /usr/local/bin/suid-so 2>&1 | grep -i -E "open|access|no such file"
echo "check a .so file missing from a writable directory"

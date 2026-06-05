savedcmd_kmonitor.mod := printf '%s\n'   kmonitor.o | awk '!x[$$0]++ { print("./"$$0) }' > kmonitor.mod

#!/bin/bash
## ==========================================
## SUPSI - Ambienti Operativi - BashBLOG
## Amos Brocco, Vanni Galli
## ========================================== 

## ==========================================
## Parsing dei parametri
## ========================================== 
function urldecode {
	local url_encoded="${1//+/ }"
	printf '%b' "${url_encoded//%/\\x}"
}
[ -z "$POST_STRING" -a "$REQUEST_METHOD" = "POST" -a ! -z "$CONTENT_LENGTH" ] && read -n $CONTENT_LENGTH POST_STRING
OIFS=$IFS
IFS='=&'
parm_get=($QUERY_STRING)
parm_post=($POST_STRING)
IFS=$OIFS
declare -A parameters
for ((i=0; i<${#parm_get[@]}; i+=2)); do
	if [ "${parm_get[i]}" == "pid" ]; then
		parameters[${parm_get[i]}]="${parm_get[i+1]}"
	else		
		parameters[${parm_get[i]}]=$(urldecode ${parm_get[i+1]})
	fi
done
for ((i=0; i<${#parm_post[@]}; i+=2)); do
	parameters[${parm_post[i]}]=$(urldecode ${parm_post[i+1]})
done


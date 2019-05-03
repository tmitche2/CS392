argu=$1
var=${PATH//:/ }
	for a in ${var}:
	do
		filepath=$a/$argu
		if [ -x ${filepath} ]; then
			echo ${filepath}
		fi
	done
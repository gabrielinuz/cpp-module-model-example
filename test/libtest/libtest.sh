#!/bin/bash
SYMBOL=$(objdump -t LanguageManagerModule.so |grep getInstance | awk '{print $6}')

##DEBUG:
#echo "$SYMBOL"

if [ "$SYMBOL" = "getInstance" ];
then
	echo Symbol "$SYMBOL" is present. Test OK.
else
	echo Test FAIL.
fi


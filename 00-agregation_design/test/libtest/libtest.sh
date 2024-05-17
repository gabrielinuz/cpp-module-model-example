#!/bin/bash
SYMBOL=$(objdump -t LanguageManagerModule.so |grep getInstanceOf | awk '{print $6}')

##DEBUG:
#echo "$SYMBOL"

if [ "$SYMBOL" = "getInstanceOf" ];
then
	echo Symbol "$SYMBOL" is present. Test OK.
else
	echo Test FAIL.
fi


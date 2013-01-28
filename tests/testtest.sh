#!/bin/bash
dts=$(date +%Y%m%d_%H%M%S)
testname=testtest
mkdir -p results/$dts/
cat \
	<tests/$testname.input \
	>results/$dts/$testname.output
diff tests/$testname.output results/$dts/$testname.output \
	>results/$dts/$testname.diff

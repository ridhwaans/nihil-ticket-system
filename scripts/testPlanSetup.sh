#/bin/sh
for section in login logout create delete addcredit buy sell refund privileges
do
	for code in 001 002 003 004 005 006 007 008 009
	do
		for ext in input output dtf.output cua atf
		do
			touch tests/$section$code.$ext
		done
	done
done

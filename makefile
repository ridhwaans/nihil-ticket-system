#globals
default: all
clean:
	tools/cleandir .
	tools/cleandir tests
	tools/cleandir tools
remove-results:
	rm -rf results/*
all: locals
locals:
tests: \
		test-login
#locals


#tests
test-test:
	tests/testtest.sh
test-login:
	tests/login001.sh


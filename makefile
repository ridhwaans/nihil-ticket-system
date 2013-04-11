#globals
default: all
freshen: clean all
clean: clean-specials
	tools/cleandir .
	tools/cleandir assets
	tools/cleandir assets/commands
	tools/cleandir resultsj-test
	tools/cleandir scripts
	tools/cleandir tests
	tools/cleandir tools
	rm -rf bin/*
clean-specials: \
		tests/cases.zip
	rm -rf results/*
	rm -rf documentation
	rm -f nts-client
	rm -f output.dtf
docs: doxyfile
	doxygen
docs-view: docs
	chromium-browser documentation/html/index.html

#git
git-prepare: clean
	git add -u
	git add *
git-pushall:
	git push origin working
	git push origin merging
	git push origin master
git-updateall:
	git checkout master
	git merge merging
	git merge working
	git checkout merging
	git merge master
	git merge working
	git checkout working
	git merge master
	git merge merging
git-fetchall:
	git fetch wes
	git fetch ridhwaan
	git fetch bryce

#variables
cp = -cp jsrc:bin:libs/*
dest = -d bin
dir_guard = @mkdir -p $(@D)

#groups
all: client-all server-all
resources: \
	resources/data.atf \
	resources/data.cua

#includes
include client.mk
include server.mk

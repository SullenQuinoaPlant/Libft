#!/bin/bash

#get the following with apt addon if needed
#if [ "$TRAVIS_OS_NAME" == linux ]; then
#	sudo apt-get -qq update;
#	sudo apt-get install libbsd-dev;
#fi

git clone https://github.com/jgigault/42FileChecker ~/42FileChecker
chmod a+x ~/42FileChecker/42FileChecker.sh

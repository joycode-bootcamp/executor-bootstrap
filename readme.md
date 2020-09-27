## executor-bootstrap

The bootstrap c/c++ project of design bootcamp.

- setup

```sh
$ git clone git@github.com:joycode-bootcamp/executor-bootstrap.git
$ cd executor-bootstrap
$ chmod a+x ./ccup.sh
```

- build&test

Make sure that docker is pre installed on the system.

```sh
$ cd executor-bootstrap

# launch docker environment, wait until the image download completely.
./ccup.sh -e

# update the dependent codes
$ ./ccup.sh -u

# build
$ ./ccup.sh -b

# test
$ ./ccup.sh -b
```

- usage

```sh
# start project from docker env
./ccup.sh -e

# update depends
./ccup.sh -u

# build
./ccup.sh -b

# update & build
./ccup.sh -ub

# run executable
./ccup.sh -r

# run tests
./ccup.sh -t

# clean build
./ccup.sh -c

# clean all
./ccup.sh -C

# build & test
./ccup.sh -bt

# update & build & test
./ccup.sh -ubt

# help
./ccup.sh -h
```
